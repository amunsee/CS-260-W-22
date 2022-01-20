/*The result of me playing with nodes and classes for a few hours no where near being a finished project*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


class Node{
    int value; //able to keep this private so long as i have a method to get the value via get_value
    Node *first = this;
    Node *last = this;
    

    public:
    Node *next;    //wanted to make this part private as well but couldnt get it to work

    Node(int new_value){ //initalizer function???
        value = new_value;
        this->next = NULL; //by default set next to NULL when a new node is created, can change value if node is not being added to end of the list.
    }

    int get_value(){
        return value;
    }

    void set_value(int input){
        this->value = input;
    }

    void set_next(Node *next_node){
        this->next = next_node;
    }

    //this add node function is for strictly adding to the back of the list not for inserting anywhere in the list (enqueueing function)
    void add_node(int value){ //this works for creating a new node just neeed to get it linked to original list. :) making progress
        Node *temp = new Node(value);
        last->next = temp;
        //need to figure out how to keep track of where i am in this list now and then how to keep track of the start and ending....
        //cout << temp->value << endl;
        this->last = temp;
    }

    void delete_node(){ //this function just deletes the first node -dequeueing function (currently no checking to see if this is last node in list yet...add later)
        this->first;
        //grab first node
        //point first* at 2nd value to make it first
        //delte first value

    }

    void insert_at(){

    }

    void delete_at(){

    }
};


/*
    void set_next(Node thing){
        this->next = &thing;
    }

    //void get_next(){
     //   cout << this->next << endl;
        //cout << this->*next << endl;
    //}

  

};
*/
//ok this is working so far!!!
  void print_list(Node *n){
        while (n != NULL){
            cout << n->get_value() << endl;
            n = n->next;
        }
    }



int main(){
    //Node h(10);
    //Node j(15);

    Node *h = new Node(10);
    Node *j = new Node(15);
    Node *k = new Node(16);


    h->set_next(j);
    j->set_next(k);
    k->set_next(NULL);

    cout << h->get_value() << endl;
    //h->value = 67; value is private so this wont work, if it was public it would
    cout << h->get_value() << endl;

    cout << h->next << endl;
    cout << j->next << endl;
    cout << k->next << endl;

    cout << j << endl;

    Node *previous = k;

    for(int i = 0; i < 5; i++){
        Node *p = new Node(i);
        previous->next = p;
        previous = p;
    }

    print_list(h);

    cout << "testing my node adding and linking" << endl << endl;
    Node *z = new Node(9);

    for(int i = 0; i < 5; i++){
        z->add_node(i);
    }
    
    print_list(z);


    cout << "deleting the first value/node (9)" << endl;
    z->delete_node();

    print_list(z);
    
   /* cout << h.get_value() << endl;
    h.set_next(j);
    //cout << h.get_next() << endl;
    //h.get_next();
    cout << &j << endl;
    cout << j.get_value() << endl;
    j.set_next(NULL);
*/
    return 0;
}
