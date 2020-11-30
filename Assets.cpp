#include "Assets.h"
/**
\brief This function controls downloading of the type

Use throw when the type wasn't downloaded
*/
void Assets::Load()
{
	if (!font.loadFromFile("calibri.ttf")) throw;
}
