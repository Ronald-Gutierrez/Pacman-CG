#ifndef FRUITOBJECT_H
#define FRUITOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "texture.h"


class FruitObject : public GameObject
{
public:
    // ball state
    unsigned int VAO;
    int     n_VAO;
    bool    Destroyed;
    // constructor(s)
    FruitObject();
    FruitObject(glm::vec2 pos);
    ~FruitObject();
    void    Draw(SpriteRenderer &renderer);
    // resets the ball to original state with given position and velocity
    void      Reset(glm::vec2 position);
};

#endif