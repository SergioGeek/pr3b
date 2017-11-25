#ifndef __CGVSCENE3D
#define __CGVSCENE3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif


class cgvScene3D {
protected:

    float angleX, angleY, angleZ;
////// Section B: add here the attributes to control the degrees of freedom of the model
	//Tail
	float RtailX, RtailY, RtailZ;
	bool cambioTail;

	//eyes
	float TeyeX, TeyeY, TeyeZ;
	bool cambioEye;

	float TtongueX, TtongueY, TtongueZ;
	bool cambioTongue;

////// Section D: add here the attribute/s to control the selected object and to color it yellow


	// Additional attributes

	bool axes;

public:
	// Default constructor and destructor
	cgvScene3D();
	~cgvScene3D();

	// Static methods

	// Methods
	// method with the OpenGL calls to render the scene
	void render();

    void rotateX(const float& angle);

    void rotateY(const float& angle);

    void rotateZ(const float& angle);

	////// Section B: include here the methods to modify the degrees of freedom of the model
	void draw_body ( void );
	void draw_head ( void );
	void draw_legs ( void );
	void draw_feet( void );
	void draw_tail ( void );
	void draw_tongue ( void );

	void rotateTail ( float aux );
	void rotateEyes ( float aux );
	void rotateTongue (float aux );
	void rotateAll( float auxTo, float auxTa, float auxE );

	////// Section D: include here the method/s to indicate the selected object

	bool get_axes() {return axes;};
	void set_axes(bool _axes){axes = _axes;};
};

#endif