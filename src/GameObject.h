//
// Created by basti on 20/09/2021.
//

#ifndef PLATFORMERGAME_GAMEOBJECT_H
#define PLATFORMERGAME_GAMEOBJECT_H


#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"


namespace Biscuit {
    class GameObject {
    public:
        explicit GameObject(const char *texture_file);

        void set_pos(int x, int y);

        void set_pos(int x, int y, int w, int h);

        void update();

        void show();

        void hide();

        const SDL_Rect &get_hitbox();

        void render(SDL_Renderer *renderer, TextureManager &textureManager);


        void set_id(const std::string &id);

        std::string get_id();

    private:
        SDL_Texture *texture{};
        SDL_Rect base_dims{};
        SDL_Rect hitbox{};
        bool hidden = false;
        std::string texture_file;

        std::string identifier;

    };

}


#endif //PLATFORMERGAME_GAMEOBJECT_H
