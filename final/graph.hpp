#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <limits>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;
using std::numeric_limits;
using std::priority_queue;
using std::greater;

class graph{
    private:
    vector <graphnode *> nodes; //all vertices/nodes in the graph
    int num_nodes = 0;

    public:
    graph(){ //constructor
    }
    
    void add_node(string name){
        graphnode *node = new graphnode{name}; //new node createed
        this->nodes.push_back(node); //add that node to vector of nodes
        this->num_nodes += 1;
    }
    
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
    //shortest path function - using dijikstras algorithm
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


            //time to visit currents neighbors and update values - has to be a neighbor and in the unvisited list otherwise ignore it
            int current_path = node_path_index(dist[current_index].first->name, paths);

            for(int k = 0; k < current.first->neighbors.size(); k++){
                graphnode *current_neighbor = current.first->neighbors[k].first;  
                bool visited_neighbor = check_visited(current_neighbor, visited);
                if(visited_neighbor == false){ //if its true then we skip it and go to next neighbor
                    
                    //find distance from this node to the neighbor and add to distance to this node -- if less than currant distance to the neighbor than update its distance
                    int distance = current.first->neighbors[k].second + current.second;

             
                    for(int j = 0; j < dist.size(); j++){
                        if(dist[j].first == current.first->neighbors[k].first){
                            int neighbor_path = node_path_index(dist[j].first->name, paths); //get path to neighbor
                            if(distance < dist[j].second){
                                paths[neighbor_path].second = update_path(paths[current_path].second, paths[neighbor_path].second, dist[j].first->name); //update path to the neighbor
                                dist[j].second = distance; //update min distance to neighbor
                            }
                        }
                    }
                }
            }
        }
           

        cout << "The shortest path from: " << start << " to " << end << " is :" << dist[end_destination_index].second << endl;
        cout << "path to destination from start is: " << endl;
        print_path(end, paths);   //print path from start to dest here.


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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //min spanniing tree algorith  -- need all nodes in graph, need all edges of each node in graph, # of nodes in graph.
    void min_spanning_tree(){ //using kruskals algorithm
        typedef pair <int, pair <string, string>> total_edges; //change name....
        vector <pair <string, string>> mst_edges; //holds all the edges to form the mst
        vector <vector<string>> edge_groups;
        int num_nodes = this->nodes.size();

        cout << "number of nodes is: " << this->nodes.size();

        int mst_weight = 0;
        int groups_counter = 0;

        priority_queue <total_edges, vector<total_edges>, greater<total_edges>> pq; //will hold all edge weights/connected nodes in a min heap queue
        //fill queue
        for (int i = 0; i < num_nodes; i++){
            for(int j = 0; j < this->nodes[i]->neighbors.size(); j++){
                pq.push(make_pair(this->nodes[i]->neighbors[j].second, make_pair(this->nodes[i]->name, this->nodes[i]->neighbors[j].first->name)));
            }
        }
    

        //go through queue from smalleset weight to largest weight costing edges
        while(pq.empty() == false || mst_edges.size() < num_nodes-1){ 
            cout << "in business now" << endl;
            pair <int, pair<string, string>> top = pq.top();
            pair<int, int> to_add;
            to_add = check_redundant(edge_groups, top.second);
            vector <string> visited;

//-2 means dont add its redundant, -1 has no group, anything else i an existing group
            if(to_add.first != -2 && to_add.second != -2){//work on this once i get my other function sorted out, need to deal with creating new groups and joining groups, and adding the edges here.


    cout << "time to work magic" << endl;

                if(to_add.first == -1 && to_add.second == -1){
                    //create new edge group
                    vector <string> group;
                    
                    edge_groups.push_back(group);

                    edge_groups[groups_counter].push_back(top.second.first); //add the data to the new group
                    edge_groups[groups_counter].push_back(top.second.second);
                    groups_counter += 1;

                    cout << "groups time" << endl;
                  
                    cout << "counter" << groups_counter << endl;
                    cout << " how we doin now" << endl;
                }

                else if(to_add.first == -1 || to_add.second == -1){
                    cout << "case 2" << endl;
                    if(to_add.first == -1){
                        edge_groups[to_add.second].push_back(top.second.first);
                        edge_groups[to_add.second].push_back(top.second.second);
                    }

                    else{
                        edge_groups[to_add.first].push_back(top.second.first);
                        edge_groups[to_add.first].push_back(top.second.second);
                    }
                }

                else{
                    cout << "case 3" << endl;
                    edge_groups[to_add.first].push_back(top.second.first); //add new edge to group
                    edge_groups[to_add.first].push_back(top.second.second);
                    //copy second group to 1st
                    for(int i = 0; i < edge_groups[to_add.second].size(); i++){
                        edge_groups[to_add.first].push_back(edge_groups[to_add.second][i]);
                    }

                    //delete second group

                    edge_groups.erase(edge_groups.begin() + to_add.second);

                    //decrement group counter
                    groups_counter -= 1;
                    }


                cout << "pickle" << endl;
                
                //add the edge here.
                mst_edges.push_back(make_pair(top.second.first, top.second.second));//good
                cout << "added " << top.second.first << " " << top.second.second << endl;
                mst_print(mst_edges);
                
                mst_weight += top.first;//good
                cout << "current weight: " << mst_weight << endl;
            }

            pq.pop();
        }
            cout << "Minimum Weight Spanning Tree connections:" << endl;
            mst_print(mst_edges);
            cout << "Minimum Spanning Tree Weight: " << mst_weight << endl;
    }


    pair <int, int> check_redundant(vector <vector<string>> edge_groups, pair <string, string> edge){
        int string1_group = -1;
        int string2_group = -1;
        pair<int, int> group_pair;
        group_pair.first = -1;
        group_pair.second = -1;
        bool same_group = false;

        cout << "checking edge groups" << endl;

        for(int i = 0; i < edge_groups.size(); i++){
            for(int j = 0; j < edge_groups[i].size(); j++){
                cout << edge_groups[i][j] << " i " << i  << endl;
            }
        }
        cout << "done with that " << endl;

        
        cout << "am i redundant" << endl;
        if(edge_groups.empty() == true){
            group_pair.first = -1;//-1 means new group needed
            group_pair.second = -1;
            cout << "empty groups yikes" << endl;
            cout << "pair: "<< group_pair.first << " " << group_pair.second << endl;
            return group_pair;
        }

        //check for groups here


        for(int i = 0; i < edge_groups.size(); i++){
            
            for(int j = 0; j < edge_groups[i].size(); j++){
                cout << "word at: " << edge_groups[i][j] << endl;
                cout << " word looking for " << edge.first << endl;
                if(edge_groups[i][j] == edge.first){
                    cout << "cheese" << endl;
                    cout << i << endl;
                    string1_group = i;
                    cout << "string 1 " << i << endl;
                    break;
                }
            }
        }   


        for(int i = 0; i < edge_groups.size(); i++){
            cout << "group i " << i << endl;
            
            for(int j = 0; j < edge_groups[i].size(); j++){
                if(edge_groups[i][j] == edge.second){
                    cout << "peek" << endl;
                    string2_group = i;
                    cout << "string 2 should be " << i << endl;
                    break;
                    }
                }   
            }

        if(string1_group == string2_group){ //try else if here if this doesnt work
            //edge_groups not empty and they are same group
            if(string1_group == -1 && string2_group == -1){
                return make_pair(-1, -1);
            }
            cout << "popping into 3" << endl;
            cout << " same group " << endl;
            cout << "same group -2 " << endl;
            return make_pair(-2, -2);
        }

        else if(string1_group != string2_group){//at least one has a group or both have a different group
            cout << "popped in 2" << endl;
            return make_pair(string1_group, string2_group);
        }

        
        
    }  
    bool check_contains(vector <string> group, string search_for){
        for(int i = 0; i < group.size(); i++){
            if(group[i] == search_for){
                return true;
            }
        }
        return false;
    }

    void mst_print(vector <pair <string, string>> mst){
        for(int i = 0; i < mst.size(); i++){
            cout << mst[i].first << "->" << mst[i].second << endl;
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};
