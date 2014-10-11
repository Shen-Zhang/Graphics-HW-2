//
//  CurveInstance.h
//  practical2
//
//  Created by Shen on 10/9/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//
#include "Curve.h"
#include "float2.h"

#ifndef practical2_CurveInstance_h
#define practical2_CurveInstance_h
class CurveInstance
{
protected:
    Curve* curve; // the geometric model,
    // can point to any Curve subclass
    float2 position; // instance position
public:

    CurveInstance(Curve* curve, float2 position)
    :curve(curve), position(position) {}
    
    void draw()
    {
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(.5,0,0);
        
        // need to make OpenGL translate the vertices
        curve->draw();
        glPopMatrix();
        // need to make OpenGL stop translating
    }
    
};



#endif
