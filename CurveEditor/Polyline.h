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
    // constructor to initialize members
    int getNumCP()
    {
        return (int)controlPoints.size();
    }
    
    float2 getPoint(float t)  // only in C++11
    {
        float2 r;
        if (controlPoints.size() > 0)
            r = controlPoints[0];
        else
            r = float2(0,0);
        //r = controlPoints[0];
        for(int i = 1; i < controlPoints.size(); i++)
        {
            r = (controlPoints[i-1] * (1-t) + controlPoints[i] *t);
        }
        // evaluate parametric line segment formula
        
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
    
    void removeCP(float2 p)
    {
        std:: vector<float2>:: iterator i = controlPoints.begin() = find(controlPoints.begin(), controlPoints.end(), p);
        if (i != controlPoints.end())
        {
            int pos = (int)  distance (controlPoints.begin(), i);
            controlPoints.erase(controlPoints.begin()+ pos);
        }
        
        
    }
    
};
#endif
