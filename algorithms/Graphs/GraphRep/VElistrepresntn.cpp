#include<bits/stdc++.h>
using namespace std;

// ALL WRT UNDIRECTED GRAPH

// Directly storing names of vertices in edgelist(takes lots of memory, inefficient)
// struct Edges{
//     string Ver1;
//     string Ver2;
//     int Weight;
// };

// storing pointer to name(string type name) in edgelist(efficient)
// struct Edges{
//     char* Ver1;
//     char* Ver2;
//     int Weight;
// };

// storing indices of vertex(efficient)
// struct Edges{
//     int Ver1;
//     int Ver2;
//     int Weight;
// };


class Edges{
    public:
    string Ver1;
    string Ver2;
    int Weight;
    void getEdge(string V1, string V2, int W);     // constructor for getting and edge
};

void Edges::getEdge(string V1, string V2, int W){
    Ver1 = V1;
    Ver2 = V2;
    Weight = W;
}




int main()
{
    int v = 8;
    // cout << "Enter number of vertices : ";
    // cin >> v;                                   // |V| = v
    string VER_LIST[v];                            // array list of vertices
    Edges EDGE_LIST[v * (v - 1)];                  // array list of edges

    VER_LIST[0] = "Priyanshu";
    VER_LIST[1] = "Kanak";
    VER_LIST[2] = "Ashish";
    VER_LIST[3] = "Madhu";
    VER_LIST[4] = "Rakesh";
    VER_LIST[5] = "Gaurav";
    VER_LIST[6] = "Anuj";
    VER_LIST[7] = "Bhide";

    EDGE_LIST[0].getEdge("Priyanshu", "Rakesh", 40);
    EDGE_LIST[1].getEdge("Rakesh", "Kanak", 36);
    EDGE_LIST[2].getEdge("Kanak", "Madhu", 20);
    EDGE_LIST[3].getEdge("Anuj", "Gaurav", 19);
    EDGE_LIST[4].getEdge("Rakesh", "Ashish", 49);
    EDGE_LIST[5].getEdge("Rakesh", "Gaurav", 12);
    EDGE_LIST[6].getEdge("Anuj", "Rakesh", 15);
    EDGE_LIST[7].getEdge("Anuj", "Kanak", 20);
    EDGE_LIST[8].getEdge("Bhide", "Priyanshu", 25);
    EDGE_LIST[9].getEdge("Madhu", "Kanak", 48);
    EDGE_LIST[10].getEdge("Bhide", "Ashish", 13);
    EDGE_LIST[11].getEdge("Bhide", "Kanak", 37);

    // we can do without constructor also,
    // Edges EDGE_LIST[v * (v - 1)];
    // EDGE_LIST[0].Ver1 = "Priyanshu";
    // EDGE_LIST[0].Ver2 = "Rakesh";
    // EDGE_LIST[0].W = 40;
    // similarly for other edges

    return 0;
}


// FOR DIRECTED GRAPH : store the start and end vertex
// struct Edges{
//     string startVer;
//     string endVer;
//     int Weight;
// };