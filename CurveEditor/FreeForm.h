//
//  FreeForm.h
//  practical2
//
//  Created by Shen on 10/8/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//
#ifndef __practical2__Freedom__
#define __practical2__Freedom__

#include <iostream>
#include "float2.h"
#include "Curve.h"
#include <GLUT/glut.h>


class FreeForm : public Curve
{
protected:
    std::vector<float2> controlPoints;
   
public:
    virtual float2 getPoint(float t)=0;
    
    void setControlPoint(int pos, float2 p)
    {
        controlPoints[pos] = p;
    }
    void setControlPoint(float2 offset)
    {
        if (!controlPoints.empty())
        {
            for(int i = 0; i < controlPoints.size(); i++)
            {
                setControlPoint(i, controlPoints[i]+offset);
            }
        }
    }
    
    int onPoint(float2 p)
    {
        if(!controlPoints.empty())
        {
            for(int i = 0; i < controlPoints.size();i++)
            {
              
            if (controlPoints[i].distance(p) <= 0.15)
                return i;
                
            }
        }
        return -1;
        
    }
    virtual void addControlPoint(float2 p)
    {
        controlPoints.push_back(p);
        
    }
    void drawControlPoints(){
		
        glBegin(GL_POINTS) ;
        glPointSize(9);
        glColor3d(1,1,1);
        for(int i = 0; i < controlPoints.size(); i++)
            glVertex2f(controlPoints[i].x, controlPoints[i].y);
        glEnd();
        // draw points at control points
    }
    
    void removeCP(int p)
    {
        controlPoints.erase(controlPoints.begin() + p);
    }
    
    void translate(float x, float y)
    {
        glLoadIdentity();
        glPushMatrix();
        
        glTranslatef(x,y,0);
        // need to make OpenGL translate the vertices
        this->draw();
        glPopMatrix();
        glFlush();
    }
 
};
#endif /* defined(__practical2__FreeForm__) */
