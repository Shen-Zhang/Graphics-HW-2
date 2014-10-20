//
//  CatmullRom.h
//  practical2
//
//  Created by Shen on 10/20/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//

#ifndef practical2_CatmullRom_h
#define practical2_CatmullRom_h


#include <iostream>
#include "FreeForm.h"
#include "float2.h"

class CatmullRom : public FreeForm
{
protected:
    Curve * curve;
    
public:
    void draw()
	{
        draw(.3,0.6,0.5);
        
	};
    void draw(float a, float b, float c){
        if(controlPoints.size() < 4)
        {
            glColor3d(a,b,c);
            glBegin(GL_LINE_STRIP);
            for (int i = 0; i < controlPoints.size(); i++)
                glVertex2d(controlPoints[i].x, controlPoints[i].y);
        }
        else{
        glColor3d(a,b,c);
        glBegin(GL_LINE_STRIP);
        float2 v;
        for (float i = 0; i<=1; i+=0.01) {
            v = getPoint(i);
            glVertex2d(v.x, v.y);
        }
        }
		glEnd();
        
    };
    void getWeight(int i, double t)
    {
        float x = 1/2 *((2 *controlPoints[i+1].x) + (-controlPoints[i].x + controlPoints[i+2].x)*t + (2*controlPoints[i].x-5*controlPoints[i+1].x+4*controlPoints[i+2].x -controlPoints[i+3].x) * t*t + (-controlPoints[i].x + 3* controlPoints[i+1].x - 3*controlPoints[i+2].x + controlPoints[i+3].x) * t * t *t);
        float y = 1/2 *((2 *controlPoints[i+1].y) + (-controlPoints[i].y + controlPoints[i+2].y)*t + (2*controlPoints[i].y-5*controlPoints[i+1].y+4*controlPoints[i+2].y -controlPoints[i+3].y) * t*t + (-controlPoints[i].y + 3* controlPoints[i+1].y - 3*controlPoints[i+2].y + controlPoints[i+3].y) * t * t *t);
        
    }

    float2 getPoint(float t)
    {
        float2 r(0.0, 0.0);
        if (controlPoints.size() >=4)
        {
            for(int i = 0; i < controlPoints.size(); i=i+4)
        {
            double x = 1/2 *((2 *controlPoints[i+1].x) + (-1*controlPoints[i].x + controlPoints[i+2].x)*t + (2*controlPoints[i].x-5*controlPoints[i+1].x+4*controlPoints[i+2].x -1*controlPoints[i+3].x) * t*t + (-controlPoints[i].x + 3* controlPoints[i+1].x - 3*controlPoints[i+2].x + controlPoints[i+3].x) * t * t *t);
            double y = 1/2 *((2 *controlPoints[i+1].y) + (-1 * controlPoints[i].y + controlPoints[i+2].y)*t + (2*controlPoints[i].y - 5*controlPoints[i+1].y+4*controlPoints[i+2].y -1*controlPoints[i+3].y) * t*t + (-controlPoints[i].y + 3* controlPoints[i+1].y - 3*controlPoints[i+2].y + controlPoints[i+3].y) * t * t *t);
            
            r += float2(controlPoints[i].x * (float)x, controlPoints[i].y * (float)y);
        }
        }
        return r;
        
    }
    
    int getNumCP()
    {
        return (int)controlPoints.size();
    }
    
    float2 getDerivative(float t)
    {
        
        return float2(0,0) ;
    }
    
};

#endif
