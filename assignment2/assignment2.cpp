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

        else{ //if not deleting the only node in the list
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

    void insert_at(){ //assumption is that if user wants to add to the end of the list they will add a new node, so this can only add infront of exitsting nodes in list
        int location = 0;
        int new_value;

        while (location < 1 || location >this->list_length){
            cout << "where would you like to insert the value in your list: 1-" << this->list_length <<endl;
            cin >> location;

            if(location < 1 || location > this->list_length){
                cout << "invalid location please pick something between 1 and " << this->list_length << endl;
            }
        }

        cout << "What value would you like to insert at that location?: " << endl;
        cin >> new_value;

        if(location == 1){ //this part working great at inserting at the beginning of the list! yay
            
           Node *inserting = new Node(this->value); //creating new node that will take first nodes value; this node will go in second spot and take first nodes values while first
            //node changes values -- wasnt able to get a node to insert at first spot...
          

            int original_value = this->value;

            inserting->next = this->next;
            this->next =inserting;
            this -> value = new_value;

        }

        else{//now working -- had to make sure i was updating temp and not pointing to this over and over 
            Node *temp = this;

            for(int i = 2; i < location; i++){


                cout << "i " << i << endl;
                cout << temp->value << endl;
                temp = temp->next;           

            }
            
            Node *current = temp; //node we are inserting after
            Node *next = temp->next; //node we want to insert before

            Node *inserting = new Node(new_value); //new node to insert into list
            current->next = inserting;
            inserting->next = next;

        }

    }

    void delete_at(){
        int location = 0;

        while (location < 1 || location >this->list_length){
            cout << "where would you like to delete the value in your list: 1-" << this->list_length <<endl;
            cin >> location;

            if(location < 1 || location > this->list_length){
                cout << "invalid location please pick something between 1 and " << this->list_length << endl;
            }
        }

        if(location == 1){ //if they want to delete the first node just jump to this method
            this->delete_node();
        }

        else{
            Node *temp = this;

            for(int i = 2; i < location; i++){ //starting at location 2 since location 1 is already handled via delete node function.


                cout << "i " << i << endl;
                cout << temp->value << endl;
                temp = temp->next;           

            }
            
            temp->next = temp->next->next;

        }

    }

    void print_list(){
        //create function in list to print list so its not outside of class

        if(this->list_length == 0)
        {
            cout << "your list is empty" << endl;
            return;
        }

        Node *temp = this;
        while(temp != NULL)
        {
            
            cout << temp->value << endl;;
            temp = temp->next;
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
      
    }
};


//ok this is working so far!!! - not using anymore but left here for now
  void print_list(Node *n){
    
        while (n != NULL){
            cout << n->get_value() << endl;
            n = n->next;
        }
    }



int main(){

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

/*
    cout << "testing built in print function" << endl;
    z->print_list();
    z->insert_at();
    cout << "printing new list now" << endl << endl;
    z->print_list();
*/
    cout << "now to delete at spots" << endl;
    z->delete_at();
    
    cout << "printing list again time to see if i deleted my index" << endl;
    z->print_list();

/*
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
*/
    return 0;
}
