#include <libdragon.h>
#include <GL/gl.h>
// #include <GL/>
#include "camera.h"
#include "game.h"

fm_vec3_t calculateCenter(Camera *camera)
{

    float pitch = camera->pitch;
    float yaw = camera->yaw;
    fm_vec3_t forward = {{cosf(pitch) * sinf(yaw),
                          cosf(pitch) * cosf(yaw),
                          sinf(pitch)}};

    fm_vec3_t eye = camera->position;

    fm_vec3_t center = {{eye.x + forward.x,
                         eye.y + forward.y,
                         eye.z + forward.z}};

    return center;
}