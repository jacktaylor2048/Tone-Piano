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
	note = (rand() % 31) - 9;
}

// Set a specific note based on key press.
void Note::set_note(char key)
{

}
