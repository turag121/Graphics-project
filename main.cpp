#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include<windows.h>
#include <vector>
#include <cstdlib>
#include <mmsystem.h>
#include <math.h>
#include<cstdio>
#define PI 3.141516



void renderBitmapString(float x, float y, float z, void *font, const char *string) {
    char *c;
    glRasterPos3f(x, y, z);
    for (c = (char*)string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void Intro() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    // Set text color
    glColor3f(0, 0, 0); // Custom color

    renderBitmapString(-0.4f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University-Bangladesh");
    renderBitmapString(-0.4f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "GRAPHICS PROJECT");
    renderBitmapString(-0.4f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "SECTION: I");
    renderBitmapString(-0.4f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "GROUP: 3");
    renderBitmapString(-0.4f, 0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "SHADES OF CIVILIZATION");
    renderBitmapString(-0.5f, 0.40f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "COURSE TEACHER:   NOBORANJAN DEY");
    renderBitmapString(-0.5f, 0.30f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "23-50652-1  -  TAHMID TAMJID TURAG");
    renderBitmapString(-0.5f, 0.20f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "23-50638-1  -  USWATUL HASAN NIBIR");
    renderBitmapString(-0.5f, 0.10f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "23-50624-1  -  ANUJA SARKER");
    renderBitmapString(-0.5f, 0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-49555-3  -  ASHADULLAH HIL GALIB");

    glFlush(); // Render now
}

///---------------------------------------------------------------------------------------------------------------------------------------------------///
float _move = 0.0f;
float _move2 = 0.0f;
float cloudPosition=-1.0;
float cloudSpeed=0.005;
float car_position1 = 0;
float car_speed1=0.01;
float man1Position=-0.3f;
float man1Speed=+0.008;
float man2Position=-0.4f;
float man2Speed=0.012;
float man3Position=0.8f;
float man3Speed=0.01;
float man4Position=0.9f;
float man4Speed=0.015;
float suv_car_position1 = 0.0f;;
float suv_car_speed1=0.01;
bool  vehiclesRunning = true;
bool  redLightOn = false;
bool  greenLightOn = true;
float icePosition=0.0f;
float iceSpeed=0.02;
bool isSnow= false;
float move_ship_container =-0.0f;
float container_ship_speed = 0.5f;


void circle(float radius, float cX, float cY, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float x = radius * cos(A);
        float y = radius * sin(A);
        glVertex2f(x+cX,y+cY);
    }
}

void sky19()
{

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(1.0f, 0.4f);
    glColor3ub(200,224,232);
    glVertex2f(1.0f, 1.0f);
    glColor3ub(255,255,255);
    glVertex2f(-1.0f, 1.0f);

    glEnd();
}

void hills()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.75f, 0.80f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.9f, 0.40f);
    glVertex2f(-0.60f, 0.40f);
    glEnd();


//hill1
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.85f, 0.90f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-1.1f, 0.40f);
    glVertex2f(-0.70f, 0.40f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.85f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.7f, 0.40f);
    glVertex2f(-0.3f, 0.40f);
    glEnd();

//hill2
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.65f, 0.7f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.8f, 0.40f);
    glVertex2f(-0.50f, 0.40f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.15f, 0.85f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.4f, 0.40f);
    glVertex2f(0.1f, 0.40f);
    glEnd();


//hill3

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.35f, 0.8f);
     glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.6f, 0.40f);
    glVertex2f(-0.20f, 0.40f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.22f, 0.8f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.1f, 0.40f);
    glVertex2f(0.5f, 0.40f);
    glEnd();


//hill4
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.65f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-0.35f, 0.40f);
    glVertex2f(0.20f, 0.40f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.5f, 0.9f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(0.2f, 0.40f);
    glVertex2f(0.7f, 0.40f);
    glEnd();



//hill5
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.25f, 0.55f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(0.10f, 0.40f);
    glVertex2f(0.40f, 0.40f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.72f, 0.9f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(0.45f, 0.40f);
    glVertex2f(0.95f, 0.40f);
    glEnd();

//hill6
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.55f, 0.65f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(0.40f, 0.40f);
    glVertex2f(0.75f, 0.40f);
    glEnd();


//hill7
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.95f, 0.82f);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(0.70f, 0.40f);
    glVertex2f(1.1f, 0.40f);
    glEnd();

}


void Wire()
{glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-1, 0.7);
    glVertex2f(1, 0.7);
    glVertex2f(1 ,0.702);
    glVertex2f(-1, 0.702);
    glEnd();

}


void river19()
{

    glBegin(GL_QUADS);
    glColor3f(.149,0.604, 0.839);
	glVertex2f(-1.0f,0.45f);
	glVertex2f(1.0f,0.45f);
	glVertex2f(1.0f,-0.85f);
    glVertex2f(-1.0f,-0.85f);
    glEnd();
}

 void road()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-1.0f, -0.67f);
    glVertex2f(-0.80f, -0.67f);
    glVertex2f(-0.80f, -0.7f);
    glVertex2f(-1.0f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.60f, -0.67f);
    glVertex2f(-0.40f, -0.67f);
    glVertex2f(-0.40f, -0.7f);
    glVertex2f(-0.60f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.20f, -0.67f);
    glVertex2f(0.00f, -0.67f);
    glVertex2f(0.00f, -0.7f);
    glVertex2f(-0.20f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(0.20f, -0.67f);
    glVertex2f(0.40f, -0.67f);
    glVertex2f(0.40f, -0.7f);
    glVertex2f(0.20f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(0.60f, -0.67f);
    glVertex2f(0.80f, -0.67f);
    glVertex2f(0.80f, -0.7f);
    glVertex2f(0.60f, -0.7f);
    glEnd();

}


void skatingroad()
{
    glBegin(GL_QUADS);
    glColor3f(209.0f / 255.0f, 227.0f / 255.0f, 255.0f / 255.0f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(-1.0f, -0.1f);
    glEnd();


}

void curvedBranch(float x0, float y0, float x1, float y1, float cx, float cy, float thickness) {
    int segments = 20;
    float t;

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.3f, 0.2f, 0.0f);

    for (int i = 0; i <= segments; i++) {
        t = (float)i / segments;


        float x = (1 - t) * (1 - t) * x0 + 2 * (1 - t) * t * cx + t * t * x1;
        float y = (1 - t) * (1 - t) * y0 + 2 * (1 - t) * t * cy + t * t * y1;


        float dx = -(y1 - y0);
        float dy = (x1 - x0);
        float len = sqrt(dx * dx + dy * dy);
        dx = (dx / len) * (thickness * (1 - t));
        dy = (dy / len) * (thickness * (1 - t));

        glVertex2f(x + dx, y + dy);
        glVertex2f(x - dx, y - dy);
    }

    glEnd();
}


 void tree1()
{
    //tree1

    glScalef(1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, -.1);
    glVertex2f(0.064f, -.1);
    glVertex2f(0.064f, 0.03);
    glVertex2f(0.048f, 0.03);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,-0.03);
    glVertex2f(0.081f,-0.03);
    glVertex2f(0.06f,0.18);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,-0.02);
    glVertex2f(0.082f,-0.02);
    glVertex2f(0.07f,0.14);
    glEnd();

    glLoadIdentity();


    //tree2

    glScalef(-1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, -.1);
    glVertex2f(0.064f, -.1);
    glVertex2f(0.064f, -0.03);
    glVertex2f(0.048f, -0.03);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,-0.03);
    glVertex2f(0.081f,-0.03);
    glVertex2f(0.06f,0.18);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,-0.02);
    glVertex2f(0.082f,-0.02);
    glVertex2f(0.07f,0.14);
    glEnd();

    glLoadIdentity();

//trunk
glBegin(GL_QUADS);
    glColor3f(0.3f, 0.2f, 0.0f);
    glVertex2f(0.59f,-0.15f);
    glVertex2f(0.633f,-0.15f);
    glVertex2f(0.623f,0.066f);
    glVertex2f(0.595f,0.066f);
    glEnd();
    //1left

    curvedBranch(
        0.63f, -0.17f,
        0.69f,  0.1f,
        0.59f,  0.0f,
        0.018f
    );
    //1right
    curvedBranch(
        0.596f, -0.17f,
        0.54f,  0.1f,
        0.62f,   0.0f,
        0.018f
    );
    //2right
    // Left curved branch
    curvedBranch(0.62f, 0.01f,
                 0.67f, 0.18f,
                 0.63f, 0.09f,
                 0.01f);

    //middle
    curvedBranch(
        0.62f, 0.01f,
        0.598f, 0.18f,
        0.61f, 0.09f,
        0.015f
    );

    //2nd left
    curvedBranch(
        0.595f, 0.016f,
        0.56f, 0.18f,
        0.595f, 0.09f,
        0.01f
    );


    circle(0.045f, 0.72f, 0.085f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.04f, 0.69f, 0.06f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.02f, 0.66f, 0.062f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.04f, 0.68f, 0.09f, 0.0f, 0.8f, 0.0f);
    glEnd();


    circle(0.03f, 0.51f, 0.07f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.045f, 0.5f, 0.088f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.02f, 0.55f, 0.04f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.05f, 0.545f, 0.085f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.02f, 0.55f, 0.12f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f, 0.6f, 0.13f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f, 0.58f, 0.12f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f, 0.63f, 0.12f, 0.0f, 0.4f, 0.0f);
    glEnd();


    circle(0.05f, 0.55f, 0.16f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.05f, 0.62f, 0.155f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.05f, 0.68f, 0.15f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.055f, 0.49f, 0.163f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.65f, 0.18f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.72f, 0.163f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.04f, 0.54f, 0.18f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.04f, 0.67f, 0.18f, 0.0f, 0.4f, 0.0f);
    glEnd();

    circle(0.055f, 0.5f, 0.20f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.55f, 0.21f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.62f, 0.21f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.7f, 0.2f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.055f, 0.49f, 0.24f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.55f, 0.26f, 0.0f, 0.77f, 0.0f);
    glEnd();
    circle(0.055f, 0.62f, 0.26f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.65f, 0.27f, 0.0f, 0.77f, 0.0f);
    glEnd();
    circle(0.055f, 0.72f, 0.22f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.055f, 0.5f, 0.28f, 0.0f, 0.85f, 0.0f);
    glEnd();
    circle(0.055f, 0.55f, 0.3f, 0.0f, 0.85f, 0.0f);
    glEnd();
    circle(0.055f, 0.57f, 0.34f, 0.0f, 0.85f, 0.0f);
    glEnd();
    circle(0.055f, 0.58f, 0.28f, 0.0f, 0.85f, 0.0f);
    glEnd();
    circle(0.055f, 0.65f, 0.32f, 0.0f, 0.85f, 0.0f);
    glEnd();
    circle(0.055f, 0.7f, 0.28f, 0.0f, 0.85f, 0.0f);
    glEnd();


    glLoadIdentity();

}

void Bigtree()
{
        glPushMatrix();
    glTranslatef(-1.2f, -0.1f, 0);
glScalef(1.0f, 0.9f, 0.0f);

    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.2f, 0.0f);
        glVertex2f(0.59f,-0.15f);
        glVertex2f(0.633f,-0.15f);
        glVertex2f(0.623f,0.066f);
        glVertex2f(0.595f,0.066f);
        glEnd();
        //1left
    curvedBranch(
        0.63f, -0.17f,
        0.69f,  0.1f,
        0.59f,  0.0f,
        0.018f
    );
    //1right
    curvedBranch(
        0.596f, -0.17f,
        0.54f,  0.1f,
        0.62f,   0.0f,
        0.018f
    );
    //2right
    // Left curved branch
    curvedBranch(0.62f, 0.01f,
                 0.67f, 0.18f,
                 0.63f, 0.09f,
                 0.01f);

    //middle
    curvedBranch(
        0.62f, 0.01f,
        0.598f, 0.18f,
        0.61f, 0.09f,
        0.015f
    );

    //2nd left
    curvedBranch(
        0.595f, 0.016f,
        0.56f, 0.18f,
        0.595f, 0.09f,
        0.01f
    );


    circle(0.04f, 0.7f, 0.092f, 0.0f, 0.75f, 0.0f); glEnd();
    circle(0.02f, 0.66f, 0.062f, 0.0f, 0.4f, 0.0f); glEnd();
    circle(0.04f, 0.68f, 0.09f, 0.0f, 0.8f, 0.0f); glEnd();

    circle(0.04f, 0.52f, 0.092f, 0.0f, 0.75f, 0.0f); glEnd();
    circle(0.03f, 0.55f, 0.06f, 0.0f, 0.4f, 0.0f); glEnd();
    circle(0.04f, 0.545f, 0.08f, 0.0f, 0.8f, 0.0f); glEnd();

    circle(0.03f, 0.55f, 0.11f, 0.0f, 0.4f, 0.0f); glEnd();
    circle(0.03f, 0.65f, 0.13f, 0.0f, 0.4f, 0.0f); glEnd();
    circle(0.03f, 0.6f, 0.12f, 0.0f, 0.4f, 0.0f); glEnd();

    circle(0.05f, 0.55f, 0.145f, 0.0f, 0.8f, 0.0f); glEnd();
    circle(0.05f, 0.62f, 0.155f, 0.0f, 0.8f, 0.0f); glEnd();

    circle(0.045f, 0.57f, 0.18f, 0.0f, 0.8f, 0.0f); glEnd();
    circle(0.045f, 0.655f, 0.19f, 0.0f, 0.8f, 0.0f); glEnd();
    circle(0.038f, 0.68f, 0.14f, 0.0f, 0.8f, 0.0f); glEnd();


    circle(0.05f, 0.56f, 0.21f, 0.0f, 0.85f, 0.0f); glEnd();
    circle(0.055f, 0.63f, 0.24f, 0.0f, 0.85f, 0.0f); glEnd();
    circle(0.045f, 0.58f, 0.24f, 0.0f, 0.85f, 0.0f); glEnd();
    circle(0.05f, 0.65f, 0.2f, 0.0f, 0.85f, 0.0f); glEnd();

    glPopMatrix();


}

void cable2(){

    glBegin(GL_POLYGON);
    glColor3f(0.502f, 0.0f, 0.0f);
    glVertex2f(0.55, 0.702);
    glVertex2f(0.5581, 0.702);
    glVertex2f(0.5577206393564, 0.6422895175778);
    glVertex2f(0.5498433631957, 0.6430772451939);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(0.5117919786159, 0.6422895175778);
    glVertex2f(0.6047438373113, 0.6418956537698);
     glVertex2f(0.6189229344005, 0.5906933587257);
    glVertex2f(0.4980067453348, 0.5899056311096);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.502f, 0.0f, 0.0f);
    glVertex2f(0.4980067453348, 0.5899056311096);
    glVertex2f(0.6189229344005, 0.5906933587257);
    glVertex2f(0.607105317983, 0.5492227572163);
    glVertex2f(0.5099011999664, 0.5507415715603);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.502f, 0.0f, 0.0f);
    glVertex2f(0.5269333376212, 0.6434318867888);
    glVertex2f (0.52,0.59);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.502f, 0.0f, 0.0f);
    glVertex2f(0.58,0.64);
    glVertex2f(0.59,0.590);
    glEnd();

}

void cable(){
    glBegin(GL_POLYGON);
    glColor3f(0.502f, 0.0f, 0.0f);
    glVertex2f(-0.5696, 0.702);
    glVertex2f(-0.5596, 0.702);
    glVertex2f(-0.5584950286975, 0.644888102843);
    glVertex2f(-0.56982461821, 0.644888102843);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-0.6127577995204, 0.6454843970279);
    glVertex2f(-0.5233611918577, 0.6451961499495);
    glVertex2f(-0.5059953634307, 0.5929886490722);
    glVertex2f(-0.6280481778946, 0.5937889953966);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.502f, 0.0f, 0.0f);
    glVertex2f(-0.6280481778946, 0.5937889953966);
    glVertex2f(-0.5059953634307, 0.5929886490722);
    glVertex2f(-0.5208017704313, 0.5541718523411);
    glVertex2f(-0.615242636705, 0.5549721986654);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.502f, 0.0f, 0.0f);

    glVertex2f(-0.59,0.59);
    glVertex2f (-0.597,0.64);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.502f, 0.0f, 0.0f);
    glVertex2f(-0.535,0.59);
    glVertex2f (-0.53,0.64);

    glEnd();
}


void drawcable(){
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    cable();
    glPopMatrix();
}

void drawcable2(){
    glPushMatrix();
    glTranslatef(_move2, 0.0f, 0.0f);
    cable2();
    glPopMatrix();


}


 void update(int value) {
    _move += 0.002;

        if (_move > 1.96) {
     _move = -1.0f;
    }

    _move2 -= 0.002;
    if(_move2<-1.96)
    {
    _move2= +1.0;
    }

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

void circle1(float p1, float q1, float r1)
{
    int i;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glVertex2f (p1,q1);
    for(i= 0; i<=tringle2; i++)
    {
        glVertex2f (
            p1+(r1*cos(i*tp2/tringle2)),
            q1+(r1*sin(i*tp2/tringle2))
        );
    }
    glEnd();
}

void Cloud()
{
    glColor3f(1, 1, 1);

    glPushMatrix();
    glTranslatef(cloudPosition+0.48, 0.9, 0);

    // First cloud
    circle1(-0.42, -0.05, 0.05f);
    circle1(-0.46, -0.10, 0.05f);
    circle1(-0.39, -0.10, 0.05f);

    // Second cloud
    circle1(0.08, 0.05, 0.05f);
    circle1(0.04, 0.00, 0.05f);
    circle1(0.11, 0.00, 0.05f);

    // Third cloud
    circle1(0.38, -0.05, 0.05f);
    circle1(0.34, -0.1, 0.05f);
    circle1(0.41, -0.1, 0.05f);

    glPopMatrix();
}
void update_cloud(int value)        ///AFID-1
{
    cloudPosition+=cloudSpeed;
    if(cloudPosition>1.0)
    {
        cloudPosition=-1.7;
    }

    glutPostRedisplay();
    glutTimerFunc(80, update_cloud, 0);
}


void snowman()
{

    glColor3f(1,1,1);
    circle1(0.744f, -0.229f, 0.054f);
    circle1(0.745f, -0.335f, 0.075f);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(0.72,-0.18);
    glVertex2f(0.74,-0.15);
    glVertex2f(0.79,-0.15);
    glVertex2f(0.84,-0.18);
    glVertex2f(0.80,-0.18);
    glVertex2f(0.78,-0.19);

    glEnd();

     glBegin(GL_TRIANGLES);
    glColor3f(1, .549, 0);
    glVertex2f(0.75, -0.25);
    glVertex2f(0.70, -0.245);
    glVertex2f(0.75, -0.23);
    glEnd();

    glColor3f(0, 0, 0);
    circle1(0.77, -0.22, 0.01f);


   glColor3f(0, 0, 0);
   circle1(0.72, -0.22, 0.01f);


}

void hill2()
{

    glPopMatrix();

    // Rotated (180° flip around X-axis → -Y)
    glPushMatrix();
    glTranslatef(0.0f, 0.56f, 0.0f);
    glRotatef(105.0f, 1.0f, 0.0f, 0.0f);
    // hill 0

    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(-0.75f, 0.80f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(-0.9f, 0.40f);
    glVertex2f(-0.60f, 0.40f);
    glEnd();

    // Hill 1 - left
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(-0.85f, 0.90f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(-1.1f, 0.40f);
    glVertex2f(-0.70f, 0.40f);
    glEnd();

    // Hill 1 - right
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(-0.5f, 0.85f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(-0.7f, 0.40f);
    glVertex2f(-0.3f, 0.40f);
    glEnd();

    // Hill 2 - left
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(-0.65f, 0.7f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(-0.8f, 0.40f);
    glVertex2f(-0.50f, 0.40f);
    glEnd();

    // Hill 2 - right
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(-0.15f, 0.85f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(-0.4f, 0.40f);
    glVertex2f(0.1f, 0.40f);
    glEnd();

    // Hill 3 - left
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(-0.35f, 0.8f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(-0.6f, 0.40f);
    glVertex2f(-0.20f, 0.40f);
    glEnd();

    // Hill 3 - right
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(0.22f, 0.8f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(-0.1f, 0.40f);
    glVertex2f(0.5f, 0.40f);
    glEnd();

    // Hill 4 - left
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(0.0f, 0.65f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(-0.35f, 0.40f);
    glVertex2f(0.20f, 0.40f);
    glEnd();

    // Hill 4 - right
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(0.5f, 0.9f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(0.2f, 0.40f);
    glVertex2f(0.7f, 0.40f);
    glEnd();

    // Hill 5 - left
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(0.25f, 0.55f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(0.10f, 0.40f);
    glVertex2f(0.40f, 0.40f);
    glEnd();

    // Hill 5 - right
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(0.72f, 0.9f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(0.45f, 0.40f);
    glVertex2f(0.95f, 0.40f);
    glEnd();

    // Hill 6
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(0.55f, 0.65f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(0.40f, 0.40f);
    glVertex2f(0.75f, 0.40f);
    glEnd();

    // Hill 7
    glBegin(GL_TRIANGLES);
    glColor4f(0.4f, 0.6f, 0.7f, 0.4f);
    glVertex2f(0.95f, 0.82f);
    glColor4f(0.0f, 0.25f, 0.35f, 0.4f);
    glVertex2f(0.70f, 0.40f);
    glVertex2f(1.1f, 0.40f);
    glEnd();
        glPopMatrix();
}

void road_border()
{
    glPushMatrix();

    glTranslatef(0.0f, -1.75f, 0.0f);
    glScalef(1.5f, 2.5f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(-1, 0.49);
    glVertex2f(1, 0.49);
    glVertex2f(1 ,0.50);
    glVertex2f(-1, 0.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-1, 0.49);
    glVertex2f(-0.98, 0.49);
    glVertex2f(-0.98 ,0.50);
    glVertex2f(-1, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.9, 0.49);
    glVertex2f(-0.8, 0.49);
    glVertex2f(-0.8 ,0.50);
    glVertex2f(-0.9, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.7, 0.49);
    glVertex2f(-0.6, 0.49);
    glVertex2f(-0.6 ,0.50);
    glVertex2f(-0.7, 0.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.5, 0.49);
    glVertex2f(-0.4, 0.49);
    glVertex2f(-0.4 ,0.50);
    glVertex2f(-0.5, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.3, 0.49);
    glVertex2f(-0.2, 0.49);
    glVertex2f(-0.2 ,0.50);
    glVertex2f(-0.3, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.1, 0.49);
    glVertex2f(-0.05, 0.49);
    glVertex2f(-0.05 ,0.50);
    glVertex2f(-0.1, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.0, 0.49);
    glVertex2f(0.05, 0.49);
    glVertex2f(0.05,0.50);
    glVertex2f(0.0, 0.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.15, 0.49);
    glVertex2f(0.2, 0.49);
    glVertex2f(0.2 ,0.50);
    glVertex2f(0.15, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.35, 0.49);
    glVertex2f(0.4, 0.49);
    glVertex2f(0.4 ,0.50);
    glVertex2f(0.35, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.55, 0.49);
    glVertex2f(0.6, 0.49);
    glVertex2f(0.6 ,0.50);
    glVertex2f(0.55, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.65, 0.49);
    glVertex2f(0.7, 0.49);
    glVertex2f(0.7 ,0.50);
    glVertex2f(0.65, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.85, 0.49);
    glVertex2f(0.9, 0.49);
    glVertex2f(0.9 ,0.50);
    glVertex2f(0.85, 0.50);
    glEnd();

    glPopMatrix();
}

void car()
{
    float cy=0.3;
    glPushMatrix();
    glRotatef(-1,0,1,0);
    glTranslatef(car_position1+0.5,0,0);
    glScalef(-1,1,0);
    ///police car
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 1.0f);
    glVertex2f(0.37f, -0.77f+cy);
    glVertex2f(0.35f, -0.89f+cy);
    glVertex2f(0.7f, -0.89f+cy);
    glVertex2f(0.69f, -0.77f+cy);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.34f, -0.87f+cy);
    glVertex2f(0.34f, -0.89f+cy);
    glVertex2f(0.37f, -0.89f+cy);
    glVertex2f(0.37f, -0.87f+cy);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.68f, -0.87f+cy);
    glVertex2f(0.68f, -0.89f+cy);
    glVertex2f(0.72f, -0.89f+cy);
    glVertex2f(0.72f, -0.87f+cy);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.366f, -0.79f+cy);
    glVertex2f(0.363f, -0.81f+cy);
    glVertex2f(0.39f, -0.81f+cy);
    glVertex2f(0.39f, -0.79f+cy);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.4f, -0.79f+cy);
    glVertex2f(0.4f, -0.81f+cy);
    glVertex2f(0.66f, -0.81f+cy);
    glVertex2f(0.66f, -0.79f+cy);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.67f, -0.79f+cy);
    glVertex2f(0.67f, -0.81f+cy);
    glVertex2f(0.695f, -0.81f+cy);
    glVertex2f(0.693f, -0.79f+cy);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.46f, -0.7f+cy);
    glVertex2f(0.41f, -0.77f+cy);
    glVertex2f(0.65f, -0.77f+cy);
    glVertex2f(0.62f, -0.7f+cy);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.465f, -0.715f+cy);
    glVertex2f(0.42f, -0.77f+cy);
    glVertex2f(0.52f, -0.77f+cy);
    glVertex2f(0.52f, -0.715f+cy);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.53f, -0.715f+cy);
    glVertex2f(0.53f, -0.77f+cy);
    glVertex2f(0.64f, -0.77f+cy);
    glVertex2f(0.615f, -0.715f+cy);
    glEnd();

    ///wheel
    glScalef(0.2,0.2,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.03,y-2.95);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.03,y-2.95);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.23,y-2.95);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.23,y-2.95);
    }
    glEnd();
    glLoadIdentity();
}

void suv()
{
    float cx = 5.5;
    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(suv_car_position1-2.0,0,0);
    glScalef(0.14,0.14,0);
    ///car Body
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.90,0.3,0.0);
    glVertex2f(-3.0f, 0.0-cx);
    glVertex2f(-3.0f, 0.8-cx);
    glVertex2f(-0.7f, 0.8-cx);
    glVertex2f(-0.5f, 0.55-cx);
    glVertex2f(-0.5f, 0.0-cx);
    glEnd();

    ///car UP
    glBegin(GL_QUADS);
    glColor3f(1.,1.0,1.0);
    glVertex2f(-3.0f, 0.8f-cx);
    glVertex2f(-2.7f, 1.3f-cx);
    glVertex2f(-1.7f, 1.3f-cx);
    glVertex2f(-1.35f, 0.8f-cx);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-2.9f, 0.8f-cx);
    glVertex2f(-2.6f, 1.23f-cx);
    glVertex2f(-2.15f, 1.23f-cx);
    glVertex2f(-2.15f, 0.8f-cx);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-2.05f, 0.8f-cx);
    glVertex2f(-2.05f, 1.23f-cx);
    glVertex2f(-1.75f, 1.23f-cx);
    glVertex2f(-1.45f, 0.8f-cx);
    glEnd();

    ///Wheel
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.38;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.05-cx,y-5.45);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.05-cx,y-5.45);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.38;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+4.45-cx,y-5.45);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+4.45-cx,y-5.45);
    }
    glEnd();
    glPopMatrix();
    glLoadIdentity();
}



