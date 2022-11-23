#include <windows.h>
#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#define CIRCLE_RADIUS 0.15f
#define PI 3.14159265358979323846

int eggs_caught = 0, missed_eggs = 0, level_count = 1, points = 0;
static int high_score = 0;

int egg_xc, egg_yc;
// for coordinates of egg
int basket_x, basket_y;
// for coordinates of basket
int a = 600, b = 650; // for default size of the screen
int s = 0;
// for menu option
int dropped_eggs = 0;
int speed_1 = 1, speed_2 = 1.2, speed_3 = 1.5, speed_4 = 2;
int w = 48, h = 48, t = 10, e = 9, g = 12;
void myinit();
void start_screen(int, int);
void cloud1();
void egg();
void basket(int, int);
void print_score();
void egg_start();
void color();
void score();
void display(void);
void basket_set(int, int);
void myReshape(int, int);
void keys(unsigned char, int, int);
void menu(int);
void myinit() {
    glViewport(0, 0, a, b);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble)a, 0, (GLdouble)b);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}
void start_screen(int i, int j) {
    int k;
    char cat[] = "Dora";
    char orr[] = "Catch";
    char hatch[] = "Game";
    char start[] = "Press S to start";
    char msg2[] = "Presented to you by: GROUP 1 ICS 3A";
    char session_hi_sc[] = "SESSION HIGH SCORE: ";
    char curr_sc[] = "YOUR SCORE: ";
    char msg3[] = "Use A to move the falling dora left and S to move them right";
    char msg5[] = "Move the basket using the mouse";
    char msg4[] = "Use Q to quit the game";

    if (s == 2) {
        // CURRENT SCORE
        glColor3f(1, 1, 1);
        std::string sc = std::to_string(eggs_caught);
        glRasterPos2i(210, 570);
        for (int d = 0; d < strlen(curr_sc); d++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, curr_sc[d]);
        }
        int starting_point = 350;
        glColor3f(0, 1, 0);
        for (i = 0; i < sc.length(); i++) {
            glRasterPos2i(starting_point, 570);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int(sc[i]));
            starting_point += 9;
        }
    }
    // HIGH SCORE
    glColor3f(0, 0, 0);
    std::string hi_sc = std::to_string(high_score);
    glRasterPos2i(50, 80);
    for (int d = 0; d < strlen(session_hi_sc); d++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, session_hi_sc[d]);
    }
    int starting_point = 230;
    for (i = 0; i < hi_sc.length(); i++) {
        glRasterPos2i(starting_point, 80);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, int(hi_sc[i]));
        starting_point += 5;
    }

    glColor3f(0, 1, 0);
    glRasterPos2i(150, 400);
    for (k = 0; k < strlen(cat); k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cat[k]);
    glColor3f(1, 1, 1);
    glRasterPos2i(200, 400);
    for (k = 0; k < strlen(orr); k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, orr[k]);
    glColor3f(1, 0, 0);
    glRasterPos2i(260, 400);
    for (k = 0; k < strlen(hatch); k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hatch[k]);
    glColor3f(1, 1, 0);
    glRasterPos2i(150, 380);
    for (int d = 0; d < strlen(msg2); d++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg2[d]);
    }
    glRasterPos2i(50, 280);
    for (int d = 0; d < strlen(msg3); d++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg3[d]);
    }
    glColor3f(1, 1, 0);
    glRasterPos2i(150, 260);
    for (int d = 0; d < strlen(msg5); d++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg5[d]);
    }

    glColor3f(1, 1, 0);
    glRasterPos2i(150, 240);
    for (int d = 0; d < strlen(msg4); d++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg4[d]);
    }
    glRasterPos2i(210, 200);
    for (k = 0; k < strlen(start); k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, start[k]);
    glColor3f(1, .5, .5);
}

void cloud1() {

    float theta;

    GLfloat angle;
    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        theta = i * PI * i / 180;
        glVertex2f(100 + 50 * cos(theta) / 2, 490 + 50 * sin(theta) / 2);
    }

    glEnd();
    // GLfloat angle;
    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        theta = i * PI * i / 180;
        glVertex2f(130 + 50 * cos(theta) / 2, 480 + 50 * sin(theta) / 2);
    }
    glEnd();

    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        theta = i * PI * i / 180;
        glVertex2f(140 + 50 * cos(theta) / 2, 500 + 50 * sin(theta) / 2);
    }
    glEnd();

    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        theta = i * PI * i / 180;
        glVertex2f(170 + 50 * cos(theta) / 2, 490 + 50 * sin(theta) / 2);
    }

    glEnd();
    glFlush();
}

