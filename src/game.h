

typedef struct Player
{
    fm_vec3_t position;
} Player;

typedef struct Camera
{
    fm_vec3_t position;
    float pitch;
    float yaw;
} Camera;

typedef struct Game
{
    Camera camera;
    Player player;
} Game;