void updateVehicals(int value)                  ///AFID-7
{
    if(vehiclesRunning)
    {
    car_position1+=car_speed1;
    if (car_position1>=1.5)
    {
        car_position1=-1.2;
    }

   suv_car_position1+=suv_car_speed1;
     if (suv_car_position1<=-0.9)
    {
        suv_car_position1=+1.0;
    }
    }

    glutPostRedisplay();

    glutTimerFunc(30, updateVehicals, 0);
}


void human(float red, float green, float blue)
{
    /// Shirt
    glBegin(GL_QUADS);
    glColor3f(red, green, blue);
    glVertex2f(0.0f, -0.13f);
    glVertex2f(0.035f, -0.13f);
    glVertex2f(0.035f, -0.06f);
    glVertex2f(0.0f, -0.06f);
    glEnd();

    /// Left hand
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.7f);
    glVertex2f(0.0f,-0.145f);
    glVertex2f(-0.0075f,-0.145f);
    glVertex2f(-0.006f,-0.06f);
    glVertex2f(0.0f,-0.06f);
    glEnd();

    /// Left hand sleeve
    glBegin(GL_QUADS);
    glColor3f(red, green, blue);
    glVertex2f(0.0f,-0.1f);
    glVertex2f(-0.0075f,-0.1f);
    glVertex2f(-0.006f,-0.06f);
    glVertex2f(0.0f,-0.06f);
    glEnd();

    /// Right hand
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.7f);
    glVertex2f(0.035f,-0.145f);
    glVertex2f(0.0425f,-0.145f);
    glVertex2f(0.041f,-0.06f);
    glVertex2f(0.035f,-0.06f);
    glEnd();

    /// Right hand sleeve
    glBegin(GL_QUADS);
    glColor3f(red, green, blue);
    glVertex2f(0.035f,-0.1f);
    glVertex2f(0.0425f,-0.1f);
    glVertex2f(0.041f,-0.06f);
    glVertex2f(0.035f,-0.06f);
    glEnd();

    /// Legs
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.6f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(0.01f, -0.2f);
    glVertex2f(0.035f, -0.13f);
    glVertex2f(0.0f, -0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.6f);
    glVertex2f(0.025f, -0.2f);
    glVertex2f(0.035f, -0.2f);
    glVertex2f(0.035f, -0.13f);
    glVertex2f(0.015f, -0.16f);
    glEnd();

    /// Shoes
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, -0.22f);
    glVertex2f(0.01f, -0.22f);
    glVertex2f(0.01f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.025f, -0.22f);
    glVertex2f(0.035f, -0.22f);
    glVertex2f(0.035f, -0.2f);
    glVertex2f(0.025f, -0.2f);
    glEnd();

    /// Neck
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0125f, -0.06f);
    glVertex2f(0.0225f, -0.06f);
    glVertex2f(0.0225f, -0.04f);
    glVertex2f(0.0125f, -0.04f);
    glEnd();

    /// Face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.005f, -0.04f);
    glVertex2f(0.03f, -0.04f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.005f, 0.0f);
    glEnd();

    /// Hat
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.005f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.025f, 0.03f);
    glVertex2f(0.01f, 0.03f);
    glEnd();
}

void drawHuman(float red, float green, float blue, float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    human(red, green, blue);
    glPopMatrix();
}

void updateHuman(int value)
{

    man2Position+=man2Speed;
    if(man2Position>1.0)
    {
        man2Position=-1.0;
    }
    man1Position-=man1Speed;
    if(man1Position<-1.0)
    {
        man1Position=+1.0;
    }
    man4Position-=man4Speed;
    if(man4Position<-1.0)
    {
        man4Position=+1.0;
    }
    glutPostRedisplay();
    glutTimerFunc(100, updateHuman, 0);
}

void trafficLight()
{

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.01f, -0.5f);
    glVertex2f(0.01f, -0.5f);
    glVertex2f(0.01f, -0.2f);
    glVertex2f(-0.01f, -0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(-0.04f, -0.2f);
    glVertex2f(0.04f, -0.2f);
    glVertex2f(0.04f, -0.05f);
    glVertex2f(-0.04f, -0.05f);
    glEnd();


    if (redLightOn)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.3f, 0.0f, 0.0f);
    circle1(0.0f, -0.08f, 0.015f);


    glColor3f(0.3f, 0.3f, 0.0f);
    circle1(0.0f, -0.12f, 0.015f);


    if (greenLightOn)
        glColor3f(0.0f, 1.0f, 0.0f);
    else
        glColor3f(0.0f, 0.3f, 0.0f);
    circle1(0.0f, -0.165f, 0.015f);
}


void snow_fall()
{
    glPushMatrix();
    glTranslatef(0,icePosition, 0);
    for(float x=-0.95; x<=1; x+=0.1)
    {
        glPointSize(4.4);
        glColor3f(1,1,1);
        glBegin(GL_POINTS);
        for(float y=-1; y<=1; y+=0.1)
        {
            glVertex2f(0.0+x, -1.0+y);
            glVertex2f(0.0+x, 0.0+y);
            glVertex2f(0.0+x, 1.0+y);
        }
        glEnd();
    }
    glPopMatrix();

}

void weather_update(int value)          ///AFID-9
{
    icePosition-=iceSpeed;
    if(icePosition<-1.0)
    {
        icePosition=1;
    }

    glutPostRedisplay();
    glutTimerFunc(60, weather_update, 0);
}

void ships()                                    ///OID-11
{
/// ship1

    float Z=200.00;

    glColor3f(0,0,0);
    glPushMatrix();
    glScalef(0.0055,0.0025,0);
    glTranslatef(move_ship_container, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(10.0f,-170.0f+Z);
    glVertex2f(110.0f,-170.0f+Z);
    glVertex2f(110.0f,-140.0f+Z);
    glVertex2f(10.0f,-140.0f+Z);
    glEnd();

    ///middle white
    glColor3f(0.698f, 0.745f, 0.710f);
    glBegin(GL_QUADS);
    glVertex2f(10.0f,-140.0f+Z);
    glVertex2f(110.0f,-140.0f+Z);
    glVertex2f(110.0f,-120.0f+Z);
    glVertex2f(10.0f,-120.0f+Z);
    glEnd();

    ///deck room
    glColor3f(0.7745f, 0.510f, 0.706f);
    glBegin(GL_QUADS);
    glVertex2f(18.0f,-120.0f+Z);
    glVertex2f(40.0f,-120.0f+Z);
    glVertex2f(40.0f,-50.0f+Z);
    glVertex2f(18.0f,-50.0f+Z);
    glEnd();

    ///deck roof top
    glColor3f(0.8196f, 0.682f, 0.1216f);
    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glVertex2f(13.0f,-50.0f+Z);
    glVertex2f(43.0f,-50.0f+Z);
    glEnd();

    ///body to deck line1
    glColor3f(0.8196f, 0.682f, 0.1216f);
    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glVertex2f(14.0f,-100.0f+Z);
    glVertex2f(14.0f,-50.0f+Z);
    glEnd();

    ///body to deck line2
    glColor3f(0.8196f, 0.682f, 0.1216f);
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glVertex2f(18.0f,-100.0f+Z);
    glVertex2f(18.0f,-50.0f+Z);
    glEnd();

    ///upper white tail part
    glColor3ub(209,174,31);
    glBegin(GL_QUADS);
    glVertex2f(10.0f,-120.0f+Z);
    glVertex2f(40.0f,-120.0f+Z);
    glVertex2f(35.0f,-100.0f+Z);
    glVertex2f(10.0f,-100.0f+Z);
    glEnd();

    ///upper white front part
    glColor3ub(155,155,255);
    glBegin(GL_QUADS);
    glVertex2f(85.0f,-120.0f+Z);
    glVertex2f(110.0f,-120.0f+Z);
    glVertex2f(120.0f,-90.0f+Z);
    glVertex2f(90.0f,-90.0f+Z);
    glEnd();

    ///left first container
    glColor3f(0.545f, 0.271f, 0.0745f);
    glBegin(GL_QUADS);
    glVertex2f(45.0f,-120.0f+Z);
    glVertex2f(62.0f,-120.0f+Z);
    glVertex2f(62.0f,-85.0f+Z);
    glVertex2f(45.0f,-85.0f+Z);
    glEnd();


    ///left second container
    glColor3f(1.0f, 0.647f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(65.0f,-120.0f+Z);
    glVertex2f(82.0f,-120.0f+Z);
    glVertex2f(82.0f,-85.0f+Z);
    glVertex2f(65.0f,-85.0f+Z);
    glEnd();

    ///top container
    glColor3f(1.0f, 0.498f, 0.314f);
    glBegin(GL_QUADS);
    glVertex2f(56.5f,-85.0f+Z);
    glVertex2f(73.5f,-85.0f+Z);
    glVertex2f(73.5f,-50.0f+Z);
    glVertex2f(56.5f,-50.0f+Z);
    glEnd();

    glPopMatrix();
    glLoadIdentity();

}

void update_ship(int value)
{
    if(move_ship_container>=211.90)
    {
        move_ship_container = -320;
    }
    glutPostRedisplay();
    move_ship_container += container_ship_speed ;
    glutTimerFunc(20, update_ship, 0);
}

void BigtreeS()
{
        glPushMatrix();
    glTranslatef(-1.2f, -0.1f, 0);
glScalef(1.0f, 0.9f, 0.0f);

    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.2f, 0.0f);
        glVertex2f(0.59f,-0.15f);
        glVertex2f(0.633f,-0.15f);
        glVertex2f(0.623f,0.066f);
        glVertex2f(0.595f,0.066f);
        glEnd();
        //1left
    curvedBranch(
        0.63f, -0.17f,
        0.69f,  0.1f,
        0.59f,  0.0f,
        0.018f
    );
    //1right
    curvedBranch(
        0.596f, -0.17f,
        0.54f,  0.1f,
        0.62f,   0.0f,
        0.018f
    );
    //2right
    // Left curved branch
    curvedBranch(0.62f, 0.01f,
                 0.67f, 0.18f,
                 0.63f, 0.09f,
                 0.01f);

    //middle
    curvedBranch(
        0.62f, 0.01f,
        0.598f, 0.18f,
        0.61f, 0.09f,
        0.015f
    );

    //2nd left
    curvedBranch(
        0.595f, 0.016f,
        0.56f, 0.18f,
        0.595f, 0.09f,
        0.01f
    );



    circle(0.02f, 0.66f, 0.062f, 0.0f, 0.4f, 0.0f); glEnd();
    circle(0.04f, 0.68f, 0.09f, 0.0f, 0.8f, 0.0f); glEnd();

    circle(0.03f, 0.55f, 0.06f, 0.0f, 0.4f, 0.0f); glEnd();
    circle(0.04f, 0.545f, 0.08f, 0.0f, 0.8f, 0.0f); glEnd();

    circle(0.03f, 0.55f, 0.11f, 0.0f, 0.4f, 0.0f); glEnd();
    circle(0.03f, 0.65f, 0.13f, 0.0f, 0.4f, 0.0f); glEnd();
    circle(0.03f, 0.6f, 0.12f, 0.0f, 0.4f, 0.0f); glEnd();

    circle(0.05f, 0.55f, 0.145f, 0.5f, 0.85f, 0.6f); glEnd();
    circle(0.05f, 0.62f, 0.155f, 0.5f, 0.85f, 0.6f); glEnd();

    circle(0.045f, 0.57f, 0.18f, 0.5f, 0.85f, 0.6f); glEnd();
    circle(0.045f, 0.655f, 0.19f, 0.5f, 0.85f, 0.6f); glEnd();
    circle(0.038f, 0.68f, 0.14f, 0.5f, 0.85f, 0.6f); glEnd();


    circle(0.05f, 0.56f, 0.21f, 0.7f, 0.95f, 0.7f );glEnd();
    circle(0.055f, 0.63f, 0.24f, 0.7f, 0.95f, 0.7f); glEnd();
    circle(0.045f, 0.58f, 0.24f, 0.7f, 0.95f, 0.7f); glEnd();
    circle(0.05f, 0.65f, 0.2f, 0.7f, 0.95f, 0.7f); glEnd();

    glPopMatrix();

}

void treeS()
{
    //tree1

    glScalef(1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, -.1);
    glVertex2f(0.064f, -.1);
    glVertex2f(0.064f, 0.03);
    glVertex2f(0.048f, 0.03);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,-0.03);
    glVertex2f(0.081f,-0.03);
    glVertex2f(0.06f,0.18);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,-0.02);
    glVertex2f(0.082f,-0.02);
    glVertex2f(0.07f,0.14);
    glEnd();

    glLoadIdentity();


    //tree2

    glScalef(-1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, -.1);
    glVertex2f(0.064f, -.1);
    glVertex2f(0.064f, -0.03);
    glVertex2f(0.048f, -0.03);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,-0.03);
    glVertex2f(0.081f,-0.03);
    glVertex2f(0.06f,0.18);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,-0.02);
    glVertex2f(0.082f,-0.02);
    glVertex2f(0.07f,0.14);
    glEnd();

    glLoadIdentity();

//trunk
glBegin(GL_QUADS);
    glColor3f(0.3f, 0.2f, 0.0f);
    glVertex2f(0.59f,-0.15f);
    glVertex2f(0.633f,-0.15f);
    glVertex2f(0.623f,0.066f);
    glVertex2f(0.595f,0.066f);
    glEnd();
    //1left

    curvedBranch(
        0.63f, -0.17f,
        0.69f,  0.1f,
        0.59f,  0.0f,
        0.018f
    );
    //1right
    curvedBranch(
        0.596f, -0.17f,
        0.54f,  0.1f,
        0.62f,   0.0f,
        0.018f
    );
    //2right
    // Left curved branch
    curvedBranch(0.62f, 0.01f,
                 0.67f, 0.18f,
                 0.63f, 0.09f,
                 0.01f);

    //middle
    curvedBranch(
        0.62f, 0.01f,
        0.598f, 0.18f,
        0.61f, 0.09f,
        0.015f
    );

    //2nd left
    curvedBranch(
        0.595f, 0.016f,
        0.56f, 0.18f,
        0.595f, 0.09f,
        0.01f
    );


    circle(0.045f, 0.72f, 0.085f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.04f, 0.69f, 0.06f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.02f, 0.66f, 0.062f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.04f, 0.68f, 0.09f, 0.0f, 0.8f, 0.0f);
    glEnd();


    circle(0.03f, 0.51f, 0.07f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.045f, 0.5f, 0.088f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.02f, 0.55f, 0.04f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.05f, 0.545f, 0.085f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.02f, 0.55f, 0.12f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f, 0.6f, 0.13f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f, 0.58f, 0.12f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f, 0.63f, 0.12f, 0.0f, 0.4f, 0.0f);
    glEnd();


    circle(0.05f, 0.55f, 0.16f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.05f, 0.62f, 0.155f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.05f, 0.68f, 0.15f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.055f, 0.49f, 0.163f, 0.5f, 0.85f, 0.6f);
    glEnd();
    circle(0.055f, 0.65f, 0.18f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.72f, 0.163f, 0.5f, 0.85f, 0.6f);
    glEnd();

    circle(0.04f, 0.54f, 0.18f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.04f, 0.67f, 0.18f, 0.0f, 0.4f, 0.0f);
    glEnd();

    circle(0.055f, 0.5f, 0.20f, 0.5f, 0.85f, 0.6f);
    glEnd();
    circle(0.055f, 0.55f, 0.21f, 0.5f, 0.85f, 0.6f);
    glEnd();
    circle(0.055f, 0.62f, 0.21f, 0.5f, 0.85f, 0.6f);
    glEnd();
    circle(0.055f, 0.7f, 0.2f, 0.5f, 0.85f, 0.6f);
    glEnd();

    circle(0.055f, 0.49f, 0.24f, 0.5f, 0.85f, 0.6f);
    glEnd();
    circle(0.055f, 0.55f, 0.26f, 0.5f, 0.85f, 0.6f);
    glEnd();
    circle(0.055f, 0.62f, 0.26f, 0.5f, 0.85f, 0.6f);
    glEnd();
    circle(0.055f, 0.65f, 0.27f, 0.5f, 0.85f, 0.6f);
    glEnd();
    circle(0.055f, 0.72f, 0.22f, 0.5f, 0.85f, 0.6f);
    glEnd();

    circle(0.055f, 0.5f, 0.28f, 0.7f, 0.95f, 0.7f);
    glEnd();
    circle(0.055f, 0.55f, 0.3f, 0.7f, 0.95f, 0.7f);
    glEnd();
    circle(0.055f, 0.57f, 0.34f, 0.7f, 0.95f, 0.7f);
    glEnd();
    circle(0.055f, 0.58f, 0.28f, 0.7f, 0.95f, 0.7f);
    glEnd();
    circle(0.055f, 0.65f, 0.32f, 0.7f, 0.95f, 0.7f);
    glEnd();
    circle(0.055f, 0.7f, 0.28f, 0.7f, 0.95f, 0.7f);
    glEnd();


    glLoadIdentity();

}


void Display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    sky19();
    hills();
    river19();
    hill2();
    road();
    road_border();
    skatingroad();
    ships();
    Wire();
    tree1();
    drawcable();
    drawcable2();
    Cloud();
    drawHuman(1,0,1,man1Position,0);
    drawHuman(0.5,0.2,0.6,man4Position,0);
    drawHuman(0,1,1,man2Position,0);
    drawHuman(1,1,0,man3Position,0);
    snowman();
    trafficLight();
    Bigtree();
    car();
    suv();
    if(isSnow){
        snow_fall();
    }


    glFlush();
}

