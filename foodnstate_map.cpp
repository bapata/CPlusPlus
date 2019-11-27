#include <map>
#include <string>
#include <iterator>
#include <iostream>

// Dictionary in C++
// Compile: g++ <this-cpp-file>
// To execute: ./a.out

using namespace std;

int main()
{
    // dictionary to store <food> : <state>
    map<string, string> foodnstate;

    foodnstate["dosa"] = "karnataka";
    foodnstate["upma"] = "tamilnadu";
    foodnstate["poha"] = "maharashtra";
    foodnstate["choley"] = "punjab";
    foodnstate["shahitoast"] = "uttarpradesh";
    foodnstate["guntivankya"] = "andhra";

    for (map<string, string>::iterator it = foodnstate.begin(); it != foodnstate.end(); it++ ) {
        cout<<it->first<<" is from "<<it->second<<endl;
    }

    return 0;
}
