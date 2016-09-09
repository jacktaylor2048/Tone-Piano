#ifndef NOTE_H
#define NOTE_H

#include <math.h>
#include <windows.h>

// Frequency of note A4.
const double BASE_FREQUENCY = 440;
// Base value for which the semitone difference from the base frequency will serve as the exponent (2 ^ 1/12).
const double BASE_MULTIPLIER = 1.059463;
// The amount of notes accessible for each octave configuration
const int NOTES_PER_CONFIG = 31;
// Semitone difference between base note (A) and lowest note for a configuration (C)
const int BASE_NOTE_DIFF = 9;

/*
 * A single Note. This will be created when the user presses a key in play mode, 
 * and last until it finishes playing (handled by main).
 */
class Note
{
public:
	Note();
	void play(char& octave, unsigned char& length);
	void set_note();
	void set_note(char key);
private:
	char note;
	double frequency;
};

#endif
