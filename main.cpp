//
//  main.cpp
//  25-2698_25-4602_25-5201_T10_T10_T10
//
//  Created by Almgohar on 11/27/14.
//  Copyright (c) 2014 Almgohar. All rights reserved.
//
#include <GLUT/glut.h>  // GLUT, include glu.h and gl.h
#include <OpenGL/OpenGL.h>
#include <ctime>
#include <stdlib.h>     /* srand, rand */



/* Global variables */
char title[] = "3D Shapes";
float angle = 120.0;
bool start;
int windowWidth = 680;
int windowHeight = 350;
float z = -5.0f;
int left[10][50];
int right[10][50];
int top[20][50];
int bottom[20][50];
void generateRandom(void);
void drawLeftWall(void);
double sphX;
double sphY;
double sphZ;
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
	glTranslatef(0.0,5.0,-1);
	glColor3f(0,0,0);
	// glScalef(-1.0,-1.0,-1.0);
	glutSolidSphere(0.3,20,20);
	glPopMatrix();
}

void drawLeftWall(){
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 4; j++) {
			srand(time(NULL));
			generateRandom();
			glVertex3f(-6.0f,  (float)j+3, -(float)i-6);
			glVertex3f(-6.0f, (float)j+3, (float)i);
			glVertex3f(-6.0f, (float)j,  (float)i);
			glVertex3f(-6.0f,  (float)j,  -(float)i-6);
			
		}
	}
}

void generateRandom(){
	int color = rand()%4 + 1;
	switch(color) {
		case 1: glColor3f(0.6f, 0.6f, 1.0f); break;
		case 2: glColor3f(0.0f, 0.8f, 0.8f); break;
		case 3: glColor3f(0.4f, 0.0f, 0.4f); break;
		case 4: glColor3f(0.0f, 0.5f, 1); break;
		default: glColor3f(0.0f,0.0f,0.0f); break;
	}
}

	


/* Handler for window-repaint event. Called back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
	// glMatrixMode(GL_PROJECTION); // set the view volume shape
	// glLoadIdentity();
	// glOrtho(-2.0*64/48.0, 2.0*64/48.0, -2.0, 2.0, 0.1, 100);
	// glMatrixMode(GL_MODELVIEW); // position and aim the camera
	// glLoadIdentity();
	// gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// glClear(GL_COLOR_BUFFER_BIT); // clear the screen
	
	// // glPushMatrix();
	// // glTranslated(0.5, 0.5, 0.5); // big cube at (0.5, 0.5, 0.5)
	// // glutWireCube(1.0);
	// // glPopMatrix();
	// glPushMatrix();
	// glTranslated(0,0,-2); // sphere at (1,1,0)
	// glutWireSphere(0.25, 10, 10);
	// glPopMatrix();
	// glFlush();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	
	glLoadIdentity();// Reset the model-view matrix
	gluLookAt(0.0, 6.0, 0.1, 0, 6.0, 0, 0.0, 12.0, 0.0);
	glTranslatef(0.5f, 0.0f, 0.0f);  // Move right and into the screen
	
	
	
	glBegin(GL_QUADS);                // Begin drawing the room
	// Top face (y = 12.0f)
	// Define vertices in counter-clockwise (CCW) order with normal pointing out
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex3f( 6.0f, 12.0f, 0.0f);
	glVertex3f(-6.0f, 12.0f, 0.0f);
	glVertex3f(-6.0f, 12.0f,  -48.0f);
	glVertex3f( 6.0f, 12.0f,  -48.0f);
	
//     // Back wall (z = -48.0f)
	glColor3f(1.0f,0.2f, 0.0f);
	glVertex3f( 6.0f, 12.0f,  -48.0f);
	glVertex3f(-6.0f, 12.0f,  -48.0f);
	glVertex3f(-6.0f, 0.0f, -48.0f);
	glVertex3f( 6.0f, 0.0f, -48.0f);
	
//     // bottom wall (y = 0.0f)
	glColor3f(0.0, 0.5f, 1.0f);
	glVertex3f( 6.0f, 0.0f, 0.0f);
	glVertex3f(-6.0f, 0.0f, 0.0f);
	glVertex3f(-6.0f,  0.0f, -48.0f);
	glVertex3f( 6.0f,  0.0f, -48.0f);
	
// //    // Left wall (x = -6.0f)
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-6.0f,  12.0f, -48.0f);
	glVertex3f(-6.0f, 12.0f, 0.0f);
	glVertex3f(-6.0f, 0.0f,  0.0f);
	glVertex3f(-6.0f,  0.0f,  -48.0f);
	
   // drawLeftWall();
	
//     // Right wall (x = 6.0f)
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(6.0f, 12.0f, 0.0f);
	glVertex3f(6.0f, 12.0f, -48.0f);
	glVertex3f(6.0f, 0.0f,  -48.0f);
	glVertex3f(6.0f, 0.0f, 0.0f);
	glEnd();  // End of drawing color-cube
	
	sphere(); //ersem el sphere

	glFlush();
	glLoadIdentity();                  // Reset the model-view matrix
	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

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
	for(int i=0;i<100000000;i++);
	SetupLights();
		glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(angle > 20 && start){
		angle-=3;
		z-= 1.0f;
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
			}
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
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
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	initGL();// Our own OpenGL initialization
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}
