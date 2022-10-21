#include <iostream>
#include <string>

using namespace std;

#ifndef ROOM_H
#define ROOM_H

class Room
{
    public:
    Room();
    Room(int max_size, string b_name);
    Room(string r_name);
    string name;
    string building_name;
    int max_size;
    string get_name();
    //string get_theme();
    virtual bool compare_pzl_answers();
    virtual void playRoom() = 0;
    virtual void end_game() = 0;

    virtual ~Room();

};

#endif

