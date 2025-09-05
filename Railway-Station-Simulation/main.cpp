#include <windows.h>  // for MS Windows
#include <GL/glu.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
# define PI           3.14159265358979323846


void morning(int value);
void night(int value);

static int time=0;
GLfloat j=0.2;
GLfloat position = 0.0f;
GLfloat positionz = 0.0f;
GLfloat positionr = 0.0f;
GLfloat speed = 0.02f;
GLfloat Bspeed=0.006f;
GLfloat speedr=0.6f;
GLfloat positionm = 0.0f;
GLfloat speedm = 0.007f;


//moving animation

//for train
void update1(int value) {
    if(position <-3.0)
        position = 1.0f;
    position -= speed;
	glutPostRedisplay();
	glutTimerFunc(100, update1, 0);
}
void update2(int value) {
if(position > 3.0)
        position = -1.0f;
    position += speed;
	glutPostRedisplay();
	glutTimerFunc(100, update2, 0);
}

//for bird
void update3(int value) {
        if(positionz <-1.0)
        positionz = 1.0f;
    positionz -= Bspeed;
	glutPostRedisplay();
	glutTimerFunc(100, update3, 0);
}
void update4(int value) {
        if(positionz >2.0) //for bird
        positionz = -1.0f;
    positionz += Bspeed;
	glutPostRedisplay();
	glutTimerFunc(100, update4, 0);
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

//for mouse and button
//cloud
void update5(int value) {

    if(positionm <-1.0)
        positionm = 1.2f;

    positionm -= speedm;

	glutPostRedisplay();


	glutTimerFunc(100, update5, 0);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
			speedm += 0.1f;
			}

			if (button == GLUT_RIGHT_BUTTON)
	{
			speedm -= 0.1f;
			}
	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'a':
    speedm = 0.0f;
    break;
case 'w':
    speedm = 0.1f;
    break;

case 'm':
    glutTimerFunc(100,morning,0);
    break;

case 'n':
    glutTimerFunc(100,night,0);
    break;

glutPostRedisplay();

	}
}

//key control animation
void SpecialInput(int key, int x, int y)
{  switch(key)
{
case GLUT_KEY_UP:
        glutTimerFunc(100, update4, 0);
break;
case GLUT_KEY_DOWN:
        glutTimerFunc(100, update3, 0);
break;
case GLUT_KEY_LEFT:
    glutTimerFunc(100, update1, 0);
break;
case GLUT_KEY_RIGHT:
    glutTimerFunc(100, update2, 0);
break;
}
glutPostRedisplay();}


void drawText(float x, float y, float z, const char* string) {
    glRasterPos3f(x, y, z);
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
}

void drawText1(float x, float y, float z, const char* string) {
    glRasterPos3f(x, y, z);
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
}


void bird(){
    glBegin(GL_POLYGON);

    glVertex2f(-0.2,0.1);
    glVertex2f(-0.05,0.1);
    glVertex2f(-0.14,0.13);
    glVertex2f( -0.18,0.16);
    glVertex2f( -0.17,0.17);
    glVertex2f(-0.16,0.2);
    glVertex2f(-0.2,0.17);
    glVertex2f(-0.21,0.23);
    glVertex2f(-0.2,0.15);
    glVertex2f( -0.26,0.16);
    glVertex2f( -0.29,0.172);
    glVertex2f(-0.31,0.18);
    glVertex2f(-0.31,0.15);
    glVertex2f( -0.30,0.149);
    glVertex2f(-0.2,0.06);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,0);
    glVertex2f(-0.31,0.18);
    glVertex2f(-0.38,0.165);
    glVertex2f(-0.31,0.15);
    glEnd();

    int iz;
	GLfloat xz=-.296f; GLfloat yz=.157f; GLfloat radiusz =.006f;
	int triangleAmountz = 20; //# of triangles used to draw circle
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePiz = 2.0f * PI;
	glColor3ub(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xz,yz); // center of circle
		for(iz = 0; iz <= triangleAmountz;iz++) {
			glVertex2f(
		            xz + (radiusz * cos(iz *  twicePiz / triangleAmountz)),
			    yz + (radiusz * sin(iz * twicePiz / triangleAmountz))
			);
		}
	glEnd();

}


void sky(){
    glBegin(GL_QUADS);

    glVertex2f(-1.0,1.0);
    glVertex2f(-1.0,-0.2);
    glVertex2f(1.0,-0.2);
    glVertex2f(1.0,1.0);
    glEnd();
}

void mountain(){

//1st Mountain
    glScalef(.1,.1,0); // increase x right and y
    glTranslatef(-7.3,-0.08,0.0); // Translate x left and y down

	glBegin(GL_TRIANGLES);
	glVertex2f(-2,-1);
	glVertex2f(2.0f,1.9f);
	glVertex2f(6,-1);
	glEnd();
    glLoadIdentity();

//2nd Mountain
    glScalef(.05,.05,0); // increase x right and y
    glTranslatef(1.0,-1.0,0.0); // Translate x left and y down

	glBegin(GL_TRIANGLES);
	glVertex2f(0,-1);
	glVertex2f(9,4.4f);
	glVertex2f(20,-1);
	glEnd();
	glLoadIdentity();
}

