//
//  vector2.h
//  RTS-Engine
//
//  Created by Regin Hurley David on 8/29/21.
//

#ifndef vector2_h
#define vector2_h

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
