//
//  BezierNumber.h
//  practical2
//
//  Created by Shen on 10/17/14.
//  Copyright (c) 2014 Shen Zhang. All rights reserved.
//

#ifndef practical2_BezierNumber_h
#define practical2_BezierNumber_h

#include "Curve.h"
#include "float2.h"
#include <GLUT/glut.h>
#include "BezierCurve.h"

void BezierZero(int shift)
{
    Curve * zero = new BezierCurve();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-.7+ shift * 0.15,.65 ,0);
    zero->addControlPoint(float2(-0.156,0.152));
    zero->addControlPoint(float2(-0.28,0.28));
    zero->addControlPoint(float2(-0.152,0.432));
    zero->addControlPoint(float2(-0.076,0.308));
    zero->addControlPoint(float2(-0.168,0.148));
    zero->draw();
    glPopMatrix();
}

void BezierOne(int shift)
{
    Curve * one = new BezierCurve();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-1+ shift * 0.15,.7,0);
    one->addControlPoint(float2(0.136,0.164));
    one->addControlPoint(float2(0.216,0.268));
    one->addControlPoint(float2(0.208,0.304));
    one->addControlPoint(float2(0.2,0.068));
    one->addControlPoint(float2(0.236,0.056));
    one->draw();
    glPopMatrix();
}

void BezierTwo(int shift)
{
    Curve * two = new BezierCurve();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-.7+ shift * 0.15,.7,0);
    two->addControlPoint(float2(-0.096
                                ,0.112));
    two->addControlPoint(float2(-0.16
                                ,0.212));
    two->addControlPoint(float2(-0.088
                                ,0.304));
    two->addControlPoint(float2(-0.028
                                ,0.216));
    two->addControlPoint(float2(-0.008
                                ,0.132));
    two->addControlPoint(float2(-0.164
                                ,0.028));
    two->addControlPoint(float2(-0.004
                                ,0.032));
    two->draw();
    glPopMatrix();
}

void BezierThree(int shift)
{
    Curve * three = new BezierCurve();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-.8+ shift * 0.15,.7,0);
    three->addControlPoint(float2(-0.012
                                  ,0.152));
    three->addControlPoint(float2(-0.056
                                  ,0.24));
    three->addControlPoint(float2(-0.004
                                  ,0.272));
    three->addControlPoint(float2(0.124
                                  ,0.3));
    three->addControlPoint(float2(0.112
                                  ,0.192));
    three->addControlPoint(float2(0.064
                                  ,0.132));
    three->addControlPoint(float2(-0.024
                                  ,0.1));
    three->addControlPoint(float2(-0.024
                                  ,0.124));
    three->addControlPoint(float2(0.128
                                  ,0.088));
    three->addControlPoint(float2(0.104,0.004));
    three->addControlPoint(float2(0.032
                                  ,0.012));
    three->draw();
    glPopMatrix();
}

void BezierFour(int shift)
{
    
    Curve * four = new BezierCurve();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-1.5+ shift * 0.15,.9,0);
    four->addControlPoint(float2(0.676
                                 ,-0.228));
    four->addControlPoint(float2(0.668
                                 ,0.068));
    four->addControlPoint(float2(0.708
                                 ,0.016));
    four->addControlPoint(float2(0.54
                                 ,-0.076));
    four->addControlPoint(float2(0.492
                                 ,-0.14));
    four->addControlPoint(float2(0.792
                                 ,-0.112));
    four->draw();
    glPopMatrix();
}

void BezierFive(int shift)
{
    Curve * five = new BezierCurve();
    
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-.7+ shift * 0.15,.6,0);
    five->addControlPoint(float2(-0.008
                                 ,0.344));
    five->addControlPoint(float2(-0.144
                                 ,0.336));
    five->addControlPoint(float2(-0.152
                                 ,0.38));
    five->addControlPoint(float2(-0.136
                                 ,0.204));
    five->addControlPoint(float2(-0.184
                                 ,0.192));
    five->addControlPoint(float2(-0.008
                                 ,0.204));
    five->addControlPoint(float2(-0.008
                                 ,0.12));
    five->addControlPoint(float2(-0.016
                                 ,0.08));
    five->addControlPoint(float2(-0.14
                                 ,0.064));
    five->draw();
    glPopMatrix();

}

void BezierSix(int shift)
{
    Curve * six = new BezierCurve();
    
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0+ shift * 0.15,0,0);
    six->addControlPoint(float2(-0.688
                                ,0.848));
    six->addControlPoint(float2(-0.732
                                ,0.928));
    six->addControlPoint(float2(-0.84
                                ,0.932));
    six->addControlPoint(float2(-0.868
                                ,0.8));
    six->addControlPoint(float2(-0.868
                                ,0.608));
    six->addControlPoint(float2(-0.736
                                ,0.632));
    six->addControlPoint(float2(-0.704
                                ,0.728));
    six->addControlPoint(float2(-0.836
                                ,0.772));
    six->draw();
     glPopMatrix();
    
}
    
void BezierSeven(int shift)
{
    
    Curve * seven = new BezierCurve();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0+ shift * 0.15,0,0);
    seven->addControlPoint(float2(-0.852
                                  ,0.916));
    seven->addControlPoint(float2(-0.728
                                  ,0.92));
    seven->addControlPoint(float2(-0.728
                                  ,0.956));
    seven->addControlPoint(float2(-0.804
                                  ,0.8));
    seven->addControlPoint(float2(-0.82
                                  ,0.736));
    seven->draw();
    glPopMatrix();
}

void BezierEight(int shift)
{
    
    Curve * eight = new BezierCurve();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0+ shift * 0.15,0,0);
    eight->addControlPoint(float2(-0.788
                                  ,0.772));
    eight->addControlPoint(float2(-0.68
                                  ,0.84));
    eight->addControlPoint(float2(-0.756
                                  ,0.96));
    eight->addControlPoint(float2(-0.876
                                  ,0.892));
    eight->addControlPoint(float2(-0.676
                                  ,0.648));
    eight->addControlPoint(float2(-0.78
                                  ,0.608));
    eight->addControlPoint(float2(-0.844
                                  ,0.716));
    eight->addControlPoint(float2(-0.78,0.788));
    eight->draw();
    glPopMatrix();
}

void BezierNine(int shift)
{
    
    Curve * nine = new BezierCurve();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0+ shift * 0.15,0,0);
    nine->addControlPoint(float2(-0.816
                                  ,0.616));
    nine->addControlPoint(float2(-0.696
                                  ,0.628));
    nine->addControlPoint(float2(-0.692
                                  ,0.848));
    nine->addControlPoint(float2(-0.72
                                  ,0.912));
    nine->addControlPoint(float2(-0.84
                                  ,0.892));
    nine->addControlPoint(float2(-0.832
                                  ,0.784));
    nine->addControlPoint(float2(-0.76
                                  ,0.748));
    
    nine->draw();
    glPopMatrix();
}

#endif
