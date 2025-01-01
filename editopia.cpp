#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ncurses.h>
#include "gapBuffer.h"

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
        if (int(press) == 5)
        {
            editor.right(1);
        }
        else if (int(press) == 4)
        {
            editor.left(1);
        }
        else if (int(press) == 7)
        {
            editor.deleteChar(editor.gap_start - 1);
        }
        else if (int(press) == 24)
        {
            break;
        }
        else if (int(press) == 19)
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
