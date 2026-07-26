#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <libdragon.h>
#include "../renderer/mesh.h"

typedef struct Object
{
    fm_vec3_t pos;
    Mesh *mesh;
} Object;

void render_object(Object *object);

#endif