#include "triangle_counting.h"
#include <algorithm>

static bool has_edge(const CSRGraph &g, int v, int w)
{
    int start = g.row_ptr[v];
    int end = g.row_ptr[v + 1];
    return std::binary_search(g.col_idx.begin() + start, g.col_idx.begin() + end, w);
}

TriangleResult count_triangles(const CSRGraph &g, int V, bool list_triangles)
{
    TriangleResult result;
    long long raw_count = 0;

    for (int u = 0; u < V; u++)
    {
        int start = g.row_ptr[u];
        int end = g.row_ptr[u + 1];

        for (int i = start; i < end; i++)
        {
            for (int j = i + 1; j < end; j++)
            {
                int v = g.col_idx[i];
                int w = g.col_idx[j];

                if (has_edge(g, v, w))
                {
                    raw_count++;

                    if (list_triangles)
                    {
                        std::array<int, 3> tri = {u, v, w};
                        std::sort(tri.begin(), tri.end());
                        result.triangle_list.push_back(tri);
                    }
                }
            }
        }
    }
    result.total_triangles = raw_count / 3;

    if (list_triangles)
    {
        std::sort(result.triangle_list.begin(), result.triangle_list.end());
        result.triangle_list.erase(
            std::unique(result.triangle_list.begin(), result.triangle_list.end()),
            result.triangle_list.end());
    }

    return result;
}