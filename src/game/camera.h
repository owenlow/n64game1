#ifndef CAMERA_H
#define CAMERA_H
#include <libdragon.h>

typedef struct Camera
{
    fm_vec3_t position;
    float pitch;
    float yaw;
} Camera;

fm_vec3_t calculateCenter(Camera *camera);

#endif