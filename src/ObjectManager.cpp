//
// Created by basti on 23/09/2021.
//

#include <iostream>
#include "ObjectManager.h"

namespace Biscuit{
ObjectManager::ObjectManager(SDL_Renderer *rend) {
    renderer = rend;
}


ObjectManager::~ObjectManager() {
    for (auto &pair: objects) {
        delete pair.second;
    }
}

void ObjectManager::add_object(const std::string &identifier, GameObject *object) {
    objects.insert(std::make_pair(identifier, object));
    object->set_id(identifier);
}

GameObject &ObjectManager::operator[](const std::string &identifier) {
    try {
        return *objects.at(identifier);
    } catch (const std::out_of_range &) {
        throw (std::out_of_range("No GameObject with identifier <" + identifier + ">"));
    }
}


void ObjectManager::render_all() {
    for (auto &pair: objects) {
        pair.second->render(renderer, textureManager);
    }
}

int ObjectManager::render_where(bool (&func)(GameObject &)) {
    int count;
    for (auto &pair: objects)
        if (func(*pair.second)) {
            pair.second->render(renderer, textureManager);
            ++count;
        }
    return count;
}

void ObjectManager::update_all() {
    for (auto &pair: objects)
        pair.second->update();
}

std::vector<GameObject *> ObjectManager::get_collisions(SDL_Point &point) {
    std::vector<GameObject *> collisions{};
    for (auto &pair: objects) {
        if (SDL_PointInRect(&point, &pair.second->get_hitbox()))
            collisions.emplace_back(pair.second);
    }

    return collisions;
}

std::vector<std::pair<GameObject *, SDL_Rect>> ObjectManager::get_collisions(SDL_Rect &rect) {
    std::vector<std::pair<GameObject *, SDL_Rect>> collisions;
    for (auto &pair: objects) {
        SDL_Rect result;
        if (SDL_IntersectRect(&pair.second->get_hitbox(), &rect, &result))
            collisions.emplace_back(std::make_pair(pair.second, result));

    }
    return collisions;
}

void ObjectManager::set_renderer(SDL_Renderer *rend) {
    renderer = rend;
}

}