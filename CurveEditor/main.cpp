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
#include "Polyline.h"
#include "BezierNumber.h"
#include "CurveInstance.h"
#include "CatmullClark.h"
#include "CatmullRom.h"

/**-----------------------------
 Support the following
 - Pressing SPACE makes the next object selected instead of the current one, repeatedly pressing SPACE cycles over all curves.
 - As long as the RIGHT mouse button remains pressed, mouse movements drag the selected object. When the button is released, the object remains selected.
 - When an object is selected, the user may hold down 'A' to add control points to the selected object by clicking.
 - Support removing control points of the selected curve, by holding 'D' and clicking them.
 - Support Catmull-Clark subdivision curves, created by clicking control points while holding key 'C'.
 - Support Catmull-Rom splines, created by clicking control points while holding key 'R'.
 - Support dragging control points of the selected curve.
 - Display the current number of curves in the corner using Bezier curves to form the numbers
 **----------------------------/

/*** Global Values ***/
float TIME;
std::vector<Curve*> Curves;
std::vector<Curve*> PL;
std::vector<Curve*> LC ;
std::vector<Curve*> BC ;
std::vector<CurveInstance*> CI ;
std::vector<Curve*> CC;
std::vector<Curve*> CR;

int viewportRect[4];
std::vector<float> knots;
bool HELD = false;
bool DELETE = false;
bool DRAG = true;
int DragPoint;
Curve* currentCur = NULL;
float2 INITIAL_CLICK;
bool LINE_MOVE = false;
bool SET_INITIAL = false;
bool CREATED = false;
int currentIdx = 0;

/*** **** ***/
/** Method **/
void CreateCurve(std::vector<Curve*> vec, int currPos, float x, float y)
{
    vec.at(currPos)->addControlPoint(float2(x,y));
    
}

int getNCP(std::vector<Curve*> vec, int position)
{
    return vec[position]->getNumCP();
}

// Get the current mouse cursour
float2 mouseToPoint(int x , int y)
{
    return float2(x * 2.0 / viewportRect[2] - 1.0,-y * 2.0 / viewportRect[3] + 1.0);
}

// shifting the selcted object by offset
void translate(float offsetX, float offsetY)
{
    while (currentCur != NULL)
    {
        currentCur->translate(offsetX, offsetY);
    }
}

// for dragging the curve or control points
void onDrag(int x, int y)
{
    if (LINE_MOVE == true && currentCur!=NULL)
    {
        if (SET_INITIAL == false)
        {
            INITIAL_CLICK = mouseToPoint(x, y);
            SET_INITIAL = true;
        }
        currentCur->setControlPoint(float2((mouseToPoint(x,y).x -INITIAL_CLICK.x)/50.0,(mouseToPoint(x,y).y -INITIAL_CLICK.y)/50.0));
        
    }
    if (DragPoint >= 0 && DRAG == false)
    {
        currentCur->setControlPoint(DragPoint, mouseToPoint(x,y));
    }
    glutPostRedisplay();
}

void onMouse(int button, int state, int x, int y) {
    
  
    glGetIntegerv(GL_VIEWPORT, viewportRect);
    
    // HELD means there is a key pressed
    if (HELD == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        currentCur->addControlPoint(float2(x * 2.0 / viewportRect[2] - 1.0,-y * 2.0 / viewportRect[3] + 1.0));
        
    }
    else if (DELETE == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && currentCur)
    {
        
        int on = currentCur->onPoint(float2(x * 2.0 / viewportRect[2] - 1.0,-y * 2.0 / viewportRect[3] + 1.0));
        if (on >= 0)
            currentCur->removeCP(on);
        if (currentCur->getNumCP() < 2)
        {
            Curves.pop_back();
            currentCur = NULL;
        }
    }
    // LEFT Button to drag the control point
    else if (HELD == false && button == GLUT_LEFT_BUTTON && currentCur && DRAG == true)
    {
        DragPoint = (currentCur->onPoint(mouseToPoint(x, y)));
        DRAG = false;
    }
      // RIGHT Button to move the object
    else if (HELD == false && button == GLUT_RIGHT_BUTTON && currentCur && DRAG == true)
    {
        LINE_MOVE = true;
    }
    
    
    if (button == GLUT_LEFT_BUTTON  && state == GLUT_UP && currentCur)
    {
        DRAG = true;
        
        
    }
    if (button == GLUT_RIGHT_BUTTON  && state == GLUT_UP && currentCur)
    {
        LINE_MOVE = false;
        SET_INITIAL = false;
    }
    glutPostRedisplay();
    
}


