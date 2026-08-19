#include<bits/stdc++.h>
#include "maxflow.h"
#include "../../shared/CSR/csr.h"  

using namespace std;


struct FlowEdge{
    int to, cap, flow;
};

vector<FlowEdge> edgeList;
vector<vector<int>> adjList;  
vector<int> level, iter_;
int V_global;

void addEdge(int u, int v, int cap){
    adjList[u].push_back((int)edgeList.size());
    edgeList.push_back({v, cap, 0});
    adjList[v].push_back((int)edgeList.size());
    edgeList.push_back({u, 0, 0});   
}

bool bfsLevelGraph(int s, int t){
    level.assign(V_global, -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int id : adjList[u]){
            if(edgeList[id].cap - edgeList[id].flow > 0 && level[edgeList[id].to] < 0){
                level[edgeList[id].to] = level[u] + 1;
                q.push(edgeList[id].to);
            }
        }
    }
    return level[t] >= 0;
}

int dfsBlockingFlow(int u, int t, int pushed){
    if(u == t || pushed == 0) return pushed;
    for(int &cid = iter_[u]; cid < (int)adjList[u].size(); cid++){
        int id = adjList[u][cid];
        int v  = edgeList[id].to;
        if(level[v] != level[u] + 1 || edgeList[id].cap - edgeList[id].flow <= 0) continue;
        int tr = dfsBlockingFlow(v, t, min(pushed, edgeList[id].cap - edgeList[id].flow));
        if(tr > 0){
            edgeList[id].flow   += tr;
            edgeList[id ^ 1].flow -= tr;
            return tr;
        }
    }
    return 0;
}

long long dinicMaxflow(int s, int t){
    long long totalFlow = 0;
    while(bfsLevelGraph(s, t)){
        iter_.assign(V_global, 0);
        int pushed;
        while((pushed = dfsBlockingFlow(s, t, INT_MAX)) > 0){
            totalFlow += pushed;
        }
    }
    return totalFlow;
}

struct FileMeta{
    bool ok = false;
    int V = -1, E = -1, source = -1, sink = -1;
    string error;
};

FileMeta readSourceSinkMeta(const string &fileName){
    FileMeta meta;
    ifstream fin(fileName);
    if(!fin){
        meta.error = "File not found: " + fileName;
        return meta;
    }

    if(!(fin >> meta.V >> meta.E)){
        meta.error = "Malformed header (expected 'V E')";
        return meta;
    }
    if(meta.V <= 0){
        meta.error = "Invalid vertex count";
        return meta;
    }

    for(int i = 0; i < meta.V; i++){
        int vertex, outDegree;
        if(!(fin >> vertex >> outDegree)){
            meta.error = "Malformed adjacency list";
            return meta;
        }
        for(int j = 0; j < outDegree; j++){
            int neighbor, capacity;
            if(!(fin >> neighbor >> capacity)){
                meta.error = "Malformed adjacency entry";
                return meta;
            }
        }
    }

    string tag;
    if(!(fin >> tag >> meta.source) || tag != "SOURCE"){
        meta.error = "Missing/invalid SOURCE line";
        return meta;
    }
    if(!(fin >> tag >> meta.sink) || tag != "SINK"){
        meta.error = "Missing/invalid SINK line";
        return meta;
    }

    if(meta.source < 0 || meta.source >= meta.V || meta.sink < 0 || meta.sink >= meta.V){
        meta.error = "SOURCE/SINK vertex out of range";
        return meta;
    }
    if(meta.source == meta.sink){
        meta.error = "SOURCE and SINK must be different vertices";
        return meta;
    }

    meta.ok = true;
    return meta;
}


void executeMaxflowMincut(string fileName){
    FileMeta meta = readSourceSinkMeta(fileName);
    string outputFile=fileName.substr(0,fileName.find("."))+"_output.txt";
    ofstream fout(outputFile);
    if(!meta.ok){
        fout << "Invalid Maxflow-Mincut input (" << fileName << "): " << meta.error << endl;
        return;
    }

    executeCSR(fileName, true);

    int V = meta.V;
    int source = meta.source;
    int sink   = meta.sink;

    for(int i = 0; i < POS; i++){
        if(PROPERTY[i] < 0){
            fout << "Invalid Maxflow-Mincut input (" << fileName
                 << "): negative capacity found" << endl;
            return;
        }
    }

    cout << "\nExecuting " << fileName << endl;

    auto startTime = chrono::high_resolution_clock::now();

    V_global = V;
    edgeList.clear();
    adjList.assign(V, {});

    for(int u = 0; u < V; u++){
        for(int idx = OFFSET[u]; idx < OFFSET[u + 1]; idx++){
            int v   = INTERMEDIATE[idx];
            int cap = PROPERTY[idx];
            addEdge(u, v, cap);
        }
    }

    long long maxFlow = dinicMaxflow(source, sink);

    vector<bool> visited(V, false);
    queue<int> q;
    visited[source] = true;
    q.push(source);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int id : adjList[u]){
            if(edgeList[id].cap - edgeList[id].flow > 0 && !visited[edgeList[id].to]){
                visited[edgeList[id].to] = true;
                q.push(edgeList[id].to);
            }
        }
    }

    long long cutCapacity = 0;
    vector<pair<int,int>> cutEdgeEndpoints;
    vector<int> cutEdgeCap;
    for(int u = 0; u < V; u++){
        if(!visited[u]) continue;
        for(int id : adjList[u]){
            if(id % 2 != 0) continue;             
            int v = edgeList[id].to;
            int origCap = edgeList[id].cap;
            if(origCap > 0 && !visited[v]){
                cutCapacity += origCap;
                cutEdgeEndpoints.push_back({u, v});
                cutEdgeCap.push_back(origCap);
            }
        }
    }

    auto endTime = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration<double, milli>(endTime - startTime);

    fout << "Algorithm: Maxflow-Mincut" << endl;
    fout << "Source: " << source << endl;
    fout << "Sink: " << sink << endl;
    fout << "Maximum flow: " << maxFlow << endl;
    fout << "Minimum cut capacity: " << cutCapacity << endl;

    fout << "Source side:";
    for(int u = 0; u < V; u++) if(visited[u]) fout << " " << u;
    fout << endl;

    fout << "Sink side:";
    for(int u = 0; u < V; u++) if(!visited[u]) fout << " " << u;
    fout << endl;

    fout << "Cut edges:" << endl;
    for(size_t i = 0; i < cutEdgeEndpoints.size(); i++){
        fout << cutEdgeEndpoints[i].first << " " << cutEdgeEndpoints[i].second
             << " " << cutEdgeCap[i] << endl;
    }

    fout << "Execution time: " << elapsed.count() << " ms" << endl;

    fout.close();
    cout << "Algorithm: Maxflow-Mincut" << endl;
    cout << "Source: " << source << endl;
    cout << "Sink: " << sink << endl;
    cout << "Maximum flow: " << maxFlow << endl;
    cout << "Minimum cut capacity: " << cutCapacity << endl;

    cout << "Execution time: " << elapsed.count() << " ms" << endl;
}