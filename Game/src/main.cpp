#include <SDL.h>
#include "Application.h"
#include "map/MapConstants.h"

int main(int argc, char** argv)
{
	Application app(WindowDimensions::Width, WindowDimensions::Height, WindowDimensions::Title);
	app.Run();

	return 0;
}