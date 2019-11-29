#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
# define PI  3.14159265358979323846

GLfloat car_position1 = 0.0f;
GLfloat car_speed1 = 0.03f;
GLfloat car_position2 = 0.0f;
GLfloat car_speed2 = 0.03f;
GLfloat car_position3 = 0.0f;
GLfloat car_speed3 = 0.03f;
GLfloat car_position4 = 0.0f;
GLfloat car_speed4 = 0.03f;
GLfloat sun_position = 0.0f;
GLfloat sun_speed = 0.02f;
GLfloat plane_position = 0.0f;
GLfloat plane_speed = 0.05f;
GLfloat bird_position = 0.0f;
GLfloat bird_speed = 0.01f;
GLfloat cloud_position = 0.0f;
GLfloat cloud_speed = 0.01f;
GLfloat moon_position = 0.0f;
GLfloat moon_speed = 0.02f;
GLfloat rain_position = 0.0f;
GLfloat rain_speed = 0.05f;

void city_day();
void city_night();
void left_right_traffic_day();
void day_rain();
void night_rain();
void city_day1(int val);
void city_night1(int val);
void day_rain1(int val);
void night_rain1(int val);

void update1(int value){
    if(car_position1 > 1.5)
        car_position1 = -1.0;
    car_position1 += car_speed1;
        glutPostRedisplay();
        glutTimerFunc(100, update1, 0);
}

void update2(int value){
    if(car_position2 < -1.5)
        car_position2 = 1.0;
    car_position2 -= car_speed2;
        glutPostRedisplay();
        glutTimerFunc(100, update2, 0);
}

void update3(int value){
    if(sun_position < -1.0)
        sun_position = 0.1;
    sun_position -= sun_speed;
        glutPostRedisplay();
        glutTimerFunc(100, update3, 0);
}

void update4(int value){
    if(plane_position > 1.5)
        plane_position = -1.0;
    plane_position += plane_speed;
        glutPostRedisplay();
        glutTimerFunc(100, update4, 0);
}

void update5(int value){
    if(bird_position > 1.5)
        bird_position = -1.0;
    bird_position += bird_speed;
        glutPostRedisplay();
        glutTimerFunc(100, update5, 0);
}

void update6(int value){
    if(cloud_position < -1.5)
        cloud_position = 1.0;
    cloud_position -= cloud_speed;
        glutPostRedisplay();
        glutTimerFunc(100, update6, 0);
}

void update7(int value){
    if(car_position3 < -0.8)
        car_position3 = 0.35;
    car_position3 -= car_speed3;
        glutPostRedisplay();
        glutTimerFunc(100, update7, 0);
}

void update8(int value){
    if(car_position4 > 0.85)
        car_position4 = -0.3;
    car_position4 += car_speed4;
        glutPostRedisplay();
        glutTimerFunc(100, update8, 0);
}

void update9(int value){
    if(moon_position > 1.1)
        moon_position = 0.0;
    moon_position += moon_speed;
        glutPostRedisplay();
        glutTimerFunc(100, update9, 0);
}

