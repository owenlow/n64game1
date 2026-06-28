#include <libdragon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>
#include "game.h"
#include "camera.h"

void render_cube(Camera camera, GLfloat r, GLfloat g, GLfloat b)
{
    // Begin OpenGL compatibility with the RDP
    gl_context_begin();

    // Set the camera's position
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        0, -10.0, 0.0,
        0, 0, 0,
        0, 0, 1);

    // Draw the triangle
    glBegin(GL_TRIANGLES);
    glColor3f(r, g, b); // Red color
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd();

    // Does nothing for now, but keep it in case
    gl_context_end();
}