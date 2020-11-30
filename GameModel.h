#pragma once
/// Directions of the moving on the field
enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

/**
\brief The logic of the game

This class contains the main logic fields and functions
Public constants are for the sizes of game field and for counters(game objects)
The class has protected fields: the array of counters, emty counter and logical variable for finishing the game
Public methods: Init- fill the game field, Check- checks is the game solved, Move- movings in the game, two setters
*/
class GameModel
{
public:
	static const int SIZE = 4;					
	static const int ARRAY_SIZE = SIZE * SIZE;///< Size of field in counters		
	static const int FIELD_SIZE = 500;///< Size of field in pixels				
	static const int CELL_SIZE = 120;///< Size of counter in pixels				
protected:
	int elements[ARRAY_SIZE];///< Array of counters
	int empty_index;///< Empty counter
	bool solved;///< If the end ofthe game
public:
	/// Constructor
	GameModel();
	/// Initialization of the game field
	void Init();
	/// Is the game solved
	bool Check();
	/// Movings in the geme
	void Move(Direction direction);
	/// Setter for bool solved
	bool IsSolved() { return solved; }
	/// setter for counters
	int* Elements() { return elements; }
};

