//
//  main.cpp
//  25-2698_25-4602_25-5201_T10_T10_T10
//
//  Created by el dou7 wa a3wano on 11/27/14.
//  Copyright (c) 2014 el dou7 wa a3wano. All rights reserved.
//
#include <GLUT/glut.h>  // GLUT, include glu.h and gl.h
#include <OpenGL/OpenGL.h>
#include <ctime>
#include <stdlib.h>     /* srand, rand */
#include <complex>
#include <iostream>
#include <stdio.h>

/* Global variables */
double theta  = 0.25*(3.141593f / 180);
double cx = 0.0;
double cy = 12.0;
double cz = 0.0;
char title[] = "3D Shapes";
float angle = 120.0;
bool start;
bool rotate;
int score;
int madfa3DirecH = 0;
int madfa3DircV = 0;
int windowWidth = 680;
int windowHeight = 350;
int left[12][48] = {{1,1,1,2,2,2,3,3,3,4,4,4,
    1,1,1,2,2,2,3,3,3,4,4,4,
    1,1,1,2,2,2,3,3,3,4,4,4,
    1,1,1,2,2,2,3,3,3,4,4,4},
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4},
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4},
    
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1},
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1},
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1},
    
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2},
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2},
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2},
    
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3},
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3},
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3}};

int right[12][48] = {{2,2,2,3,3,3,4,4,4,1,1,1,
    2,2,2,3,3,3,4,4,4,1,1,1,
    2,2,2,3,3,3,4,4,4,1,1,1,
    2,2,2,3,3,3,4,4,4,1,1,1},
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1},
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1},
    
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2},
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2},
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2},
    
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3},
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3},
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3},
    
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4},
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4},
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4}};

int top[12][48] = {{3,3,3,4,4,4,1,1,1,2,2,2,
    3,3,3,4,4,4,1,1,1,2,2,2,
    3,3,3,4,4,4,1,1,1,2,2,2,
    3,3,3,4,4,4,1,1,1,2,2,2},
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2},
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2},
    
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3},
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3},
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3},
    
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4},
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4},
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4},
    
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1},
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1},
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1}};

int bottom[12][48] = {{4,4,4,1,1,1,2,2,2,3,3,3,
    4,4,4,1,1,1,2,2,2,3,3,3,
    4,4,4,1,1,1,2,2,2,3,3,3,
    4,4,4,1,1,1,2,2,2,3,3,3},
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3},
    {4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3,
        4,4,4,1,1,1,2,2,2,3,3,3},
    
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4},
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4},
    {1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4,
        1,1,1,2,2,2,3,3,3,4,4,4},
    
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1},
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1},
    {2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1,
        2,2,2,3,3,3,4,4,4,1,1,1},
    
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2},
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2},
    {3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2,
        3,3,3,4,4,4,1,1,1,2,2,2}};

void drawLeftWall(void);
void drawRightWall(void);
void drawTopWall(void);
void drawBottomWall(void);
void sphere(void);
double sphX;
double sphY;
double sphZ;
double startingX, startingY, startingZ;
int signX, signY;
double speed;
// float epsilon = 0.000000001;
/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* el sphere el khafeya */
void sphere(){
    glPushMatrix();
    glTranslatef(startingX + sphX, startingY + sphY, startingZ - sphZ);
    glColor3f(1,0,0);
    glScalef(0.5, 0.5, 0);
    glutSolidSphere(0.5,30,30);
    glPopMatrix();
}

void madfa3() {
    glPushMatrix();
    glTranslatef(6, 5.8, -0.05);
    glColor3f(1,0.7,0);
    glScalef(0.5, 0.25, 0);
    int directionZ  = madfa3DirecH * 1;
    int directionY = madfa3DirecH * -1;
    int directionX = madfa3DircV + 45;
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glRotated(directionX,0,directionY, directionZ);
    gluCylinder(quadratic, 0.2, 0.2, 1, 30, 30);
    glPopMatrix();
}

void drawLeftWall(){
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 48; j++) {
            switch (left[i][j]) {
                case 1:
                    glColor3f(0.6f, 0.6f, 1.0f);
                    break;
                    
                case 2:
                    glColor3f(0.0f, 0.8f, 0.8f);
                    break;
                    
                case 3:
                    glColor3f(0.4f, 0.0f, 0.4f);
                    break;
                    
                case 4:
                    glColor3f(0.0f, 0.5f, 1);
                    break;
                    
                default:
                    break;
            }
            
            glVertex3f(0.0f,  (float)i+1, -((float)j+1));
            glVertex3f(0.0f, (float)i+1, -j);
            glVertex3f(0.0f, i,  -j);
            glVertex3f(0.0f,  i,  -((float)j+1));
        }
    }
}