void DisplayS()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    sky19();
    hills();
    river19();
    hill2();
    road();
    road_border();
    skatingroad();
    ships();
    Wire();
    treeS();
    drawcable();
    drawcable2();
    Cloud();
    drawHuman(1,0,1,man1Position,0);
    drawHuman(0.5,0.2,0.6,man4Position,0);
    drawHuman(0,1,1,man2Position,0);
    drawHuman(1,1,0,man3Position,0);
    snowman();
    trafficLight();
    BigtreeS();
    car();
    suv();
    if(isSnow){
        snow_fall();
    }


    glFlush();
}

///----------------------------------------------------------snow city End---------------------------------------------------------------------///



GLfloat position22 = 0.0f;
GLfloat speed22 = 0.007f;
void birdd(int value) {
    if(position22 > 1.0)
        position22 =-1.0f;
    position22 += speed22;
	glutPostRedisplay();
	glutTimerFunc(100, birdd, 0);
}
GLfloat position4 = 0.0f;
GLfloat speed4 =-0.01f;
void sunn(int value)
{
   if(position4 > 1.0)
        position4 = 0.0f;

    position4 += speed4;

	glutPostRedisplay();



	glutTimerFunc(100, sunn, 0);
}
GLfloat position3 = 0.0f;
GLfloat speed3 =- 1.0f;
void rain(int value) {
    if(position3 <- 1.0)
        position3 = 1.0f;
    position3 += speed3;
	glutPostRedisplay();
	glutTimerFunc(100, rain, 0);
}
GLfloat position2 = 0.0f;
GLfloat speed2 = 0.004f;
void cloud(int value) {
    if(position2 > 1.0)
        position2 =-1.0f;
    position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(100, cloud, 0);
}
GLfloat position1 = 1.0f;
GLfloat speed1 =-0.005f;
void boat(int value)
{
   if(position1 <- 1.0)
        position1 = 1.0f;

    position1 += speed1;

	glutPostRedisplay();



	glutTimerFunc(100, boat, 0);
}
void cloud1()
{
    int i;

	GLfloat x=.5f; GLfloat y=.86f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=.55f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=.45f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=.52f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=.6f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}

void cloud2()
{
   // glLoadIdentity();
    int i;

	GLfloat x=-.5f; GLfloat y=.86f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=-.55f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.45f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.52f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.6f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void cloud3()
{
    // glLoadIdentity();
    int i;

	GLfloat x=0.0f; GLfloat y=.86f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=.05f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-0.05f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=.02f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=.1f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}
void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(51, 204, 255);
	glVertex2f(-1.0f, 0.45f);
	glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
    glEnd();
}
void sky2()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 51, 204);
	glVertex2f(-1.0f, 0.45f);
	glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
    glEnd();
}
void sky3()
{
    glBegin(GL_QUADS);
    glColor3ub(2,0,108);
	glVertex2f(-1.0f, 0.45f);
	glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
    glEnd();
}
void backgroundtree()


{

  	glBegin(GL_POLYGON);
	glColor3ub(0,90,0);
	glVertex2f(-1.0f,0.45f);
	glVertex2f(-0.98f, 0.5f);
    glVertex2f(-0.93f, 0.56);
    glVertex2f(-0.9f,0.6f);
    glVertex2f(-0.82f, 0.65);
    glVertex2f(-0.75f, 0.70);
    glVertex2f(-0.68f, 0.67);
     glVertex2f(-0.6f,0.6f);
     glVertex2f(-0.57f, 0.56);
     glVertex2f(-0.52f, 0.5f);
     glVertex2f(-0.5f,0.45f);
     glVertex2f(-1.0f,0.45f);
	glEnd();



glBegin(GL_POLYGON);
    glColor3ub(0, 110, 0);
    glVertex2f(-0.80f, 0.45f);
    glVertex2f(-0.78f, 0.485f);
    glVertex2f(-0.73f, 0.527f);
    glVertex2f(-0.70f, 0.555f);
    glVertex2f(-0.62f, 0.59f);
    glVertex2f(-0.55f, 0.625f);
    glVertex2f(-0.48f, 0.604f);
    glVertex2f(-0.40f, 0.555f);
    glVertex2f(-0.37f, 0.527f);
    glVertex2f(-0.32f, 0.485f);
    glVertex2f(-0.30f, 0.45f);
    glVertex2f(-0.80f, 0.45f);
    glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
	glVertex2f(1.0f,0.45f);
	glVertex2f(0.98f, 0.5f);
    glVertex2f(0.93f, 0.56);
    glVertex2f(0.9f,0.6f);
    glVertex2f(0.82f, 0.64);
    glVertex2f(0.75f, 0.66);///
    glVertex2f(0.68f, 0.64);
    glVertex2f(0.6f,0.6f);
    glVertex2f(0.57f, 0.56);
    glVertex2f(0.52f, 0.5f);
    glVertex2f(0.5f,0.45f);
    glVertex2f(1.0f,0.45f);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,109,0);  // Same dark green
    glVertex2f(-0.05f, 0.45f);   // -0.25 + 0.2
    glVertex2f(0.0f, 0.505f);    // -0.20 + 0.2
    glVertex2f(0.05f, 0.571f);   // -0.15 + 0.2
    glVertex2f(0.10f, 0.615f);   // -0.10 + 0.2
    glVertex2f(0.15f, 0.659f);   // -0.05 + 0.2
    glVertex2f(0.20f, 0.681f);   // 0.0 + 0.2 (peak)
    glVertex2f(0.25f, 0.659f);   // 0.05 + 0.2
    glVertex2f(0.30f, 0.615f);   // 0.10 + 0.2
    glVertex2f(0.35f, 0.571f);   // 0.15 + 0.2
    glVertex2f(0.40f, 0.505f);   // 0.20 + 0.2
    glVertex2f(0.45f, 0.45f);    // 0.25 + 0.2
    glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(0,90,0);  // Dark green
    glVertex2f(-0.45f, 0.55f);
    glVertex2f(-0.40f, 0.45f);
    glVertex2f(-0.45f, 0.35f);
    glVertex2f(-0.30f, 0.565f);
    glVertex2f(-0.25f, 0.609f);
    glVertex2f(-0.20f, 0.600f);  // peak
    glVertex2f(-0.15f, 0.609f);
    glVertex2f(-0.10f, 0.565f);
    glVertex2f(-0.05f, 0.45f);
    glVertex2f(0.1f, 0.45f);
    glVertex2f(0.05f, 0.25f);
glEnd();





	glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
	glVertex2f(-0.5f,0.45f);
	glVertex2f(-0.48f, 0.5f);
    glVertex2f(-0.45f, 0.56);
    glVertex2f(-0.42f,0.6f);
    glVertex2f(-0.37f, 0.68);///
    glVertex2f(-0.32f, 0.6);
    glVertex2f(-0.29f, 0.56f);
     glVertex2f(-0.27f, 0.5f);
    glVertex2f(-0.25f,0.45f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(0,109,0);
	glVertex2f(0.5f,0.45f);
	glVertex2f(0.48f, 0.5f);
    glVertex2f(0.45f, 0.56);
    glVertex2f(0.42f,0.6f);
    glVertex2f(0.37f, 0.65);///
    glVertex2f(0.32f, 0.6);
    glVertex2f(0.29f, 0.56f);
     glVertex2f(0.27f, 0.5f);
    glVertex2f(0.25f,0.45f);
    glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(34,139,34);
    glVertex2f(0.65f, 0.45f);  // 0.5 + 0.15
    glVertex2f(0.63f, 0.5f);   // 0.48 + 0.15
    glVertex2f(0.60f, 0.56f);  // 0.45 + 0.15
    glVertex2f(0.57f, 0.6f);   // 0.42 + 0.15
    glVertex2f(0.52f, 0.55f);  // 0.37 + 0.15  <- peak vertex
    glVertex2f(0.47f, 0.6f);   // 0.32 + 0.15
    glVertex2f(0.44f, 0.56f);  // 0.29 + 0.15
    glVertex2f(0.42f, 0.5f);   // 0.27 + 0.15
    glVertex2f(0.40f, 0.45f);  // 0.25 + 0.15
glEnd();




    glBegin(GL_POLYGON);
	glColor3ub(34,139,44);
	glVertex2f(-.25f,0.45f);
	glVertex2f(-0.23f, 0.5f);
    glVertex2f(-0.18f, 0.56);
    glVertex2f(-0.15f,0.6f);
    glVertex2f(-0.07f, 0.64);
    glVertex2f(-0.00f, 0.70);///
    glVertex2f(0.07f, 0.64);
    glVertex2f(0.15f,0.6f);
    glVertex2f(0.18f, 0.56);
    glVertex2f(0.23f, 0.5f);
    glVertex2f(.25f,0.45f);
	glEnd();

}
void backgroundTreeReflection()
{
    glPushMatrix();

    // Move the origin to water surface and simulate rotation
    glTranslatef(0.0f, -0.45f, 0.0f);  // move reflection below water
    glRotatef(110.0f, 0.0f, 1.0f, 0.0f); // rotate 110 degrees along Y-axis
    glScalef(1.0f, -1.0f, 1.0f);       // flip vertically for reflection

    // Layer 1
    glBegin(GL_POLYGON);
    glColor3ub(0,60,0);  // darker green for reflection
    glVertex2f(-1.0f,0.45f);
    glVertex2f(-0.98f, 0.5f);
    glVertex2f(-0.93f, 0.56f);
    glVertex2f(-0.9f,0.6f);
    glVertex2f(-0.82f, 0.65f);
    glVertex2f(-0.75f, 0.70f);
    glVertex2f(-0.68f, 0.67f);
    glVertex2f(-0.6f,0.6f);
    glVertex2f(-0.57f, 0.56f);
    glVertex2f(-0.52f, 0.5f);
    glVertex2f(-0.5f,0.45f);
    glVertex2f(-1.0f,0.45f);
    glEnd();

    // Layer 2
    glBegin(GL_POLYGON);
    glColor3ub(0,80,0);
    glVertex2f(-0.80f, 0.45f);
    glVertex2f(-0.78f, 0.485f);
    glVertex2f(-0.73f, 0.527f);
    glVertex2f(-0.70f, 0.555f);
    glVertex2f(-0.62f, 0.59f);
    glVertex2f(-0.55f, 0.625f);
    glVertex2f(-0.48f, 0.604f);
    glVertex2f(-0.40f, 0.555f);
    glVertex2f(-0.37f, 0.527f);
    glVertex2f(-0.32f, 0.485f);
    glVertex2f(-0.30f, 0.45f);
    glVertex2f(-0.80f, 0.45f);
    glEnd();

    // Layer 3 (right side)
    glBegin(GL_POLYGON);
    glColor3ub(24,100,24);
    glVertex2f(1.0f,0.45f);
    glVertex2f(0.98f, 0.5f);
    glVertex2f(0.93f, 0.56f);
    glVertex2f(0.9f,0.6f);
    glVertex2f(0.82f, 0.64f);
    glVertex2f(0.75f, 0.66f);
    glVertex2f(0.68f, 0.64f);
    glVertex2f(0.6f,0.6f);
    glVertex2f(0.57f, 0.56f);
    glVertex2f(0.52f, 0.5f);
    glVertex2f(0.5f,0.45f);
    glVertex2f(1.0f,0.45f);
    glEnd();

    // Layer 4 (middle)
    glBegin(GL_POLYGON);
    glColor3ub(0,80,0);
    glVertex2f(-0.05f, 0.45f);
    glVertex2f(0.0f, 0.505f);
    glVertex2f(0.05f, 0.571f);
    glVertex2f(0.10f, 0.615f);
    glVertex2f(0.15f, 0.659f);
    glVertex2f(0.20f, 0.681f);
    glVertex2f(0.25f, 0.659f);
    glVertex2f(0.30f, 0.615f);
    glVertex2f(0.35f, 0.571f);
    glVertex2f(0.40f, 0.505f);
    glVertex2f(0.45f, 0.45f);
    glEnd();

    // Layer 5 (front small trees)
    glBegin(GL_POLYGON);
    glColor3ub(0,60,0);
    glVertex2f(-0.45f, 0.55f);
    glVertex2f(-0.40f, 0.45f);
    glVertex2f(-0.45f, 0.35f);
    glVertex2f(-0.30f, 0.565f);
    glVertex2f(-0.25f, 0.609f);
    glVertex2f(-0.20f, 0.600f);
    glVertex2f(-0.15f, 0.609f);
    glVertex2f(-0.10f, 0.565f);
    glVertex2f(-0.05f, 0.45f);
    glVertex2f(0.1f, 0.45f);
    glVertex2f(0.05f, 0.25f);
    glEnd();



    glPopMatrix();
}


void bird()
{
       int i;

	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
	/////2nd bird////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	/////3rd bird/////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	////4th bird////
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();


}
    void stars()
{
    glPointSize( 2.5 );
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.8f,0.95f);
    glVertex2f(0.9f,0.9f);
    glVertex2f(0.95f,0.7f);
    glVertex2f(0.8f,0.8f);
    glVertex2f(0.7f,0.9f);
    glVertex2f(0.6f,0.8f);
    glVertex2f(0.5f,0.75f);
    glVertex2f(0.4f,0.9f);
    glVertex2f(0.3f,0.7f);
    glVertex2f(0.25f,0.9f);
    glVertex2f(0.25f,0.7f);
    glVertex2f(0.1f,0.9f);
    glVertex2f(0.15f,0.75f);
    glVertex2f(0.0f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.4f,0.8f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.9f,0.9f);
    glVertex2f(-0.95f,0.7f);
    glVertex2f(-0.8f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.5f,0.75f);
    glVertex2f(-0.4f,0.9f);
    glVertex2f(-0.3f,0.7f);
    glVertex2f(-0.25f,0.9f);
    glVertex2f(-0.25f,0.7f);
    glVertex2f(-0.15f,0.75f);
    glVertex2f(-0.1f,0.9f);
    glEnd();

}
void sun()
{
    int i;

	GLfloat x=.0f; GLfloat y=.9f; GLfloat radius =.06f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void moon()
{
    int i;

    GLfloat xx=-.5f; GLfloat yx=.93f; GLfloat radiusx =.06f;
    int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0, 51, 204);
		glVertex2f(xx, yx); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            xx + (radiusx * cos(i *  twicePi / triangleAmount)),
			    yx + (radiusx * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x=-.5f; GLfloat y=.9f; GLfloat radius =.06f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(242, 242, 242);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

}

void ground()
{
    glBegin(GL_POLYGON);
	glColor3ub(34, 200, 34);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(-1.0f,0.0f);
	glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, -0.03);
    glVertex2f(1.0f, -0.07);
    glVertex2f(1.0f, -0.1);//6
    glVertex2f(1.0f, -0.13);
    glVertex2f(1.0f, -0.17);
    glVertex2f(1.0f, -0.2);
    glVertex2f(1.0f, -0.23);
    glVertex2f(1.0f, -0.25);
    glVertex2f(1.0f, -0.28);//12
    glVertex2f(1.0f, -0.32);
    glVertex2f(1.0f, -0.35);
    glVertex2f(1.0f, -0.4);
    glVertex2f(1.0f, -0.6);
    glVertex2f(1.0f, -0.65);
    glVertex2f(1.0f, -0.7);
    glVertex2f(1.0f, -0.75);
    glVertex2f(1.0f, -0.8);
    glVertex2f(1.0f, -0.85);
    glVertex2f(1.05f, -0.9);
    glVertex2f(1.0f, -0.95);
    glVertex2f(1.0f, -1.0);
    glEnd();




}
     void ground1()
{
    glBegin(GL_POLYGON);
	glColor3ub(34, 139, 34);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(-1.0f,0.0f);
	glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, -0.03);
    glVertex2f(1.0f, -0.07);
    glVertex2f(1.0f, -0.1);//6
    glVertex2f(1.0f, -0.13);
    glVertex2f(1.0f, -0.17);
    glVertex2f(1.0f, -0.2);
    glVertex2f(1.0f, -0.23);
    glVertex2f(1.0f, -0.25);
    glVertex2f(1.0f, -0.28);//12
    glVertex2f(1.0f, -0.32);
    glVertex2f(1.0f, -0.35);
    glVertex2f(1.0f, -0.4);
    glVertex2f(1.0f, -0.6);
    glVertex2f(1.0f, -0.65);
    glVertex2f(1.0f, -0.7);
    glVertex2f(1.0f, -0.75);
    glVertex2f(1.0f, -0.8);
    glVertex2f(1.0f, -0.85);
    glVertex2f(1.05f, -0.9);
    glVertex2f(1.0f, -0.95);
    glVertex2f(1.0f, -1.0);
    glEnd();




}
void river()
{
   glBegin(GL_QUADS);
   glColor3ub(38, 154, 214);
	//glColor3ub(0,122,204);
	glVertex2f(-1.0f,0.45f);
	glVertex2f(1.0f,0.45f);
	glVertex2f(1.0f,-1.0f);
    glVertex2f(-1.0f,-1.0f);
    glEnd();
}
void riverN()
{
   glBegin(GL_QUADS);
   glColor3ub(0, 0, 51);
	//glColor3ub(0,122,204);
	glVertex2f(-1.0f,0.45f);
	glVertex2f(1.0f,0.45f);
	glVertex2f(1.0f,-1.0f);
    glVertex2f(-1.0f,-1.0f);
    glEnd();
}
void hut()
{

    glBegin(GL_POLYGON);
    glColor3ub(70, 35, 10);
    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.1f,0.0f);
    glVertex2f(-0.18f,0.3f);
    glVertex2f(-0.58f,0.3f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(70, 35, 10);
    glVertex2f(-0.49f,0.0f);
    glVertex2f(-0.13f,0.0f);
    glVertex2f(-0.13f,-0.4f);
    glVertex2f(-0.49f,-0.4f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(70, 35, 10);
    glVertex2f(-0.58f,0.3f);
    glVertex2f(-0.63f,0.0f);
    glVertex2f(-0.61f,0.0f);
    glVertex2f(-0.61f,-0.35f);
    glVertex2f(-0.49f,-0.4f);
    glVertex2f(-0.17f,-0.4f);

    glEnd();
    glLineWidth(2);
     glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.1f,0.0f);

    glColor3ub(0,0,0);
    glVertex2f(-0.49f,0.0f);
    glVertex2f(-0.49f,-0.4f);

    glColor3ub(0,0,0);
     glVertex2f(-0.13f,-0.4f);
    glVertex2f(-0.49f,-0.4f);

     glColor3ub(0,0,0);
     glVertex2f(-0.13f,-0.4f);
    glVertex2f(-0.13f,0.0f);

    glColor3ub(0,0,0);
    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.58f,0.3f);

    glColor3ub(0,0,0);
    glVertex2f(-0.58f,0.3f);
    glVertex2f(-0.63f,0.0f);

    glColor3ub(0,0,0);
    glVertex2f(-0.57f,0.245f);
    glVertex2f(-0.61f,0.0f);

    glColor3ub(0,0,0);
    glVertex2f(-0.61f,0.0f);
    glVertex2f(-0.61f,-0.35f);

    glColor3ub(0,0,0);
    glVertex2f(-0.61f,-0.35f);
    glVertex2f(-0.49f,-0.4f);

    glColor3ub(0,0,0);
    glVertex2f(-0.1f,0.0f);
    glVertex2f(-0.18f,0.3f);

    glColor3ub(0,0,0);
    glVertex2f(-0.18f,0.3f);
    glVertex2f(-0.58f,0.3f);

    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.35f,-0.1f);
    glVertex2f(-0.22f,-0.1f);    //main door
    glVertex2f(-0.22f,-0.4f);
    glVertex2f(-0.35f,-0.4f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35f,-0.1f);
    glVertex2f(-0.22f,-0.1f);
    glVertex2f(-0.22f,-0.1f);
    glVertex2f(-0.22f,-0.4f);
    glVertex2f(-0.35f,-0.1f);
    glVertex2f(-0.35f,-0.4f);
    glVertex2f(-0.285f,-0.1f);
    glVertex2f(-0.285f,-0.4f);
    glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.44f,-0.15f);
    glVertex2f(-0.38f,-0.15f); //left window
    glVertex2f(-0.38f,-0.25f);
    glVertex2f(-0.44f,-0.25f);
    glEnd();
     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.44f,-0.15f);
    glVertex2f(-0.44f,-0.25f);
    glVertex2f(-0.38f,-0.15f);
    glVertex2f(-0.38f,-0.25f);
    glVertex2f(-0.44f,-0.15f);
    glVertex2f(-0.38f,-0.15f);
    glVertex2f(-0.44f,-0.25f);
    glVertex2f(-0.38f,-0.25f);
    glVertex2f(-0.41f,-0.15f);
    glVertex2f(-0.41f,-0.25f);
    glEnd();

glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
     glVertex2f(-0.51f,-0.08f); //2nd door
    glVertex2f(-0.58f,-0.06f);
    glVertex2f(-0.58f,-0.37f);
    glVertex2f(-0.51f,-0.4f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.58f,-0.06f);
    glVertex2f(-0.58f,-0.37f);
    glVertex2f(-0.51f,-0.08f);
    glVertex2f(-0.51f,-0.4f);
    glVertex2f(-0.58f,-0.06f);
    glVertex2f(-0.51f,-0.08f);
    glVertex2f(-0.545f,-0.07f);
    glVertex2f(-0.545f,-0.385f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.14f,-0.15f);
    glVertex2f(-0.2f,-0.15f);   //rightwindow
    glVertex2f(-0.2f,-0.25f);
    glVertex2f(-0.14f,-0.25f);
    glEnd();
     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.14f,-0.15f);
    glVertex2f(-0.14f,-0.25f);
    glVertex2f(-0.2f,-0.15f);
    glVertex2f(-0.2f,-0.25f);
    glVertex2f(-0.14f,-0.15f);
    glVertex2f(-0.2f,-0.15f);
    glVertex2f(-0.14f,-0.25f);
    glVertex2f(-0.2f,-0.25f);
    glVertex2f(-0.17f,-0.15f);
    glVertex2f(-0.17f,-0.25f);
    glEnd();
}
void hut1()
{
  glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,-0.2f);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.35f,-0.2f);
    glVertex2f(-0.285f,0.1f);
    glVertex2f(-0.285f,-0.2f);
    glEnd();


     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,-0.2f);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.35f,-0.2f);
    glVertex2f(-0.285f,0.1f);
    glVertex2f(-0.285f,-0.2f);
    glEnd();



    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.38f,0.05f);
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.38f,0.05f);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.41f,0.05f);
    glVertex2f(-0.41f,-0.05f);
    glEnd();


     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.58f,-0.17f);
    glVertex2f(-0.51f,0.12f);
    glVertex2f(-0.51f,-0.2f);
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.51f,0.12f);
    glVertex2f(-0.545f,0.13f);
    glVertex2f(-0.545f,-0.185f);
    glEnd();

     /*glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.14f,0.05f); ///right window
    glVertex2f(-0.2f,0.05f);
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.14f,-0.05f);
    glEnd();*/


     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.14f,-0.05f);
    glVertex2f(-0.2f,0.05f);
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.2f,0.05f);
    glVertex2f(-0.14f,-0.05f);
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.17f,0.05f);
    glVertex2f(-0.17f,-0.05f);
    glEnd();

    glLineWidth(2);
     glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.49f,0.2f);
    glVertex2f(-0.49f,-0.2f);
     glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.49f,-0.2f);
     glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.13f,0.2f);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.63f,0.2f);
    glVertex2f(-0.57f,0.445f);
    glVertex2f(-0.61f,0.2f);
    glVertex2f(-0.61f,0.2f);
    glVertex2f(-0.61f,-0.15f);
    glVertex2f(-0.61f,-0.15f);
    glVertex2f(-0.49f,-0.2f);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.58f,0.5f);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.58f,0.5f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-0.49f,0.2f);
    glVertex2f(-0.13f,0.2f);
    glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.49f,-0.2f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.63f,0.2f);
    glVertex2f(-0.61f,0.2f);
    glVertex2f(-0.61f,-0.15f);
    glVertex2f(-0.49f,-0.2f);
    glVertex2f(-0.17f,-0.2f);
    glEnd();


}
void hut2()
{

     glBegin(GL_POLYGON);
    glColor3ub(178, 34, 34);
    glVertex2f(0.03f,-0.2f);
    glVertex2f(0.39f,-0.2f);
    glVertex2f(0.39f,0.25f);
    glVertex2f(0.03f,0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(165, 30, 30);
    glVertex2f(0.06f,0.25f);
    glVertex2f(0.36f,0.25f);
    glVertex2f(0.36f,0.50f);
    glVertex2f(0.06f,0.50f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(90, 45, 20);
    glVertex2f(0.0f,0.50f);
    glVertex2f(0.43f,0.50f);
    glVertex2f(0.215f,0.80f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(120, 30, 30);
    glVertex2f(0.30f,0.55f);
    glVertex2f(0.34f,0.55f);
    glVertex2f(0.34f,0.70f);
    glVertex2f(0.30f,0.70f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(0.18f,-0.2f);
    glVertex2f(0.24f,-0.2f);
    glVertex2f(0.24f,0.05f);
    glVertex2f(0.18f,0.05f);
    glEnd();

    // Door frame
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3ub(220, 200, 180);
    glVertex2f(0.18f,-0.2f);
    glVertex2f(0.24f,-0.2f);
    glVertex2f(0.24f,0.05f);
    glVertex2f(0.18f,0.05f);
    glEnd();

    // ===================== WINDOWS =====================
    glLineWidth(2);

    // --- Ground left window ---
    glBegin(GL_POLYGON);
    glColor3ub(100, 120, 140); // darker window
    glVertex2f(0.06f,-0.05f);
    glVertex2f(0.12f,-0.05f);
    glVertex2f(0.12f,0.10f);
    glVertex2f(0.06f,0.10f);
    glEnd();

    // window panes (2 vertical + 2 horizontal)
    glColor3ub(50,50,60);
    glBegin(GL_LINES);
        // vertical
        glVertex2f(0.09f,-0.05f); glVertex2f(0.09f,0.10f);
        // horizontal
        glVertex2f(0.06f,0.025f); glVertex2f(0.12f,0.025f);
    glEnd();

    // --- Ground right window ---
    glBegin(GL_POLYGON);
    glColor3ub(100, 120, 140);
    glVertex2f(0.30f,-0.05f);
    glVertex2f(0.36f,-0.05f);
    glVertex2f(0.36f,0.10f);
    glVertex2f(0.30f,0.10f);
    glEnd();

    glColor3ub(50,50,60);
    glBegin(GL_LINES);
        glVertex2f(0.33f,-0.05f); glVertex2f(0.33f,0.10f); // vertical
        glVertex2f(0.30f,0.025f); glVertex2f(0.36f,0.025f); // horizontal
    glEnd();

    // --- Second floor left window ---
    glBegin(GL_POLYGON);
    glColor3ub(100, 120, 140);
    glVertex2f(0.10f,0.32f);
    glVertex2f(0.15f,0.32f);
    glVertex2f(0.15f,0.45f);
    glVertex2f(0.10f,0.45f);
    glEnd();

    glColor3ub(50,50,60);
    glBegin(GL_LINES);
        glVertex2f(0.125f,0.32f); glVertex2f(0.125f,0.45f); // vertical
        glVertex2f(0.10f,0.385f); glVertex2f(0.15f,0.385f); // horizontal
    glEnd();

    // --- Second floor right window ---
    glBegin(GL_POLYGON);
    glColor3ub(100, 120, 140);
    glVertex2f(0.27f,0.32f);
    glVertex2f(0.32f,0.32f);
    glVertex2f(0.32f,0.45f);
    glVertex2f(0.27f,0.45f);
    glEnd();

    glColor3ub(50,50,60);
    glBegin(GL_LINES);
        glVertex2f(0.295f,0.32f); glVertex2f(0.295f,0.45f); // vertical
        glVertex2f(0.27f,0.385f); glVertex2f(0.32f,0.385f); // horizontal
    glEnd();

    // ===================== PORCH =====================
    glBegin(GL_POLYGON);
    glColor3ub(100, 100, 120); // dark grey porch floor
    glVertex2f(0.10f,-0.2f);
    glVertex2f(0.32f,-0.2f);
    glVertex2f(0.32f,-0.12f);
    glVertex2f(0.10f,-0.12f);
    glEnd();

    // Porch pillars
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(220, 220, 220);
    glVertex2f(0.13f,-0.2f); glVertex2f(0.13f,-0.05f);
    glVertex2f(0.29f,-0.2f); glVertex2f(0.29f,-0.05f);
    glEnd();

    // ===================== FLOOR SEPARATOR =====================
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 180, 180);
    glVertex2f(0.03f,0.25f);
    glVertex2f(0.39f,0.25f);
    glEnd();

    // ===================== BRICKS =====================
    glLineWidth(1);
    glColor3ub(90,20,20);

    // Ground floor bricks
    for(float y=-0.2f; y<=0.25f; y+=0.03f) {
        if(y < -0.05f || y > 0.10f) {
            glBegin(GL_LINES);
            glVertex2f(0.03f, y); glVertex2f(0.18f, y);
            glVertex2f(0.24f, y); glVertex2f(0.39f, y);
            glEnd();
        }
        bool shift = ((int)((y+0.2f)/0.03f) %2 ==0);
        float start = shift?0.04f:0.03f;
        for(float x=start;x<=0.39f;x+=0.04f) {
            if((x>0.03f && x<0.18f)||(x>0.24f && x<0.39f)) {
                if(!((x>0.06f && x<0.12f)&&(y>-0.05f&&y<0.10f)) &&
                   !((x>0.30f && x<0.36f)&&(y>-0.05f&&y<0.10f))) {
                    glBegin(GL_LINES);
                    glVertex2f(x,y); glVertex2f(x,y+0.03f);
                    glEnd();
                }
            }
        }
    }

    // Second floor bricks
    for(float y=0.25f; y<=0.50f; y+=0.03f) {
        if(y<0.32f || y>0.45f) {
            glBegin(GL_LINES);
            glVertex2f(0.06f, y); glVertex2f(0.36f, y);
            glEnd();
        }
        bool shift = ((int)((y-0.25f)/0.03f)%2==0);
        float start = shift?0.07f:0.06f;
        for(float x=start;x<=0.36f;x+=0.04f) {
            if(!((x>0.10f && x<0.15f)&&(y>0.32f&&y<0.45f)) &&
               !((x>0.27f && x<0.32f)&&(y>0.32f&&y<0.45f))) {
                glBegin(GL_LINES);
                glVertex2f(x,y); glVertex2f(x,y+0.03f);
                glEnd();
            }
        }
    }

}

void tree()
{
   glBegin(GL_QUADS);
    glColor3f(0.3f, 0.2f, 0.0f);
    glVertex2f(0.59f,-0.15f);
    glVertex2f(0.633f,-0.15f);
    glVertex2f(0.623f,0.066f);
    glVertex2f(0.595f,0.066f);
    glEnd();
    //1left

    curvedBranch(
        0.63f, -0.17f,
        0.69f,  0.1f,
        0.59f,  0.0f,
        0.018f
    );
    //1right
    curvedBranch(
        0.596f, -0.17f,
        0.54f,  0.1f,
        0.62f,   0.0f,
        0.018f
    );
    //2right
    // Left curved branch
    curvedBranch(0.62f, 0.01f,
                 0.67f, 0.18f,
                 0.63f, 0.09f,
                 0.01f);

    //middle
    curvedBranch(
        0.62f, 0.01f,
        0.598f, 0.18f,
        0.61f, 0.09f,
        0.015f
    );

    //2nd left
    curvedBranch(
        0.595f, 0.016f,
        0.56f, 0.18f,
        0.595f, 0.09f,
        0.01f
    );


    circle(0.045f, 0.72f, 0.085f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.04f, 0.69f, 0.06f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.02f, 0.66f, 0.062f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.04f, 0.68f, 0.09f, 0.0f, 0.8f, 0.0f);
    glEnd();


    circle(0.03f, 0.51f, 0.07f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.045f, 0.5f, 0.088f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.02f, 0.55f, 0.04f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.05f, 0.545f, 0.085f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.02f, 0.55f, 0.12f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f, 0.6f, 0.13f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f, 0.58f, 0.12f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f, 0.63f, 0.12f, 0.0f, 0.4f, 0.0f);
    glEnd();


    circle(0.05f, 0.55f, 0.16f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.05f, 0.62f, 0.155f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.05f, 0.68f, 0.15f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.055f, 0.49f, 0.163f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.65f, 0.18f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.72f, 0.163f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.04f, 0.54f, 0.18f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.04f, 0.67f, 0.18f, 0.0f, 0.4f, 0.0f);
    glEnd();

    circle(0.055f, 0.5f, 0.20f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.55f, 0.21f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.62f, 0.21f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.7f, 0.2f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.055f, 0.49f, 0.24f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.55f, 0.26f, 0.0f, 0.77f, 0.0f);
    glEnd();
    circle(0.055f, 0.62f, 0.26f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f, 0.65f, 0.27f, 0.0f, 0.77f, 0.0f);
    glEnd();
    circle(0.055f, 0.72f, 0.22f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.055f, 0.5f, 0.28f, 0.0f, 0.85f, 0.0f);
    glEnd();
    circle(0.055f, 0.55f, 0.3f, 0.0f, 0.85f, 0.0f);
    glEnd();
    circle(0.055f, 0.57f, 0.34f, 0.0f, 0.85f, 0.0f);
    glEnd();
    circle(0.055f, 0.58f, 0.28f, 0.0f, 0.85f, 0.0f);
    glEnd();
    circle(0.055f, 0.65f, 0.32f, 0.0f, 0.85f, 0.0f);
    glEnd();
    circle(0.055f, 0.7f, 0.28f, 0.0f, 0.85f, 0.0f);
    glEnd();


    glLoadIdentity();

}
void tree2() {
    // Tree trunk (scaled and shifted left)
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.2f, 0.0f);
    glVertex2f((0.59f * 1.5f) - 0.1f, -0.15f * 1.5f);
    glVertex2f((0.633f * 1.5f) - 0.1f, -0.15f * 1.5f);
    glVertex2f((0.623f * 1.5f) - 0.1f, 0.066f * 1.5f);
    glVertex2f((0.595f * 1.5f) - 0.1f, 0.066f * 1.5f);
    glEnd();

    // Branches (scaled + shifted)
    curvedBranch(
        (0.63f * 1.5f) - 0.1f, -0.17f * 1.5f,
        (0.69f * 1.5f) - 0.1f, 0.1f * 1.5f,
        (0.59f * 1.5f) - 0.1f, 0.0f * 1.5f,
        0.018f * 1.5f
    );

    curvedBranch(
        (0.596f * 1.5f) - 0.1f, -0.17f * 1.5f,
        (0.54f * 1.5f) - 0.1f, 0.1f * 1.5f,
        (0.62f * 1.5f) - 0.1f, 0.0f * 1.5f,
        0.018f * 1.5f
    );

    curvedBranch(
        (0.62f * 1.5f) - 0.1f, 0.01f * 1.5f,
        (0.67f * 1.5f) - 0.1f, 0.18f * 1.5f,
        (0.63f * 1.5f) - 0.1f, 0.09f * 1.5f,
        0.01f * 1.5f
    );

    curvedBranch(
        (0.62f * 1.5f) - 0.1f, 0.01f * 1.5f,
        (0.598f * 1.5f) - 0.1f, 0.18f * 1.5f,
        (0.61f * 1.5f) - 0.1f, 0.09f * 1.5f,
        0.015f * 1.5f
    );

    curvedBranch(
        (0.595f * 1.5f) - 0.1f, 0.016f * 1.5f,
        (0.56f * 1.5f) - 0.1f, 0.18f * 1.5f,
        (0.595f * 1.5f) - 0.1f, 0.09f * 1.5f,
        0.01f * 1.5f
    );

    // Leaves (scaled + shifted)
    circle(0.045f * 1.5f, (0.72f * 1.5f) - 0.1f, 0.085f * 1.5f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.04f * 1.5f, (0.69f * 1.5f) - 0.1f, 0.06f * 1.5f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.02f * 1.5f, (0.66f * 1.5f) - 0.1f, 0.062f * 1.5f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.04f * 1.5f, (0.68f * 1.5f) - 0.1f, 0.09f * 1.5f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.03f * 1.5f, (0.51f * 1.5f) - 0.1f, 0.07f * 1.5f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.045f * 1.5f, (0.5f * 1.5f) - 0.1f, 0.088f * 1.5f, 0.0f, 0.75f, 0.0f);
    glEnd();
    circle(0.02f * 1.5f, (0.55f * 1.5f) - 0.1f, 0.04f * 1.5f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.05f * 1.5f, (0.545f * 1.5f) - 0.1f, 0.085f * 1.5f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.02f * 1.5f, (0.55f * 1.5f) - 0.1f, 0.12f * 1.5f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f * 1.5f, (0.6f * 1.5f) - 0.1f, 0.13f * 1.5f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f * 1.5f, (0.58f * 1.5f) - 0.1f, 0.12f * 1.5f, 0.0f, 0.4f, 0.0f);
    glEnd();
    circle(0.03f * 1.5f, (0.63f * 1.5f) - 0.1f, 0.12f * 1.5f, 0.0f, 0.4f, 0.0f);
    glEnd();

    circle(0.05f * 1.5f, (0.55f * 1.5f) - 0.1f, 0.16f * 1.5f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.05f * 1.5f, (0.62f * 1.5f) - 0.1f, 0.155f * 1.5f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.05f * 1.5f, (0.68f * 1.5f) - 0.1f, 0.15f * 1.5f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.055f * 1.5f, (0.49f * 1.5f) - 0.1f, 0.163f * 1.5f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f * 1.5f, (0.65f * 1.5f) - 0.1f, 0.18f * 1.5f, 0.0f, 0.8f, 0.0f);
    glEnd();
    circle(0.055f * 1.5f, (0.72f * 1.5f) - 0.1f, 0.163f * 1.5f, 0.0f, 0.8f, 0.0f);
    glEnd();

    circle(0.04f * 1.5f, (0.54f * 1.5f) - 0.1f, 0.18f * 1.5f, 0.0f, 0.4f, 0.0f);glEnd();
    circle(0.04f * 1.5f, (0.67f * 1.5f) - 0.1f, 0.18f * 1.5f, 0.0f, 0.4f, 0.0f);glEnd();

    circle(0.055f * 1.5f, (0.5f * 1.5f) - 0.1f, 0.20f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.55f * 1.5f) - 0.1f, 0.21f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.62f * 1.5f) - 0.1f, 0.21f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.7f * 1.5f) - 0.1f, 0.2f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();

    circle(0.055f * 1.5f, (0.49f * 1.5f) - 0.1f, 0.24f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.55f * 1.5f) - 0.1f, 0.26f * 1.5f, 0.0f, 0.77f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.62f * 1.5f) - 0.1f, 0.26f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.65f * 1.5f) - 0.1f, 0.27f * 1.5f, 0.0f, 0.77f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.72f * 1.5f) - 0.1f, 0.22f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();

    circle(0.055f * 1.5f, (0.5f * 1.5f) - 0.1f, 0.28f * 1.5f, 0.0f, 0.85f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.55f * 1.5f) - 0.1f, 0.3f * 1.5f, 0.0f, 0.85f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.57f * 1.5f) - 0.1f, 0.34f * 1.5f, 0.0f, 0.85f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.58f * 1.5f) - 0.1f, 0.28f * 1.5f, 0.0f, 0.85f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.65f * 1.5f) - 0.1f, 0.32f * 1.5f, 0.0f, 0.85f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.7f * 1.5f) - 0.1f, 0.28f * 1.5f, 0.0f, 0.85f, 0.0f);glEnd();

    glLoadIdentity();
}




void tree3() {
    // Tree trunk (keep current position)
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.2f, 0.0f);
    glVertex2f((0.59f * 1.5f) - 1.65f, -0.15f * 1.5f);
    glVertex2f((0.633f * 1.5f) - 1.65f, -0.15f * 1.5f);
    glVertex2f((0.623f * 1.5f) - 1.65f, 0.066f * 1.5f);
    glVertex2f((0.595f * 1.5f) - 1.65f, 0.066f * 1.5f);
    glEnd();

    // Branches (aligned with trunk)
    curvedBranch(
        (0.63f * 1.5f) - 1.65f, -0.17f * 1.5f,
        (0.69f * 1.5f) - 1.65f, 0.1f * 1.5f,
        (0.59f * 1.5f) - 1.65f, 0.0f * 1.5f,
        0.018f * 1.5f
    );

    curvedBranch(
        (0.596f * 1.5f) - 1.65f, -0.17f * 1.5f,
        (0.54f * 1.5f) - 1.65f, 0.1f * 1.5f,
        (0.62f * 1.5f) - 1.65f, 0.0f * 1.5f,
        0.018f * 1.5f
    );

    curvedBranch(
        (0.62f * 1.5f) - 1.65f, 0.01f * 1.5f,
        (0.67f * 1.5f) - 1.65f, 0.18f * 1.5f,
        (0.63f * 1.5f) - 1.65f, 0.09f * 1.5f,
        0.01f * 1.5f
    );

    curvedBranch(
        (0.62f * 1.5f) - 1.65f, 0.01f * 1.5f,
        (0.598f * 1.5f) - 1.65f, 0.18f * 1.5f,
        (0.61f * 1.5f) - 1.65f, 0.09f * 1.5f,
        0.015f * 1.5f
    );

    curvedBranch(
        (0.595f * 1.5f) - 1.65f, 0.016f * 1.5f,
        (0.56f * 1.5f) - 1.65f, 0.18f * 1.5f,
        (0.595f * 1.5f) - 1.65f, 0.09f * 1.5f,
        0.01f * 1.5f
    );

    // Leaves (all shifted to align with trunk)
    circle(0.045f * 1.5f, (0.72f * 1.5f) - 1.65f, 0.085f * 1.5f, 0.0f, 0.75f, 0.0f);glEnd();
    circle(0.04f * 1.5f, (0.69f * 1.5f) - 1.65f, 0.06f * 1.5f, 0.0f, 0.75f, 0.0f);glEnd();
    circle(0.02f * 1.5f, (0.66f * 1.5f) - 1.65f, 0.062f * 1.5f, 0.0f, 0.4f, 0.0f);glEnd();
    circle(0.04f * 1.5f, (0.68f * 1.5f) - 1.65f, 0.09f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();

    circle(0.03f * 1.5f, (0.51f * 1.5f) - 1.65f, 0.07f * 1.5f, 0.0f, 0.75f, 0.0f);glEnd();
    circle(0.045f * 1.5f, (0.5f * 1.5f) - 1.65f, 0.088f * 1.5f, 0.0f, 0.75f, 0.0f);glEnd();
    circle(0.02f * 1.5f, (0.55f * 1.5f) - 1.65f, 0.04f * 1.5f, 0.0f, 0.4f, 0.0f);
    circle(0.05f * 1.5f, (0.545f * 1.5f) - 1.65f, 0.085f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();

    circle(0.02f * 1.5f, (0.55f * 1.5f) - 1.65f, 0.12f * 1.5f, 0.0f, 0.4f, 0.0f);glEnd();
    circle(0.03f * 1.5f, (0.6f * 1.5f) - 1.65f, 0.13f * 1.5f, 0.0f, 0.4f, 0.0f);glEnd();
    circle(0.03f * 1.5f, (0.58f * 1.5f) - 1.65f, 0.12f * 1.5f, 0.0f, 0.4f, 0.0f);glEnd();
    circle(0.03f * 1.5f, (0.63f * 1.5f) - 1.65f, 0.12f * 1.5f, 0.0f, 0.4f, 0.0f);glEnd();

    circle(0.05f * 1.5f, (0.55f * 1.5f) - 1.65f, 0.16f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();
    circle(0.05f * 1.5f, (0.62f * 1.5f) - 1.65f, 0.155f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();
    circle(0.05f * 1.5f, (0.68f * 1.5f) - 1.65f, 0.15f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();

    circle(0.055f * 1.5f, (0.49f * 1.5f) - 1.65f, 0.163f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.65f * 1.5f) - 1.65f, 0.18f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();
    circle(0.055f * 1.5f, (0.72f * 1.5f) - 1.65f, 0.163f * 1.5f, 0.0f, 0.8f, 0.0f);glEnd();

    // Continue for all remaining leaves similarly, keeping the x-shift -1.65f

    glLoadIdentity();
}

void boat()
{
    glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(-0.2f, 0.4f);
	glVertex2f(-0.15f, 0.35f);
	glVertex2f(0.15f, 0.35f);
    glVertex2f(0.2f, 0.4f);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 153, 0);
	glVertex2f(-0.13f, 0.4f);
	glVertex2f(-0.11f,0.48f);
	glVertex2f(-0.088f, 0.52f);
	glVertex2f(0.13f, 0.52f);
	glVertex2f(0.14f, 0.49f);
    glVertex2f(0.15f, 0.4f);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	glVertex2f(-0.038f, 0.57f);
	glVertex2f(-0.038f, 0.73f);
	glVertex2f(-0.035f, 0.75f);
	glVertex2f(0.064f, 0.73f);
	glVertex2f(0.065f, 0.71f);
    glVertex2f(0.065f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(136,204,0);
	glVertex2f(0.0f, 0.52f);
	glVertex2f(0.0f, 0.79f);
	glVertex2f(0.01f, 0.79f);
	glVertex2f(0.01f, 0.52f);
	glEnd();
}



void boat4()
{
    glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(-0.2f, 0.4f);
	glVertex2f(-0.15f, 0.35f);
	glVertex2f(0.15f, 0.35f);
    glVertex2f(0.2f, 0.4f);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 153, 0);
	glVertex2f(-0.13f, 0.4f);
	glVertex2f(-0.11f,0.48f);
	glVertex2f(-0.088f, 0.52f);
	glVertex2f(0.13f, 0.52f);
	glVertex2f(0.14f, 0.49f);
    glVertex2f(0.15f, 0.4f);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255,25,25);
	glVertex2f(-0.038f, 0.57f);
	glVertex2f(-0.038f, 0.73f);
	glVertex2f(-0.035f, 0.75f);
	glVertex2f(0.064f, 0.73f);
	glVertex2f(0.065f, 0.71f);
    glVertex2f(0.065f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(136,204,0);
	glVertex2f(0.0f, 0.52f);
	glVertex2f(0.0f, 0.79f);
	glVertex2f(0.01f, 0.79f);
	glVertex2f(0.01f, 0.52f);
	glEnd();
}
void Straw()
{
    glBegin(GL_POLYGON);
    glColor3ub(230, 180, 50); // lightest shade at bottom
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.15f);
    glVertex2f(0.07f, 0.20f);
    glVertex2f(0.02f, 0.27f);
    glVertex2f(-0.05f, 0.32f);
    glVertex2f(-0.12f, 0.27f);
    glVertex2f(-0.17f, 0.20f);
    glVertex2f(-0.2f, 0.15f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0); // middle shade
    glVertex2f(-0.17f, 0.20f);
    glVertex2f(0.07f, 0.20f);
    glVertex2f(0.07f, 0.25f);
    glVertex2f(0.02f, 0.32f);
    glVertex2f(-0.05f, 0.37f);
    glVertex2f(-0.12f, 0.32f);
    glVertex2f(-0.17f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 0); // darkest shade at top
    // vertices to make a rounded tip blending with middle shade
    glVertex2f(-0.12f, 0.32f);    // left base
    glVertex2f(-0.10f, 0.34f);
    glVertex2f(-0.07f, 0.36f);
    glVertex2f(-0.05f, 0.37f);    // center top
    glVertex2f(-0.03f, 0.36f);
    glVertex2f(0.00f, 0.34f);
    glVertex2f(0.02f, 0.32f);     // right base
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.05f, 0.37f);
    glVertex2f(-0.05f, 0.40f);
    glEnd();

}

void way()
{
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.25f,-0.2f);
    glVertex2f(0.12f,-0.2f);
    glVertex2f(0.18f,-0.5f);
    glVertex2f(0.33f,-0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.33f,-0.5f);
    glVertex2f(0.65f,-1.0f);
    glVertex2f(0.46f,-1.0f);
    glVertex2f(0.18f,-0.5f);
    glEnd();

}
void way1()
{
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.30f,-0.2f);
    glVertex2f(-0.17f,-0.2f);
    glVertex2f(-0.23f,-0.5f);
    glVertex2f(-0.38f,-0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.38f,-0.5f);
    glVertex2f(-0.70f,-1.0f);
    glVertex2f(-0.51f,-1.0f);
    glVertex2f(-0.23f,-0.5f);
    glEnd();

}


