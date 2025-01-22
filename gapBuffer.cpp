#include "gapBuffer.h"
using namespace std;

    GapBuffer::GapBuffer(unsigned long initial_size) 
        : buffer(initial_size, '\0'), gap_start(0), gap_end(initial_size) {}

    void GapBuffer::insert(char c) {
        if (gap_start == gap_end) resize();
        buffer[gap_start++] = c;
    }

    void GapBuffer::insert_string(string s)
    {
         if (gap_end - gap_start < s.size())
    {
        resize();
    }

        
        buffer.insert(buffer.begin() + gap_start, s.begin(), s.end());
        gap_start += s.size();
    }
    

    void GapBuffer::left(unsigned long position) // Move gap to a specific position
    {
        while (position < gap_start)
        {
            gap_start--;
            gap_end--;
            buffer[gap_end+1] = buffer[gap_start];
        }

    } 

     void GapBuffer::right(unsigned long position) // Move gap to a specific position
    {
        while (position > gap_end)
        {
            gap_start++;
            gap_end++;
            buffer[gap_end-1] = buffer[gap_start];
        }
    } 

    void GapBuffer::moveCursor(unsigned long position) 
    { 
        if (position >= buffer.size())
        {
            return;
        }

        if (position < gap_start) { 
            left(position); 
        } 
        else { 
            right(position); 
        } 
    } 

    void GapBuffer::deleteChar(unsigned long position) // Remove character near cursor
    {
        if (position >= buffer.size())
        {
            return;
        }
        //Position is before gap, 
        //so expand left, leave characters in there, we don't care what the buffer actually looks like
        if(position < gap_start)
        {
            gap_start--;
        }
        //Position is after gap
        //Expand right , leave characters in there, we don't care what the buffer actually looks like
        if(position >= gap_end)
        {
            gap_end++;
        }
    } 

    void GapBuffer::resize() // Increase buffer size and move gap
    {
        //make a new, double sized buffer
        unsigned long new_size = buffer.size() * 2;
        unsigned long prev_size = buffer.size();
        vector<char> new_buffer(new_size, '\0');
        
        //copy everything before the gap
        copy(buffer.begin(), buffer.begin() + gap_start, new_buffer.begin());

        //Copy everything after the gap
        unsigned long after_pos = prev_size - gap_end;
        copy(buffer.begin() + gap_end, buffer.end(), new_buffer.begin() + new_size - after_pos);

        // Update the end of the explanded gap
        gap_end = new_size - after_pos;

        buffer = move(new_buffer);

    }

    void GapBuffer::update(unsigned long position, char c)
    {
        if (position < gap_start || position > gap_end)
        {
            buffer[position] = c;
        }
    }     