void drawRightWall(){
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 48; j++) {
            switch (right[i][j]) {
                case 1:
                    glColor3f(0.6f, 0.6f, 1.0f);
                    break;
                    
                case 2:
                    glColor3f(0.0f, 0.8f, 0.8f);
                    break;
                    
                case 3:
                    glColor3f(0.4f, 0.0f, 0.4f);
                    break;
                    
                case 4:
                    glColor3f(0.0f, 0.5f, 1);
                    break;
                    
                default:
                    break;
            }
            
            glVertex3f(12.0f,  (float)i+1, -((float)j+1));
            glVertex3f(12.0f, (float)i+1, -j);
            glVertex3f(12.0f, i,  -j);
            glVertex3f(12.0f,  i,  -((float)j+1));
        }
    }
}

void drawTopWall(){
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 48; j++) {
            switch (top[i][j]) {
                case 1:
                    glColor3f(0.6f, 0.6f, 1.0f);
                    break;
                    
                case 2:
                    glColor3f(0.0f, 0.8f, 0.8f);
                    break;
                    
                case 3:
                    glColor3f(0.4f, 0.0f, 0.4f);
                    break;
                    
                case 4:
                    glColor3f(0.0f, 0.5f, 1);
                    break;
                    
                default:
                    break;
            }
            
            
            glVertex3f(i+1, 12.0f, -j);
            glVertex3f(i, 12.0f, -j);
            glVertex3f(i, 12.0f,  -(j+1));
            glVertex3f(i+1, 12.0f,  -(j+1));
        }
    }
}

void drawBottomWall(){
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 48; j++) {
            switch (bottom[i][j]) {
                case 1:
                    glColor3f(0.6f, 0.6f, 1.0f);
                    break;
                    
                case 2:
                    glColor3f(0.0f, 0.8f, 0.8f);
                    break;
                    
                case 3:
                    glColor3f(0.4f, 0.0f, 0.4f);
                    break;
                    
                case 4:
                    glColor3f(0.0f, 0.5f, 1);
                    break;
                    
                default:
                    break;
            }
            
            glVertex3f(i+1, 0.0f, -j);
            glVertex3f(i, 0.0f, -j);
            glVertex3f(i, 0.0f,  -(j+1));
            glVertex3f(i+1, 0.0f,  -(j+1));
        }
    }
}

