//
// Created by basti on 23/09/2021.
//

#ifndef TICTACTOEGAME_OBJECTMANAGER_H
#define TICTACTOEGAME_OBJECTMANAGER_H

#include "GameObject.h"
#include <map>
#include <vector>

namespace Biscuit{
class ObjectManager {
public:
    explicit ObjectManager(SDL_Renderer *rend);

    ObjectManager() = default;

    ~ObjectManager();

    GameObject &operator[](const std::string &identifier);

    void add_object(const std::string &identifier, GameObject *object);


    std::vector<GameObject *> get_collisions(SDL_Point &point);

    std::vector<std::pair<GameObject *, SDL_Rect>> get_collisions(SDL_Rect &rect);

    void render_all();

    int render_where(bool (&func)(GameObject &));

    void update_all();

    void set_renderer(SDL_Renderer *rend);

private:
    std::map<std::string, GameObject *> objects{};
    TextureManager textureManager{};

    SDL_Renderer *renderer{};
};

}


#endif //TICTACTOEGAME_OBJECTMANAGER_H
