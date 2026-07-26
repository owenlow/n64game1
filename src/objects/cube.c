#include <libdragon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>

#include "cube.h"
#include "../game/camera.h"
#include "../game/player.h"

// uint32_t frame_count = 0;

void render_cube(Camera *camera, Player *player, GLfloat r, GLfloat g, GLfloat b)
{

    // Draw the triangle
    glBegin(GL_TRIANGLES);
    glColor3f(r, g, b); // Red color
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd();
}