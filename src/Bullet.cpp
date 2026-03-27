#include "Bullet.h"

Bullet::Bullet()
    : speed(500.0f),
      direction(1),
      active(false) {
      rect = {0.0f, 0.0f, 16.0f, 6.0f};
    }

void Bullet::init(float startX, float startY, int dir) {
    rect.x = startX;
    rect.y = startY;
    rect.w = 16.0f;
    rect.h = 6.0f;

    direction = dir;
    active = true;
}

void Bullet::update(float deltaTime) {
    if (!active) {
        return;
    }

    rect.x += direction * speed * deltaTime;
}

void Bullet::render(SDL_Renderer* renderer, const SDL_FRect& camera) {
    if (!active) {
        return;
    }

    SDL_FRect screenRect= rect;
    screenRect.x -= camera.x;
    screenRect.y -= camera.y;

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &screenRect);
}

bool Bullet::isActive() const {
    return active;
}

void Bullet::deactivate() {
    active = false;
}

SDL_FRect Bullet::getBounds() const {
    return rect;
}