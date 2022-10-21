#include <iostream>
#include <string>
#include "Room.h"

using namespace std;


Room::Room()
{
    building_name = "";
    max_size = 0;
    name = "";
    //theme = "";
}

Room::Room(string r_name)
{
    name = r_name;
    //theme = r_theme;
}

Room::Room(int max_size, string b_name)
{
    max_size = 0;
    building_name = b_name;
}

string Room::get_name()
{
    return name;
}

/*string Room::get_theme()
{
    return theme;
}*/

bool Room::compare_pzl_answers(/*int pzl_answer, int player_answer*/)
{

}

Room::~Room()
{
}