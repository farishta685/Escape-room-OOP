#include <iostream>
#include <string>
#include "Room.h"
#include "Person.h"

using namespace std;

#ifndef ALICE_H
#define ALICE_H

class Alice : public Room
{
    public:
    Alice();
    Alice(Person p_name);
    string name;
    Person player;
    //void kill_game();
    string give_puzzle1();
    string give_puzzle2();
    string give_puzzle3();
    int answered_questions;
    virtual bool compare_pzl_answers(int pzl_answer , int player_answer);
    virtual bool compare_pzl_answers(string pzl_answer, string player_answer);
    string getpuzzle_answer(int i);
    virtual void playRoom();
    virtual void end_game();
    ~Alice();

    private:
    string pz1_answer;
    string pz2_answer;
    string pz3_answer;



};
#endif