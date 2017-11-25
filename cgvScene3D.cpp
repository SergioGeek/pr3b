#include <cstdlib>
#include <stdio.h>

#include "cgvScene3D.h"

// Constructor methods -----------------------------------

cgvScene3D::cgvScene3D () : angleX(0), angleY(0), angleZ(0){
	axes = true;
// Section B: initialize the attributes to control the degrees of freedom of the model

    //Tail
    this->RtailX = -30;
    this->RtailY = -90;
    this->angleZ = 0;
    this->cambioTail = false;

    //Eyes
    this->TeyeX = 2.8;
    this->TeyeY = 1.2;
    this->cambioEye = false;

    //Ear
    this->TtongueX = 2.8;
    this->TtongueY = 0.3;
    this->cambioTongue = false;

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

void cgvScene3D::draw_body ( void ) {

	static GLUquadric* quad = gluNewQuadric();

    GLfloat marronc[] = { 0.44,0.25,0.2,1 };

    glMaterialfv(GL_FRONT,GL_EMISSION,marronc);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,marronc);


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

void cgvScene3D::draw_head ( void ) {

	static GLUquadric* quad = gluNewQuadric();


    GLfloat marrono[] = { 0.37,0.25,0.2,1 };

    glMaterialfv(GL_FRONT,GL_EMISSION,marrono);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,marrono);

	//Cabeza
	glPushMatrix();
		glTranslatef(2.1,1,0);
		glutSolidSphere(0.75,15,15);
	glPopMatrix();

    GLfloat marronc[] = { 0.6,0.3,0.2,1 };

    glMaterialfv(GL_FRONT,GL_EMISSION,marronc);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,marronc);

	//Morro
	glPushMatrix();
		glTranslatef(2.1,1,0);
		glutSolidSphere(0.25,15,15);
		glRotatef(90,0,1,0);
		glRotatef(15,1,0,0);
		gluCylinder(quad, 0.6, 0.15, 1.30, 15, 15);
	glPopMatrix();

    GLfloat rosa[] = { 0.824, 0.106, 0.325,1 };

    glMaterialfv(GL_FRONT,GL_EMISSION,rosa);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,marrono);

	//Nariz
	glPushMatrix();
		glTranslatef(3.5,0.65,0);
		glutSolidSphere(0.175,15,15);
	glPopMatrix();

    glMaterialfv(GL_FRONT,GL_EMISSION,marrono);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,marrono);

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

    GLfloat blanco[] = { 1,1,1,1 };

    glMaterialfv(GL_FRONT,GL_EMISSION,blanco);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,blanco);

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

    GLfloat negro[] = { 0,0,0,1 };

    glMaterialfv(GL_FRONT,GL_EMISSION,negro);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,negro);


    glPushMatrix();
		glTranslatef(this->TeyeX,this->TeyeY,0.35);
		glScalef(0.3,1,0.65);
		glutSolidSphere(0.13,15,15);
	glPopMatrix();

	glPushMatrix();
        glTranslatef(this->TeyeX,this->TeyeY,-0.35);
		glScalef(0.3,1,0.65);
		glutSolidSphere(0.13,15,15);
	glPopMatrix();


}


void cgvScene3D::draw_legs ( void ) {

	//Patas
	//TD
	glPushMatrix();
		glTranslatef(-1.7,-1,0.67);
		glScalef(1,1,0.5);
		glRotatef(270,1,0,0);
		glutSolidCone(0.25,1,15,15);
	glPopMatrix();



	//TI
	glPushMatrix();
		glTranslatef(-1.7,-1,-0.67);
		glScalef(1,1,0.5);
		glRotatef(270,1,0,0);
		glutSolidCone(0.25,1,15,15);
	glPopMatrix();



	//DD
	glPushMatrix();
		glTranslatef(1.3,-1,0.67);
		glScalef(1,1,0.5);
		glRotatef(270,1,0,0);
		glutSolidCone(0.25,1,15,15);
	glPopMatrix();


	//DI
	glPushMatrix();
		glTranslatef(1.3,-1,-0.67);
		glScalef(1,1,0.5);
		glRotatef(270,1,0,0);
		glutSolidCone(0.25,1,15,15);
	glPopMatrix();


}