void cloud2() {
    float theta;
    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        theta = i * PI * i / 180;
        glVertex2f(420 + 45 * cos(theta) / 2, 540 + 45 * sin(theta) / 2);
    }

    glEnd();

    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        theta = i * PI * i / 180;
        glVertex2f(455 + 45 * cos(theta) / 2, 550 + 45 * sin(theta) / 2);
    }

    glEnd();

    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        theta = i * PI * i / 180;
        glVertex2f(455 + 45 * cos(theta) / 2, 530 + 45 * sin(theta) / 2);
    }

    glEnd();

    glLineWidth(1.5);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        theta = i * PI * i / 180;
        glVertex2f(490 + 45 * cos(theta) / 2, 540 + 45 * sin(theta) / 2);
    }

    glEnd();
    glFlush();
}

void line(int i, int j) {

    glBegin(GL_QUADS);
    glColor3f(1.0, .5, 0.5);
    glVertex2f(0.0 + i, 10.0 + j);
    glVertex2f(0.0 + i, 15.0 + j);
    glVertex2f(600.0 + i, 15.0 + j);
    glVertex2f(600.0 + i, 10.0 + j);
    glEnd();
    glFlush();
}

void buildings() {
    if (s != 1) {
        glColor3f(0.0, .5, .8);
    }
    else {
        glColor3f(0.7, .6, .8);
    }

    glBegin(GL_POLYGON);
    glVertex2f(80, 150);
    glVertex2f(80, 350);
    glVertex2f(220, 350);
    glVertex2f(220, 150);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(250, 150);
    glVertex2f(250, 300);
    glVertex2f(310, 300);
    glVertex2f(310, 150);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(350, 150);
    glVertex2f(350, 320);
    glVertex2f(410, 320);
    glVertex2f(410, 150);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(340, 325);
    glVertex2f(340, 350);
    glVertex2f(420, 350);
    glVertex2f(420, 325);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(400, 150);
    glVertex2f(400, 250);
    glVertex2f(450, 300);
    glVertex2f(500, 250);
    glVertex2f(650, 250);
    glVertex2f(650, 150);

    glEnd();

    glFlush();
}
void backk(int i, int j) {
    glColor3f(0, .5, 1);
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, -500 + j);
    glVertex2f(0.0 + i, -500 + j);
    glEnd();
    glFlush();
}
void ground(int i, int j) {

    glBegin(GL_QUADS);
    glColor3f(0, 1.0, 0);
    glVertex2f(0.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, -j);
    glVertex2f(0.0 + i, -j);
    glEnd();
}

void egg() {

    float x, y, z;
    int t;

    // Change colours
    switch (egg_xc) {
    case 115:
        glColor3f(1.0, 1.0, 0.0);
        break;
    case 255:
        glColor3f(0.5, 0.1, 0.3);
        break;
    case 390:
        glColor3f(0.9, 0.5, 0.0);
        break;
    default:
        glColor3f(1.0, 1.0, 1.0);
        break;
    }
    glBegin(GL_POLYGON);
    glVertex2f(egg_xc, egg_yc);
    glVertex2f(egg_xc - 10, egg_yc - 20);
    glVertex2f(egg_xc, egg_yc - 40);
    glVertex2f(egg_xc + 10, egg_yc - 20);

    glEnd();
}

