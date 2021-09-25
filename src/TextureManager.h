//
// Created by basti on 20/09/2021.
//

#ifndef PLATFORMERGAME_TEXTUREMANAGER_H
#define PLATFORMERGAME_TEXTUREMANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>

namespace Biscuit {
    class TextureManager {

    public:
        ~TextureManager();

        SDL_Texture *LoadTexture(const std::string &file, SDL_Renderer *renderer, SDL_Rect *dims);

    private:
        std::unordered_map<std::string, SDL_Texture *> textures;

    };

}


#endif //PLATFORMERGAME_TEXTUREMANAGER_H
