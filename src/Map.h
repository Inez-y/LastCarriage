#pragma once

#include <SDL3/SDL.h>
#include <string>
#include <vector>

// Items
struct SpawnPoint {
    float x;
    float y;
};

struct ItemSpawn {
    float x;
    float y;
    std::string type;
};


class Map {
public:
    Map();

    bool load(const char* path);
    void render(SDL_Renderer* renderer, SDL_Texture* tilesetTexture, const SDL_FRect& camera);

    const std::vector<ItemSpawn>& getItemSpawns() const;
    const std::vector<SpawnPoint>& getEnemySpawnPoints() const;
    const std::vector<SDL_FRect>& getColliders() const;

    SpawnPoint getPlayerSpawn() const;
    bool hasPlayerSpawn() const;

    int getWidth() const;
    int getHeight() const;
    int getTileWidth() const;
    int getTileHeight() const;

    // For collision
    int getTileAt(int row, int col) const;
    int isWalkableTile(int row, int col) const;

    // World-position collision
    bool isWalkableAtWorld(float worldX, float worldY) const;

private:
    std::vector<std::vector<int>> tiles;
    std::vector<ItemSpawn> itemSpawns;
    std::vector<SpawnPoint> enemySpawnPoints;
    std::vector<SDL_FRect> colliders;

    SpawnPoint playerSpawn;
    bool playerSpawnSet;

    int width;
    int height;
    int tileWidth;
    int tileHeight;
    int firstGid;
};