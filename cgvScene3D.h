#ifndef __CGVSCENE3D
#define __CGVSCENE3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

enum {

    BODY,
    LEGS,
    HEAD,
    EARS,
    MOUTH,
    EYE_R,
    EYE_L,
    PUPIL_R,
    PUPIL_L,
    TAIL,
    TONGUE

};


class cgvScene3D {
protected:

    float angleX, angleY, angleZ;
////// Section B: add here the attributes to control the degrees of freedom of the model
	//Tail
	float RtailX, RtailY, RtailZ;
	bool cambioTail;

	//Eyes
	float TeyeX, TeyeY, TeyeZ;
	bool cambioEye;

    //Tongue
	float TtongueX, TtongueY, TtongueZ;
	bool cambioTongue;

////// Section D: add here the attribute/s to control the selected object and to color it yellow

    bool changeColor[7];


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
	void draw_body (  bool color );
	void draw_head ( bool color );
    void draw_ears ( bool color );
    void draw_eyes ( bool color, float zB );
    void draw_pupil ( bool color );
    void draw_mouth ( bool color );
	void draw_legs ( bool color );
	void draw_tail ( bool color );
	void draw_tongue ( bool color );

	void rotateTail ( float aux );
	void rotateEyes ( float aux );
	void rotateTongue (float aux );
	void rotateAll( float auxTo, float auxTa, float auxE );

	////// Section D: include here the method/s to indicate the selected object

	bool get_axes() {return axes;};
	void set_axes(bool _axes){axes = _axes;};
};

#endif