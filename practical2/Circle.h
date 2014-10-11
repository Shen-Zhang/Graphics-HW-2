//
//  Circle.h
//  practical2
//
//  Created by Shen on 10/8/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//

#ifndef __practical2__Circle__
#define __practical2__Circle__

#include <iostream>
#include <math.h>
#include "float2.h"
#include "Curve.h"

class Circle : public Curve
{
    
public:
	int x;
	int y;
	double radius;
    
	Circle(int x, int y, double radius)
	{
		this->x = x;
		this->y = y;
		this->radius = radius;
	}
	float2 getPoint(float t)
	{
		t *= M_PI*2;
		float2 point;
		point.x = sin(t) * radius;
		point.y = cos(t) * radius;
		return point;
	}
    float2 getDerivative(float t)
    {
        t *= M_PI*2;
		float2 d;
		d.x = 2 * M_PI * radius * cos(t);
		d.y = -2 * M_PI * radius * sin(t);
        return d;
    }
	
};


#endif /* defined(__practical2__Circle__) */
