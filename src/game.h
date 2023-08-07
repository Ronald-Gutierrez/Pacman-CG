
#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "game_level.h"
#include "camera.h"

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Represents the four possible (collision) directions
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

// Recuerda que todas las configuraciones estan en base a cubos de 2.0f
const glm::vec3 PLAYER_SIZE(1.0f, 1.0f, 1.0f);
// Initial velocity of the player paddle
const float PLAYER_VELOCITY(5.0f);



// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // game state
    GameState               State;
    Camera&                 GameCamera;
    bool                    Keys[1024];
    unsigned int            Width, Height;
    std::vector<GameLevel>  Levels;
    unsigned int            Level;
    unsigned int            Lives;
    bool showAggressiveCounter = false;

    // constructor/destructor
    Game(unsigned int width, unsigned int height, Camera &camera);
    ~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
    void DoCollisions();
    // reset
    void ResetLevel();
    void ResetPlayer();
};

#endif