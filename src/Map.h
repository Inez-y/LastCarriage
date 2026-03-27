#pragma once

#include <SDL3/SDL.h>
#include <string>
#include <vector>

struct SpawnPoint {
    float x;
    float y;
};

class Map {
public:
    Map();

    bool load(const char* path);
    void render(SDL_Renderer* renderer, SDL_Texture* tilesetTexture, const SDL_FRect& camera);

    const std::vector<SpawnPoint>& getItemSpawnPoints() const;
    const std::vector<SDL_FRect>& getColliders() const;

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
    std::vector<SpawnPoint> itemSpawnPoints;
    std::vector<SDL_FRect> colliders;

    int width;
    int height;
    int tileWidth;
    int tileHeight;
    int firstGid;
};