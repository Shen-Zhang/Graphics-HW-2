//
//  Polyline.h
//  practical2
//
//  Created by Shen on 10/13/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//

#ifndef practical2_Polyline_h
#define practical2_Polyline_h
#include <iostream>
#include <GLUT/glut.h>
#include "float2.h"
#include "Curve.h"


class Polyline: public Curve
{
protected:
    std::vector<float2> controlPoints;
    std::vector<float> knots;
    
public:
    
    int getNumCP()
    {
        return (int) controlPoints.size();
    }
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
                if (controlPoints[i].distance(p) <= 0.15)
                    return i;
        }
        return -1;
        
    }
    float2 getPoint(float t)  // only in C++11
    {
        float2 r;
        if (controlPoints.size() > 0)
            r = controlPoints[0];
        else
            r = float2(0,0);
       
        for(int i = 1; i < controlPoints.size(); i++)
        {
            r = (controlPoints[i-1] * (1-t) + controlPoints[i] *t);
        }
     
        
        return r;
    }
    
    float2 getDerivative(float t)
    {
        
        return float2(0,0) ;
    }
    void addControlPoint(float2 p)
    {
        controlPoints.push_back(p);
    }
    void drawControlPoints()
    {
        glBegin(GL_POINTS) ;
        for(int i = 0; i < controlPoints.size(); i++)
            glVertex2f(controlPoints[i].x, controlPoints[i].y);
        glEnd();
    }
    void draw()
	{
        draw(.4,.7,.2);
		
	};
    void draw(float a, float b, float c){
        glBegin(GL_LINE_STRIP);
        glColor3d(a,b,c);
        for(int i = 0; i < controlPoints.size();i++)
            glVertex2f(controlPoints[i].x, controlPoints[i].y);
		glEnd();
        
    };
   
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
        draw();
        glPopMatrix();
    }
    
};
#endif
