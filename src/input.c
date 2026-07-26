#include <libdragon.h>
#include "input.h"
#include "game/camera.h"
#include "game/player.h"

float stick_value_to_movement_value(int8_t stick_value)
{
    return stick_value / 100;
}

void handleInput(Camera *camera, Player *player)
{
    joypad_inputs_t inputs = joypad_get_inputs(JOYPAD_PORT_1);

    player->position.y += stick_value_to_movement_value(inputs.stick_y);
    player->position.x += stick_value_to_movement_value(inputs.stick_x);
}