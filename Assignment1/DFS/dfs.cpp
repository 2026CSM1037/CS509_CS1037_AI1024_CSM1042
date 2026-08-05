#include<bits/stdc++.h>

#include "dfs.h"

using namespace std;

#define MAX_SIZE 100000

void printArray(int arr[], int sz, ofstream &fout){
    for(int i=0;i<sz;i++)
        fout<<arr[i]<<" ";
    fout<<endl;
}

void dfsCSR(int node, int offset[], int intermediate[], bool visited[], ofstream &fout){
    visited[node] = true;
    fout<<node<<" ";

    for(int i=offset[node]; i<offset[node+1]; i++) {
        int neighbor = intermediate[i];

        if(!visited[neighbor])
            dfsCSR(neighbor, offset, intermediate, visited, fout);
    }
}

void executeDFS(string fileName){

    ifstream fin(fileName);

    string outputFile=fileName.substr(0,fileName.find("."))+"_output.txt";
    ofstream fout(outputFile);

    if(!fin){
        cout<<"File not found\n";
        return;
    }

    int vertices, edges;
    fin>>vertices>>edges;

    unordered_map<int, vector<int>> graph;

    for(int i=0;i<vertices;i++) {
        int vertex,outDegree;
        fin>>vertex>>outDegree;

        for(int j=0;j<outDegree;j++) {
            int neighbor;
            fin>>neighbor;

            graph[vertex].push_back(neighbor);
        }
    }

    fin.close();

    int offset[MAX_SIZE];
    int intermediate[MAX_SIZE];

    fill(offset,offset+MAX_SIZE,-1);
    fill(intermediate,intermediate+MAX_SIZE,0);

    int pos=0;

    for(int i=0;i<vertices;i++){
        offset[i] = pos;
        for(int j=0;j<graph[i].size();j++){
            intermediate[pos] = graph[i][j];
            pos++;
        }
    }

    offset[vertices]=pos;

    cout<<"\nExecuting "<<fileName<<endl;

    auto blockStart=chrono::high_resolution_clock::now();

    bool visited[MAX_SIZE];
    fill(visited,visited+MAX_SIZE,false);

    fout<<"Algorithm : DFS"<<endl;
    fout<<"Source : 0"<<endl;
    fout<<"Traversal"<<endl;

    for(int i=0;i<vertices;i++){
        if(!visited[i])
            dfsCSR(i,offset,intermediate,visited,fout);
    }

    fout<<endl;

    auto blockEnd=chrono::high_resolution_clock::now();
    auto blockTime=chrono::duration_cast<chrono::milliseconds>(blockEnd-blockStart);

    fout<<"DFS completed in : "<<blockTime.count()<<" milliseconds"<<endl;

    cout<<"DFS completed in : "<<blockTime.count()<<" milliseconds"<<endl;

    fout.close();
}