void fence()
{
     glLineWidth(5);
     glBegin(GL_LINES);
    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

     glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

     glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

     glColor3ub(255, 255, 102);
    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
}
void fence2()
{
      glLineWidth(5);
     glBegin(GL_LINES);
     glColor3ub(255, 255, 102);
    glVertex2f(0.9f,-0.1f);
    glVertex2f(0.5f,-0.1f);

    glColor3ub(255, 255, 102);
    glVertex2f(1.0f,-0.1f);
    glVertex2f(0.6f,-0.1f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.9f,-0.05f);
    glVertex2f(0.5f,-0.05f);


    glColor3ub(255, 255, 102);
    glVertex2f(1.0f,-0.05f);
    glVertex2f(0.6f,-0.05f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.9f,0.0f);
    glVertex2f(0.5f,0.0f);

    glColor3ub(255, 255, 102);
    glVertex2f(1.0f,0.0f);
    glVertex2f(0.6f,0.0f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.9f,0.05f);
    glVertex2f(0.5f,0.05f);

     glColor3ub(255, 255, 102);
    glVertex2f(1.0f,0.05f);
    glVertex2f(0.6f,0.05f);

      glColor3ub(255, 255, 102);
    glVertex2f(0.9f,0.1f);
    glVertex2f(0.5f,0.1f);

     glColor3ub(255, 255, 102);
    glVertex2f(1.0f,0.1f);
    glVertex2f(0.6f,0.1f);

     glColor3ub(255, 255, 102);
    glVertex2f(0.95f,0.13f);
    glVertex2f(0.95f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.9f,0.13f);
    glVertex2f(0.9f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.85f,0.13f);
    glVertex2f(0.85f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.8f,0.13f);
    glVertex2f(0.8f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.75f,0.13f);
    glVertex2f(0.75f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.7f,0.13f);
    glVertex2f(0.7f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.65f,0.13f);
    glVertex2f(0.65f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.60f,0.13f);
    glVertex2f(0.60f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.55f,0.13f);
    glVertex2f(0.55f,-0.12f);

    glEnd();
}


void well()
{

glLineWidth(5);
     glBegin(GL_LINES);
    glColor3ub(204, 51, 0);
     glVertex2f(0.9f,-0.35f);
    glVertex2f(0.85f,-0.33f);//
    glVertex2f(0.85f,-0.33f);
    glVertex2f(0.8f,-0.325f);//
    glVertex2f(0.8f,-0.325f);
    glVertex2f(0.7f,-0.325f);//
    glVertex2f(0.7f,-0.325f);
    glVertex2f(0.65f,-0.33f);//
     glVertex2f(0.65f,-0.33f);
     glVertex2f(0.6f,-0.35f);
    glEnd();

    glLineWidth(3);
     glBegin(GL_LINES);
    glColor3ub(194, 194, 163);
    glVertex2f(0.59f,-0.43f);
    glVertex2f(0.57f,-0.39f);//
    glVertex2f(0.57f,-0.39f);
    glVertex2f(0.55f,-0.39f);//
    glVertex2f(0.55f,-0.39f);
    glVertex2f(0.52f,-0.39f);//
    glVertex2f(0.52f,-0.39f);
    glVertex2f(0.5f,-0.43f);//
    glEnd();

    glLineWidth(2.5);
     glBegin(GL_LINES);
    glColor3ub(230, 172, 0);
    glVertex2f(0.545f,-0.385f);
    glVertex2f(0.57f,-0.45f);//
    glVertex2f(0.57f,-0.45f);
    glVertex2f(0.575f,-0.5f);//
    glVertex2f(0.575f,-0.5f);
    glVertex2f(0.58f,-0.53f);//
    glVertex2f(0.58f,-0.53f);
    glVertex2f(0.57f,-0.55f);//
    glVertex2f(0.57f,-0.55f);
    glVertex2f(0.48f,-0.53f);//
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 154, 214);
    glVertex2f(0.585f,-0.43f);
    glVertex2f(0.568f,-0.44f);
    glVertex2f(0.528f,-0.44f);
    glVertex2f(0.505f,-0.43f);
    glVertex2f(0.528f,-0.425f);
    glVertex2f(0.57f,-0.425f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 51, 0);
    glVertex2f(0.9f,-0.35f);
    glVertex2f(0.9f,-0.55f);
    glVertex2f(0.85f,-0.575f);
    glVertex2f(0.8f,-0.59f);
    glVertex2f(0.7f,-0.59f);
    glVertex2f(0.65f,-0.575f);
    glVertex2f(0.6f,-0.55f);
    glVertex2f(0.6f,-0.35f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 51);
    glVertex2f(0.9f,-0.35f);
    glVertex2f(0.85f,-0.375f);
    glVertex2f(0.8f,-0.38f);
    glVertex2f(0.7f,-0.38f);
    glVertex2f(0.65f,-0.375f);
    glVertex2f(0.6f,-0.35f);
    glVertex2f(0.65f,-0.33f);
    glVertex2f(0.7f,-0.325f);
     glVertex2f(0.8f,-0.325f);
     glVertex2f(0.85f,-0.33f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(194, 194, 163);
    glVertex2f(0.59f,-0.43f);
    glVertex2f(0.57f,-0.5f);
    glVertex2f(0.52f,-0.5f);
    glVertex2f(0.5f,-0.43f);
    glVertex2f(0.52f,-0.42f);
    glVertex2f(0.57f,-0.42f);
    glEnd();
}

void well1()
{

     glLineWidth(5);
     glBegin(GL_LINES);
    glColor3ub(204, 51, 0);
     glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.85f,-0.33f);//
    glVertex2f(-0.85f,-0.33f);
    glVertex2f(-0.8f,-0.325f);//
    glVertex2f(-0.8f,-0.325f);
    glVertex2f(-0.7f,-0.325f);//
    glVertex2f(-0.7f,-0.325f);
    glVertex2f(-0.65f,-0.33f);//
     glVertex2f(-0.65f,-0.33f);
     glVertex2f(-0.6f,-0.35f);
    glEnd();

    glLineWidth(3);
     glBegin(GL_LINES);
    glColor3ub(194, 194, 163);
    glVertex2f(-0.59f,-0.43f);
    glVertex2f(-0.57f,-0.39f);//
    glVertex2f(-0.57f,-0.39f);
    glVertex2f(-0.55f,-0.39f);//
    glVertex2f(-0.55f,-0.39f);
    glVertex2f(-0.52f,-0.39f);//
    glVertex2f(-0.52f,-0.39f);
    glVertex2f(-0.5f,-0.43f);//
    glEnd();

    glLineWidth(2.5);
     glBegin(GL_LINES);
    glColor3ub(230, 172, 0);
    glVertex2f(-0.545f,-0.385f);
    glVertex2f(-0.57f,-0.45f);//
    glVertex2f(-0.57f,-0.45f);
    glVertex2f(-0.575f,-0.5f);//
    glVertex2f(-0.575f,-0.5f);
    glVertex2f(-0.58f,-0.53f);//
    glVertex2f(-0.58f,-0.53f);
    glVertex2f(-0.57f,-0.55f);//
    glVertex2f(-0.57f,-0.55f);
    glVertex2f(-0.48f,-0.53f);//
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 154, 214);
    glVertex2f(-0.585f,-0.43f);
    glVertex2f(-0.568f,-0.44f);
    glVertex2f(-0.528f,-0.44f);
    glVertex2f(-0.505f,-0.43f);
    glVertex2f(-0.528f,-0.425f);
    glVertex2f(-0.57f,-0.425f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 51, 0);
    glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.9f,-0.55f);
    glVertex2f(-0.85f,-0.575f);
    glVertex2f(-0.8f,-0.59f);
    glVertex2f(-0.7f,-0.59f);
    glVertex2f(-0.65f,-0.575f);
    glVertex2f(-0.6f,-0.55f);
    glVertex2f(-0.6f,-0.35f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 51);
    glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.85f,-0.375f);
    glVertex2f(-0.8f,-0.38f);
    glVertex2f(-0.7f,-0.38f);
    glVertex2f(-0.65f,-0.375f);
    glVertex2f(-0.6f,-0.35f);
    glVertex2f(-0.65f,-0.33f);
    glVertex2f(-0.7f,-0.325f);
     glVertex2f(-0.8f,-0.325f);
     glVertex2f(-0.85f,-0.33f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(194, 194, 163);
    glVertex2f(-0.59f,-0.43f);
    glVertex2f(-0.57f,-0.5f);
    glVertex2f(-0.52f,-0.5f);
    glVertex2f(-0.5f,-0.43f);
    glVertex2f(-0.52f,-0.42f);
    glVertex2f(-0.57f,-0.42f);
    glEnd();
}
/*
void DrawSphere()
{
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
    glEnable ( GL_COLOR_MATERIAL ) ;
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    cloud3();
    glPopMatrix();
    moon();
    boat4();
    hut1();
    tree();
    backgroundtree();

    fence();
    way();
    tree2();
    tree3();
    Straw();
    ground();
    river();
    backgroundTreeReflection();
    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    sun();
    glPopMatrix();
    stars();
    sky2();
    glFlush();

}
*/
void displayN()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(2);
    sky2();
    moon();
    stars();
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    cloud1();
    cloud2();
    cloud3();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    glPopMatrix();
    backgroundtree();
    riverN();
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
    boat();

    glPopMatrix();
    ground1();
    way();
    fence2();
    hut2();
    tree();
    tree2();
    fence();
    tree3();
    well();
    way1();
    hut();
    hut2();
	glFlush();
	glutSwapBuffers();


}
float rainPosition = 0.0f;    // global rain position
float rainSpeed    = 0.02f;  // speed of falling rain

void update_rain(int value)
{
    rainPosition -= rainSpeed;
    if (rainPosition < -.5f)
    {
        rainPosition = .1f;
    }

    glutPostRedisplay();
    glutTimerFunc(60, update_rain, 0);  // call again every 20 ms
}

void Rain_fall()
{
    glPushMatrix();
    glTranslatef(0, rainPosition, 0);   // falling effect

    glColor3f(0.6f, 0.6f, 1.0f);   // bluish color for rain

    for (float x = -0.95; x <= 1; x += 0.1)  // smaller step for denser rain
    {
        for (float y = -1; y <= 3; y += 0.1)  // limit Y range, no need 1000
        {
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + 0.002, y);
            glVertex2f(x + 0.002, y + 0.08);   // vertical drop
            glVertex2f(x, y + 0.08);
            glEnd();
        }
    }

    glPopMatrix();
}


struct Point
{
    float x, y;
    unsigned char r, g, b, a;
};
std::vector< Point > points;

void displayR(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    sky3();
    cloud1();
    cloud2();
    cloud3();
    backgroundtree();
    river();
    boat();
    ground();
    way();
    way1();
    fence();
    tree3();
    fence2();
    tree();
    tree2();
    well();
    Straw();
    hut();
    hut2();
    Rain_fall();

    glFlush();

}

void displayD() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(2);
    sky();
    sun();
    glPushMatrix();
    glTranslatef(position4,0.0f, 0.0f);
    cloud1();
    cloud2();
    cloud3();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(position22,0.0f, 0.0f);
    bird();
    glPopMatrix();
    backgroundtree();

    river();
    backgroundTreeReflection();
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
    boat();
    glPopMatrix();
    ground();


    way();
    way1();
    well();
    Straw();
    fence();
    tree3();
    fence2();
    tree();
    tree2();

    hut();
    hut2();
    glFlush();
	glutSwapBuffers();
}

///----------------------------------------------------village view end-------------------------------------------------------////



void buildings1()                          ///OID-6
{
    ///1st
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.6f);
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(-0.91f, 0.4f);
    glVertex2f(-0.91f, 0.6f);
    glVertex2f(-1.0f, 0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(-0.91f, 0.4f);
    glVertex2f(-0.89f, 0.4f);
    glVertex2f(-0.89f, 0.57f);
    glVertex2f(-0.91f, 0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.47f);
    glVertex2f(-0.97f, 0.47f);
    glVertex2f(-0.97f, 0.52f);
    glVertex2f(-1.0f, 0.52f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.96f, 0.47f);
    glVertex2f(-0.93f, 0.47f);
    glVertex2f(-0.93f, 0.52f);
    glVertex2f(-0.96f, 0.52f);
    glEnd();

    ///2
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(-0.86f, 0.4f);
    glVertex2f(-0.76f, 0.4f);
    glVertex2f(-0.76f, 0.65f);
    glVertex2f(-0.86f, 0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.4f);
    glVertex2f(-0.76f, 0.4f);
    glVertex2f(-0.73f, 0.4f);
    glVertex2f(-0.73f, 0.62f);
    glVertex2f(-0.76f, 0.65f);
    glEnd();

    ///windows
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.84f, 0.43f);
    glVertex2f(-0.81f, 0.43f);
    glVertex2f(-0.81f, 0.48f);
    glVertex2f(-0.84f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.43f);
    glVertex2f(-0.77f, 0.43f);
    glVertex2f(-0.77f, 0.48f);
    glVertex2f(-0.8f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.84f, 0.5f);
    glVertex2f(-0.81f, 0.5f);
    glVertex2f(-0.81f, 0.55f);
    glVertex2f(-0.84f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.77f, 0.5f);
    glVertex2f(-0.77f, 0.55f);
    glVertex2f(-0.8f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.84f, 0.57f);
    glVertex2f(-0.81f, 0.57f);
    glVertex2f(-0.81f, 0.62f);
    glVertex2f(-0.84f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.57f);
    glVertex2f(-0.77f, 0.57f);
    glVertex2f(-0.77f, 0.62f);
    glVertex2f(-0.8f, 0.62f);
    glEnd();

    ///3
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.72f, 0.4f);
    glVertex2f(-0.62f, 0.4f);
    glVertex2f(-0.62f, 0.71f);
    glVertex2f(-0.72f, 0.71f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.62f, 0.4f);
    glVertex2f(-0.59f, 0.4f);
    glVertex2f(-0.59f, 0.65f);
    glVertex2f(-0.62f, 0.71f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.43f);
    glVertex2f(-0.67f, 0.43f);
    glVertex2f(-0.67f, 0.48f);
    glVertex2f(-0.7f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.43f);
    glVertex2f(-0.63f, 0.43f);
    glVertex2f(-0.63f, 0.48f);
    glVertex2f(-0.66f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.5f);
    glVertex2f(-0.67f, 0.5f);
    glVertex2f(-0.67f, 0.55f);
    glVertex2f(-0.7f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.5f);
    glVertex2f(-0.63f, 0.5f);
    glVertex2f(-0.63f, 0.55f);
    glVertex2f(-0.66f, 0.55f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.57f);
    glVertex2f(-0.67f, 0.57f);
    glVertex2f(-0.67f, 0.62f);
    glVertex2f(-0.7f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.57f);
    glVertex2f(-0.63f, 0.57f);
    glVertex2f(-0.63f, 0.62f);
    glVertex2f(-0.66f, 0.62f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.64f);
    glVertex2f(-0.67f, 0.64f);
    glVertex2f(-0.67f, 0.69f);
    glVertex2f(-0.7f, 0.69f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.64f);
    glVertex2f(-0.63f, 0.64f);
    glVertex2f(-0.63f, 0.69f);
    glVertex2f(-0.66f, 0.69f);
    glEnd();

    ///4
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2f(-0.58f, 0.4f);
    glVertex2f(-0.48f, 0.4f);
    glVertex2f(-0.48f, 0.5f);
    glVertex2f(-0.58f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2f(-0.48f, 0.4f);
    glVertex2f(-0.47f, 0.4f);
    glVertex2f(-0.47f, 0.48f);
    glVertex2f(-0.48f, 0.5f);
    glEnd();

    ///windows
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.56f, 0.43f);
    glVertex2f(-0.53f, 0.43f);
    glVertex2f(-0.53f, 0.48f);
    glVertex2f(-0.56f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.52f, 0.43f);
    glVertex2f(-0.49f, 0.43f);
    glVertex2f(-0.49f, 0.48f);
    glVertex2f(-0.52f, 0.48f);
    glEnd();

    ///5
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.45f, 0.4f);
    glVertex2f(-0.35f, 0.4f);
    glVertex2f(-0.35f, 0.72f);
    glVertex2f(-0.45f, 0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.35f, 0.4f);
    glVertex2f(-0.33f, 0.4f);
    glVertex2f(-0.33f, 0.67f);
    glVertex2f(-0.35f, 0.72f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.43f);
    glVertex2f(-0.4f, 0.43f);
    glVertex2f(-0.4f, 0.48f);
    glVertex2f(-0.43f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.43f);
    glVertex2f(-0.36f, 0.43f);
    glVertex2f(-0.36f, 0.48f);
    glVertex2f(-0.39f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.5f);
    glVertex2f(-0.4f, 0.5f);
    glVertex2f(-0.4f, 0.55f);
    glVertex2f(-0.43f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.5f);
    glVertex2f(-0.36f, 0.5f);
    glVertex2f(-0.36f, 0.55f);
    glVertex2f(-0.39f, 0.55f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.57f);
    glVertex2f(-0.4f, 0.57f);
    glVertex2f(-0.4f, 0.62f);
    glVertex2f(-0.43f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.57f);
    glVertex2f(-0.36f, 0.57f);
    glVertex2f(-0.36f, 0.62f);
    glVertex2f(-0.39f, 0.62f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.64f);
    glVertex2f(-0.4f, 0.64f);
    glVertex2f(-0.4f, 0.69f);
    glVertex2f(-0.43f, 0.69f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.64f);
    glVertex2f(-0.36f, 0.64f);
    glVertex2f(-0.36f, 0.69f);
    glVertex2f(-0.39f, 0.69f);
    glEnd();

    ///6
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.3f);
    glVertex2f(-0.3f, 0.4f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.2f, 0.6f);
    glVertex2f(-0.3f, 0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.2f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.18f, 0.4f);
    glVertex2f(-0.18f, 0.57f);
    glVertex2f(-0.2f, 0.6f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.28f, 0.43f);
    glVertex2f(-0.25f, 0.43f);
    glVertex2f(-0.25f, 0.48f);
    glVertex2f(-0.28f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.24f, 0.43f);
    glVertex2f(-0.21f, 0.43f);
    glVertex2f(-0.21f, 0.48f);
    glVertex2f(-0.24f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.28f, 0.5f);
    glVertex2f(-0.25f, 0.5f);
    glVertex2f(-0.25f, 0.55f);
    glVertex2f(-0.28f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.24f, 0.5f);
    glVertex2f(-0.21f, 0.5f);
    glVertex2f(-0.21f, 0.55f);
    glVertex2f(-0.24f, 0.55f);
    glEnd();

    ///7
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.0f);
    glVertex2f(-0.17f, 0.4f);
    glVertex2f(-0.07f, 0.4f);
    glVertex2f(-0.07f, 0.65f);
    glVertex2f(-0.17f, 0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.0f);
    glVertex2f(-0.07f, 0.4f);
    glVertex2f(-0.06f, 0.4f);
    glVertex2f(-0.06f, 0.62f);
    glVertex2f(-0.07f, 0.65f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.43f);
    glVertex2f(-0.13f, 0.43f);
    glVertex2f(-0.13f, 0.48f);
    glVertex2f(-0.16f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.43f);
    glVertex2f(-0.09f, 0.43f);
    glVertex2f(-0.09f, 0.48f);
    glVertex2f(-0.12f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.5f);
    glVertex2f(-0.13f, 0.5f);
    glVertex2f(-0.13f, 0.55f);
    glVertex2f(-0.16f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.5f);
    glVertex2f(-0.09f, 0.5f);
    glVertex2f(-0.09f, 0.55f);
    glVertex2f(-0.12f, 0.55f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.57f);
    glVertex2f(-0.13f, 0.57f);
    glVertex2f(-0.13f, 0.62f);
    glVertex2f(-0.16f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.57f);
    glVertex2f(-0.09f, 0.57f);
    glVertex2f(-0.09f, 0.62f);
    glVertex2f(-0.12f, 0.62f);
    glEnd();

    ///8
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.4f);
    glVertex2f(-0.04f, 0.4f);
    glVertex2f(0.04f, 0.4f);
    glVertex2f(0.04f, 0.71f);
    glVertex2f(-0.04f, 0.71f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.1f, 0.1f);
    glVertex2f(0.04f, 0.4f);
    glVertex2f(0.043f, 0.4f);
    glVertex2f(0.043f, 0.65f);
    glVertex2f(0.04f, 0.71f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.43f);
    glVertex2f(-0.01f, 0.43f);
    glVertex2f(-0.01f, 0.48f);
    glVertex2f(-0.03f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.43f);
    glVertex2f(0.03f, 0.43f);
    glVertex2f(0.03f, 0.48f);
    glVertex2f(0.01f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.5f);
    glVertex2f(-0.01f, 0.5f);
    glVertex2f(-0.01f, 0.55f);
    glVertex2f(-0.03f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.5f);
    glVertex2f(0.03f, 0.5f);
    glVertex2f(0.03f, 0.55f);
    glVertex2f(0.01f, 0.55f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.57f);
    glVertex2f(-0.01f, 0.57f);
    glVertex2f(-0.01f, 0.62f);
    glVertex2f(-0.03f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.57f);
    glVertex2f(0.03f, 0.57f);
    glVertex2f(0.03f, 0.62f);
    glVertex2f(0.01f, 0.62f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.64f);
    glVertex2f(-0.01f, 0.64f);
    glVertex2f(-0.01f, 0.69f);
    glVertex2f(-0.03f, 0.69f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.64f);
    glVertex2f(0.03f, 0.64f);
    glVertex2f(0.03f, 0.69f);
    glVertex2f(0.01f, 0.69f);
    glEnd();

    ///9
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.4f);
    glVertex2f(0.18f, 0.4f);
    glVertex2f(0.18f, 0.6f);
    glVertex2f(0.08f, 0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(0.07f, 0.4f);
    glVertex2f(0.08f, 0.4f);
    glVertex2f(0.08f, 0.6f);
    glVertex2f(0.07f, 0.55f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.43f);
    glVertex2f(0.12f, 0.43f);
    glVertex2f(0.12f, 0.48f);
    glVertex2f(0.09f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.43f);
    glVertex2f(0.16f, 0.43f);
    glVertex2f(0.16f, 0.48f);
    glVertex2f(0.13f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.5f);
    glVertex2f(0.12f, 0.5f);
    glVertex2f(0.12f, 0.55f);
    glVertex2f(0.09f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.5f);
    glVertex2f(0.16f, 0.5f);
    glVertex2f(0.16f, 0.55f);
    glVertex2f(0.13f, 0.55f);
    glEnd();

    ///10
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.22f, 0.4f);
    glVertex2f(0.32f, 0.4f);
    glVertex2f(0.32f, 0.65f);
    glVertex2f(0.22f, 0.65f);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.22f, 0.4f);
    glVertex2f(0.22f, 0.65f);
    glVertex2f(0.2f, 0.62f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.24f, 0.43f);
    glVertex2f(0.27f, 0.43f);
    glVertex2f(0.27f, 0.48f);
    glVertex2f(0.24f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.28f, 0.43f);
    glVertex2f(0.31f, 0.43f);
    glVertex2f(0.31f, 0.48f);
    glVertex2f(0.28f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.24f, 0.5f);
    glVertex2f(0.27f, 0.5f);
    glVertex2f(0.27f, 0.55f);
    glVertex2f(0.24f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.28f, 0.5f);
    glVertex2f(0.31f, 0.5f);
    glVertex2f(0.31f, 0.55f);
    glVertex2f(0.28f, 0.55f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.24f, 0.57f);
    glVertex2f(0.27f, 0.57f);
    glVertex2f(0.27f, 0.62f);
    glVertex2f(0.24f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.28f, 0.57f);
    glVertex2f(0.31f, 0.57f);
    glVertex2f(0.31f, 0.62f);
    glVertex2f(0.28f, 0.62f);
    glEnd();
}
/////////////////////////////////////train////////////////////////
float r_l_train_position=0;
float r_l_train_speed=0.01;

