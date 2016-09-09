# Tone Piano
A simple program in which the user can play their keyboard like a piano.

This is actually a project I created several years ago (in fact my first C++ program); I only recently decided to publish 
the source code on GitHub after cleaning it up, adding some comments, and fixing a few bugs.

I am also aware that the _getch() function is deprecated. Without using any additional libraries, I'm not sure how to achieve 
the same effect without having to press Enter after each input.

## Key Bindings (Playmode Off)

- 1 to 7: Set Octave
- 8: Play random note (given current octave)
- -: Reduce note length by 5ms
- +: Increase note length by 5ms
- Space: Activate Playmode
- Escape: Exit program

## Key Bindings (Playmode On)

N.B. The current octave is the lowest octave available given the configuration. Because of this, Note (low) will refer to 
that note in the current octave, Note (high) will refer to the octave above, and Note (s.high) will refer to two octaves 
above the currently selected octave.

If you have used the program FamiTracker before, the keyboard layout as far as notes are concerned is almost identical.

- Z: C  (low)
- S: C# (low)
- X: D  (low)
- D: D# (low)
- C: E  (low)
- V: F  (low)
- G: F# (low)
- B: G  (low)
- H: G# (low)
- N: A  (low)
- J: A# (low)
- M: B  (low)
- Q: C  (high); Comma also works
- 2: C# (high); L also works
- W: D  (high); Full Stop also works
- 3: D# (high)
- E: E  (high)
- R: F  (high)
- 5: F# (high)
- T: G  (high)
- 6: G# (high)
- Y: A  (high)
- 7: A# (high)
- U: B  (high)
- I: C  (s.high)
- 9: C# (s.high)
- O: D  (s.high)
- 0: D# (s.high)
- P: E  (s.high)
- [: F  (s.high)
- ]: F# (s.high)
- Space: Deactivate Playmode

Changing note length and exiting program are the same as when Playmode is off. You will not be able to switch octaves 
while it is on.
