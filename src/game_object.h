
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "texture.h"
#include "sprite_renderer.h"
#include "shader.h"
// Container object for holding all state relevant for a single
// game object entity. Each object in the game likely needs the
// minimal of state as described within GameObject.
class GameObject
{
public:
    // object state
    glm::vec2   Position;
    glm::vec3   Size;
    float       Rotation;
    // render state
    // constructor(s)
    GameObject();
    GameObject(glm::vec2 pos, glm::vec3 size);
    // draw sprite
    virtual void Draw(SpriteRenderer &renderer);
};

#endif