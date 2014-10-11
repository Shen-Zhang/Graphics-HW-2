//
//  curve2.h
//  practical2
//
//  Created by Shen on 10/8/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//

#ifndef __practical2__curve2__
#define __practical2__curve2__

#include <iostream>
#include "float2.h"
#include "Curve.h"
#include <math.h>


class curve2 : public Curve
{
public:
    int x;
    int y;
    
    curve2(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    float2 getPoint(float t)
    {
        t *= M_PI *2;
        float2 point;
        point.x = (16 * sin(t)* sin(t)* sin(t) ) /20 ;
        point.y = (13 * cos(t) - 5 * cos(2*t) -2 * cos(3*t) - cos(4*t)) /20 ;
        return point;
    }
    
    float2 getDerivative(float t)
    {
        
        return float2(0,0) ;
    }
};

#endif /* defined(__practical2__curve2__) */
