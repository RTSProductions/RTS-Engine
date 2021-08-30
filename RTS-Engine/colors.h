//
//  Colors.h
//  RTS-Engine
//
//  Created by Regin Hurley David on 8/28/21.
//

#ifndef colors_h
#define colors_h
#include <stdio.h>
#include <stdlib.h>



void GLFloatArrayToRGBColor(GLfloat color[], GLfloat R, GLfloat G, GLfloat B, int vertexCount)
{
    
    int j = 0;
    
    for (int i = 0; i < vertexCount * 3; i++)
    {
        if (j > 2)
        {
            j = 0;
        }
        if (j == 0)
        {
            color[i] = R;
        }
        if (j == 1)
        {
            color[i] = G;
        }
        if (j == 2)
        {
            color[i] = B;
        }
        j++;
    }
}
#endif /* Colors_h */
