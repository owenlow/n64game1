#include <libdragon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>
#include "mesh.h"

void render_mesh(Mesh *mesh)
{
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0); // Red color

    fm_vec3_t vertex;
    for (int i = 0; i < mesh->vertex_count; ++i)
    {
        vertex = mesh->vertices[i];
        glVertex3f(vertex.x, vertex.y, vertex.z);
    }

    glEnd();
}