void sun(){
    	int i;
	GLfloat x=-.75f; GLfloat y=.88f; GLfloat radius =.1f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x,y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void cloud(){

//Up cloud

    	int iy;//1
    glTranslatef(positionm,0.0f, 0.0f);
	GLfloat xy=-.45f; GLfloat yy=.82f; GLfloat radiusy =.07f;
	int triangleAmounty = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePiy = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xy,yy); // center of circle
		for(iy = 0; iy <= triangleAmounty;iy++) {
			glVertex2f(
		            xy + (radiusy * cos(iy *  twicePiy / triangleAmounty)),
			    yy + (radiusy * sin(iy * twicePiy / triangleAmounty))
			);
		}
	glEnd();

    int ix;//2
	GLfloat xx=-.49f; GLfloat yx=.9f; GLfloat radiusx =.07f;
	int triangleAmountx = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
		GLfloat twicePix = 2.0f * PI;
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xx,yx); // center of circle
		for(ix = 0; ix <= triangleAmountx;ix++) {
			glVertex2f(
		            xx + (radiusx * cos(ix *  twicePix / triangleAmountx)),
			    yx + (radiusx * sin(ix * twicePix / triangleAmountx))
			);
		}
	glEnd();

    int iw;//3
	GLfloat xw=-.56f; GLfloat yw=.9f; GLfloat radiusw =.04f;
	int triangleAmountw = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
		GLfloat twicePiw = 2.0f * PI;
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xw,yw); // center of circle
		for(iw = 0; iw <= triangleAmountw;iw++) {
			glVertex2f(
		            xw + (radiusw * cos(iw *  twicePiw / triangleAmountw)),
			    yw + (radiusw * sin(iw * twicePiw / triangleAmountw))
			);
		}
	glEnd();

	    int iv;//4
	GLfloat xv=-.60f; GLfloat yv=.828f; GLfloat radiusv =.07f;
	int triangleAmountv = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
		GLfloat twicePiv = 2.0f * PI;
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xv,yv); // center of circle
		for(iv = 0; iv <= triangleAmountv;iv++) {
			glVertex2f(
		            xv + (radiusv * cos(iv *  twicePiv / triangleAmountv)),
			    yv + (radiusv * sin(iv * twicePiv/ triangleAmountv))
			);
		}
	glEnd();

	    int iu;//5
	GLfloat xu=-.52f; GLfloat yu=.79f; GLfloat radiusu =.05f;
	int triangleAmountu = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
		GLfloat twicePiu = 2.0f * PI;
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xu,yu); // center of circle
		for(iu = 0; iu <= triangleAmountu;iu++) {
			glVertex2f(
		            xu + (radiusu * cos(iu *  twicePiu / triangleAmountu)),
			    yu + (radiusu * sin(iu * twicePiu/ triangleAmountu))
			);
		}
	glEnd();

//down cloud
	int it;//1

	GLfloat xt=-.62f; GLfloat yt=.657f; GLfloat radiust =.07f;
	int triangleAmountt = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePit = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xt,yt); // center of circle
		for(it = 0; it <= triangleAmountt;it++) {
			glVertex2f(
		            xt + (radiust * cos(it *  twicePit / triangleAmountt)),
			    yt + (radiust * sin(it * twicePit / triangleAmountt))
			);
		}
	glEnd();
	int iq;//2

	GLfloat xq=-.675f; GLfloat yq=.75f; GLfloat radiusq =.07f;
	int triangleAmountq = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePiq = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xq,yq); // center of circle
		for(iq = 0; iq <= triangleAmountq;iq++) {
			glVertex2f(
		            xq + (radiusq * cos(iq *  twicePiq / triangleAmountq)),
			    yq + (radiusq * sin(iq * twicePiq / triangleAmountq))
			);
		}
	glEnd();

	int is;//3
	GLfloat xs=-.756f; GLfloat ys=.77f; GLfloat radiuss =.04f;
	int triangleAmounts = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePis = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xs,ys); // center of circle
		for(is = 0; is <= triangleAmounts;is++) {
			glVertex2f(
		            xs + (radiuss * cos(is *  twicePis / triangleAmounts)),
			    ys + (radiuss * sin(is * twicePis / triangleAmounts))
			);
		}
	glEnd();

    int ir;//4
	GLfloat xr=-.8f; GLfloat yr=.7f; GLfloat radiusr =.07f;
	int triangleAmountr = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePir = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xr,yr); // center of circle
		for(ir = 0; ir <= triangleAmountr;ir++) {
			glVertex2f(
		            xr + (radiusr * cos(ir *  twicePir / triangleAmountr)),
			    yr + (radiusr * sin(ir * twicePir / triangleAmountr))
			);
		}
	glEnd();

    int ip;//5
	GLfloat xp=-.714f; GLfloat yp=.66f; GLfloat radiusp =.07f;
	int triangleAmountp = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePip = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xp,yp); // center of circle
		for(ip = 0; ip <= triangleAmountp;ip++) {
			glVertex2f(
		            xp + (radiusp * cos(ip *  twicePip / triangleAmountp)),
			    yp + (radiusp * sin(ip * twicePip / triangleAmountp))
			);
		}
	glEnd();

	glLoadIdentity();
}

 void land(){

    glBegin(GL_QUADS);
    glVertex2f(1.0,-0.1);
    glVertex2f(-1.0,-0.1);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glEnd();
}


