//
//  Curve.h
//  practical2
//
//  Created by Shen on 10/8/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//

#ifndef __practical2__Curve__
#define __practical2__Curve__

#include <iostream>
#include "float2.h"
#include <GLUT/glut.h>


class Curve
{
public:
	virtual float2 getPoint(float t)=0; //getPoint will be a different function depending on what type of curve we are calling on
    virtual float2 getDerivative(float t)=0;
    virtual void drawControlPoints(){};
    virtual void addControlPoint(float2 p)=0;
    virtual int getNumCP()=0;
    virtual void draw()=0;
	virtual void draw(float a, float b, float c)=0;
    virtual void removeCP(int p)=0;
    virtual int onPoint(float2 p)=0;
    virtual void setControlPoint(int pos, float2 p)=0;
    virtual void translate(float x, float y)=0;
    virtual void setControlPoint(float2 offset)=0;

    void drawTracker(float t)
    {
        float2 r = getPoint(t);
        float2 d = getDerivative(t);
        glPointSize(10);
        glColor3d(1,1,1);
        glBegin(GL_POINTS);
        glVertex3f(r.x, r.y,0.0);
        glEnd();
        glBegin(GL_LINES) ;
        glVertex3f(r.x,r.y,0.0) ;
        glVertex3f(r.x + d.x,r.y + d.y,0.0) ;
        glEnd();
    } // frawTracker(float)
    
    
};

#endif /* defined(__practical2__Curve__) */
