#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ncurses.h>
#include "gapBuffer.h"

#define CTRL(c) ((c) & 0x1f)

using namespace std;
int main()
{
    GapBuffer editor;    
    initscr();
    cbreak();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    while (1)
    {
        clear();
        //draw everything
        for (size_t i = 0; i < editor.buffer.size(); ++i)
        {
            // Only print characters that are before or after the gap
            if (i < editor.gap_start || i >= editor.gap_end)
            {
                printw("%c", editor.buffer[i]);
            }
        }
        char press = getch();
        //Handle movement and such, do this next
        if (press == KEY_RIGHT)
        {
            editor.right(1);
        }
        else if (press == KEY_LEFT)
        {
            editor.left(1);
        }
        else if (press == KEY_BACKSPACE || press == 7)
        {
            editor.deleteChar(editor.gap_start - 1);
        }
        else if (press == CTRL('X'))
        {
            break;
        }
        else if (press == CTRL('S'))
        {
            ofstream outfile("output.txt"); 
            for (size_t i = 0; i < editor.buffer.size(); ++i)
        {
            // Only print characters that are before or after the gap
            if (i < editor.gap_start || i >= editor.gap_end)
            {
                outfile << editor.buffer[i];
            }
        }
            outfile.close();
        }
        //Else, insert to the temp buffer
        else 
        {
        editor.insert(press);
        }
       
        refresh();
    }
    // deallocates memory and ends ncurses
    endwin();
    return 0;
}