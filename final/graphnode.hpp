#include <string>
#include <vector>

using std::string;
using std::vector;

struct graphnode{
    string name;
    vector <graphnode *> neighbors;

};
