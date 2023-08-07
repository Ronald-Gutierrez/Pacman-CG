#ifndef MONSTEROBJECT_H
#define MONSTEROBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "texture.h"
class MonsterObject : public GameObject
{
public:
    // ball state
    unsigned int VAO;
    int     n_VAO;
    bool    Destroyed;
    glm::vec2   Velocity;
    // constructor(s)
    MonsterObject();
    ~MonsterObject();
    MonsterObject(glm::vec2 pos, glm::vec2 velocity);
    void    Draw(SpriteRenderer &renderer);
    // moves the ball, keeping it constrained within the window bounds (except bottom edge); returns new position
    glm::vec2 Move(float dt, unsigned int window_width);
    // resets the ball to original state with given position and velocity
    void      Reset(glm::vec2 position, glm::vec2 velocity);
};

#endif