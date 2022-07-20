#include <string>
#include "console.hpp"
#if __unix__ || __APPLE__
#include <ncurses.h>
#elif __WIN32__ || _WIN32 || _MSC_VER || __MS_DOS__
#include <conio.h>
#endif

void console::init()
{
#if __unix__ || __APPLE__
    // init ncurses: character-at-a-time input without echoing
    initscr();
    cbreak();
    noecho();
#endif
}

void console::print(std::string str)
{
#if __unix__ || __APPLE__
    printw(str.c_str());
    refresh();
#elif __WIN32__ || _WIN32 || _MSC_VER || __MS_DOS__
    std::cout << out;
#endif
}

void console::clearScreen()
{
#if __unix__ || __APPLE__
    clear();
#elif __WIN32__ || _WIN32 || _MSC_VER || __MS_DOS__
    system("cls");
#endif
}

char console::getCharacter()
{
#if __unix__ || __APPLE__
    return getch();
#elif __WIN32__ || _WIN32 || _MSC_VER || __MS_DOS__
    return _getch();
#endif
}

void console::close()
{
#if __unix__ || __APPLE__
    endwin(); // end ncurses
#endif
}