void SetupLights()
{
    GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
    GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
    GLfloat mat_shininess[] = { 50 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    //set the light source properties
    GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
    GLfloat light_position[] = { -7.0f, 6.0f, 3.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    
    glLoadIdentity();// Reset the model-view matrix
    if(rotate) {
        gluLookAt(6.0, 6.0, 0.1, 6.0, 6.0, 0, cx, cy, cz);
        double tx = cx;
        double ty = cy;
        cx = (cosf(theta)*tx) - (sinf(theta)*ty);
        cy = (sinf(theta)*tx) + (cosf(theta)*ty);
    } else {
        gluLookAt(6.0, 6.0, 0.1, 6.0, 6.0, 0, 0, 12, 0);
    }
    
    glBegin(GL_QUADS);                // Begin drawing the room
    // Back wall (z = -48.0f)
    // Back wall (z = -48.0f)
    glColor3f(1.0f,0.9f, 0.0f);
    glVertex3f( 12.0f, 12.0f,  -48.0f);
    glVertex3f(0.0f, 12.0f,  -48.0f);
    glVertex3f(0.0f, 0.0f, -48.0f);
    glVertex3f(12.0f, 0.0f, -48.0f);
    
    drawTopWall();
    drawBottomWall();
    drawLeftWall();
    drawRightWall();
    
    glEnd();  // End of drawing room
    
    sphere(); //ersem el sphere
    madfa3(); //ersm el madfa3
    glFlush();
    glLoadIdentity();                  // Reset the model-view matrix
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
    
}

bool double_equals(double a, double b, double epsilon = 0.001)
{
    return std::abs(a - b) < epsilon;
}

/* Handler for window re-size event. Called back when the window first appears and
 whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {
    windowWidth = width;
    windowHeight = height;
    SetupLights();
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, aspect, 0.1f, 50.0f);
}

void repeat(void){
    sphX = sphY = sphZ = speed = 0;
    angle = 120;
    SetupLights();
    glViewport(0, 0, windowWidth, windowHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(angle > 15 && start){
        angle -= 0.09;
    }
    if(sphZ > -48 && start) {
        int zPosition = ceil(startingZ - sphZ);
        double xPosition = startingX + sphX;
        xPosition *= 10;
        xPosition /= 2.5;
        double yPosition = startingY + sphY;
        yPosition *= 10;
        yPosition /= 2.5;
        
        if(!(sphZ > 5.5 && sphX < 0.3 && sphX > -0.3 && sphY < 0.1 && sphY > -0.01)) {
            int div = 8;
            sphX += (signX * (0.02/div + speed));
            sphY += (signY * (speed + 0.05/div));
            sphZ += (0.002 + speed);
            speed += 0.000005;
        }
        
        gluPerspective(angle, (float)windowWidth/(float)windowHeight, 0.1f, 50.0f);
        glutPostRedisplay();
    }
    
}

void anim(void) {
    SetupLights();
    glViewport(0, 0, windowWidth, windowHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(angle > 15 && start){
        angle -= 0.09;
        // gluPerspective(angle, (float)windowWidth/(float)windowHeight, 0.1f, 50.0f);
        //  glutPostRedisplay();
        
    }
    if(sphZ > -48 && start) {
        int zPosition = ceil(startingZ - sphZ);
        double xPosition = startingX + sphX;
        xPosition *= 10;
        xPosition /= 2.5;
        double yPosition = startingY + sphY;
        yPosition *= 10;
        yPosition /= 2.5;

        if(5.5 + sphY > 7) {
        	// hit upper wall
        	switch(top[(int)yPosition][zPosition]) {
        		case 1:
        		score += 10;
        		break;
        		case 2:
        		score += 20;
        		break;
        		case 3:
        		score -= 30;
        		break;
        		default:
        		score += 40;
        		break;
        	}
            signY *= -1;
        }
        if(5.5 + sphY < 5) {
        	// hit bottom wall
        	switch(bottom[(int)yPosition][zPosition]) {
        		case 1:
        		score += 10;
        		break;
        		case 2:
        		score += 20;
        		break;
        		case 3:
        		score -= 30;
        		break;
        		default:
        		score += 40;
        		break;
        	}
        	signY *= -1;	
        }
        if(-0.5 + sphX > 1) {
        	// hit right wall
        	switch(right[(int)yPosition][zPosition]) {
        		case 1:
        		score += 10;
        		break;
        		case 2:
        		score += 20;
        		break;
        		case 3:
        		score -= 30;
        		break;
        		default:
        		score += 40;
        		break;
        	}
            signX *= -1;
        }
        if(-0.5 + sphX < -2) {
        	// hit left wall
        	switch(left[(int)yPosition][zPosition]) {
        		case 1:
        		score += 10;
        		break;
        		case 2:
        		score += 20;
        		break;
        		case 3:
        		score -= 30;
        		break;
        		default:
        		score += 40;
        		break;
        	}
        	signX *= -1;
        }
        if(!(sphZ > 5.5 && sphX < 0.3 && sphX > -0.3 && sphY < 0.1 && sphY > -0.01)) {
        	// std:: cout << "printing " << std::endl;
	        sphX += (signX * (0.02 + speed));
	        sphY += (signY * (speed + 0.05));
	        sphZ += 0.002 + speed;
	        speed += 0.000005;
    	}
        
        gluPerspective(angle, (float)windowWidth/(float)windowHeight, 0.1f, 50.0f);
        glutPostRedisplay();   
    }
}

void Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 's':
            start = true;
            break;
        case 'r':
            rotate = true;
            break;
        case 'p':
        	printf("Score is: %d\n", score);
        case 'a':
            repeat();
            break;

    }
}


void processSpecialKeys(int key, int x, int y) {
    if(!start) {
        switch(key) {
            case GLUT_KEY_LEFT :
                signX= -1;
                madfa3DirecH = -1;
                break;
            case GLUT_KEY_RIGHT :
                signX = 1;
                madfa3DirecH = 1;
                break;
            case GLUT_KEY_UP :
                signY = 1;
                madfa3DircV = 15;
                break;
            case GLUT_KEY_DOWN :
                signY = -1;
                madfa3DircV = -15;
                break;
        }
    }
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    sphZ = 0;
    speed = 0;
    startingX = 6;
    startingY = 5.5;
    startingZ = -0.2 ;
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(680, 350);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("Bouncing Ball");

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f,0.0f); // background is white
    glutIdleFunc(anim);//callig the anim func
    glutKeyboardFunc (Keyboard);
    glutSpecialFunc(processSpecialKeys);
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    
    initGL();// Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}