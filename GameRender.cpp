#include "GameRender.h"
#include "Assets.h"
/**
\brief Constructor
Parameter- game object
Function Init()
*/
GameRender::GameRender(GameModel* game)
{
	m_game = game;///< game object
	/// Initialization
	Init();
}
/// Destructor
GameRender::~GameRender()
{
}
/**
\brief Create and initialize the game window

Makes the field and texts
*/
bool GameRender::Init()
{
	/// Field position
	setPosition(50.f, 50.f);
	/// Window 600 x 600, 60 updatesper second
	m_window.create(sf::VideoMode(600, 600), "15");
	m_window.setFramerateLimit(60);
	/// Instructions for the game
	m_text = sf::Text("F2 - New Game / Esc - Exit / Arrow Keys - Move Tile", Assets::Instance().font, 20);
	m_text.setFillColor(sf::Color::Cyan);///< Color
	m_text.setPosition(5.f, 5.f);
	return true;
}
/**
\brief draw and check the game situation

draw the current situation in the game
*/
void GameRender::Render()
{
	m_window.clear();
	m_window.draw(*this);
	m_window.draw(m_text);
	m_window.display();
}
/**
\brief  drawind method

*/
void GameRender::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	sf::Color color = sf::Color(200, 100, 200); ///< Color(RGB)

	/// drawing the shape of the game field
	sf::RectangleShape shape(sf::Vector2f(GameModel::FIELD_SIZE, GameModel::FIELD_SIZE));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);
	target.draw(shape, states);

	/// preparing for drawing counters
	shape.setSize(sf::Vector2f(GameModel::CELL_SIZE - 2, GameModel::CELL_SIZE - 2));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);

	
	sf::Text text("", Assets::Instance().font, 52);
	
	int* elements = m_game->Elements();
	for (unsigned int i = 0; i < GameModel::ARRAY_SIZE; i++)
	{
		shape.setOutlineColor(color);
		text.setFillColor(color);
		text.setString(std::to_string(elements[i]));
		if (m_game->IsSolved())
		{
			/// Another color for solved game
			shape.setOutlineColor(sf::Color::Cyan);
			text.setFillColor(sf::Color::Cyan);
		}
		else if (elements[i] == i + 1)
		{
			/// green color for counters on the correct places
			text.setFillColor(sf::Color::Green);
		}

		/// draw counters which are not empty
		if (elements[i] > 0)
		{
			/// counting counter position
			sf::Vector2f position(i % GameModel::SIZE * GameModel::CELL_SIZE + 10.f, i / GameModel::SIZE * GameModel::CELL_SIZE + 10.f);
			shape.setPosition(position);
			/// positions of the texts
			text.setPosition(position.x + 30.f + (elements[i] < 10 ? 15.f : 0.f), position.y + 25.f);
			target.draw(shape, states);
			target.draw(text, states);
		}
	}
}
