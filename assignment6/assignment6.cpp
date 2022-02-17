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
            prev = current;
            add_value(new_value, current->left, prev);
            
        }

        
        else{ //node value > new_value go right
            prev = current;
            add_value(new_value, current->right, prev);
        }

    }

    Node * find_successor(Node *current){
        if(current == nullptr){
            return current;
        }

        else{//keep going until biggest value which is furthest right off first left
            while(current->right != nullptr){
                current = current->right;
            }

            return current;
        }
    }

    Node * remove_value(int find, Node *current){
        if(current == nullptr){
            cout << find << " is not in the list" << endl;
            return current; //nullptr remains nullptr
        }

        else if(current->value < find){
            current->right = remove_value(find, current->right); //right either stays same or is changed after funct call
        }

        else if(current->value > find){
            current->left = remove_value(find, current->left); //left either stays same or is changed after funct call
        }

        else{//if the current node  value is == to the value to remove
            if(current->left == nullptr){//if right child or no children
                if(current->right == nullptr){ //if no children
                    current = nullptr;
                }

                else{//if right only child move it up one level
                    Node *temp = current;
                    current = current->right;
                    delete temp; //clean up memory
                }
            
               
            }

            else if(current->right == nullptr){ //only child on the left just move it up one level
                Node *temp = current;
                current = current->left;
                delete temp; //clean up memory
            }

            //if two children find the successor
            else{
                Node *temp = find_successor(current->left);
                root->value = temp->value;
                current->left = remove_value(temp->value, current->left); //find biggest value that is smaller than the value to delete so go left once then as far right as possible.
        
            }
        }

        return current;

    }

    void traverse_tree(Node *node){
        if(node == nullptr){
            return;
        }

        traverse_tree(node->left);
        cout << node->value << endl;
        traverse_tree(node->right);

    }


};
