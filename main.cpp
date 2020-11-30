#include "Assets.h"
#include "GameModel.h"
#include "GameRender.h"
#include "GameController.h"

int main()
{
	Assets::Instance().Load(); // load resources					
	GameModel game;	// game model creating							
	GameRender render(&game);	// representation of the game				
	GameController controller(&game, &render);	// game controller
	controller.Run();	//	run the game					
	return 0;
}