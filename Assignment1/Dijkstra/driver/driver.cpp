// #include "dijkstra.h"
#include "../src/dijkstra.h"

int main()
{
    // ifstream fin("graph_test_02.txt");

    int choice;
string fileName;

cout << "1. Run Test 01\n";
cout << "2. Run Test 02\n";
cout << "3. Run Test 03\n";
cout << "4. Run Test 04\n";
cout << "5. Run Test 05\n\n";

cout << "Enter Choice : ";
cin >> choice;

switch(choice)
{
    case 1:
        fileName = "../tests/graph_test_01.txt";
        break;

    case 2:
        fileName = "../tests/graph_test_02.txt";
        break;

    case 3:
        fileName = "../tests/graph_test_03.txt";
        break;

    case 4:
        fileName = "../tests/graph_test_04.txt";
        break;

    case 5:
        fileName = "../tests/graph_test_05.txt";
        break;

    default:
        cout << "Invalid Choice\n";
        return 0;
}

ifstream fin(fileName);




    if(!fin)
    {
        cout << "File not found\n";
        return 0;
    }

    int vertices, edges;
    fin >> vertices >> edges;

    map<int, vector<pair<int,int>>> graph;

    for(int i = 0; i < vertices; i++)
    {
        int vertex, outDegree;
        fin >> vertex >> outDegree;

        for(int j = 0; j < outDegree; j++)
        {
            int neighbor, weight;
            fin >> neighbor >> weight;

            graph[vertex].push_back({neighbor, weight});
        }
    }

    int offset[MAX_SIZE];
    int intermediate[MAX_SIZE];
    int property[MAX_SIZE];

    fill(offset, offset + MAX_SIZE, -1);

    int pos = 0;

    for(int i = 0; i < vertices; i++)
    {
        offset[i] = pos;

        for(int j = 0; j < graph[i].size(); j++)
        {
            intermediate[pos] = graph[i][j].first;
            property[pos] = graph[i][j].second;
            pos++;
        }
    }

    offset[vertices] = pos;

    int dist[MAX_SIZE];

    auto start = chrono::high_resolution_clock::now();

    dijkstra(vertices, offset, intermediate, property, dist);

    auto end = chrono::high_resolution_clock::now();

    auto timeTaken =
        chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Algorithm : Dijkstra\n";
    cout << "Source : 0\n\n";

    cout << "Shortest Distance from Source\n";

    for(int i = 0; i < vertices; i++)
    {
        if(dist[i] == INF)
            cout << i << " : INF\n";
        else
            cout << i << " : " << dist[i] << endl;
    }

    cout << "\nDijkstra completed in : "
         << timeTaken.count() << " milliseconds\n";

    return 0;
}