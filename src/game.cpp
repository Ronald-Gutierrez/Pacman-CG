/*******************************************************************
Pacman 3D
******************************************************************/
#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"
#include "game_object.h"
//#include "ball_object.h"
#include "pacman_object.h"
#include "text_renderer.h"
// #include <irrklang/irrKlang.h>
// using namespace irrklang;


  
// Game-related State data
#include <iostream>
PacmanObject    *Pacman;
SpriteRenderer  *Renderer;

float conAgressive = 0.0f; //contador de segundo del estado agresivo del pacman
const float AGGRESSIVE_TIME = 5.0f;
// ISoundEngine *SoundEngine = createIrrKlangDevice();

Game::Game(unsigned int width, unsigned int height, Camera &camera) 
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height), GameCamera(camera)
{ 

}

Game::~Game()
{
    delete Renderer;
    delete Pacman;
}

TextRenderer  *Text;
void Game::Init()
{

    // load shaders
    ResourceManager::LoadShader("../src/shaders/sprite.vs", "../src/shaders/sprite.frag", nullptr, "sprite");
    ResourceManager::LoadShader("../src/shaders/sprite_color.vs", "../src/shaders/sprite_color.frag", nullptr, "sprite_color");
    // configure shaders
    //glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), 
        //static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    glm::mat4 projection = glm::perspective(glm::radians(this->GameCamera.Zoom), (float)this->Width / (float)this->Height, 0.1f, 100.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    // camera
    glm::mat4 view = this->GameCamera.GetViewMatrix();//este el gluLookAt
    ResourceManager::GetShader("sprite").SetMatrix4("view", view);
    //replicando view y projection en sprite_color
    ResourceManager::GetShader("sprite_color").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite_color").SetMatrix4("projection", projection);
    ResourceManager::GetShader("sprite_color").SetMatrix4("view", view);

    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"), ResourceManager::GetShader("sprite_color"));
    //RendererObjects = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    // load textures
    ResourceManager::LoadTexture("../src/textures/background.jpg", false, "background");
    ResourceManager::LoadTexture("../src/textures/block.png", false, "block");
    ResourceManager::LoadTexture("../src/textures/block_solid.png", false, "block_solid");
    ResourceManager::LoadTexture("../src/textures/muro.jpg", false, "muro");
    //Load Texto
    Text = new TextRenderer(this->Width, this->Height);
    Text->Load("../fonts/OCRAEXT.TTF", 24);
    ResourceManager::LoadShader("../src/text_2d.vs", "..src/text_2d.fs", nullptr, "text");
    
    // load levels
    GameLevel one; one.Load("../src/levels/one.lvl", this->Width, this->Height);
    GameLevel two; two.Load("../src/levels/two.lvl", this->Width, this->Height);
    GameLevel three; three.Load("../src/levels/three.lvl", this->Width, this->Height);
    GameLevel four; four.Load("../src/levels/four.lvl", this->Width, this->Height);
    this->Levels.push_back(one);
    this->Levels.push_back(two);
    this->Levels.push_back(three);
    this->Levels.push_back(four);
    this->Level = 0;
    // configure game objects
    //estas variables estan en game.h
    Pacman = new PacmanObject(glm::vec2(3.0f, 3.0f), PLAYER_SIZE, PLAYER_VELOCITY);
    //Monster = new MonsterObject
    //Load Texto
    // audio
    // SoundEngine->play2D("../audio/breakout.mp3", true);
}

void Game::ProcessInput(float dt)
{
    if (this->State == GAME_ACTIVE){
        float velocity = Pacman->Velocity * dt;
        if (this->Keys[GLFW_KEY_T]){
            Pacman->Direction = 8;
            //Pacman->Rotation = glm::vec3(0.0f, 1.0f)
            Pacman->Position = Pacman->Position + glm::vec2(0.0f, velocity);
        }
        if (this->Keys[GLFW_KEY_G]){
            Pacman->Direction = 2;
            Pacman->Position = Pacman->Position - glm::vec2(0.0f, velocity);
        }
        if (this->Keys[GLFW_KEY_F]){
            Pacman->Direction = 4;
            Pacman->Position = Pacman->Position + glm::vec2(velocity, 0.0f);
        }
        if (this->Keys[GLFW_KEY_H]){
            Pacman->Direction = 6;
            Pacman->Position = Pacman->Position - glm::vec2(velocity, 0.0f);
        }

        //esto es para el estado agresivo del pacman
        if(Pacman->StateAgressive == true){
            conAgressive += dt;
            if((conAgressive > AGGRESSIVE_TIME)){
                Pacman->StateAgressive = false;
                Pacman->Size = PLAYER_SIZE;
                conAgressive = 0.0f;
            }
        }
    }
}

