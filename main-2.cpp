#include <iostream>
#include <string>
#include "Puzzles.h"

int main(void){
    Person *player1 = new Person("new_player");
    Room *room1 = new Puzzles(*player1);
    
    room1->playRoom();

    /*string *p_answer1 = new string;
    *p_answer1 = room1->give_question1();
    string pzl_ans1 = room1->getpuzzle_answer(1);
    bool response1 = room1->compare_pzl_answers(pzl_ans1, *p_answer1);

    string *p_answer2 = new string;
    *p_answer2 = room1->give_question2();
    string pzl_ans2 = room1->getpuzzle_answer(2);
    bool response2 = room1->compare_pzl_answers(pzl_ans2, *p_answer2);

    string *p_answer3 = new string;
    *p_answer3 = room1->give_question3();
    string pzl_ans3 = room1->getpuzzle_answer(3);
    bool response3 = room1->compare_pzl_answers(pzl_ans3, *p_answer3);*/
}