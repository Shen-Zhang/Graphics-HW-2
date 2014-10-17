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
#include "FreeForm.h"
#include "BezierCurve.h"
#include "LagrangeCurve.h"
//#include "CurveInstance.h"
#include "Polyline.h"

float TIME;

std::vector<Curve*> Curves;
std::vector<Curve*> PL;
std::vector<Curve*> LC ;
std::vector<Curve*> BC ;


std::vector<float> knots;
bool HELD = false;
bool DELETE = true;
Curve* currentCur = NULL;
bool CREATED = false;
int currentIdx = 0;


void CreateCurve(std::vector<Curve*> vec, int currPos, float x, float y)
{
    vec.at(currPos)->addControlPoint(float2(x,y));
}
int getNCP(std::vector<Curve*> vec, int position)
{
    return vec[position]->getNumCP();
}

void onMouse(int button, int state, int x, int y) {
    int viewportRect[4];
    glGetIntegerv(GL_VIEWPORT, viewportRect);
    if (HELD == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        currentCur->addControlPoint(float2(x * 2.0 / viewportRect[2] - 1.0,-y * 2.0 / viewportRect[3] + 1.0));
        
    }
   /* if (DELETE == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        currentCur->removeCP(float2(x * 2.0 / viewportRect[2] - 1.0,-y * 2.0 / viewportRect[3] + 1.0));
    }
    */
    glutPostRedisplay();
    
}

void onKeyBoard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'p':
        {
            HELD = true;
            if(CREATED == false)
            {
                currentCur = new Polyline();
                CREATED = true;
            }
            break;
        }
        case 'l':
        {
            
            HELD = true;
            if(CREATED == false)
            {
                currentCur = new LagrangeCurve();
                CREATED = true;
            }
            
            break;
        }
        case 'b':
        {
            
            HELD = true;
            if(CREATED == false)
            {
                currentCur = new BezierCurve();
                CREATED = true;
            }
            break;
        }
        case ' ':
            if (!Curves.empty())
            {
                currentIdx = (currentIdx + 1) % Curves.size();
                currentCur = Curves.at(currentIdx);
            }
            break;
        case 'a':
            if (currentCur != NULL)
            {
                HELD = true;
            }
    }
    
    glutPostRedisplay();
}

void keyBoardUp(unsigned char keyUp, int x, int y)
{
    switch (keyUp)
    {
        case 'p':
        {
            
            HELD = false;
            if (currentCur->getNumCP() >= 2)
            {
                PL.push_back(currentCur);
                Curves.push_back(currentCur);
                
            } else {
                currentCur = NULL;
            }
            CREATED = false;
            break;
        }
            
        case 'l':
        {
            
            HELD = false;
            if (currentCur->getNumCP() >= 2)
            {
                LC.push_back(currentCur);
                Curves.push_back(currentCur);
            } else {
                currentCur = NULL;
            }
            CREATED = false;
            break;
        }
        case 'b':
        {
            
            HELD = false;
            if (currentCur->getNumCP() >= 2)
            {
                BC.push_back(currentCur);
                Curves.push_back(currentCur);
            } else {
                currentCur = NULL;
            }
            CREATED = false;
            break;
        }
        case 'a':
        {
            HELD = false;
            break;
        }
            
            
    }
    glutPostRedisplay();
    
}
void onIdle()
{
    TIME = glutGet(GLUT_ELAPSED_TIME) * .001 * 0.1 - floor(glutGet(GLUT_ELAPSED_TIME) * .001 *0.1) ;
    glutPostRedisplay();
}

void drawCurve(Curve* cur)
{
    cur->drawControlPoints();
    cur->draw();
    onIdle();
    cur->drawTracker(TIME);
}

void onDisplay( )
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
    
    if (currentCur != NULL)
    {
        glLineWidth(8);
        currentCur->drawControlPoints();
        onIdle();
        currentCur->drawTracker(TIME);
        currentCur->draw(.2,.6,1);
    }
    
    
    glColor3d(1,1,1);
    glLineWidth(3);
    glPointSize(6);
    // defalt setting
   
    
    if (!LC.empty())
    {
        for (int i = 0; i < LC.size(); i++)
            drawCurve(LC.at(i));
    }
    
    if(!BC.empty())
    {
        for(int i = 0; i < BC.size(); i++)
            drawCurve(BC.at(i));
    }
    if(!PL.empty())
    {
        for(int i = 0; i < PL.size(); i++)
            drawCurve(PL.at(i));
    }
	glutSwapBuffers();
    
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(
                        GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); //RGBA if you want an alpha channel for transparency
    glutCreateWindow("Curve Editor");
    
    glutKeyboardFunc(onKeyBoard);
    glutKeyboardUpFunc(keyBoardUp);
    glutMouseFunc(onMouse);
    
    //CurveInstance * c = new CurveInstance(l, float2(0.5,0.5));
    //CI.push_back(c);
    glutDisplayFunc(onDisplay);
    glutMainLoop();
    
    
    return 0;
}