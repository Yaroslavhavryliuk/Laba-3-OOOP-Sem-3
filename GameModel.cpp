#include "GameModel.h"
/**
\brief Constructor

Initialize the game objects and field
*/
GameModel::GameModel()
{
	
	Init();
}
/**
 \brief Initialization of the game field

 Init the field and make the true game solution
*/
void GameModel::Init()
{
	
	for (int i = 0; i < ARRAY_SIZE - 1; i++) elements[i] = i + 1;
	
	empty_index = ARRAY_SIZE - 1;
	elements[empty_index] = 0;	
	solved = true;
}
/**
 \ brief Is the game solved

 Checks if the solution is correct
*/
bool GameModel::Check()
{
	
	for (unsigned int i = 0; i < ARRAY_SIZE; i++)
	{
		if (elements[i] > 0 && elements[i] != i + 1) return false;
	}
	return true;
}
/**
\brief Movings in the geme

Movings of the counters on the field logic
Parametr - direction of the move from the keyboard
*/
void GameModel::Move(Direction direction)
{
	
	int col = empty_index % SIZE;///< columns
	int row = empty_index / SIZE;///< rows

	
	int move_index = -1;
	if (direction == Direction::Left && col < (SIZE - 1)) move_index = empty_index + 1;///< Left
	if (direction == Direction::Right && col > 0) move_index = empty_index - 1;///< Right
	if (direction == Direction::Up && row < (SIZE - 1)) move_index = empty_index + SIZE;///< Up
	if (direction == Direction::Down && row > 0) move_index = empty_index - SIZE;///< Down

	/// Swap the moving counter and the empty counter
	if (empty_index >= 0 && move_index >= 0)
	{
		int tmp = elements[empty_index];
		elements[empty_index] = elements[move_index];
		elements[move_index] = tmp;
		empty_index = move_index;
	}
	solved = Check();///< final solution
}