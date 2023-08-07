#include "coin_object.h"


CoinObject::CoinObject() 
    : GameObject(), Destroyed(false) {
        
        this->VAO = 2;
    this->n_VAO = 72;
    }

CoinObject::CoinObject(glm::vec2 pos, glm::vec3 size)
    : GameObject(pos, size), Destroyed(false)
{
        this->VAO = 2;
        this->n_VAO = 72;
}


CoinObject::~CoinObject()
{
    glDeleteVertexArrays(1, &this->VAO);
}

void CoinObject::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->Position, this->Size, this->Rotation);
    //renderer.DrawSprite(this->VAO, this->n_VAO, this->Position, this->Size, this->Rotation);
}


// resets the ball to initial Stuck Position (if ball is outside window bounds)
void CoinObject::Reset(glm::vec2 position)
{
    this->Position = position;
    this->Destroyed = false;
}