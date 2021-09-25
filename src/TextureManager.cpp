//
// Created by basti on 20/09/2021.
//

#include <string>
#include "TextureManager.h"

namespace Biscuit {
    SDL_Texture *TextureManager::LoadTexture(const std::string &file, SDL_Renderer *renderer, SDL_Rect *dims) {
        if (textures.find(file) == textures.end()) {
            SDL_Surface *tmp = IMG_Load(file.c_str());
            textures.emplace(std::make_pair(file, SDL_CreateTextureFromSurface(renderer, tmp)));
            SDL_FreeSurface(tmp);
        }

        if (dims) {
            SDL_QueryTexture(textures[file], nullptr, nullptr, &dims->w, &dims->h);
        }

        return textures[file];
    }

    TextureManager::~TextureManager() {
        for (const auto &pair: textures) {
            SDL_DestroyTexture(pair.second);
        }
    }

}
