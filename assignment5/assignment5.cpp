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

    void add_node(int node_value){ //creates new node and adds it to the list

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

     void print_list(){ //prints out the contents of the list from head to tail

        if(this->list_length == 0)
        {
            cout << endl;
            cout << "your list is empty" << endl;
            return;
        }

        else{
            cout << endl;
            cout << "your list contents: " << endl;

            Node *temp = head;
            while(temp != nullptr)
            {
            
                cout << temp->value << endl;;
                temp = temp->next;
            }

            delete temp;
            cout << endl;
        }
        
    }

    void insert(int new_value){ //assumption is that if user wants to add to the end of the list they will add a new linked_list, so this can only add infront of exitsting linked_lists in list
      
        if(this->list_length == 0){ //if list has nothing in it no need to sort it
            this->add_node(new_value);
            this->center_mid();
        }

        else if(tail->value < new_value){
            this->add_node(new_value);
            this->center_mid();
        }

        else if(head->value >= new_value){
            Node *temp = new Node{new_value};
            temp->next = head;
            head = temp;
            this->list_length += 1;
            this->center_mid();          
        }

        
        else{//if list has 1 or more items have to find right spot to put it
            Node *temp = head->next; //since we have the if above we know this wont execut if head is <= to new_value
            Node *before = head;

            for(int i = 1; i < this->list_length; i++){ //alternative would have been while temp->value != nullptr.

                if(temp->value >= new_value){
                    Node *insert = new Node{new_value};
                    before->next = insert;
                    insert->next = temp;

                    delete temp;
                    delete before;
                }

                else{
                    temp = temp->next;
                    before = before->next;  
                }              

            }
            this->list_length += 1;            
        }

    }

//---was unsure as to whether or not we needed to search for a value to find it, or search to find it and remove it based on instructions ---
    bool basic_search(int to_find){
        Node *temp = head;

        while(temp != nullptr){
            if(temp->value == to_find){
                cout << to_find << " is in the list" << endl;

                temp = NULL;
                delete temp;
                return true;
            }

            else{
                temp = temp->next;
            }
        }

        temp = NULL;
        delete temp;
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


//make sure faster search looks good - deletes and remove unneccessary returns. --other stuff to add in for assignment?
//could have more pointers that point to sections if the data set was large enough, a pointer to inbetween mid and head, 
//and one between mid and tail or more as needed to create a pseudo binary search
    bool faster_search(int to_find){
        if(mid->value < to_find){ //if searched for value is greater than mid value
            if(tail->value == to_find){
                cout << to_find << " is in list" << endl;
                return true;

            }

            else if(tail->value < to_find){ //if tail is less than value than its not in the list since tail is the largest number in list
                cout << to_find  << " is not in the list" << endl;
                return false;
            }

            else{ //search for it between mid and tail
                Node *temp = mid;
                while(temp != nullptr){
                    if(temp->value == to_find){
                        cout << to_find << " is in list" << endl;
                        temp = NULL;
                        delete temp;
                        return true;
                    }

                    else{
                        temp = temp->next;
                    }
                }

                temp = NULL;
                delete temp;
                cout << to_find << " is not in the list" << endl;
                return false;
            }
        }

        else if(mid->value > to_find){ //if mid is larger than searched for value than we look in first half of list
            if(head->value == to_find){
                cout << to_find << " is in the list" << endl;
                return true;
            }

            else if(head->value > to_find){ //if head is > than searched for value its not in list as head is smallest value in list
                cout << to_find << " is not in the list" << endl;
                return false;
            }

            else{ //search for it between head and mid
                Node *temp = head;
                int mid_location = list_length/2 + (list_length % 2);
                for(int i = 0; i < mid_location; i++){
                    if(temp->value == to_find){
                        temp = NULL;
                        delete temp;
                        cout << to_find << " is in list" << endl;
                        return true;
                    }

                    else{
                        temp = temp->next;
                    }
                }

                temp = NULL;
                delete temp;
                cout << to_find << " is not in the list" << endl;
                return false;

            }
        }

        else{ //if mid is == to the value being searched for
            cout << to_find << " is in list" << endl;\
            return true;
        }

    }

};

int main(){
    
    linked_list *int_list = new linked_list();

    int_list->print_list(); //list creation

    int_list->insert(11); //first node added
    int_list->print_list(); //verify 11 is in the list

    int_list->insert(9); //add 9
 
    int_list->print_list(); //verify that 9 is in the list before 11
    int_list->insert(8); 
    int_list->insert(7);
    int_list->insert(15); //list should now contain values 7,8,9,11,15 in that order



    int_list->print_list(); //should match above order
    int_list->insert(0);

    int_list->insert(55);
    int_list->print_list(); //verify list is now: 0,7,8,9,11,15,55

    bool ten_found = int_list->basic_search(10); //should output 10 is not in list
    bool nine_found = int_list->basic_search(11); //should output 11 is in list

    int_list->print_list();

    bool fast_10_found = int_list->faster_search(10);
    bool fast_11_found = int_list->faster_search(11);
    bool fast_6_found = int_list->faster_search(6);
    bool fast_7_found = int_list->faster_search(7);
    bool fast_neg1_found = int_list->faster_search(-1);
    bool fast_0_found = int_list->faster_search(0);

    int_list->get_mid();

    return 0;
}
