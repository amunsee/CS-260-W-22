#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::make_pair;
using std::numeric_limits;

class graph{
    private:
    vector <graphnode *> nodes; //all vertices/nodes in the graph
    int num_nodes = 0;

    public:
//thinking i might need a master list of nodes/edge connections in the graph for mst function to use... would have start/end nodes and weighting in it
//would be vector with 3 vectors one for start, end, and weight???
//add an int to keep track of number of nodes?
    graph(){ //constructor
        //maybe dont need anything for constructor???
    }
    
    void add_node(string name){
        graphnode *node = new graphnode{name}; //new node createed
        this->nodes.push_back(node); //add that node to vector of nodes
        this->num_nodes += 1;
    }
    
    //add edge - need to figure out how i want to handle storing the edge weights
    void add_edge(string name1, string name2, int weight){ //iterate through all vertices to see if name1 and name2 are in there if so connect them
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

            this->nodes[node1_pos]->neighbors.push_back(make_pair(this->nodes[node2_pos], weight)); //adding edge to both nodes as it is non directional graph
            this->nodes[node2_pos]->neighbors.push_back(make_pair(this->nodes[node1_pos], weight)); 
        }
        
    }

    //just to show that things are connected. doesnt show edge weights or anything else will need a new print function for shortest path/mst probably
    void print_graph(){
        for(int i = 0; i < this->nodes.size(); i++){
            cout << this->nodes[i]->name << " -> ";
            for(int j = 0; j < this->nodes[i]->neighbors.size(); j++){
                cout << this->nodes[i]->neighbors[j].first->name << " -> " ;
            }
            cout << "Null" << endl;
        }
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////
    //shortest path function
    void shortest_path(string start, string end){
        int inf = numeric_limits<int>::max(); //so i can set distance to nodes to infinity for start of dijikstras algorithm
        vector <graphnode *> unvisited;
        unvisited = this->nodes; //unvisited now has all nodes in graph
  
        int end_destination_index;
        vector <pair<string, vector<string>>> paths; //will hold paths to all nodes to trace start to end nodes
        vector <string> path;


        vector <graphnode *> visited; //initially empty since we havent visited any nodes
        //graphnode* current_node = ; //set to start
        pair <graphnode *, int> current; //holds current node and total distance to get to this node. ned distance to it to add to the distance to its neighbors
        int current_index;
        //create table of initial distances from start node
        vector <pair <graphnode *, int>> dist; //holds the distance from start to each other node

        for(int i = 0; i < unvisited.size(); i++){
            if(unvisited[i]->name == start){
                dist.push_back(make_pair(unvisited[i], 0));
                paths.push_back(make_pair(unvisited[i]->name, path));
                paths[i].second.push_back(unvisited[i]->name); //start will have self as path to self
            }

            else if(unvisited[i]-> name == end){
                dist.push_back(make_pair(unvisited[i], inf));
                end_destination_index = i;
                paths.push_back(make_pair(unvisited[i]->name, path)); //all other nodes start with an empty path
            }

            else{
                dist.push_back(make_pair(unvisited[i], inf));
                paths.push_back(make_pair(unvisited[i]->name, path));
            }
        }
print_list(unvisited);//making sure has 3 to start
cout << " made it" << endl;
        //find node with smallest distance from start to be current node
        while(unvisited.size() != 0){//keep algorithm going until all nodes are visited
        //find node with smallest distance from start -> set to current
        //visit all neighbors of current that are in unvisited list
        //update distance if distance to current + distance to neighbor is smaller than current distance to neighbor
        //once all neighbors are visited current goes to visited list -> restart loop to get new current or if all visited done

            current_index = next_current(dist, visited);
            
            current = make_pair(dist[current_index].first, dist[current_index].second);//new current node - that has the smallest value out of unviisted list

            visited.push_back(dist[current_index].first); //add the new current to visited list
            

            for(int i = 0; i < unvisited.size(); i++){ //remove current from unvisited list
                if(unvisited[i]->name == current.first->name){
                    unvisited.erase(unvisited.begin()+i);
                }

            }

            cout << "current node" << endl;
            cout << current.first->name << endl;
            cout << current.second << endl;
            print_list(unvisited);

            cout << endl;
 //break;            
cout << "stil goin" << endl;
//currently my loop below isnt working or a part in it isnt working
            //time to visit currents neighbors and update values - has to be a neighbor and in the unvisited list otherwise ignore it
            int current_path = node_path_index(dist[current_index].first->name, paths);

            for(int k = 0; k < current.first->neighbors.size(); k++){
                graphnode *current_neighbor = current.first->neighbors[k].first;  
                bool visited_neighbor = check_visited(current_neighbor, visited);
                if(visited_neighbor == false){ //if its true then we skip it and go to next neighbor
                    //do my stuff
                    //find distance from this node to the neighbor and add to distance to this node -- if less than currant distance to the neighbor than update its distance
                    int distance = current.first->neighbors[k].second + current.second;

                    cout << endl;
                    cout << "neighbors distance from me" << endl;
                    cout << current.first->neighbors[k].second << endl; //this is goood
                    cout << "total distance to me" << endl; 
                    cout << current.second << endl; //this is not
                    cout << endl;

                    for(int j = 0; j < dist.size(); j++){
                        if(dist[j].first == current.first->neighbors[k].first){
                            int neighbor_path = node_path_index(dist[j].first->name, paths); //get path to neighbor
                            if(distance < dist[j].second){
                                paths[neighbor_path].second = update_path(paths[current_path].second, paths[neighbor_path].second, dist[j].first->name); //update path to the neighbor
                                dist[j].second = distance; //update min distance to neighbor
                            }
                        }
                    }
                  
cout <<" almost done" << endl;
                    ///finish this -- also in here might be where i deal with updating the path dictionary map thing.
                }

            }
            print_grid(dist);
            cout << "beep boop" << endl; //making it out of the above loop...
        }
           

//never getting out of while loop so this isnt executing
        cout << "end standings " << endl;
        print_grid(dist);

        cout << "The shortest path from: " << start << " to " << end << " is :" << dist[end_destination_index].second << endl;
        cout << "path to destination from start is: " << endl;
        print_path(end, paths);
        //print path from start to dest here.


    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool check_visited(graphnode *current, vector <graphnode *> visited){
        bool is_visited = false;

        for(int i = 0; i < visited.size(); i++){
            if(visited[i]->name == current->name){
                is_visited = true;
                break;
            }
        }

        return is_visited;
    }

    int next_current(vector <pair<graphnode *, int>> nodes, vector<graphnode *> visited){
        pair <int, int> next = make_pair(-1, numeric_limits<int>::max()); //index and value update both when a lower value is found in unvisited vector
     
        for(int i = 0; i < nodes.size(); i++)
        {
            bool unvisited = true;

            if(nodes[i].second <= next.second){
                for(int j = 0; j < visited.size(); j++){
                    if(visited[j]->name == nodes[i].first->name){
                        unvisited = false;
                    }
                }
                if(unvisited == true){
                    next.first = i;
                    next.second = nodes[i].second;
                }                
            }

        }
        cout << "next.first" << endl;
        cout << next.first << endl;
        return next.first; //returning the index that contains the node with the current shortest distance from the start node
    }

    void print_grid(vector <pair <graphnode *, int>> grid){
        for(int i = 0; i < grid.size(); i++)
        {
            cout << grid[i].first->name << " " << grid[i].second << endl;
        }
    }

    void print_list(vector <graphnode *> list){
        cout << " unvisited list" << endl;
        for(int i = 0; i < list.size(); i++){
            cout << list[i] << endl;
        }
    }

    int node_path_index(string name, vector <pair <string, vector <string>>> paths){ //loop through paths until path for given node is found
        for(int i = 0; i < paths.size(); i++){
            if(name == paths[i].first){
                return i;
            }
        }

    }

    vector <string> update_path(vector <string> parent, vector <string> next, string name){ //copy path taken to previous node and add self to it
        next = parent;
        next.push_back(name);
        return next;
    }


    void print_path(string end, vector <pair <string, vector <string>>> paths){

        for(int i = 0; i < paths.size(); i++){
            if(paths[i].first == end){
                for(int j = 0; j < paths[i].second.size(); j++){
                    cout << paths[i].second[j] << "->";
                }
                cout << "Null" << endl;
                return;
            }
        }


    }
    //min spanniing tree algorith   



};