void mosque(){

// Corridor
    glBegin(GL_QUADS);
    glColor3ub(130,130, 56);
    glVertex2f(-0.35,-0.15);
    glVertex2f(-0.30,-0.10);
    glVertex2f(0.30,-0.10);
    glVertex2f(0.35,-0.15);
    glEnd();

// Corridor down part
    glBegin(GL_QUADS);
    glColor3ub(130, 27, 27);
    glVertex2f(-0.35,-0.15);
    glVertex2f(-0.35,-0.17);
    glVertex2f(0.35,-0.17);
    glVertex2f(0.35,-0.15);
    glEnd();

// Mosque body
    glBegin(GL_QUADS);
    glColor3ub(130, 87, 56);
    glVertex2f(-0.30,-0.10);
    glVertex2f(-0.30,0.15);
    glVertex2f(0.30,0.15);
    glVertex2f(0.30,-0.10);
    glEnd();

// GOMBUJ 1
    glBegin(GL_QUADS);
    glColor3ub(130, 87, 56);
    glVertex2f(-0.30,0.15);
    glVertex2f(-0.30,0.30);
    glVertex2f(-0.25,0.30);
    glVertex2f(-0.25,0.15);
    glEnd();

// GOMBUJ 1 UP Quad
    glBegin(GL_QUADS);
    glColor3ub(130, 87, 56);
    glVertex2f(-0.33,0.30);
    glVertex2f(-0.33,0.33);
    glVertex2f(-0.22,0.33);
    glVertex2f(-0.22,0.30);
    glEnd();

// GOMBUJ 1 UP Polygon
    glBegin(GL_POLYGON);
    glColor3ub(130, 87, 56);
    glVertex2f(-0.31,0.33);
    glVertex2f(-0.31,0.35);
    glVertex2f(-0.275,0.37);
    glVertex2f(-0.24,0.35);
    glVertex2f(-0.24,0.33);
    glEnd();

// GOMBUJ 2
    glBegin(GL_QUADS);
    glColor3ub(130, 87, 56);
    glVertex2f(-0.21,0.15);
    glVertex2f(-0.21,0.20);
    glVertex2f(-0.16,0.20);
    glVertex2f(-0.16,0.15);
    glEnd();

// GOMBUJ 2 UP Quad
    glBegin(GL_QUADS);
    glColor3ub(130, 87, 56);
    glVertex2f(-0.24,0.20);
    glVertex2f(-0.24,0.23);
    glVertex2f(-0.13,0.23);
    glVertex2f(-0.13,0.20);
    glEnd();

// GOMBUJ 2 UP Polygon
    glBegin(GL_POLYGON);
    glColor3ub(130, 87, 56);
    glVertex2f(-0.22,0.23);
    glVertex2f(-0.22,0.25);
    glVertex2f(-0.185,0.275);
    glVertex2f(-0.15,0.25);
    glVertex2f(-0.15,0.23);
    glEnd();

// GOMBUJ 3
    glBegin(GL_QUADS);
    glColor3ub(130, 87, 56);
    glVertex2f(0.21,0.15);
    glVertex2f(0.21,0.20);
    glVertex2f(0.16,0.20);
    glVertex2f(0.16,0.15);
    glEnd();

// GOMBUJ 3 UP Quad
    glBegin(GL_QUADS);
    glColor3ub(130, 87, 56);
    glVertex2f(0.24,0.20);
    glVertex2f(0.24,0.23);
    glVertex2f(0.13,0.23);
    glVertex2f(0.13,0.20);
    glEnd();


// GOMBUJ 3 UP Polygon
    glBegin(GL_POLYGON);
    glColor3ub(130, 87, 56);
    glVertex2f(0.22,0.23);
    glVertex2f(0.22,0.25);
    glVertex2f(0.185,0.275);
    glVertex2f(0.15,0.25);
    glVertex2f(0.15,0.23);
    glEnd();

// GOMBUJ 4
    glBegin(GL_QUADS);
    glColor3ub(130, 87, 56);
    glVertex2f(0.30,0.15);
    glVertex2f(0.30,0.30);
    glVertex2f(0.25,0.30);
    glVertex2f(0.25,0.15);
    glEnd();


// GOMBUJ 4 UP Quad
    glBegin(GL_QUADS);
    glColor3ub(130, 87, 56);
    glVertex2f(0.33,0.30);
    glVertex2f(0.33,0.33);
    glVertex2f(0.22,0.33);
    glVertex2f(0.22,0.30);
    glEnd();

// GOMBUJ 4 UP Polygon
    glBegin(GL_POLYGON);
    glColor3ub(130, 87, 56);
    glVertex2f(0.31,0.33);
    glVertex2f(0.31,0.35);
    glVertex2f(0.275,0.37);
    glVertex2f(0.24,0.35);
    glVertex2f(0.24,0.33);
    glEnd();

// Middle GOMBUJ
    glBegin(GL_QUADS);
    glColor3ub(130, 87, 56);
    glVertex2f(-0.11,0.15);
    glVertex2f(-0.11,0.25);
    glVertex2f(0.11,0.25);
    glVertex2f(0.11,0.15);
    glEnd();

//Middle GOMBUJ Polygon
    glBegin(GL_POLYGON);
    glColor3ub(10, 57, 90);
    glVertex2f(-0.08,0.25);
    glVertex2f(-0.08,0.32);
    glVertex2f(0.00,0.36);
    glVertex2f(0.08,0.32);
    glVertex2f(0.08,0.25);
    glEnd();

// Door big part
    glBegin(GL_QUADS);
    glColor3ub(30, 87, 56);
    glVertex2f(-0.10,-0.10);
    glVertex2f(-0.10,0.12);
    glVertex2f(0.10,0.12);
    glVertex2f(0.10,-0.10);
    glEnd();

// Mosque Door
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.04,-0.10);
    glVertex2f(-0.04,0.05);
    glVertex2f(0.04,0.05);
    glVertex2f(0.04,-0.10);
    glEnd();

// Triangles
    glBegin(GL_TRIANGLES);
    glColor3ub(30, 87, 56);
    glVertex2f(-0.10,0.12);
    glVertex2f(0.00,0.17);
    glVertex2f(0.10,0.12);
    glEnd();

// Left window
    glBegin(GL_QUADS);
    glColor3ub(30, 87, 56);
    glVertex2f(-0.25,-0.05);
    glVertex2f(-0.25,0.07);
    glVertex2f(-0.15,0.07);
    glVertex2f(-0.15,-0.05);
    glEnd();

// Left window triangle
    glBegin(GL_TRIANGLES);
    glColor3ub(30, 87, 56);
    glVertex2f(-0.25,0.07);
    glVertex2f(-0.20,0.11);
    glVertex2f(-0.15,0.07);
    glEnd();

// Right window
    glBegin(GL_QUADS);
    glColor3ub(30, 87, 56);
    glVertex2f(0.25,-0.05);
    glVertex2f(0.25,0.07);
    glVertex2f(0.15,0.07);
    glVertex2f(0.15,-0.05);
    glEnd();

// Right window triangle
    glBegin(GL_TRIANGLES);
    glColor3ub(30, 87, 56);
    glVertex2f(0.25,0.07);
    glVertex2f(0.20,0.11);
    glVertex2f(0.15,0.07);
    glEnd();


/*//write Mosque name
    glColor3ub(255, 255, 0);
    drawText1(-0.2f, 0.04f, 1.0f, (const char*)"Kamalapur Central Masjid");*/
}

