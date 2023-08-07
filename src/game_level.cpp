
#include "game_level.h"

#include <fstream>
#include <sstream>
#include <iostream>


void GameLevel::Load(const char *file, unsigned int levelWidth, unsigned int levelHeight)
{
    // clear old data
    this->Bricks.clear();
    this->Coins.clear();
    this->Fruits.clear();
    // load from file
    unsigned int tileCode;
    GameLevel level;
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<unsigned int>> tileData;
    if (fstream)
    {
        while (std::getline(fstream, line)) // read each line from level file
        {
            std::istringstream sstream(line);
            std::vector<unsigned int> row;
            while (sstream >> tileCode) // read each word separated by spaces
                row.push_back(tileCode);
            tileData.push_back(row);
        }
        if (tileData.size() > 0)
            this->init(tileData, levelWidth, levelHeight);
    }
}

void GameLevel::Draw(SpriteRenderer &renderer)
{
    for (GameObject &tile : this->Bricks)
        tile.Draw(renderer);
    for (CoinObject &coin : this->Coins)
        if(!coin.Destroyed)
            coin.Draw(renderer);
    for (FruitObject &fruit : this->Fruits)
        if(!fruit.Destroyed)
            fruit.Draw(renderer);
    
}

bool GameLevel::IsCompleted()
{
    for (CoinObject &tile : this->Coins)
        if (!tile.Destroyed)
            return false;
    return true;
}

void GameLevel::init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight)
{
    // calculate dimensions
    unsigned int height = tileData.size();
    unsigned int width = tileData[0].size(); // note we can index vector at [0] since this function is only called if height > 0
    //float unit_width = levelWidth / static_cast<float>(width), unit_height = levelHeight / height;
    float unit_width = 2.0f, unit_height = 2.0f;
    //std::cout<<"unit-width: "<<unit_width<<" - unit height: "<<unit_height<<"\n";
    // initialize level tiles based on tileData		
    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {
            // check block type from level data (2D level array)
            if (tileData[y][x] == 0) // monedita
            {
                glm::vec2 pos(unit_width * x + (unit_width / 2), unit_height * y + (unit_height / 2));
                //std::cout<<"x: "<<pos.x<<" - y: "<<pos.y<<"\n";
                glm::vec3 size(unit_width / 4 , unit_height / 4, unit_height / 4);
                CoinObject obj(pos, size);
                this->Coins.push_back(obj);
            }
            if (tileData[y][x] == 1) // solid
            {
                glm::vec2 pos(unit_width * x, unit_height * y);
                //std::cout<<"x: "<<pos.x<<" - y: "<<pos.y<<"\n";
                glm::vec3 size(unit_width, unit_height, unit_height);
                GameObject obj(pos, size);
                this->Bricks.push_back(obj);
            }
            if (tileData[y][x] == 2) // fruta
            {
                glm::vec2 pos(unit_width * x, unit_height * y);
                //std::cout<<"x: "<<pos.x<<" - y: "<<pos.y<<"\n";
                FruitObject obj(pos);
                this->Fruits.push_back(obj);
            }

        }
    }
}