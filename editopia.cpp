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
    noecho();
    keypad(stdscr, TRUE);




    while (1)
    {
        clear();
        //draw everything
        for (size_t i = 0; i < editor.gap_start; ++i) 
        {
        printw("%c", editor.buffer[i]);
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
        //Else, insert to the temp buffer
        else 
        {
        editor.insert(press);
        }
        //draw everything after the cursor
        for (size_t i = editor.gap_end; i < editor.buffer.size(); ++i) 
        {
        printw("%c", editor.buffer[i]);
        }
        refresh();
    }
    // deallocates memory and ends ncurses
    endwin();
    cout.flush();
    for (char c : editor.buffer)
    {
        cout << c;
    }
    cout << '\n';
    cout.flush(); 
    return 0;
}
