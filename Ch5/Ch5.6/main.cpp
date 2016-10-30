#include <iostream>
#include <vector>
#include <string>

template <typename Key, typename Value>
struct Map{

};

template <class Value>
using String_map = Map<std::string, Value>;

int main(int argc, char const *argv[])
{
    String_map<int> m;   
    return 0;
}