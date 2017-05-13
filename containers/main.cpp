#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>

#include <set>
#include <map>

#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>


int main(int, char*[])
{
    // Containers

    // Sequence Containers
    std::array<int,4>           fixed_size_array;
    std::deque<int>             double_ended_queue;
    std::forward_list<int>      singly_linked_list;
    std::list<int>              doubly_linked_list;
    std::vector<int>            dynamic_array;

    // Associative Containers
    std::set<int>               set;
    std::multiset<int>          multi_set;
    std::map<int,double>        map;
    std::multimap<int,double>   multi_map;

    // Unordered Associative Containers
    std::unordered_set<int>             hash_set;
    std::unordered_multiset<int>        hash_multi_set;
    std::unordered_map<int,double>      hash_map;
    std::unordered_multimap<int,double> hash_multi_map;

    // Container Adaptors
    std::stack<int/*, std::deque<int>*/>               first_in_last_out;
    std::queue<int/*, std::deque<int>*/>               first_in_first_out;
    std::priority_queue<int/*, std::vector<int>*/>     priority_queue;
}