void r_l_train()
{
glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(r_l_train_position-0.8,0,0);
    glScalef(-1,1,0);

glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.01, 0.695);
    glVertex2f(0.05, 0.695);
    glVertex2f(0.05 ,0.699);
    glVertex2f(0.01, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.025, 0.677);
    glVertex2f(0.028, 0.677);
    glVertex2f(0.05 ,0.685);
    glVertex2f(0.045, 0.685);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.045, 0.685);
    glVertex2f(0.05, 0.685);
    glVertex2f(0.025 ,0.699);
    glVertex2f(0.023, 0.699);
    glEnd();

////////////////////////////////////////////body 1
glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.0, 0.67);
    glVertex2f(0.1, 0.67);
    glVertex2f(.1 ,0.677);
    glVertex2f(0, 0.677);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.0, 0.63);
    glVertex2f(0.1, 0.63);
    glVertex2f(.1 ,0.67);
    glVertex2f(0, 0.67);
    glEnd();

    /////////////////////dore1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.01, 0.635);
    glVertex2f(0.025, 0.635);
    glVertex2f(.025 ,0.665);
    glVertex2f(0.01, 0.665);
    glEnd();
    //////////////////////windows1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.03, 0.64);
    glVertex2f(0.06, 0.64);
    glVertex2f(.06 ,0.665);
    glVertex2f(0.03, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.065, 0.635);
    glVertex2f(0.08, 0.635);
    glVertex2f(.08 ,0.665);
    glVertex2f(0.065, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.085, 0.64);
    glVertex2f(0.1, 0.64);
    glVertex2f(.1,0.665);
    glVertex2f(0.085, 0.665);
    glEnd();
    /////////////////////////////////////////body 2
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.105, 0.63);
    glVertex2f(0.2, 0.63);
    glVertex2f(.2 ,0.67);
    glVertex2f(0.105, 0.67);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.105, 0.67);
    glVertex2f(0.2, 0.67);
    glVertex2f(.2 ,0.677);
    glVertex2f(0.105, 0.677);
    glEnd();
    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.11, 0.635);
    glVertex2f(0.125, 0.635);
    glVertex2f(.125 ,0.665);
    glVertex2f(0.11, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.13, 0.64);
    glVertex2f(0.16, 0.64);
    glVertex2f(.16 ,0.665);
    glVertex2f(0.13, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.165, 0.635);
    glVertex2f(0.18, 0.635);
    glVertex2f(.18 ,0.665);
    glVertex2f(0.165, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.185, 0.64);
    glVertex2f(0.2, 0.64);
    glVertex2f(.2,0.665);
    glVertex2f(0.185, 0.665);
    glEnd();
    /////////////////////////////body 3
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.205, 0.63);
    glVertex2f(0.3, 0.63);
    glVertex2f(.3 ,0.67);
    glVertex2f(0.205, 0.67);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.205, 0.67);
    glVertex2f(0.3, 0.67);
    glVertex2f(.3,0.677);
    glVertex2f(0.205, 0.677);
    glEnd();
    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.21, 0.635);
    glVertex2f(0.225, 0.635);
    glVertex2f(.225 ,0.665);
    glVertex2f(0.21, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.23, 0.64);
    glVertex2f(0.26, 0.64);
    glVertex2f(.26 ,0.665);
    glVertex2f(0.23, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.265, 0.635);
    glVertex2f(0.28, 0.635);
    glVertex2f(.28 ,0.665);
    glVertex2f(0.265, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.285, 0.64);
    glVertex2f(0.3, 0.64);
    glVertex2f(.3,0.665);
    glVertex2f(0.285, 0.665);
    glEnd();
    //////////////////////////////////////body 4

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.37, 0.695);
    glVertex2f(0.41, 0.695);
    glVertex2f(0.41 ,0.699);
    glVertex2f(0.37, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.389, 0.677);
    glVertex2f(0.391, 0.677);
    glVertex2f(0.41 ,0.685);
    glVertex2f(0.399, 0.685);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.40, 0.685);
    glVertex2f(0.41, 0.685);
    glVertex2f(0.391 ,0.699);
    glVertex2f(0.389, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.305, 0.67);
    glVertex2f(0.41, 0.67);
    glVertex2f(.41 ,0.677);
    glVertex2f(0.305, 0.677);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.305, 0.63);
    glVertex2f(0.41, 0.63);
    glVertex2f(.41,0.67);
    glVertex2f(0.305, 0.67);
    glEnd();

    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.31, 0.635);
    glVertex2f(0.325, 0.635);
    glVertex2f(.325 ,0.665);
    glVertex2f(0.31, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.33, 0.64);
    glVertex2f(0.36, 0.64);
    glVertex2f(.36 ,0.665);
    glVertex2f(0.33, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.365, 0.635);
    glVertex2f(0.38, 0.635);
    glVertex2f(.38 ,0.665);
    glVertex2f(0.365, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.385, 0.64);
    glVertex2f(0.4, 0.64);
    glVertex2f(.4,0.665);
    glVertex2f(0.385, 0.665);
    glEnd();

    glPopMatrix();
    glLoadIdentity();
    // glPopMatrix();
}

float l_r_train_position=0;
float l_r_train_speed=0.02;


void l_r_train(){

glColor3ub(155,150,150);
glPushMatrix();
    glRotatef(0,0,1,0);
    glTranslatef(l_r_train_position-0.6,-0.0,0);




glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.01, 0.695);
    glVertex2f(0.05, 0.695);
    glVertex2f(0.05 ,0.699);
    glVertex2f(0.01, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.025, 0.677);
    glVertex2f(0.028, 0.677);
    glVertex2f(0.05 ,0.685);
    glVertex2f(0.045, 0.685);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.045, 0.685);
    glVertex2f(0.05, 0.685);
    glVertex2f(0.025 ,0.699);
    glVertex2f(0.023, 0.699);
    glEnd();

////////////////////////////////////////////body 1
glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.0, 0.67);
    glVertex2f(0.1, 0.67);
    glVertex2f(.1 ,0.677);
    glVertex2f(0, 0.677);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.0, 0.63);
    glVertex2f(0.1, 0.63);
    glVertex2f(.1 ,0.67);
    glVertex2f(0, 0.67);
    glEnd();

    /////////////////////dore1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.01, 0.635);
    glVertex2f(0.025, 0.635);
    glVertex2f(.025 ,0.665);
    glVertex2f(0.01, 0.665);
    glEnd();
    //////////////////////windows1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.03, 0.64);
    glVertex2f(0.06, 0.64);
    glVertex2f(.06 ,0.665);
    glVertex2f(0.03, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.065, 0.635);
    glVertex2f(0.08, 0.635);
    glVertex2f(.08 ,0.665);
    glVertex2f(0.065, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.085, 0.64);
    glVertex2f(0.1, 0.64);
    glVertex2f(.1,0.665);
    glVertex2f(0.085, 0.665);
    glEnd();
    /////////////////////////////////////////body 2
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.105, 0.63);
    glVertex2f(0.2, 0.63);
    glVertex2f(.2 ,0.67);
    glVertex2f(0.105, 0.67);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.105, 0.67);
    glVertex2f(0.2, 0.67);
    glVertex2f(.2 ,0.677);
    glVertex2f(0.105, 0.677);
    glEnd();
    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.11, 0.635);
    glVertex2f(0.125, 0.635);
    glVertex2f(.125 ,0.665);
    glVertex2f(0.11, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.13, 0.64);
    glVertex2f(0.16, 0.64);
    glVertex2f(.16 ,0.665);
    glVertex2f(0.13, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.165, 0.635);
    glVertex2f(0.18, 0.635);
    glVertex2f(.18 ,0.665);
    glVertex2f(0.165, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.185, 0.64);
    glVertex2f(0.2, 0.64);
    glVertex2f(.2,0.665);
    glVertex2f(0.185, 0.665);
    glEnd();
    /////////////////////////////body 3
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.205, 0.63);
    glVertex2f(0.3, 0.63);
    glVertex2f(.3 ,0.67);
    glVertex2f(0.205, 0.67);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.205, 0.67);
    glVertex2f(0.3, 0.67);
    glVertex2f(.3,0.677);
    glVertex2f(0.205, 0.677);
    glEnd();
    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.21, 0.635);
    glVertex2f(0.225, 0.635);
    glVertex2f(.225 ,0.665);
    glVertex2f(0.21, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.23, 0.64);
    glVertex2f(0.26, 0.64);
    glVertex2f(.26 ,0.665);
    glVertex2f(0.23, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.265, 0.635);
    glVertex2f(0.28, 0.635);
    glVertex2f(.28 ,0.665);
    glVertex2f(0.265, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.285, 0.64);
    glVertex2f(0.3, 0.64);
    glVertex2f(.3,0.665);
    glVertex2f(0.285, 0.665);
    glEnd();
    //////////////////////////////////////body 4

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.37, 0.695);
    glVertex2f(0.41, 0.695);
    glVertex2f(0.41 ,0.699);
    glVertex2f(0.37, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.389, 0.677);
    glVertex2f(0.391, 0.677);
    glVertex2f(0.41 ,0.685);
    glVertex2f(0.399, 0.685);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.40, 0.685);
    glVertex2f(0.41, 0.685);
    glVertex2f(0.391 ,0.699);
    glVertex2f(0.389, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.305, 0.67);
    glVertex2f(0.41, 0.67);
    glVertex2f(.41 ,0.677);
    glVertex2f(0.305, 0.677);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.305, 0.63);
    glVertex2f(0.41, 0.63);
    glVertex2f(.41,0.67);
    glVertex2f(0.305, 0.67);
    glEnd();

    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.31, 0.635);
    glVertex2f(0.325, 0.635);
    glVertex2f(.325 ,0.665);
    glVertex2f(0.31, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.33, 0.64);
    glVertex2f(0.36, 0.64);
    glVertex2f(.36 ,0.665);
    glVertex2f(0.33, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.365, 0.635);
    glVertex2f(0.38, 0.635);
    glVertex2f(.38 ,0.665);
    glVertex2f(0.365, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.385, 0.64);
    glVertex2f(0.4, 0.64);
    glVertex2f(.4,0.665);
    glVertex2f(0.385, 0.665);
    glEnd();

    glPopMatrix();
    glLoadIdentity();
    // glPopMatrix();

}

void bridge()
{
   glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);   // gray color
    glVertex2f(-1, 0.6);
    glVertex2f(1, 0.6);
    glVertex2f(1 ,0.63);
    glVertex2f(-1, 0.63);
   glEnd();

}

void Wire11()
{glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-1, 0.7);
    glVertex2f(1, 0.7);
    glVertex2f(1 ,0.702);
    glVertex2f(-1, 0.702);
    glEnd();

}


void bridge_wirepillar()

{
 float L = 140.0;
    float l = 40.0;

    glScalef(0.005,0.005,0);

    // left side pillars with lights
    for (int i = 0; i <= 6; i++)   /// pillar 1 to 7
    {
        float x = 62.0f - i*l;

        // draw pillar line
        glColor3ub(0,0,0);
        glLineWidth(6.0f);   // uniform pillar width
        glBegin(GL_LINES);
        glVertex2f(x,260.0f-L);
        glVertex2f(x,282.0f-L);
        glEnd();

        // light bulb (sphere) on top of pillar
        glPushMatrix();
        glTranslatef(x, 282.0f-L, 0.0f);   // move to top of pillar
        glColor3ub(255, 255, 0);           // yellow light
        glutSolidSphere(3, 20, 20);        // smaller bulb (radius 3)
        glPopMatrix();
    }

    // right side pillars with lights
    float right_x[] = {62.0f + l, 62.0f + 2.2f*l, 62.0f + 3*l};

    for (int j = 0; j < 3; j++)
    {
        float x = right_x[j];

        // draw pillar line
        glColor3ub(0,0,0);
        glLineWidth(6.0f);   // uniform pillar width
        glBegin(GL_LINES);
        glVertex2f(x,260.0f-L);
        glVertex2f(x,282.0f-L);
        glEnd();

        // light bulb on top
        glPushMatrix();
        glTranslatef(x, 282.0f-L, 0.0f);
        glColor3ub(255,255,0);
        glutSolidSphere(3, 20, 20);        // smaller bulb (radius 3)
        glPopMatrix();
    }

    glLoadIdentity();
}
////////////////////////////////bench

void road_border6()
{ glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(-1, 0.49);
    glVertex2f(1, 0.49);
    glVertex2f(1 ,0.50);
    glVertex2f(-1, 0.50);
    glEnd();


//////////////////////////////////////white line
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-1, 0.49);
    glVertex2f(-0.98, 0.49);
    glVertex2f(-0.98 ,0.50);
    glVertex2f(-1, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.9, 0.49);
    glVertex2f(-0.8, 0.49);
    glVertex2f(-0.8 ,0.50);
    glVertex2f(-0.9, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.7, 0.49);
    glVertex2f(-0.6, 0.49);
    glVertex2f(-0.6 ,0.50);
    glVertex2f(-0.7, 0.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.5, 0.49);
    glVertex2f(-0.4, 0.49);
    glVertex2f(-0.4 ,0.50);
    glVertex2f(-0.5, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.3, 0.49);
    glVertex2f(-0.2, 0.49);
    glVertex2f(-0.2 ,0.50);
    glVertex2f(-0.3, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.1, 0.49);
    glVertex2f(-0.05, 0.49);
    glVertex2f(-0.05 ,0.50);
    glVertex2f(-0.1, 0.50);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.0, 0.49);
    glVertex2f(0.05, 0.49);
    glVertex2f(0.05,0.50);
    glVertex2f(0.0, 0.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.15, 0.49);
    glVertex2f(0.2, 0.49);
    glVertex2f(0.2 ,0.50);
    glVertex2f(0.15, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.35, 0.49);
    glVertex2f(0.4, 0.49);
    glVertex2f(0.4 ,0.50);
    glVertex2f(0.35, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.55, 0.49);
    glVertex2f(0.6, 0.49);
    glVertex2f(0.6 ,0.50);
    glVertex2f(0.55, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.65, 0.49);
    glVertex2f(0.7, 0.49);
    glVertex2f(0.7 ,0.50);
    glVertex2f(0.65, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.85, 0.49);
    glVertex2f(0.9, 0.49);
    glVertex2f(0.9 ,0.50);
    glVertex2f(0.85, 0.50);
    glEnd();
    }

int triangleAmount = 500;
float twicePi = 2.0f * PI;
float angle1=0.0;
float angle2=120.0;
float angle3=240.0;


