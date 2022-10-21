//main file for checking the room class functions working properly
#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

int main(void)
{
    Room *alice = new Room("alice's adventures", "alice and the wonderland");
    cout<<alice->get_name()<<"\n"<<alice->get_theme()<<endl;
}