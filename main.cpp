#include <assert.h>
#include <iostream>
#include <stdbool.h>
#include <string.h>

enum BEARING
{
    NORTH = 0,
    EAST  = 1,
    SOUTH = 2,
    WEST  = 3
};

struct Position
{
    int x;
    int y;
};

struct Robot
{
    struct Position position;
    enum BEARING    bearing;
};

struct Position get_position(struct Robot robot) { return robot.position; }

enum BEARING get_bearing(struct Robot robot) { return robot.bearing; }

void turn_right(struct Robot *robot) { robot->bearing = static_cast<enum BEARING>((robot->bearing + 1) % 4); }

void turn_left(struct Robot *robot) { robot->bearing = static_cast<enum BEARING>((robot->bearing + 3) % 4); }

void advance(struct Robot *robot)
{
    switch (robot->bearing)
    {
        case NORTH: robot->position.y++; break;
        case EAST: robot->position.x++; break;
        case SOUTH: robot->position.y--; break;
        case WEST: robot->position.x--; break;
    }
}

void execute_sequence(struct Robot *robot, char *sequence)
{
    int i = 0;
    while (sequence[i] != '\0')
    {
        switch (sequence[i])
        {
            case 'R': turn_right(robot); break;
            case 'L': turn_left(robot); break;
            case 'A': advance(robot); break;
        }
        i++;
    }
}

// Test case for get_position()
void testGetPosition()
{
    struct Robot robot;
    robot.position.x = 0;
    robot.position.y = 0;
    robot.bearing    = NORTH;

    struct Position position = get_position(robot);

    assert(position.x == 0 && position.y == 0);
    printf("Test passed: get_position()\n");
}

// Test case for get_bearing()
void testGetBearing()
{
    struct Robot robot;
    robot.position.x = 0;
    robot.position.y = 0;
    robot.bearing    = EAST;

    enum BEARING bearing = get_bearing(robot);

    assert(bearing == EAST);
    printf("Test passed: get_bearing()\n");
}

// Test case for turn_right()
void testTurnRight()
{
    struct Robot robot;
    robot.position.x = 0;
    robot.position.y = 0;
    robot.bearing    = NORTH;

    turn_right(&robot);

    assert(robot.position.x == 0 && robot.position.y == 0 && robot.bearing == EAST);
    printf("Test passed: turn_right()\n");
}

// Test case for turn_left()
void testTurnLeft()
{
    struct Robot robot;
    robot.position.x = 0;
    robot.position.y = 0;
    robot.bearing    = NORTH;

    turn_left(&robot);

    assert(robot.position.x == 0 && robot.position.y == 0 && robot.bearing == WEST);
    printf("Test passed: turn_left()\n");
}

// Test case for advance()
void testAdvance()
{
    struct Robot robot;
    robot.position.x = 0;
    robot.position.y = 0;
    robot.bearing    = NORTH;

    advance(&robot);

    assert(robot.position.x == 0 && robot.position.y == 1 && robot.bearing == NORTH);
    printf("Test passed: advance()\n");
}

// Test case for execute_sequence()
void testExecuteSequence()
{
    struct Robot robot;
    robot.position.x = 7;
    robot.position.y = 3;
    robot.bearing    = NORTH;

    char sequence[] = "RAALAL";

    execute_sequence(&robot, sequence);

    assert(robot.position.x == 9 && robot.position.y == 4 && robot.bearing == WEST);
    printf("Test passed: execute_sequence()\n");
}

int main()
{
    testGetPosition();
    testGetBearing();
    testTurnRight();
    testTurnLeft();
    testAdvance();
    testExecuteSequence();

    return 0;
}
