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
    graphy->add_node("pink");


    graphy->add_edge("red", "blue", 5);
    graphy->add_edge("green", "blue", 2);
    graphy->add_edge("red", "green", 6);
    graphy->add_edge("red", "yellow", 3); //mst current works for my 4 nodes graph...but adding pink it goes back to adding repeats...
    graphy->add_edge("yellow", "pink", 7);


    graphy->print_graph();

    //cout << "here" << endl;
    //above line working
    graphy->shortest_path("yellow", "blue");

    //cout <<"wooo made it to the end no issues" << endl;

    
    cout << "mst time" << endl;
    graphy->min_spanning_tree();
    

    return 0;
}
