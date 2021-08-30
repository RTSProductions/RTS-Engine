//
//  shapes.h
//  RTS-Engine
//
//  Created by Regin Hurley David on 8/29/21.
//

#ifndef shapes_h
#define shapes_h

#include "vector.h"
#include <math.h>

void DrawRectangle(Vector2 originPoint, Vector2 scale, GLfloat color[])
{
    float xPos = originPoint.x;
    float yPos = originPoint.y;
    float xScale = scale.x  / 2;
    float yScale = scale.y / 2;
    
    GLfloat vertices[] =
    {
        xPos - xScale, yPos + yScale, 0.0, /* Top left corner */
        xPos + xScale, yPos + yScale, 0.0, /* Top right corner */
        xPos + xScale, yPos - yScale, 0.0, /* Bottom left corner */
        xPos - xScale, yPos - yScale, 0.0 /* Bottom right corner */
    };
    

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, color);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
};

void DrawTriangle(Vector2 originPoint, Vector2 scale, GLfloat color[])
{
    float xPos = originPoint.x;
    float yPos = originPoint.y;
    float xScale = scale.x  / 2;
    float yScale = scale.y / 2;
    
    GLfloat vertices[] =
    {
        xPos, yPos + yScale, 0.0, /* Top */
        xPos + xScale, yPos - yScale, 0.0, /* Bottom left corner */
        xPos - xScale, yPos - yScale, 0.0 /* Bottom right corner */
    };
    

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, color);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
};

void DrawCircle(Vector2 originPoint, Vector2 scale, int numberOfSides, GLfloat color[])
{
    int numberOfVertices = numberOfSides + 2;
    
    float x = originPoint.x;
    float y = originPoint.y;
        
    GLfloat twicePi = 2.0f * M_PI;
    
    GLfloat circleVerticesX[numberOfVertices];
    GLfloat circleVerticesY[numberOfVertices];
    GLfloat circleVerticesZ[numberOfVertices];
    
    circleVerticesX[0] = x;
    circleVerticesY[0] = y;
    circleVerticesZ[0] = 0;
        
    for (int i = 1; i < numberOfVertices; i++)
    {
        circleVerticesX[i] = x + ((scale.x / 2) * cos(i * twicePi / numberOfSides));
        circleVerticesY[i] = y + ((scale.y / 2) * sin(i * twicePi / numberOfSides));
        circleVerticesZ[i] = 0;
    }
    
    GLfloat allCircleVertices[( numberOfVertices ) * 3];
    
    for ( int i = 0; i < numberOfVertices; i++ )
    {
        allCircleVertices[i * 3] = circleVerticesX[i];
        allCircleVertices[( i * 3 ) + 1] = circleVerticesY[i];
        allCircleVertices[( i * 3 ) + 2] = circleVerticesZ[i];
    }
    
    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, allCircleVertices );
    glDrawArrays( GL_TRIANGLE_FAN, 0, numberOfVertices);
    glDisableClientState( GL_VERTEX_ARRAY );

};

enum Shape
{
    Rectangle,
    Circle,
    Triangle
};

class Shape2D
{
public:
    Vector2 OriginPoint = Vector2(0, 0);
    Vector2 Scale = Vector2(0, 0);
    GLfloat* color = nullptr;
    Shape shapeType;
    
    Shape2D(float xScale, float yScale, float xPos, float yPos, Shape type)
    {
        Scale = Vector2(xScale, yScale);
        OriginPoint = Vector2(xPos, yPos);
        shapeType = type;
        if (shapeType == Rectangle)
        {
            color = new GLfloat[12];
        }
        if (shapeType == Triangle)
        {
            color = new GLfloat[9];
        }
        if (shapeType == Circle)
        {
            color = new GLfloat[362];
        }
    }
    ~Shape2D()
    {
        if (color != nullptr)
        {
            delete [] color;
        }
    }
    
    void Render()
    {
        if (shapeType == Rectangle)
        {
            DrawRectangle(OriginPoint, Scale, color);
        }
        if (shapeType == Triangle)
        {
            DrawTriangle(OriginPoint, Scale, color);
        }
        if (shapeType == Circle)
        {
            DrawCircle(OriginPoint, Scale, 360, color);
        }
    }
    
};

#endif /* shapes_h */