void Game::Update(float dt)
{
    // update objects
    //Ball->Move(dt, this->Width);
     // check for collisions
    this->DoCollisions();
    // check loss condition
    //if (Ball->Position.y >= this->Height) // did ball reach bottom edge?
    //{
    //    this->ResetLevel();
    //    this->ResetPlayer();
    //}
    glm::mat4 projection = glm::perspective(glm::radians(this->GameCamera.Zoom), (float)this->Width / (float)this->Height, 0.1f, 100.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // camera
    glm::mat4 view = this->GameCamera.GetViewMatrix();
    //printMatrix(view);
    ResourceManager::GetShader("sprite").SetMatrix4("view", view);

    ResourceManager::GetShader("sprite_color").Use();
    ResourceManager::GetShader("sprite_color").SetMatrix4("projection", projection);
    ResourceManager::GetShader("sprite_color").SetMatrix4("view", view);
    this->Lives=3;
    if (Pacman->StateAgressive)
    {
        showAggressiveCounter = true;
        conAgressive += dt;
        if (conAgressive > AGGRESSIVE_TIME)
        {
            Pacman->StateAgressive = false;
            Pacman->Size = PLAYER_SIZE;
            conAgressive = 0.0f;
            showAggressiveCounter = false;
        }
    }
    // if (Pacman->Position.y >= this->Height) // did ball reach bottom edge?
    // {
    //     --this->Lives;
    //     // did the player lose all his lives? : Game over
    //     if (this->Lives == 0)
    //     {
    //         this->ResetLevel();
    //         // this->State = GAME_MENU;
    //     }
    //     this->ResetPlayer();
    // }

}
// collision detection
bool CheckCollisionPacmanCoin(GameObject &one, GameObject &two);
bool CheckCollision(GameObject &one, GameObject &two);
//Collision CheckCollision(PacmanObject &one, GameObject &two);
//Direction VectorDirection(glm::vec2 closest);


void Game::Render()
{   
    if(this->State == GAME_ACTIVE)
    {
        // draw background
        //Renderer->DrawSprite(ResourceManager::GetTexture("background"), glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
        // draw level
        Pacman->Draw(*Renderer);
        this->Levels[this->Level].Draw(*Renderer);
        //texto de puntaje
        Text->RenderText("Puntaje:" + std::to_string(Pacman->points), 5.0f, 5.0f, 1.0f);
        // Texto de vidas
        Text->RenderText("Vidas: " + std::to_string(this->Lives), this->Width - 150.0f, 5.0f, 1.0f);
        if (showAggressiveCounter)
        {
            float x = this->Width / 2.0f - 100.0f; 
            float y = 50.0f; 
            float scale = 1.0f;

            int secondsRemaining = static_cast<int>(AGGRESSIVE_TIME - conAgressive);
            Text->RenderText("Modo Agresivo: " + std::to_string(secondsRemaining) + "s", x, y, scale);
        }
    }
    
}


void Game::ResetLevel()
{

    if (this->Level == 0)
        this->Levels[0].Load("levels/one.lvl", this->Width, this->Height / 2);
    else if (this->Level == 1)
        this->Levels[1].Load("levels/two.lvl", this->Width, this->Height / 2);
    else if (this->Level == 2)
        this->Levels[2].Load("levels/three.lvl", this->Width, this->Height / 2);
    else if (this->Level == 3)
        this->Levels[3].Load("levels/four.lvl", this->Width, this->Height / 2);

    this->Lives = 3;
}

void Game::ResetPlayer()
{
    // reset player/ball stats
    Pacman->Size = PLAYER_SIZE;
    Pacman->Position = glm::vec2(this->Width / 2.0f - PLAYER_SIZE.x / 2.0f, this->Height - PLAYER_SIZE.y);
    //Ball->Reset(Player->Position + glm::vec2(PLAYER_SIZE.x / 2.0f - BALL_RADIUS, -(BALL_RADIUS * 2.0f)), INITIAL_BALL_VELOCITY);
}


void Game::DoCollisions()
{
    for (CoinObject &coin : this->Levels[this->Level].Coins)
    {
        if(!coin.Destroyed){
            bool collision = CheckCollision(*Pacman, coin);
            if (collision) // if collision is true
            {
                coin.Destroyed = true;
                Pacman->points++;
                // std::cout<<"Comi un coin\n";
            }
        }
    }
    for (FruitObject &fruit : this->Levels[this->Level].Fruits)
    {
        if(!fruit.Destroyed){
            bool collision = CheckCollision(*Pacman, fruit);
            if (collision) // if collision is true
            {
                fruit.Destroyed = true;
                Pacman->Size = PLAYER_SIZE * 1.3f;
                Pacman->StateAgressive = true;
            }
        }
    }
    for (GameObject &box : this->Levels[this->Level].Bricks)
    {
        bool collision = CheckCollision(*Pacman, box);
        if(collision){
            if(Pacman->Direction  == 8){ //UP
                Pacman->Position.y = box.Position.y - Pacman->Size.y - 0.05f;
            }
            if(Pacman->Direction  == 2){ //DOWN
                Pacman->Position.y = box.Position.y + box.Size.y + 0.05f;
            }
            if(Pacman->Direction  == 6){ //RIGHT
                Pacman->Position.x = box.Position.x + box.Size.x + 0.05f;
            }
            if(Pacman->Direction  == 4){ //LEFT
                Pacman->Position.x = box.Position.x - Pacman->Size.x - 0.05f;
            }
        }
    }
}


//colision entre el pacman y los coins
bool CheckCollision(GameObject &one, GameObject &two) // AABB - AABB collision
{
    // collision x-axis
    bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
        two.Position.x + two.Size.x >= one.Position.x;
    // collision y-axis
    bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
        two.Position.y + two.Size.y >= one.Position.y;
    // collision only if on both axes
    return collisionX && collisionY;
}

//colision del pacman con las cubos(paredes, ladrillos)
//bool CheckCollision(PacmanObject &one, GameObject &two){

//}