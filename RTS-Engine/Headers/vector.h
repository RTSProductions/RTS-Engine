//
//  vector2.h
//  RTS-Engine
//
//  Created by Regin Hurley David on 8/29/21.
//

#ifndef vector_h
#define vector_h

/* 2D position in world */
class Vector2
{
public:
    float x;
    float y;
    Vector2(float X, float Y)
    {
        x = X;
        y = Y;
    }
};

/* 3D position in world space */
class Vector3
{
public:
    float x;
    float y;
    float z;
    Vector3(float X, float Y, float Z)
    {
        x = X;
        y = Y;
        z = Z;
    }
};

#endif /* vector2_h */
