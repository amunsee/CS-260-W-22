#include <iostream>
#include "assignment6.cpp"

using std::cin;
using std::cout;
using std::endl;



void add_test(){
        tree *leafy = new tree;
              
    leafy->add_value(10, leafy->root, leafy->root);
    leafy->add_value(8, leafy->root, leafy->root);
    leafy->add_value(15, leafy->root, leafy->root);
    leafy->add_value(9, leafy->root, leafy->root);
        
    cout << "--done adding time to print" << endl;
     
    cout << leafy->root->value << endl; //should give 10(pass)
    cout << leafy->root->left->value << endl; //should give 8 (pass)
    cout << leafy->root->right->value << endl; //should give 15 (pass)
    cout << leafy->root->left->right->value << endl;
};

void traverse_test(){
    tree *leafy = new tree;
              
    leafy->add_value(10, leafy->root, leafy->root);
    leafy->add_value(8, leafy->root, leafy->root);
    leafy->add_value(15, leafy->root, leafy->root);
    leafy->add_value(9, leafy->root, leafy->root);
    leafy->add_value(1, leafy->root, leafy->root);
    leafy->add_value(2, leafy->root, leafy->root);
    leafy->add_value(11, leafy->root, leafy->root);
    leafy->add_value(23, leafy->root, leafy->root);



    leafy->traverse_tree(leafy->root); //should print out 8,9,10,15
    cout << endl;
    leafy->traverse_tree(leafy->root);
};

void remove_test(){
    tree *leafy = new tree;

    leafy->add_value(10, leafy->root, leafy->root);
    leafy->add_value(8, leafy->root, leafy->root);
    leafy->add_value(15, leafy->root, leafy->root);
    leafy->add_value(9, leafy->root, leafy->root);


    leafy->remove_value(55, leafy->root); //should indicate 55 not in list
    leafy->remove_value(9, leafy->root); 

    leafy->traverse_tree(leafy->root); //should print out 8 10 15
};

int main(){
    //run tests here...

    //add_test();

    //traverse_test();

    //remove_test();
     


    return 0;
}
