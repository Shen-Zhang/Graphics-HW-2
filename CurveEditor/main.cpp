#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
// Needed on MsWindows
#include <windows.h>
#endif // Win32 platform

#include <GLUT/glut.h>
#include <vector>
#include "float2.h"
#include "Curve.h"
#include "Circle.h"
#include "Freedom.h"
#include "BezierCurve.h"
#include "LagrangeCurve.h"
#include "CurveInstance.h"

float TIME;


bool pol = false;
bool lan = false;
bool bez = false;

std::vector<Curve*> LC ;
std::vector<Curve*> BC ;
std::vector<CurveInstance*> CI;

std::vector<float> knots;

void onMouse(int button, int state, int x, int y) {
    int viewportRect[4];
    glGetIntegerv(GL_VIEWPORT, viewportRect);
    if (lan == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        LC.at(0)->addControlPoint( float2(
                                              x * 2.0 / viewportRect[2] - 1.0,
                                              -y * 2.0 / viewportRect[3] + 1.0));
    if (bez == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        BC.at(0)->addControlPoint( float2(
                                            x * 2.0 / viewportRect[2] - 1.0,
                                            -y * 2.0 / viewportRect[3] + 1.0));
    glutPostRedisplay();
}

void onKeyBoard(unsigned char key, int x, int y)
{

    if (key == 'p')
    {
        pol = true;
    } else {
        pol = false;
        
    }
    
    
    if (key == 'b')
    {
        bez = true;
    } else {
        bez = false;
    }
    
    
    if (key == 'l')
    {
        lan = true;
    } else {
        lan = false;
    }
    
    glutPostRedisplay();
}

void onIdle()
{
    TIME = glutGet(GLUT_ELAPSED_TIME) * .001 * 0.1 - floor(glutGet(GLUT_ELAPSED_TIME) * .001 *0.1) ;
    glutPostRedisplay();
}


void onDisplay( )
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3d(1,1,1);
    glLineWidth(4);
    glPointSize(8);
    
    LC.at(0)->drawControlPoints();
    LC.at(0)->draw();
    onIdle();
    LC.at(0)->drawTracker(TIME);
    
    BC.at(0)->drawControlPoints();
    BC.at(0)->draw();
    onIdle();
    BC.at(0)->drawTracker(TIME);
    
    onIdle();
    CI.at(0)->draw();
    
	glutSwapBuffers();
    
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(
                        GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); //RGBA if you want an alpha channel for transparency
    glutCreateWindow("l02_Curves");
    
    BezierCurve *  b= new BezierCurve();
    LagrangeCurve * l = new LagrangeCurve();
   
    LC.push_back(l);
    BC.push_back(b);
    glutKeyboardFunc(onKeyBoard);
    glutMouseFunc(onMouse);

    CurveInstance * c = new CurveInstance(l, float2(0.5,0.5));
    CI.push_back(c);
    glutDisplayFunc(onDisplay);
    glutMainLoop();
    
    
    return 0;
}