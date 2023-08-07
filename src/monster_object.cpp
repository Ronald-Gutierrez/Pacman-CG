#include "monster_object.h"


MonsterObject::MonsterObject() 
    : GameObject(), Destroyed(false)
{
    this->VAO = 3;
    this->n_VAO = 60;
}

MonsterObject::MonsterObject(glm::vec2 pos, glm::vec2 velocity)
    : GameObject(pos, glm::vec3(2.0f, 2.0f, 2.0f)), Velocity(velocity), Destroyed(false)
{
    this->VAO = 3;
    this->n_VAO = 60;
}


MonsterObject::~MonsterObject()
{
    glDeleteVertexArrays(1, &this->VAO);
}

void MonsterObject::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->VAO, this->n_VAO, this->Position, this->Size, this->Rotation);
}

glm::vec2 MonsterObject::Move(float dt, unsigned int window_width)
{
    // if not stuck to player board
    if (!this->Destroyed)
    {
        // move the ball
        this->Position += this->Velocity * dt;
        // then check if outside window bounds and if so, reverse velocity and restore at correct position
        if (this->Position.x <= 0.0f)
        {
            this->Velocity.x = -this->Velocity.x;
            this->Position.x = 0.0f;
        }
        else if (this->Position.x + this->Size.x >= window_width)
        {
            this->Velocity.x = -this->Velocity.x;
            this->Position.x = window_width - this->Size.x;
        }
        if (this->Position.y <= 0.0f)
        {
            this->Velocity.y = -this->Velocity.y;
            this->Position.y = 0.0f;
        }
    }
    return this->Position;
}

// resets the ball to initial Stuck Position (if ball is outside window bounds)
void MonsterObject::Reset(glm::vec2 position, glm::vec2 velocity)
{
    this->Position = position;
    this->Velocity = velocity;
    this->Destroyed = false;
}