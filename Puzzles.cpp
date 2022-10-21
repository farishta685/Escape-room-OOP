#include <iostream>
#include <string>
#include "Puzzles.h"

using namespace std;

Puzzles::Puzzles()
{
}

Puzzles::Puzzles(Person p_name)
{
    player = p_name; //This will store the name of the player
    name = "Classic Puzzles"; //This is the name of the room
    answered_questions = 0; // initialises the variable used to store the player's score
}
// each of the give_question function output the questions, then take in and store the player's answers
string Puzzles::give_question1()
{
    answer1 = "piano"; // defines the correct answer as it is protected in the header file
    string player_answer1;//intialises the variable for storing the player answer
    cout << "Your first puzzle is: What has many keys but cannot open a single door? -----" << endl;
    getline(cin, player_answer1);
    return player_answer1;
}

string Puzzles::give_question2()
{
    answer2 = "towel";
    string player_answer2;
    cout << "Your second puzzle is: What gets wetter as it dries? -----" <<  endl;
    getline(cin, player_answer2);
    return player_answer2;
}

string Puzzles::give_question3()
{
    answer3 = "nothing";
    string player_answer3;
    cout <<  "Your third and final puzzle is: The poor have it, the rich need it and if you eat it you die. -------"<< endl;
    getline(cin, player_answer3);
    return player_answer3;
}
//getpuzzle_answer returns each of the above answer so that they can be used in later functions
string Puzzles::getpuzzle_answer(int i)
{
    if (i==1)
    {
        return answer1;
    }

    else if (i==2)
    {
        return answer2;
    }

    else if (i==3)
    {
        return answer3;
    }
}
// this function compares the player answer with the correct answer
bool Puzzles::compare_pzl_answers(string pzl_answer, string player_answer)
{
    bool result = false;
    int i = 1;
    string new_answer;
    while (pzl_answer != player_answer && i < 10){ //if the player answers incorrectly, the question is given again
        bool result = false;
        if (i==9)
        {
            result = false;
            cout << "this is your final try to answer this question!\n please enter you answer:" << endl;
            getline(cin, new_answer);
            player_answer = new_answer;
            i++;
        }
        cout << "Your answer is not correct! Please try again." << endl;
        getline(cin, new_answer);
        player_answer = new_answer;
        i++;

    }
    if(i == 10) //once the user has had 10 guesses, they have no more chances and must move onto the next question
    {
        result = false;
        cout << "You have answered incorrectly 10 times. You have no more chances for this question." << endl;
    }

    else if(i > 0 && i < 10) // in this case, the user has answered the question correctly
    {
        result = true;
        cout << "Your answer is correct! Congratulations!" << endl;
        answered_questions++; // this records the number of correct answers. Only increases if the player succeeds in answering the question
    }

    return result;
}


//depending on which rom user wants to enter the play room function is called and user gets to enter the room and puzzles and given
void Puzzles::playRoom()
{

    //playRoom runs all three question consecutively
    cout << "Welcome to "<<name<<", "<<player.get_name()<<"! you will need to solve 3 puzzles to be able to escape this room.\n"<<endl;
    string *p_answer1 = new string; // initialises a place to store the player's answer
    *p_answer1 = give_question1(); // runs the give_question function and receives the answer
    string pzl_ans1 = getpuzzle_answer(1); // returns the player's answer
    bool response1 = compare_pzl_answers(pzl_ans1, *p_answer1); // determines whether the player's answer is correct, continues running if it is not

    string *p_answer2 = new string;
    *p_answer2 = give_question2();
    string pzl_ans2 = getpuzzle_answer(2);
    bool response2 = compare_pzl_answers(pzl_ans2, *p_answer2);

    string *p_answer3 = new string;
    *p_answer3 = give_question3();
    string pzl_ans3 = getpuzzle_answer(3);
    bool response3 = compare_pzl_answers(pzl_ans3, *p_answer3);
}

//end_game calculates how many correct answers have been given, then stores the score and presents the results to the user
void Puzzles::end_game()
{

    if (answered_questions ==3)
    {
        cout<< "I see you have managed to solve all three problems!" << endl;
        cout<< "I can see you have a very analytical mind." << endl;
        cout<< "I shall keep a record of your scores in case you decide to ever come back." << endl;
        player.set_new_score(3);
    }
    else if (answered_questions == 2)
    {
        cout << "I see you have managed to solve only 2 problems!" << endl;;
        cout << "A perfectly respectable score." << endl;
        cout << "I shall keep a record of your scores in case you decide to ever come back to break them." << endl;
        player.set_new_score(2);
    }
    else if (answered_questions == 1)
    {
        cout << "So you only managed to answer 1 question!" << endl;
        cout << "Perhaps you need some practise in thinking outside of the box." << endl;
        cout << "I shall keep a record of this failure. Come back to break your high score any day." << endl;
        player.set_new_score(1);
    }
    else if (answered_questions == 0)
    {
        cout << "What a shame, you didn't even answer one question!" << endl;
        cout << "You will require much practise before you can attempt such questions." << endl;
        cout << "I see no point but I shall keep this failure recorded for you!";
        player.set_new_score(0);
    }
}

Puzzles::~Puzzles()
{
}