/*test coming soon -- now that program is working will work on adding some way to show that other than manual input via user.*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


class linked_list{
    int value; //able to keep this private so long as i have a method to get the value via get_value
    //linked_list *first = this;
    linked_list *last = this;
    

    public:
    linked_list *next;    //wanted to make this part private as well but couldnt get it to work
    int list_length = 0;

    linked_list(int new_value){
        value = new_value;
        this->next = NULL; //by default set next to NULL when a new linked_list is created, value updated when new linked_list is added after
        list_length = 1; 
    }

    int get_value(){
        return value;
    }

    void set_value(int input){
        this->value = input;
    }

    void set_next(linked_list *next_linked_list){
        this->next = next_linked_list;
    }

    //this add linked_list function is for strictly adding to the back of the list not for inserting anywhere in the list (enqueueing function)
    void add_node(){ //this works for creating a new linked_list just neeed to get it linked to original list. :) making progress
        int node_value;
        cout << "what value would you like to add to your list?: " << endl;
        cin >> node_value;

        linked_list *temp = new linked_list(node_value);
        last->next = temp;

        this->last = temp;

        this->list_length += 1;
    }

    void delete_node(){ //this function just deletes the first linked_list -dequeueing function (currently no checking to see if this is last linked_list in list yet...add later)
       
        if(this->list_length == 0)
        {
            cout << "your list is already empty, nothing left to delete" << endl;
            return;
        }

        linked_list *temp = this; //this delete is successfully deleteing the first linked_list in the linked list !!! \O/
        linked_list *prev = NULL;


        if(this->list_length == 1){ //if last linked_list happens to also be the only linked_list in list
            this->value = NULL;

        }

        else{ //if not deleting the only linked_list in the list
            this->value = temp->next->value;
            this->next = temp->next->next;     
        }
        
        this->list_length -= 1;

    }

    int get_list_size(){
        return this->list_length;
    }

    void insert_at(){ //assumption is that if user wants to add to the end of the list they will add a new linked_list, so this can only add infront of exitsting linked_lists in list
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
            
           linked_list *inserting = new linked_list(this->value); //creating new linked_list that will take first linked_lists value; this linked_list will go in second spot and take first linked_lists values while first
            //linked_list changes values -- wasnt able to get a linked_list to insert at first spot...
          

            int original_value = this->value;

            inserting->next = this->next;
            this->next =inserting;
            this -> value = new_value;
            
        }

        else{//now working -- had to make sure i was updating temp and not pointing to this over and over 
            linked_list *temp = this;

            for(int i = 2; i < location; i++){

                temp = temp->next;           

            }
            
            linked_list *current = temp; //linked_list we are inserting after
            linked_list *next = temp->next; //linked_list we want to insert before

            linked_list *inserting = new linked_list(new_value); //new linked_list to insert into list
            current->next = inserting;
            inserting->next = next;

        }

        this->list_length += 1;

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

        if(location == 1){ //if they want to delete the first linked_list just jump to this method
            this->delete_node();
        }

        else{
            linked_list *temp = this;

            for(int i = 2; i < location; i++){ //starting at location 2 since location 1 is already handled via delete linked_list function.

                temp = temp->next;           

            }
            
            temp->next = temp->next->next;
            
            if(location == this->list_length){ //update this->last to point at the new last item when the last item is removed from linked list.
                this->last = temp;
            }

            this->list_length -= 1;

        }

    }

    void print_list(){
        //create function in list to print list so its not outside of class

        if(this->list_length == 0)
        {
            cout << "your list is empty" << endl;
            return;
        }

        cout << endl;
        cout << "your list contents: " << endl;

        linked_list *temp = this;
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

        linked_list *temp = this;
        for(int i = 1; i < input; i++){ //i starts at 1 not 0 due to the linked_list already pointing at place 1 in the list and the user not starting their location at 0
            temp = temp->next;
        }

        cout << "the value at location " << input << " is " << temp->value << endl;
      
    }
};

void instructions(){

    cout << endl;
    cout << "enter 1 to add an item to the end of your list (enqueue)" << endl;
    cout << "enter 2 to remove the first list item (dequeue)" << endl;
    cout << "enter 3 to insert an item in a specifc place in the list" << endl;
    cout << "enter 4 to remove an item from a specific location in the list" << endl;
    cout << "enter 5 to see the size of the list" << endl;
    cout << "enter 6 to print the contents of the entire list" << endl;
    cout << "enter 7 to see the content of a specific list item" << endl;
    cout << "enter anything else to quit the program" << endl;
}


int main(){

    int initial_value;

    cout << "enter the initial value youd like to create you list with: " << endl;
    cin >> initial_value;


    linked_list *int_list = new linked_list(initial_value);

    bool exit = false;

    int choice = 0;

    while(exit == false){


        instructions();
        
        cin >> choice;

        if (choice == 1){
            int_list->add_node();
        }

        else if (choice == 2){
            int_list->delete_node();
        }

        else if (choice == 3){
            int_list->insert_at();
        }

        else if (choice == 4){
            int_list->delete_at();
        }

        else if (choice == 5){
        
            cout << int_list->get_list_size() << endl;
        }

        else if (choice == 6){
            int_list->print_list();

        }

        else if (choice == 7){
            int_list->check_value();

        }  
        
        else{
            return 0;
        }

    }    

    return 0; //unnecessary to have this return but left anyways
}
