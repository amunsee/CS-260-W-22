#include <iostream>
#include <vector>
#include <string>

#include "graphnode.hpp"
#include "graph.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(){//driver file/tests to show graph and functions are working

    graph *graphy = new graph(); 

    graphy->add_node("blue"); 
    graphy->add_node("green");
    graphy->add_node("red");
    graphy->add_node("yellow");
    graphy->add_node("pink");

    graphy->print_graph(); //should print each node with no neighbors indicated by just null after node name
    cout << endl;


    graphy->add_edge("red", "blue", 5);
    graphy->add_edge("green", "blue", 2);
    graphy->add_edge("red", "green", 6);
    graphy->add_edge("red", "yellow", 3); 
    graphy->add_edge("yellow", "pink", 7);


    graphy->print_graph(); //verify that blue-pink nodes are  added to graph, and that the edges added above are added to the respective nodes
    //prints out the node and all of its neighbors, the arrows dont indicate a list chain blue->red->green = blues neighbors are red and green.
    //each set of neighbors is ended with null to indicate end of neighbor list
    //should printout blue->red->green, green->blue->red, red->blue->green->yellow, yellow->red->pink, pink->yellow

    cout << endl;
    graphy->shortest_path("yellow", "blue"); //verify that shorest path from yellow to blue is yellow->red->blue nodes with a weight of 8


    cout << endl;
    cout << "mst time" << endl; //should output blue->green, red->yellow, blue->red, pink->yellow with weight of 17
    graphy->min_spanning_tree();
    

    return 0;
}