void basket(int i, int j) {
    j = 10; // y-axis
    if (i >= a - 60)
        i = a - 60;

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(10.0 + i, 10.0 + j); // x,y
    glVertex2f(50.0 + i, 10.0 + j); // x,y
    glVertex2f(60.0 + i, 40.0 + j); // x,y
    glVertex2f(0.0 + i, 40.0 + j);  // x,y
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(15.0 + i, 35.0 + j); // x,y
    glVertex2f(20.0 + i, 35.0 + j); // x,y
    glVertex2f(10.0 + i, 20.0 + j); // x,y
    glVertex2f(10.0 + i, 20.0 + j); // x,y
    glVertex2f(15.0 + i, 20.0 + j); // x,y
    glVertex2f(20.0 + i, 35.0 + j); // x,y
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(25.0 + i, 35.0 + j); // x,y
    glVertex2f(30.0 + i, 35.0 + j); // x,y
    glVertex2f(20.0 + i, 20.0 + j); // x,y
    glVertex2f(20.0 + i, 20.0 + j); // x,y
    glVertex2f(25.0 + i, 20.0 + j); // x,y
    glVertex2f(30.0 + i, 35.0 + j); // x,y
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(35.0 + i, 35.0 + j); // x,y
    glVertex2f(40.0 + i, 35.0 + j); // x,y
    glVertex2f(30.0 + i, 20.0 + j); // x,y
    glVertex2f(30.0 + i, 20.0 + j); // x,y
    glVertex2f(35.0 + i, 20.0 + j); // x,y
    glVertex2f(40.0 + i, 35.0 + j); // x,y
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(45.0 + i, 35.0 + j); // x,y
    glVertex2f(50.0 + i, 35.0 + j); // x,y
    glVertex2f(40.0 + i, 20.0 + j); // x,y
    glVertex2f(40.0 + i, 20.0 + j); // x,y
    glVertex2f(45.0 + i, 20.0 + j); // x,y
    glVertex2f(50.0 + i, 35.0 + j); // x,y
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(5.0 + i, 40.0 + j);
    glVertex2f(5.0 + i, 50.0 + j);
    glVertex2f(10.0 + i, 50.0 + j);
    glVertex2f(10.0 + i, 40.0 + j);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(50.0 + i, 40.0 + j);
    glVertex2f(50.0 + i, 50.0 + j);
    glVertex2f(55.0 + i, 50.0 + j);
    glVertex2f(55.0 + i, 40.0 + j);
    glEnd();
}

void print_score() {
    printf("\nLevel reached: %d\n\n", level_count);
    printf("\nNo. of Dora dropped= %d \n", dropped_eggs);
    printf("\nNo. of Dora caught = %d\n", eggs_caught);
    printf("\nNo. of Dora missed = %d\n", missed_eggs);

    s = 2;
    high_score = max(eggs_caught, high_score);
}
void egg_start() {
    egg_yc = 600;
    if (missed_eggs >= 10) {
        printf("\n\n\t\t\t\tGAME OVER\n\n");
        print_score();
    }
    dropped_eggs++;

    switch (rand() % 9) {
    case 0:
        egg_xc = 115;
        break;
    case 1:
        egg_xc = 255;
        break;
    case 2:
        egg_xc = 390;
        break;
    case 5:
        egg_xc = 115;
        break;
    case 3:
        egg_xc = 255;
        break;
    case 4:
        egg_xc = 390;
        break;
    case 7:
        egg_xc = 115;
        break;
    case 6:
        egg_xc = 255;
        break;
    case 8:
        egg_xc = 390;
        break;
    }
}

