#include <iostream>
#include <vector>
#include <string>

#include "graphnode.hpp"
#include "graph.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(){

    graph *graphy = new graph();

    graphy->add_node("blue");
    graphy->add_node("green");
    graphy->add_node("red");
    graphy->add_node("yellow");


    graphy->add_edge("red", "blue", 5);
    graphy->add_edge("green", "blue", 2);
    graphy->add_edge("red", "green", 6);
    graphy->add_edge("red", "yellow", 3);

    graphy->print_graph();

    cout << "here" << endl;
    //above line working
    graphy->shortest_path("yellow", "blue");

    cout <<"wooo made it to the end no issues" << endl;

    

    return 0;
}
