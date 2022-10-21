#include <iostream>
#include <string>
#include "Alice.h"
#include "Puzzles.h"
#include "Sherlock.h"

using namespace std;

int main(void)
{
    //Room *building = new Room(/*3, "60 minute escape"*/);
    cout<<"You have entered dangerous grounds!"<<endl;
    string player_name;
    cout << "State your name:" << endl;
    getline(cin, player_name);
    Person *new_player = new Person(player_name);
    cout<<"This is your ID number, "<<new_player->get_name()<<"."<<" Its useless but you can keep it safe if you want!"<<endl;
    cout<<new_player->ID<<endl;

    cout<<"Hi "<<new_player->name<< "! Welcome. Here is a brief explanation of this escape room." << endl;
    cout<< "You can choose a room from 3 options of different themes." << endl;
    cout<<"1. Sherlock Holmes"<<endl;
    cout<<"2. Classic puzzles"<<endl;
    cout<<"3. Alice in Wonderland" << endl;
    cout<<"Each room will have a total of 3 problems you will have to answer. you will have 10 tries to answer each problem!"<<endl;
    cout<<"If you dont manage to answer the problem after 10 tries, you will be given the next question"<<endl;
    cout<<"remember you cannot exit the room until you run out of tries or manage to solve every problem!"<<endl;

    string room1;
    cout<<"Please enter 1, 2 or 3 for your room of choice:" << endl;
    cin >> room1;

    while(room1 != "1" && room1 != "2" && room1 != "3")
    {
        string new_response;
        cout << "That is not a valid entry. Here is the list of rooms again:"<<endl;
        cout<<"1. Sherlock Holmes"<<endl;
        cout<<"2. Classic puzzles"<<endl;
        cout<<"3. Alice in Wonderland" << endl;


        cout<<"Please choose 1, 2 or 3 for your room of choice:";
        cin >> new_response;
        room1 = new_response;
    }

    Room *room = nullptr; // polymorphism because it can call any of the child classes

    if (room1 == "1") {
        room = new Sherlock(*new_player);
    } else if (room1 == "2") {
        room = new Puzzles(*new_player);
    } else if (room1 == "3") {
        room = new Alice(*new_player);
    }


    room->playRoom(); // pure virtual function, causes the child class to run the puzzles
    // this funtion plays the game depending on which room the user wants to enter this function can call any of the room
    room->end_game();

    return 0;
}