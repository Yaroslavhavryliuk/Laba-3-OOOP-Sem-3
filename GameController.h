#pragma once
#include <SFML/Graphics.hpp>
#include "GameRender.h"
/**
\brief Controller class

This class controls the game
It has pointers on objects of game model and game representation
It has constructor, destructor and public method Run - start the game
*/
class GameController
{
	GameModel* m_game;///< game model
	GameRender* m_render;///< game representation
public:
	/// Constructor
	GameController(GameModel* game, GameRender* render);
	/// Destructor
	~GameController();
	/// Main method for starting the game
	void Run();
};
