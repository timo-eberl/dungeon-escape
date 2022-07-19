#include <string>
#include <ncurses.h>
#include "dungeon.hpp"

void init(Dungeon &dungeon);

char waitForInput();

bool update(char input, Dungeon &dungeon);

void draw(Dungeon &dungeon);

void shutdown();

int main(int argc, char *argv[])
{
    Dungeon dungeon;

    init(dungeon);

    bool won = false;
    while (!won)
    {
        char input = waitForInput();
        won = update(input, dungeon);
        draw(dungeon);
    }

    shutdown();
    return 0;
}

void init(Dungeon &dungeon)
{
    // init ncurses: character-at-a-time input without echoing
    initscr(); cbreak(); noecho();

    draw(dungeon);
}

char waitForInput()
{
    return (char)toupper(getch());
}

bool update(char input, Dungeon &dungeon)
{
    bool won = false;

    switch (input)
    {
    case 'W':
        won = dungeon.moveUp();
        break;
    case 'A':
        won = dungeon.moveLeft();
        break;
    case 'S':
        won = dungeon.moveDown();
        break;
    case 'D':
        won = dungeon.moveRight();
        break;
    }

    return won;
}

// prints a tutorial text and the dungeon
void draw(Dungeon &dungeon)
{
    clear();

    std::string out;
    out += "You are trapped in a maze, find the exit (E)!\n";
    out += "Watch out for mud (~) and fragile walls (O)!\n";
    out += "Use 'w', 'a', 's' and 'd' to move.\n\n";
    out += dungeon.visibleAreaStr() + '\n';

    printw(out.c_str());
    refresh();
}

void shutdown()
{
    std::string out;
    out += "Congratulations, you have escaped the maze!\n";
    out += "Press any key to exit.\n";
    printw(out.c_str());
    refresh();
    getch();
    endwin(); // end ncurses mode
}
