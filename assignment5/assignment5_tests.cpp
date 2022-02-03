#include <iostream>

#include "assignment5_list.cpp"

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

    int nums[6] = {10, 11, 6, 7, -1, 0};

    for(int i = 0; i < 6; i++){
        bool found = int_list->faster_search(nums[i]);

        if(found == false){
            cout << nums[i] << " was not found in the list" << endl;
        }

        else{
            cout << nums[i] << " was found in the list" << endl;
        }
    }
/* turned this chunk into the above loop
    bool fast_10_found = int_list->faster_search(10);
    bool fast_11_found = int_list->faster_search(11);
    bool fast_6_found = int_list->faster_search(6);
    bool fast_7_found = int_list->faster_search(7);
    bool fast_neg1_found = int_list->faster_search(-1);
    bool fast_0_found = int_list->faster_search(0);
*/
    return 0;
}
