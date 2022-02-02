#include <iostream>

using std::cout;
using std::cin;
using std::endl;



struct Node {
    int value;
    Node *next;
};

class linked_list{ 
    Node *head;
    Node *tail;
    Node *mid;

    int list_length = 0;
    
    public:
  
    linked_list(){
        head = nullptr;
        tail = nullptr;
    }

    void add_node(int node_value){

        if(this->list_length == 0){
            head = new Node{node_value, nullptr};
            tail = head;
            this->list_length =+ 1;

        }
        
        else{
            Node *temp = new Node{node_value, nullptr};
            tail->next = temp;
            tail = temp;

            this->list_length += 1;
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

        Node *temp = head;
        while(temp != nullptr)
        {
            
            cout << temp->value << endl;;
            temp = temp->next;
        }

        cout << endl;
    }

    void insert(int new_value){ //assumption is that if user wants to add to the end of the list they will add a new linked_list, so this can only add infront of exitsting linked_lists in list
      
        if(this->list_length == 0){ //if list has nothing in it no need to sort it
            this->add_node(new_value);
            this->center_mid();
            return;
        }

        else if(tail->value < new_value){
            this->add_node(new_value);
            this->center_mid();
            return;
        }

        else if(head->value >= new_value){
            Node *temp = new Node{new_value};
            temp->next = head;
            head = temp;
            this->list_length += 1;
            this->center_mid();
            return;            
        }


        /*below part not yet done.**/
        
        else{//if list has 1 or more items have to sort as we add. -- no sorting added yet.
            Node *temp = head->next; //since we have the if above we know this wont execut if head is <= to new_value
            Node *before = head;

            for(int i = 1; i < this->list_length; i++){ //alternative would have been while temp->value != nullptr.

                if(temp->value >= new_value){
                    Node *insert = new Node{new_value};
                    before->next = insert;
                    insert->next = temp;
                    return; //to break out of function.

                }

                else{
                    temp = temp->next;
                    before = before->next;  
                }              

            }
            this->list_length += 1;            
        }

        add_node(new_value); //if no node values are smaller in the list than it will be added to the end of the list
        center_mid();
    }

    bool basic_search(int to_find){
        Node *temp = head;

        while(temp != nullptr){
            if(temp->value == to_find){
                cout << to_find << " is in the list" << endl;
                return true;
            }

            else{
                temp = temp->next;
            }
        }

        cout << to_find << " is not in the list" << endl;
        return false;

    }

    void center_mid(){
        int list_mid = list_length/2 + (list_length % 2); 
        mid = head;

        for(int i = 1; i < list_mid; i++){
            mid = mid->next;
        }
    }

    void get_mid(){
        cout << mid->value << " mid value" << endl;
    }



    bool faster_search(int to_find){
        if(mid->value < to_find){
            if(tail->value < to_find){
                cout << to_find  << " is not in the list" << endl;
                return false;
            }

            else{
                for(){
                    //iterate from mid to tail, if not found return false, if found return true
                }
            }
        }

        else if(mid->value > to_find){
            //go from head to mid here.
        }

        else{
            cout << to_find << " is in list" << endl;\
            return true;
        }


        //need to keep track of a middle point in the linked list somehow maybe a pointer that shifts as things are added/removed??
        //then check the middle pointer if its less than search from the middle up to end, if its more then search from the middle down
        //would reduce the amount of things being searched on a worst case scenario by half
        //check the middle if lower check head, if lower not in list if higher check contents from head to mid
        //if higher than mid check tail, if lower check between the two, if higher not in list
    }

};

int main(){
    
    linked_list *int_list = new linked_list();

    int_list->print_list();

    


    int_list->insert(11);
    int_list->print_list();

    int_list->insert(9);

    int_list->print_list();
    int_list->insert(8);
    int_list->insert(7);
    int_list->insert(15);



    int_list->print_list();
    int_list->insert(0);

    //int_list->insert(55);
    int_list->print_list();

    bool ten_found = int_list->basic_search(10);
    bool nine_found = int_list->basic_search(11);

    int_list->get_mid();

    return 0;
}
