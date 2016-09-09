#include "note.h"
// Constructor.
Note::Note()
{
	note = 0;
	frequency = 0;
}

// Play this note.
void Note::play(char& octave, unsigned char& notelength)
{

}

// Set a random note.
void Note::set_note()
{
	note = (rand() % NOTES_PER_CONFIG) - BASE_NOTE_DIFF;
}

// Set a specific note based on key press.
void Note::set_note(char key)
{
	if (key == 'z') note = -9;
	else if (key == 's') note = -8;
	else if (key == 'x') note = -7;
	else if (key == 'd') note = -6;
	else if (key == 'c') note = -5;
	else if (key == 'v') note = -4;
	else if (key == 'g') note = -3;
	else if (key == 'b') note = -2;
	else if (key == 'h') note = -1;
	else if (key == 'n') note = 0;
	else if (key == 'j') note = 1;
	else if (key == 'm') note = 2;
	else if (key == ',' || key == 'q') note = 3;
	else if (key == 'l' || key == '2') note = 4;
	else if (key == '.' || key == 'w') note = 5;
	else if (key == '3') note = 6;
	else if (key == 'e') note = 7;
	else if (key == 'r') note = 8;
	else if (key == '5') note = 9;
	else if (key == 't') note = 10;
	else if (key == '6') note = 11;
	else if (key == 'y') note = 12;
	else if (key == '7') note = 13;
	else if (key == 'u') note = 14;
	else if (key == 'i') note = 15;
	else if (key == '9') note = 16;
	else if (key == 'o') note = 17;
	else if (key == '0') note = 18;
	else if (key == 'p') note = 19;
	else if (key == '[') note = 20;
	else if (key == ']') note = 21;
}
