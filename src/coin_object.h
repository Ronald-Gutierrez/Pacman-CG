#ifndef COINOBJECT_H
#define COINOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "texture.h"


// BallObject holds the state of the Ball object inheriting
// relevant state data from GameObject. Contains some extra
// functionality specific to Breakout's ball object that
class CoinObject : public GameObject
{
public:
    // ball state
    unsigned int VAO;
    int     n_VAO;
    bool    Destroyed;
    // constructor(s)
    CoinObject();
    CoinObject(glm::vec2 pos, glm::vec3 size);
    ~CoinObject();
    void    Draw(SpriteRenderer &renderer);
    // resets the ball to original state with given position and velocity
    void      Reset(glm::vec2 position);
};

#endif