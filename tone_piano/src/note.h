#ifndef NOTE_H
#define NOTE_H

#include <math.h>
#include <windows.h>

/* 
 * BASE_FREQUENCY: Frequency of note A4.
 * BASE_MULTIPLIER: Base value for which the semitone difference from the base 
 * frequency will serve as the exponent (2 ^ 1/12).
 * NOTES_PER_CONFIG: The amount of notes accessible for each octave configuration
 * BASE_NOTE_DIFF: Semitone difference between base note (A) and lowest note for 
 * a configuration (C)
 */
const double BASE_FREQUENCY = 440;
const double BASE_MULTIPLIER = 1.059463;
const int NOTES_PER_CONFIG = 31;
const int BASE_NOTE_DIFF = 9;
const int BASE_OCTAVE = 4;
const int NOTES_PER_OCTAVE = 12;

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
