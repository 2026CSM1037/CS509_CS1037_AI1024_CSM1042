#ifndef TRIANGLE_COUNTING_H
#define TRIANGLE_COUNTING_H

#include "csr.h"
#include <vector>
#include <array>

struct TriangleResult
{
    long long total_triangles;
    std::vector<std::array<int, 3>> triangle_list;
};

TriangleResult count_triangles(const CSRGraph &g, int V, bool list_triangles);

#endif