void bus_wheel_circle(GLfloat cx, GLfloat cy, GLfloat radius, int r, int g, int b)
{
    glColor3ub(r,g,b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            cx + (radius * cos(i *  twicePi / triangleAmount)),
            cy + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}

    void road1()
    {glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex2f(-1, 0.30);
    glVertex2f(1, 0.30);
    glVertex2f(1 ,0.49);
    glVertex2f(-1, 0.49);
    glEnd();
        }
    float public_bus_position=0;
float public_bus_speed=0.01;
        void public_bus()
    {glPushMatrix();
    glRotatef(0,0,1,0);
    glTranslatef(public_bus_position-0.6,-0.0,0);
    ////////////////////////////body

        glBegin(GL_QUADS);
   glColor3f(1, 0, 0);
    glVertex2f(-.9, 0.47);
    glVertex2f(-0.67, 0.47);
    glVertex2f(-.67,0.55);
    glVertex2f(-0.9, 0.55);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(0, 0, 0);
    glVertex2f(-.89, 0.49);
    glVertex2f(-0.695, 0.49);
    glVertex2f(-.695 ,0.53);
    glVertex2f(-0.89, 0.53);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(0, 0, 0);
    glVertex2f(-.69, 0.48);
    glVertex2f(-0.67, 0.48);
    glVertex2f(-.67,0.53);
    glVertex2f(-0.69, 0.53);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(0, 0, 0);
   glVertex2f(-0.68, 0.545);
    glVertex2f(-.65, 0.545);
    glVertex2f(-.65,0.55);
    glVertex2f(-0.68, 0.55);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(0, 0, 0);
   glVertex2f(-0.658, 0.52);
    glVertex2f(-.65, 0.52);
    glVertex2f(-.65,0.55);
    glVertex2f(-0.658, 0.55);
    glEnd();

    ///////GLfloat cx, GLfloat cy, GLfloat radius, int r, int g, int b
    bus_wheel_circle(-0.87,0.47,0.015,1,1,1);
    bus_wheel_circle(-0.83,0.47,0.015,1,1,1);
    bus_wheel_circle(-0.71,0.47,0.015,1,1,1);

     glPopMatrix();
    glLoadIdentity();
    }

void road_marking()
    {
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(-1, 0.445);
    glVertex2f(-0.2, 0.445);
    glVertex2f(-.2 ,0.45);
    glVertex2f(-1, 0.45);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(-0.15, 0.445);
    glVertex2f(-0.1, 0.445);
    glVertex2f(-.1 ,0.45);
    glVertex2f(-0.15, 0.45);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(-0.08, 0.445);
    glVertex2f(-0.05, 0.445);
    glVertex2f(-.05,0.45);
    glVertex2f(-0.08, 0.45);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(-0.03, 0.445);
    glVertex2f(0.01, 0.445);
    glVertex2f(0.01,0.45);
    glVertex2f(-0.03, 0.45);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(0.03, 0.445);
    glVertex2f(0.07, 0.445);
    glVertex2f(.07,0.45);
    glVertex2f(0.03, 0.45);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(0.1, 0.445);
    glVertex2f(1, 0.445);
    glVertex2f(1 ,0.45);
    glVertex2f(0.1, 0.45);
    glEnd();

        }////////////////////////////////////////////pillar fence
void p_fence()                            ///OID-15
{   glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(-1, 0.52);
    glVertex2f(-0.15, 0.52);
    glVertex2f(-0.15 ,0.522);
    glVertex2f(-1, 0.522);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(0.15, 0.52);
    glVertex2f(1, 0.52);
    glVertex2f(1 ,0.522);
    glVertex2f(0.15, 0.522);
    glEnd();

    float L = 0.05;
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.98f,0.52f);
    glVertex2f(-0.98f,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.94f,0.52f);
    glVertex2f(-0.94f,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.9f,0.52f);
    glVertex2f(-0.9f,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f,0.52f);
    glVertex2f(-0.85f,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+L,0.52f);
    glVertex2f(-0.85f+L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.84f+2*L,0.52f);
    glVertex2f(-0.84f+2*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+3*L,0.52f);
    glVertex2f(-0.85f+3*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+4*L,0.52f);
    glVertex2f(-0.85f+4*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+5*L,0.52f);
    glVertex2f(-0.85f+5*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.84f+6*L,0.52f);
    glVertex2f(-0.84f+6*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+7*L,0.52f);
    glVertex2f(-0.85f+7*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+8*L,0.52f);
    glVertex2f(-0.85f+8*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+9*L,0.52f);
    glVertex2f(-0.85f+9*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.84f+10*L,0.52f);
    glVertex2f(-0.84f+10*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+11*L,0.52f);
    glVertex2f(-0.85f+11*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+12*L,0.52f);
    glVertex2f(-0.85f+12*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+13*L,0.52f);
    glVertex2f(-0.85f+13*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+14*L,0.52f);
    glVertex2f(-0.85f+14*L,0.50f);
    glEnd();

    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+21*L,0.52f);
    glVertex2f(-0.85f+21*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+22*L,0.52f);
    glVertex2f(-0.85f+22*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+23*L,0.52f);
    glVertex2f(-0.85f+23*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+24*L,0.52f);
    glVertex2f(-0.85f+24*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+25*L,0.52f);
    glVertex2f(-0.85f+25*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+26*L,0.52f);
    glVertex2f(-0.85f+26*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+27*L,0.52f);
    glVertex2f(-0.85f+27*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+28*L,0.52f);
    glVertex2f(-0.85f+28*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+29*L,0.52f);
    glVertex2f(-0.85f+29*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+30*L,0.52f);
    glVertex2f(-0.85f+30*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+31*L,0.52f);
    glVertex2f(-0.85f+31*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+32*L,0.52f);
    glVertex2f(-0.85f+32*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+33*L,0.52f);
    glVertex2f(-0.85f+33*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+34*L,0.52f);
    glVertex2f(-0.85f+34*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+35*L,0.52f);
    glVertex2f(-0.85f+35*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+36*L,0.52f);
    glVertex2f(-0.85f+36*L,0.50f);
    glEnd();



}
//////////////////////////////////////////////////////
void pillar()
{   //////p1
glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
     glVertex2f(-0.97, 0.57);
    glVertex2f(-0.95 ,0.57);
    glVertex2f(-0.92 ,0.63);
    glVertex2f(-1, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-0.97, 0.5);
    glVertex2f(-0.95, 0.5);
    glVertex2f(-0.95 ,0.57);
    glVertex2f(-0.97, 0.57);
    glEnd();

//////p2

glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
     glVertex2f(-0.77, 0.57);
    glVertex2f(-0.75 ,0.57);
    glVertex2f(-0.72 ,0.63);
    glVertex2f(-0.8, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-0.77, 0.5);
    glVertex2f(-0.75, 0.5);
    glVertex2f(-0.75 ,0.57);
    glVertex2f(-0.77, 0.57);
    glEnd();
    //////p3


glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
     glVertex2f(-0.57, 0.57);
    glVertex2f(-0.55 ,0.57);
    glVertex2f(-0.52 ,0.63);
    glVertex2f(-0.6, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-0.57, 0.5);
    glVertex2f(-0.55, 0.5);
    glVertex2f(-0.55 ,0.57);
    glVertex2f(-0.57, 0.57);
    glEnd();
    //////p4

glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
     glVertex2f(-0.37, 0.57);
    glVertex2f(-0.35 ,0.57);
    glVertex2f(-0.32 ,0.63);
    glVertex2f(-0.4, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-0.37, 0.5);
    glVertex2f(-0.35, 0.5);
    glVertex2f(-0.35 ,0.57);
    glVertex2f(-0.37, 0.57);
    glEnd();
    //////p5

glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
     glVertex2f(-0.17, 0.57);
    glVertex2f(-0.15 ,0.57);
    glVertex2f(-0.12 ,0.63);
    glVertex2f(-0.2, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-0.17, 0.5);
    glVertex2f(-0.15, 0.5);
    glVertex2f(-0.15 ,0.57);
    glVertex2f(-0.17, 0.57);
    glEnd();
    //////p6


glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(0.15 ,0.57);
     glVertex2f(0.17, 0.57);
    glVertex2f(0.2 ,0.63);
    glVertex2f(0.12, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(0.17, 0.5);
    glVertex2f(0.15, 0.5);
    glVertex2f(0.15 ,0.57);
    glVertex2f(0.17, 0.57);
    glEnd();
    //////p7
glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(0.35 ,0.57);
     glVertex2f(0.37, 0.57);
    glVertex2f(0.4 ,0.63);
    glVertex2f(0.32, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(0.37, 0.5);
    glVertex2f(0.35, 0.5);
    glVertex2f(0.35 ,0.57);
    glVertex2f(0.37, 0.57);
    glEnd();
    //////p9
glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(0.65 ,0.57);
     glVertex2f(0.67, 0.57);
    glVertex2f(0.7 ,0.63);
    glVertex2f(0.62, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);

    glVertex2f(0.65, 0.5);
    glVertex2f(0.67, 0.5);
     glVertex2f(0.67, 0.57);
    glVertex2f(0.65 ,0.57);

    glEnd();


}


//////////////////////////////////////

void buildings()                          ///OID-6
{   ///////////////////////////////1st
  glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.6f);
    glVertex2f(0.0f, 0.50f);
    glVertex2f(0.1f, 0.50f);
    glVertex2f(0.1f, 0.80f);
    glVertex2f(0.0f, 0.80f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(0.1f, 0.50f);
    glVertex2f(0.15f, 0.50f);
    glVertex2f(0.15f, 0.78f);
    glVertex2f(0.1f, 0.80f);
    glEnd();
    //////////////////////////////////1st windows

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(0.05f, 0.60f);
    glVertex2f(0.0f, 0.60f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.05f, 0.60f);
    glVertex2f(0.1f, 0.60f);
    glVertex2f(0.1f, 0.65f);
    glVertex2f(0.05f, 0.65f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.005f, 0.65f);
    glVertex2f(0.05f, 0.65f);
    glVertex2f(0.05f, 0.70f);
    glVertex2f(0.005f, 0.70f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.05f, 0.70f);
    glVertex2f(0.1f, 0.70f);
    glVertex2f(0.1f, 0.75f);
    glVertex2f(0.05f, 0.75f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.005f, 0.75f);
    glVertex2f(0.05f, 0.75f);
    glVertex2f(0.05f, 0.795f);
    glVertex2f(0.005f, 0.795f);
    glEnd();



    ///////////////////////////////1st
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(0.2f, 0.50f);
    glVertex2f(0.3f, 0.50f);
    glVertex2f(0.3f, 0.80f);
    glVertex2f(0.2f, 0.80f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(0.2f, 0.50f);
    glVertex2f(0.3f, 0.50f);
    glVertex2f(0.3f, 0.80f);
    glVertex2f(0.2f, 0.80f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.4f, 0.0f, 0.4f);
    glVertex2f(0.2f, 0.50f);
    glVertex2f(0.22f, 0.50f);
    glVertex2f(0.22f, 0.78f);
    glVertex2f(0.2f, 0.80f);
    glEnd();

    ///////////////////////////////1st
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(0.35f, 0.50f);
    glVertex2f(0.65f, 0.50f);
    glVertex2f(0.65f, 0.80f);
    glVertex2f(0.35f, 0.80f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.50f);
    glVertex2f(0.64f, 0.50f);
    glVertex2f(0.64f, 0.54f);
    glVertex2f(0.36f, 0.54f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.55f);
    glVertex2f(0.64f, 0.55f);
    glVertex2f(0.64f, 0.59f);
    glVertex2f(0.36f, 0.59f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.60f);
    glVertex2f(0.64f, 0.60f);
    glVertex2f(0.64f, 0.64f);
    glVertex2f(0.36f, 0.64f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.65f);
    glVertex2f(0.64f, 0.65f);
    glVertex2f(0.64f, 0.69f);
    glVertex2f(0.36f, 0.69f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.70f);
    glVertex2f(0.64f, 0.70f);
    glVertex2f(0.64f, 0.74f);
    glVertex2f(0.36f, 0.74f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.75f);
    glVertex2f(0.64f, 0.75f);
    glVertex2f(0.64f, 0.79f);
    glVertex2f(0.36f, 0.79f);
    glEnd();

    glBegin(GL_QUADS);
     glColor3f(0.00,0.40,0.80);
    glVertex2f(0.42f, 0.50f);
    glVertex2f(0.45f, 0.50f);
    glVertex2f(0.45f, 0.79f);
    glVertex2f(0.42f, 0.79f);
    glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.00,0.40,0.80);
    glVertex2f(0.55f, 0.50f);
    glVertex2f(0.57f, 0.50f);
    glVertex2f(0.57f, 0.79f);
    glVertex2f(0.55f, 0.79f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.0f, 0.3f);
    glVertex2f(0.42f, 0.80f);
    glVertex2f(0.57f, 0.80f);
    glVertex2f(0.57f, 0.85f);
    glVertex2f(0.42f, 0.85f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.6f, 0.6f);
   glVertex2f(0.42f, 0.85f);
    glVertex2f(0.57f, 0.85f);

     glVertex2f(0.5f, 0.90f);
    glVertex2f(0.5f, 0.90f);
    glEnd();

///////////////////////////////1st
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(0.7f, 0.50f);
    glVertex2f(0.85f, 0.50f);
    glVertex2f(0.85f, 0.90f);
    glVertex2f(0.7f, 0.90f);
    glEnd();
    //windows 4
    glBegin(GL_QUADS);
     glColor3f(0.00f,0.50f,0.60f);
    glVertex2f(0.77f, 0.50f);
    glVertex2f(0.79f, 0.50f);
    glVertex2f(0.79f, 0.90f);
    glVertex2f(0.77f, 0.90f);
    glEnd();
glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.50f);
    glVertex2f(0.85f, 0.50f);
    glVertex2f(0.85f, 0.550f);
    glVertex2f(0.7f, 0.550f);
    glEnd();
glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.560f);
    glVertex2f(0.85f, 0.560f);
    glVertex2f(0.85f, 0.60f);
    glVertex2f(0.7f, 0.600f);
    glEnd();
glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.620f);
    glVertex2f(0.85f, 0.620f);
    glVertex2f(0.85f, 0.670f);
    glVertex2f(0.7f, 0.67f);
    glEnd();
glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.690f);
    glVertex2f(0.85f, 0.690f);
    glVertex2f(0.85f, 0.740f);
    glVertex2f(0.7f, 0.74f);
    glEnd();
glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.760f);
    glVertex2f(0.85f, 0.760f);
    glVertex2f(0.85f, 0.810f);
    glVertex2f(0.7f, 0.810f);
    glEnd();

glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.830f);
    glVertex2f(0.85f, 0.830f);
    glVertex2f(0.85f, 0.880f);
    glVertex2f(0.7f, 0.88f);
    glEnd();







    glBegin(GL_QUADS);
     glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.85f, 0.50f);
    glVertex2f(0.9f, 0.50f);
    glVertex2f(0.9f, 0.88f);
    glVertex2f(0.85f, 0.90f);
    glEnd();


}
        void river4()                              ///OID-9
{
    ///river
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.8f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(-1.0f, 0.4f);
    glEnd();

    ///bank river
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-1.0,0.4);
    glVertex2f(1.0, 0.4);
    glEnd();
}
float move_flow = 0.0f;
float move_speed_boat =1.0f;
float speedboat_speed =0.5f;

void flow7()                                  ///OID-10
{
    float x=0.1,y=0.1;
    ///flow
    glPushMatrix();
    glTranslatef(move_flow, 0.0f, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5,0.3);
    glVertex2f(0.6, 0.3);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x,0.3-x);
    glVertex2f(0.6-x, 0.3-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x,0.3-x-x);
    glVertex2f(0.6-x-x, 0.3-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x, 0.3-x-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x,0.3-x-x-x+0.05);
    glVertex2f(0.6-x-x-x-2*x, 0.3-x-x-x+0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x,0.3-x-x-x+0.15);
    glVertex2f(0.6-x-x-x-2*x-2*x, 0.3-x-x-x+0.15);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x,0.3-x-x-x+0.25);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x, 0.3-x-x-x+0.25);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.35);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.35);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.25);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.25);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.35);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.35);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-0.12,0.3-x-x-x+0.15);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-0.12, 0.3-x-x-x+0.15);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x-0.05);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x-0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x,0.3-x-x-x+0.1);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x, 0.3-x-x-x+0.1);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x+x,0.3-x-x-x-0.08);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x+x, 0.3-x-x-x-0.08);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x+2*x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x+2*x, 0.3-x-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x-2*x-2*x, 0.3-x-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17,0.3);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17, 0.3);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17+2*x,0.3+0.06);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17+2*x, 0.3+0.06);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17+2*x,0.2);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17+2*x, 0.2);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x,0.2);
    glVertex2f(0.6-x,0.2);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x,0.1);
    glVertex2f(0.6-x+2*x,0.1);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x,0.1+y);
    glVertex2f(0.6-x+2*x+x,0.1+y);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x+x,0.1+y+y);
    glVertex2f(0.6-x+2*x+x+x,0.1+y+y);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x+x,0.0);
    glVertex2f(0.6-x+2*x+x+x,0.0);
    glEnd();
    glPopMatrix();
}



void speed_boat()                           ///OID-14
{
    ///SpeedBoat
    float I = 60.0;
    ///deck
    glColor3ub(0,0,128);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.0055,0.0020,0);
    glTranslatef(move_speed_boat, 0.0f, 0.0f);//for move
    glBegin(GL_QUADS);
    glVertex2f(135.0f, -44.0f+I);
    glVertex2f(167.0f, -60.0f+I);
    glVertex2f(164.0f, -30.0f+I);
    glVertex2f(140.0f, -10.0f+I);
    glEnd();

    ///windows
    glColor3ub(72,209,204);
    glBegin(GL_QUADS);
    glVertex2f(137.0f, -39.0f+I);
    glVertex2f(165.0f, -51.0f+I);
    glVertex2f(163.0f, -34.0f+I);
    glVertex2f(141.0f, -15.0f+I);
    glEnd();

//window line

    glColor3ub(0,0,128);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
    glVertex2f(145.0f, -52.0f+I);
    glVertex2f(145.0f, -16.0f+I);

    glVertex2f(151.0f, -52.0f+I);
    glVertex2f(151.0f, -19.0f+I);

    glVertex2f(157.0f, -52.0f+I);
    glVertex2f(157.0f, -25.5f+I);
    glEnd();
//middle body
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(132.0f, -85.0f+I);
    glVertex2f(173.0f, -85.0f+I);
    glVertex2f(177.0f, -60.0f+I);
    glVertex2f(123.0f, -38.0f+I);
    glEnd();

    ///bottom body
    glColor3ub(0,0,128);
    glBegin(GL_QUADS);
    glVertex2f(135.0f, -105.0f+I);
    glVertex2f(170.0f, -105.0f+I);
    glVertex2f(173.0f, -85.0f+I);
    glVertex2f(130.0f, -76.0f+I);
    glEnd();
    glPopMatrix();
    glLoadIdentity();
}

void update_speed_boat(int value)               ///AFID-3
{
    move_speed_boat -= speedboat_speed;
    if(move_speed_boat<-360)
    {
        move_speed_boat =70;
    }
    glutPostRedisplay();
    glutTimerFunc(8, update_speed_boat, 0);
}

float ambulance_position=0;
float ambulance_speed=0.01;
float police_car_position=0;
float police_car_speed=0.01;
float suv_car_position = 0;
float suv_car_speed=0.01;
float car_position = 0;
float car_speed=0.01;
float truck_position= 0;
float truck_speed= 0.01;
float jeep_position = 0.0f;  // initial position
float jeep_speed =0.01f;


void car5()
{ glPushMatrix();
    glTranslatef(jeep_position, -0.1, 0); // independent movement
    glRotatef(0, 0, 1, 0);

    /// Car body (bright yellow, low profile)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.84f, 0.0f); // Lamborghini yellow
    glVertex2f(-0.7f, -0.35f);   // rear bottom
    glVertex2f(-0.65f, -0.25f);  // rear slope
    glVertex2f(-0.45f, -0.20f);  // roof line
    glVertex2f(-0.25f, -0.25f);  // front top
    glVertex2f(-0.2f, -0.35f);   // front bottom
    glEnd();

    /// Windshield (black glass)
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(-0.55f, -0.20f);
    glVertex2f(-0.45f, -0.20f);
    glVertex2f(-0.40f, -0.25f);
    glVertex2f(-0.58f, -0.25f);
    glEnd();
 /// Headlights (sharp white)
  /*  glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.8f);
    glVertex2f(-0.25f, -0.25f);
    glVertex2f(-0.20f, -0.25f);
    glVertex2f(-0.20f, -0.30f);
    glVertex2f(-0.27f, -0.30f);
    glEnd();
*/
    /// Wheels (bigger + stylish rim)
    float wheelCX[2] = {-0.6f, -0.3f};
    for(int w=0; w<2; w++)
    {
        float cx = wheelCX[w];
        float cy = -0.38f;

        // Tire (black)
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416f;
            float A=(i*2*pi)/200;
            float r=0.08f;
            float x=r*cos(A)+cx;
            float y=r*sin(A)+cy;
            glColor3f(0.05f,0.05f,0.05f);
            glVertex2f(x,y);
        }
        glEnd();

        // Rim (silver)
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416f;
            float A=(i*2*pi)/200;
            float r=0.04f;
            float x=r*cos(A)+cx;
            float y=r*sin(A)+cy;
            glColor3f(0.7f,0.7f,0.7f);
            glVertex2f(x,y);
        }
        glEnd();
    }

    glPopMatrix();
    glLoadIdentity();

}



void updateVehicals2(int value)                  ///AFID-7
{
if (public_bus_position>=2.5)
    {
        public_bus_position=-1;
    }
    public_bus_position+=public_bus_speed;
    if (r_l_train_position>=2.5)
    {
        r_l_train_position=-1;
    }
    r_l_train_position+=r_l_train_speed;
if (l_r_train_position>=2.5)
    {
        l_r_train_position=-1;
    }
    l_r_train_position+=l_r_train_speed;
    if (ambulance_position>=2.5)
    {
        ambulance_position=-1;
    }
    ambulance_position+=ambulance_speed;

    if (police_car_position>=2.5)
    {
        police_car_position=-1;
    }
    police_car_position+=police_car_speed;
/*
    if (suv_car_position>=3.5)
    {
        suv_car_position=-0.2;
    }
    suv_car_position+=suv_car_speed;

    if (car_position>=3.5)
    {
        car_position=-1.2;
    }
    car_position+=car_speed;

    */
    if (truck_position >= 2.5)
{
    truck_position = -1;   // reset to start from left
}
    truck_position += truck_speed;

    if (jeep_position >= 2.5)  // when jeep goes past the right edge
{
    jeep_position = -1;     // reset to the left
}
    jeep_position += jeep_speed;

    glutPostRedisplay();
    glutTimerFunc(30, updateVehicals2, 0);

}


void footpath()                             ///OID-17
{
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 0.5f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(-1.0f, -0.1f);
    glEnd();


}


void tree65()                                 ///OID-18
{
    ///tree1
    float t = 0.5;
    glScalef(1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, 0.4f-t);
    glVertex2f(0.064f, 0.4f-t);
    glVertex2f(0.064f, 0.53f-t);
    glVertex2f(0.048f, 0.53f-t);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.47f-t);
    glVertex2f(0.081f,0.47f-t);
    glVertex2f(0.06f,0.68f-t);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.48f-t);
    glVertex2f(0.082f,0.48f-t);
    glVertex2f(0.07f,0.64f-t);
    glEnd();

    glLoadIdentity();

    ///tree2
    glPushMatrix();
    glScalef(-1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, 0.4f-t);
    glVertex2f(0.064f, 0.4f-t);
    glVertex2f(0.064f, 0.53f-t);
    glVertex2f(0.048f, 0.53f-t);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.47f-t);
    glVertex2f(0.081f,0.47f-t);
    glVertex2f(0.06f,0.68f-t);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.48f-t);
    glVertex2f(0.082f,0.48f-t);
    glVertex2f(0.07f,0.64f-t);
    glEnd();

    glLoadIdentity();

    ///tree3
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(-0.6f,-0.15f);
    glVertex2f(-0.624f,-0.15f);
    glVertex2f(-0.624f,0.08f);
    glVertex2f(-0.6f,0.08f);
    glEnd();

    circle(0.04,-0.645,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.04,-0.58,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.06,-0.61,0.2,0.0,1.0,0.2);
    glEnd();

    circle(0.04,-0.67,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,-0.56,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,-0.615,0.1,0.0, 0.6, 0.0);
    glEnd();

    ///tree4
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.6f,-0.15f);
    glVertex2f(0.624f,-0.15f);
    glVertex2f(0.624f,0.08f);
    glVertex2f(0.6f,0.08f);
    glEnd();

    circle(0.04,0.645,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.04,0.58,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.06,0.61,0.2,0.0,1.0,0.2);
    glEnd();

    circle(0.04,0.67,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,0.56,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,0.615,0.1,0.0, 0.6, 0.0);
    glEnd();


}



