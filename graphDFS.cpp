// WRITE A C++ PROGRAM TO REPRESENT THE GRAPH USING ADJACENCY MATRIX AND PERFORM DEPTH FIRST SEARCH (DFS).
/*
The program first asks the user to input the number of vertices in the graph.
Then, it asks the user to input the adjacency matrix representing the graph.
The user is then asked to input the start vertex for the depth-first search (DFS) traversal.
The DFS function is then called to perform the traversal.
The DFSUtil function is a recursive utility function that performs the actual traversal.
*/
#include<iostream>
using namespace std;

// function prototype for DFSUtil
void DFSUtil(int **graph, int vertices, int vertex, bool *visited);

// function to perform DFS
void DFS(int **graph, int vertices, int startVertex){
    bool *visited = new bool[vertices];
    for(int i=0; i<vertices; i++){
        visited[i] = false;
    }

    //  perform DFS from the start vertex
    cout<< "DFS Traversal: ";
    DFSUtil(graph, vertices, startVertex, visited);
    cout<<endl;
}

// utility function to perform DFS
void DFSUtil(int **graph, int vertices, int vertex, bool*visited){
    visited[vertex] = true;
    cout<<vertex<<" ";

    for(int i=0; i<vertices; i++){
        if(graph[vertex][i] == 1 && !visited[i]){
            DFSUtil(graph, vertices, i, visited);
        }
    }
}

int main(){
    int vertices;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;

    int **graph = new int*[vertices];
    for(int i=0; i<vertices; i++){
        graph[i] = new int[vertices];
    }

    cout<<"Enter the adjacency matrix (0/1): "<<endl;
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            cin>>graph[i][j];
        }
    }

    int startVertex;
    cout<<"Enter the start vertex for DFS: ";
    cin>>startVertex;

    DFS(graph, vertices, startVertex);

    // deallocate memory
    for(int i=0; i<vertices; i++){
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}