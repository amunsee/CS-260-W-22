#include <iostream>
//#include "tree_node.h"
#include "assignment6.cpp"

using std::cin;
using std::cout;
using std::endl;



void add_test(){
        tree *leafy = new tree;
              
        leafy->add_value(10, leafy->root, leafy->root);
        leafy->add_value(8, leafy->root, leafy->root);
        leafy->add_value(15, leafy->root, leafy->root);
        
        cout << "--done adding time to print" << endl;
     
        cout << leafy->root->value << endl; //should give 10(pass)
        cout << leafy->root->left->value << endl; //should give 8 (pass)
        cout << leafy->root->right->value << endl; //should give 15 (pass)
              
};


int main(){
    //run tests here...

    add_test();





    return 0;
}