void tree(){

//1St Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(79, 26, 8);
    glVertex2f(0.6,0.1);
    glVertex2f(0.55,0.1);
    glVertex2f(0.55,-0.2);
    glVertex2f(0.6,-0.2);
    glEnd();

//2nd Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(79, 26, 8);
    glVertex2f(0.85,0.1);
    glVertex2f(0.8,0.1);
    glVertex2f(0.8,-0.2);
    glVertex2f(0.85,-0.2);
    glEnd();

//3rd Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(79, 26, 8);
    glVertex2f(1.01,0.1);
    glVertex2f(0.96,0.1);
    glVertex2f(0.96,-0.2);
    glVertex2f(1.01,-0.2);
    glEnd();

//1st Tree Crown
    int ic;
    GLfloat xc=0.57f; GLfloat yc=0.07f; GLfloat radiusc =0.1f;
    int triangleAmountc = 20; //# of triangles used to draw circle

    GLfloat twicePic = 2.0f * PI;

    glPushMatrix();
    glTranslatef(xc, yc, 0);
    glScalef(1.2, 1.2, 1);

    glBegin(GL_POLYGON);
    glColor3ub(5, 97, 32);
    for(ic = 0; ic <= triangleAmountc;ic++) {
        GLfloat radius = radiusc + (sin(ic * twicePic / triangleAmountc) * 0.05);
        GLfloat x = radius * cos(ic *  twicePic / triangleAmountc);
        GLfloat y = radius * sin(ic * twicePic / triangleAmountc);
        glVertex2f(x + (sin(ic * twicePic / triangleAmountc) * 0.02), y + (cos(ic * twicePic / triangleAmountc) * 0.02));
    }
    glEnd();

    glPopMatrix();

    // Branches
    glBegin(GL_LINES);
    glColor3ub(79, 26, 8);
    glVertex2f(0.57, 0.05);
    glVertex2f(0.64, 0.15);
    glVertex2f(0.57, 0.05);
    glVertex2f(0.50, 0.15);
    glVertex2f(0.57, 0.05);
    glVertex2f(0.57, 0.2);
    glEnd();

//2nd Tree Crown
    int i2c;
    GLfloat x2c=0.81f; GLfloat y2c=0.06f; GLfloat radius2c =0.1f;
    int triangleAmount2c = 20; //# of triangles used to draw circle

    GLfloat twicePic2 = 2.0f * PI;

    glPushMatrix();
    glTranslatef(x2c, y2c, 0);
    glScalef(1.2, 1.2, 1);

    glBegin(GL_POLYGON);
    glColor3ub(5, 97, 32);
    for(i2c = 0; i2c <= triangleAmount2c;i2c++) {
        GLfloat radius2 = radius2c + (sin(i2c * twicePic2 / triangleAmount2c) * 0.05);
        GLfloat x = radius2 * cos(i2c *  twicePic2 / triangleAmount2c);
        GLfloat y = radius2 * sin(i2c * twicePic2 / triangleAmount2c);
        glVertex2f(x + (sin(i2c * twicePic2 / triangleAmount2c) * 0.02), y + (cos(i2c * twicePic2 / triangleAmount2c) * 0.02));
    }
    glEnd();

    glPopMatrix();

     // Branches
    glBegin(GL_LINES);
    glColor3ub(79, 26, 8);
    glVertex2f(0.82, 0.05);
    glVertex2f(0.89, 0.15);
    glVertex2f(0.82, 0.05);
    glVertex2f(0.75, 0.15);
    glVertex2f(0.82, 0.05);
    glVertex2f(0.82, 0.2);
    glEnd();

//3rd Tree Crown
    int i3c;
    GLfloat x3c=1.00f; GLfloat y3c=0.02f; GLfloat radius3c =0.1f;
    int triangleAmount3c = 20; //# of triangles used to draw circle

    GLfloat twicePic3 = 2.0f * PI;

    glPushMatrix();
    glTranslatef(x3c, y3c, 0);
    glScalef(1.2, 1.2, 1);

    glBegin(GL_POLYGON);
    glColor3ub(5, 97, 32);
    for(i3c = 0; i3c <= triangleAmount3c;i3c++) {
        GLfloat radius3 = radius3c + (sin(i3c * twicePic3 / triangleAmount3c) * 0.05);
        GLfloat x = radius3 * cos(i3c *  twicePic3 / triangleAmount3c);
        GLfloat y = radius3 * sin(i3c * twicePic3 / triangleAmount3c);
        glVertex2f(x + (sin(i3c * twicePic3 / triangleAmount3c) * 0.02), y + (cos(i3c * twicePic3 / triangleAmount3c) * 0.02));
    }
    glEnd();

    glPopMatrix();


}


void platform(){

//Ground
    glBegin(GL_QUADS);
    glColor3ub(188, 74, 60);
    glVertex2f(1.00,-0.58);
    glVertex2f(1.00,-0.50);
    glVertex2f(-1.00,-0.50);
    glVertex2f(-1.00,-0.58);
    glEnd();

//Piller 01
    glBegin(GL_QUADS);
    glColor3ub(213, 207, 207);
    glVertex2f(-0.90,-0.50);
    glVertex2f(-0.90,-0.30);
    glVertex2f(-0.94,-0.30);
    glVertex2f(-0.94,-0.50);
    glEnd();

//Piller 02
    glBegin(GL_QUADS);
    glColor3ub(213, 207, 207);
    glVertex2f(-0.60,-0.50);
    glVertex2f(-0.60,-0.30);
    glVertex2f(-0.64,-0.30);
    glVertex2f(-0.64,-0.50);
    glEnd();

//Piller 03
    glBegin(GL_QUADS);
    glColor3ub(213, 207, 207);
    glVertex2f(-0.30,-0.50);
    glVertex2f(-0.30,-0.30);
    glVertex2f(-0.34,-0.30);
    glVertex2f(-0.34,-0.50);
    glEnd();

//Piller 04
    glBegin(GL_QUADS);
    glColor3ub(213, 207, 207);
    glVertex2f(0.00,-0.50);
    glVertex2f(0.00,-0.30);
    glVertex2f(0.04,-0.30);
    glVertex2f(0.04,-0.50);
    glEnd();

//Piller 05
    glBegin(GL_QUADS);
    glColor3ub(213, 207, 207);
    glVertex2f(0.30,-0.50);
    glVertex2f(0.30,-0.30);
    glVertex2f(0.34,-0.30);
    glVertex2f(0.34,-0.50);
    glEnd();

//Piller 06
    glBegin(GL_QUADS);
    glColor3ub(213, 207, 207);
    glVertex2f(0.60,-0.50);
    glVertex2f(0.60,-0.30);
    glVertex2f(0.64,-0.30);
    glVertex2f(0.64,-0.50);
    glEnd();

//Piller 07
    glBegin(GL_QUADS);
    glColor3ub(213, 207, 207);
    glVertex2f(0.90,-0.50);
    glVertex2f(0.90,-0.30);
    glVertex2f(0.94,-0.30);
    glVertex2f(0.94,-0.50);
    glEnd();


//Crown
     glBegin(GL_QUADS);
    glColor3ub(1, 1, 1);
    glVertex2f(-0.90,-0.25);
    glVertex2f(-1.00,-0.35);
    glVertex2f(1.00,-0.35);
    glVertex2f(0.90,-0.25);
    glEnd();

//write Station name
    glColor3ub(255, 255, 255);
    drawText1(-0.2f, -0.315f, 0.9f, (const char*)"Kamalapur Railway Station");
}

