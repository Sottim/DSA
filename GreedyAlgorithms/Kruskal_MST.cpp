#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct EDGE{
    int src;
    int dst;
    int weight;
};

struct GraphNode{
    int parent;
    int rank;
};

vector<GraphNode> graph; // Declaration of graph

int find(int node) {
    if (graph[node].parent == -1)
        return node;
    return graph[node].parent = find(graph[node].parent); // Update the parent during path compression
}

void Union(int from, int to) {
    int fromParent = find(from);
    int toParent = find(to);
    if (graph[fromParent].rank < graph[toParent].rank) {
        graph[fromParent].parent = toParent;

    } else if (graph[fromParent].rank > graph[toParent].rank) {
        graph[toParent].parent = fromParent;

    } else {
        graph[toParent].parent = fromParent;
        graph[fromParent].rank++;
    }
}

bool comparison(EDGE a, EDGE b){
    // if a.weight is less than b.weight form the EDGE vector, it returns true and a is placed before b in the sorting order
    return (a.weight < b.weight);
}

void printMST(vector<EDGE>& mst){
    //printing each nodes source, desti and weights
    for(auto i: mst){
        cout << "source: "<<i.src << "destination: "<<i.dst << "weight: " <<i.weight << "\n";
    }
}


void Kruskal(vector<EDGE>& edgeList, int vertex, int edge){
    // We sort the edge list according to the weight by calling the comparison
    sort(edgeList.begin(), edgeList.end(), comparison);

    vector<EDGE> mst;
    int i=0;
    int j=0;
    // we need to check v-1 edges in total and j < edge keeps track of how many edges have we considered so far
    while(i < vertex-1 && j < edge)
    {
        int from_Parent = find(edgeList[j].src); //finding absolute parent set
        int to_Parent = find(edgeList[j].dst);
        //if parents of both the nodes are same then by adding a new edge from src to dst will form a cycle. Thus ignore this edge
        if(from_Parent == to_Parent){
            ++j;
            continue;
        }
        //If not we peform the UNION operation
        Union(from_Parent, to_Parent);
        //pushing all the edges selected into the mst vector 
        mst.push_back(edgeList[j]);
        ++i;
    }
    printMST(mst);

}


int main(){
    int edge, vertex;
    cin >> edge >> vertex;
    cout.flush(); // Flush the output stream to display the prompt
    graph.resize(vertex);
    for(int i=0; i<vertex; i++){
        //Intially parent of every node present in graph array of type struct is -1 and rank is 0
        graph[i].parent = -1;
        graph[i].rank = 0;
    }
    //Initialize new array called EDGE 
    vector<EDGE> edgeList;
    EDGE temp;
    for(int i=0; i<edge; i++){
        // Each node will have these information 
        int from;
        int to;
        int weight;
        cin >> from >> to >> weight;
        temp.src = from;  // src means source 
        temp.dst = to;   // dst means destination 
        temp.weight = weight;
        //We need to push them in the edgeList
        edgeList.push_back(temp);
    }
    // calling function giving edgeList entered by user
    Kruskal(edgeList, vertex, edge);

    return 0;
}
