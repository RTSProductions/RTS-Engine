#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "Headers/RTS-EngineHeaders.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(void)
{
    GLFWwindow *window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RTS-Engine", NULL, NULL);



    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    glViewport( 0.0f, 0.0f, screenWidth, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;

    GLfloat halfSideLength = 200;

    GLfloat vertices[] =
    {
        halfScreenWidth, halfScreenHeight + halfSideLength, 0.0, // top center vertex
        halfScreenWidth - halfSideLength, halfScreenHeight - halfSideLength, 0.0, // bottom left corner
        halfScreenWidth + halfSideLength, halfScreenHeight - halfSideLength, 0.0 // bottom right corner
    };

    GLfloat color[] =
    {
        255, 0, 0,
        0, 255, 0,
        0, 0, 255
    };
    
    Shape2D square(100, 100, 100, 100, Rectangle);
    GLFloatArrayToRGBColor(square.color, 0, 255, 0, 4);
    
    Shape2D tri(100, 100, 100, 250, Triangle);
    GLFloatArrayToRGBColor(tri.color, 255, 0, 0, 4);
    
    Shape2D circle(100, 100, 100, 360, Circle);
    GLFloatArrayToRGBColor(circle.color, 0, 0, 255, 4);
    
    
    glClearColor(0, 0, 0, 1);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render OpenGL here
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glColorPointer(3, GL_FLOAT, 0, color);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
        
        square.OriginPoint.x += 1;
        
        square.Render();
        
        tri.OriginPoint.x += 1;
        
        tri.Render();
        
        circle.OriginPoint.x += 1;
        
        circle.Render();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
