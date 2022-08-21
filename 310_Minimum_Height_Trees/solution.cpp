#include "header.h"
#include <unordered_set>

namespace
{
    int maxHeightOfTree(int root, vector<vector<int>>& graph, unordered_set<int>& visited);
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
{
    int min_height = INT_MAX;
    vector<int> node_height(n, 0);

    vector<vector<int>>graph(n, vector<int>());
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    for (int i = 0; i < n; i++)
    {
        unordered_set<int> visited;
        visited.insert(i);
        node_height[i] = maxHeightOfTree(i, graph, visited);;
        min_height = min(min_height, node_height[i]);
    }

    vector<int> results;
    for (int i = 0; i < n; i++)
    {
        if (node_height[i] == min_height)
        {
            results.push_back(i);
        }
    }
    return results;
}

namespace
{
    int maxHeightOfTree(int root, vector<vector<int>>& graph, unordered_set<int>& visited)
    {
        int maxHeight = 0;
        for (int i = 0; i < graph[root].size(); i++)
        {
            if (visited.find(graph[root][i]) == visited.end())
            {
                visited.insert(graph[root][i]);
                maxHeight = max(maxHeight, maxHeightOfTree(graph[root][i], graph, visited));
            }
        }
        return maxHeight + 1;
    }
}