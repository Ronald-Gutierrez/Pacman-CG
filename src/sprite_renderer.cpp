
#include "sprite_renderer.h"
#include <iostream>

SpriteRenderer::SpriteRenderer(Shader &shader, Shader &shader_color)
{
    this->shader = shader;
    this->shader_color = shader_color;
    this->initRenderData();
}

SpriteRenderer::~SpriteRenderer()
{
    glDeleteVertexArrays(10, this->VAOs);
}

void SpriteRenderer::DrawSprite(glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color)
{   

    // prepare transformations
    this->shader.Use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position.x, 0.0f, position.y));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)
    model = glm::scale(model, glm::vec3(size.x, size.y, size.x));
    //model = glm::scale(model, glm::vec3(size, size.x)); // last scale

    this->shader.SetMatrix4("model", model);

    glActiveTexture(GL_TEXTURE0);
    ResourceManager::GetTexture("block").Bind();
    //texture.Bind();

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36); //36 porque son cubos
    glBindVertexArray(0);
}


void SpriteRenderer::DrawSprite(unsigned int &vao, int n_VAO, glm::vec2 position, glm::vec3 size, float rotate)
{   
    // prepare transformations
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    this->shader_color.Use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position.x, 0.0f, position.y ));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)

    //model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f)); // move origin of rotation to center of quad
    //model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate
    //model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f)); // move origin back

    //model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f)); // last scale
    model = glm::scale(model, size); // last scale

    this->shader_color.SetMatrix4("model", model);

    glBindVertexArray(this->VAOs[vao]);
    glDrawArrays(GL_TRIANGLES, 0, n_VAO);
    glBindVertexArray(0);
}

