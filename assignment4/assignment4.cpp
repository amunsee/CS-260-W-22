#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//modified assignment 3 code for assignment 4.

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
    void add_node(int node_value){ //this works for creating a new linked_list just neeed to get it linked to original list. :) making progress
        
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

        cout << "the value deleted was: " << this->value << endl;

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

    void insert_at(int location, int new_value){ //assumption is that if user wants to add to the end of the list they will add a new linked_list, so this can only add infront of exitsting linked_lists in list
      
            if(location < 1 || location > this->list_length){
                cout << "invalid location please pick something between 1 and " << this->list_length << endl;
                return;
            }
        
        if(location == 1){ //this part inserts at the beginning of the list
            
           linked_list *inserting = new linked_list(this->value);           

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

    void delete_at(int location){

        if(location < 1 || location > this->list_length){
            cout << "invalid location please pick something between 1 and " << this->list_length << endl;
        }
        

        if(location == 1){ //if they want to delete the first linked_list just jump to this method
            this->delete_node();
        }

        else{
            linked_list *temp = this;

            for(int i = 2; i < location; i++){ //starting at location 2 since location 1 is already handled via delete linked_list function.

                temp = temp->next;           

            }
            cout << "the value deleted was: " << temp->next->value;
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

        cout << endl;
    }

    int check_value(int input){
       
        if(this->list_length == 0){
            cout << "your list is empty add some items to it before you try to check a value" << endl;
        }

        if(input < 0 || input > this->list_length){ //make sure we get valid input -- currently not sure what will happen if the list is empty should add a check for that
            cout << "thats not a valid option plase pick a different location" << endl;
            cout << "your list is " << this->list_length << " items long" << endl;
        }

        else{
            linked_list *temp = this;
            for(int i = 1; i < input; i++){ //i starts at 1 not 0 due to the linked_list already pointing at place 1 in the list and the user not starting their location at 0
                temp = temp->next;
            }

            return temp->value;
        }
      
    }
};


int main(){ //removed the ability to interact with the program so that i could try to implement better tests for assignment 4 than 3
            //below is the built in test that will run to show these work

    linked_list *int_list = new linked_list(10);

    for(int i = 0; i < 10; i++){ //add 10 more items to the list - 11 total now
        int_list->add_node(i);
    }

    int_list->print_list(); //print to verify list contents - should print 10, 0, 1... 9

    int_list->insert_at(5, 99); //5th location should now equal 99
    cout << "5th item should now equal 99" << endl;
    int_list->print_list(); //verify 5th item is equal to 99

    int_list->delete_at(5); //should delete the 5th item that - the value 99 we just added in
    int_list->print_list(); //verifying it worked

    cout << "the 2nd item value is: " << int_list->check_value(2) << endl; //should give 0
    cout << "the 5th item value is: " << int_list->check_value(5) << endl; //should give 3
    cout << "the 10th item value is: " << int_list->check_value(10) << endl; //should give 8
     
    return 0;
}
