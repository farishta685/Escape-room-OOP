#include <iostream>
#include <string>
#include "Sherlock.h"

using namespace std;

int main(void)
{
    Person *player1 = new Person("player1");
    Room *sher_room = new Sherlock(*player1);
    
    sher_room->playRoom();
    

    /*int player_answer1;
    string player_answer2, player_answer3, pz2_ans, pz3_ans ;

    //give player the first puzzle
    player_answer1 = sher_room->give_puzzle1();
    string *pz1_ans_str = new string[50];
    *pz1_ans_str = sher_room->getpuzzle_answer(1);
    int pz1_ans_int = stoi(*pz1_ans_str); //change back to int
    bool chek_answer1 = sher_room->compare_pzl_answers(pz1_ans_int, player_answer1);

    //give puzzle 2 and get puzzle 2 answer and compare player answer
    player_answer2 = sher_room->give_puzzle2();
    pz2_ans =  sher_room->getpuzzle_answer(2);
    bool check_answer2 = sher_room->compare_pzl_answers(pz2_ans, player_answer2);

    //give puzzle 2 and get puzzle 2 answer and compare player answer
    player_answer3 = sher_room->give_puzzle3();
    pz3_ans =  sher_room->getpuzzle_answer(3);
    bool check_answer3 = sher_room->compare_pzl_answers(pz3_ans, player_answer3);*/
}