#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <random>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <V> <E> <output_file>" << std::endl;
        return 1;
    }

    int V = std::stoi(argv[1]);
    long long E = std::stoll(argv[2]);
    std::string out_file = argv[3];

    long long max_edges = (long long)V * (V - 1) / 2;
    if (E > max_edges) {
        std::cerr << "Error: E is too large for V=" << V 
                  << " (max possible = " << max_edges << ")" << std::endl;
        return 1;
    }

    std::mt19937_64 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, V - 1);

    std::set<std::pair<int, int>> edge_set;
    std::vector<std::vector<int>> adj(V);

    while ((long long)edge_set.size() < E) {
        int a = dist(rng);
        int b = dist(rng);
        if (a == b) continue;
        if (a > b) std::swap(a, b);
        if (edge_set.count({a, b})) continue;
        
        edge_set.insert({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::ofstream fout(out_file);
    fout << V << " " << E << "\n";
    for (int i = 0; i < V; i++) {
        fout << i << " " << adj[i].size();
        for (int nb : adj[i]) {
            fout << " " << nb;
        }
        fout << "\n";
    }
    fout.close();

    std::cout << "Generated: V=" << V << ", E=" << E << " -> " << out_file << std::endl;
    return 0;
}