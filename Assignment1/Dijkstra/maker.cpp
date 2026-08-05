#include<bits/stdc++.h>

using namespace std;

int main(){

    int vertices = 100000;
    int maxOutDegree = 22;

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> weightDist(1,100);
    uniform_int_distribution<int> degreeDist(0,maxOutDegree);
    uniform_int_distribution<int> vertexDist(0,vertices-1);

    ofstream fout("graph_test_05.txt");

    vector<vector<pair<int,int>>> graph;

    int edges=0;

    for(int i=0;i<vertices;i++){

        int outDegree = degreeDist(gen);

        unordered_set<int> used;

        vector<pair<int,int>> adj;

        while(adj.size()<outDegree){

            int neighbor = vertexDist(gen);

            if(neighbor==i)
                continue;

            if(used.count(neighbor))
                continue;

            used.insert(neighbor);

            int weight = weightDist(gen);

            adj.push_back({neighbor,weight});
        }

        graph.push_back(adj);
        edges += outDegree;
    }

    fout<<vertices<<" "<<edges<<endl;

    for(int i=0;i<vertices;i++){

        fout<<i<<" "<<graph[i].size();

        for(int j=0;j<graph[i].size();j++){

            fout<<" "<<graph[i][j].first<<" "<<graph[i][j].second;
        }

        fout<<endl;
    }

    fout.close();
    return 0;
}