void SpriteRenderer::initRenderData()
{


    float vertices[] = {
        //pos                 //tex
         0.0f,  0.0f,  0.0f,  0.0f, 0.0f,
         1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         1.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
         0.0f,  0.0f,  0.0f,  0.0f, 0.0f,

         0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
         1.0f,  0.0f,  1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
         0.0f,  1.0f,  1.0f,  0.0f, 1.0f,
         0.0f,  0.0f,  1.0f,  0.0f, 0.0f,

         0.0f,  1.0f,  1.0f,  1.0f, 0.0f,
         0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         0.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
         0.0f,  1.0f,  1.0f,  1.0f, 0.0f,

         1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         1.0f,  0.0f,  1.0f,  0.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 0.0f,

         0.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
         1.0f,  0.0f,  1.0f,  1.0f, 0.0f,
         1.0f,  0.0f,  1.0f,  1.0f, 0.0f,
         0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
         0.0f,  0.0f,  0.0f,  0.0f, 1.0f,

         0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
         1.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
         0.0f,  1.0f,  1.0f,  0.0f, 0.0f,
         0.0f,  1.0f,  0.0f,  0.0f, 1.0f
    };
    


    //pacman
    float pacman[] = {
        //la perpectiva esta mal, por eso en main le hice una
        //rotacion como deberia estar
        //posiciones        //colores
        //cara de abajo
         0.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  1.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,

        //cara de arriba
         0.0f,  0.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  0.0f,  1.0f,  1.0f, 1.0f, 0.0f,

        //cara de atras
         0.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  1.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  0.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,

        //cara de adelante
        //Frente
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  0.5f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  0.5f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  0.5f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,
        
        //Menton
         1.0f,  1.0f,  0.1f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  0.1f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  0.1f,  1.0f, 1.0f, 0.0f,

        //Ojos
        //ojo derecho
         1.001f,  0.75f,  0.80f,  0.0f, 0.0f, 0.0f,
         1.001f,  0.65f,  0.70f,  0.0f, 0.0f, 0.0f,
         1.001f,  0.85f,  0.70f,  0.0f, 0.0f, 0.0f,
        //ojo izquierdo
         1.001f,  0.25f,  0.80f,  0.0f, 0.0f, 0.0f,
         1.001f,  0.35f,  0.70f,  0.0f, 0.0f, 0.0f,
         1.001f,  0.15f,  0.70f,  0.0f, 0.0f, 0.0f,
        
        //Boca
        //parte superior
         0.5f,  1.0f,  0.5f,  1.0f, 0.0f, 0.0f,
         1.0f,  1.0f,  0.5f,  1.0f, 0.0f, 0.0f,
         1.0f,  0.0f,  0.5f,  1.0f, 0.0f, 0.0f,
         1.0f,  0.0f,  0.5f,  1.0f, 0.0f, 0.0f,
         0.5f,  0.0f,  0.5f,  1.0f, 0.0f, 0.0f,
         0.5f,  1.0f,  0.5f,  1.0f, 0.0f, 0.0f,
        
        //parte lengua
         0.5f,  1.0f,  0.5f,  1.0f, 0.0f, 0.0f,
         1.0f,  1.0f,  0.1f,  1.0f, 0.0f, 0.0f,
         1.0f,  0.0f,  0.1f,  1.0f, 0.0f, 0.0f,
         1.0f,  0.0f,  0.1f,  1.0f, 0.0f, 0.0f,
         0.5f,  0.0f,  0.5f,  1.0f, 0.0f, 0.0f,
         0.5f,  1.0f,  0.5f,  1.0f, 0.0f, 0.0f,

        //cara izquierda
         0.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  0.0f,  1.0f,  1.0f, 1.0f, 0.0f,

         0.0f,  0.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         0.5f,  0.0f,  0.5f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  1.0f,  1.0f, 1.0f, 0.0f,

         0.5f,  0.0f,  0.5f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  0.5f,  1.0f, 1.0f, 0.0f,
        
        //triangulo delgado
         1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  0.0f,  0.1f,  1.0f, 1.0f, 0.0f,
         0.5f,  0.0f,  0.5f,  1.0f, 1.0f, 0.0f,

        //cara derecha
         0.0f,  1.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         0.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,

         0.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         0.5f,  1.0f,  0.5f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,

         0.5f,  1.0f,  0.5f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  0.5f,  1.0f, 1.0f, 0.0f,
         //triangulo delgado
         1.0f,  1.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         1.0f,  1.0f,  0.1f,  1.0f, 1.0f, 0.0f,
         0.5f,  1.0f,  0.5f,  1.0f, 1.0f, 0.0f,
        };

    


    float fruit[] = {
        //cara de atras
        -0.2f, -0.3f, -0.2f,  1.0f, 0.0f, 0.0f,
         0.2f, -0.3f, -0.2f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f, -0.3f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f, -0.3f,  1.0f, 0.0f, 0.0f,
        -0.3f,  0.1f, -0.3f,  1.0f, 0.0f, 0.0f,
        -0.2f, -0.3f, -0.2f,  1.0f, 0.0f, 0.0f,

        -0.1f,  0.3f, -0.1f,  1.0f, 0.0f, 0.0f,
         0.1f,  0.3f, -0.1f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f, -0.3f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f, -0.3f,  1.0f, 0.0f, 0.0f,
        -0.3f,  0.1f, -0.3f,  1.0f, 0.0f, 0.0f,
        -0.1f,  0.3f, -0.1f,  1.0f, 0.0f, 0.0f,
        //cara de adelante
        -0.2f, -0.3f,  0.2f,  1.0f, 0.0f, 0.0f,
         0.2f, -0.3f,  0.2f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
        -0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
        -0.2f, -0.3f,  0.2f,  1.0f, 0.0f, 0.0f,

        -0.1f,  0.3f,  0.1f,  1.0f, 0.0f, 0.0f,
         0.1f,  0.3f,  0.1f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
        -0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
        -0.1f,  0.3f,  0.1f,  1.0f, 0.0f, 0.0f,
        //cara derecha de la fruta
        -0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
        -0.3f,  0.1f, -0.3f,  1.0f, 0.0f, 0.0f,
        -0.2f, -0.3f, -0.2f,  1.0f, 0.0f, 0.0f,
        -0.2f, -0.3f, -0.2f,  1.0f, 0.0f, 0.0f,
        -0.2f, -0.3f,  0.2f,  1.0f, 0.0f, 0.0f,
        -0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,

        -0.3f,  0.1f, -0.3f,  1.0f, 0.0f, 0.0f,
        -0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
        -0.1f,  0.3f, -0.1f,  1.0f, 0.0f, 0.0f,
        -0.1f,  0.3f, -0.1f,  1.0f, 0.0f, 0.0f,
        -0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
        -0.1f,  0.3f,  0.1f,  1.0f, 0.0f, 0.0f,
        //cara izqueirda
         0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f, -0.3f,  1.0f, 0.0f, 0.0f,
         0.2f, -0.3f, -0.2f,  1.0f, 0.0f, 0.0f,
         0.2f, -0.3f, -0.2f,  1.0f, 0.0f, 0.0f,
         0.2f, -0.3f,  0.2f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,

         0.3f,  0.1f, -0.3f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
         0.1f,  0.3f, -0.1f,  1.0f, 0.0f, 0.0f,
         0.1f,  0.3f, -0.1f,  1.0f, 0.0f, 0.0f,
         0.3f,  0.1f,  0.3f,  1.0f, 0.0f, 0.0f,
         0.1f,  0.3f,  0.1f,  1.0f, 0.0f, 0.0f,
        //cara abajo
        -0.2f, -0.3f, -0.2f,  1.0f, 0.0f, 0.0f,
         0.2f, -0.3f, -0.2f,  1.0f, 0.0f, 0.0f,
         0.2f, -0.3f,  0.2f,  1.0f, 0.0f, 0.0f,
         0.2f, -0.3f,  0.2f,  1.0f, 0.0f, 0.0f,
        -0.2f, -0.3f,  0.2f,  1.0f, 0.0f, 0.0f,
        -0.2f, -0.3f, -0.2f,  1.0f, 0.0f, 0.0f,
        //cara arriba
        -0.1f,  0.3f, -0.1f,  1.0f, 0.0f, 0.0f,
         0.1f,  0.3f, -0.1f,  1.0f, 0.0f, 0.0f,
         0.1f,  0.3f,  0.1f,  1.0f, 0.0f, 0.0f,
         0.1f,  0.3f,  0.1f,  1.0f, 0.0f, 0.0f,
        -0.1f,  0.3f,  0.1f,  1.0f, 0.0f, 0.0f,
        -0.1f,  0.3f, -0.1f,  1.0f, 0.0f, 0.0f,
        //hojita
         0.0f,  0.3f,  0.0f,  0.0f, 1.0f, 0.0f,
         0.35f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f,
         0.35f,  0.4f,  0.0f,  0.0f, 1.0f, 0.0f,

         0.0f,  0.3f,  0.0f,  0.0f, 1.0f, 0.0f,
        -0.35f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f,
        -0.35f,  0.4f,  0.0f,  0.0f, 1.0f, 0.0f,

         0.0f,  0.3f,  0.0f,   0.0f, 1.0f, 0.0f,
         0.0f,  0.5f,  0.35f,  0.0f, 1.0f, 0.0f,
         0.0f,  0.4f,  0.35f,  0.0f, 1.0f, 0.0f,

         0.0f,  0.3f,  0.0f,  0.0f, 1.0f, 0.0f,
         0.0f,  0.5f,  -0.35f,  0.0f, 1.0f, 0.0f,
         0.0f,  0.4f,  -0.35f,  0.0f, 1.0f, 0.0f,
    };

    float monster[] = {
        //perspectiva de la camara desde tras del monster
        //cara de atras
        -0.5f, -0.2f, -0.5f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.2f, -0.5f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.2f, -0.5f,  0.0f, 0.0f, 1.0f,


        //cara de adelante
        -0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
        //ojos
         0.25f, 0.15f, 0.501f,  1.0f, 0.0f, 0.0f,
         0.10f, 0.30f, 0.501f,  1.0f, 0.0f, 0.0f,
         0.40f, 0.30f, 0.501f,  1.0f, 0.0f, 0.0f,
        -0.25f, 0.15f, 0.501f,  1.0f, 0.0f, 0.0f,
        -0.10f, 0.30f, 0.501f,  1.0f, 0.0f, 0.0f,
        -0.40f, 0.30f, 0.501f,  1.0f, 0.0f, 0.0f,
        //boca
         0.0f,   0.1f, 0.501f,  1.0f, 0.0f, 0.0f,
         0.25f, -0.1f, 0.501f,  1.0f, 0.0f, 0.0f,
        -0.25f, -0.1f, 0.501f,  1.0f, 0.0f, 0.0f,
        //tentaculos adelante 1
        -0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.2f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.2f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.2f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
        //tentaculos adelante 2
        -0.15f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.15f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.15f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.15f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.15f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.15f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
        //tentaculos adelante 3
         0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.2f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.2f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.2f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,

        
        //cara derecha
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.2f, -0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.2f, -0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,

        //cara izquierda
         0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.2f, -0.5f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.2f, -0.5f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,

        //cara abajo
        -0.5f, -0.2f, -0.5f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.2f, -0.5f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.2f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.2f, -0.5f,  0.0f, 0.0f, 1.0f,


        //cara arriba
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
        
    };

    // configure VAO/VBO
    unsigned int VBO;
    glGenVertexArrays(1, &this->quadVAO);

    glGenBuffers(1, &VBO);
    glBindVertexArray(this->quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);



        // configure VAO/VBO
    unsigned int VBOs[5];
    glGenVertexArrays(5, this->VAOs);
    glGenBuffers(5, VBOs);



    //glBindVertexArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    
    glBindVertexArray(this->VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(pacman), pacman, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //glBindVertexArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(this->VAOs[2]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(fruit), fruit, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //glBindVertexArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(this->VAOs[3]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(monster), monster, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //glBindVertexArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindVertexArray(0);
    
}