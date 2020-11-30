#include "GameController.h"
/**
\brief Constructor

Parametr 1 - game model
Parametr 2 - game representation
*/
GameController::GameController(GameModel* game, GameRender* render)
{
	m_game = game;
	m_render = render;
}
/// Destructor
GameController::~GameController()
{
}
/**
\brief Main method for starting the game

Method with the main cycle, it works with messages and redraws the main window during the game
*/
void GameController::Run()
{
	sf::Event event;
	int move_counter = 0; ///< mixing counters

	while (m_render->window().isOpen())
	{
		while (m_render->window().pollEvent(event))
		{
			if (event.type == sf::Event::Closed) m_render->window().close();
			if (event.type == sf::Event::KeyPressed)
			{
				/// Press keys and moving counters
				if (event.key.code == sf::Keyboard::Escape) m_render->window().close();
				if (event.key.code == sf::Keyboard::Left) m_game->Move(Direction::Left);
				if (event.key.code == sf::Keyboard::Right) m_game->Move(Direction::Right);
				if (event.key.code == sf::Keyboard::Up) m_game->Move(Direction::Up);
				if (event.key.code == sf::Keyboard::Down) m_game->Move(Direction::Down);
				/// The new game
				if (event.key.code == sf::Keyboard::F2)
				{
					m_game->Init();
					move_counter = 100;
				}
			}
		}

		/// If the counter greater than 0, continue mixing counters(game objects)
		if (move_counter-- > 0) m_game->Move((Direction)(rand() % 4));

		/// drawing the current situation 
		m_render->Render();
	}
}
