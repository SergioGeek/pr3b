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
		gluCylinder(quad, 0.7, 0.7, 3.75, 15, 15);
	glPopMatrix();


	glPushMatrix();
		glTranslatef(-2,0,0);
		glutSolidSphere(0.7,15,15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8,0,0);
	glutSolidSphere(0.7,15,15);
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

	draw_body();

	//glLightfv(GL_LIGHT0,GL_POSITION,light0); // the light is placed here and it moves with the scene
	float mesh_color[4] = {1.0, 0.0, 0.0, 1.0};
	glMaterialfv(GL_FRONT,GL_EMISSION,mesh_color);

///// Section B: include here the visualization of the tree of the model by using the OpenGL stack of matrices
/////             it is advisable to create an auxiliary method to encapsulate the code to visualize the model
/////             leaving here only the call to this method. In Section D add the names to the mobile parts of the object by
/////		          the stack of names and control the selected object to colour it yellow




	glPopMatrix (); // restore the modelview matrix

}
