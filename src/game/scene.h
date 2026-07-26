#ifndef SCENE_H
#define SCENE_H

#include "object.h"

#define SCENE_MAX_OBJECT_COUNT 16

typedef struct Scene
{
    Object *objects[SCENE_MAX_OBJECT_COUNT];
    uint8_t object_count;
} Scene;

void scene_init(Scene *scene);
void scene_add_object(Scene *scene, Object *object);
void scene_render(Scene *scene);

#endif