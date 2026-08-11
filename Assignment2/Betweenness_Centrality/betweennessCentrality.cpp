#include <bits/stdc++.h>
#include "betweennessCentrality.h"

using namespace std;

void readGraph(string fileName,CSRGraph& graph){
    ifstream fin(fileName);

    if(!fin){
        cout<<"File not found: "<<fileName<<endl;
        return;
    }

    int V,E;
    fin>>V>>E;

    vector<vector<int>> adjList(V);

    for(int i=0;i<V;i++){
        int u,degree;
        fin>>u>>degree;

        for(int j=0;j<degree;j++){
            int neighbor;
            fin>>neighbor;
            adjList[u].push_back(neighbor);
        }
    }

    fin.close();

    graph.numVertices=V;
    graph.numEdges=E;

    graph.offset.resize(V+1,0);

    for(int u=0;u<V;u++)
        graph.offset[u+1]=graph.offset[u]+adjList[u].size();

    graph.intermediate.resize(graph.offset[V]);

    for(int u=0;u<V;u++){
        int pos=graph.offset[u];

        for(int j=0;j<adjList[u].size();j++)
            graph.intermediate[pos+j]=adjList[u][j];
    }
}

void brandesBFS(const CSRGraph& graph,int source,vector<double>& centrality){
    int V=graph.numVertices;

    vector<int> distance(V,-1);
    vector<double> sigma(V,0);
    vector<double> dependency(V,0);

    vector<vector<int>> predecessor(V);

    vector<int> queue;
    vector<int> stack;

    queue.reserve(V);
    stack.reserve(V);

    distance[source]=0;
    sigma[source]=1;

    queue.push_back(source);

    int front=0;

    while(front<queue.size()){
        int u=queue[front++];
        stack.push_back(u);

        for(int i=graph.offset[u];i<graph.offset[u+1];i++){
            int v=graph.intermediate[i];

            if(distance[v]==-1){
                distance[v]=distance[u]+1;
                queue.push_back(v);
            }

            if(distance[v]==distance[u]+1){
                sigma[v]+=sigma[u];
                predecessor[v].push_back(u);
            }
        }
    }

    while(!stack.empty()){
        int v=stack.back();
        stack.pop_back();

        for(int p:predecessor[v]){
            dependency[p]+=(sigma[p]/sigma[v])*(1+dependency[v]);
        }

        if(v!=source)
            centrality[v]+=dependency[v];
    }
}

vector<double> calculateBetweennessCentrality(const CSRGraph& graph){
    int V=graph.numVertices;

    vector<double> centrality(V,0);

    for(int source=0;source<V;source++)
        brandesBFS(graph,source,centrality);

    // Graph is undirected, so divide by 2
    for(int i=0;i<V;i++)
        centrality[i]/=2.0;

    return centrality;
}

void printCentrality(const vector<double>& centrality,ostream& out){
    out<<"Vertex Centrality"<<endl;

    for(int i=0;i<centrality.size();i++)
        out<<i<<" "<<fixed<<setprecision(2)<<centrality[i]<<endl;
}

void executeBetweennessCentrality(string fileName){
    CSRGraph graph;

    readGraph(fileName,graph);
    if(graph.numVertices==0)
        return;

    cout<<"\nExecuting "<<fileName<<endl;

    auto start=chrono::high_resolution_clock::now();

    vector<double> centrality=calculateBetweennessCentrality(graph);

    auto end=chrono::high_resolution_clock::now();
    double executionTime=chrono::duration<double,milli>(end-start).count();

    string outputFile=fileName.substr(0,fileName.find("."))+"_output.txt";
    ofstream fout(outputFile);

    if(!fout){
        cout<<"Unable to create output file: "<<outputFile<<endl;
        return;
    }

    cout<<"Algorithm: Betweenness Centrality"<<endl;
    fout<<"Algorithm: Betweenness Centrality"<<endl;

    printCentrality(centrality,fout);

    cout<<"Execution time: "<<executionTime<<" ms"<<endl;
    fout<<"Execution time: "<<executionTime<<" ms"<<endl;

    fout.close();
}