void railway(){

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.98,-0.845);
    glVertex2f(-0.98,-0.865);
    glVertex2f(-0.90,-0.865);
    glVertex2f(-0.90,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.98,-0.845);
    glVertex2f(-0.98,-0.865);
    glVertex2f(-0.90,-0.865);
    glVertex2f(-0.90,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.88,-0.845);
    glVertex2f(-0.88,-0.865);
    glVertex2f(-0.80,-0.865);
    glVertex2f(-0.80,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.78,-0.845);
    glVertex2f(-0.78,-0.865);
    glVertex2f(-0.70,-0.865);
    glVertex2f(-0.70,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.68,-0.845);
    glVertex2f(-0.68,-0.865);
    glVertex2f(-0.60,-0.865);
    glVertex2f(-0.60,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.58,-0.845);
    glVertex2f(-0.58,-0.865);
    glVertex2f(-0.50,-0.865);
    glVertex2f(-0.50,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.48,-0.845);
    glVertex2f(-0.48,-0.865);
    glVertex2f(-0.40,-0.865);
    glVertex2f(-0.40,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.38,-0.845);
    glVertex2f(-0.38,-0.865);
    glVertex2f(-0.30,-0.865);
    glVertex2f(-0.30,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.28,-0.845);
    glVertex2f(-0.28,-0.865);
    glVertex2f(-0.20,-0.865);
    glVertex2f(-0.20,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.18,-0.845);
    glVertex2f(-0.18,-0.865);
    glVertex2f(-0.10,-0.865);
    glVertex2f(-0.10,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(-0.08,-0.845);
    glVertex2f(-0.08,-0.865);
    glVertex2f(0.00,-0.865);
    glVertex2f(0.00,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(0.02,-0.845);
    glVertex2f(0.02,-0.865);
    glVertex2f(0.10,-0.865);
    glVertex2f(0.10,-0.845);
    glEnd();
//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(0.12,-0.845);
    glVertex2f(0.12,-0.865);
    glVertex2f(0.20,-0.865);
    glVertex2f(0.20,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(0.22,-0.845);
    glVertex2f(0.22,-0.865);
    glVertex2f(0.30,-0.865);
    glVertex2f(0.30,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(0.32,-0.845);
    glVertex2f(0.32,-0.865);
    glVertex2f(0.40,-0.865);
    glVertex2f(0.40,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(0.42,-0.845);
    glVertex2f(0.42,-0.865);
    glVertex2f(0.50,-0.865);
    glVertex2f(0.50,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(0.52,-0.845);
    glVertex2f(0.52,-0.865);
    glVertex2f(0.60,-0.865);
    glVertex2f(0.60,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(0.62,-0.845);
    glVertex2f(0.62,-0.865);
    glVertex2f(0.70,-0.865);
    glVertex2f(0.70,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(0.72,-0.845);
    glVertex2f(0.72,-0.865);
    glVertex2f(0.80,-0.865);
    glVertex2f(0.80,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(0.82,-0.845);
    glVertex2f(0.82,-0.865);
    glVertex2f(0.90,-0.865);
    glVertex2f(0.90,-0.845);
    glEnd();

//rail line brick
    glBegin(GL_QUADS);

    glVertex2f(0.92,-0.845);
    glVertex2f(0.92,-0.865);
    glVertex2f(1.0,-0.865);
    glVertex2f(1.0,-0.845);
    glEnd();

//rail line
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(-1.0,-0.832);
    glVertex2f(-1.0,-0.845);
    glVertex2f(1.0,-0.845);
    glVertex2f(1.0,-0.832);
    glEnd();

glPushMatrix();
   glTranslatef(position,0.0f, 0.0f);


//wheels

//wheel 1 (train 1)

    GLfloat xa=-0.6f; GLfloat ya=-0.8f; GLfloat radius1 =0.035f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(82, 80, 79);
		glVertex2f(xa, ya); // center of circle
		for(int i = 0; i <= triangleAmount1;i++) {
			glVertex2f(
		            xa + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
			    ya + (radius1 * sin(i * twicePi1 / triangleAmount1))
			);
		}
	glEnd();


//wheel 2 (train 1)

    GLfloat xb=-0.4f; GLfloat yb=-0.8f; GLfloat radius2 =0.035f;
	int triangleAmount2 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(82, 80, 79);
		glVertex2f(xb, yb); // center of circle
		for(int j = 0; j <= triangleAmount2;j++) {
			glVertex2f(
		            xb + (radius2 * cos(j *  twicePi2 / triangleAmount2)),
			    yb + (radius2 * sin(j * twicePi2 / triangleAmount2))
			);
		}
	glEnd();


//wheel 3 (train 1)

    GLfloat xc=-0.2f; GLfloat yc=-0.8f; GLfloat radius3 =0.035f;
	int triangleAmount3 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(82, 80, 79);
    glVertex2f(xc, yc); // center of circle
		for(int k = 0; k <= triangleAmount3;k++) {
			glVertex2f(
		            xc + (radius3 * cos(k *  twicePi3 / triangleAmount3)),
			    yc + (radius3 * sin(k * twicePi3 / triangleAmount3))
			);
		}
	glEnd();


 //wheel 4 (train 1)

    GLfloat xd=0.0f; GLfloat yd=-0.8f; GLfloat radius4 =0.035f;
	int triangleAmount4 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(82, 80, 79);
    glVertex2f(xd, yd); // center of circle
		for(int l = 0; l <= triangleAmount4;l++) {
			glVertex2f(
		            xd + (radius4 * cos(l *  twicePi4 / triangleAmount4)),
			    yd + (radius4 * sin(l * twicePi4 / triangleAmount4))
			);
		}
	glEnd();


//wheel 1 (train 2)

    GLfloat xe=0.3f; GLfloat ye=-0.8f; GLfloat radius5 =0.035f;
	int triangleAmount5 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(82, 80, 79);
    glVertex2f(xe, ye); // center of circle
		for(int m = 0; m <= triangleAmount5;m++) {
			glVertex2f(
		            xe + (radius5 * cos(m *  twicePi5 / triangleAmount5)),
			    ye + (radius5 * sin(m * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


//wheel 2 (train 2)

    GLfloat xf=0.5f; GLfloat yf=-0.8f; GLfloat radius6 =0.035f;
	int triangleAmount6 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(82, 80, 79);
    glVertex2f(xf, yf); // center of circle
		for(int n = 0; n <= triangleAmount6;n++) {
			glVertex2f(
		            xf + (radius6 * cos(n *  twicePi6 / triangleAmount6)),
			    yf + (radius6 * sin(n * twicePi6 / triangleAmount6))
			);
		}
	glEnd();


//wheel 3 (train 2)

    GLfloat xg=0.7f; GLfloat yg=-0.8f; GLfloat radius7 =0.035f;
	int triangleAmount7 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(82, 80, 79);
    glVertex2f(xg, yg); // center of circle
		for(int o = 0; o <= triangleAmount7;o++) {
			glVertex2f(
		            xg + (radius7 * cos(o *  twicePi7 / triangleAmount7)),
			    yg + (radius7 * sin(o * twicePi7 / triangleAmount7))
			);
		}
	glEnd();


//wheel 4 (train 2)

    GLfloat xh=0.9f; GLfloat yh=-0.8f; GLfloat radius8 =0.035f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(82, 80, 79);
    glVertex2f(xh, yh); // center of circle
		for(int p = 0; p <= triangleAmount8;p++) {
			glVertex2f(
		            xh + (radius8 * cos(p *  twicePi8 / triangleAmount8)),
			    yh + (radius8 * sin(p * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

//Train Head
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(-0.70,-0.60);
    glVertex2f(-0.80,-0.78);
    glVertex2f(-0.80,-0.80);
    glVertex2f(-0.70,-0.80);
    glEnd();

//train compartment up
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(-0.70,-0.60);
    glVertex2f(-0.70,-0.62);
    glVertex2f(0.10,-0.62);
    glVertex2f(0.10,-0.60);
    glEnd();

//train compartment 1st up gray part

    glBegin(GL_QUADS);
    glColor3ub(49, 66, 91);
    glVertex2f(-0.70,-0.62);
    glVertex2f(-0.70,-0.64);
    glVertex2f(0.10,-0.64);
    glVertex2f(0.10,-0.62);
    glEnd();

//train compartment 1st up gray part
    glBegin(GL_QUADS);

    glColor3ub(49, 66, 91);
    glVertex2f(-0.70,-0.64);
    glVertex2f(-0.70,-0.65);
    glVertex2f(0.10,-0.65);
    glVertex2f(0.10,-0.64);
    glEnd();

//train compartment down
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(-0.70,-0.78);
    glVertex2f(-0.70,-0.80);
    glVertex2f(0.10,-0.80);
    glVertex2f(0.10,-0.78);
    glEnd();

//train compartment 1st black part
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(-0.7,-0.65);
    glVertex2f(-0.7,-0.73);
    glVertex2f(0.10,-0.73);
    glVertex2f(0.10,-0.65);
    glEnd();

//1st train white part
    glBegin(GL_QUADS);

    glColor3ub(132, 134, 135);
    glVertex2f(-0.7,-0.73);
    glVertex2f(-0.7,-0.78);
    glVertex2f(0.10,-0.78);
    glVertex2f(0.10,-0.73);
    glEnd();



//train compartment 1st joint
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(0.10,-0.60);
    glVertex2f(0.10,-0.80);
    glVertex2f(0.12,-0.80);
    glVertex2f(0.12,-0.64);
    glEnd();

//train compartment 2nd white part
    glBegin(GL_QUADS);

    glColor3ub(132, 134, 135);
    glVertex2f(0.14,-0.78);
    glVertex2f(0.14,-0.62);
    glVertex2f(0.95,-0.62);
    glVertex2f(0.95,-0.78);
    glEnd();

    glBegin(GL_QUADS); //train compartment
    glColor3ub(43, 50, 54);
    glVertex2f(0.17,-0.60);
    glVertex2f(0.14,-0.62);
    glVertex2f(0.95,-0.62);
    glVertex2f(0.95,-0.60);
    glEnd();

//train compartment 2nd black part
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(0.22,-0.62);
    glVertex2f(0.22,-0.73);
    glVertex2f(0.95,-0.73);
    glVertex2f(0.95,-0.62);
    glEnd();

//train compartment 2nd up gray part
    glBegin(GL_QUADS);

    glColor3ub(49, 66, 91);
    glVertex2f(0.14,-0.62);
    glVertex2f(0.14,-0.65);
    glVertex2f(0.95,-0.65);
    glVertex2f(0.95,-0.62);
    glEnd();



//train compartment
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(0.14,-0.78);
    glVertex2f(0.17,-0.80);
    glVertex2f(0.95,-0.80);
    glVertex2f(0.95,-0.78);
    glEnd();

//train compartment
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(0.14,-0.62);
    glVertex2f(0.14,-0.78);
    glVertex2f(0.17,-0.78);
    glVertex2f(0.17,-0.62);
    glEnd();

//train compartment
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(0.95,-0.60);
    glVertex2f(0.95,-0.80);
    glVertex2f(0.98,-0.80);
    glVertex2f(0.98,-0.63);
    glEnd();

//train compartment
    glBegin(GL_QUADS);

    glColor3ub(27, 33, 36);
    glVertex2f(0.12,-0.75);
    glVertex2f(0.12,-0.78);
    glVertex2f(0.14,-0.78);
    glVertex2f(0.14,-0.75);
    glEnd();

//train compartment
    glBegin(GL_QUADS);

    glColor3ub(43, 50, 54);
    glVertex2f(0.98,-0.75);
    glVertex2f(0.98,-0.78);
    glVertex2f(1.0,-0.78);
    glVertex2f(1.0,-0.75);
    glEnd();

//window engine
    glBegin(GL_QUADS);

    glColor3ub(90, 123, 155);
    glVertex2f(-0.727,-0.65);
    glVertex2f(-0.76,-0.71);
    glVertex2f(-0.76,-0.73);
    glVertex2f(-0.72,-0.70);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(-0.65,-0.66);
    glVertex2f(-0.65,-0.72);
    glVertex2f(-0.60,-0.72);
    glVertex2f(-0.60,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(-0.57,-0.66);
    glVertex2f(-0.57,-0.72);
    glVertex2f(-0.52,-0.72);
    glVertex2f(-0.52,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(-0.49,-0.66);
    glVertex2f(-0.49,-0.72);
    glVertex2f(-0.44,-0.72);
    glVertex2f(-0.44,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(-0.41,-0.66);
    glVertex2f(-0.41,-0.72);
    glVertex2f(-0.36,-0.72);
    glVertex2f(-0.36,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(-0.33,-0.66);
    glVertex2f(-0.33,-0.72);
    glVertex2f(-0.27,-0.72);
    glVertex2f(-0.27,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(-0.24,-0.66);
    glVertex2f(-0.24,-0.72);
    glVertex2f(-0.19,-0.72);
    glVertex2f(-0.19,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(-0.16,-0.66);
    glVertex2f(-0.16,-0.72);
    glVertex2f(-0.11,-0.72);
    glVertex2f(-0.11,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(-0.08,-0.66);
    glVertex2f(-0.08,-0.72);
    glVertex2f(-0.03,-0.72);
    glVertex2f(-0.03,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(-0.00,-0.66);
    glVertex2f(-0.00,-0.72);
    glVertex2f(0.05,-0.72);
    glVertex2f(0.05,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(0.25,-0.66);
    glVertex2f(0.25,-0.72);
    glVertex2f(0.30,-0.72);
    glVertex2f(0.30,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(0.25,-0.66);
    glVertex2f(0.25,-0.72);
    glVertex2f(0.30,-0.72);
    glVertex2f(0.30,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(0.33,-0.66);
    glVertex2f(0.33,-0.72);
    glVertex2f(0.38,-0.72);
    glVertex2f(0.38,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(0.41,-0.66);
    glVertex2f(0.41,-0.72);
    glVertex2f(0.46,-0.72);
    glVertex2f(0.46,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(0.49,-0.66);
    glVertex2f(0.49,-0.72);
    glVertex2f(0.54,-0.72);
    glVertex2f(0.54,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(0.57,-0.66);
    glVertex2f(0.57,-0.72);
    glVertex2f(0.62,-0.72);
    glVertex2f(0.62,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(0.65,-0.66);
    glVertex2f(0.65,-0.72);
    glVertex2f(0.70,-0.72);
    glVertex2f(0.70,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(0.73,-0.66);
    glVertex2f(0.73,-0.72);
    glVertex2f(0.78,-0.72);
    glVertex2f(0.78,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(0.81,-0.66);
    glVertex2f(0.81,-0.72);
    glVertex2f(0.86,-0.72);
    glVertex2f(0.86,-0.66);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3ub(90, 123, 155);
    glVertex2f(0.89,-0.66);
    glVertex2f(0.89,-0.72);
    glVertex2f(0.94,-0.72);
    glVertex2f(0.94,-0.66);
    glEnd();

//write train name
    glColor3ub(0, 0, 0);
    drawText(-0.50f, -0.767f, -0.01f, (const char*)"Bonolota Express");

    glPopMatrix();
}




void treetranslation(){

    glLoadIdentity();                // Reset the model-view matrix
    glScalef(.5,.3,0); // increase x right and y
    glTranslatef(-2.09,-0.199,0.0); // Translate x right and y up
    glBegin(GL_QUADS);
    glColor3ub(79, 26, 8);
    glVertex2f(0.6,0.1);
    glVertex2f(0.55,0.1);
    glVertex2f(0.55,-0.2);
    glVertex2f(0.6,-0.2);
    glEnd();

    glLoadIdentity();                // Reset the model-view matrix
    glScalef(.5,.26,0); // increase x right and y
    glTranslatef(-2.09,-0.189, 0.0); // Translate x left and y down
    glBegin(GL_TRIANGLES);
    glColor3ub(5, 97, 32);
    glVertex2f(0.45,0.0);
    glVertex2f(0.7,0.0);
    glVertex2f(0.58,0.3);
    glEnd();

//SCALING TREE DECREASE

    glLoadIdentity();                // Reset the model-view matrix
    glScalef(.5,.3,0); // increase x right and y
    glTranslatef(-2.0,-0.16,0.0); // Translate x right and y up
    glBegin(GL_QUADS);
    glColor3ub(79, 26, 8);
    glVertex2f(0.6,0.1);
    glVertex2f(0.55,0.1);
    glVertex2f(0.55,-0.2);
    glVertex2f(0.6,-0.2);
    glEnd();


    glLoadIdentity();                // Reset the model-view matrix
    glScalef(.5,.26,0); // increase x right and y
    glTranslatef(-2.0,-0.15, 0.0); // Translate x left and y down
    glBegin(GL_TRIANGLES);
    glColor3ub(5, 97, 32);
    glVertex2f(0.45,0.0);
    glVertex2f(0.7,0.0);
    glVertex2f(0.58,0.3);
    glEnd();
    glLoadIdentity();                // Reset the model-view matrix

}

void windmill(){
    glLoadIdentity();

	glTranslated(-0.69,.19,0);
    glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_QUADS);
	glVertex2f(0.002f, 0);
	glVertex2f(-0.002f, 0);
	glVertex2f(-0.01f, -.45);
	glVertex2f(0.01f, -.45);
	glEnd();


//middle wing
        glPushMatrix();
        glRotatef(j,0,0,1);
        glScaled(0.2,0.2,1);
        glColor3ub(41,78,144);
        glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0.45f, 0.087f);
		glVertex2f(.9f,0);
		glVertex2f(0.45f, -0.087f);
		glEnd();

//up wing
        glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(-0.1f,0.45f);
		glVertex2f(-.4f,.9);
		glVertex2f(-0.25f, 0.37f);
		glEnd();

//down wing
        glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(-0.21f, -0.4f);
		glVertex2f(-.28f,-.9);
		glVertex2f(-0.072f, -0.49f);
		glEnd();



// 2nd small windmill
    glLoadIdentity();
    glScaled(0.56,0.56,1);
    glTranslated(-1.6,0.12,0);
    glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_QUADS);
	glVertex2f(0.002f, 0);
	glVertex2f(-0.002f, 0);
	glVertex2f(-0.01f, -.45);
	glVertex2f(0.01f, -.45);
	glEnd();


//middle wing(2)
        glPushMatrix();
        glRotatef(j,0,0,1);
        glScaled(0.2,0.2,1);
        glColor3ub(41,78,144);
        glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0.45f, 0.087f);
		glVertex2f(.9f,0);
		glVertex2f(0.45f, -0.087f);
		glEnd();

//up wing(2)
        glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(-0.1f,0.45f);
		glVertex2f(-.4f,.9);
		glVertex2f(-0.25f, 0.37f);
		glEnd();

//down wing(2)
        glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(-0.21f, -0.4f);
		glVertex2f(-.28f,-.9);
		glVertex2f(-0.072f, -0.49f);
		glEnd();

        glPopMatrix();
        glLoadIdentity();
        j+=0.2;

//1st windmill center
    int icc;
    GLfloat xcc=-.69f; GLfloat ycc=.187f; GLfloat radiuscc =.02f;
    int triangleAmountcc = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePicc = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	//glColor3ub(0,0,0);
		glVertex2f(xcc, ycc); // center of circle
		for(icc = 0; icc <= triangleAmountcc;icc++) {
			glVertex2f(
		            xcc + (radiuscc * cos(icc *  twicePicc / triangleAmountcc)),
			    ycc + (radiuscc * sin(icc * twicePicc / triangleAmountcc))
			);
		}
	glEnd();

//2nd small windmill center
    int iccc;
    GLfloat xccc=-.895f; GLfloat yccc=.07f; GLfloat radiusccc =.01f;
    int triangleAmountccc = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePiccc = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
//	glColor3ub(0,0,0);
		glVertex2f(xccc, yccc); // center of circle
		for(iccc = 0; iccc <= triangleAmountccc;iccc++) {
			glVertex2f(
		            xccc + (radiusccc * cos(iccc *  twicePiccc / triangleAmountccc)),
			    yccc + (radiusccc * sin(iccc * twicePiccc / triangleAmountccc))
			);
		}
	glEnd();


}


void birdplay(){
    glTranslatef(positionz,positionz,positionz);
    glPushMatrix();
    glTranslatef(.6,0.8,0.0); // Translate x left and y down
    glScalef(.34,.34,0); // increase x right and y
    glColor3ub(255,255,255);
    bird();
    glPopMatrix();
    glLoadIdentity();

    glTranslatef(positionz,positionz,positionz);
    glPushMatrix();
    glTranslatef(.7,0.85,0.0); // Translate x left and y down
    glScalef(.34,.34,0); // increase x right and y
    glColor3ub(255,255,255);
    bird();
    glPopMatrix();
    glLoadIdentity();

    glTranslatef(positionz,positionz,positionz);
    glPushMatrix();
    glTranslatef(.5,0.85,0.0); // Translate x left and y down
    glScalef(.34,.34,0); // increase x right and y
    glColor3ub(255,255,255);
    bird();
    glPopMatrix();
    glLoadIdentity();

    glTranslatef(positionz,positionz,positionz);
    glPushMatrix();
    glTranslatef(.4,0.8,0.0); // Translate x left and y down
    glScalef(.34,.34,0); // increase x right and y
    glColor3ub(255,255,255);
    bird();
    glPopMatrix();
    glLoadIdentity();

    glTranslatef(positionz,positionz,positionz);
    glPushMatrix();
    glTranslatef(.53,0.73,0.0); // Translate x left and y down
    glScalef(.34,.34,0); // increase x right and y
    glColor3ub(255,255,255);
    bird();
    glPopMatrix();
    glLoadIdentity();

    glTranslatef(positionz,positionz,positionz);
    glPushMatrix();
    glTranslatef(.7,0.75,0.0); // Translate x left and y down
    glScalef(.34,.34,0); // increase x right and y
    glColor3ub(255,255,255);
    bird();
    glPopMatrix();
    glLoadIdentity();
}
void Moon()
{
       	int i;
	GLfloat ximo=.3f; GLfloat yimo=.78f; GLfloat radiusimo =.13f;
	int triangleAmountimo = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePiimo = 2.0f * PI;
	glColor3ub(255, 255,255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(ximo,yimo); // center of circle
		for(i = 0; i <= triangleAmountimo;i++) {
			glVertex2f(
		            ximo + (radiusimo * cos(i *  twicePiimo / triangleAmountimo)),
			    yimo + (radiusimo * sin(i * twicePiimo / triangleAmountimo))
			);
		}
    glEnd();
			GLfloat xim=.33f; GLfloat yim=1.98f; GLfloat radiusim =.13f;
	int triangleAmountim = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePiim = 2.0f * PI;
    glColor3ub(30, 33, 49);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(xim,yim); // center of circle
		for(i = 0; i <= triangleAmountim;i++) {
			glVertex2f(
		            xim + (radiusim * cos(i *  twicePiim / triangleAmountim)),
			    yimo + (radiusim * sin(i * twicePiim / triangleAmountim))
			);
		}
	glEnd();
}

void morning(int value){
    time=0;
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);

//Sky
    glColor3ub(122, 159, 213);
    sky();

//Mountain
	glColor3ub(1,50,32);
    mountain();

//Sun
	glColor3ub(250, 250,0);
    sun();

//Cloud
	glColor3ub(255, 255,255);
    cloud();

//LAND
    glColor3ub(0, 110, 0);
    land();

//House
    glColor3ub(160,124,64);
    mosque();

//Tree
    glColor3ub(5, 97, 32);
    tree();

//Railway
    railway();

//TREE Translation
    treetranslation();


    glColor3ub(160,124,64);


    windmill();

    platform();

    birdplay();

    glFlush();  // Render now
}


void night(int value){
    time=1;
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);

//Sky
    glColor3ub(30, 33, 49);
    sky();

//Mountain
	glColor3ub(35, 34, 30);
    mountain();

//Sun
	glColor3ub(255, 255,102);
    Moon();

//Cloud
	glColor3ub(40, 37, 24);
    cloud();

//Land
    glColor3ub(0, 50, 0);
    land();

//Mosque

    mosque();

//tree
    glColor3ub(5, 97, 32);
    tree();

//railway
    glColor3ub(55, 48, 42);
    railway();

//TREE Translation
    treetranslation();

//windmill
    windmill();

//Platform
    platform();


    glFlush();  // Render now
}


void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)


if(time==0)
{
    morning(0);
}

if(time==1)
{
    night(0);
}


glFlush();  // Render now

}

void idle()
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(990,880);
    glutInitWindowPosition(98,30);
    glutCreateWindow("Railway Station Simulation");

    glutTimerFunc(100, update1, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update3, 0);
    glutTimerFunc(100, update4, 0);
    glutTimerFunc(100, update5, 0);

    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutSpecialFunc(SpecialInput);
    glutMainLoop();

    return EXIT_SUCCESS;
}