void cgvScene3D::draw_feet( void ) {

    GLfloat marrono[] = { 0.3,0.25,0.2,1 };

    glMaterialfv(GL_FRONT,GL_EMISSION,marrono);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,marrono);

    //DI
    glPushMatrix();
        glTranslatef(1.4,-1.1,-0.67);
        glScalef(0.95,0.2,0.47);
        glutSolidCube(1);
    glPopMatrix();

    //DD
    glPushMatrix();
        glTranslatef(1.4,-1.1,0.67);
        glScalef(0.95,0.2,0.47);
        glutSolidCube(1);
    glPopMatrix();


    //TI
    glPushMatrix();
        glTranslatef(-1.6,-1.1,-0.67);
        glScalef(0.95,0.2,0.47);
        glutSolidCube(1);
    glPopMatrix();

    //TD
    glPushMatrix();
        glTranslatef(-1.6,-1.1,0.67);
        glScalef(0.95,0.2,0.47);
        glutSolidCube(1);
    glPopMatrix();



}


void cgvScene3D::draw_tail ( void ) {

    GLfloat marrono[] = { 0.37,0.25,0.2,1 };

    glMaterialfv(GL_FRONT,GL_EMISSION,marrono);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,marrono);


	glPushMatrix();
		glTranslatef(-2,0,0);
		glRotatef(this->RtailY,0,1,0);
		glRotatef(this->RtailX,1,0,0);
        glRotatef(this->RtailZ,1,0,0);
		glutSolidCone(0.2,2.2,15,15);
	glPopMatrix();


}

void cgvScene3D::draw_tongue ( void ) {

    GLfloat rosa[] = { 0.824, 0.106, 0.325,1 };

    glMaterialfv(GL_FRONT,GL_EMISSION,rosa);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,rosa);


    glPushMatrix();
        glTranslatef(this->TtongueX, this->TtongueY, 0);
        glScalef( 1, 0.2, 1);
        glRotatef(-90,0,1,0);
        glRotatef( -75,1,0,0);
        glutSolidCone(0.2,3,15,15);
    glPopMatrix();

}

void cgvScene3D::rotateEyes(float aux) {


    if ( this->TeyeY > 1.375 || this->TeyeY < 1.06 )
        this->cambioEye = !this->cambioEye;
    if ( !this->cambioEye )
        this->TeyeY += aux;
    else
        this->TeyeY -= aux;
}

void cgvScene3D::rotateTail(float aux) {

    if ( this->RtailY > -40 || this->RtailY < -125 )
        this->cambioTail = !this->cambioTail;

    if ( !this->cambioTail )
        this->RtailY += aux;
    else
        this->RtailY -= aux;

}

void cgvScene3D::rotateTongue(float aux) {


    if ( this->TtongueX > 3.1  || this->TtongueX < 2.7 )
        this->cambioTongue = !this->cambioTongue;

    if ( !this->cambioTongue ) {

        this->TtongueX += aux;
        this->TtongueY -= aux;

    }else {

        this->TtongueX -= aux;
        this->TtongueY += aux;
    }

}

void cgvScene3D::rotateAll( float auxTo, float auxTa, float auxE ) {

    this->rotateTongue(auxTo);
    this->rotateEyes(auxE);
    this->rotateTail(auxTa);
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
    draw_feet();
	draw_tail();
    draw_tongue();



	//glLightfv(GL_LIGHT0,GL_POSITION,light0); // the light is placed here and it moves with the scene
	float mesh_color[4] = {1.0, 0.0, 0.0, 1.0};
	glMaterialfv(GL_FRONT,GL_EMISSION,mesh_color);

///// Section B: include here the visualization of the tree of the model by using the OpenGL stack of matrices
/////             it is advisable to create an auxiliary method to encapsulate the code to visualize the model
/////             leaving here only the call to this method. In Section D add the names to the mobile parts of the object by
/////		          the stack of names and control the selected object to colour it yellow




	glPopMatrix (); // restore the modelview matrix

}
