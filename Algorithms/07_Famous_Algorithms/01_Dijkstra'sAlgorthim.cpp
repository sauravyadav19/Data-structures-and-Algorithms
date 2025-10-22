/*
   - Objective: To find the shorest distance from a source node to all other nodes in the graph
   - Algorithm in use : We are using Dijsktra's Algorithm 
   - How does it works? 
        => We start of with assuming that every node is very far away with an unknown distance (infinity)
            and as we start the traversal of our graph from the source node to all other nodes, we continue to update these distance 
            with something called "relaxation" of the node, this relaxation is done when the current distance to the reach that node
            is bigger than what we have find. 
        => We keep an array of all the nodes we have visited and when its length is equal to that of length of all the nodes in the 
            graph we exit the loop. 
        => The core idea why this algorithm works is that at every step we are picking a unvisited node with least amount of distance 
        required to reach it.

    - Where does this algorithm fails?
        => when we have negative weights, this algorithm fail there becasue it assumes that when we placed a node in the visited array
         there could not be a better path to reach that, but negative number totally off throws this logic for negative weights we have
         a different algorithm called bellman fort algorithm.

-  Rough algorithm will look something like this:
        1. Initialize all nodes with an infinite distance, except the source.
        2. Pick the unvisited node with the smallest known distance.
        3. Relax all its outgoing edges — if a shorter path to a neighbor is found, update it.
        4. Mark the current node as visited (its shortest path is now finalized).
        5. Repeat until all nodes are visited

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<vector<int>>> graph = {
        // 0
        {{1,7}}, // this means that there is an edge from 0 to 1 with a weight of 7

        //1
        {{2,6}, {3,20}, {4,3}}, // this means there is a edge from 1 to 2,3 and 4 with respective weight of 6,20 and 3

        //2
        {{3,14}},

        //3
        {{4,2}},

        //4
        {},  // this means that there is not outgoing edge from 4

        //5
        {}
    };
    return 0;
}