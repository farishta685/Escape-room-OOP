#include <iostream>
#include <string>
#include "Alice.h"

using namespace std;

int main()
{
    Person *new_player = new Person("Raechel");
    Room *room = nullptr;
    room = new Alice(*new_player); //nullptr// polymorphism because it can call any of the child classes
    room->playRoom();
    room->end_game();


}




// node * right_ro(node * parent)
// {
//      //          z
//     //        /   \
//     //       y     T3
//     //      / \
//     //     x   T2 
//     //    / \
//     //   T0  T1
//     // 
//     // for right rotation do the following:
//     // 1. create temporary nodes to hold y and another to hold y's subtree
//     // 2. check first if y has a right subtree then if yes assign this to root->right
//     // 3. swap the z->left with T2 or y->right
//     // 4. swap y->right with z
//     node * tempY = parent->left;
//     node * tempYr = tempY->right;
//     if(tempY->right != NULL)
//     {
//         parent->left = tempYr;
//         tempY->right = parent;
//         // return tempY;
//     }
//     else if (tempY->right == NULL)
//     {
//         tempY->right = parent;
//         parent->left = NULL;
//     }
//     // std::cout<<"single right OG: "<<parent->data<<"  ";
//     // std::cout<<"new P Pr: "<<tempY->data<<" "<<tempY->right->data<<" \n";
//     return tempY;

// }


// node * left_ro(node * parent)
// {
//     //         x
//     //        /  \
//     //       T1    y
//     //            / \
//     //          T2   z
//     //               / \
//     //              T3  T4
//     // 
//     // for right rotation do the following:
//     // 1. create temporary nodes to hold y and another to hold y's left
//     // 2. check first if y has a left subtree then if yes assign this to root->right
//     // 3. swap the x->right with T2 or y->left
//     // 4. swap y->left with x

//     node * tempy = parent->right; 
//     if (tempy->left != NULL)
//     {
//         parent->right = tempy->left;
//         tempy->left = parent;
//         // return tempy;
//     }
//     else if(tempy->left == NULL)
//     {
//         tempy->left = parent;
//         parent->right = NULL;
//     }
//     // std::cout<<"single left OG: "<<parent->data<<" ";
//     // std::cout<<"\n new P Pl: "<<tempy->data<<" "<<tempy->left->data<<" \n";
//     return tempy;

// }

// node * left_right_ro(node * parent)
// {
//     parent->left = left_ro(parent->left);
//     return right_ro(parent);
// }

// node * right_left_ro(node * parent)
// {
//     parent->right = right_ro(parent->right);
//     return left_ro(parent);
// }
