#include <iostream>

using std::cout;
using std::cin;
using std::endl;


class Node{
    int value; //able to keep this private so long as i have a method to get the value via get_value
    //Node *first = this;
    Node *last = this;
    

    public:
    Node *next;    //wanted to make this part private as well but couldnt get it to work
    int list_length = 0;

    Node(int new_value){ //initalizer function???
        value = new_value;
        this->next = NULL;
        list_length = 1; //by default set next to NULL when a new node is created, can change value if node is not being added to end of the list.
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

        this->list_length += 1;
    }

    void delete_node(){ //this function just deletes the first node -dequeueing function (currently no checking to see if this is last node in list yet...add later)
        //Node *temp = new Node(0);
        if(this->list_length == 0)
        {
            cout << "your list is already empty, nothing left to delete" << endl;
            return;
        }

        cout << this->value << "debugging info " << endl;
        cout << this->next << "debugging info" <<  endl;
        Node *temp = this; //this delete is successfully deleteing the first node in the linked list !!! \O/
        Node *prev = NULL;

        cout << "hi" << endl;

        if(this->list_length == 1){ //if last node happens to also be the only node in list
            this->value = NULL;

        }

        else{ //if not deleting the last node in the list
            this->value = temp->next->value;
            this->next = temp->next->next;
            cout << "bye" << endl;
            cout << this->value << endl;
            cout << this->next << endl;
            cout << "still here" << endl;
        }
        
        this->list_length -= 1;

    }

    int get_list_size(){
        return this->list_length;
    }

    void insert_at(){
        //iterate through node number of times specificed to place in list unless list length < index input then yell at user
        //when 1 less than index place in temp space
        //create new node
        //have old one point at this node now
        //have new node point to next node
        //if first or last minor tweaks...
        //increment size counter

    }

    void delete_at(){
        //iterate through loop to index selected unless greater than size of list
        //get the before node
        //grab the next from current node
        //change previous to point to next
        //decrement size counter
        //if first or last minor tweaks...

    }

    void print_list(){
        //create function in list to print list so its not outside of class

        if(this->list_length == 0)
        {
            cout << "your list is empty" << endl;
            return;
        }

        Node *n = this;
        while(n != NULL)
        {
            
            cout << n->value << endl;;
            n = n->next;
        }
    }

    void check_value(){
        int input;
        cout << "what place in the list would you like to see the value of? " << endl;
        cin >> input;

        if(this->list_length == 0){
            cout << "your list is empty add some items to it before you try to check a value" << endl;
            return;
        }

        while(input < 0 || input > this->list_length){ //make sure we get valid input -- currently not sure what will happen if the list is empty should add a check for that
            cout << "thats not a valid option plase pick a different location" << endl;
            cout << "your list is " << this->list_length << " items long" << endl;
            cin >> input;
        }

        Node *temp = this;
        for(int i = 1; i < input; i++){ //i starts at 1 not 0 due to the node already pointing at place 1 in the list and the user not starting their location at 0
            temp = temp->next;
        }

        cout << "the value at location " << input << " is " << temp->value << endl;

        
        //get index check if valid index
        //find that index get value 
        //spit out value of index yay :D
        
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
//ok this is working so far!!! - not using anymore but left here for now
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

    cout << "length: " << z->get_list_size() << endl;
    cout << "deleting the first value/node (9)" << endl;
    z->delete_node();

    cout << "reprinting now ive deleted first list item (9)" << endl;
    cout << "new length " << z->get_list_size() << endl;
    print_list(z);


    cout << "testing built in print function" << endl;
    z->print_list();

    z->check_value();

    cout << "w list" << endl;
    Node *w = new Node(5);
    cout << "printing w" << endl;
    w->print_list();


    cout << " list was printed " << endl;
    w->delete_node();
    cout << "printing w after deleting node" << endl;
    w->print_list();
    cout << "end of stuff here" << endl;
    w->get_list_size();
    cout << "am i shown? " << endl;
    w->delete_node();
    cout << w->get_list_size() << endl;
    
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
