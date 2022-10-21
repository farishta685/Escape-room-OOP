#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

int main(void)
{
    Person *p1 = new Person("friend");
    p1->set_new_score(45);
    cout<<p1->get_name()<<endl;
    cout<<p1->get_highscore()<<endl;
}