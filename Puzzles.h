#include <iostream>
#include <string>
#include "Room.h"
#include "Person.h"

using namespace std;

#ifndef PUZZLES_H
#define PUZZLES_H

class Puzzles : public Room
{
    public:
    Puzzles();
    Puzzles(Person p_name);
    string name; // this will store the name of the room
    Person player; //When running outside of the main, create a person object as the player
    string give_question1();    //a function to print out each question and take input for the player's answer
    string give_question2();
    string give_question3();
    // to store the number of questions that the player has correctly answered
    int answered_questions;
    // returns each of the player's answers
    string getpuzzle_answer(int i);
    bool compare_pzl_answers(int pzl_answer, int player_answer);
    //compares the player's answer with the correct answer
    bool compare_pzl_answers(string pzl_answer, string player_answer);
    // runs the game as a whole
    virtual void playRoom();
    // determines the player's score and finishes their game
    virtual void end_game();
    ~Puzzles();
    private:
    //the correct answers are protected
    string answer1;
    string answer2;
    string answer3;

};

#endif