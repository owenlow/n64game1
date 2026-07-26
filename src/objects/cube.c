#include <libdragon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>
#include <stdlib.h>

#include "cube.h"
#include "../game/camera.h"
#include "../game/player.h"
#include "../renderer/mesh.h"

// uint32_t frame_count = 0;

Object *init_cube(GLfloat r, GLfloat g, GLfloat b)
{

    Object *result = malloc(sizeof(*result));
    Mesh *mesh = malloc(sizeof(*mesh));

    mesh->vertex_count = 3; // TODO: fix!
    mesh->vertices = malloc(mesh->vertex_count * sizeof(*mesh->vertices));
    mesh->vertices[0] = (fm_vec3_t){{-1.0f, -1.0f, -1.0f}};
    mesh->vertices[1] = (fm_vec3_t){{-1.0f, -1.0f, 1.0f}};
    mesh->vertices[2] = (fm_vec3_t){{1.0f, -1.0f, 1.0f}};

    result->mesh = mesh;

    return result;
}