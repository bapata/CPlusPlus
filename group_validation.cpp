#include <iostream>
#include <string>
#include <map>
#include <vector>

// g++ --std=c++2a <this-file>
using namespace std;

int main() {
  map<string, vector<string> > node_group = {
    { "group1", { "h1.example.com", "h2.example.com" } },
    { "group2", { "h3.example.com", "h4.example.com" } },
    { "group3", { "h5.example.com", "h6.example.com" } },
  };
  return 0;
}

bool is_valid_node_groups(map<string, vector<string> > in_node_groups) {
  // fill here
}
