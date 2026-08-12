#include <bits/stdc++.h>
#include "../src/connected_components.h"

using namespace std;

int main()
{
    int choice;

    cout << "1. Run cc_10.txt\n";
    cout << "2. Run cc_100.txt\n";
    cout << "3. Run cc_10000.txt\n";
    cout << "4. Run cc_50000.txt\n";
    cout << "5. Run cc_100000.txt\n";

    cout << "Enter choice: ";
    cin >> choice;

    string fileName;

    switch(choice)
    {
        case 1:
            fileName = "tests/test.txt";
            break;

        case 2:
            fileName = "tests/cc_100.txt";
            break;

        case 3:
            fileName = "tests/cc_10000.txt";
            break;

        case 4:
            fileName = "tests/cc_50000.txt";
            break;

        case 5:
            fileName = "tests/cc_100000.txt";
            break;

        default:
            cout << "Invalid choice\n";
            return 0;
    }

    ifstream fin(fileName);

    if(!fin)
    {
        cout << "Cannot open file: "
             << fileName << "\n";
        return 1;
    }

    int vertices, edges;

    fin >> vertices >> edges;

    vector<vector<int>> graph(vertices);

    // Read adjacency list
    for(int i = 0; i < vertices; i++)
    {
        int vertex;
        int degree;

        fin >> vertex >> degree;

        for(int j = 0; j < degree; j++)
        {
            int neighbor;
            fin >> neighbor;

            graph[vertex].push_back(neighbor);
        }
    }

    fin.close();

    // Algorithm timing only
    auto start = chrono::high_resolution_clock::now();

    ConnectedComponentsResult result =
        connectedComponents(vertices, graph);

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(
            end - start
        ).count();

    // Output
    cout << "Algorithm: Connected Components\n";

    cout << "Number of components: "
         << result.numberOfComponents << "\n";

    cout << "Vertex Component\n";

    for(int i = 0; i < vertices; i++)
    {
        cout << i << " "
             << result.component[i] << "\n";
    }

    cout << "Execution time: "
         << fixed << setprecision(3)
         << executionTime << " ms\n";

    return 0;
}