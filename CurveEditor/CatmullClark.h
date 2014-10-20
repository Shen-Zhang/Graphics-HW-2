//
//  CatmullClark.h
//  practical2
//
//  Created by Shen on 10/20/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//

#ifndef practical2_CatmullClark_h
#define practical2_CatmullClark_h
#include <iostream>
#include "FreeForm.h"
#include "float2.h"
#include <vector>

class CatmullClark : public Curve
{
protected:
    std::vector<float2> controlPoints;
    std::vector<float2> newPoints;
    std::vector<float2> weightPoints;
    int idx = -1;
public:
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
    void addControlPoint(float2 p)
    {
        controlPoints.push_back(p);
        idx +=1;
        if(controlPoints.size() >=2)
        {
            newPoints.push_back(float2((controlPoints[idx-1].x + controlPoints[idx].x)/2,
            (controlPoints[idx-1].y + controlPoints[idx].y)/2));
        }
        if(controlPoints.size() >=3)
        {
            weightPoints.push_back(float2(newPoints[idx-2].x * 1/4 + newPoints[idx-1].x * 1/4 +controlPoints[idx-1].x * 1/2,(newPoints[idx-2].y) * 1/4 + newPoints[idx-1].y * 1/4 +controlPoints[idx-1].y * 1/2));
        }
        
    }
    void draw()
	{
        draw(0.1,0.9,0.5);
        
	};
    void drawControlPoints()
    {
        glBegin(GL_POINTS) ;
        for(int i = 0; i < controlPoints.size(); i++)
            glVertex2f(controlPoints[i].x, controlPoints[i].y);
        glEnd();
    }

    void draw(float a, float b, float c){
        glColor3d(a,b,c);
        glBegin(GL_LINE_STRIP);
        
       if (controlPoints.size() >=2)
       {
           glVertex2f(controlPoints[0].x, controlPoints[0].y);
        for(int i = 0; i < weightPoints.size();i++)
        {
            glVertex2f(newPoints[i].x,newPoints[i].y);
            if (weightPoints.size() > i)
           glVertex2f(weightPoints[i].x,weightPoints[i].y);
        }
           glVertex2f(controlPoints.back().x, controlPoints.back().y);
       }
           glEnd();
        
    };
    
    float2 getPoint(float t)
    {
        return float2(0,0);
    }
    
    float2 getDerivative(float t)
    {
        return float2(0,0);
    }
    int getNumCP()
    {
        return (int) controlPoints.size();
    }
    void removeCP(int p)
    {
        
        controlPoints.erase(controlPoints.begin() + p);
        if((p > 0) && (p < controlPoints.size()-1))
        {
            newPoints[p-1] = float2((controlPoints[p-1].x + controlPoints[p].x)/2,
                                      (controlPoints[p-1].y + controlPoints[p].y)/2);
            newPoints[p+1] = float2((controlPoints[p+1].x + controlPoints[p].x)/2,
                                      (controlPoints[p+1].y + controlPoints[p].y)/2);
            weightPoints[p-1] =float2(newPoints[p-1].x * 1/4 + newPoints[p].x * 1/4 +controlPoints[p].x * 1/2,(newPoints[p-1].y) * 1/4 + newPoints[p].y * 1/4 +controlPoints[p].y * 1/2);
        }
        
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
    void setControlPoint(int pos, float2 p)
    {
        controlPoints[pos] = p;
        if((pos > 0) && (pos < controlPoints.size()-1))
        {
            newPoints[pos-1] = float2((controlPoints[pos-1].x + controlPoints[pos].x)/2,
                                         (controlPoints[pos-1].y + controlPoints[pos].y)/2);
            newPoints[pos+1] = float2((controlPoints[pos+1].x + controlPoints[pos].x)/2,
                                         (controlPoints[pos+1].y + controlPoints[pos].y)/2);
            weightPoints[pos-1] =float2(newPoints[pos-1].x * 1/4 + newPoints[pos].x * 1/4 +controlPoints[pos].x * 1/2,(newPoints[pos-1].y) * 1/4 + newPoints[pos].y * 1/4 +controlPoints[pos].y * 1/2);
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
    
};

#endif
