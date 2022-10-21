#include <iostream>
#include <string>
#include "Sherlock.h"
//#include "Room.h"

using namespace std;

Sherlock::Sherlock()
{

}

Sherlock::Sherlock(Person s_player)
{
    name = "sherlock holme's myteries";
    answered_questions =0;
    player = s_player;
}
int Sherlock::give_puzzle1()
{
    pz1_answer = 221;
    int player_answer;
    cout<<"Here is your first question.\nAt what number on Baker St do Sherlock & Watson live?"<<endl;
    cin>>player_answer;

    return player_answer;
}

string Sherlock::give_puzzle2()
{
    pz2_answer = "doctor";
    string player_answer;
    cout<<"Here is your second puzzle. Are you ready!\nWhat is Watson's profession?"<<endl;
    cin>>player_answer;

    return player_answer;
}


string Sherlock::give_puzzle3()
{
    pz3_answer = "moriarty";
    string player_answer;
    cout<<"Here is your third puzzle. are you ready!\nWho is Sherlock Holmes' arch enemy?"<<endl;
    cin>>player_answer;
    return player_answer;
}


//compare player answer with the actual answer and increament player answered_question if correctly answered
bool Sherlock::compare_pzl_answers(int pzl_answer, int player_answer)
{
    bool answer = false;
    int i = 1;
    while (player_answer != pzl_answer && i < 10)
    {
        answer = false;
        int new_answer;
        cout<<"\nThat is wrong!  When you have eliminated the impossible,\nwhatever remains, however improbable, must be the truth.\nPlease try again"<<endl;
        cin >> new_answer;
        player_answer = new_answer;
        i++;
    }
   if(i == 10){
        answer = false;
        cout << "\nYou have answered incorrectly 10 times. It is a capital mistake to theorise before one has data. You have no more chances for this question." << endl;
    }
    else if(i > 0 && i < 10){
        answer = true;
        cout << "\nThat is correct, you are on your way to becoming a great detective." << endl;
        answered_questions++;
    }
    return answer;
}

//compares string answers and returns truw or false depending on user performance
bool Sherlock::compare_pzl_answers(string pzl_answer, string player_answer)
{
    //if user cannot answer question in 10 tries they get moved on to the next question  at their last try they are given a warning
    //if answered correctly user score increments ++. and user is told their answer is correct
    bool answer = false;
    int j = 1;
    while (player_answer != pzl_answer && j < 10)
    {
        answer = false;
        string new_answer;
        cout<<"\nThat is wrong!  When you have eliminated the impossible,\nwhatever remains, however improbable, must be the truth.\nPlease try again"<<endl;
        cin >> new_answer;
        player_answer = new_answer;
        j++;
    }
    if(j == 10){
        answer = false;
        cout << "\nYou have answered incorrectly 10 times. It is a capital mistake to theorise before one has data. You have no more chances for this question." << endl;
    }
    else if(j > 0 && j < 10){
        answer = true;
        cout << "\nThat is correct, you are on your way to becoming a great detective." << endl;
        answered_questions++;
    }
    return answer;
}

string Sherlock::getpuzzle_answer(int i)
{
    //sherlock has an int answer for question 1. change to string and then in main change back to int for comparing answer with
    string answer; // = new string[50]
    if (i==1)
    {
        answer = to_string(pz1_answer);
        return answer;
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
void Sherlock::playRoom()
{
    //declare new variables to assign pzl answers and player answers;
        int player_answer1;
        string player_answer2, player_answer3, pz2_ans, pz3_ans ;
        string *pz1_ans_str = new string[50];

        cout<<"\nWelcome to "<<name<<", "<<player.get_name()<<"! I see you want to become Sherlock's new sidekick!"<<endl;
        cout<<"Prove yourself worthy by answering these questions and we shall think about it."<<endl;

        //give player the first puzzle and assign answer to compare later with the actual answer
        player_answer1 = give_puzzle1();
        *pz1_ans_str = getpuzzle_answer(1);
        int pz1_ans_int = stoi(*pz1_ans_str); //change back to int
        bool chek_answer1 = compare_pzl_answers(pz1_ans_int, player_answer1);

        //give puzzle 2 and get player answer to compare and check
        player_answer2 = give_puzzle2();
        pz2_ans =  getpuzzle_answer(2);
        bool check_answer2 = compare_pzl_answers(pz2_ans, player_answer2);

        //give puzzle 2 and get player answer and compare player answer
        player_answer3 = give_puzzle3();
        pz3_ans =  getpuzzle_answer(3);
        bool check_answer3 = compare_pzl_answers(pz3_ans, player_answer3);
}

//ends the game by giving the user a message about how they went and tells them how many problems they solved also keep a record of their score
void Sherlock::end_game()
{
    if (answered_questions ==3)
    {
        cout<< "I see you have managed to solve all three problems!" << endl;
        cout<< "You would make an excellent assistant to Mr Holmes" << endl;
        cout<< "I shall keep a record of your scores in case you decide to ever come back." << endl;
        player.set_new_score(3);
    }
    else if (answered_questions == 2)
    {
        cout << "I see you have managed to solve only 2 problems!" << endl;;
        cout << "You are not quite ready to solve crimes just yet." << endl;
        cout << "I shall keep a record of your scores in case you decide to ever come back to break them." << endl;
        player.set_new_score(2);
    }
    else if (answered_questions == 1)
    {
        cout << "So you only managed to answer 1 question!" << endl;
        cout << "Pretty suspicious if you ask me!" << endl;
        cout << "I shall keep a record of this failure. Come back to break your high score any day." << endl;
        player.set_new_score(1);
    }
    else if (answered_questions == 0)
    {
        cout << "What a shame, you didn't even answer one question!" << endl;
        cout << "You do not have what it takes to be a detective at all." << endl;
        cout << "I see no point but I shall keep this failure recorded for you!";
        player.set_new_score(0);
    }
}

Sherlock::~Sherlock()
{
}