void score() {
    if (egg_yc <= 50 && (egg_xc >= basket_x && egg_xc <= basket_x + 60)) {
        // printf("\a");
        eggs_caught++;
        egg_yc = -10;
    }
    missed_eggs = dropped_eggs - eggs_caught;
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    ground(0, 650);
    backk(0, 650);
    cloud1();
    cloud2();
    buildings();
    line(0, 600);

    int i;
    char z[12] = "Group 1";
    char level1[12] = "LEVEL 1";
    char level2[12] = "LEVEL 2";
    char level3[12] = "LEVEL 3";
    char level4[12] = "LEVEL 4";

    if (s == 1) {
        glColor3f(0, 0, 1);

        glRasterPos2i(10, 10);
        for (i = 0; i < 12; i++)
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, z[i]);

        if (level_count == 1) {
            glColor3f(1, 1, 1);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level1[i]);
        }
        else if (level_count == 2) {
            glColor3f(1, 0, 0);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level2[i]);
        }
        else if (level_count == 3) {
            glColor3f(0, 1, 1);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level3[i]);
        }
        if (level_count == 4) {
            glColor3f(1, 0, 1);
            glRasterPos2i(500, 300);
            for (i = 0; i < 12; i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level4[i]);
        }

        if (egg_yc <= 10)
            egg_start();

        egg();
        basket(basket_x, basket_y);
        if (eggs_caught >= 10) {
            egg_yc -= speed_2;
            level_count = 2;
        }
        if (eggs_caught >= 20) {
            egg_yc -= speed_3;
            level_count = 3;
        }
        if (eggs_caught >= 30) {
            egg_yc -= speed_4;
            level_count = 4;
        }
        else
            egg_yc -= speed_1;

        score();
        // missed_eggs = dropped_eggs - eggs_caught;

        char score[7] = "Score:";
        char lives[7] = "Lives:";

        std::string sc = std::to_string(eggs_caught);
        std::string lv = std::to_string(10 - missed_eggs);

        glColor3f(0, 0, 0);
        glRasterPos2i(50, 80);
        for (i = 0; i < 8; i++)
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, score[i]);

        glColor3f(0, 0, 1);
        int starting_point = 100;
        for (i = 0; i < sc.length(); i++) {
            glRasterPos2i(starting_point, 80);
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, int(sc[i]));
            starting_point += 5;
        }
        /////////////////////////////////////////////////////////////

        glColor3f(0, 0, 0);
        glRasterPos2i(50, 50);
        for (i = 0; i < 8; i++)
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, lives[i]);

        glColor3f(0, 0, 0);
        int starting_point2 = 100;
        for (i = 0; i < lv.length(); i++) {
            if ((int(lv[i])) < 4)
                glColor3f(1, 0, 0);
            else if ((int(lv[i])) < 6)
                glColor3f(0.6, 0, 0);
            else
                glColor3f(0, 0, 0);

            glRasterPos2i(starting_point2, 50);
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int(lv[i])));
            starting_point2 += 5;
        }

    }
    else if (s == 2) {
        start_screen(40, 300);
    }
    else
        start_screen(40, 300);
    glFlush();
    glutSwapBuffers();
}
void initGame() {
    eggs_caught = 0, missed_eggs = 0, level_count = 1, points = 0,
        dropped_eggs = 0;
}
void basket_set(int a, int b) {
    basket_x = a;
    basket_y = b;
    glutPostRedisplay();
}
void myReshape(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    a = w;
    b = h;
}
void keys(unsigned char key, int x, int y) {
    if (key == 'q' || key == 'Q') {
        printf("\n\n\n\t\tQUIT BY PLAYER\n\n");
        print_score();
    }
    if (key == 's' || key == 'S') {
        s = 1;
        initGame();
    }

    if (key == 'a' || key == 'A') {
        egg_xc -= 10;
        if (egg_xc <= 0)
            egg_xc = 10;
    }
    if (key == 'd' || key == 'D') {
        egg_xc += 10;
        if (egg_xc >= 500)
            egg_xc = 490;
    }
}
void menu(int id) {
    switch (id) {
    case 1:
        s = 1;
        initGame();
        break;
    case 2:
        print_score();
        break;
    case 3:
        printf("\n\n\n\t\tQUIT BY PLAYER\n");
        break;
    default:
        exit(0);
    }
    glutPostRedisplay();
}
int main(int argc, char** argv) {

    printf("******************************************************************");
    printf("\n\t\t\t\t DORA CATCH GAME\n\n");
    printf("******************************************************************");
    printf("\n\tHow to Play..?\n\n <1>The objective of the game is to catch the "
        "Dora in the basket.\n\t To move Basket use mouse.\n");
    printf("\n <2> To Start, press key 's' or 'S' or \n\tClick Right mouse "
        "button then click 'Start Game'.\n");
    printf("\n <3> To Quit manually, press key 'q' or 'Q' or\n\t Click Right "
        "mouse button then click 'Quit'.\n");
    printf("\n\n RULES : If the player misses 10 Dora,then 'Game Over'.\n");
    printf("\nFor each level, speed is Increased\n\n");
    printf("\n\nBEST OF LUCK\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(a, b);
    glutCreateWindow("EGG GAME");
    myinit();
    glutInitWindowPosition(100, 100);
    glutCreateMenu(menu);
    glutAddMenuEntry("Start game", 1);
    glutAddMenuEntry("score", 2);
    glutAddMenuEntry("Quit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glutPassiveMotionFunc(basket_set);
    glutIdleFunc(display);
    glutReshapeFunc(myReshape);
    glutMainLoop();
}
