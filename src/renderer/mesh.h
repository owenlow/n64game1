#ifndef MESH_H
#define MESH_H

#include <libdragon.h>

typedef struct Mesh
{
    fm_vec3_t *vertices;
    uint8_t vertex_count;
} Mesh;

void render_mesh(Mesh *mesh);

#endif