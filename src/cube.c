#include <libdragon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>
#include "game.h"
#include "camera.h"

// uint32_t frame_count = 0;

void render_cube(Camera *camera, GLfloat r, GLfloat g, GLfloat b)
{
    fm_vec3_t pos = camera->position;
    fm_vec3_t center = calculateCenter(camera);
    fm_vec3_t up = {{0.0f, 0.0f, 1.0f}};
    // Begin OpenGL compatibility with the RDP
    gl_context_begin();

    // Set the camera's position
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(
        pos.x, pos.y, pos.z,
        center.x, center.y, center.z,
        up.x, up.y, up.z);

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