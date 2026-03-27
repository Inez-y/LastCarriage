#include "Item.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

Item::Item()
    : texture(nullptr),
      x(0.0f),
      y(0.0f),
      type(ItemType::Coin),
      active(true) {
        dstRect = {0.0f, 0.0f, 32.0f, 32.0f};
    }

bool Item::init(SDL_Renderer *renderer, const char *texturePath, float startX, float startY, ItemType itemType) {
    texture = IMG_LoadTexture(renderer, texturePath);
    if (!texture) {
        std::cout << "Failed to load item texture: " << SDL_GetError() << std::endl;
        return false;
    }

    x = startX;
    y = startY;
    type = itemType;
    active = true;

    float texW = 0.0f;
    float texH = 0.0f;
    SDL_GetTextureSize(texture, &texW, &texH);

    dstRect.w = texW;
    dstRect.h = texH;
    dstRect.x = x;
    dstRect.y = y;

    return true;
}

void Item::render(SDL_Renderer *renderer, const SDL_FRect& camera) {
    if (!texture || !active) { return; }

    SDL_FRect screenRect = dstRect;
    screenRect.x -= camera.x;
    screenRect.y -= camera.y;

    SDL_RenderTexture(renderer, texture, nullptr, &screenRect);
}

void Item::clean() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

SDL_FRect Item::getBounds() const {
    return dstRect;
}

ItemType Item::getType() const {
    return type;
}

bool Item::isActive() const {
    return active;
}

void Item::pickUp() {
    active = false;
}

ItemType stringToItemType(const std::string& type) {
    if (type == "Coin") {
        return ItemType::Coin;
    }
    if (type == "Health") {
        return ItemType::Health;
    }
    // if (type == "Key") {
    //     return ItemType::Key;
    // }

    return ItemType::Coin;
}

const char* itemTexturePath(ItemType type) {
    switch (type) {
        case ItemType::Coin:
            return "../assets/item_coin.png";
        case ItemType::Health:
            return "../assets/item_health.png";
        // case ItemType::Key:
        //     return "assets/item_key.png";
        default:
            return "../assets/item_coin.png";
    }
}