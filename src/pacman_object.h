#ifndef PACMANOBJECT_H
#define PACMANOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "texture.h"


class PacmanObject : public GameObject
{
public:
    // ball state
    unsigned int VAO;
    int     n_VAO;
    bool    StateAgressive;
    int Direction;//8 UP - 2 DOWN - 4 LEFT - 6 RIGHT
    float   Velocity;
    int points;
    // constructor(s)
    PacmanObject();
    ~PacmanObject();
    PacmanObject(glm::vec2 pos, glm::vec3 size, float velocity);
    void    Draw(SpriteRenderer &renderer);
    // moves the ball, keeping it constrained within the window bounds (except bottom edge); returns new position
    glm::vec2 Move(float dt, unsigned int window_width);
    // resets the ball to original state with given position and velocity
    void      Reset(glm::vec2 position, float velocity);
};

#endif