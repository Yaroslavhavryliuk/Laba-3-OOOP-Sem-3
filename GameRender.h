#pragma once
#include <SFML/Graphics.hpp>
#include "GameModel.h"
/**
\brief Class for the visualization

This class draws the window of the game 15
It has fields of GameModel, Game window and text
It has constructor, destructor, public methods: window- create the window, Init- initialize the game, Render- draw the game steps
Virtual method draw- draws the game field and counters
*/
class GameRender : public sf::Drawable, public sf::Transformable
{
	GameModel* m_game; ///< game object
	sf::RenderWindow m_window;///< game window
	sf::Text m_text;///< text
public:
	/// Constructor
	GameRender(GameModel* game);
	/// Destructor
	~GameRender();
	/// Create  window
	sf::RenderWindow& window() { return m_window; };
	/// Create and initialize the game window
	bool Init();
	/// draw and check the game situation
	void Render();
public:
	/// drawind method
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

