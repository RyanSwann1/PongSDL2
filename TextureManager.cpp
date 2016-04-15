#include "TextureManager.h"
#include "Game.h"
#include <assert.h>
#include <iostream>

//Static variable shared across all instances of TextureManager#
// Javawag: and with those, you write e.g. static Game *m_instance;
// Javawag: and then you have to put it in the cpp too i.e.Game *Game::m_instance;
//Javawag: and the = nullptr is just setting a default value, if you didnt do that it would be a random number (i.e. invalid pointer)
TextureManager * TextureManager::m_instance = nullptr;


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}
//
//TextureManager * TextureManager::instance()
//{
//	if (m_pInstance == nullptr) {
//		m_pInstance = new TextureManager();
//	}
//
//	return m_pInstance;
//}

TextureManager * TextureManager::instance()
{
	if (m_instance == nullptr) {
		m_instance = new TextureManager();
	}
	return m_instance;
}

void TextureManager::load(std::string ID, std::string path)
{
	//Load surface
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	assert(surface != nullptr);
	//Optimize said surface
	SDL_Surface* optimizedSurface = SDL_ConvertSurface(surface, Game::instance()->getWindowSurface()->format, 0);
	assert(optimizedSurface != nullptr);
	//Convert surface into texture
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), optimizedSurface);
	//Free the surface
	SDL_FreeSurface(surface);

	if (texture != nullptr) {
		m_textures[ID] = texture;
		return;
	}

}

void TextureManager::draw(int x, int y, int width, int height, SDL_Renderer * renderer, std::string ID)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	
	SDL_RenderCopy(Game::instance()->getRenderer(), m_textures[ID], &srcRect, &destRect);
}
