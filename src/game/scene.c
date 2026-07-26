#include "scene.h"
#include "../game/object.h"
#include "../renderer/mesh.h"

void scene_init(Scene *scene)
{
    scene->object_count = 0;
}

void scene_add_object(Scene *scene, Object *object)
{
    if (scene->object_count >= SCENE_MAX_OBJECT_COUNT)
    {
        return;
    }
    scene->objects[scene->object_count] = object;
    scene->object_count++;
}

void scene_render(Scene *scene)
{
    for (int i = 0; i < scene->object_count; i++)
    {
        render_mesh(scene->objects[i]->mesh);
    }
}