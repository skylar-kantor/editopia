#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ncurses.h>

using namespace std;
int main()
{
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    
    while(1)
    {
        char input = getch();
        printw("%c", input);
    }
    
    // deallocates memory and ends ncurses
    endwin();
    return 0;
}
