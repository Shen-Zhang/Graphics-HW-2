//
//  LagrangeCurve.h
//  practical2
//
//  Created by Shen on 10/8/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//

#ifndef __practical2__LagrangeCurve__
#define __practical2__LagrangeCurve__

#include <iostream>
#include "float2.h"
#include "FreeForm.h"

class LagrangeCurve : public FreeForm
{
    std::vector<float> knots;
public:
    void addControlPoint(float2 p)
    {
        controlPoints.push_back(p);
        knots.clear();
        for(int i=0; i<controlPoints.size(); i++)
            knots.push_back((float)i/(controlPoints.size()-1));
    }
    
    // i is the index of the line
    double polynomials(int i, float t)
    {
        double l = 1;
        for (int j = 0; j < knots.size();j++)
        {
            if (i != j)
            l *= (t - knots[j])/(knots[i] - knots[j]);
        }
        return l;
    };
    
    float2 getPoint(float t)
    {
        float2 r(0.0, 0.0);
        for(int i = 0; i < controlPoints.size(); i++)
        {
            double l = polynomials(i,t);
            r = r + (controlPoints[i] * (float)l);
        }
        return r;
    }
    
    float2 getDerivative(float t)
    {
        
        return float2(0,0) ;
    }
    
};

#endif /* defined(__practical2__LagrangeCurve__) */
