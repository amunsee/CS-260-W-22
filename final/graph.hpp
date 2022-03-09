#include <vector>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class graph{
    private:
    vector <graphnode *> nodes; //all vertices/nodes in the graph

    public:

    graph(){ //constructor
        //maybe dont need anything for constructor???
    }
    
    void add_node(string name){
        graphnode *node = new graphnode{name}; //new node createed
        this->nodes.push_back(node); //add that node to vector of nodes
    }
    
    //add edge
    void add_edge(string name1, string name2){ //iterate through all vertices to see if name1 and name2 are in there if so connect them
        int node1_pos = -1;
        int node2_pos = -1;

        for(int i = 0; i < this->nodes.size(); i++){ //searching to find the node that contains name 1
            if(name1 == this->nodes[i]->name){
                node1_pos = i;
                break;
            }
        }

        for (int j = 0; j < this->nodes.size(); j++){ //searching to find the node that contains name 2
            if(name2 == this->nodes[j]->name){
                node2_pos = j;
                break;
            }
        }

        if(node1_pos == -1 || node2_pos == -1){ //if either are still -1 then 1 or both werent found so exiting function
            cout << "unable to create edge one or both nodes doesnt exist" << endl;
            return;
        }

        else{
            this->nodes[node1_pos]->neighbors.push_back(this->nodes[node2_pos]); //leave as one for directed, or can do both to eachother for undirected graph...
        }
        
    }

    //shortest path function

    //min spanniing tree algorith   

};