void bench()                                ///OID-19
{
    float B = 115.0;
    float b = 50.0;

    ///bench2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.005,0.005,0);
    ///left leg
    glColor3ub(0,0,0);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(41.0f+b,80.0f-B);
    glVertex2f(41.0f+b,92.0f-B);
    glEnd();
    ///right leg
    glColor3ub(0,0,0);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(57.0f+b,80.0f-B);
    glVertex2f(57.0f+b,92.0f-B);
    glEnd();
    ///upper part
    glColor3f(0.3f, 0.3f, 0.0f);
    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glVertex2f(40.0f+b,92.0f-B);
    glVertex2f(58.0f+b,92.0f-B);
    glEnd();
    glLoadIdentity();

    ///bench2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(-0.005,0.005,0);
    ///left leg
    glColor3ub(0,0,0);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(41.0f+b,80.0f-B);
    glVertex2f(41.0f+b,92.0f-B);
    glEnd();
    ///right leg
    glColor3ub(0,0,0);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(57.0f+b,80.0f-B);
    glVertex2f(57.0f+b,92.0f-B);
    glEnd();
    ///upper part
    glColor3f(0.3f, 0.3f, 0.0f);
    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glVertex2f(40.0f+b,92.0f-B);
    glVertex2f(58.0f+b,92.0f-B);
    glEnd();
    glLoadIdentity();
}


void fence23()                            ///OID-15
{
    float L = 0.05;
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.95f,-0.01f);
    glVertex2f(-0.95f,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.9f,-0.01f);
    glVertex2f(-0.9f,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f,-0.01f);
    glVertex2f(-0.85f,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+L,-0.01f);
    glVertex2f(-0.85f+L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+2*L,-0.01f);
    glVertex2f(-0.85f+2*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+3*L,-0.01f);
    glVertex2f(-0.85f+3*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+4*L,-0.01f);
    glVertex2f(-0.85f+4*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+5*L,-0.01f);
    glVertex2f(-0.85f+5*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+6*L,-0.01f);
    glVertex2f(-0.85f+6*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+7*L,-0.01f);
    glVertex2f(-0.85f+7*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+8*L,-0.01f);
    glVertex2f(-0.85f+8*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+9*L,-0.01f);
    glVertex2f(-0.85f+9*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+10*L,-0.01f);
    glVertex2f(-0.85f+10*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+11*L,-0.01f);
    glVertex2f(-0.85f+11*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+12*L,-0.01f);
    glVertex2f(-0.85f+12*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+13*L,-0.01f);
    glVertex2f(-0.85f+13*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+14*L,-0.01f);
    glVertex2f(-0.85f+14*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+15*L,-0.01f);
    glVertex2f(-0.85f+15*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+16*L,-0.01f);
    glVertex2f(-0.85f+16*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+17*L,-0.01f);
    glVertex2f(-0.85f+17*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+18*L,-0.01f);
    glVertex2f(-0.85f+18*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+19*L,-0.01f);
    glVertex2f(-0.85f+19*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+20*L,-0.01f);
    glVertex2f(-0.85f+20*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+21*L,-0.01f);
    glVertex2f(-0.85f+21*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+22*L,-0.01f);
    glVertex2f(-0.85f+22*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+23*L,-0.01f);
    glVertex2f(-0.85f+23*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+24*L,-0.01f);
    glVertex2f(-0.85f+24*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+25*L,-0.01f);
    glVertex2f(-0.85f+25*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+26*L,-0.01f);
    glVertex2f(-0.85f+26*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+27*L,-0.01f);
    glVertex2f(-0.85f+27*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+28*L,-0.01f);
    glVertex2f(-0.85f+28*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+29*L,-0.01f);
    glVertex2f(-0.85f+29*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+30*L,-0.01f);
    glVertex2f(-0.85f+30*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+31*L,-0.01f);
    glVertex2f(-0.85f+31*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+32*L,-0.01f);
    glVertex2f(-0.85f+32*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+33*L,-0.01f);
    glVertex2f(-0.85f+33*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+34*L,-0.01f);
    glVertex2f(-0.85f+34*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+35*L,-0.01f);
    glVertex2f(-0.85f+35*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+36*L,-0.01f);
    glVertex2f(-0.85f+36*L,-0.1f);
    glEnd();

    glColor3ub(57,43,23);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(-1.0,-0.01f);
    glVertex2f(1.0f,-0.01f);
    glEnd();

}
void ambulance()                            ///OID-22
{
    /// ambulance
    glPushMatrix();
    glRotatef(0,0,1,0);
    glTranslatef(ambulance_position-0.6,-0.0,0);
    glBegin(GL_QUADS);/// white ambulance down body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.7f, -0.35f);
    glVertex2f(-0.7f, -0.45f);
    glVertex2f(-0.35f, -0.45f);
    glVertex2f(-0.36f, -0.35f);
    glEnd();

    glBegin(GL_QUADS);/// yellow quads
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(-0.39f, -0.35f);
    glVertex2f(-0.39f, -0.37f);
    glVertex2f(-0.357f, -0.37f);
    glVertex2f(-0.36f, -0.35f);
    glEnd();

    glBegin(GL_QUADS);/// black ambulance start
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(-0.71f, -0.43f);
    glVertex2f(-0.71f, -0.45f);
    glVertex2f(-0.69f, -0.45f);
    glVertex2f(-0.69f, -0.43f);
    glEnd();

    glBegin(GL_QUADS);/// black ambulance end
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(-0.36f, -0.43f);
    glVertex2f(-0.36f, -0.45f);
    glVertex2f(-0.34f, -0.45f);
    glVertex2f(-0.34f, -0.43f);
    glEnd();

    glBegin(GL_QUADS);    ///ambulance middle line
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.343f);
    glVertex2f(-0.7f, -0.35f);
    glVertex2f(-0.36f, -0.35f);
    glVertex2f(-0.363f, -0.343f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance middle body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.7f, -0.31f);
    glVertex2f(-0.7f, -0.343f);
    glVertex2f(-0.363f, -0.343f);
    glVertex2f(-0.39f, -0.31f);
    glEnd();

    glBegin(GL_QUADS);    ///ambulance middle body end
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.31f);
    glVertex2f(-0.7f, -0.343f);
    glVertex2f(-0.69f, -0.343f);
    glVertex2f(-0.69f, -0.31f);
    glEnd();



    glBegin(GL_QUADS);/// white ambulance up body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.65f, -0.17f);
    glVertex2f(-0.7f, -0.31f);
    glVertex2f(-0.39f, -0.31f);
    glVertex2f(-0.43f, -0.17f);
    glEnd();


    glBegin(GL_QUADS);   ///ambulance up body alarm
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.55f, -0.15f);
    glVertex2f(-0.55f, -0.17f);
    glVertex2f(-0.53f, -0.17f);
    glVertex2f(-0.53f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body blue right quads
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(-0.49f, -0.19f);
    glVertex2f(-0.49f, -0.31f);
    glVertex2f(-0.41f, -0.31f);
    glVertex2f(-0.45f, -0.19f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body blue left quads
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(-0.57f, -0.19f);
    glVertex2f(-0.57f, -0.31f);
    glVertex2f(-0.5f, -0.31f);
    glVertex2f(-0.5f, -0.19f);
    glEnd();


    glBegin(GL_QUADS);/// ambulance up body red
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.65f, -0.24f);
    glVertex2f(-0.65f, -0.26f);
    glVertex2f(-0.58f, -0.26f);
    glVertex2f(-0.58f, -0.24f);
    glEnd();

    glBegin(GL_QUADS);///  ambulance up body red
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.62f, -0.19f);
    glVertex2f(-0.62f, -0.31f);
    glVertex2f(-0.61f, -0.31f);
    glVertex2f(-0.61f, -0.19f);
    glEnd();

    ///Wheel
    glScalef(0.2,0.2,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-3.05,y-2.2);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-3.05,y-2.2);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-2.2,y-2.2);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-2.2,y-2.2);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glLoadIdentity();
}

void policeCar()                                ///OID-25
{
    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(police_car_position-0.8,0,0);
    glScalef(-1,1,0);
    ///police car
    glBegin(GL_QUADS);/// white policeCar down body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.37f, -0.77f);
    glVertex2f(0.35f, -0.89f);
    glVertex2f(0.7f, -0.89f);
    glVertex2f(0.69f, -0.77f);
    glEnd();

    glBegin(GL_QUADS);/// black policeCar down start line
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(0.34f, -0.87f);
    glVertex2f(0.34f, -0.89f);
    glVertex2f(0.37f, -0.89f);
    glVertex2f(0.37f, -0.87f);
    glEnd();

    glBegin(GL_QUADS);/// black policeCar down end line
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(0.68f, -0.87f);
    glVertex2f(0.68f, -0.89f);
    glVertex2f(0.72f, -0.89f);
    glVertex2f(0.72f, -0.87f);
    glEnd();

    glBegin(GL_QUADS);    ///policeCar middle line
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(0.366f, -0.79f);
    glVertex2f(0.363f, -0.81f);
    glVertex2f(0.39f, -0.81f);
    glVertex2f(0.39f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);/// blue policeCar middle line
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(0.4f, -0.79f);
    glVertex2f(0.4f, -0.81f);
    glVertex2f(0.66f, -0.81f);
    glVertex2f(0.66f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);   ///policeCar middle line
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.67f, -0.79f);
    glVertex2f(0.67f, -0.81f);
    glVertex2f(0.695f, -0.81f);
    glVertex2f(0.693f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);/// white policeCar up body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.46f, -0.7f);
    glVertex2f(0.41f, -0.77f);
    glVertex2f(0.65f, -0.77f);
    glVertex2f(0.62f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);/// cyan policeCar up body
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0.465f, -0.715f);
    glVertex2f(0.42f, -0.77f);
    glVertex2f(0.52f, -0.77f);
    glVertex2f(0.52f, -0.715f);
    glEnd();

    glBegin(GL_QUADS);/// cyan policeCar up body
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0.53f, -0.715f);
    glVertex2f(0.53f, -0.77f);
    glVertex2f(0.64f, -0.77f);
    glVertex2f(0.615f, -0.715f);
    glEnd();

    glBegin(GL_QUADS);  ///policeCar upper light
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.475f, -0.68f);
    glVertex2f(0.475f, -0.7f);
    glVertex2f(0.49f, -0.7f);
    glVertex2f(0.49f, -0.68f);
    glEnd();

    glBegin(GL_QUADS);/// blue policeCar upper light
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(0.49f, -0.68f);
    glVertex2f(0.49f, -0.7f);
    glVertex2f(0.505f, -0.7f);
    glVertex2f(0.505f, -0.68f);
    glEnd();

    glBegin(GL_QUADS);  ///policeCar upper light
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.505f, -0.68f);
    glVertex2f(0.505f, -0.7f);
    glVertex2f(0.52f, -0.7f);
    glVertex2f(0.52f, -0.68f);
    glEnd();

    ///Wheel
    glScalef(0.2,0.2,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.03,y-4.45);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.03,y-4.45);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.23,y-4.45);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.23,y-4.45);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glLoadIdentity();
}
void sky5()
{
    ///sky
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}

void road10()
{
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(-1.0f, -0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-1.0f, -0.35f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-1.0f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-1.0f, -0.35f);
    glVertex2f(-0.80f, -0.35f);
    glVertex2f(-0.80f, -0.3f);
    glVertex2f(-1.0f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.60f, -0.35f);
    glVertex2f(-0.40f, -0.35f);
    glVertex2f(-0.40f, -0.3f);
    glVertex2f(-0.60f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.20f, -0.35f);
    glVertex2f(0.00f, -0.35f);
    glVertex2f(0.00f, -0.3f);
    glVertex2f(-0.20f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.20f, -0.35f);
    glVertex2f(0.40f, -0.35f);
    glVertex2f(0.40f, -0.3f);
    glVertex2f(0.20f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.60f, -0.35f);
    glVertex2f(0.80f, -0.35f);
    glVertex2f(0.80f, -0.3f);
    glVertex2f(0.60f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-1.0f, -0.67f);
    glVertex2f(-0.80f, -0.67f);
    glVertex2f(-0.80f, -0.7f);
    glVertex2f(-1.0f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.60f, -0.67f);
    glVertex2f(-0.40f, -0.67f);
    glVertex2f(-0.40f, -0.7f);
    glVertex2f(-0.60f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.20f, -0.67f);
    glVertex2f(0.00f, -0.67f);
    glVertex2f(0.00f, -0.7f);
    glVertex2f(-0.20f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(0.20f, -0.67f);
    glVertex2f(0.40f, -0.67f);
    glVertex2f(0.40f, -0.7f);
    glVertex2f(0.20f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(0.60f, -0.67f);
    glVertex2f(0.80f, -0.67f);
    glVertex2f(0.80f, -0.7f);
    glVertex2f(0.60f, -0.7f);
    glEnd();

}

void lamp_post()                              ///OID-20
{
    float ww = 100;
    ///lamp1
    ///pillar
    float L = 140.0;
    float l = 40.0;
    glScalef(0.005,0.005,0);
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f,80.0f-L);
    glVertex2f(62.0f,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f,160.0f-L);
    glVertex2f(54.0f,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f,158.0f-L);
    glVertex2f(57.0f,158.0f-L);
    glEnd();

    ///lamp2
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-l,80.0f-L);
    glVertex2f(62.0f-l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-l,160.0f-L);
    glVertex2f(54.0f-l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-l,158.0f-L);
    glVertex2f(57.0f-l,158.0f-L);
    glEnd();

    ///lamp3
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-2*l,80.0f-L);
    glVertex2f(62.0f-2*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-2*l,160.0f-L);
    glVertex2f(54.0f-2*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-2*l,158.0f-L);
    glVertex2f(57.0f-2*l,158.0f-L);
    glEnd();

    ///lamp4
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-3*l,80.0f-L);
    glVertex2f(62.0f-3*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-3*l,160.0f-L);
    glVertex2f(54.0f-3*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-3*l,158.0f-L);
    glVertex2f(57.0f-3*l,158.0f-L);
    glEnd();

    ///lamp5
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-4*l,80.0f-L);
    glVertex2f(62.0f-4*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-4*l,160.0f-L);
    glVertex2f(54.0f-4*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-4*l,158.0f-L);
    glVertex2f(57.0f-4*l,158.0f-L);
    glEnd();

    ///lamp6
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-5*l,80.0f-L);
    glVertex2f(62.0f-5*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-5*l,160.0f-L);
    glVertex2f(54.0f-5*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-5*l,158.0f-L);
    glVertex2f(57.0f-5*l,158.0f-L);
    glEnd();

    ///lamp7
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-6*l,80.0f-L);
    glVertex2f(62.0f-6*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-6*l,160.0f-L);
    glVertex2f(54.0f-6*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-6*l,158.0f-L);
    glVertex2f(57.0f-6*l,158.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-5*l,158.0f-L);
    glVertex2f(57.0f-5*l,158.0f-L);
    glEnd();

    ///lamp8
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+l,80.0f-L);
    glVertex2f(62.0f+l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+l,160.0f-L);
    glVertex2f(54.0f+l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f+l,158.0f-L);
    glVertex2f(57.0f+l,158.0f-L);
    glEnd();

    ///lamp9
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+2*l,80.0f-L);
    glVertex2f(62.0f+2*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+2*l,160.0f-L);
    glVertex2f(54.0f+2*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f+2*l,158.0f-L);
    glVertex2f(57.0f+2*l,158.0f-L);
    glEnd();

    ///lamp10
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+3*l,80.0f-L);
    glVertex2f(62.0f+3*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+3*l,160.0f-L);
    glVertex2f(54.0f+3*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f+3*l,158.0f-L);
    glVertex2f(57.0f+3*l,158.0f-L);
    glEnd();

    glLoadIdentity();

}

void truck()
{
    glPushMatrix();
    glTranslatef(truck_position+0.4, -1.25, 0); // truck moves like before

    //////////////////////////// Cargo body (bigger)
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.7f);  // dark blue
    glVertex2f(-0.95f, 0.45f);
    glVertex2f(-0.55f, 0.45f);
    glVertex2f(-0.55f, 0.65f);   // higher top
    glVertex2f(-0.95f, 0.65f);
    glEnd();

    // Text on cargo box
   // drawText("CITY TRANSPORT", -0.90f, 0.56f, 1.0f, 1.0f, 1.0f); // white text

    //////////////////////////// Cabin (slanted)
    glBegin(GL_POLYGON);
    glColor3f(0.85f, 0.2f, 0.1f);  // red
    glVertex2f(-0.55f, 0.45f);
    glVertex2f(-0.42f, 0.45f);
    glVertex2f(-0.38f, 0.52f);  // slant
    glVertex2f(-0.42f, 0.62f);
    glVertex2f(-0.55f, 0.62f);
    glEnd();

    //////////////////////////// Window (angled glass look)
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 0.1f);  // black glass
    glVertex2f(-0.52f, 0.48f);
    glVertex2f(-0.43f, 0.48f);
    glVertex2f(-0.40f, 0.56f);
    glVertex2f(-0.52f, 0.56f);
    glEnd();

    // Glass shine effect
    glBegin(GL_LINES);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.51f, 0.49f);
    glVertex2f(-0.41f, 0.55f);
    glEnd();

    //////////////////////////// Wheels
    bus_wheel_circle(-0.88f, 0.45f, 0.045f, 0, 0, 0); // rear
    bus_wheel_circle(-0.70f, 0.45f, 0.045f, 0, 0, 0); // middle
    bus_wheel_circle(-0.46f, 0.45f, 0.05f, 0, 0, 0);  // front

    // wheel rims
    bus_wheel_circle(-0.88f, 0.45f, 0.022f, 0.6f, 0.6f, 0.6f);
    bus_wheel_circle(-0.70f, 0.45f, 0.022f, 0.6f, 0.6f, 0.6f);
    bus_wheel_circle(-0.46f, 0.45f, 0.025f, 0.6f, 0.6f, 0.6f);

    //////////////////////////// Headlight
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.3f);
    glVertex2f(-0.40f, 0.52f);
    glVertex2f(-0.38f, 0.52f);
    glVertex2f(-0.38f, 0.56f);
    glVertex2f(-0.40f, 0.56f);
    glEnd();

    //////////////////////////// Exhaust pipe
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.52f, 0.62f);
    glVertex2f(-0.50f, 0.62f);
    glVertex2f(-0.50f, 0.70f);
    glVertex2f(-0.52f, 0.70f);
    glEnd();

    glPopMatrix();
    glLoadIdentity();
}



void day_Display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    lamp_post();
    sky5();
    buildings();
    buildings1();
    r_l_train();
    l_r_train();
    Wire11();
    bridge_wirepillar();
    bridge();
    road_border6();
    p_fence() ;
    pillar();
    road1();
    public_bus();
    road_marking();
    river4();
    flow7();
    speed_boat();
    fence23();
    road10();
    footpath();
    tree65();
    bench();
    ambulance();
    truck();
    car5();
    //policeCar();
//


    glFlush();  /// Render now
}

///--------------------------------------------------------------smart city end-------------------------------------------------------------------------///


void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            isSnow=false;
        glutDisplayFunc(Display);
        PlaySound("ship.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;
        case '2':
            glutDisplayFunc(displayD);
            PlaySound(TEXT("sunny"), NULL, SND_ASYNC);
            break;
        case '3':
        glutDisplayFunc(day_Display);
        PlaySound(NULL, 0, 0);
        break;
        case 'm':
            glutDisplayFunc(displayR);
            PlaySound(TEXT("rainy2"), NULL, SND_ASYNC);
            break;
        case 'n':
            glutDisplayFunc(displayN);
            PlaySound(TEXT("night2"), NULL, SND_ASYNC);
            glutPostRedisplay();
            break;
        case 'r':
            redLightOn = true;
            greenLightOn = false;
            vehiclesRunning = false;
            break;
        case 'g':
            redLightOn = false;
            greenLightOn = true;
            vehiclesRunning = true;
            break;
        case 's':
            if(isSnow)
            {
                glutDisplayFunc(Display);
                isSnow=false;
                PlaySound(NULL, 0, 0);
                PlaySound("ship.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
            }
            else
            {
                glutDisplayFunc(DisplayS);
                isSnow=true;
                PlaySound("snow.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
            }
            break;
        case 'a':
            PlaySound("ambulance.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    }
    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y)       ///AFID-10
{
    if (button == GLUT_LEFT_BUTTON)
    {
        suv_car_speed+=0.0051;
        car_speed+=0.0051;
        container_ship_speed+=0.05f;
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        suv_car_speed-=0.0051;
        car_speed-=0.0051;
        container_ship_speed-=0.05f;
    }
    glutPostRedisplay();
}






int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0,0);
    glutCreateWindow("");
    //gluOrtho2D(-z,1920,0,1080);
    //gluOrtho2D(0,1920,0,1080);


    glutDisplayFunc(Intro);
    glutTimerFunc(20, update, 0);
    glutTimerFunc(30, updateVehicals, 0);
    glutTimerFunc(80, update_cloud, 0);
    glutTimerFunc(150, updateHuman, 0);
    glutTimerFunc(60, weather_update, 0);
    glutTimerFunc(20, update_ship, 0);


    ///
    glutTimerFunc(100, cloud, 0);
    glutTimerFunc(100, sunn, 0);
    glutTimerFunc(100, boat, 0);
    glutTimerFunc(100, rain, 0);
    glutTimerFunc(100, birdd, 0);
    glutTimerFunc(60, update_rain, 0);

    ///
    glutTimerFunc(10, update_speed_boat, 0);
    glutTimerFunc(60, updateVehicals2, 0);


    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);




    glutMainLoop();
    return 0;
}
