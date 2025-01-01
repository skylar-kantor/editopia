#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ncurses.h>

using namespace std;
int main()
{
    string fname;
    cin >> fname;
    vector<vector<char>> textbuf;
    ifstream infile(fname);
    string line;
    while (getline(infile, line))
    {
        istringstream iss(line);
        string working_line = iss.str();
        vector<char> proccessed_line;
        for (char c : working_line)
        {
            proccessed_line.push_back(c);
        }
        proccessed_line.push_back('\n'); //We're eating the newline, so we can add it back here
        textbuf.push_back(proccessed_line);
    }
    
    initscr();
    for (vector<char> l : textbuf)
    {
        string line = string(l.begin(), l.end());
        printw("%s", line.c_str());
        refresh();
    }
    getch();

    // deallocates memory and ends ncurses
    endwin();
    return 0;
}
