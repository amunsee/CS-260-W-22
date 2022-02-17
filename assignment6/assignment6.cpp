#include <iostream>
#include "tree_node.h"

using std::cin;
using std::cout;
using std::endl;


class tree{
    public:
    Node *root;


    //public:

    tree(){
        root = nullptr;
    }

    void add_value(int new_value, Node *current, Node *prev){ //rules of tree <= go left, > go right
        if(root == nullptr){        //if tree is empty start by changing root value
            root = new Node{new_value, nullptr, nullptr};
            return;
        }

        else if(current == nullptr){
            if(prev->value >= new_value){
                current = new Node{new_value, nullptr, nullptr};
                prev->left = current;
            }
            
            else{
                current = new Node{new_value, nullptr, nullptr};
                prev->right = current;
            }
            return;
        }

        else if(current->value >= new_value){ //go left
                    
            add_value(new_value, current->left, prev);
            
        }

        
        else{ //node value > new_value go right
            add_value(new_value, current->right, prev);
        }

    }


    void remove_value(){
        return;
    }

    void traverse_tree(Node *node){
        return;
    }


};
