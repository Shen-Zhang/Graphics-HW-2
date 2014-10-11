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
    virtual void addControlPoint(float2 p)
    {
        controlPoints.push_back(p);
    }
    void drawControlPoints(){
        glBegin(GL_POINTS) ;
        for(int i = 0; i < controlPoints.size(); i++)
            glVertex2f(controlPoints[i].x, controlPoints[i].y);
        glEnd();
        
        // draw points at control points
    }
};
#endif /* defined(__practical2__FreeForm__) */
