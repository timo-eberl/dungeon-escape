#include <string>
#include "console.hpp"
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
    console::init();

    draw(dungeon);
}

char waitForInput()
{
    return toupper(console::getCharacter());
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
    console::clearScreen();

    std::string out;
    out += "You are trapped in a maze, find the exit (E)!\n";
    out += "Watch out for mud (~) and fragile walls (O)!\n";
    out += "Use 'w', 'a', 's' and 'd' to move.\n\n";
    out += dungeon.visibleAreaStr() + '\n';

    console::print(out);
}

void shutdown()
{
    std::string out;
    out += "Congratulations, you have escaped the maze!\n";
    out += "Press any key to exit.\n";

    console::print(out);
    console::getCharacter();

    console::close();
}
