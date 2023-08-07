#include "pacman_object.h"


PacmanObject::PacmanObject() 
    : GameObject(), StateAgressive(false)
{
    this->VAO = 1;
    this->n_VAO = 72;
}

PacmanObject::PacmanObject(glm::vec2 pos, glm::vec3 size, float velocity)
    : GameObject(pos, size), Velocity(velocity), StateAgressive(false), Direction(8)
{
    this->VAO = 1;
    this->n_VAO = 72;
}


PacmanObject::~PacmanObject()
{
    glDeleteVertexArrays(1, &this->VAO);
}

void PacmanObject::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->VAO, this->n_VAO, this->Position, this->Size, this->Rotation);
}

// resets the ball to initial Stuck Position (if ball is outside window bounds)
void PacmanObject::Reset(glm::vec2 position, float velocity)
{
    this->Position = position;
    this->Velocity = velocity;
    this->StateAgressive = false;
}