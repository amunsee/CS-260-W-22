/*For the sake of simplicity in this assignment i kept the adding/removing of marbles to one at a time, in a more complicated assignment implementing an option to allow the user to input how many marbles to remove/add could be implemented with some checks to make sure the user is not trying to remove more marbles than are currently in the bag, and even allowing the user to choose what color and how many of the color to add or remove. - may implement these later just to practice some c++ code
*/
#include <iostream>
#include <time.h>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

//void check_bag(int &red, int &blue, int &green, vector<int> &bag); took this function out, can figure out whats in the bag just with the ints keeping track of the colors
void add_marble(int &red, int &blue, int &green, vector<int> &bag);
void remove_marble(int &red, int &blue, int &green, vector<int> &bag);


int main(){

    srand(time(0));

    int red = 0; 
    int blue = 0;
    int green = 0;

    int n = 15;
    cout << "number of marbles: " << n << endl;
    vector<int> bag = {}; //ended up learning what a vector was while trying to make arrays work so scrapped that idea and changed it :D

    

    for(int i = 0; i<n; i++){  //initializing the bag of marbles with 15 random color marbles. - can be initialized with any number just choose 15 - probably should have added a function
        int marble = rand() % 3;
               
        if(marble == 0){
            red += 1;
        }

        else if (marble == 1){
            blue += 1;
        }

        else{
            green += 1;
        }

        bag.push_back(marble);
    }
   
  
    while(true){ //menu of options for user that goes until something that isnt 1,2, or 3 is input
        int choice = 0;

        cout << "Enter 1 to add a marble to the bag" << endl;
        cout << "Enter 2 to remove a marble from the bag" << endl;
        cout << "Enter 3 to look at the contents of the marble bag" <<endl;
        cout << "Enter anything else if you've lost your marbles and want to be done with this program\n" << endl;

        cin >> choice;

        if(choice == 1) //go to add marble function
        {
            add_marble(red, blue, green, bag);
        }

        else if (choice == 2)//go to remove marble funct
        {
            remove_marble(red, blue, green, bag);
        }

        else if (choice == 3)//go to check_bag funct -- no long check_bag funct was able to get all data needed for this from the 3 ints keeping track of # of each color
        {
            cout << "you peak in side the bag and see that there are " << red << " red marbles, " << blue << " blue marbles, and " 
            << green << " green marbles in the bag for a total of " << red+green+blue << " marbles" << endl;
        }

        else{ //bye
        cout << "cya later homes" << endl;
            return 0;
        }
        
        
    }

    return 0; //guess i dont need this one but left it for formality
}

void add_marble(int &red, int &blue, int &green, vector<int> &bag){ //generate random color marble add to bag and increase the color by 1
    int marble = rand() % 3;
    string color = "";

    if(marble == 0){
        red += 1;
        color = "red";
    }

    else if (marble == 1){
        blue += 1;
        color = "blue";
    }

    else{
        green += 1;
        color = "green";
    }

    bag.push_back(marble);
    cout << "you have added a " << color << " marble to the bag." << endl;
}

void remove_marble(int &red, int &blue, int &green, vector<int> &bag){ //pick random marble out of bag and remove, check color and decrease the number by 1
    int bag_capacity = bag.size();
    int unlucky_marble = rand() % bag_capacity;

    vector<int>::iterator selected = bag.begin();

    for(int i = 0; i < unlucky_marble; i++){
        selected++;
    }

    if(bag[*selected] == 0){
        cout << "a red marble was randomly selected and removed from the bag " << endl;
        red--;
    }

    else if(bag[*selected] == 1){
        cout << "a blue marble was randomly selected and removed from the bag " << endl;
        blue--;
    } 

    else{
        cout << "a green marble was randomly selected and removed from the bag " << endl;
        green--;
    }
}
