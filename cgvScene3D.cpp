#include <cstdlib>
#include <stdio.h>

#include "cgvScene3D.h"

// Constructor methods -----------------------------------

cgvScene3D::cgvScene3D () : angleX(0), angleY(0), angleZ(0){
	axes = true;
// Section B: initialize the attributes to control the degrees of freedom of the model


// Section D: initialize the attribute/s that identifies the select object and to colour it yellow

}

cgvScene3D::~cgvScene3D() {}


// Public methods ----------------------------------------

void cgvScene3D::rotateX(const float& angle) { this->angleX += angle; }

void cgvScene3D::rotateY(const float& angle) { this->angleY += angle; }

void cgvScene3D::rotateZ(const float& angle) { this->angleZ += angle; }

void draw_axes(void) {

	GLfloat red[]={1,0,0,1.0};
	GLfloat green[]={0,1,0,1.0};
	GLfloat blue[]={0,0,1,1.0};

	glBegin(GL_LINES);
	glMaterialfv(GL_FRONT,GL_EMISSION,red);
	glVertex3f(1000,0,0);
	glVertex3f(-1000,0,0);

	glMaterialfv(GL_FRONT,GL_EMISSION,green);
	glVertex3f(0,1000,0);
	glVertex3f(0,-1000,0);

	glMaterialfv(GL_FRONT,GL_EMISSION,blue);
	glVertex3f(0,0,1000);
	glVertex3f(0,0,-1000);
	glEnd();
}

void draw_body ( void ) {

	static GLUquadric* quad = gluNewQuadric();

	glPushMatrix();
		glTranslatef(-1.9,0,0);
		glRotatef(90,0,1,0);
		gluCylinder(quad, 0.7, 0.7, 3.25, 15, 15);
	glPopMatrix();


	glPushMatrix();
		glTranslatef(-1.9,0,0);
		glutSolidSphere(0.7,15,15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.3,0,0);
		glutSolidSphere(0.7,15,15);
	glPopMatrix();

}

void draw_head ( void ) {

	static GLUquadric* quad = gluNewQuadric();



	//Cabeza
	glPushMatrix();
		glTranslatef(2.1,1,0);
		glutSolidSphere(0.75,15,15);
	glPopMatrix();

	//Morro
	glPushMatrix();
		glTranslatef(2.1,1,0);
		glutSolidSphere(0.25,15,15);
		glRotatef(90,0,1,0);
		glRotatef(15,1,0,0);
		gluCylinder(quad, 0.6, 0.15, 1.30, 15, 15);
	glPopMatrix();


	//Nariz
	glPushMatrix();
		glTranslatef(3.5,0.65,0);
		glutSolidSphere(0.175,15,15);
	glPopMatrix();

	//Orejas
	 glPushMatrix();
		glTranslatef(2.1,-0.65,0.73);
		glScalef(1,1,0.5);
		glRotatef(270,1,0,0);
		glutSolidCone(0.4,2,15,15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.1,-0.65,-0.73);
		glScalef(1,1,0.5);
		glRotatef(270,1,0,0);
		glutSolidCone(0.4,2,15,15);
	glPopMatrix();

	//Ojo
	glPushMatrix();
		glTranslatef(2.75,1.2,-0.35);
		glScalef(0.3,1,0.65);
		glutSolidSphere(0.25,15,15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.75,1.2,0.35);
		glScalef(0.3,1,0.65);
		glutSolidSphere(0.25,15,15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.8,1.2,0.35);
		glScalef(0.3,1,0.65);
		glutSolidSphere(0.13,15,15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.8,1.2,-0.35);
		glScalef(0.3,1,0.65);
		glutSolidSphere(0.13,15,15);
	glPopMatrix();


}


void draw_legs ( void ) {

	//Patas
	//TD
	glPushMatrix();
		glTranslatef(-1.7,-1,0.67);
		glScalef(1,1,0.5);
		glRotatef(270,1,0,0);
		glutSolidCone(0.25,1,15,15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.6,-1.1,0.67);
		glScalef(0.95,0.2,0.47);
		glutSolidCube(1);
	glPopMatrix();

	//TI
	glPushMatrix();
		glTranslatef(-1.7,-1,-0.67);
		glScalef(1,1,0.5);
		glRotatef(270,1,0,0);
		glutSolidCone(0.25,1,15,15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.6,-1.1,-0.67);
		glScalef(0.95,0.2,0.47);
		glutSolidCube(1);
	glPopMatrix();

	//DD
	glPushMatrix();
		glTranslatef(1.3,-1,0.67);
		glScalef(1,1,0.5);
		glRotatef(270,1,0,0);
		glutSolidCone(0.25,1,15,15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.4,-1.1,0.67);
		glScalef(0.95,0.2,0.47);
		glutSolidCube(1);
	glPopMatrix();

	//DI
	glPushMatrix();
		glTranslatef(1.3,-1,-0.67);
		glScalef(1,1,0.5);
		glRotatef(270,1,0,0);
		glutSolidCone(0.25,1,15,15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.4,-1.1,-0.67);
		glScalef(0.95,0.2,0.47);
		glutSolidCube(1);
	glPopMatrix();
}


void draw_tail ( void ) {

	glPushMatrix();
		glTranslatef(-2,0,0);
		glRotatef(-90,0,1,0);
		glRotatef(-30,1,0,0);
		glutSolidCone(0.2,2.2,15,15);
	glPopMatrix();


}





void cgvScene3D::render(void) {

	// lights
	GLfloat light0[4]={5.0,5.0,5.0,1}; // point light source
	glLightfv(GL_LIGHT0,GL_POSITION,light0); // this light is placed here and it remains still
	glEnable(GL_LIGHT0);


	// create the model
	glPushMatrix(); // store the model matrices

	glRotatef(this->angleX, 1, 0, 0);
	glRotatef(this->angleY, 0, 1, 0);
	glRotatef(this->angleZ, 0, 0, 1);

	// draw the axes
	//if (axes) draw_axes();

	draw_head();
	draw_body();
	draw_legs();
	draw_tail();



	//glLightfv(GL_LIGHT0,GL_POSITION,light0); // the light is placed here and it moves with the scene
	float mesh_color[4] = {1.0, 0.0, 0.0, 1.0};
	glMaterialfv(GL_FRONT,GL_EMISSION,mesh_color);

///// Section B: include here the visualization of the tree of the model by using the OpenGL stack of matrices
/////             it is advisable to create an auxiliary method to encapsulate the code to visualize the model
/////             leaving here only the call to this method. In Section D add the names to the mobile parts of the object by
/////		          the stack of names and control the selected object to colour it yellow




	glPopMatrix (); // restore the modelview matrix

}
