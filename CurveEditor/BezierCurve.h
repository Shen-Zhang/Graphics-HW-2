//
//  BezierCurve.h
//  practical2
//
//  Created by Shen on 10/8/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//

#ifndef __practical2__BezierCurve__
#define __practical2__BezierCurve__

#include <iostream>
#include "FreeForm.h"
#include "float2.h"


class BezierCurve : public FreeForm
{
    
    static double bernstein(int i, int n, double t)
    {
        if(n == 1) {
            if(i == 0) return 1-t;
            if(i == 1) return t;
            return 0;
        }
        if(i < 0 || i > n)
            return 0;
        return (1 - t) * bernstein(i, n-1, t) + t * bernstein(i-1, n-1, t);
    }
    float2 getPoint(float t) {
        float2 r(0.0, 0.0);
        for(int i = 0; i < controlPoints.size(); i++)
        {
            double weight = bernstein(i,controlPoints.size(),t);
            r = r + (controlPoints[i] * (float) weight);
        }
        // for every control point
        // compute weight using the Bernstein formula
        // add control point to r, weighted
        return r;
    }
    
    float2 getDerivative(float t)
    {
        
        return float2(0,0) ;
    }
};

#endif /* defined(__practical2__BezierCurve__) */
