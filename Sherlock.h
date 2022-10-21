#include <iostream>
#include <string>
#include "Room.h"
#include "Person.h"

using namespace std;

#ifndef SHERLOCK_H
#define SHERLOCK_H

class Sherlock : public Room
{
    public:
    Sherlock();
    Sherlock(Person s_player);
    string name;
    Person player;
    int give_puzzle1();
    string give_puzzle2();
    string give_puzzle3();
    int answered_questions;
    bool compare_pzl_answers(int pzl_answer , int player_answer);
    bool compare_pzl_answers(string pzl_answer, string player_answer);
    string getpuzzle_answer(int i);
    virtual void playRoom();
    virtual void end_game();
    ~Sherlock();
    private:
    int pz1_answer;
    string pz2_answer;
    string pz3_answer;
};
#endif