void onKeyBoard(unsigned char key, int x, int y)
{
    switch (key)
    {
            //Polylines
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
            //Lagrange
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
            //Bezier
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
            //CatmullClark
        case 'c':
        {
            
            HELD = true;
            if(CREATED == false)
            {
                currentCur = new CatmullClark();
                CREATED = true;
            }
            
            break;
        }
            //CatmullRom
        case 'r':
        {
            
            HELD = true;
            if(CREATED == false)
            {
                currentCur = new CatmullRom();
                CREATED = true;
            }
            
            break;
        }
            // SPACE to shift
        case ' ':
            if (!Curves.empty())
            {
                currentIdx = (currentIdx + 1) % Curves.size();
                currentCur = Curves.at(currentIdx);
            }
            break;
            // Add control points
        case 'a':
            if (currentCur != NULL)
            {
                HELD = true;
            }
            // Delete control points
        case 'd':
                DELETE = true;
                break;
    }
    
    glutPostRedisplay();
}

// key up to push back on the vector
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
        case 'c':
        {
            
            HELD = false;
            if (currentCur->getNumCP() >= 2)
            {
                CR.push_back(currentCur);
                Curves.push_back(currentCur);
            } else {
                currentCur = NULL;
            }
            CREATED = false;
            break;
        }
        case 'r':
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
        case 'a':
        {
            HELD = false;
            break;
        }
        case 'd':
        {
            DELETE = false;
            break;
        }
            
            
    }
    glutPostRedisplay();
    
}
// for trackers to move
void onIdle()
{
    TIME = glutGet(GLUT_ELAPSED_TIME) * .001 * 0.1 - floor(glutGet(GLUT_ELAPSED_TIME) * .001 *0.1) ;
    glutPostRedisplay();
}

void drawCurve(Curve* cur)
{
    cur->drawControlPoints();
    cur->draw();
}


void onDisplay( )
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (currentCur != NULL)
    {
        glLineWidth(8);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glPointSize(9);
        glColor3d(1,1,1);
        currentCur->drawControlPoints();
        onIdle();
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
    if(!CC.empty())
    {
        for(int i = 0; i < CC.size(); i++)
            drawCurve(CC.at(i));
    }
    if(!CR.empty())
    {
        for(int i = 0; i < CR.size(); i++)
            drawCurve(CR.at(i));
    }
    
    int NoC = (int) Curves.size();
    std::vector<int> stack;
    
    while (NoC > 0)
    {
        stack.push_back(NoC % 10);
        NoC = NoC/10;
    }
    int shift = 0;
    if(stack.empty())
        BezierZero(shift);
    
    // For the Bezier curve counter
    while(!stack.empty())
    {
        int n = stack.back();
        stack.pop_back();
        switch (n) {
            case 0:
                BezierZero(shift);
                break;
            case 1:
                BezierOne(shift);
                break;
            case 2:
                BezierTwo(shift);
                break;
            case 3:
                BezierThree(shift);
                break;
            case 4:
                BezierFour(shift);
                break;
            case 5:
                BezierFive(shift);
                break;
            case 6:
                BezierSix(shift);
                break;
            case 7:
                BezierSeven(shift);
                break;
            case 8:
                BezierEight(shift);
                break;
            case 9:
                BezierNine(shift);
                break;
            default:
                break;
                
        }
        shift +=1;
        
    }
    
	glutSwapBuffers();
    
}

/** Main **/
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
    glutMotionFunc(onDrag);
  
    glutDisplayFunc(onDisplay);
    glutMainLoop();

    
    return 0;
}