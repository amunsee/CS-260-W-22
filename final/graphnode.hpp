#include <string>
#include <vector>
#include <utility>

using std::string;
using std::vector;
using std::pair;

struct graphnode{
    string name;
    //vector <graphnode *> neighbors; //each index of the 2 vectors matches together, neighbors[0] weight between it and the start node is neighbor_weights[0]
    //vector <int> neighbor_weights;
    vector <pair <graphnode *, int>> neighbors; //vector holds pair  that contains the neighbor and weight of getting to neighbor
};
