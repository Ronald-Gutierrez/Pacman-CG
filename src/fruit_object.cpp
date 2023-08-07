#include "fruit_object.h"


FruitObject::FruitObject() 
    : GameObject(), Destroyed(false) 
{
    this->VAO = 2;
    this->n_VAO = 72;
}

FruitObject::FruitObject(glm::vec2 pos)
    : GameObject(pos, glm::vec3(2.0f, 2.0f, 2.0f)), Destroyed(false)
{
    this->VAO = 2;
    this->n_VAO = 72;
}


FruitObject::~FruitObject()
{
    glDeleteVertexArrays(1, &this->VAO);
}

void FruitObject::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->VAO, this->n_VAO, this->Position, this->Size, this->Rotation);
}


// resets the ball to initial Stuck Position (if ball is outside window bounds)
void FruitObject::Reset(glm::vec2 position)
{
    this->Position = position;
    this->Destroyed = false;
}