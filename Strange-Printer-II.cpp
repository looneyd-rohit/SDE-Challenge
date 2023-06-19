class Solution
{
public:
    bool isPrintable(vector<vector<int>> &targetGrid)
    {
        int m = targetGrid.size(), n = targetGrid[0].size();
        unordered_set<int> distinctColors;
        // create the adjacency list for graph
        unordered_map<int, unordered_set<int>> adj;
        vector<int> indegree(61, 0);
        for (int color = 1; color <= 60; color++)
        {
            int min_i = m, min_j = n;
            int max_i = -1, max_j = -1;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (color == targetGrid[i][j])
                    {
                        min_i = min(min_i, i);
                        min_j = min(min_j, j);
                        max_i = max(max_i, i);
                        max_j = max(max_j, j);
                    }
                }
            }

            // create dependencies between colors
            for (int i = min_i; i <= max_i; i++)
            {
                for (int j = min_j; j <= max_j; j++)
                {
                    if (color != targetGrid[i][j])
                    {
                        adj[color].insert(targetGrid[i][j]);
                    }
                }
                distinctColors.insert(color);
            }
        }
        // calculate indegrees
        for (auto &e : adj)
        {
            for (auto &f : e.second)
            {
                indegree[f]++;
            }
        }
        // now try to generate a topological sort, which will give the ordering of the colors
        // if it is possible to order the colors then we can surely color the matrix else we cannot
        int supposedLength = distinctColors.size();
        queue<int> q;
        for (int i = 1; i <= 60; i++)
        {
            if (distinctColors.count(i))
            {
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        vector<int> order;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            order.push_back(f);
            for (auto &next : adj[f])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        return order.size() == supposedLength;
    }
};