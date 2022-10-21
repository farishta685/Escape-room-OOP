#include <iostream>
#include <string>

using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person
{
    public:
    Person();
    Person(string p_name);
    string name;
    static int my_id;
    int ID;
    int HS_count;
    string set_name(string pname);
    string get_name();
    int* scores_array;
    void set_new_score(int new_score);
    int get_highscore();
    ~Person();

    protected:

    int high_score;
};

#endif