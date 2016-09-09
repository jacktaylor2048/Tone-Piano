#include <conio.h>
#include <iostream>
#include "note.h"

const int CONSOLE_WIDTH = 64;
const int CONSOLE_HEIGHT = 16;
const unsigned char DEFAULT_NOTELENGTH = 150;
const unsigned char MIN_NOTELENGTH = 10;
const unsigned char MAX_NOTELENGTH = 255;
const char ESCAPE_KEY = 27;

// Clear console
void clear()
{
	DWORD n;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), TEXT(' '), 1024, {0}, &n);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0});
}

// Draw to console
void draw(bool& redraw, bool& playmode, char& octave, unsigned char& notelength)
{
	if (redraw)
	{
		clear();
		std::cout << "\n\n                  Tone Piano 1.0 by Jack Taylor\n\n\n";
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
	// Main loop
	while (key != ESCAPE_KEY)
	{
		draw(redraw, playmode, octave, notelength);
		Note cur_note;
		// Playmode OFF. Notes cannot be played, but octave can be configured.
		if (!playmode)
		{
			key = _getch();
			// Octaves
			if (key == '1') octave = 1;
			else if (key == '2') octave = 2;
			else if (key == '3') octave = 3;
			else if (key == '4') octave = 4;
			else if (key == '5') octave = 5;
			else if (key == '6') octave = 6;
			else if (key == '7') octave = 7;
			// Note length configuration
			else if (key == '-' && notelength > MIN_NOTELENGTH) notelength -= 5;
			else if (key == '=' && notelength < MAX_NOTELENGTH) notelength += 5;
			// Space toggles playmode
			else if (key == ' ') playmode = true;
			redraw = true;
			// Play random note (does not require console redraw)
			if (key == '8')
			{
				cur_note.set_note();
				cur_note.play(octave, notelength);
				redraw = false;
			}
		}
		// Playmode ON. Notes can be played, but octave cannot be configured.
		else
		{
			key = _getch();
			if (key == '-' && notelength > MIN_NOTELENGTH)
			{
				notelength -= 5;
				redraw = true;
			}
			else if (key == '=' && notelength < MAX_NOTELENGTH)
			{
				notelength += 5;
				redraw = true;
			}
			else if (key == ' ')
			{
				playmode = false;
				redraw = true;
			}
			else
			{
				cur_note.set_note(key);
				cur_note.play(octave, notelength);
			}
		}
	}
	return 0;
}
