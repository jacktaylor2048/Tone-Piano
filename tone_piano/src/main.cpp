#include <conio.h>
#include <iostream>
#include "note.h"

const int CONSOLE_WIDTH = 64;
const int CONSOLE_HEIGHT = 16;
const unsigned char DEFAULT_NOTELENGTH = 150;

// Clear console
void clear()
{

}

// Draw to console
void draw(bool& redraw, bool& playmode, char& octave, char& notelength)
{
	if (redraw)
	{
		std::cout << "\n\n                   Tone Piano 1.0 by Jack Taylor\n\n\n";
		if (!playmode)
		{
			std::cout << "        1 - 7: Set Octave             8: Random Note\n\n";
			std::cout << "        -: Note length - 5            +: Note length + 5\n\n";
			std::cout << "        Octave: " << static_cast<int>(octave) << "                     Note Length: " << static_cast<int>(notelength) << "ms\n\n";
			std::cout << "             SPACE: Toggle play mode (Currently OFF)\n\n";
		}
		else
		{
			std::cout << "               Octave cannot be set while playing.\n\n";
			std::cout << "        -: Note length - 5            +: Note length + 5\n\n";
			std::cout << "        Octave: " << static_cast<int>(octave) << "                     Note Length: " << static_cast<int>(notelength) << "ms\n\n";
			std::cout << "             SPACE: Toggle play mode (Currently ON)\n\n";
		}
		std::cout << "                       ESC: Exit program";
		redraw = false;
	}
}

// Main function
int main()
{
	bool redraw = true;
	bool playmode = false;
	char key = 0;
	char octave = BASE_OCTAVE;
	unsigned char notelength = DEFAULT_NOTELENGTH;
	srand(time_t(NULL));
	// Initialise console window
	SetConsoleTitle("Tone Piano");
	SMALL_RECT window = {0, 0, CONSOLE_WIDTH - 1, CONSOLE_HEIGHT - 1};
	COORD buffer = {CONSOLE_WIDTH, CONSOLE_HEIGHT};
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &window);
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), buffer);
	return 0;
}
