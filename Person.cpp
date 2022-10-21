#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

int Person::my_id = 1000;

Person::Person()
{
    name = "";
    ID = my_id++;
    high_score  = 0;
    HS_count = 0;
    
}

Person::Person(string p_name)
{
    name = p_name;
    ID = my_id++;
    HS_count = 0;
    scores_array = new int[1000];
}


/*void Person::Person(string pname)
{
    name = pname;
}*/

string Person::get_name()
{
    return name;
}

void Person::set_new_score( int new_score)
{
    //using the high score count index add each new score to the array and upsate high score if needed 
    if (HS_count >1000)
    {
         scores_array[HS_count] = new_score;
    }
   
    if (new_score >= high_score)
    {
        high_score = new_score;
    }
    HS_count++;
}

int Person::get_highscore()
{
    //int current_high_score = high_score[HS_count--];
    return high_score;
}

Person::~Person()
{
}