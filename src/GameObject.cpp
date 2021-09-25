//
// Created by basti on 20/09/2021.
//

#include <iostream>
#include "GameObject.h"


namespace Biscuit {
    GameObject::GameObject(const char *texture_file) {
        this->texture_file = texture_file;
    }

    void GameObject::update() {

    }


    void GameObject::render(SDL_Renderer *renderer, TextureManager &textureManager) {

        if (!hidden) {
            if (!texture)
                texture = textureManager.LoadTexture(texture_file, renderer, &base_dims);
            SDL_RenderCopy(renderer, texture, nullptr, &hitbox);
        }
    }

    void GameObject::set_pos(int x, int y) {
        hitbox.x = x;
        hitbox.y = y;
    }

    void GameObject::set_pos(int x, int y, int w, int h) {
        hitbox.x = x;
        hitbox.y = y;
        hitbox.w = w;
        hitbox.h = h;
    }

    const SDL_Rect &GameObject::get_hitbox() {
        return hitbox;
    }

    void GameObject::show() {
        hidden = false;

    }

    void GameObject::hide() {
        hidden = true;
    }

    std::string GameObject::get_id() {
        return identifier;
    }


    void GameObject::set_id(const std::string &id) {
        identifier = id;
    }

}
