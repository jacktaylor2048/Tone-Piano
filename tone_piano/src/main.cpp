#include <conio.h>
#include "note.h"

const int CONSOLE_WIDTH = 64;
const int CONSOLE_HEIGHT = 16;
const unsigned char DEFAULT_NOTELENGTH = 150;

// Clear console
void clear()
{

}

// Draw to console
void draw(bool& redraw)
{

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
