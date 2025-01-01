#ifndef GAPBUFFER_H
#define GAPBUFFER_H
#pragma once
#include <vector>
#include <string>

class GapBuffer
{
public:
    std::vector<char> buffer;
    unsigned long gap_start, gap_end;


    // Constructor: initializes the buffer with a default size
    GapBuffer(unsigned long initial_size = 1024);

    // Inserts a single character at the current gap position
    void insert(char c);

    // Inserts a string at the current gap position
    void insert_string(std::string s);

    // Moves the gap left to the specified position
    void left(unsigned long position);

    // Moves the gap right to the specified position
    void right(unsigned long position);

    // Moves the cursor to the specified position
    void moveCursor(unsigned long position);

    // Deletes the character at the specified position
    void deleteChar(unsigned long position);

    // Resizes the buffer when the gap is full
    void resize();

    // Updates the character at the given position
    void update(unsigned long position, char c);
};

#endif // GAPBUFFER_H
