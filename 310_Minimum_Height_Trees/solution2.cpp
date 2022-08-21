#include "header.h"
#include <unordered_set>

vector<int> findMinHeightTrees2(int n, vector<vector<int>>& edges)
{
    if(n == 1)
    {
        return vector<int>(1, 0);
    }

    vector<unordered_set<int>>graph(n, unordered_set<int>());
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].insert(edges[i][1]);
        graph[edges[i][1]].insert(edges[i][0]);
    }

    vector<int> leves;
    for (int i = 0; i < n; i++)
    {
        if (graph[i].size() == 1)
        {
            leves.push_back(i);
        }
    }

    int count = n;
    while(count > 2)
    {
        vector<int> new_leves;
        for (int j = 0; j < leves.size(); j++)
        {
            int k = *(graph[leves[j]].begin());
            graph[k].erase(leves[j]);
            if (graph[k].size() == 1)
            {
                new_leves.push_back(k);
            }

        }
        count -= leves.size();
        leves = new_leves;
    }

    return leves;
}
