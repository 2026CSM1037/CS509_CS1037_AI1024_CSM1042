#include <iostream>
#include <chrono>
#include <algorithm>
#include "graph.h"
#include "csr.h"
#include "triangle_counting.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " triangle_counting <input_file_path>" << std::endl;
        return 1;
    }

    std::string algo = argv[1];
    std::string input_file = argv[2];

    if (algo != "triangle_counting") {
        std::cerr << "Error: this driver only supports 'triangle_counting' right now." << std::endl;
        return 1;
    }

    bool ok = false;
    AdjList graph = read_adjacency_list(input_file, ok);
    if (!ok) {
        return 1;
    }
    CSRGraph g = convert_to_csr(graph);

    for (int i = 0; i < graph.V; i++) {
        std::sort(g.col_idx.begin() + g.row_ptr[i], g.col_idx.begin() + g.row_ptr[i + 1]);
    }
    bool list_triangles = (graph.V <= 100);

    auto start_time = std::chrono::high_resolution_clock::now();
    TriangleResult result = count_triangles(g, graph.V, list_triangles);
    auto end_time = std::chrono::high_resolution_clock::now();

    double elapsed_ms = std::chrono::duration<double, std::milli>(end_time - start_time).count();
    int repeat_count = 1;

    if (elapsed_ms < 5.0) {
        repeat_count = (elapsed_ms > 0.0)
                           ? (int)std::min(100000.0, std::max(100.0, 50.0 / elapsed_ms))
                           : 5000;

        auto rep_start = std::chrono::high_resolution_clock::now();
        for (int r = 0; r < repeat_count; r++) {
            count_triangles(g, graph.V, false);
        }
        auto rep_end = std::chrono::high_resolution_clock::now();

        elapsed_ms = std::chrono::duration<double, std::milli>(rep_end - rep_start).count() / repeat_count;
    }

    std::cout << "Algorithm: Triangle Counting" << std::endl;
    std::cout << "Total triangles: " << result.total_triangles << std::endl;

    if (list_triangles) {
        std::cout << "Triangles found:" << std::endl;
        for (auto &t : result.triangle_list) {
            std::cout << "(" << t[0] << ", " << t[1] << ", " << t[2] << ")" << std::endl;
        }
    }

    std::cout << "Execution time: " << elapsed_ms << " ms";
    if (repeat_count > 1) {
        std::cout << " (averaged over " << repeat_count << " runs)";
    }
    std::cout << std::endl;

    return 0;
}