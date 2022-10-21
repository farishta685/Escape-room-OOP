#include <iostream>
#include <string>
#include "Alice.h"

using namespace std;

Alice::Alice()
{
    name = "Alice in Wonderland";
    pz1_answer = "mad";
    pz2_answer = "drink me potion";
    pz3_answer = "a white rabbit";
    answered_questions = 0;
}

Alice::Alice(Person p_name)
{
    player = p_name;
    name = "Alice in Wonderland";
    answered_questions = 0;
}


// the next three functions give the player the puzzles. puzzles with more than one one answers use getlin() command
string Alice::give_puzzle1()
{
    pz1_answer = "mad";
    string player_answer;
    cout << "Here is your first puzzle. Are you ready!\nWhy is the madhatter called the madhatter? Because he is ---." << endl;
    getline(cin, player_answer);//cin >> player_answer;
    return player_answer;
}


string Alice::give_puzzle2()
{
    pz2_answer = "drink me potion";
    string player_answer;
    cout << "I see the madhatter's madness is rubbing off on you. Here is your second puzzle.\nAlice shrinks by drinking a ----- -- ------." << endl;
    getline(cin, player_answer);
    return player_answer;
}

string Alice::give_puzzle3()
{
    pz3_answer = "a white rabbit";
    string player_answer;
    cout << "I wasn't expecting you to make it so far! Here is your last problem \nWhat animal does Alice follow into Wonderland?" << endl;
    cout << "Remember to think hard and be specific!" << endl;
    getline(cin, player_answer);

    return player_answer;
}

//compares string answers and returns truw or false depending on user performance
bool Alice::compare_pzl_answers(string pzl_answer, string player_answer)
{
    //if user cannot answer question in 10 tries they get moved on to the next question  at their last try they are given a warning
    //if answered correctly user score increments ++. and user is told their answer is correct
    string new_answer;
    bool answer = false;
    int i = 1;
    while (player_answer != pzl_answer && i < 10)
    {
        if (i==9)
        {
            answer = false;
            cout << "this is your final try to answer this question!\n please enter you answer:" << endl;
            getline(cin, new_answer);
            player_answer = new_answer;
            i++;
        }
        answer = false;
        cout << "That is wrong!  Perhaps you could use a bit more imagination!" << endl;
        getline(cin, new_answer);

        player_answer = new_answer;
        i++;
    }
   if(i == 10){
        answer = false;
        cout << "You have answered incorrectly 10 times. You cannot continue this question, or else you will be late for a very important date!" << endl;
    }
    else if(i > 0 && i < 10){
        answer = true;
        cout << "That is correct, looks like you are mad enough to make it out of this place!" << endl;
        answered_questions++;
    }

    return answer;
}

//compares string answers and returns truw or false depending on user performance
bool Alice::compare_pzl_answers(int pzl_answer, int player_answer)
{
    //if user cannot answer question in 10 tries they get moved on to the next question  at their last try they are given a warning
    //if answered correctly user score increments ++. and user is told their answer is correct
    bool answer = false;
    int new_answer;
    int j = 1;
    while (player_answer != pzl_answer && j < 10)
    {
        if (j==9)
        {
            answer = false;
            cout << "this is your final try to answer this question!\n please enter you answer:" << endl;
            cin >> new_answer;
            player_answer = new_answer;
            j++;
        }
        answer = false;
        cout << "That is wrong! Maybe you need a little more madness." << endl;
        cin >> new_answer;
        player_answer = new_answer;
        j++;
    }
    if(j == 10){
        answer = false;
        cout << "You have answered incorrectly 10 times. You cannot continue this question, or else you will be late to a very important date!" << endl;
    }
    else if(j > 0 && j < 10){
        answer = true;
        cout << "That is correct, you are indeed a good fit in Wonderland." << endl;
        answered_questions++;
    }
    return answer;
}

//returns puzzles answers depending on which puzzle the user is at
string Alice::getpuzzle_answer(int i)
{
    if (i==1)
    {
        //answer = to_string(pz1_answer);
        return pz1_answer;
    }

    else if (i==2)
    {
        return pz2_answer;
    }

    else if (i==3)
    {
        return pz3_answer;
    }
}

//depending on which rom user wants to enter the play room function is called and user gets to enter the room and puzzles and given
 void Alice::playRoom()
{
    string player_answer1, player_answer2, player_answer3, pz1_ans, pz2_ans, pz3_ans;
    cout << "Welcome to "<<name<<", "<<player.get_name()<<"! We need you to solve some problems ASAP and clarify some things before we let you go.\n"<<endl;
    player_answer1 =give_puzzle1();
    pz1_ans = getpuzzle_answer(1);
    bool check_answer1 = compare_pzl_answers(pz1_ans, player_answer1);

    player_answer2 = give_puzzle2();
    ////getline(cin, player_answer2);
    pz2_ans = getpuzzle_answer(2);
   // cout<<player_answer2<<"  "<<pz2_ans<<endl;
    bool check_answer2 = compare_pzl_answers(pz2_ans, player_answer2);

    player_answer3 = give_puzzle3();
    //getline(cin, player_answer3);
    pz3_ans = getpuzzle_answer(3);
    bool check_answer3 = compare_pzl_answers(pz3_ans, player_answer3);

}

//ends the game by giving the user a message about how they went and tells them how many problems they solved also keep a record of their score
void Alice::end_game()
{

    if (answered_questions ==3)
    {
        cout<< "I see you have managed to solve all three problems!" << endl;
        cout<< "Well I suppose you must really want to get out of Wonderland by looking at your records." << endl;
        cout<< "I shall keep a record of your scores in case you decide to ever come back." << endl;
        player.set_new_score(3);
    }
    else if (answered_questions == 2)
    {
        cout << "I see you have managed to solve only 2 problems!" << endl;;
        cout << "Well I don't suppose you had plans outside of Wonderland did you?" << endl;
        cout << "I shall keep a record of your scores in case you decide to ever come back to break them." << endl;
        player.set_new_score(2);
    }
    else if (answered_questions == 1)
    {
        cout << "So you only managed to answer 1 question!" << endl;
        cout << "Pretty suspicouse if you ask me!" << endl;
        cout << "I shall keep a record of this failure. Come back to break your high score any day." << endl;
        player.set_new_score(1);
    }
    else if (answered_questions == 0)
    {
        cout << "What a shame, you didn't even answer one question!" << endl;
        cout << "You shall come back no sooner than an eternity to answer such simple questions again!" << endl;
        cout << "I see no point but I shall keep this failure recorded for you!";
        player.set_new_score(0);
    }
}

Alice::~Alice()
{
}
