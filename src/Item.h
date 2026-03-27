#ifndef LASTCARRIAGE_ITEM_H
#define LASTCARRIAGE_ITEM_H
#pragma once

#include <string>
#include <SDL3/SDL.h>

enum class ItemType {
    Coin,
    Health,
};

ItemType stringToItemType(const std::string& type);
const char* itemTexturePath(ItemType type);

class Item {
public:
    Item();

    bool init(SDL_Renderer* renderer, const char* texturePath, float x, float y, ItemType type);
    void render(SDL_Renderer* renderer, const SDL_FRect& camera);
    void clean();

    SDL_FRect getBounds() const;
    ItemType getType() const;
    bool isActive() const;
    void pickUp();

private:
    SDL_Texture* texture;
    SDL_FRect dstRect;

    float x, y;

    ItemType type;
    bool active;
};
#endif //LASTCARRIAGE_ITEM_H