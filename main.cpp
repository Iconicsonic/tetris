//
//  main.cpp
//  25-2698_25-4602_25-5201_T10_T10_T10
//
//  Created by el dou7 wa a3wano on 11/27/14.
//  Copyright (c) 2014 el dou7 wa a3wano. All rights reserved.
//
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <ctime>
#include <stdlib.h>     /* srand, rand */
#include <complex>
#include <iostream>


/* Global variables */
double theta  = 0.25*(3.141593f / 180);
double cx = 0.0;
double cy = 12.0;
double cz = 0.0;
char title[] = "3D Shapes";
float angle = 120.0;
bool start;
int score;
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
double sphereStartX, sphereStartY, sphereStartZ;
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
    // cout << sphX << " " << sphY << endl;
    // cout << "x axis " << (-0.5 + sphX) << endl;
    std::cout << "not at " << (6 + sphX) << std::endl;
    glTranslatef(6 + sphX, 5.5 + sphY, -0.2 - sphZ);
    glColor3f(0,0,0);
    glScalef(0.5, 0.5, 0);
    glutWireSphere(0.2,10,10);
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

/* Handler for window-repaint event. Called back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    
    glLoadIdentity();// Reset the model-view matrix
    gluLookAt(6.0, 6.0, 0.1, 6.0, 6.0, 0, cx, cy, cz);
    double tx = cx;
    double ty = cy;
    cx = (cosf(theta)*tx) - (sinf(theta)*ty);
    cy = (sinf(theta)*tx) + (cosf(theta)*ty);
    
    
    glBegin(GL_QUADS);                // Begin drawing the room
    // Back wall (z = -48.0f)
    glColor3f(1.0f,0.2f, 0.0f);
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
    
    glFlush();
    glLoadIdentity();                  // Reset the model-view matrix
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
    
}

bool double_equals(double a, double b, double epsilon = 0.001) {
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
        if(5.5 + sphY > 7) {
        	// hit upper wall
        	switch(top[12][ceil(sphereStartZ - sphZ)]) {
        		
        	}
            signY *= -1;
        }
        if(5.5 + sphY < 5) {
        	// hit bottom wall
        	signY *= -1;
        }
        if(-0.5 + sphX > 1) {
        	// hit right wall
            signX *= -1;
        }
        if(-0.5 + sphX < -2) {
        	// hit left wall
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

void Keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's':
            start = true;
            break;  
    }
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	speed = score = sphZ = 0;
	signX = signY = 1;
	sphereStartX = 6;
	sphereStartY = 5.5;
	sphereStartZ = -0.2;
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(680, 350);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner


    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f,0.0f); // background is white
    glutIdleFunc(anim);//callig the anim func
    glutKeyboardFunc (Keyboard);
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();// Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
