
#include "game_object.h"


GameObject::GameObject() 
    : Position(0.0f, 0.0f), Size(1.0f, 1.0f, 1.0f), Rotation(0.0f) { }

GameObject::GameObject(glm::vec2 pos, glm::vec3 size) 
    : Position(pos), Size(size), Rotation(0.0f) { }

void GameObject::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->Position, this->Size, this->Rotation);
}