void update10(int value){
    if(rain_position < -0.1)
        rain_position = 0.0;
    rain_position -= rain_speed;
        glutPostRedisplay();
        glutTimerFunc(100, update10, 0);
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void city_day(){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);// Clear the color buffer (background)
    glLoadIdentity();//Reset the current matrix

    glBegin(GL_QUADS);
    glColor3ub(16, 214, 232);      //sky
	glVertex2f(-1, 0.2);
	glVertex2f(1, 0.2);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(249, 215, 28);      //star
	glVertex2f(0.2, -0.65);
	glVertex2f(0.5, -0.65);
	glVertex2f(0.5, -0.62);
	glVertex2f(0.46, -0.61);
	glVertex2f(0.4, -0.56);
	glVertex2f(0.3, -0.56);
	glVertex2f(0.27, -0.6);
	glVertex2f(0.2, -0.63);
    glEnd();

    glLoadIdentity();
    glPushMatrix();
	glTranslatef(0.0f, sun_position, 0.0f);
    int i;                                      //sun
    GLfloat x=-0.5f; GLfloat y=1.13f; GLfloat radius =.13f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(249, 215, 28);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount; i++) {
			glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glPopMatrix();

    glLoadIdentity();
    glPushMatrix();
	glTranslatef(plane_position, 0.0f, 0.0f);
    glBegin(GL_QUADS);              //plane up wing
	glColor3ub(53, 143, 112);
	glVertex2f(-0.6, 0.65);
	glVertex2f(-0.5, 0.65);
	glVertex2f(-0.47, 0.75);
	glVertex2f(-0.5, 0.75);
	glEnd();

    glBegin(GL_POLYGON);            //plane body
	glColor3ub(67, 171, 136);
	glVertex2f(-0.8, 0.6);
	glVertex2f(-0.73, 0.55);
	glVertex2f(-0.4, 0.55);
	glVertex2f(-0.4, 0.58);
	glVertex2f(-0.43, 0.63);
	glVertex2f(-0.5, 0.68);
	glVertex2f(-0.72, 0.68);
	glEnd();

    glBegin(GL_QUADS);              //plane tail
	glColor3ub(53, 143, 112);
	glVertex2f(-0.8, 0.6);
	glVertex2f(-0.72, 0.68);
	glVertex2f(-0.79, 0.75);
	glVertex2f(-0.82, 0.75);
	glEnd();

    glBegin(GL_QUADS);              //plane down wing
	glColor3ub(53, 143, 112);
	glVertex2f(-0.75, 0.48);
	glVertex2f(-0.7, 0.48);
	glVertex2f(-0.5, 0.58);
	glVertex2f(-0.65, 0.58);
	glEnd();

    glBegin(GL_QUADS);              //plane front window
	glColor3ub(227, 227, 227);
	glVertex2f(-0.53, 0.63);
	glVertex2f(-0.43, 0.63);
	glVertex2f(-0.5, 0.68);
	glVertex2f(-0.53, 0.65);
	glEnd();

	glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.56, 0.63);
	glVertex2f(-0.58, 0.63);
	glVertex2f(-0.58, 0.66);
	glVertex2f(-0.56, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.56, 0.63);
	glVertex2f(-0.58, 0.63);
	glVertex2f(-0.58, 0.66);
	glVertex2f(-0.56, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.6, 0.63);
	glVertex2f(-0.62, 0.63);
	glVertex2f(-0.62, 0.66);
	glVertex2f(-0.6, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.64, 0.63);
	glVertex2f(-0.66, 0.63);
	glVertex2f(-0.66, 0.66);
	glVertex2f(-0.64, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.68, 0.63);
	glVertex2f(-0.7, 0.63);
	glVertex2f(-0.7, 0.66);
	glVertex2f(-0.68, 0.66);
    glEnd();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(bird_position, 0.0f, 0.0f);
    glBegin(GL_LINES);              //bird
    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.35, 0.45);
    glBegin(GL_LINES);
    glVertex2f(-0.35, 0.45);
    glVertex2f(-0.3, 0.5);
    glEnd();

    glBegin(GL_LINES);              //bird
    glVertex2f(-0.25, 0.5);
    glVertex2f(-0.2, 0.45);
    glBegin(GL_LINES);
    glVertex2f(-0.2, 0.45);
    glVertex2f(-0.15, 0.5);
    glEnd();
    glPopMatrix();

    glLoadIdentity();
    glPushMatrix();
	glTranslatef(cloud_position, 0.0f, 0.0f);
    int e;                          //cloud
    GLfloat x5=0.6f; GLfloat y5=0.85f; GLfloat radius5 =.05f;
	int triangleAmount5 = 20;
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x5, y5);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x5 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    GLfloat x6=0.66f; GLfloat y6=0.88f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x6, y6);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x6 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y6 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x7=0.66f; GLfloat y7=0.83f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x6, y6);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x7 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y7 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x8=0.73f; GLfloat y8=0.87f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x8, y8);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x8 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y8 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x9=0.72f; GLfloat y9=0.83f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x9, y9);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x9 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y9 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x10=-0.1f; GLfloat y10=0.88f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x10, y10);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x10 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y10 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x11=-0.05f; GLfloat y11=0.9f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x11, y11);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x11 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y11 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x12=-0.05f; GLfloat y12=0.85f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x12, y12);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x12 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y12 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x13=0.0f; GLfloat y13=0.85f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x13, y13);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x13 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y13 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();
	glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(82, 79, 78);      //background
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0.2);
	glVertex2f(-1, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //road
	glVertex2f(-1, -0.7);
	glVertex2f(1, -0.7);
	glVertex2f(1, -0.4);
	glVertex2f(-1, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //bottom road
	glVertex2f(-0.17, -1);
	glVertex2f(0.17, -1);
	glVertex2f(0.15, -0.7);
	glVertex2f(-0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //top road
	glVertex2f(-0.14, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(-0.1, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-1.1, -0.55);
	glVertex2f(-1, -0.55);
	glVertex2f(-0.95, -0.53);
	glVertex2f(-1.05, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.9, -0.55);
	glVertex2f(-0.8, -0.55);
	glVertex2f(-0.75, -0.53);
	glVertex2f(-0.85, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.7, -0.55);
	glVertex2f(-0.6, -0.55);
	glVertex2f(-0.55, -0.53);
	glVertex2f(-0.65, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.5, -0.55);
	glVertex2f(-0.4, -0.55);
	glVertex2f(-0.35, -0.53);
	glVertex2f(-0.45, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.3, -0.55);
	glVertex2f(-0.2, -0.55);
	glVertex2f(-0.15, -0.53);
	glVertex2f(-0.25, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.15, -0.55);
	glVertex2f(0.25, -0.55);
	glVertex2f(0.3, -0.53);
	glVertex2f(0.2, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.35, -0.55);
	glVertex2f(0.45, -0.55);
	glVertex2f(0.5, -0.53);
	glVertex2f(0.4, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.55, -0.55);
	glVertex2f(0.65, -0.55);
	glVertex2f(0.7, -0.53);
	glVertex2f(0.6, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.75, -0.55);
	glVertex2f(0.85, -0.55);
	glVertex2f(0.9, -0.53);
	glVertex2f(0.8, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.95, -0.55);
	glVertex2f(1, -0.55);
	glVertex2f(1, -0.53);
	glVertex2f(1, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //bottom divider
	glVertex2f(-0.01, -0.8);
	glVertex2f(0.01, -0.8);
	glVertex2f(0.01, -0.7);
	glVertex2f(-0.01, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //bottom divider
	glVertex2f(-0.01, -0.9);
	glVertex2f(0.01, -0.9);
	glVertex2f(0.01, -1);
	glVertex2f(-0.01, -1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, -0.4);
	glVertex2f(0.01, -0.4);
	glVertex2f(0.01, -0.3);
	glVertex2f(-0.01, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, -0.2);
	glVertex2f(0.01, -0.2);
	glVertex2f(0.01, -0.1);
	glVertex2f(-0.01, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, 0.0);
	glVertex2f(0.01, 0.0);
	glVertex2f(0.01, 0.1);
	glVertex2f(-0.01, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom left footpath
	glVertex2f(-1, -0.8);
	glVertex2f(-0.25, -0.8);
	glVertex2f(-0.25, -0.7);
	glVertex2f(-1, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom left footpath
	glVertex2f(-0.28, -1);
	glVertex2f(-0.17, -1);
	glVertex2f(-0.15, -0.7);
	glVertex2f(-0.25, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom right footpath
	glVertex2f(0.2, -0.8);
	glVertex2f(1, -0.8);
	glVertex2f(1, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom right footpath
	glVertex2f(0.17, -1);
	glVertex2f(0.28, -1);
	glVertex2f(0.25, -0.7);
	glVertex2f(0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top left footpath
	glVertex2f(-1, -0.4);
	glVertex2f(-0.2, -0.4);
	glVertex2f(-0.2, -0.3);
	glVertex2f(-1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top left footpath
	glVertex2f(-0.24, -0.4);
	glVertex2f(-0.14, -0.4);
	glVertex2f(-0.1, 0.2);
	glVertex2f(-0.19, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top right footpath
	glVertex2f(1, -0.4);
	glVertex2f(0.2, -0.4);
	glVertex2f(0.2, -0.3);
	glVertex2f(1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top right footpath
	glVertex2f(0.24, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(0.19, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 148, 146);      //1st building front
	glVertex2f(-0.95, -0.25);
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.95, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(39, 122, 121);      //1st building right
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.65, -0.2);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.7, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(68, 212, 209);      //1st building top
	glVertex2f(-0.95, 0.35);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.9, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.25);
	glVertex2f(-0.85, 0.25);
	glVertex2f(-0.85, 0.3);
	glVertex2f(-0.9, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.25);
	glVertex2f(-0.75, 0.25);
	glVertex2f(-0.75, 0.3);
	glVertex2f(-0.8, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.15);
	glVertex2f(-0.85, 0.15);
	glVertex2f(-0.85, 0.2);
	glVertex2f(-0.9, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.15);
	glVertex2f(-0.75, 0.15);
	glVertex2f(-0.75, 0.2);
	glVertex2f(-0.8, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.05);
	glVertex2f(-0.85, 0.05);
	glVertex2f(-0.85, 0.1);
	glVertex2f(-0.9, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.05);
	glVertex2f(-0.75, 0.05);
	glVertex2f(-0.75, 0.1);
	glVertex2f(-0.8, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.0);
	glVertex2f(-0.85, 0.0);
	glVertex2f(-0.85, -0.05);
	glVertex2f(-0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.0);
	glVertex2f(-0.75, 0.0);
	glVertex2f(-0.75, -0.05);
	glVertex2f(-0.8, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, -0.1);
	glVertex2f(-0.85, -0.1);
	glVertex2f(-0.85, -0.15);
	glVertex2f(-0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, -0.15);
	glVertex2f(-0.75, -0.15);
	glVertex2f(-0.75, -0.1);
	glVertex2f(-0.8, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building door
	glVertex2f(-0.85, -0.25);
	glVertex2f(-0.8, -0.25);
	glVertex2f(-0.8, -0.18);
	glVertex2f(-0.85, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(54, 145, 173);      //2nd building front
	glVertex2f(-0.63, -0.25);
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.63, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(41, 115, 138);      //2nd building right
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.28, -0.2);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.33, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(72, 189, 224);      //2nd building top
	glVertex2f(-0.63, 0.15);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.58, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, -0.15);
	glVertex2f(-0.51, -0.15);
	glVertex2f(-0.51, -0.1);
	glVertex2f(-0.58, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, -0.15);
	glVertex2f(-0.38, -0.15);
	glVertex2f(-0.38, -0.1);
	glVertex2f(-0.45, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, 0.0);
	glVertex2f(-0.51, 0.0);
	glVertex2f(-0.51, -0.05);
	glVertex2f(-0.58, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, 0.0);
	glVertex2f(-0.38, 0.0);
	glVertex2f(-0.38, -0.05);
	glVertex2f(-0.45, -0.05);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, 0.05);
	glVertex2f(-0.51, 0.05);
	glVertex2f(-0.51, 0.1);
	glVertex2f(-0.58, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, 0.05);
	glVertex2f(-0.38, 0.05);
	glVertex2f(-0.38, 0.1);
	glVertex2f(-0.45, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building door
	glVertex2f(-0.51, -0.25);
	glVertex2f(-0.45, -0.25);
	glVertex2f(-0.45, -0.18);
	glVertex2f(-0.51, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 125, 189);      //3rd building
	glVertex2f(0.3, -0.25);
	glVertex2f(0.55, -0.25);
	glVertex2f(0.55, 0.4);
	glVertex2f(0.3, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.3);
	glVertex2f(0.4, 0.3);
	glVertex2f(0.4, 0.35);
	glVertex2f(0.35, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, 0.3);
	glVertex2f(0.5, 0.3);
	glVertex2f(0.5, 0.35);
	glVertex2f(0.45, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.2);
	glVertex2f(0.4, 0.2);
	glVertex2f(0.4, 0.25);
	glVertex2f(0.35, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, 0.2);
	glVertex2f(0.5, 0.2);
	glVertex2f(0.5, 0.25);
	glVertex2f(0.45, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.1);
	glVertex2f(0.4, 0.1);
	glVertex2f(0.4, 0.15);
	glVertex2f(0.35, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, 0.1);
	glVertex2f(0.5, 0.1);
	glVertex2f(0.5, 0.15);
	glVertex2f(0.45, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.0);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.4, 0.05);
	glVertex2f(0.35, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, 0.05);
	glVertex2f(0.45, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, -0.1);
	glVertex2f(0.4, -0.1);
	glVertex2f(0.4, -0.05);
	glVertex2f(0.35, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, -0.1);
	glVertex2f(0.5, -0.1);
	glVertex2f(0.5, -0.05);
	glVertex2f(0.45, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, -0.2);
	glVertex2f(0.4, -0.2);
	glVertex2f(0.4, -0.15);
	glVertex2f(0.35, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, -0.2);
	glVertex2f(0.5, -0.2);
	glVertex2f(0.5, -0.15);
	glVertex2f(0.45, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building door
	glVertex2f(0.45, -0.25);
	glVertex2f(0.4, -0.25);
	glVertex2f(0.4, -0.22);
	glVertex2f(0.45, -0.22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 189, 145);      //4th building
	glVertex2f(0.6, -0.25);
	glVertex2f(0.95, -0.25);
	glVertex2f(0.95, 0.25);
	glVertex2f(0.6, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.2);
	glVertex2f(0.7, 0.2);
	glVertex2f(0.7, 0.15);
	glVertex2f(0.65, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.2);
	glVertex2f(0.8, 0.2);
	glVertex2f(0.8, 0.15);
	glVertex2f(0.75, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.2);
	glVertex2f(0.85, 0.2);
	glVertex2f(0.85, 0.15);
	glVertex2f(0.9, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.1);
	glVertex2f(0.7, 0.1);
	glVertex2f(0.7, 0.05);
	glVertex2f(0.65, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.1);
	glVertex2f(0.8, 0.1);
	glVertex2f(0.8, 0.05);
	glVertex2f(0.75, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.1);
	glVertex2f(0.85, 0.1);
	glVertex2f(0.85, 0.05);
	glVertex2f(0.9, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.0);
	glVertex2f(0.7, 0.0);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.65, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.0);
	glVertex2f(0.8, 0.0);
	glVertex2f(0.8, -0.05);
	glVertex2f(0.75, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.0);
	glVertex2f(0.85, 0.0);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, -0.1);
	glVertex2f(0.7, -0.1);
	glVertex2f(0.7, -0.15);
	glVertex2f(0.65, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, -0.1);
	glVertex2f(0.8, -0.1);
	glVertex2f(0.8, -0.15);
	glVertex2f(0.75, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, -0.1);
	glVertex2f(0.85, -0.1);
	glVertex2f(0.85, -0.15);
	glVertex2f(0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building door
	glVertex2f(0.75, -0.25);
	glVertex2f(0.8, -0.25);
	glVertex2f(0.8, -0.18);
	glVertex2f(0.75, -0.18);
    glEnd();

    glPushMatrix();
	glTranslatef(car_position1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(240, 80, 22);      //left car body
	glVertex2f(-0.5, -0.48);
	glVertex2f(-0.2, -0.48);
	glVertex2f(-0.2, -0.46);
	glVertex2f(-0.26, -0.43);
	glVertex2f(-0.3, -0.39);
	glVertex2f(-0.4, -0.39);
	glVertex2f(-0.43, -0.43);
	glVertex2f(-0.5, -0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //left car window
	glVertex2f(-0.42, -0.43);
	glVertex2f(-0.36, -0.43);
	glVertex2f(-0.36, -0.4);
	glVertex2f(-0.39, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //left car window
	glVertex2f(-0.34, -0.43);
	glVertex2f(-0.28, -0.43);
	glVertex2f(-0.31, -0.4);
	glVertex2f(-0.34, -0.4);
    glEnd();

    int a;                          //left car wheel1
    GLfloat x1=-0.41f; GLfloat y1=-0.48f; GLfloat radius1 =.03f;
	int triangleAmount1 = 20;
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x1, y1);
		for(a = 0; a <= triangleAmount1; a++) {
			glVertex2f(
                x1 + (radius1 * cos(a * twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(a * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	int b;                          //left car wheel2
    GLfloat x2=-0.27f; GLfloat y2=-0.48f; GLfloat radius2 =.03f;
	int triangleAmount2 = 20;
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x2, y2);
		for(b = 0; b <= triangleAmount2; b++) {
			glVertex2f(
                x2 + (radius2 * cos(b * twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(b * twicePi2 / triangleAmount2))
			);
		}
	glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(car_position2, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
    glColor3ub(209, 31, 123);      //right car body
	glVertex2f(0.2, -0.65);
	glVertex2f(0.5, -0.65);
	glVertex2f(0.5, -0.62);
	glVertex2f(0.46, -0.61);
	glVertex2f(0.4, -0.56);
	glVertex2f(0.3, -0.56);
	glVertex2f(0.27, -0.6);
	glVertex2f(0.2, -0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //right car window
	glVertex2f(0.34, -0.6);
	glVertex2f(0.28, -0.6);
	glVertex2f(0.31, -0.57);
	glVertex2f(0.34, -0.57);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //right car window
	glVertex2f(0.42, -0.6);
	glVertex2f(0.36, -0.6);
	glVertex2f(0.36, -0.57);
	glVertex2f(0.39, -0.57);
    glEnd();

    int c;                          //right car wheel
    GLfloat x3=0.29f; GLfloat y3=-0.65f; GLfloat radius3 =.03f;
	int triangleAmount3 = 20;
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x3, y3);
		for(c = 0; c <= triangleAmount3; c++) {
			glVertex2f(
                x3 + (radius3 * cos(c * twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(c * twicePi3 / triangleAmount3))
			);
		}
	glEnd();

	int d;                          //right car wheel
    GLfloat x4=0.42f; GLfloat y4=-0.65f; GLfloat radius4 =.03f;
	int triangleAmount4 = 20;
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x4, y4);
		for(d = 0; d <= triangleAmount4; d++) {
			glVertex2f(
                x4 + (radius4 * cos(d * twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(d * twicePi4 / triangleAmount4))
			);
		}
	glEnd();
    glPopMatrix();


    glBegin(GL_QUADS);
    glColor3ub(237, 151, 38);              //top car
	glVertex2f(0.03, -0.35);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.1, -0.17);
	glVertex2f(0.03, -0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(176, 112, 28);              //top car
	glVertex2f(0.03, -0.37);
	glVertex2f(0.1, -0.37);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.03, -0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);              //top car window
	glVertex2f(0.04, -0.3);
	glVertex2f(0.09, -0.3);
	glVertex2f(0.085, -0.25);
	glVertex2f(0.045, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(31, 207, 95);              //bottom car
	glVertex2f(-0.1, -0.9);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.03, -0.72);
	glVertex2f(-0.1, -0.72);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(22, 140, 65);              //bottom car
	glVertex2f(-0.1, -0.92);
	glVertex2f(-0.03, -0.92);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.1, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);              //bottom car window
	glVertex2f(-0.09, -0.85);
	glVertex2f(-0.04, -0.85);
	glVertex2f(-0.05, -0.8);
	glVertex2f(-0.08, -0.8);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom left signal
	glVertex2f(-0.2, -0.8);
	glVertex2f(-0.19, -0.8);
	glVertex2f(-0.19, -0.7);
	glVertex2f(-0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //bottom left signal
	glVertex2f(-0.23, -0.7);
	glVertex2f(-0.16, -0.7);
	glVertex2f(-0.16, -0.54);
	glVertex2f(-0.23, -0.54);
    glEnd();

    GLfloat x26=-0.195f; GLfloat y26=-0.57f;GLfloat radius26 =.025f;          //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x26, y26);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x26 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y26 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x27=-0.195f; GLfloat y27=-0.62f;                                   //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x27, y27);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x27 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y27 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x28=-0.195f; GLfloat y28=-0.67f;                                  //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x28, y28);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x28 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y28 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom right signal
	glVertex2f(0.2, -0.8);
	glVertex2f(0.19, -0.8);
	glVertex2f(0.19, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //bottom right signal
	glVertex2f(0.23, -0.7);
	glVertex2f(0.16, -0.7);
	glVertex2f(0.16, -0.54);
	glVertex2f(0.23, -0.54);
    glEnd();

    GLfloat x29=0.195f; GLfloat y29=-0.57f;GLfloat radius29 =.025f;          //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x29, y29);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x29 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y29 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x30=0.195f; GLfloat y30=-0.62f;                                   //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x30, y30);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x30 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y30 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x31=0.195f; GLfloat y31=-0.67f;                                  //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x31, y31);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x31 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y31 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top left signal
	glVertex2f(-0.2, -0.35);
	glVertex2f(-0.19, -0.35);
	glVertex2f(-0.19, -0.25);
	glVertex2f(-0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //top left signal
	glVertex2f(-0.23, -0.25);
	glVertex2f(-0.16, -0.25);
	glVertex2f(-0.16, -0.09);
	glVertex2f(-0.23, -0.09);
    glEnd();

    GLfloat x32=-0.195f; GLfloat y32=-0.12f;GLfloat radius32=.025f;          //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x32, y32);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x32 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y32 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x33=-0.195f; GLfloat y33=-0.17f;                                   //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x33, y33);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x33 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y33 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x34=-0.195f; GLfloat y34=-0.22f;                                  //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x34, y34);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x34 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y34 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top right signal
	glVertex2f(0.2, -0.35);
	glVertex2f(0.19, -0.35);
	glVertex2f(0.19, -0.25);
	glVertex2f(0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //top right signal
	glVertex2f(0.23, -0.25);
	glVertex2f(0.16, -0.25);
	glVertex2f(0.16, -0.09);
	glVertex2f(0.23, -0.09);
    glEnd();

    GLfloat x35=0.195f; GLfloat y35=-0.12f;GLfloat radius35=.025f;          //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x35, y35);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x35 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y35 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x36=0.195f; GLfloat y36=-0.17f;                                   //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x36, y36);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x36 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y36 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x37=0.195f; GLfloat y37=-0.22f;                                  //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x37, y37);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x37 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y37 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x14=-0.61f; GLfloat y14=-0.56f;GLfloat radius14 =.04f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x14, y14);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x14 + (radius14 * cos(e * twicePi5 / triangleAmount5)),
			    y14 + (radius14 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x15=-0.71f; GLfloat y15=-0.61f;GLfloat radius15 =.03f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x15, y15);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x15 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y15 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x16=-0.51f; GLfloat y16=-0.61f;                                  //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x16, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x16 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y16 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x17=0.61f; GLfloat y17=-0.56f;GLfloat radius17 =.04f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x17, y17);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x17 + (radius17 * cos(e * twicePi5 / triangleAmount5)),
			    y17 + (radius17 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x18=0.71f; GLfloat y18=-0.61f;GLfloat radius18 =.03f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x18, y18);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x18 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y18 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x19=0.51f; GLfloat y19=-0.61f;                                  //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x19, y19);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x19 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y19 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    glScaled(0.6, 0.6, 0);
    glTranslated(0.35, 0.45, 0);
    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x20=0.61f; GLfloat y20=-0.56f;GLfloat radius20 =.04f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x20, y20);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x20 + (radius20 * cos(e * twicePi5 / triangleAmount5)),
			    y20 + (radius20 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x21=0.71f; GLfloat y21=-0.61f;GLfloat radius21 =.03f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x21, y21);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x21 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y21 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x22=0.51f; GLfloat y22=-0.61f;                                  //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x22, y22);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x22 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y22 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	//glScaled(0.7, 0.7, 0);
    glTranslated(-0.85, 0.0, 0);
	glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x23=-0.61f; GLfloat y23=-0.56f;GLfloat radius23 =.04f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x23, y23);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x23 + (radius23 * cos(e * twicePi5 / triangleAmount5)),
			    y23 + (radius23 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x24=-0.71f; GLfloat y24=-0.61f;GLfloat radius24 =.03f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x24, y24);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x24 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y24 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x25=-0.51f; GLfloat y25=-0.61f;                                  //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x25, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x25 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y25 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glutTimerFunc(5500,city_night1,0);

	glFlush();  // Render now
}

void city_day1(int val){
     glutDisplayFunc(city_day);
}



void city_night() {
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);// Clear the color buffer (background)
    glLoadIdentity();//Reset the current matrix

    glBegin(GL_QUADS);
    glColor3ub(66, 66, 66);      //sky
	glVertex2f(-1, 0.2);
	glVertex2f(1, 0.2);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
    glEnd();

    glPushMatrix();
	glTranslatef(0.0f, moon_position, 0.0f);
    int i;                                      //moon
    GLfloat x=-0.5f; GLfloat y=0.07f; GLfloat radius =.13f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 232);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount; i++) {
			glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.0f, moon_position, 0.0f);
                                                                    //moon
    GLfloat x100=-0.45f; GLfloat y100=0.15f;
	int triangleAmount100 = 20;
	GLfloat twicePi100 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(66, 66, 66);
		glVertex2f(x100, y100);
		for(i = 0; i <= triangleAmount100; i++) {
			glVertex2f(
                x100 + (radius * cos(i * twicePi100 / triangleAmount100)),
			    y100 + (radius * sin(i * twicePi100 / triangleAmount100))
			);
		}
	glEnd();
    glPopMatrix();


    glPushMatrix();
	glTranslatef(cloud_position, 0.0f, 0.0f);
    int e;                          //cloud
    GLfloat x5=0.6f; GLfloat y5=0.85f; GLfloat radius5 =.05f;
	int triangleAmount5 = 20;
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x5, y5);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x5 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    GLfloat x6=0.66f; GLfloat y6=0.88f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x6, y6);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x6 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y6 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x7=0.66f; GLfloat y7=0.83f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x6, y6);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x7 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y7 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x8=0.73f; GLfloat y8=0.87f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x8, y8);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x8 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y8 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x9=0.72f; GLfloat y9=0.83f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x9, y9);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x9 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y9 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x10=-0.1f; GLfloat y10=0.88f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x10, y10);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x10 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y10 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x11=-0.05f; GLfloat y11=0.9f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x11, y11);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x11 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y11 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x12=-0.05f; GLfloat y12=0.85f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x12, y12);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x12 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y12 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x13=0.0f; GLfloat y13=0.85f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x13, y13);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x13 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y13 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();
	glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(41, 39, 39);      //background
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0.2);
	glVertex2f(-1, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(70, 79, 94);      //road
	glVertex2f(-1, -0.7);
	glVertex2f(1, -0.7);
	glVertex2f(1, -0.4);
	glVertex2f(-1, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(70, 79, 94);      //bottom road
	glVertex2f(-0.17, -1);
	glVertex2f(0.17, -1);
	glVertex2f(0.15, -0.7);
	glVertex2f(-0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(70, 79, 94);      //top road
	glVertex2f(-0.14, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(-0.1, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //left divider
	glVertex2f(-1.1, -0.55);
	glVertex2f(-1, -0.55);
	glVertex2f(-0.95, -0.53);
	glVertex2f(-1.05, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //left divider
	glVertex2f(-0.9, -0.55);
	glVertex2f(-0.8, -0.55);
	glVertex2f(-0.75, -0.53);
	glVertex2f(-0.85, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //left divider
	glVertex2f(-0.7, -0.55);
	glVertex2f(-0.6, -0.55);
	glVertex2f(-0.55, -0.53);
	glVertex2f(-0.65, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //left divider
	glVertex2f(-0.5, -0.55);
	glVertex2f(-0.4, -0.55);
	glVertex2f(-0.35, -0.53);
	glVertex2f(-0.45, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //left divider
	glVertex2f(-0.3, -0.55);
	glVertex2f(-0.2, -0.55);
	glVertex2f(-0.15, -0.53);
	glVertex2f(-0.25, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //right divider
	glVertex2f(0.15, -0.55);
	glVertex2f(0.25, -0.55);
	glVertex2f(0.3, -0.53);
	glVertex2f(0.2, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //right divider
	glVertex2f(0.35, -0.55);
	glVertex2f(0.45, -0.55);
	glVertex2f(0.5, -0.53);
	glVertex2f(0.4, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //right divider
	glVertex2f(0.55, -0.55);
	glVertex2f(0.65, -0.55);
	glVertex2f(0.7, -0.53);
	glVertex2f(0.6, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //right divider
	glVertex2f(0.75, -0.55);
	glVertex2f(0.85, -0.55);
	glVertex2f(0.9, -0.53);
	glVertex2f(0.8, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);            //right divider
	glVertex2f(0.95, -0.55);
	glVertex2f(1, -0.55);
	glVertex2f(1, -0.53);
	glVertex2f(1, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);            //bottom divider
	glVertex2f(-0.01, -0.8);
	glVertex2f(0.01, -0.8);
	glVertex2f(0.01, -0.7);
	glVertex2f(-0.01, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //bottom divider
	glVertex2f(-0.01, -0.9);
	glVertex2f(0.01, -0.9);
	glVertex2f(0.01, -1);
	glVertex2f(-0.01, -1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //top divider
	glVertex2f(-0.01, -0.4);
	glVertex2f(0.01, -0.4);
	glVertex2f(0.01, -0.3);
	glVertex2f(-0.01, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //top divider
	glVertex2f(-0.01, -0.2);
	glVertex2f(0.01, -0.2);
	glVertex2f(0.01, -0.1);
	glVertex2f(-0.01, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);            //top divider
	glVertex2f(-0.01, 0.0);
	glVertex2f(0.01, 0.0);
	glVertex2f(0.01, 0.1);
	glVertex2f(-0.01, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //bottom left footpath
	glVertex2f(-1, -0.8);
	glVertex2f(-0.25, -0.8);
	glVertex2f(-0.25, -0.7);
	glVertex2f(-1, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //bottom left footpath
	glVertex2f(-0.28, -1);
	glVertex2f(-0.17, -1);
	glVertex2f(-0.15, -0.7);
	glVertex2f(-0.25, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //bottom right footpath
	glVertex2f(0.2, -0.8);
	glVertex2f(1, -0.8);
	glVertex2f(1, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //bottom right footpath
	glVertex2f(0.17, -1);
	glVertex2f(0.28, -1);
	glVertex2f(0.25, -0.7);
	glVertex2f(0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //top left footpath
	glVertex2f(-1, -0.4);
	glVertex2f(-0.2, -0.4);
	glVertex2f(-0.2, -0.3);
	glVertex2f(-1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //top left footpath
	glVertex2f(-0.24, -0.4);
	glVertex2f(-0.14, -0.4);
	glVertex2f(-0.1, 0.2);
	glVertex2f(-0.19, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //top right footpath
	glVertex2f(1, -0.4);
	glVertex2f(0.2, -0.4);
	glVertex2f(0.2, -0.3);
	glVertex2f(1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //top right footpath
	glVertex2f(0.24, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(0.19, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 148, 146);      //1st building front
	glVertex2f(-0.95, -0.25);
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.95, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(42, 130, 130);      //1st building right
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.65, -0.2);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.7, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(45, 156, 153);      //1st building top
	glVertex2f(-0.95, 0.35);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.9, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.9, 0.25);
	glVertex2f(-0.85, 0.25);
	glVertex2f(-0.85, 0.3);
	glVertex2f(-0.9, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.25);
	glVertex2f(-0.75, 0.25);
	glVertex2f(-0.75, 0.3);
	glVertex2f(-0.8, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.9, 0.15);
	glVertex2f(-0.85, 0.15);
	glVertex2f(-0.85, 0.2);
	glVertex2f(-0.9, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.8, 0.15);
	glVertex2f(-0.75, 0.15);
	glVertex2f(-0.75, 0.2);
	glVertex2f(-0.8, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.05);
	glVertex2f(-0.85, 0.05);
	glVertex2f(-0.85, 0.1);
	glVertex2f(-0.9, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.8, 0.05);
	glVertex2f(-0.75, 0.05);
	glVertex2f(-0.75, 0.1);
	glVertex2f(-0.8, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.9, 0.0);
	glVertex2f(-0.85, 0.0);
	glVertex2f(-0.85, -0.05);
	glVertex2f(-0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.8, 0.0);
	glVertex2f(-0.75, 0.0);
	glVertex2f(-0.75, -0.05);
	glVertex2f(-0.8, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, -0.1);
	glVertex2f(-0.85, -0.1);
	glVertex2f(-0.85, -0.15);
	glVertex2f(-0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.8, -0.15);
	glVertex2f(-0.75, -0.15);
	glVertex2f(-0.75, -0.1);
	glVertex2f(-0.8, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building door
	glVertex2f(-0.85, -0.25);
	glVertex2f(-0.8, -0.25);
	glVertex2f(-0.8, -0.18);
	glVertex2f(-0.85, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(46, 124, 148);      //2nd building front
	glVertex2f(-0.63, -0.25);
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.63, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(39, 108, 130);      //2nd building right
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.28, -0.2);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.33, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(53, 148, 176);      //2nd building top
	glVertex2f(-0.63, 0.15);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.58, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //2nd building window
	glVertex2f(-0.58, -0.15);
	glVertex2f(-0.51, -0.15);
	glVertex2f(-0.51, -0.1);
	glVertex2f(-0.58, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, -0.15);
	glVertex2f(-0.38, -0.15);
	glVertex2f(-0.38, -0.1);
	glVertex2f(-0.45, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, 0.0);
	glVertex2f(-0.51, 0.0);
	glVertex2f(-0.51, -0.05);
	glVertex2f(-0.58, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //2nd building window
	glVertex2f(-0.45, 0.0);
	glVertex2f(-0.38, 0.0);
	glVertex2f(-0.38, -0.05);
	glVertex2f(-0.45, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //2nd building window
	glVertex2f(-0.58, 0.05);
	glVertex2f(-0.51, 0.05);
	glVertex2f(-0.51, 0.1);
	glVertex2f(-0.58, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //2nd building window
	glVertex2f(-0.45, 0.05);
	glVertex2f(-0.38, 0.05);
	glVertex2f(-0.38, 0.1);
	glVertex2f(-0.45, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building door
	glVertex2f(-0.51, -0.25);
	glVertex2f(-0.45, -0.25);
	glVertex2f(-0.45, -0.18);
	glVertex2f(-0.51, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(47, 99, 148);      //3rd building
	glVertex2f(0.3, -0.25);
	glVertex2f(0.55, -0.25);
	glVertex2f(0.55, 0.4);
	glVertex2f(0.3, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.35, 0.3);
	glVertex2f(0.4, 0.3);
	glVertex2f(0.4, 0.35);
	glVertex2f(0.35, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.45, 0.3);
	glVertex2f(0.5, 0.3);
	glVertex2f(0.5, 0.35);
	glVertex2f(0.45, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.2);
	glVertex2f(0.4, 0.2);
	glVertex2f(0.4, 0.25);
	glVertex2f(0.35, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.45, 0.2);
	glVertex2f(0.5, 0.2);
	glVertex2f(0.5, 0.25);
	glVertex2f(0.45, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.35, 0.1);
	glVertex2f(0.4, 0.1);
	glVertex2f(0.4, 0.15);
	glVertex2f(0.35, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, 0.1);
	glVertex2f(0.5, 0.1);
	glVertex2f(0.5, 0.15);
	glVertex2f(0.45, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.0);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.4, 0.05);
	glVertex2f(0.35, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.45, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, 0.05);
	glVertex2f(0.45, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.35, -0.1);
	glVertex2f(0.4, -0.1);
	glVertex2f(0.4, -0.05);
	glVertex2f(0.35, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, -0.1);
	glVertex2f(0.5, -0.1);
	glVertex2f(0.5, -0.05);
	glVertex2f(0.45, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.35, -0.2);
	glVertex2f(0.4, -0.2);
	glVertex2f(0.4, -0.15);
	glVertex2f(0.35, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.45, -0.2);
	glVertex2f(0.5, -0.2);
	glVertex2f(0.5, -0.15);
	glVertex2f(0.45, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building door
	glVertex2f(0.45, -0.25);
	glVertex2f(0.4, -0.25);
	glVertex2f(0.4, -0.22);
	glVertex2f(0.45, -0.22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 143, 109);      //4th building
	glVertex2f(0.6, -0.25);
	glVertex2f(0.95, -0.25);
	glVertex2f(0.95, 0.25);
	glVertex2f(0.6, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.65, 0.2);
	glVertex2f(0.7, 0.2);
	glVertex2f(0.7, 0.15);
	glVertex2f(0.65, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.2);
	glVertex2f(0.8, 0.2);
	glVertex2f(0.8, 0.15);
	glVertex2f(0.75, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.9, 0.2);
	glVertex2f(0.85, 0.2);
	glVertex2f(0.85, 0.15);
	glVertex2f(0.9, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.65, 0.1);
	glVertex2f(0.7, 0.1);
	glVertex2f(0.7, 0.05);
	glVertex2f(0.65, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.1);
	glVertex2f(0.8, 0.1);
	glVertex2f(0.8, 0.05);
	glVertex2f(0.75, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.9, 0.1);
	glVertex2f(0.85, 0.1);
	glVertex2f(0.85, 0.05);
	glVertex2f(0.9, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.0);
	glVertex2f(0.7, 0.0);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.65, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.75, 0.0);
	glVertex2f(0.8, 0.0);
	glVertex2f(0.8, -0.05);
	glVertex2f(0.75, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.0);
	glVertex2f(0.85, 0.0);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.65, -0.1);
	glVertex2f(0.7, -0.1);
	glVertex2f(0.7, -0.15);
	glVertex2f(0.65, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.75, -0.1);
	glVertex2f(0.8, -0.1);
	glVertex2f(0.8, -0.15);
	glVertex2f(0.75, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, -0.1);
	glVertex2f(0.85, -0.1);
	glVertex2f(0.85, -0.15);
	glVertex2f(0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building door
	glVertex2f(0.75, -0.25);
	glVertex2f(0.8, -0.25);
	glVertex2f(0.8, -0.18);
	glVertex2f(0.75, -0.18);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(240, 80, 22);      //left car body
	glVertex2f(-0.5, -0.48);
	glVertex2f(-0.2, -0.48);
	glVertex2f(-0.2, -0.46);
	glVertex2f(-0.26, -0.43);
	glVertex2f(-0.3, -0.39);
	glVertex2f(-0.4, -0.39);
	glVertex2f(-0.43, -0.43);
	glVertex2f(-0.5, -0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);      //left car window
	glVertex2f(-0.42, -0.43);
	glVertex2f(-0.36, -0.43);
	glVertex2f(-0.36, -0.4);
	glVertex2f(-0.39, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);      //left car window
	glVertex2f(-0.34, -0.43);
	glVertex2f(-0.28, -0.43);
	glVertex2f(-0.31, -0.4);
	glVertex2f(-0.34, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //right car light
	glVertex2f(-0.2, -0.47);
	glVertex2f(-0.12, -0.44);
	glVertex2f(-0.12, -0.5);
	glVertex2f(-0.2, -0.47);
    glEnd();

    int a;                          //left car wheel1
    GLfloat x1=-0.41f; GLfloat y1=-0.48f; GLfloat radius1 =.03f;
	int triangleAmount1 = 20;
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x1, y1);
		for(a = 0; a <= triangleAmount1; a++) {
			glVertex2f(
                x1 + (radius1 * cos(a * twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(a * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	int b;                          //left car wheel2
    GLfloat x2=-0.27f; GLfloat y2=-0.48f; GLfloat radius2 =.03f;
	int triangleAmount2 = 20;
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x2, y2);
		for(b = 0; b <= triangleAmount2; b++) {
			glVertex2f(
                x2 + (radius2 * cos(b * twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(b * twicePi2 / triangleAmount2))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(184, 28, 108);      //right car body
	glVertex2f(0.2, -0.65);
	glVertex2f(0.5, -0.65);
	glVertex2f(0.5, -0.62);
	glVertex2f(0.46, -0.61);
	glVertex2f(0.4, -0.56);
	glVertex2f(0.3, -0.56);
	glVertex2f(0.27, -0.6);
	glVertex2f(0.2, -0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);      //right car window
	glVertex2f(0.34, -0.6);
	glVertex2f(0.28, -0.6);
	glVertex2f(0.31, -0.57);
	glVertex2f(0.34, -0.57);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //right car light
	glVertex2f(0.12, -0.61);
	glVertex2f(0.2, -0.64);
	glVertex2f(0.2, -0.64);
	glVertex2f(0.12, -0.67);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);      //right car window
	glVertex2f(0.42, -0.6);
	glVertex2f(0.36, -0.6);
	glVertex2f(0.36, -0.57);
	glVertex2f(0.39, -0.57);
    glEnd();

    int c;                          //right car wheel
    GLfloat x3=0.29f; GLfloat y3=-0.65f; GLfloat radius3 =.03f;
	int triangleAmount3 = 20;
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x3, y3);
		for(c = 0; c <= triangleAmount3; c++) {
			glVertex2f(
                x3 + (radius3 * cos(c * twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(c * twicePi3 / triangleAmount3))
			);
		}
	glEnd();

	int d;                          //right car wheel
    GLfloat x4=0.42f; GLfloat y4=-0.65f; GLfloat radius4 =.03f;
	int triangleAmount4 = 20;
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x4, y4);
		for(d = 0; d <= triangleAmount4; d++) {
			glVertex2f(
                x4 + (radius4 * cos(d * twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(d * twicePi4 / triangleAmount4))
			);
		}
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.0f, car_position3, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(194, 123, 29);              //top car
	glVertex2f(0.03, -0.35);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.1, -0.17);
	glVertex2f(0.03, -0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(156, 99, 25);              //top car
	glVertex2f(0.03, -0.37);
	glVertex2f(0.1, -0.37);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.03, -0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //top car light
	glVertex2f(0.03, -0.47);
	glVertex2f(0.06, -0.47);
	glVertex2f(0.045, -0.37);
	glVertex2f(0.045, -0.37);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //top car light
	glVertex2f(0.07, -0.47);
	glVertex2f(0.1, -0.47);
	glVertex2f(0.085, -0.37);
	glVertex2f(0.085, -0.37);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);              //top car window
	glVertex2f(0.04, -0.3);
	glVertex2f(0.09, -0.3);
	glVertex2f(0.085, -0.25);
	glVertex2f(0.045, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.0f, car_position4, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(23, 153, 70);              //bottom car
	glVertex2f(-0.1, -0.9);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.03, -0.72);
	glVertex2f(-0.1, -0.72);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(17, 112, 52);              //bottom car
	glVertex2f(-0.1, -0.92);
	glVertex2f(-0.03, -0.92);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.1, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //bottom car light
	glVertex2f(-0.045, -0.73);
	glVertex2f(-0.045, -0.73);
	glVertex2f(-0.03, -0.63);
	glVertex2f(-0.06, -0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //bottom car light
	glVertex2f(-0.085, -0.73);
	glVertex2f(-0.085, -0.73);
	glVertex2f(-0.07, -0.63);
	glVertex2f(-0.1, -0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);              //bottom car window
	glVertex2f(-0.09, -0.85);
	glVertex2f(-0.04, -0.85);
	glVertex2f(-0.05, -0.8);
	glVertex2f(-0.08, -0.8);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom left signal
	glVertex2f(-0.2, -0.8);
	glVertex2f(-0.19, -0.8);
	glVertex2f(-0.19, -0.7);
	glVertex2f(-0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left signal
	glVertex2f(-0.23, -0.7);
	glVertex2f(-0.16, -0.7);
	glVertex2f(-0.16, -0.54);
	glVertex2f(-0.23, -0.54);
    glEnd();

    GLfloat x26=-0.195f; GLfloat y26=-0.57f;GLfloat radius26 =.025f;          //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x26, y26);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x26 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y26 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x27=-0.195f; GLfloat y27=-0.62f;                                   //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x27, y27);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x27 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y27 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x28=-0.195f; GLfloat y28=-0.67f;                                  //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x28, y28);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x28 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y28 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom right signal
	glVertex2f(0.2, -0.8);
	glVertex2f(0.19, -0.8);
	glVertex2f(0.19, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right signal
	glVertex2f(0.23, -0.7);
	glVertex2f(0.16, -0.7);
	glVertex2f(0.16, -0.54);
	glVertex2f(0.23, -0.54);
    glEnd();

    GLfloat x29=0.195f; GLfloat y29=-0.57f;GLfloat radius29 =.025f;          //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x29, y29);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x29 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y29 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x30=0.195f; GLfloat y30=-0.62f;                                   //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x30, y30);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x30 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y30 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x31=0.195f; GLfloat y31=-0.67f;                                  //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x31, y31);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x31 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y31 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top left signal
	glVertex2f(-0.2, -0.35);
	glVertex2f(-0.19, -0.35);
	glVertex2f(-0.19, -0.25);
	glVertex2f(-0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left signal
	glVertex2f(-0.23, -0.25);
	glVertex2f(-0.16, -0.25);
	glVertex2f(-0.16, -0.09);
	glVertex2f(-0.23, -0.09);
    glEnd();

    GLfloat x32=-0.195f; GLfloat y32=-0.12f;GLfloat radius32=.025f;          //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x32, y32);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x32 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y32 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x33=-0.195f; GLfloat y33=-0.17f;                                   //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x33, y33);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x33 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y33 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x34=-0.195f; GLfloat y34=-0.22f;                                  //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x34, y34);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x34 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y34 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top right signal
	glVertex2f(0.2, -0.35);
	glVertex2f(0.19, -0.35);
	glVertex2f(0.19, -0.25);
	glVertex2f(0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right signal
	glVertex2f(0.23, -0.25);
	glVertex2f(0.16, -0.25);
	glVertex2f(0.16, -0.09);
	glVertex2f(0.23, -0.09);
    glEnd();

    GLfloat x35=0.195f; GLfloat y35=-0.12f;GLfloat radius35=.025f;          //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x35, y35);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x35 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y35 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x36=0.195f; GLfloat y36=-0.17f;                                   //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x36, y36);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x36 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y36 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x37=0.195f; GLfloat y37=-0.22f;                                  //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x37, y37);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x37 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y37 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);glutTimerFunc(1500,city_night1,0);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x14=-0.61f; GLfloat y14=-0.56f;GLfloat radius14 =.04f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(252, 235, 45);
		glVertex2f(x14, y14);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x14 + (radius14 * cos(e * twicePi5 / triangleAmount5)),
			    y14 + (radius14 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x15=-0.71f; GLfloat y15=-0.61f;GLfloat radius15 =.03f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x15, y15);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x15 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y15 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x16=-0.51f; GLfloat y16=-0.61f;                                  //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x16, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x16 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y16 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x17=0.61f; GLfloat y17=-0.56f;GLfloat radius17 =.04f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(252, 235, 45);
		glVertex2f(x17, y17);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x17 + (radius17 * cos(e * twicePi5 / triangleAmount5)),
			    y17 + (radius17 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x18=0.71f; GLfloat y18=-0.61f;GLfloat radius18 =.03f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x18, y18);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x18 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y18 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x19=0.51f; GLfloat y19=-0.61f;                                  //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x19, y19);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x19 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y19 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    glScaled(0.6, 0.6, 0);
    glTranslated(0.35, 0.45, 0);
    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x20=0.61f; GLfloat y20=-0.56f;GLfloat radius20 =.04f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(252, 235, 45);
		glVertex2f(x20, y20);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x20 + (radius20 * cos(e * twicePi5 / triangleAmount5)),
			    y20 + (radius20 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x21=0.71f; GLfloat y21=-0.61f;GLfloat radius21 =.03f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x21, y21);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x21 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y21 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x22=0.51f; GLfloat y22=-0.61f;                                  //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x22, y22);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x22 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y22 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	//glScaled(0.7, 0.7, 0);
    glTranslated(-0.85, 0.0, 0);
	glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x23=-0.61f; GLfloat y23=-0.56f;GLfloat radius23 =.04f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(252, 235, 45);
		glVertex2f(x23, y23);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x23 + (radius23 * cos(e * twicePi5 / triangleAmount5)),
			    y23 + (radius23 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x24=-0.71f; GLfloat y24=-0.61f;GLfloat radius24 =.03f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x24, y24);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x24 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y24 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x25=-0.51f; GLfloat y25=-0.61f;                                  //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x25, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x25 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y25 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    glScaled(0.5, 0.5, 0);
    glTranslated(-0.5, 0.5, 0);
    glBegin(GL_POLYGON);
    glColor3ub(232, 232, 232);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.85);
	glVertex2f(-0.8, 0.8);
	glVertex2f(-0.82, 0.87);
	glVertex2f(-0.78, 0.89);
	glVertex2f(-0.83, 0.89);
	glVertex2f(-0.85, 0.94);
	glVertex2f(-0.87, 0.89);
	glVertex2f(-0.92, 0.89);
	glVertex2f(-0.88, 0.87);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.84);
	glVertex2f(-0.8, 0.8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.88, 0.86);
	glVertex2f(-0.92, 0.89);
    glEnd();

    glTranslated(1.5, 0.0, 0);
    glBegin(GL_POLYGON);
    glColor3ub(232, 232, 232);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.85);
	glVertex2f(-0.8, 0.8);
	glVertex2f(-0.82, 0.87);
	glVertex2f(-0.78, 0.89);
	glVertex2f(-0.83, 0.89);
	glVertex2f(-0.85, 0.94);
	glVertex2f(-0.87, 0.89);
	glVertex2f(-0.92, 0.89);
	glVertex2f(-0.88, 0.87);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.84);
	glVertex2f(-0.8, 0.8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.88, 0.86);
	glVertex2f(-0.92, 0.89);
    glEnd();

    glTranslated(1.5, 0.2, 0);
    glBegin(GL_POLYGON);
    glColor3ub(232, 232, 232);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.85);
	glVertex2f(-0.8, 0.8);
	glVertex2f(-0.82, 0.87);
	glVertex2f(-0.78, 0.89);
	glVertex2f(-0.83, 0.89);
	glVertex2f(-0.85, 0.94);
	glVertex2f(-0.87, 0.89);
	glVertex2f(-0.92, 0.89);
	glVertex2f(-0.88, 0.87);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.84);
	glVertex2f(-0.8, 0.8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.88, 0.86);
	glVertex2f(-0.92, 0.89);
    glEnd();

    glTranslated(1.0, 0.0, 0);
    glBegin(GL_POLYGON);
    glColor3ub(232, 232, 232);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.85);
	glVertex2f(-0.8, 0.8);
	glVertex2f(-0.82, 0.87);
	glVertex2f(-0.78, 0.89);
	glVertex2f(-0.83, 0.89);
	glVertex2f(-0.85, 0.94);
	glVertex2f(-0.87, 0.89);
	glVertex2f(-0.92, 0.89);
	glVertex2f(-0.88, 0.87);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.84);
	glVertex2f(-0.8, 0.8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.88, 0.86);
	glVertex2f(-0.92, 0.89);
    glEnd();

    glTranslated(-0.5, -0.7, 0);
    glBegin(GL_POLYGON);
    glColor3ub(232, 232, 232);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.85);
	glVertex2f(-0.8, 0.8);
	glVertex2f(-0.82, 0.87);
	glVertex2f(-0.78, 0.89);
	glVertex2f(-0.83, 0.89);
	glVertex2f(-0.85, 0.94);
	glVertex2f(-0.87, 0.89);
	glVertex2f(-0.92, 0.89);
	glVertex2f(-0.88, 0.87);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.84);
	glVertex2f(-0.8, 0.8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.88, 0.86);
	glVertex2f(-0.92, 0.89);
    glEnd();

    glTranslated(-0.5, -0.2, 0);
    glBegin(GL_POLYGON);
    glColor3ub(232, 232, 232);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.85);
	glVertex2f(-0.8, 0.8);
	glVertex2f(-0.82, 0.87);
	glVertex2f(-0.78, 0.89);
	glVertex2f(-0.83, 0.89);
	glVertex2f(-0.85, 0.94);
	glVertex2f(-0.87, 0.89);
	glVertex2f(-0.92, 0.89);
	glVertex2f(-0.88, 0.87);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.85, 0.84);
	glVertex2f(-0.8, 0.8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 66, 66);      //star
	glVertex2f(-0.9, 0.8);
	glVertex2f(-0.88, 0.86);
	glVertex2f(-0.92, 0.89);
    glEnd();

    glutPostRedisplay();
    glutTimerFunc(5500,city_day1,0);

	glFlush();  // Render now
}

void city_night1(int val){
     glutDisplayFunc(city_night);
}

void day_rain(){
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);// Clear the color buffer (background)
    glLoadIdentity();//Reset the current matrix

    glBegin(GL_QUADS);
    glColor3ub(59, 59, 59);      //sky
	glVertex2f(-1, 0.2);
	glVertex2f(1, 0.2);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
    glEnd();

    glPushMatrix();
	glTranslatef(plane_position, 0.0f, 0.0f);
    glBegin(GL_QUADS);              //plane up wing
	glColor3ub(53, 143, 112);
	glVertex2f(-0.6, 0.65);
	glVertex2f(-0.5, 0.65);
	glVertex2f(-0.47, 0.75);
	glVertex2f(-0.5, 0.75);
	glEnd();

    glBegin(GL_POLYGON);            //plane body
	glColor3ub(67, 171, 136);
	glVertex2f(-0.8, 0.6);
	glVertex2f(-0.73, 0.55);
	glVertex2f(-0.4, 0.55);
	glVertex2f(-0.4, 0.58);
	glVertex2f(-0.43, 0.63);
	glVertex2f(-0.5, 0.68);
	glVertex2f(-0.72, 0.68);
	glEnd();

    glBegin(GL_QUADS);              //plane tail
	glColor3ub(53, 143, 112);
	glVertex2f(-0.8, 0.6);
	glVertex2f(-0.72, 0.68);
	glVertex2f(-0.79, 0.75);
	glVertex2f(-0.82, 0.75);
	glEnd();

    glBegin(GL_QUADS);              //plane down wing
	glColor3ub(53, 143, 112);
	glVertex2f(-0.75, 0.48);
	glVertex2f(-0.7, 0.48);
	glVertex2f(-0.5, 0.58);
	glVertex2f(-0.65, 0.58);
	glEnd();

    glBegin(GL_QUADS);              //plane front window
	glColor3ub(227, 227, 227);
	glVertex2f(-0.53, 0.63);
	glVertex2f(-0.43, 0.63);
	glVertex2f(-0.5, 0.68);
	glVertex2f(-0.53, 0.65);
	glEnd();

	glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.56, 0.63);
	glVertex2f(-0.58, 0.63);
	glVertex2f(-0.58, 0.66);
	glVertex2f(-0.56, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.56, 0.63);
	glVertex2f(-0.58, 0.63);
	glVertex2f(-0.58, 0.66);
	glVertex2f(-0.56, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.6, 0.63);
	glVertex2f(-0.62, 0.63);
	glVertex2f(-0.62, 0.66);
	glVertex2f(-0.6, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.64, 0.63);
	glVertex2f(-0.66, 0.63);
	glVertex2f(-0.66, 0.66);
	glVertex2f(-0.64, 0.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);      //plane window
	glVertex2f(-0.68, 0.63);
	glVertex2f(-0.7, 0.63);
	glVertex2f(-0.7, 0.66);
	glVertex2f(-0.68, 0.66);
    glEnd();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(bird_position, 0.0f, 0.0f);
    glBegin(GL_LINES);              //bird
    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.35, 0.45);
    glBegin(GL_LINES);
    glVertex2f(-0.35, 0.45);
    glVertex2f(-0.3, 0.5);
    glEnd();

    glBegin(GL_LINES);              //bird
    glVertex2f(-0.25, 0.5);
    glVertex2f(-0.2, 0.45);
    glBegin(GL_LINES);
    glVertex2f(-0.2, 0.45);
    glVertex2f(-0.15, 0.5);
    glEnd();
    glPopMatrix();

    glLoadIdentity();
    glPushMatrix();
	glTranslatef(cloud_position, 0.0f, 0.0f);
    int e;                          //cloud
    GLfloat x5=0.6f; GLfloat y5=0.85f; GLfloat radius5 =.05f;
	int triangleAmount5 = 20;
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x5, y5);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x5 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    GLfloat x6=0.66f; GLfloat y6=0.88f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x6, y6);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x6 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y6 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x7=0.66f; GLfloat y7=0.83f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x6, y6);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x7 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y7 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x8=0.73f; GLfloat y8=0.87f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x8, y8);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x8 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y8 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x9=0.72f; GLfloat y9=0.83f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x9, y9);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x9 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y9 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x10=-0.1f; GLfloat y10=0.88f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x10, y10);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x10 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y10 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x11=-0.05f; GLfloat y11=0.9f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x11, y11);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x11 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y11 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x12=-0.05f; GLfloat y12=0.85f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x12, y12);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x12 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y12 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x13=0.0f; GLfloat y13=0.85f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(232, 232, 230);
		glVertex2f(x13, y13);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x13 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y13 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();
	glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(82, 79, 78);      //background
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0.2);
	glVertex2f(-1, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //road
	glVertex2f(-1, -0.7);
	glVertex2f(1, -0.7);
	glVertex2f(1, -0.4);
	glVertex2f(-1, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //bottom road
	glVertex2f(-0.17, -1);
	glVertex2f(0.17, -1);
	glVertex2f(0.15, -0.7);
	glVertex2f(-0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100, 113, 135);      //top road
	glVertex2f(-0.14, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(-0.1, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-1.1, -0.55);
	glVertex2f(-1, -0.55);
	glVertex2f(-0.95, -0.53);
	glVertex2f(-1.05, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.9, -0.55);
	glVertex2f(-0.8, -0.55);
	glVertex2f(-0.75, -0.53);
	glVertex2f(-0.85, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.7, -0.55);
	glVertex2f(-0.6, -0.55);
	glVertex2f(-0.55, -0.53);
	glVertex2f(-0.65, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.5, -0.55);
	glVertex2f(-0.4, -0.55);
	glVertex2f(-0.35, -0.53);
	glVertex2f(-0.45, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //left divider
	glVertex2f(-0.3, -0.55);
	glVertex2f(-0.2, -0.55);
	glVertex2f(-0.15, -0.53);
	glVertex2f(-0.25, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.15, -0.55);
	glVertex2f(0.25, -0.55);
	glVertex2f(0.3, -0.53);
	glVertex2f(0.2, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.35, -0.55);
	glVertex2f(0.45, -0.55);
	glVertex2f(0.5, -0.53);
	glVertex2f(0.4, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.55, -0.55);
	glVertex2f(0.65, -0.55);
	glVertex2f(0.7, -0.53);
	glVertex2f(0.6, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.75, -0.55);
	glVertex2f(0.85, -0.55);
	glVertex2f(0.9, -0.53);
	glVertex2f(0.8, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //right divider
	glVertex2f(0.95, -0.55);
	glVertex2f(1, -0.55);
	glVertex2f(1, -0.53);
	glVertex2f(1, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //bottom divider
	glVertex2f(-0.01, -0.8);
	glVertex2f(0.01, -0.8);
	glVertex2f(0.01, -0.7);
	glVertex2f(-0.01, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //bottom divider
	glVertex2f(-0.01, -0.9);
	glVertex2f(0.01, -0.9);
	glVertex2f(0.01, -1);
	glVertex2f(-0.01, -1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, -0.4);
	glVertex2f(0.01, -0.4);
	glVertex2f(0.01, -0.3);
	glVertex2f(-0.01, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, -0.2);
	glVertex2f(0.01, -0.2);
	glVertex2f(0.01, -0.1);
	glVertex2f(-0.01, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);             //top divider
	glVertex2f(-0.01, 0.0);
	glVertex2f(0.01, 0.0);
	glVertex2f(0.01, 0.1);
	glVertex2f(-0.01, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom left footpath
	glVertex2f(-1, -0.8);
	glVertex2f(-0.25, -0.8);
	glVertex2f(-0.25, -0.7);
	glVertex2f(-1, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom left footpath
	glVertex2f(-0.28, -1);
	glVertex2f(-0.17, -1);
	glVertex2f(-0.15, -0.7);
	glVertex2f(-0.25, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom right footpath
	glVertex2f(0.2, -0.8);
	glVertex2f(1, -0.8);
	glVertex2f(1, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //bottom right footpath
	glVertex2f(0.17, -1);
	glVertex2f(0.28, -1);
	glVertex2f(0.25, -0.7);
	glVertex2f(0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top left footpath
	glVertex2f(-1, -0.4);
	glVertex2f(-0.2, -0.4);
	glVertex2f(-0.2, -0.3);
	glVertex2f(-1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top left footpath
	glVertex2f(-0.24, -0.4);
	glVertex2f(-0.14, -0.4);
	glVertex2f(-0.1, 0.2);
	glVertex2f(-0.19, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top right footpath
	glVertex2f(1, -0.4);
	glVertex2f(0.2, -0.4);
	glVertex2f(0.2, -0.3);
	glVertex2f(1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(148, 148, 148);      //top right footpath
	glVertex2f(0.24, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(0.19, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 148, 146);      //1st building front
	glVertex2f(-0.95, -0.25);
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.95, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(39, 122, 121);      //1st building right
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.65, -0.2);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.7, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(68, 212, 209);      //1st building top
	glVertex2f(-0.95, 0.35);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.9, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.25);
	glVertex2f(-0.85, 0.25);
	glVertex2f(-0.85, 0.3);
	glVertex2f(-0.9, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.25);
	glVertex2f(-0.75, 0.25);
	glVertex2f(-0.75, 0.3);
	glVertex2f(-0.8, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.15);
	glVertex2f(-0.85, 0.15);
	glVertex2f(-0.85, 0.2);
	glVertex2f(-0.9, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.15);
	glVertex2f(-0.75, 0.15);
	glVertex2f(-0.75, 0.2);
	glVertex2f(-0.8, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.05);
	glVertex2f(-0.85, 0.05);
	glVertex2f(-0.85, 0.1);
	glVertex2f(-0.9, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.05);
	glVertex2f(-0.75, 0.05);
	glVertex2f(-0.75, 0.1);
	glVertex2f(-0.8, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.0);
	glVertex2f(-0.85, 0.0);
	glVertex2f(-0.85, -0.05);
	glVertex2f(-0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.0);
	glVertex2f(-0.75, 0.0);
	glVertex2f(-0.75, -0.05);
	glVertex2f(-0.8, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, -0.1);
	glVertex2f(-0.85, -0.1);
	glVertex2f(-0.85, -0.15);
	glVertex2f(-0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, -0.15);
	glVertex2f(-0.75, -0.15);
	glVertex2f(-0.75, -0.1);
	glVertex2f(-0.8, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building door
	glVertex2f(-0.85, -0.25);
	glVertex2f(-0.8, -0.25);
	glVertex2f(-0.8, -0.18);
	glVertex2f(-0.85, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(54, 145, 173);      //2nd building front
	glVertex2f(-0.63, -0.25);
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.63, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(41, 115, 138);      //2nd building right
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.28, -0.2);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.33, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(72, 189, 224);      //2nd building top
	glVertex2f(-0.63, 0.15);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.58, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, -0.15);
	glVertex2f(-0.51, -0.15);
	glVertex2f(-0.51, -0.1);
	glVertex2f(-0.58, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, -0.15);
	glVertex2f(-0.38, -0.15);
	glVertex2f(-0.38, -0.1);
	glVertex2f(-0.45, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, 0.0);
	glVertex2f(-0.51, 0.0);
	glVertex2f(-0.51, -0.05);
	glVertex2f(-0.58, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, 0.0);
	glVertex2f(-0.38, 0.0);
	glVertex2f(-0.38, -0.05);
	glVertex2f(-0.45, -0.05);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, 0.05);
	glVertex2f(-0.51, 0.05);
	glVertex2f(-0.51, 0.1);
	glVertex2f(-0.58, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, 0.05);
	glVertex2f(-0.38, 0.05);
	glVertex2f(-0.38, 0.1);
	glVertex2f(-0.45, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building door
	glVertex2f(-0.51, -0.25);
	glVertex2f(-0.45, -0.25);
	glVertex2f(-0.45, -0.18);
	glVertex2f(-0.51, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 125, 189);      //3rd building
	glVertex2f(0.3, -0.25);
	glVertex2f(0.55, -0.25);
	glVertex2f(0.55, 0.4);
	glVertex2f(0.3, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.3);
	glVertex2f(0.4, 0.3);
	glVertex2f(0.4, 0.35);
	glVertex2f(0.35, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, 0.3);
	glVertex2f(0.5, 0.3);
	glVertex2f(0.5, 0.35);
	glVertex2f(0.45, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.2);
	glVertex2f(0.4, 0.2);
	glVertex2f(0.4, 0.25);
	glVertex2f(0.35, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, 0.2);
	glVertex2f(0.5, 0.2);
	glVertex2f(0.5, 0.25);
	glVertex2f(0.45, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.1);
	glVertex2f(0.4, 0.1);
	glVertex2f(0.4, 0.15);
	glVertex2f(0.35, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, 0.1);
	glVertex2f(0.5, 0.1);
	glVertex2f(0.5, 0.15);
	glVertex2f(0.45, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.0);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.4, 0.05);
	glVertex2f(0.35, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, 0.05);
	glVertex2f(0.45, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, -0.1);
	glVertex2f(0.4, -0.1);
	glVertex2f(0.4, -0.05);
	glVertex2f(0.35, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, -0.1);
	glVertex2f(0.5, -0.1);
	glVertex2f(0.5, -0.05);
	glVertex2f(0.45, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, -0.2);
	glVertex2f(0.4, -0.2);
	glVertex2f(0.4, -0.15);
	glVertex2f(0.35, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, -0.2);
	glVertex2f(0.5, -0.2);
	glVertex2f(0.5, -0.15);
	glVertex2f(0.45, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building door
	glVertex2f(0.45, -0.25);
	glVertex2f(0.4, -0.25);
	glVertex2f(0.4, -0.22);
	glVertex2f(0.45, -0.22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 189, 145);      //4th building
	glVertex2f(0.6, -0.25);
	glVertex2f(0.95, -0.25);
	glVertex2f(0.95, 0.25);
	glVertex2f(0.6, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.2);
	glVertex2f(0.7, 0.2);
	glVertex2f(0.7, 0.15);
	glVertex2f(0.65, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.2);
	glVertex2f(0.8, 0.2);
	glVertex2f(0.8, 0.15);
	glVertex2f(0.75, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.2);
	glVertex2f(0.85, 0.2);
	glVertex2f(0.85, 0.15);
	glVertex2f(0.9, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.1);
	glVertex2f(0.7, 0.1);
	glVertex2f(0.7, 0.05);
	glVertex2f(0.65, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.1);
	glVertex2f(0.8, 0.1);
	glVertex2f(0.8, 0.05);
	glVertex2f(0.75, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.1);
	glVertex2f(0.85, 0.1);
	glVertex2f(0.85, 0.05);
	glVertex2f(0.9, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.0);
	glVertex2f(0.7, 0.0);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.65, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.0);
	glVertex2f(0.8, 0.0);
	glVertex2f(0.8, -0.05);
	glVertex2f(0.75, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.0);
	glVertex2f(0.85, 0.0);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, -0.1);
	glVertex2f(0.7, -0.1);
	glVertex2f(0.7, -0.15);
	glVertex2f(0.65, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, -0.1);
	glVertex2f(0.8, -0.1);
	glVertex2f(0.8, -0.15);
	glVertex2f(0.75, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, -0.1);
	glVertex2f(0.85, -0.1);
	glVertex2f(0.85, -0.15);
	glVertex2f(0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building door
	glVertex2f(0.75, -0.25);
	glVertex2f(0.8, -0.25);
	glVertex2f(0.8, -0.18);
	glVertex2f(0.75, -0.18);
    glEnd();

    glPushMatrix();
	glTranslatef(car_position1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(240, 80, 22);      //left car body
	glVertex2f(-0.5, -0.48);
	glVertex2f(-0.2, -0.48);
	glVertex2f(-0.2, -0.46);
	glVertex2f(-0.26, -0.43);
	glVertex2f(-0.3, -0.39);
	glVertex2f(-0.4, -0.39);
	glVertex2f(-0.43, -0.43);
	glVertex2f(-0.5, -0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //left car window
	glVertex2f(-0.42, -0.43);
	glVertex2f(-0.36, -0.43);
	glVertex2f(-0.36, -0.4);
	glVertex2f(-0.39, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //left car window
	glVertex2f(-0.34, -0.43);
	glVertex2f(-0.28, -0.43);
	glVertex2f(-0.31, -0.4);
	glVertex2f(-0.34, -0.4);
    glEnd();

    int a;                          //left car wheel1
    GLfloat x1=-0.41f; GLfloat y1=-0.48f; GLfloat radius1 =.03f;
	int triangleAmount1 = 20;
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x1, y1);
		for(a = 0; a <= triangleAmount1; a++) {
			glVertex2f(
                x1 + (radius1 * cos(a * twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(a * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	int b;                          //left car wheel2
    GLfloat x2=-0.27f; GLfloat y2=-0.48f; GLfloat radius2 =.03f;
	int triangleAmount2 = 20;
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x2, y2);
		for(b = 0; b <= triangleAmount2; b++) {
			glVertex2f(
                x2 + (radius2 * cos(b * twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(b * twicePi2 / triangleAmount2))
			);
		}
	glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(car_position2, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
    glColor3ub(209, 31, 123);      //right car body
	glVertex2f(0.2, -0.65);
	glVertex2f(0.5, -0.65);
	glVertex2f(0.5, -0.62);
	glVertex2f(0.46, -0.61);
	glVertex2f(0.4, -0.56);
	glVertex2f(0.3, -0.56);
	glVertex2f(0.27, -0.6);
	glVertex2f(0.2, -0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //right car window
	glVertex2f(0.34, -0.6);
	glVertex2f(0.28, -0.6);
	glVertex2f(0.31, -0.57);
	glVertex2f(0.34, -0.57);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //right car window
	glVertex2f(0.42, -0.6);
	glVertex2f(0.36, -0.6);
	glVertex2f(0.36, -0.57);
	glVertex2f(0.39, -0.57);
    glEnd();

    int c;                          //right car wheel
    GLfloat x3=0.29f; GLfloat y3=-0.65f; GLfloat radius3 =.03f;
	int triangleAmount3 = 20;
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x3, y3);
		for(c = 0; c <= triangleAmount3; c++) {
			glVertex2f(
                x3 + (radius3 * cos(c * twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(c * twicePi3 / triangleAmount3))
			);
		}
	glEnd();

	int d;                          //right car wheel
    GLfloat x4=0.42f; GLfloat y4=-0.65f; GLfloat radius4 =.03f;
	int triangleAmount4 = 20;
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x4, y4);
		for(d = 0; d <= triangleAmount4; d++) {
			glVertex2f(
                x4 + (radius4 * cos(d * twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(d * twicePi4 / triangleAmount4))
			);
		}
	glEnd();
    glPopMatrix();


    glBegin(GL_QUADS);
    glColor3ub(237, 151, 38);              //top car
	glVertex2f(0.03, -0.35);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.1, -0.17);
	glVertex2f(0.03, -0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(176, 112, 28);              //top car
	glVertex2f(0.03, -0.37);
	glVertex2f(0.1, -0.37);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.03, -0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);              //top car window
	glVertex2f(0.04, -0.3);
	glVertex2f(0.09, -0.3);
	glVertex2f(0.085, -0.25);
	glVertex2f(0.045, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(31, 207, 95);              //bottom car
	glVertex2f(-0.1, -0.9);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.03, -0.72);
	glVertex2f(-0.1, -0.72);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(22, 140, 65);              //bottom car
	glVertex2f(-0.1, -0.92);
	glVertex2f(-0.03, -0.92);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.1, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);              //bottom car window
	glVertex2f(-0.09, -0.85);
	glVertex2f(-0.04, -0.85);
	glVertex2f(-0.05, -0.8);
	glVertex2f(-0.08, -0.8);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom left signal
	glVertex2f(-0.2, -0.8);
	glVertex2f(-0.19, -0.8);
	glVertex2f(-0.19, -0.7);
	glVertex2f(-0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //bottom left signal
	glVertex2f(-0.23, -0.7);
	glVertex2f(-0.16, -0.7);
	glVertex2f(-0.16, -0.54);
	glVertex2f(-0.23, -0.54);
    glEnd();

    GLfloat x26=-0.195f; GLfloat y26=-0.57f;GLfloat radius26 =.025f;          //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x26, y26);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x26 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y26 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x27=-0.195f; GLfloat y27=-0.62f;                                   //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x27, y27);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x27 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y27 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x28=-0.195f; GLfloat y28=-0.67f;                                  //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x28, y28);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x28 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y28 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom right signal
	glVertex2f(0.2, -0.8);
	glVertex2f(0.19, -0.8);
	glVertex2f(0.19, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //bottom right signal
	glVertex2f(0.23, -0.7);
	glVertex2f(0.16, -0.7);
	glVertex2f(0.16, -0.54);
	glVertex2f(0.23, -0.54);
    glEnd();

    GLfloat x29=0.195f; GLfloat y29=-0.57f;GLfloat radius29 =.025f;          //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x29, y29);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x29 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y29 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x30=0.195f; GLfloat y30=-0.62f;                                   //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x30, y30);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x30 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y30 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x31=0.195f; GLfloat y31=-0.67f;                                  //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x31, y31);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x31 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y31 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top left signal
	glVertex2f(-0.2, -0.35);
	glVertex2f(-0.19, -0.35);
	glVertex2f(-0.19, -0.25);
	glVertex2f(-0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //top left signal
	glVertex2f(-0.23, -0.25);
	glVertex2f(-0.16, -0.25);
	glVertex2f(-0.16, -0.09);
	glVertex2f(-0.23, -0.09);
    glEnd();

    GLfloat x32=-0.195f; GLfloat y32=-0.12f;GLfloat radius32=.025f;          //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x32, y32);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x32 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y32 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x33=-0.195f; GLfloat y33=-0.17f;                                   //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x33, y33);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x33 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y33 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x34=-0.195f; GLfloat y34=-0.22f;                                  //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x34, y34);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x34 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y34 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top right signal
	glVertex2f(0.2, -0.35);
	glVertex2f(0.19, -0.35);
	glVertex2f(0.19, -0.25);
	glVertex2f(0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 227, 227);             //top right signal
	glVertex2f(0.23, -0.25);
	glVertex2f(0.16, -0.25);
	glVertex2f(0.16, -0.09);
	glVertex2f(0.23, -0.09);
    glEnd();

    GLfloat x35=0.195f; GLfloat y35=-0.12f;GLfloat radius35=.025f;          //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x35, y35);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x35 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y35 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x36=0.195f; GLfloat y36=-0.17f;                                   //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x36, y36);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x36 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y36 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x37=0.195f; GLfloat y37=-0.22f;                                  //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x37, y37);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x37 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y37 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glPushMatrix();
	glTranslatef(0.0f,rain_position, 0.0f);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-.90,.95);
	glVertex2f(-.90,.90);
	glVertex2f(-.90,.85);
	glVertex2f(-.90,.80);
	glVertex2f(-.90,.75);
	glVertex2f(-.90,.70);
	glVertex2f(-.90,.65);
	glVertex2f(-.90,.60);
	glVertex2f(-.90,.55);
	glVertex2f(-.90,.50);
	glVertex2f(-.90,.45);
	glVertex2f(-.90,.40);
	glVertex2f(-.90,.35);
	glVertex2f(-.90,.30);
	glVertex2f(-.90,.25);
	glVertex2f(-.90,.20);
	glVertex2f(-.90,.15);
	glVertex2f(-.90,.10);
	glVertex2f(-.90,.05);
	glVertex2f(-.90,.00);
	glVertex2f(-.90,-.05);
	glVertex2f(-.90,-.10);
	glVertex2f(-.90,-.15);
	glVertex2f(-.90,-.20);
	glVertex2f(-.90,-.25);
	glVertex2f(-.90,-.30);
	glVertex2f(-.90,-.35);
	glVertex2f(-.90,-.40);
	glVertex2f(-.90,-.45);
	glVertex2f(-.90,-.50);
	glVertex2f(-.90,-.55);
	glVertex2f(-.90,-.60);
	glVertex2f(-.90,-.65);
	glVertex2f(-.90,-.70);
	glVertex2f(-.90,-.75);
	glVertex2f(-.90,-.80);
	glVertex2f(-.90,-.85);
	glVertex2f(-.90,-.90);
	//glVertex2f(-.90,-.95);
	//glVertex2f(-.80,.95);
	glVertex2f(-.80,.90);
	glVertex2f(-.80,.85);
	glVertex2f(-.80,.80);
	glVertex2f(-.80,.75);
	glVertex2f(-.80,.70);
	glVertex2f(-.80,.65);
	glVertex2f(-.80,.60);
	glVertex2f(-.80,.55);
	glVertex2f(-.80,.50);
	glVertex2f(-.80,.45);
	glVertex2f(-.80,.40);
	glVertex2f(-.80,.35);
	glVertex2f(-.80,.30);
	glVertex2f(-.80,.25);
	glVertex2f(-.80,.20);
	glVertex2f(-.80,.15);
	glVertex2f(-.80,.10);
	glVertex2f(-.80,.05);
	glVertex2f(-.80,.00);
	glVertex2f(-.80,-.05);
	glVertex2f(-.80,-.10);
	glVertex2f(-.80,-.15);
	glVertex2f(-.80,-.20);
	glVertex2f(-.80,-.25);
	glVertex2f(-.80,-.30);
	glVertex2f(-.80,-.35);
	glVertex2f(-.80,-.40);
	glVertex2f(-.80,-.45);
	glVertex2f(-.80,-.50);
	glVertex2f(-.80,-.55);
	glVertex2f(-.80,-.60);
	glVertex2f(-.80,-.65);
	glVertex2f(-.80,-.70);
	glVertex2f(-.80,-.75);
	glVertex2f(-.80,-.80);
	glVertex2f(-.80,-.85);
	glVertex2f(-.80,-.90);
	glVertex2f(-.80,-.95);
	glVertex2f(-.70,.95);
	glVertex2f(-.70,.90);
	glVertex2f(-.70,.85);
	glVertex2f(-.70,.80);
	glVertex2f(-.70,.75);
	glVertex2f(-.70,.70);
	glVertex2f(-.70,.65);
	glVertex2f(-.70,.60);
	glVertex2f(-.70,.55);
	glVertex2f(-.70,.50);
	glVertex2f(-.70,.45);
	glVertex2f(-.70,.40);
	glVertex2f(-.70,.35);
	glVertex2f(-.70,.30);
	glVertex2f(-.70,.25);
	glVertex2f(-.70,.20);
	glVertex2f(-.70,.15);
	glVertex2f(-.70,.10);
	glVertex2f(-.70,.05);
	glVertex2f(-.70,.00);
	glVertex2f(-.70,-.05);
	glVertex2f(-.70,-.10);
	glVertex2f(-.70,-.15);
	glVertex2f(-.70,-.20);
	glVertex2f(-.70,-.25);
	glVertex2f(-.70,-.30);
	glVertex2f(-.70,-.35);
	glVertex2f(-.70,-.40);
	glVertex2f(-.70,-.45);
	glVertex2f(-.70,-.50);
	glVertex2f(-.70,-.55);
	glVertex2f(-.70,-.60);
	glVertex2f(-.70,-.65);
	glVertex2f(-.70,-.70);
	glVertex2f(-.70,-.75);
	glVertex2f(-.70,-.80);
	glVertex2f(-.70,-.85);
	glVertex2f(-.70,-.90);
	//glVertex2f(-.70,-.95);
	//glVertex2f(-.60,.95);
	glVertex2f(-.60,.90);
	glVertex2f(-.60,.85);
	glVertex2f(-.60,.80);
	glVertex2f(-.60,.75);
	glVertex2f(-.60,.70);
	glVertex2f(-.60,.65);
	glVertex2f(-.60,.60);
	glVertex2f(-.60,.55);
	glVertex2f(-.60,.50);
	glVertex2f(-.60,.45);
	glVertex2f(-.60,.40);
	glVertex2f(-.60,.35);
	glVertex2f(-.60,.30);
	glVertex2f(-.60,.25);
	glVertex2f(-.60,.20);
	glVertex2f(-.60,.15);
	glVertex2f(-.60,.10);
	glVertex2f(-.60,.05);
	glVertex2f(-.60,.00);
	glVertex2f(-.60,-.05);
	glVertex2f(-.60,-.10);
	glVertex2f(-.60,-.15);
	glVertex2f(-.60,-.20);
	glVertex2f(-.60,-.25);
	glVertex2f(-.60,-.30);
	glVertex2f(-.60,-.35);
	glVertex2f(-.60,-.40);
	glVertex2f(-.60,-.45);
	glVertex2f(-.60,-.50);
	glVertex2f(-.60,-.55);
	glVertex2f(-.60,-.60);
	glVertex2f(-.60,-.65);
	glVertex2f(-.60,-.70);
	glVertex2f(-.60,-.75);
	glVertex2f(-.60,-.80);
	glVertex2f(-.60,-.85);
	glVertex2f(-.60,-.90);
	glVertex2f(-.60,-.95);
    glVertex2f(-.50,.95);
	glVertex2f(-.50,.90);
	glVertex2f(-.50,.85);
	glVertex2f(-.50,.80);
	glVertex2f(-.50,.75);
	glVertex2f(-.50,.70);
	glVertex2f(-.50,.65);
	glVertex2f(-.50,.60);
	glVertex2f(-.50,.55);
	glVertex2f(-.50,.50);
	glVertex2f(-.50,.45);
	glVertex2f(-.50,.40);
	glVertex2f(-.50,.35);
	glVertex2f(-.50,.30);
	glVertex2f(-.50,.25);
	glVertex2f(-.50,.20);
	glVertex2f(-.50,.15);
	glVertex2f(-.50,.10);
	glVertex2f(-.50,.05);
	glVertex2f(-.50,.00);
	glVertex2f(-.50,-.05);
	glVertex2f(-.50,-.10);
	glVertex2f(-.50,-.15);
	glVertex2f(-.50,-.20);
	glVertex2f(-.50,-.25);
	glVertex2f(-.50,-.30);
	glVertex2f(-.50,-.35);
	glVertex2f(-.50,-.40);
	glVertex2f(-.50,-.45);
	glVertex2f(-.50,-.50);
	glVertex2f(-.50,-.55);
	glVertex2f(-.50,-.60);
	glVertex2f(-.50,-.65);
	glVertex2f(-.50,-.70);
	glVertex2f(-.50,-.75);
	glVertex2f(-.50,-.80);
	glVertex2f(-.50,-.85);
	glVertex2f(-.50,-.90);
	//glVertex2f(-.50,-.95);
	//glVertex2f(-.40,.95);
	glVertex2f(-.40,.90);
	glVertex2f(-.40,.85);
	glVertex2f(-.40,.80);
	glVertex2f(-.40,.75);
	glVertex2f(-.40,.70);
	glVertex2f(-.40,.65);
	glVertex2f(-.40,.60);
	glVertex2f(-.40,.55);
	glVertex2f(-.40,.50);
	glVertex2f(-.40,.45);
	glVertex2f(-.40,.40);
	glVertex2f(-.40,.35);
	glVertex2f(-.40,.30);
	glVertex2f(-.40,.25);
	glVertex2f(-.40,.20);
	glVertex2f(-.40,.15);
	glVertex2f(-.40,.10);
	glVertex2f(-.40,.05);
	glVertex2f(-.40,.00);
	glVertex2f(-.40,-.05);
	glVertex2f(-.40,-.10);
	glVertex2f(-.40,-.15);
	glVertex2f(-.40,-.20);
	glVertex2f(-.40,-.25);
	glVertex2f(-.40,-.30);
	glVertex2f(-.40,-.35);
	glVertex2f(-.40,-.40);
	glVertex2f(-.40,-.45);
	glVertex2f(-.40,-.50);
	glVertex2f(-.40,-.55);
	glVertex2f(-.40,-.60);
	glVertex2f(-.40,-.65);
	glVertex2f(-.40,-.70);
	glVertex2f(-.40,-.75);
	glVertex2f(-.40,-.80);
    glVertex2f(-.40,-.85);
	glVertex2f(-.40,-.90);
	glVertex2f(-.40,-.95);
	glVertex2f(-.30,.95);
	glVertex2f(-.30,.90);
    glVertex2f(-.30,.95);
	glVertex2f(-.30,.95);
	glVertex2f(-.30,.90);
	glVertex2f(-.30,.85);
	glVertex2f(-.30,.80);
	glVertex2f(-.30,.75);
	glVertex2f(-.30,.70);
	glVertex2f(-.30,.65);
	glVertex2f(-.30,.60);
	glVertex2f(-.30,.55);
	glVertex2f(-.30,.50);
	glVertex2f(-.30,.45);
	glVertex2f(-.30,.40);
	glVertex2f(-.30,.35);
	glVertex2f(-.30,.30);
	glVertex2f(-.30,.25);
	glVertex2f(-.30,.20);
	glVertex2f(-.30,.15);
	glVertex2f(-.30,.10);
	glVertex2f(-.30,.05);
	glVertex2f(-.30,.00);
	glVertex2f(-.30,-.05);
	glVertex2f(-.30,-.10);
	glVertex2f(-.30,-.15);
	glVertex2f(-.30,-.20);
	glVertex2f(-.30,-.25);
	glVertex2f(-.30,-.30);
	glVertex2f(-.30,-.35);
	glVertex2f(-.30,-.40);
	glVertex2f(-.30,-.45);
	glVertex2f(-.30,-.50);
	glVertex2f(-.30,-.55);
	glVertex2f(-.30,-.60);
	glVertex2f(-.30,-.65);
	glVertex2f(-.30,-.70);
	glVertex2f(-.30,-.75);
	glVertex2f(-.30,-.80);
	glVertex2f(-.30,-.95);
	glVertex2f(-.30,-.90);
	glVertex2f(-.30,-.85);
    glVertex2f(-.30,-.85);
	glVertex2f(-.30,-.90);
	//glVertex2f(-.30,-.95);
	//glVertex2f(-.20,.95);
	glVertex2f(-.20,.90);
	glVertex2f(-.20,.85);
	glVertex2f(-.20,.80);
	glVertex2f(-.20,.75);
	glVertex2f(-.20,.70);
	glVertex2f(-.20,.65);
	glVertex2f(-.20,.60);
	glVertex2f(-.20,.55);
	glVertex2f(-.20,.50);
	glVertex2f(-.20,.45);
	glVertex2f(-.20,.40);
	glVertex2f(-.20,.35);
	glVertex2f(-.20,.30);
	glVertex2f(-.20,.25);
	glVertex2f(-.20,.20);
	glVertex2f(-.20,.15);
	glVertex2f(-.20,.10);
	glVertex2f(-.20,.05);
	glVertex2f(-.20,.00);
	glVertex2f(-.20,-.05);
	glVertex2f(-.20,-.10);
	glVertex2f(-.20,-.15);
	glVertex2f(-.20,-.20);
	glVertex2f(-.20,-.25);
	glVertex2f(-.20,-.30);
	glVertex2f(-.20,-.35);
	glVertex2f(-.20,-.40);
	glVertex2f(-.20,-.45);
	glVertex2f(-.20,-.50);
	glVertex2f(-.20,-.55);
	glVertex2f(-.20,-.60);
	glVertex2f(-.20,-.65);
	glVertex2f(-.20,-.70);
	glVertex2f(-.20,-.75);
	glVertex2f(-.20,-.80);
	glVertex2f(-.20,-.85);
	glVertex2f(-.20,-.90);
	glVertex2f(-.20,-.95);
	glVertex2f(-.10,.95);
	glVertex2f(-.10,.90);
	glVertex2f(-.10,.85);
	glVertex2f(-.10,.80);
	glVertex2f(-.10,.75);
	glVertex2f(-.10,.70);
	glVertex2f(-.10,.65);
	glVertex2f(-.10,.60);
	glVertex2f(-.10,.55);
	glVertex2f(-.10,.50);
	glVertex2f(-.10,.45);
	glVertex2f(-.10,.40);
	glVertex2f(-.10,.35);
	glVertex2f(-.10,.30);
	glVertex2f(-.10,.25);
	glVertex2f(-.10,.20);
	glVertex2f(-.10,.15);
	glVertex2f(-.10,.10);
	glVertex2f(-.10,.05);
	glVertex2f(-.10,.00);
	glVertex2f(-.10,-.05);
	glVertex2f(-.10,-.10);
	glVertex2f(-.10,-.15);
	glVertex2f(-.10,-.20);
	glVertex2f(-.10,-.25);
	glVertex2f(-.10,-.30);
	glVertex2f(-.10,-.35);
	glVertex2f(-.10,-.40);
	glVertex2f(-.10,-.45);
	glVertex2f(-.10,-.50);
	glVertex2f(-.10,-.55);
	glVertex2f(-.10,-.60);
	glVertex2f(-.10,-.65);
	glVertex2f(-.10,-.70);
	glVertex2f(-.10,-.75);
	glVertex2f(-.10,-.80);
    glVertex2f(-.10,-.85);
	glVertex2f(-.10,-.90);
	//glVertex2f(-.10,-.95);
	//glVertex2f(.00,.95);
	glVertex2f(.00,.90);
	glVertex2f(.00,.85);
	glVertex2f(.00,.80);
	glVertex2f(.00,.75);
	glVertex2f(.00,.70);
	glVertex2f(.00,.65);
	glVertex2f(.00,.60);
	glVertex2f(.00,.55);
	glVertex2f(.00,.50);
	glVertex2f(.00,.45);
	glVertex2f(.00,.40);
	glVertex2f(.00,.35);
	glVertex2f(.00,.30);
	glVertex2f(.00,.25);
	glVertex2f(.00,.20);
	glVertex2f(.00,.15);
	glVertex2f(.00,.10);
	glVertex2f(.00,.05);
	glVertex2f(.00,.00);
	glVertex2f(.00,-.05);
	glVertex2f(.00,-.10);
	glVertex2f(.00,-.15);
	glVertex2f(.00,-.20);
	glVertex2f(.00,-.25);
	glVertex2f(.00,-.30);
	glVertex2f(.00,-.35);
	glVertex2f(.00,-.40);
	glVertex2f(.00,-.45);
	glVertex2f(.00,-.50);
	glVertex2f(.00,-.55);
	glVertex2f(.00,-.60);
	glVertex2f(.00,-.65);
	glVertex2f(.00,-.70);
	glVertex2f(.00,-.75);
	glVertex2f(.00,-.80);
	glVertex2f(.00,-.85);
	glVertex2f(.00,-.90);
	glVertex2f(.00,-.95);
	glVertex2f(.10,.95);
	glVertex2f(.10,.90);
	glVertex2f(.10,.85);
	glVertex2f(.10,.80);
	glVertex2f(.10,.75);
	glVertex2f(.10,.70);
	glVertex2f(.10,.65);
	glVertex2f(.10,.60);
	glVertex2f(.10,.55);
	glVertex2f(.10,.50);
	glVertex2f(.10,.45);
	glVertex2f(.10,.40);
	glVertex2f(.10,.35);
	glVertex2f(.10,.30);
	glVertex2f(.10,.25);
	glVertex2f(.10,.20);
	glVertex2f(.10,.15);
	glVertex2f(.10,.10);
	glVertex2f(.10,.05);
	glVertex2f(.10,.00);
	glVertex2f(.10,-.05);
	glVertex2f(.10,-.10);
	glVertex2f(.10,-.15);
	glVertex2f(.10,-.20);
	glVertex2f(.10,-.25);
	glVertex2f(.10,-.30);
	glVertex2f(.10,-.35);
	glVertex2f(.10,-.40);
	glVertex2f(.10,-.45);
	glVertex2f(.10,-.50);
	glVertex2f(.10,-.55);
	glVertex2f(.10,-.60);
	glVertex2f(.10,-.65);
	glVertex2f(.10,-.70);
	glVertex2f(.10,-.75);
	glVertex2f(.10,-.80);
	glVertex2f(.10,-.85);
	glVertex2f(.10,-.90);
	//glVertex2f(.10,-.95);
	//glVertex2f(.20,.95);
	glVertex2f(.20,.90);
	glVertex2f(.20,.85);
	glVertex2f(.20,.80);
	glVertex2f(.20,.75);
	glVertex2f(.20,.70);
	glVertex2f(.20,.65);
	glVertex2f(.20,.60);
	glVertex2f(.20,.55);
	glVertex2f(.20,.50);
	glVertex2f(.20,.45);
	glVertex2f(.20,.40);
	glVertex2f(.20,.35);
	glVertex2f(.20,.30);
	glVertex2f(.20,.25);
	glVertex2f(.20,.20);
	glVertex2f(.20,.15);
	glVertex2f(.20,.10);
	glVertex2f(.20,.05);
	glVertex2f(.20,.00);
	glVertex2f(.20,-.05);
	glVertex2f(.20,-.10);
	glVertex2f(.20,-.15);
	glVertex2f(.20,-.20);
	glVertex2f(.20,-.25);
	glVertex2f(.20,-.30);
	glVertex2f(.20,-.35);
	glVertex2f(.20,-.40);
	glVertex2f(.20,-.45);
	glVertex2f(.20,-.50);
	glVertex2f(.20,-.55);
	glVertex2f(.20,-.60);
	glVertex2f(.20,-.65);
	glVertex2f(.20,-.70);
	glVertex2f(.20,-.75);
	glVertex2f(.20,-.80);
	glVertex2f(.20,-.85);
	glVertex2f(.20,-.90);
	glVertex2f(.20,-.95);
	glVertex2f(.30,.95);
	glVertex2f(.30,.90);
	glVertex2f(.30,.85);
	glVertex2f(.30,.80);
	glVertex2f(.30,.75);
	glVertex2f(.30,.70);
	glVertex2f(.30,.65);
	glVertex2f(.30,.60);
	glVertex2f(.30,.55);
	glVertex2f(.30,.50);
	glVertex2f(.30,.45);
	glVertex2f(.30,.40);
	glVertex2f(.30,.35);
	glVertex2f(.30,.30);
	glVertex2f(.30,.25);
	glVertex2f(.30,.20);
	glVertex2f(.30,.15);
	glVertex2f(.30,.10);
	glVertex2f(.30,.05);
	glVertex2f(.30,.00);
	glVertex2f(.30,-.05);
	glVertex2f(.30,-.10);
	glVertex2f(.30,-.15);
	glVertex2f(.30,-.20);
	glVertex2f(.30,-.25);
	glVertex2f(.30,-.30);
	glVertex2f(.30,-.35);
	glVertex2f(.30,-.40);
	glVertex2f(.30,-.45);
	glVertex2f(.30,-.50);
	glVertex2f(.30,-.55);
	glVertex2f(.30,-.60);
	glVertex2f(.30,-.65);
	glVertex2f(.30,-.70);
	glVertex2f(.30,-.75);
	glVertex2f(.30,-.80);
	glVertex2f(.30,-.85);
	glVertex2f(.30,-.90);
	//glVertex2f(.30,-.95);
	//glVertex2f(.40,.95);
	glVertex2f(.40,.90);
	glVertex2f(.40,.85);
	glVertex2f(.40,.80);
	glVertex2f(.40,.75);
	glVertex2f(.40,.70);
	glVertex2f(.40,.65);
	glVertex2f(.40,.60);
	glVertex2f(.40,.55);
	glVertex2f(.40,.50);
	glVertex2f(.40,.45);
	glVertex2f(.40,.40);
	glVertex2f(.40,.35);
	glVertex2f(.40,.30);
	glVertex2f(.40,.25);
	glVertex2f(.40,.20);
	glVertex2f(.40,.15);
	glVertex2f(.40,.10);
	glVertex2f(.40,.05);
	glVertex2f(.40,.00);
	glVertex2f(.40,-.05);
	glVertex2f(.40,-.10);
	glVertex2f(.40,-.15);
	glVertex2f(.40,-.20);
	glVertex2f(.40,-.25);
	glVertex2f(.40,-.30);
	glVertex2f(.40,-.35);
	glVertex2f(.40,-.40);
	glVertex2f(.40,-.45);
	glVertex2f(.40,-.50);
	glVertex2f(.40,-.55);
	glVertex2f(.40,-.60);
	glVertex2f(.40,-.65);
	glVertex2f(.40,-.70);
	glVertex2f(.40,-.75);
	glVertex2f(.40,-.80);
	glVertex2f(.40,-.85);
	glVertex2f(.40,-.90);
	glVertex2f(.40,-.95);
	glVertex2f(.50,.90);
	glVertex2f(.50,.85);
	glVertex2f(.50,.80);
	glVertex2f(.50,.75);
	glVertex2f(.50,.70);
	glVertex2f(.50,.65);
	glVertex2f(.50,.60);
	glVertex2f(.50,.55);
	glVertex2f(.50,.50);
	glVertex2f(.50,.45);
	glVertex2f(.50,.40);
	glVertex2f(.50,.35);
	glVertex2f(.50,.30);
	glVertex2f(.50,.25);
	glVertex2f(.50,.20);
	glVertex2f(.50,.15);
	glVertex2f(.50,.10);
	glVertex2f(.50,.05);
	glVertex2f(.50,.00);
	glVertex2f(.50,-.05);
	glVertex2f(.50,-.10);
	glVertex2f(.50,-.15);
	glVertex2f(.50,-.20);
	glVertex2f(.50,-.25);
	glVertex2f(.50,-.30);
	glVertex2f(.50,-.35);
	glVertex2f(.50,-.40);
	glVertex2f(.50,-.45);
	glVertex2f(.50,-.50);
	glVertex2f(.50,-.55);
	glVertex2f(.50,-.60);
	glVertex2f(.50,-.65);
	glVertex2f(.50,-.70);
	glVertex2f(.50,-.75);
	glVertex2f(.50,-.80);
	glVertex2f(.50,-.85);
	glVertex2f(.50,-.90);
	glVertex2f(.50,-.95);
	glVertex2f(.60,.95);
	glVertex2f(.60,.90);
	glVertex2f(.60,.85);
	glVertex2f(.60,.80);
	glVertex2f(.60,.75);
	glVertex2f(.60,.70);
	glVertex2f(.60,.65);
	glVertex2f(.60,.60);
	glVertex2f(.60,.55);
	glVertex2f(.60,.50);
	glVertex2f(.60,.45);
	glVertex2f(.60,.40);
	glVertex2f(.60,.35);
	glVertex2f(.60,.30);
	glVertex2f(.60,.25);
	glVertex2f(.60,.20);
	glVertex2f(.60,.15);
	glVertex2f(.60,.10);
	glVertex2f(.60,.05);
	glVertex2f(.60,.00);
	glVertex2f(.60,-.05);
	glVertex2f(.60,-.10);
	glVertex2f(.60,-.15);
	glVertex2f(.60,-.20);
	glVertex2f(.60,-.25);
	glVertex2f(.60,-.30);
	glVertex2f(.60,-.35);
	glVertex2f(.60,-.40);
	glVertex2f(.60,-.45);
	glVertex2f(.60,-.50);
	glVertex2f(.60,-.55);
	glVertex2f(.60,-.60);
	glVertex2f(.60,-.65);
	glVertex2f(.60,-.70);
	glVertex2f(.60,-.75);
	glVertex2f(.60,-.80);
	glVertex2f(.60,-.85);
	glVertex2f(.60,-.90);
	//glVertex2f(.60,-.95);
	//glVertex2f(.70,.95);
	glVertex2f(.70,.90);
	glVertex2f(.70,.85);
	glVertex2f(.70,.80);
	glVertex2f(.70,.75);
	glVertex2f(.70,.70);
	glVertex2f(.70,.65);
	glVertex2f(.70,.60);
	glVertex2f(.70,.55);
	glVertex2f(.70,.50);
	glVertex2f(.70,.45);
	glVertex2f(.70,.40);
	glVertex2f(.70,.35);
	glVertex2f(.70,.30);
	glVertex2f(.70,.25);
	glVertex2f(.70,.20);
	glVertex2f(.70,.15);
	glVertex2f(.70,.10);
	glVertex2f(.70,.05);
	glVertex2f(.70,.00);
	glVertex2f(.70,-.05);
	glVertex2f(.70,-.10);
	glVertex2f(.70,-.15);
	glVertex2f(.70,-.20);
	glVertex2f(.70,-.25);
	glVertex2f(.70,-.30);
	glVertex2f(.70,-.35);
	glVertex2f(.70,-.40);
	glVertex2f(.70,-.45);
	glVertex2f(.70,-.50);
	glVertex2f(.70,-.55);
	glVertex2f(.70,-.60);
	glVertex2f(.70,-.65);
	glVertex2f(.70,-.70);
	glVertex2f(.70,-.75);
	glVertex2f(.70,-.80);
	glVertex2f(.70,-.85);
	glVertex2f(.70,-.90);
	glVertex2f(.70,-.95);
	glVertex2f(.80,.95);
	glVertex2f(.80,.90);
	glVertex2f(.80,.85);
	glVertex2f(.80,.80);
	glVertex2f(.80,.75);
	glVertex2f(.80,.70);
	glVertex2f(.80,.65);
	glVertex2f(.80,.60);
	glVertex2f(.80,.55);
	glVertex2f(.80,.50);
	glVertex2f(.80,.45);
	glVertex2f(.80,.40);
	glVertex2f(.80,.35);
	glVertex2f(.80,.30);
	glVertex2f(.80,.25);
	glVertex2f(.80,.20);
	glVertex2f(.80,.15);
	glVertex2f(.80,.10);
	glVertex2f(.80,.05);
	glVertex2f(.80,.00);
	glVertex2f(.80,-.05);
	glVertex2f(.80,-.10);
	glVertex2f(.80,-.15);
	glVertex2f(.80,-.20);
	glVertex2f(.80,-.25);
	glVertex2f(.80,-.30);
	glVertex2f(.80,-.35);
	glVertex2f(.80,-.40);
	glVertex2f(.80,-.45);
	glVertex2f(.80,-.50);
	glVertex2f(.80,-.55);
	glVertex2f(.80,-.60);
	glVertex2f(.80,-.65);
	glVertex2f(.80,-.70);
	glVertex2f(.80,-.75);
	glVertex2f(.80,-.80);
	glVertex2f(.80,-.85);
	glVertex2f(.80,-.90);
	//glVertex2f(.80,-.95);
	//glVertex2f(.90,.95);
	glVertex2f(.90,.90);
	glVertex2f(.90,.85);
	glVertex2f(.90,.80);
	glVertex2f(.90,.75);
	glVertex2f(.90,.70);
	glVertex2f(.90,.65);
	glVertex2f(.90,.60);
	glVertex2f(.90,.55);
	glVertex2f(.90,.50);
	glVertex2f(.90,.45);
	glVertex2f(.90,.40);
	glVertex2f(.90,.35);
	glVertex2f(.90,.30);
	glVertex2f(.90,.25);
	glVertex2f(.90,.20);
	glVertex2f(.90,.15);
	glVertex2f(.90,.10);
	glVertex2f(.90,.05);
	glVertex2f(.90,.00);
	glVertex2f(.90,-.05);
	glVertex2f(.90,-.10);
	glVertex2f(.90,-.15);
	glVertex2f(.90,-.20);
	glVertex2f(.90,-.25);
	glVertex2f(.90,-.30);
	glVertex2f(.90,-.35);
	glVertex2f(.90,-.40);
	glVertex2f(.90,-.45);
	glVertex2f(.90,-.50);
	glVertex2f(.90,-.55);
	glVertex2f(.90,-.60);
	glVertex2f(.90,-.65);
	glVertex2f(.90,-.70);
	glVertex2f(.90,-.75);
	glVertex2f(.90,-.80);
	glVertex2f(.90,-.85);
	glVertex2f(.90,-.90);
	glVertex2f(.90,-.95);
	glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x14=-0.61f; GLfloat y14=-0.56f;GLfloat radius14 =.04f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x14, y14);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x14 + (radius14 * cos(e * twicePi5 / triangleAmount5)),
			    y14 + (radius14 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x15=-0.71f; GLfloat y15=-0.61f;GLfloat radius15 =.03f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x15, y15);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x15 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y15 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x16=-0.51f; GLfloat y16=-0.61f;                                  //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x16, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x16 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y16 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x17=0.61f; GLfloat y17=-0.56f;GLfloat radius17 =.04f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x17, y17);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x17 + (radius17 * cos(e * twicePi5 / triangleAmount5)),
			    y17 + (radius17 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x18=0.71f; GLfloat y18=-0.61f;GLfloat radius18 =.03f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x18, y18);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x18 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y18 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x19=0.51f; GLfloat y19=-0.61f;                                  //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x19, y19);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x19 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y19 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    glScaled(0.6, 0.6, 0);
    glTranslated(0.35, 0.45, 0);
    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x20=0.61f; GLfloat y20=-0.56f;GLfloat radius20 =.04f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x20, y20);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x20 + (radius20 * cos(e * twicePi5 / triangleAmount5)),
			    y20 + (radius20 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x21=0.71f; GLfloat y21=-0.61f;GLfloat radius21 =.03f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x21, y21);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x21 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y21 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x22=0.51f; GLfloat y22=-0.61f;                                  //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x22, y22);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x22 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y22 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	//glScaled(0.7, 0.7, 0);
    glTranslated(-0.85, 0.0, 0);
	glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x23=-0.61f; GLfloat y23=-0.56f;GLfloat radius23 =.04f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x23, y23);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x23 + (radius23 * cos(e * twicePi5 / triangleAmount5)),
			    y23 + (radius23 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x24=-0.71f; GLfloat y24=-0.61f;GLfloat radius24 =.03f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x24, y24);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x24 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y24 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x25=-0.51f; GLfloat y25=-0.61f;                                  //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 237, 237);
		glVertex2f(x25, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x25 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y25 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();
    glutTimerFunc(5500,night_rain1,0);

	glFlush();  // Render now
}

void day_rain1(int val){
     glutDisplayFunc(day_rain);
}

void night_rain(){
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);// Clear the color buffer (background)
    glLoadIdentity();//Reset the current matrix

    glBegin(GL_QUADS);
    glColor3ub(66, 66, 66);      //sky
	glVertex2f(-1, 0.2);
	glVertex2f(1, 0.2);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
    glEnd();


    glPushMatrix();
	glTranslatef(cloud_position, 0.0f, 0.0f);
    int e;                          //cloud
    GLfloat x5=0.6f; GLfloat y5=0.85f; GLfloat radius5 =.05f;
	int triangleAmount5 = 20;
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x5, y5);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x5 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    GLfloat x6=0.66f; GLfloat y6=0.88f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x6, y6);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x6 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y6 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x7=0.66f; GLfloat y7=0.83f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x6, y6);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x7 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y7 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x8=0.73f; GLfloat y8=0.87f;          //cloud
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x8, y8);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x8 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y8 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x9=0.72f; GLfloat y9=0.83f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x9, y9);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x9 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y9 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x10=-0.1f; GLfloat y10=0.88f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x10, y10);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x10 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y10 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x11=-0.05f; GLfloat y11=0.9f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x11, y11);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x11 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y11 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x12=-0.05f; GLfloat y12=0.85f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x12, y12);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x12 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y12 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x13=0.0f; GLfloat y13=0.85f;          //cloud

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(196, 196, 196);
		glVertex2f(x13, y13);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x13 + (radius5 * cos(e * twicePi5 / triangleAmount5)),
			    y13 + (radius5 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();
	glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(41, 39, 39);      //background
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0.2);
	glVertex2f(-1, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(70, 79, 94);      //road
	glVertex2f(-1, -0.7);
	glVertex2f(1, -0.7);
	glVertex2f(1, -0.4);
	glVertex2f(-1, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(70, 79, 94);      //bottom road
	glVertex2f(-0.17, -1);
	glVertex2f(0.17, -1);
	glVertex2f(0.15, -0.7);
	glVertex2f(-0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(70, 79, 94);      //top road
	glVertex2f(-0.14, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(-0.1, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //left divider
	glVertex2f(-1.1, -0.55);
	glVertex2f(-1, -0.55);
	glVertex2f(-0.95, -0.53);
	glVertex2f(-1.05, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //left divider
	glVertex2f(-0.9, -0.55);
	glVertex2f(-0.8, -0.55);
	glVertex2f(-0.75, -0.53);
	glVertex2f(-0.85, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //left divider
	glVertex2f(-0.7, -0.55);
	glVertex2f(-0.6, -0.55);
	glVertex2f(-0.55, -0.53);
	glVertex2f(-0.65, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //left divider
	glVertex2f(-0.5, -0.55);
	glVertex2f(-0.4, -0.55);
	glVertex2f(-0.35, -0.53);
	glVertex2f(-0.45, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //left divider
	glVertex2f(-0.3, -0.55);
	glVertex2f(-0.2, -0.55);
	glVertex2f(-0.15, -0.53);
	glVertex2f(-0.25, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //right divider
	glVertex2f(0.15, -0.55);
	glVertex2f(0.25, -0.55);
	glVertex2f(0.3, -0.53);
	glVertex2f(0.2, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //right divider
	glVertex2f(0.35, -0.55);
	glVertex2f(0.45, -0.55);
	glVertex2f(0.5, -0.53);
	glVertex2f(0.4, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //right divider
	glVertex2f(0.55, -0.55);
	glVertex2f(0.65, -0.55);
	glVertex2f(0.7, -0.53);
	glVertex2f(0.6, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //right divider
	glVertex2f(0.75, -0.55);
	glVertex2f(0.85, -0.55);
	glVertex2f(0.9, -0.53);
	glVertex2f(0.8, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);            //right divider
	glVertex2f(0.95, -0.55);
	glVertex2f(1, -0.55);
	glVertex2f(1, -0.53);
	glVertex2f(1, -0.53);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);            //bottom divider
	glVertex2f(-0.01, -0.8);
	glVertex2f(0.01, -0.8);
	glVertex2f(0.01, -0.7);
	glVertex2f(-0.01, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //bottom divider
	glVertex2f(-0.01, -0.9);
	glVertex2f(0.01, -0.9);
	glVertex2f(0.01, -1);
	glVertex2f(-0.01, -1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //top divider
	glVertex2f(-0.01, -0.4);
	glVertex2f(0.01, -0.4);
	glVertex2f(0.01, -0.3);
	glVertex2f(-0.01, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);             //top divider
	glVertex2f(-0.01, -0.2);
	glVertex2f(0.01, -0.2);
	glVertex2f(0.01, -0.1);
	glVertex2f(-0.01, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(212, 212, 212);            //top divider
	glVertex2f(-0.01, 0.0);
	glVertex2f(0.01, 0.0);
	glVertex2f(0.01, 0.1);
	glVertex2f(-0.01, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //bottom left footpath
	glVertex2f(-1, -0.8);
	glVertex2f(-0.25, -0.8);
	glVertex2f(-0.25, -0.7);
	glVertex2f(-1, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //bottom left footpath
	glVertex2f(-0.28, -1);
	glVertex2f(-0.17, -1);
	glVertex2f(-0.15, -0.7);
	glVertex2f(-0.25, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //bottom right footpath
	glVertex2f(0.2, -0.8);
	glVertex2f(1, -0.8);
	glVertex2f(1, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //bottom right footpath
	glVertex2f(0.17, -1);
	glVertex2f(0.28, -1);
	glVertex2f(0.25, -0.7);
	glVertex2f(0.15, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //top left footpath
	glVertex2f(-1, -0.4);
	glVertex2f(-0.2, -0.4);
	glVertex2f(-0.2, -0.3);
	glVertex2f(-1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //top left footpath
	glVertex2f(-0.24, -0.4);
	glVertex2f(-0.14, -0.4);
	glVertex2f(-0.1, 0.2);
	glVertex2f(-0.19, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //top right footpath
	glVertex2f(1, -0.4);
	glVertex2f(0.2, -0.4);
	glVertex2f(0.2, -0.3);
	glVertex2f(1, -0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 110, 110);      //top right footpath
	glVertex2f(0.24, -0.4);
	glVertex2f(0.14, -0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(0.19, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 148, 146);      //1st building front
	glVertex2f(-0.95, -0.25);
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.95, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(42, 130, 130);      //1st building right
	glVertex2f(-0.7, -0.25);
	glVertex2f(-0.65, -0.2);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.7, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(45, 156, 153);      //1st building top
	glVertex2f(-0.95, 0.35);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.65, 0.4);
	glVertex2f(-0.9, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.9, 0.25);
	glVertex2f(-0.85, 0.25);
	glVertex2f(-0.85, 0.3);
	glVertex2f(-0.9, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.8, 0.25);
	glVertex2f(-0.75, 0.25);
	glVertex2f(-0.75, 0.3);
	glVertex2f(-0.8, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.9, 0.15);
	glVertex2f(-0.85, 0.15);
	glVertex2f(-0.85, 0.2);
	glVertex2f(-0.9, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.8, 0.15);
	glVertex2f(-0.75, 0.15);
	glVertex2f(-0.75, 0.2);
	glVertex2f(-0.8, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, 0.05);
	glVertex2f(-0.85, 0.05);
	glVertex2f(-0.85, 0.1);
	glVertex2f(-0.9, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.8, 0.05);
	glVertex2f(-0.75, 0.05);
	glVertex2f(-0.75, 0.1);
	glVertex2f(-0.8, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.9, 0.0);
	glVertex2f(-0.85, 0.0);
	glVertex2f(-0.85, -0.05);
	glVertex2f(-0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.8, 0.0);
	glVertex2f(-0.75, 0.0);
	glVertex2f(-0.75, -0.05);
	glVertex2f(-0.8, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building window
	glVertex2f(-0.9, -0.1);
	glVertex2f(-0.85, -0.1);
	glVertex2f(-0.85, -0.15);
	glVertex2f(-0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //1st building window
	glVertex2f(-0.8, -0.15);
	glVertex2f(-0.75, -0.15);
	glVertex2f(-0.75, -0.1);
	glVertex2f(-0.8, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //1st building door
	glVertex2f(-0.85, -0.25);
	glVertex2f(-0.8, -0.25);
	glVertex2f(-0.8, -0.18);
	glVertex2f(-0.85, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(46, 124, 148);      //2nd building front
	glVertex2f(-0.63, -0.25);
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.63, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(39, 108, 130);      //2nd building right
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.28, -0.2);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.33, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(53, 148, 176);      //2nd building top
	glVertex2f(-0.63, 0.15);
	glVertex2f(-0.33, 0.15);
	glVertex2f(-0.28, 0.2);
	glVertex2f(-0.58, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //2nd building window
	glVertex2f(-0.58, -0.15);
	glVertex2f(-0.51, -0.15);
	glVertex2f(-0.51, -0.1);
	glVertex2f(-0.58, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.45, -0.15);
	glVertex2f(-0.38, -0.15);
	glVertex2f(-0.38, -0.1);
	glVertex2f(-0.45, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building window
	glVertex2f(-0.58, 0.0);
	glVertex2f(-0.51, 0.0);
	glVertex2f(-0.51, -0.05);
	glVertex2f(-0.58, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //2nd building window
	glVertex2f(-0.45, 0.0);
	glVertex2f(-0.38, 0.0);
	glVertex2f(-0.38, -0.05);
	glVertex2f(-0.45, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //2nd building window
	glVertex2f(-0.58, 0.05);
	glVertex2f(-0.51, 0.05);
	glVertex2f(-0.51, 0.1);
	glVertex2f(-0.58, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //2nd building window
	glVertex2f(-0.45, 0.05);
	glVertex2f(-0.38, 0.05);
	glVertex2f(-0.38, 0.1);
	glVertex2f(-0.45, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //2nd building door
	glVertex2f(-0.51, -0.25);
	glVertex2f(-0.45, -0.25);
	glVertex2f(-0.45, -0.18);
	glVertex2f(-0.51, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(47, 99, 148);      //3rd building
	glVertex2f(0.3, -0.25);
	glVertex2f(0.55, -0.25);
	glVertex2f(0.55, 0.4);
	glVertex2f(0.3, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.35, 0.3);
	glVertex2f(0.4, 0.3);
	glVertex2f(0.4, 0.35);
	glVertex2f(0.35, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.45, 0.3);
	glVertex2f(0.5, 0.3);
	glVertex2f(0.5, 0.35);
	glVertex2f(0.45, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.2);
	glVertex2f(0.4, 0.2);
	glVertex2f(0.4, 0.25);
	glVertex2f(0.35, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.45, 0.2);
	glVertex2f(0.5, 0.2);
	glVertex2f(0.5, 0.25);
	glVertex2f(0.45, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.35, 0.1);
	glVertex2f(0.4, 0.1);
	glVertex2f(0.4, 0.15);
	glVertex2f(0.35, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, 0.1);
	glVertex2f(0.5, 0.1);
	glVertex2f(0.5, 0.15);
	glVertex2f(0.45, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.35, 0.0);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.4, 0.05);
	glVertex2f(0.35, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.45, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, 0.05);
	glVertex2f(0.45, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.35, -0.1);
	glVertex2f(0.4, -0.1);
	glVertex2f(0.4, -0.05);
	glVertex2f(0.35, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building window
	glVertex2f(0.45, -0.1);
	glVertex2f(0.5, -0.1);
	glVertex2f(0.5, -0.05);
	glVertex2f(0.45, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.35, -0.2);
	glVertex2f(0.4, -0.2);
	glVertex2f(0.4, -0.15);
	glVertex2f(0.35, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //3rd building window
	glVertex2f(0.45, -0.2);
	glVertex2f(0.5, -0.2);
	glVertex2f(0.5, -0.15);
	glVertex2f(0.45, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //3rd building door
	glVertex2f(0.45, -0.25);
	glVertex2f(0.4, -0.25);
	glVertex2f(0.4, -0.22);
	glVertex2f(0.45, -0.22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 143, 109);      //4th building
	glVertex2f(0.6, -0.25);
	glVertex2f(0.95, -0.25);
	glVertex2f(0.95, 0.25);
	glVertex2f(0.6, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.65, 0.2);
	glVertex2f(0.7, 0.2);
	glVertex2f(0.7, 0.15);
	glVertex2f(0.65, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.2);
	glVertex2f(0.8, 0.2);
	glVertex2f(0.8, 0.15);
	glVertex2f(0.75, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.9, 0.2);
	glVertex2f(0.85, 0.2);
	glVertex2f(0.85, 0.15);
	glVertex2f(0.9, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.65, 0.1);
	glVertex2f(0.7, 0.1);
	glVertex2f(0.7, 0.05);
	glVertex2f(0.65, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.75, 0.1);
	glVertex2f(0.8, 0.1);
	glVertex2f(0.8, 0.05);
	glVertex2f(0.75, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.9, 0.1);
	glVertex2f(0.85, 0.1);
	glVertex2f(0.85, 0.05);
	glVertex2f(0.9, 0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.65, 0.0);
	glVertex2f(0.7, 0.0);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.65, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.75, 0.0);
	glVertex2f(0.8, 0.0);
	glVertex2f(0.8, -0.05);
	glVertex2f(0.75, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, 0.0);
	glVertex2f(0.85, 0.0);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.9, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.65, -0.1);
	glVertex2f(0.7, -0.1);
	glVertex2f(0.7, -0.15);
	glVertex2f(0.65, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);      //4th building window
	glVertex2f(0.75, -0.1);
	glVertex2f(0.8, -0.1);
	glVertex2f(0.8, -0.15);
	glVertex2f(0.75, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building window
	glVertex2f(0.9, -0.1);
	glVertex2f(0.85, -0.1);
	glVertex2f(0.85, -0.15);
	glVertex2f(0.9, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(209, 209, 209);      //4th building door
	glVertex2f(0.75, -0.25);
	glVertex2f(0.8, -0.25);
	glVertex2f(0.8, -0.18);
	glVertex2f(0.75, -0.18);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(240, 80, 22);      //left car body
	glVertex2f(-0.5, -0.48);
	glVertex2f(-0.2, -0.48);
	glVertex2f(-0.2, -0.46);
	glVertex2f(-0.26, -0.43);
	glVertex2f(-0.3, -0.39);
	glVertex2f(-0.4, -0.39);
	glVertex2f(-0.43, -0.43);
	glVertex2f(-0.5, -0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);      //left car window
	glVertex2f(-0.42, -0.43);
	glVertex2f(-0.36, -0.43);
	glVertex2f(-0.36, -0.4);
	glVertex2f(-0.39, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);      //left car window
	glVertex2f(-0.34, -0.43);
	glVertex2f(-0.28, -0.43);
	glVertex2f(-0.31, -0.4);
	glVertex2f(-0.34, -0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //right car light
	glVertex2f(-0.2, -0.47);
	glVertex2f(-0.12, -0.44);
	glVertex2f(-0.12, -0.5);
	glVertex2f(-0.2, -0.47);
    glEnd();

    int a;                          //left car wheel1
    GLfloat x1=-0.41f; GLfloat y1=-0.48f; GLfloat radius1 =.03f;
	int triangleAmount1 = 20;
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x1, y1);
		for(a = 0; a <= triangleAmount1; a++) {
			glVertex2f(
                x1 + (radius1 * cos(a * twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(a * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	int b;                          //left car wheel2
    GLfloat x2=-0.27f; GLfloat y2=-0.48f; GLfloat radius2 =.03f;
	int triangleAmount2 = 20;
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x2, y2);
		for(b = 0; b <= triangleAmount2; b++) {
			glVertex2f(
                x2 + (radius2 * cos(b * twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(b * twicePi2 / triangleAmount2))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(184, 28, 108);      //right car body
	glVertex2f(0.2, -0.65);
	glVertex2f(0.5, -0.65);
	glVertex2f(0.5, -0.62);
	glVertex2f(0.46, -0.61);
	glVertex2f(0.4, -0.56);
	glVertex2f(0.3, -0.56);
	glVertex2f(0.27, -0.6);
	glVertex2f(0.2, -0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);      //right car window
	glVertex2f(0.34, -0.6);
	glVertex2f(0.28, -0.6);
	glVertex2f(0.31, -0.57);
	glVertex2f(0.34, -0.57);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //right car light
	glVertex2f(0.12, -0.61);
	glVertex2f(0.2, -0.64);
	glVertex2f(0.2, -0.64);
	glVertex2f(0.12, -0.67);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);      //right car window
	glVertex2f(0.42, -0.6);
	glVertex2f(0.36, -0.6);
	glVertex2f(0.36, -0.57);
	glVertex2f(0.39, -0.57);
    glEnd();

    int c;                          //right car wheel
    GLfloat x3=0.29f; GLfloat y3=-0.65f; GLfloat radius3 =.03f;
	int triangleAmount3 = 20;
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x3, y3);
		for(c = 0; c <= triangleAmount3; c++) {
			glVertex2f(
                x3 + (radius3 * cos(c * twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(c * twicePi3 / triangleAmount3))
			);
		}
	glEnd();

	int d;                          //right car wheel
    GLfloat x4=0.42f; GLfloat y4=-0.65f; GLfloat radius4 =.03f;
	int triangleAmount4 = 20;
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
		glVertex2f(x4, y4);
		for(d = 0; d <= triangleAmount4; d++) {
			glVertex2f(
                x4 + (radius4 * cos(d * twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(d * twicePi4 / triangleAmount4))
			);
		}
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.0f, car_position3, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(194, 123, 29);              //top car
	glVertex2f(0.03, -0.35);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.1, -0.17);
	glVertex2f(0.03, -0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(156, 99, 25);              //top car
	glVertex2f(0.03, -0.37);
	glVertex2f(0.1, -0.37);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.03, -0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //top car light
	glVertex2f(0.03, -0.47);
	glVertex2f(0.06, -0.47);
	glVertex2f(0.045, -0.37);
	glVertex2f(0.045, -0.37);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //top car light
	glVertex2f(0.07, -0.47);
	glVertex2f(0.1, -0.47);
	glVertex2f(0.085, -0.37);
	glVertex2f(0.085, -0.37);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);              //top car window
	glVertex2f(0.04, -0.3);
	glVertex2f(0.09, -0.3);
	glVertex2f(0.085, -0.25);
	glVertex2f(0.045, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.0f, car_position4, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(23, 153, 70);              //bottom car
	glVertex2f(-0.1, -0.9);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.03, -0.72);
	glVertex2f(-0.1, -0.72);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(17, 112, 52);              //bottom car
	glVertex2f(-0.1, -0.92);
	glVertex2f(-0.03, -0.92);
	glVertex2f(-0.03, -0.9);
	glVertex2f(-0.1, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //bottom car light
	glVertex2f(-0.045, -0.73);
	glVertex2f(-0.045, -0.73);
	glVertex2f(-0.03, -0.63);
	glVertex2f(-0.06, -0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 130);              //bottom car light
	glVertex2f(-0.085, -0.73);
	glVertex2f(-0.085, -0.73);
	glVertex2f(-0.07, -0.63);
	glVertex2f(-0.1, -0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(181, 181, 181);              //bottom car window
	glVertex2f(-0.09, -0.85);
	glVertex2f(-0.04, -0.85);
	glVertex2f(-0.05, -0.8);
	glVertex2f(-0.08, -0.8);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom left signal
	glVertex2f(-0.2, -0.8);
	glVertex2f(-0.19, -0.8);
	glVertex2f(-0.19, -0.7);
	glVertex2f(-0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom left signal
	glVertex2f(-0.23, -0.7);
	glVertex2f(-0.16, -0.7);
	glVertex2f(-0.16, -0.54);
	glVertex2f(-0.23, -0.54);
    glEnd();

    GLfloat x26=-0.195f; GLfloat y26=-0.57f;GLfloat radius26 =.025f;          //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x26, y26);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x26 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y26 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x27=-0.195f; GLfloat y27=-0.62f;                                   //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x27, y27);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x27 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y27 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x28=-0.195f; GLfloat y28=-0.67f;                                  //bottom left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x28, y28);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x28 + (radius26 * cos(e * twicePi5 / triangleAmount5)),
			    y28 + (radius26 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //bottom right signal
	glVertex2f(0.2, -0.8);
	glVertex2f(0.19, -0.8);
	glVertex2f(0.19, -0.7);
	glVertex2f(0.2, -0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //bottom right signal
	glVertex2f(0.23, -0.7);
	glVertex2f(0.16, -0.7);
	glVertex2f(0.16, -0.54);
	glVertex2f(0.23, -0.54);
    glEnd();

    GLfloat x29=0.195f; GLfloat y29=-0.57f;GLfloat radius29 =.025f;          //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x29, y29);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x29 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y29 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x30=0.195f; GLfloat y30=-0.62f;                                   //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x30, y30);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x30 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y30 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x31=0.195f; GLfloat y31=-0.67f;                                  //bottom right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x31, y31);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x31 + (radius29 * cos(e * twicePi5 / triangleAmount5)),
			    y31 + (radius29 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top left signal
	glVertex2f(-0.2, -0.35);
	glVertex2f(-0.19, -0.35);
	glVertex2f(-0.19, -0.25);
	glVertex2f(-0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top left signal
	glVertex2f(-0.23, -0.25);
	glVertex2f(-0.16, -0.25);
	glVertex2f(-0.16, -0.09);
	glVertex2f(-0.23, -0.09);
    glEnd();

    GLfloat x32=-0.195f; GLfloat y32=-0.12f;GLfloat radius32=.025f;          //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x32, y32);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x32 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y32 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x33=-0.195f; GLfloat y33=-0.17f;                                   //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x33, y33);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x33 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y33 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x34=-0.195f; GLfloat y34=-0.22f;                                  //top left signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x34, y34);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x34 + (radius32 * cos(e * twicePi5 / triangleAmount5)),
			    y34 + (radius32 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);                     //top right signal
	glVertex2f(0.2, -0.35);
	glVertex2f(0.19, -0.35);
	glVertex2f(0.19, -0.25);
	glVertex2f(0.2, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);             //top right signal
	glVertex2f(0.23, -0.25);
	glVertex2f(0.16, -0.25);
	glVertex2f(0.16, -0.09);
	glVertex2f(0.23, -0.09);
    glEnd();

    GLfloat x35=0.195f; GLfloat y35=-0.12f;GLfloat radius35=.025f;          //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x35, y35);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x35 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y35 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x36=0.195f; GLfloat y36=-0.17f;                                   //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(173, 173, 173);
		glVertex2f(x36, y36);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x36 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y36 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x37=0.195f; GLfloat y37=-0.22f;                                  //top right signal

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 255, 0);
		glVertex2f(x37, y37);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x37 + (radius35 * cos(e * twicePi5 / triangleAmount5)),
			    y37 + (radius35 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	glPushMatrix();
	glTranslatef(0.0f,rain_position, 0.0f);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-.90,.95);
	glVertex2f(-.90,.90);
	glVertex2f(-.90,.85);
	glVertex2f(-.90,.80);
	glVertex2f(-.90,.75);
	glVertex2f(-.90,.70);
	glVertex2f(-.90,.65);
	glVertex2f(-.90,.60);
	glVertex2f(-.90,.55);
	glVertex2f(-.90,.50);
	glVertex2f(-.90,.45);
	glVertex2f(-.90,.40);
	glVertex2f(-.90,.35);
	glVertex2f(-.90,.30);
	glVertex2f(-.90,.25);
	glVertex2f(-.90,.20);
	glVertex2f(-.90,.15);
	glVertex2f(-.90,.10);
	glVertex2f(-.90,.05);
	glVertex2f(-.90,.00);
	glVertex2f(-.90,-.05);
	glVertex2f(-.90,-.10);
	glVertex2f(-.90,-.15);
	glVertex2f(-.90,-.20);
	glVertex2f(-.90,-.25);
	glVertex2f(-.90,-.30);
	glVertex2f(-.90,-.35);
	glVertex2f(-.90,-.40);
	glVertex2f(-.90,-.45);
	glVertex2f(-.90,-.50);
	glVertex2f(-.90,-.55);
	glVertex2f(-.90,-.60);
	glVertex2f(-.90,-.65);
	glVertex2f(-.90,-.70);
	glVertex2f(-.90,-.75);
	glVertex2f(-.90,-.80);
	glVertex2f(-.90,-.85);
	glVertex2f(-.90,-.90);
	//glVertex2f(-.90,-.95);
	//glVertex2f(-.80,.95);
	glVertex2f(-.80,.90);
	glVertex2f(-.80,.85);
	glVertex2f(-.80,.80);
	glVertex2f(-.80,.75);
	glVertex2f(-.80,.70);
	glVertex2f(-.80,.65);
	glVertex2f(-.80,.60);
	glVertex2f(-.80,.55);
	glVertex2f(-.80,.50);
	glVertex2f(-.80,.45);
	glVertex2f(-.80,.40);
	glVertex2f(-.80,.35);
	glVertex2f(-.80,.30);
	glVertex2f(-.80,.25);
	glVertex2f(-.80,.20);
	glVertex2f(-.80,.15);
	glVertex2f(-.80,.10);
	glVertex2f(-.80,.05);
	glVertex2f(-.80,.00);
	glVertex2f(-.80,-.05);
	glVertex2f(-.80,-.10);
	glVertex2f(-.80,-.15);
	glVertex2f(-.80,-.20);
	glVertex2f(-.80,-.25);
	glVertex2f(-.80,-.30);
	glVertex2f(-.80,-.35);
	glVertex2f(-.80,-.40);
	glVertex2f(-.80,-.45);
	glVertex2f(-.80,-.50);
	glVertex2f(-.80,-.55);
	glVertex2f(-.80,-.60);
	glVertex2f(-.80,-.65);
	glVertex2f(-.80,-.70);
	glVertex2f(-.80,-.75);
	glVertex2f(-.80,-.80);
	glVertex2f(-.80,-.85);
	glVertex2f(-.80,-.90);
	glVertex2f(-.80,-.95);
	glVertex2f(-.70,.95);
	glVertex2f(-.70,.90);
	glVertex2f(-.70,.85);
	glVertex2f(-.70,.80);
	glVertex2f(-.70,.75);
	glVertex2f(-.70,.70);
	glVertex2f(-.70,.65);
	glVertex2f(-.70,.60);
	glVertex2f(-.70,.55);
	glVertex2f(-.70,.50);
	glVertex2f(-.70,.45);
	glVertex2f(-.70,.40);
	glVertex2f(-.70,.35);
	glVertex2f(-.70,.30);
	glVertex2f(-.70,.25);
	glVertex2f(-.70,.20);
	glVertex2f(-.70,.15);
	glVertex2f(-.70,.10);
	glVertex2f(-.70,.05);
	glVertex2f(-.70,.00);
	glVertex2f(-.70,-.05);
	glVertex2f(-.70,-.10);
	glVertex2f(-.70,-.15);
	glVertex2f(-.70,-.20);
	glVertex2f(-.70,-.25);
	glVertex2f(-.70,-.30);
	glVertex2f(-.70,-.35);
	glVertex2f(-.70,-.40);
	glVertex2f(-.70,-.45);
	glVertex2f(-.70,-.50);
	glVertex2f(-.70,-.55);
	glVertex2f(-.70,-.60);
	glVertex2f(-.70,-.65);
	glVertex2f(-.70,-.70);
	glVertex2f(-.70,-.75);
	glVertex2f(-.70,-.80);
	glVertex2f(-.70,-.85);
	glVertex2f(-.70,-.90);
	//glVertex2f(-.70,-.95);
	//glVertex2f(-.60,.95);
	glVertex2f(-.60,.90);
	glVertex2f(-.60,.85);
	glVertex2f(-.60,.80);
	glVertex2f(-.60,.75);
	glVertex2f(-.60,.70);
	glVertex2f(-.60,.65);
	glVertex2f(-.60,.60);
	glVertex2f(-.60,.55);
	glVertex2f(-.60,.50);
	glVertex2f(-.60,.45);
	glVertex2f(-.60,.40);
	glVertex2f(-.60,.35);
	glVertex2f(-.60,.30);
	glVertex2f(-.60,.25);
	glVertex2f(-.60,.20);
	glVertex2f(-.60,.15);
	glVertex2f(-.60,.10);
	glVertex2f(-.60,.05);
	glVertex2f(-.60,.00);
	glVertex2f(-.60,-.05);
	glVertex2f(-.60,-.10);
	glVertex2f(-.60,-.15);
	glVertex2f(-.60,-.20);
	glVertex2f(-.60,-.25);
	glVertex2f(-.60,-.30);
	glVertex2f(-.60,-.35);
	glVertex2f(-.60,-.40);
	glVertex2f(-.60,-.45);
	glVertex2f(-.60,-.50);
	glVertex2f(-.60,-.55);
	glVertex2f(-.60,-.60);
	glVertex2f(-.60,-.65);
	glVertex2f(-.60,-.70);
	glVertex2f(-.60,-.75);
	glVertex2f(-.60,-.80);
	glVertex2f(-.60,-.85);
	glVertex2f(-.60,-.90);
	glVertex2f(-.60,-.95);
    glVertex2f(-.50,.95);
	glVertex2f(-.50,.90);
	glVertex2f(-.50,.85);
	glVertex2f(-.50,.80);
	glVertex2f(-.50,.75);
	glVertex2f(-.50,.70);
	glVertex2f(-.50,.65);
	glVertex2f(-.50,.60);
	glVertex2f(-.50,.55);
	glVertex2f(-.50,.50);
	glVertex2f(-.50,.45);
	glVertex2f(-.50,.40);
	glVertex2f(-.50,.35);
	glVertex2f(-.50,.30);
	glVertex2f(-.50,.25);
	glVertex2f(-.50,.20);
	glVertex2f(-.50,.15);
	glVertex2f(-.50,.10);
	glVertex2f(-.50,.05);
	glVertex2f(-.50,.00);
	glVertex2f(-.50,-.05);
	glVertex2f(-.50,-.10);
	glVertex2f(-.50,-.15);
	glVertex2f(-.50,-.20);
	glVertex2f(-.50,-.25);
	glVertex2f(-.50,-.30);
	glVertex2f(-.50,-.35);
	glVertex2f(-.50,-.40);
	glVertex2f(-.50,-.45);
	glVertex2f(-.50,-.50);
	glVertex2f(-.50,-.55);
	glVertex2f(-.50,-.60);
	glVertex2f(-.50,-.65);
	glVertex2f(-.50,-.70);
	glVertex2f(-.50,-.75);
	glVertex2f(-.50,-.80);
	glVertex2f(-.50,-.85);
	glVertex2f(-.50,-.90);
	//glVertex2f(-.50,-.95);
	//glVertex2f(-.40,.95);
	glVertex2f(-.40,.90);
	glVertex2f(-.40,.85);
	glVertex2f(-.40,.80);
	glVertex2f(-.40,.75);
	glVertex2f(-.40,.70);
	glVertex2f(-.40,.65);
	glVertex2f(-.40,.60);
	glVertex2f(-.40,.55);
	glVertex2f(-.40,.50);
	glVertex2f(-.40,.45);
	glVertex2f(-.40,.40);
	glVertex2f(-.40,.35);
	glVertex2f(-.40,.30);
	glVertex2f(-.40,.25);
	glVertex2f(-.40,.20);
	glVertex2f(-.40,.15);
	glVertex2f(-.40,.10);
	glVertex2f(-.40,.05);
	glVertex2f(-.40,.00);
	glVertex2f(-.40,-.05);
	glVertex2f(-.40,-.10);
	glVertex2f(-.40,-.15);
	glVertex2f(-.40,-.20);
	glVertex2f(-.40,-.25);
	glVertex2f(-.40,-.30);
	glVertex2f(-.40,-.35);
	glVertex2f(-.40,-.40);
	glVertex2f(-.40,-.45);
	glVertex2f(-.40,-.50);
	glVertex2f(-.40,-.55);
	glVertex2f(-.40,-.60);
	glVertex2f(-.40,-.65);
	glVertex2f(-.40,-.70);
	glVertex2f(-.40,-.75);
	glVertex2f(-.40,-.80);
    glVertex2f(-.40,-.85);
	glVertex2f(-.40,-.90);
	glVertex2f(-.40,-.95);
	glVertex2f(-.30,.95);
	glVertex2f(-.30,.90);
    glVertex2f(-.30,.95);
	glVertex2f(-.30,.95);
	glVertex2f(-.30,.90);
	glVertex2f(-.30,.85);
	glVertex2f(-.30,.80);
	glVertex2f(-.30,.75);
	glVertex2f(-.30,.70);
	glVertex2f(-.30,.65);
	glVertex2f(-.30,.60);
	glVertex2f(-.30,.55);
	glVertex2f(-.30,.50);
	glVertex2f(-.30,.45);
	glVertex2f(-.30,.40);
	glVertex2f(-.30,.35);
	glVertex2f(-.30,.30);
	glVertex2f(-.30,.25);
	glVertex2f(-.30,.20);
	glVertex2f(-.30,.15);
	glVertex2f(-.30,.10);
	glVertex2f(-.30,.05);
	glVertex2f(-.30,.00);
	glVertex2f(-.30,-.05);
	glVertex2f(-.30,-.10);
	glVertex2f(-.30,-.15);
	glVertex2f(-.30,-.20);
	glVertex2f(-.30,-.25);
	glVertex2f(-.30,-.30);
	glVertex2f(-.30,-.35);
	glVertex2f(-.30,-.40);
	glVertex2f(-.30,-.45);
	glVertex2f(-.30,-.50);
	glVertex2f(-.30,-.55);
	glVertex2f(-.30,-.60);
	glVertex2f(-.30,-.65);
	glVertex2f(-.30,-.70);
	glVertex2f(-.30,-.75);
	glVertex2f(-.30,-.80);
	glVertex2f(-.30,-.95);
	glVertex2f(-.30,-.90);
	glVertex2f(-.30,-.85);
    glVertex2f(-.30,-.85);
	glVertex2f(-.30,-.90);
	//glVertex2f(-.30,-.95);
	//glVertex2f(-.20,.95);
	glVertex2f(-.20,.90);
	glVertex2f(-.20,.85);
	glVertex2f(-.20,.80);
	glVertex2f(-.20,.75);
	glVertex2f(-.20,.70);
	glVertex2f(-.20,.65);
	glVertex2f(-.20,.60);
	glVertex2f(-.20,.55);
	glVertex2f(-.20,.50);
	glVertex2f(-.20,.45);
	glVertex2f(-.20,.40);
	glVertex2f(-.20,.35);
	glVertex2f(-.20,.30);
	glVertex2f(-.20,.25);
	glVertex2f(-.20,.20);
	glVertex2f(-.20,.15);
	glVertex2f(-.20,.10);
	glVertex2f(-.20,.05);
	glVertex2f(-.20,.00);
	glVertex2f(-.20,-.05);
	glVertex2f(-.20,-.10);
	glVertex2f(-.20,-.15);
	glVertex2f(-.20,-.20);
	glVertex2f(-.20,-.25);
	glVertex2f(-.20,-.30);
	glVertex2f(-.20,-.35);
	glVertex2f(-.20,-.40);
	glVertex2f(-.20,-.45);
	glVertex2f(-.20,-.50);
	glVertex2f(-.20,-.55);
	glVertex2f(-.20,-.60);
	glVertex2f(-.20,-.65);
	glVertex2f(-.20,-.70);
	glVertex2f(-.20,-.75);
	glVertex2f(-.20,-.80);
	glVertex2f(-.20,-.85);
	glVertex2f(-.20,-.90);
	glVertex2f(-.20,-.95);
	glVertex2f(-.10,.95);
	glVertex2f(-.10,.90);
	glVertex2f(-.10,.85);
	glVertex2f(-.10,.80);
	glVertex2f(-.10,.75);
	glVertex2f(-.10,.70);
	glVertex2f(-.10,.65);
	glVertex2f(-.10,.60);
	glVertex2f(-.10,.55);
	glVertex2f(-.10,.50);
	glVertex2f(-.10,.45);
	glVertex2f(-.10,.40);
	glVertex2f(-.10,.35);
	glVertex2f(-.10,.30);
	glVertex2f(-.10,.25);
	glVertex2f(-.10,.20);
	glVertex2f(-.10,.15);
	glVertex2f(-.10,.10);
	glVertex2f(-.10,.05);
	glVertex2f(-.10,.00);
	glVertex2f(-.10,-.05);
	glVertex2f(-.10,-.10);
	glVertex2f(-.10,-.15);
	glVertex2f(-.10,-.20);
	glVertex2f(-.10,-.25);
	glVertex2f(-.10,-.30);
	glVertex2f(-.10,-.35);
	glVertex2f(-.10,-.40);
	glVertex2f(-.10,-.45);
	glVertex2f(-.10,-.50);
	glVertex2f(-.10,-.55);
	glVertex2f(-.10,-.60);
	glVertex2f(-.10,-.65);
	glVertex2f(-.10,-.70);
	glVertex2f(-.10,-.75);
	glVertex2f(-.10,-.80);
    glVertex2f(-.10,-.85);
	glVertex2f(-.10,-.90);
	//glVertex2f(-.10,-.95);
	//glVertex2f(.00,.95);
	glVertex2f(.00,.90);
	glVertex2f(.00,.85);
	glVertex2f(.00,.80);
	glVertex2f(.00,.75);
	glVertex2f(.00,.70);
	glVertex2f(.00,.65);
	glVertex2f(.00,.60);
	glVertex2f(.00,.55);
	glVertex2f(.00,.50);
	glVertex2f(.00,.45);
	glVertex2f(.00,.40);
	glVertex2f(.00,.35);
	glVertex2f(.00,.30);
	glVertex2f(.00,.25);
	glVertex2f(.00,.20);
	glVertex2f(.00,.15);
	glVertex2f(.00,.10);
	glVertex2f(.00,.05);
	glVertex2f(.00,.00);
	glVertex2f(.00,-.05);
	glVertex2f(.00,-.10);
	glVertex2f(.00,-.15);
	glVertex2f(.00,-.20);
	glVertex2f(.00,-.25);
	glVertex2f(.00,-.30);
	glVertex2f(.00,-.35);
	glVertex2f(.00,-.40);
	glVertex2f(.00,-.45);
	glVertex2f(.00,-.50);
	glVertex2f(.00,-.55);
	glVertex2f(.00,-.60);
	glVertex2f(.00,-.65);
	glVertex2f(.00,-.70);
	glVertex2f(.00,-.75);
	glVertex2f(.00,-.80);
	glVertex2f(.00,-.85);
	glVertex2f(.00,-.90);
	glVertex2f(.00,-.95);
	glVertex2f(.10,.95);
	glVertex2f(.10,.90);
	glVertex2f(.10,.85);
	glVertex2f(.10,.80);
	glVertex2f(.10,.75);
	glVertex2f(.10,.70);
	glVertex2f(.10,.65);
	glVertex2f(.10,.60);
	glVertex2f(.10,.55);
	glVertex2f(.10,.50);
	glVertex2f(.10,.45);
	glVertex2f(.10,.40);
	glVertex2f(.10,.35);
	glVertex2f(.10,.30);
	glVertex2f(.10,.25);
	glVertex2f(.10,.20);
	glVertex2f(.10,.15);
	glVertex2f(.10,.10);
	glVertex2f(.10,.05);
	glVertex2f(.10,.00);
	glVertex2f(.10,-.05);
	glVertex2f(.10,-.10);
	glVertex2f(.10,-.15);
	glVertex2f(.10,-.20);
	glVertex2f(.10,-.25);
	glVertex2f(.10,-.30);
	glVertex2f(.10,-.35);
	glVertex2f(.10,-.40);
	glVertex2f(.10,-.45);
	glVertex2f(.10,-.50);
	glVertex2f(.10,-.55);
	glVertex2f(.10,-.60);
	glVertex2f(.10,-.65);
	glVertex2f(.10,-.70);
	glVertex2f(.10,-.75);
	glVertex2f(.10,-.80);
	glVertex2f(.10,-.85);
	glVertex2f(.10,-.90);
	//glVertex2f(.10,-.95);
	//glVertex2f(.20,.95);
	glVertex2f(.20,.90);
	glVertex2f(.20,.85);
	glVertex2f(.20,.80);
	glVertex2f(.20,.75);
	glVertex2f(.20,.70);
	glVertex2f(.20,.65);
	glVertex2f(.20,.60);
	glVertex2f(.20,.55);
	glVertex2f(.20,.50);
	glVertex2f(.20,.45);
	glVertex2f(.20,.40);
	glVertex2f(.20,.35);
	glVertex2f(.20,.30);
	glVertex2f(.20,.25);
	glVertex2f(.20,.20);
	glVertex2f(.20,.15);
	glVertex2f(.20,.10);
	glVertex2f(.20,.05);
	glVertex2f(.20,.00);
	glVertex2f(.20,-.05);
	glVertex2f(.20,-.10);
	glVertex2f(.20,-.15);
	glVertex2f(.20,-.20);
	glVertex2f(.20,-.25);
	glVertex2f(.20,-.30);
	glVertex2f(.20,-.35);
	glVertex2f(.20,-.40);
	glVertex2f(.20,-.45);
	glVertex2f(.20,-.50);
	glVertex2f(.20,-.55);
	glVertex2f(.20,-.60);
	glVertex2f(.20,-.65);
	glVertex2f(.20,-.70);
	glVertex2f(.20,-.75);
	glVertex2f(.20,-.80);
	glVertex2f(.20,-.85);
	glVertex2f(.20,-.90);
	glVertex2f(.20,-.95);
	glVertex2f(.30,.95);
	glVertex2f(.30,.90);
	glVertex2f(.30,.85);
	glVertex2f(.30,.80);
	glVertex2f(.30,.75);
	glVertex2f(.30,.70);
	glVertex2f(.30,.65);
	glVertex2f(.30,.60);
	glVertex2f(.30,.55);
	glVertex2f(.30,.50);
	glVertex2f(.30,.45);
	glVertex2f(.30,.40);
	glVertex2f(.30,.35);
	glVertex2f(.30,.30);
	glVertex2f(.30,.25);
	glVertex2f(.30,.20);
	glVertex2f(.30,.15);
	glVertex2f(.30,.10);
	glVertex2f(.30,.05);
	glVertex2f(.30,.00);
	glVertex2f(.30,-.05);
	glVertex2f(.30,-.10);
	glVertex2f(.30,-.15);
	glVertex2f(.30,-.20);
	glVertex2f(.30,-.25);
	glVertex2f(.30,-.30);
	glVertex2f(.30,-.35);
	glVertex2f(.30,-.40);
	glVertex2f(.30,-.45);
	glVertex2f(.30,-.50);
	glVertex2f(.30,-.55);
	glVertex2f(.30,-.60);
	glVertex2f(.30,-.65);
	glVertex2f(.30,-.70);
	glVertex2f(.30,-.75);
	glVertex2f(.30,-.80);
	glVertex2f(.30,-.85);
	glVertex2f(.30,-.90);
	//glVertex2f(.30,-.95);
	//glVertex2f(.40,.95);
	glVertex2f(.40,.90);
	glVertex2f(.40,.85);
	glVertex2f(.40,.80);
	glVertex2f(.40,.75);
	glVertex2f(.40,.70);
	glVertex2f(.40,.65);
	glVertex2f(.40,.60);
	glVertex2f(.40,.55);
	glVertex2f(.40,.50);
	glVertex2f(.40,.45);
	glVertex2f(.40,.40);
	glVertex2f(.40,.35);
	glVertex2f(.40,.30);
	glVertex2f(.40,.25);
	glVertex2f(.40,.20);
	glVertex2f(.40,.15);
	glVertex2f(.40,.10);
	glVertex2f(.40,.05);
	glVertex2f(.40,.00);
	glVertex2f(.40,-.05);
	glVertex2f(.40,-.10);
	glVertex2f(.40,-.15);
	glVertex2f(.40,-.20);
	glVertex2f(.40,-.25);
	glVertex2f(.40,-.30);
	glVertex2f(.40,-.35);
	glVertex2f(.40,-.40);
	glVertex2f(.40,-.45);
	glVertex2f(.40,-.50);
	glVertex2f(.40,-.55);
	glVertex2f(.40,-.60);
	glVertex2f(.40,-.65);
	glVertex2f(.40,-.70);
	glVertex2f(.40,-.75);
	glVertex2f(.40,-.80);
	glVertex2f(.40,-.85);
	glVertex2f(.40,-.90);
	glVertex2f(.40,-.95);
	glVertex2f(.50,.90);
	glVertex2f(.50,.85);
	glVertex2f(.50,.80);
	glVertex2f(.50,.75);
	glVertex2f(.50,.70);
	glVertex2f(.50,.65);
	glVertex2f(.50,.60);
	glVertex2f(.50,.55);
	glVertex2f(.50,.50);
	glVertex2f(.50,.45);
	glVertex2f(.50,.40);
	glVertex2f(.50,.35);
	glVertex2f(.50,.30);
	glVertex2f(.50,.25);
	glVertex2f(.50,.20);
	glVertex2f(.50,.15);
	glVertex2f(.50,.10);
	glVertex2f(.50,.05);
	glVertex2f(.50,.00);
	glVertex2f(.50,-.05);
	glVertex2f(.50,-.10);
	glVertex2f(.50,-.15);
	glVertex2f(.50,-.20);
	glVertex2f(.50,-.25);
	glVertex2f(.50,-.30);
	glVertex2f(.50,-.35);
	glVertex2f(.50,-.40);
	glVertex2f(.50,-.45);
	glVertex2f(.50,-.50);
	glVertex2f(.50,-.55);
	glVertex2f(.50,-.60);
	glVertex2f(.50,-.65);
	glVertex2f(.50,-.70);
	glVertex2f(.50,-.75);
	glVertex2f(.50,-.80);
	glVertex2f(.50,-.85);
	glVertex2f(.50,-.90);
	glVertex2f(.50,-.95);
	glVertex2f(.60,.95);
	glVertex2f(.60,.90);
	glVertex2f(.60,.85);
	glVertex2f(.60,.80);
	glVertex2f(.60,.75);
	glVertex2f(.60,.70);
	glVertex2f(.60,.65);
	glVertex2f(.60,.60);
	glVertex2f(.60,.55);
	glVertex2f(.60,.50);
	glVertex2f(.60,.45);
	glVertex2f(.60,.40);
	glVertex2f(.60,.35);
	glVertex2f(.60,.30);
	glVertex2f(.60,.25);
	glVertex2f(.60,.20);
	glVertex2f(.60,.15);
	glVertex2f(.60,.10);
	glVertex2f(.60,.05);
	glVertex2f(.60,.00);
	glVertex2f(.60,-.05);
	glVertex2f(.60,-.10);
	glVertex2f(.60,-.15);
	glVertex2f(.60,-.20);
	glVertex2f(.60,-.25);
	glVertex2f(.60,-.30);
	glVertex2f(.60,-.35);
	glVertex2f(.60,-.40);
	glVertex2f(.60,-.45);
	glVertex2f(.60,-.50);
	glVertex2f(.60,-.55);
	glVertex2f(.60,-.60);
	glVertex2f(.60,-.65);
	glVertex2f(.60,-.70);
	glVertex2f(.60,-.75);
	glVertex2f(.60,-.80);
	glVertex2f(.60,-.85);
	glVertex2f(.60,-.90);
	//glVertex2f(.60,-.95);
	//glVertex2f(.70,.95);
	glVertex2f(.70,.90);
	glVertex2f(.70,.85);
	glVertex2f(.70,.80);
	glVertex2f(.70,.75);
	glVertex2f(.70,.70);
	glVertex2f(.70,.65);
	glVertex2f(.70,.60);
	glVertex2f(.70,.55);
	glVertex2f(.70,.50);
	glVertex2f(.70,.45);
	glVertex2f(.70,.40);
	glVertex2f(.70,.35);
	glVertex2f(.70,.30);
	glVertex2f(.70,.25);
	glVertex2f(.70,.20);
	glVertex2f(.70,.15);
	glVertex2f(.70,.10);
	glVertex2f(.70,.05);
	glVertex2f(.70,.00);
	glVertex2f(.70,-.05);
	glVertex2f(.70,-.10);
	glVertex2f(.70,-.15);
	glVertex2f(.70,-.20);
	glVertex2f(.70,-.25);
	glVertex2f(.70,-.30);
	glVertex2f(.70,-.35);
	glVertex2f(.70,-.40);
	glVertex2f(.70,-.45);
	glVertex2f(.70,-.50);
	glVertex2f(.70,-.55);
	glVertex2f(.70,-.60);
	glVertex2f(.70,-.65);
	glVertex2f(.70,-.70);
	glVertex2f(.70,-.75);
	glVertex2f(.70,-.80);
	glVertex2f(.70,-.85);
	glVertex2f(.70,-.90);
	glVertex2f(.70,-.95);
	glVertex2f(.80,.95);
	glVertex2f(.80,.90);
	glVertex2f(.80,.85);
	glVertex2f(.80,.80);
	glVertex2f(.80,.75);
	glVertex2f(.80,.70);
	glVertex2f(.80,.65);
	glVertex2f(.80,.60);
	glVertex2f(.80,.55);
	glVertex2f(.80,.50);
	glVertex2f(.80,.45);
	glVertex2f(.80,.40);
	glVertex2f(.80,.35);
	glVertex2f(.80,.30);
	glVertex2f(.80,.25);
	glVertex2f(.80,.20);
	glVertex2f(.80,.15);
	glVertex2f(.80,.10);
	glVertex2f(.80,.05);
	glVertex2f(.80,.00);
	glVertex2f(.80,-.05);
	glVertex2f(.80,-.10);
	glVertex2f(.80,-.15);
	glVertex2f(.80,-.20);
	glVertex2f(.80,-.25);
	glVertex2f(.80,-.30);
	glVertex2f(.80,-.35);
	glVertex2f(.80,-.40);
	glVertex2f(.80,-.45);
	glVertex2f(.80,-.50);
	glVertex2f(.80,-.55);
	glVertex2f(.80,-.60);
	glVertex2f(.80,-.65);
	glVertex2f(.80,-.70);
	glVertex2f(.80,-.75);
	glVertex2f(.80,-.80);
	glVertex2f(.80,-.85);
	glVertex2f(.80,-.90);
	//glVertex2f(.80,-.95);
	//glVertex2f(.90,.95);
	glVertex2f(.90,.90);
	glVertex2f(.90,.85);
	glVertex2f(.90,.80);
	glVertex2f(.90,.75);
	glVertex2f(.90,.70);
	glVertex2f(.90,.65);
	glVertex2f(.90,.60);
	glVertex2f(.90,.55);
	glVertex2f(.90,.50);
	glVertex2f(.90,.45);
	glVertex2f(.90,.40);
	glVertex2f(.90,.35);
	glVertex2f(.90,.30);
	glVertex2f(.90,.25);
	glVertex2f(.90,.20);
	glVertex2f(.90,.15);
	glVertex2f(.90,.10);
	glVertex2f(.90,.05);
	glVertex2f(.90,.00);
	glVertex2f(.90,-.05);
	glVertex2f(.90,-.10);
	glVertex2f(.90,-.15);
	glVertex2f(.90,-.20);
	glVertex2f(.90,-.25);
	glVertex2f(.90,-.30);
	glVertex2f(.90,-.35);
	glVertex2f(.90,-.40);
	glVertex2f(.90,-.45);
	glVertex2f(.90,-.50);
	glVertex2f(.90,-.55);
	glVertex2f(.90,-.60);
	glVertex2f(.90,-.65);
	glVertex2f(.90,-.70);
	glVertex2f(.90,-.75);
	glVertex2f(.90,-.80);
	glVertex2f(.90,-.85);
	glVertex2f(.90,-.90);
	glVertex2f(.90,-.95);
	glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);glutTimerFunc(1500,city_night1,0);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x14=-0.61f; GLfloat y14=-0.56f;GLfloat radius14 =.04f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(252, 235, 45);
		glVertex2f(x14, y14);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x14 + (radius14 * cos(e * twicePi5 / triangleAmount5)),
			    y14 + (radius14 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x15=-0.71f; GLfloat y15=-0.61f;GLfloat radius15 =.03f;          //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x15, y15);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x15 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y15 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x16=-0.51f; GLfloat y16=-0.61f;                                  //bottom left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x16, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x16 + (radius15 * cos(e * twicePi5 / triangleAmount5)),
			    y16 + (radius15 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //bottom right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x17=0.61f; GLfloat y17=-0.56f;GLfloat radius17 =.04f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(252, 235, 45);
		glVertex2f(x17, y17);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x17 + (radius17 * cos(e * twicePi5 / triangleAmount5)),
			    y17 + (radius17 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x18=0.71f; GLfloat y18=-0.61f;GLfloat radius18 =.03f;          //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x18, y18);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x18 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y18 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x19=0.51f; GLfloat y19=-0.61f;                                  //bottom right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x19, y19);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x19 + (radius18 * cos(e * twicePi5 / triangleAmount5)),
			    y19 + (radius18 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


    glScaled(0.6, 0.6, 0);
    glTranslated(0.35, 0.45, 0);
    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top right lamppost
	glVertex2f(0.6, -0.6);
	glVertex2f(0.62, -0.6);
	glVertex2f(0.62, -0.9);
	glVertex2f(0.6, -0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top right lamppost
	glVertex2f(0.5, -0.71);
	glVertex2f(0.72, -0.71);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.5, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top right lamppost
	glVertex2f(0.52, -0.64);
	glVertex2f(0.5, -0.64);
	glVertex2f(0.5, -0.69);
	glVertex2f(0.52, -0.69);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top right lamppost
	glVertex2f(0.7, -0.64);
	glVertex2f(0.72, -0.64);
	glVertex2f(0.72, -0.69);
	glVertex2f(0.7, -0.69);
    glEnd();

    GLfloat x20=0.61f; GLfloat y20=-0.56f;GLfloat radius20 =.04f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(252, 235, 45);
		glVertex2f(x20, y20);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x20 + (radius20 * cos(e * twicePi5 / triangleAmount5)),
			    y20 + (radius20 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x21=0.71f; GLfloat y21=-0.61f;GLfloat radius21 =.03f;          //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x21, y21);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x21 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y21 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x22=0.51f; GLfloat y22=-0.61f;                                  //top right lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x22, y22);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x22 + (radius21 * cos(e * twicePi5 / triangleAmount5)),
			    y22 + (radius21 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	//glScaled(0.7, 0.7, 0);
    glTranslated(-0.85, 0.0, 0);
	glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top left lamppost
	glVertex2f(-0.62, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.6);
	glVertex2f(-0.62, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.5, -0.71);
	glVertex2f(-0.72, -0.71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top left lamppost
	glVertex2f(-0.5, -0.69);
	glVertex2f(-0.52, -0.69);
	glVertex2f(-0.52, -0.64);
	glVertex2f(-0.5, -0.64);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(173, 173, 173);             //top left lamppost
	glVertex2f(-0.72, -0.69);
	glVertex2f(-0.7, -0.69);
	glVertex2f(-0.7, -0.64);
	glVertex2f(-0.72, -0.64);
    glEnd();

    GLfloat x23=-0.61f; GLfloat y23=-0.56f;GLfloat radius23 =.04f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(252, 235, 45);
		glVertex2f(x23, y23);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x23 + (radius23 * cos(e * twicePi5 / triangleAmount5)),
			    y23 + (radius23 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

	GLfloat x24=-0.71f; GLfloat y24=-0.61f;GLfloat radius24 =.03f;          //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x24, y24);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x24 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y24 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

    GLfloat x25=-0.51f; GLfloat y25=-0.61f;                                  //top left lamppost

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 130);
		glVertex2f(x25, y16);
		for(e = 0; e <= triangleAmount5; e++) {
			glVertex2f(
                x25 + (radius24 * cos(e * twicePi5 / triangleAmount5)),
			    y25 + (radius24 * sin(e * twicePi5 / triangleAmount5))
			);
		}
	glEnd();



    glutTimerFunc(5500,day_rain1,0);

	glFlush();  // Render now
}

void night_rain1(int val){
     glutDisplayFunc(night_rain);
}


void handleKeypress(unsigned char key, int x, int y) {

    switch (key) {
		case 'r':
			glutDisplayFunc(day_rain);
			glutPostRedisplay();
            PlaySound("rain.wav",  NULL, SND_ASYNC|SND_FILENAME);
			break;
		case 'd':
			glutDisplayFunc(city_day);
			glutPostRedisplay();
            PlaySound("day.wav",  NULL, SND_ASYNC|SND_FILENAME);
			break;
    glutPostRedisplay();
        }
}

void SpecialInput(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            cloud_speed = 0.1f;
            plane_speed = 0.1f;
            bird_speed = 0.05f;
            glutTimerFunc(100, update4, 0);
            glutTimerFunc(100, update5, 0);
            glutTimerFunc(100, update5, 0);
            break;
        case GLUT_KEY_DOWN:
            cloud_speed = 0.01f;
            plane_speed = 0.05f;
            bird_speed = 0.05;
            break;
        case GLUT_KEY_LEFT:
            glutPostRedisplay();
            cloud_speed = 0.1f;
            plane_speed = 0.1f;
            bird_speed = 0.05f;
            glutTimerFunc(100, update4, 0);
            glutTimerFunc(100, update5, 0);
            glutTimerFunc(100, update5, 0);
            break;
        case GLUT_KEY_RIGHT:
            cloud_speed = 0.01f;
            plane_speed = 0.05f;
            bird_speed = 0.05;
            break;
    }
glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("City View");
    glutDisplayFunc(city_day);
    glutIdleFunc(Idle);
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(SpecialInput);
    glutTimerFunc(100, update1, 0);
	glutTimerFunc(100, update2, 0);
	glutTimerFunc(100, update3, 0);
	glutTimerFunc(100, update4, 0);
	glutTimerFunc(100, update5, 0);
	glutTimerFunc(100, update6, 0);
	glutTimerFunc(100, update7, 0);
	glutTimerFunc(100, update8, 0);
	glutTimerFunc(100, update9, 0);
	glutTimerFunc(100, update10, 0);

    PlaySound("day.wav",  NULL, SND_ASYNC|SND_FILENAME);
    glutMainLoop();
    return 0;
}
