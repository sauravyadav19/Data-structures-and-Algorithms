/*
   - Objective: To find the shorest distance from a source node to all other nodes in the graph
   - Algorithm in use : We are using Dijkstra's Algorithm 
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
#include <climits>
using namespace std;


// STEP 2
// Returns the Index of the node with the minimum distance and that has not been visited yet
// In case all the nodes are visited it return -1
int getUnvisitedMinDistance(vector<bool>& isVisited, vector<int>& distance){

    int i = 0;

    // find the first node/index that is not visited yet 
    while(i < isVisited.size() && isVisited[i]){
        i++;
    }
    // If all nodes has been visited we simply return -1 as the index
    if(i >= isVisited.size()){
        return -1;
    }
    // but if there are nodes that is yet not been visited, we simply initialize min with the first
    // unvisited node's index
    int minIndex = i;

    // Now compare each unvisited node/index against the 'min's distance'
    // if there is a index that is not yet visited and has a smaller distance than 'min'
    // we return that index
    for(int j = 0; j < isVisited.size(); j++){
        if(isVisited[j] == false  && distance[minIndex] > distance[j]){
            minIndex = j;
        }
    }

    return minIndex;
}

vector<int> dijkstrasAlgorithm(vector<vector<vector<int>>>& graph, int sourceNode = 0){

        // Helper Data strctures:
        int noOfNodes = graph.size();

        //Step 1: Initalizing all the distances to be Infinity
        // Creates an array with noOfNodes as its size and all the values intialized with INT_MAX
        vector<int> distances(noOfNodes,INT_MAX);

        // Creating an array to track all the nodes we have visited.
        // here the indices will specifiy if the node has been visited or not.
        // Example if at zeroth index its false it means that 0 node has not been yet visited
        // we starting of with all the nodes as not visited, hence all the index will have false as the value
        vector<bool> isVisited(noOfNodes,false);

        // Changing the distance of the source Node to source Node to be zero in the Distance array
        distances[sourceNode] = 0;

        // Step 3:
        // starting with traversing and relaxation
        int visitingNode = getUnvisitedMinDistance(isVisited,distances);
        // We will exit the loop if once all the nodes have been visited 
        // that happens when getUnvisitedMinDistance () return -1;
        while(visitingNode != -1){
            isVisited[visitingNode] = true;
            // Iterating through all the neighbours of a node
            for(int i = 0; i < graph[visitingNode].size(); i++){
                vector<int> neighbor = graph[visitingNode][i];
                int node = neighbor[0];
                int weight = neighbor[1];
                // We need to make sure that the current node(visiting node) does not has the weight of INT_MAX
                // because that would result in unexpected values
                if(distances[visitingNode] != INT_MAX && distances[visitingNode] + weight < distances[node]){
                    // Performing Relaxation
                    distances[node] = distances[visitingNode] + weight;
                }
            }

            // Displaying the Distance array iteration of a node visit
            cout<< visitingNode << " | ";
            for(auto& el : distances){
                if(el == INT_MAX){
                    cout<< "\tINT_MAX";
                }else{
                    cout<<"\t"<<el << " ";
                }
            }
            cout<<endl;

            visitingNode = getUnvisitedMinDistance(isVisited,distances);
        }

        // Before returning the distances array we need to make sure that some nodes might have INT_MAX as their
        // values i.e these  nodes are not connected to the graph and have no neighbour, we are sending -1 instead
        // of sending a large number such as INT_MAX for readablitiy and for working purposes
        for(int i = 0; i < distances.size(); i++){
            if(distances[i] == INT_MAX){

                distances[i] = -1;
                
            }
        }

        //  Returning the distances array which contains the smallest distance from source node to all other nodes
        return distances;

}

int main(){
    // Initializing our Graph
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
            {}};
    
    // Printing the minimu distance from source node to all other nodes in the Graph
    // if a distance for a node is  -1 means that there is no path to reach that node from the source node
    for(int& el: dijkstrasAlgorithm(graph,0)){
        cout<< el << " ";
    }
    cout<< endl;

    return 0;
}