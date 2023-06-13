#include <bits/stdc++.h>
bool isPossible(int node, int col, unordered_map<int, list<int>> &adj, vector<int> &colors)
{
    for (auto &next : adj[node])
    {
        if (colors[next] == col)
        {
            return false;
        }
    }
    return true;
}
bool solve(int node, int m, unordered_map<int, list<int>> &adj, vector<int> &colors)
{
    // base case
    if (node == colors.size())
        return true;

    if (colors[node])
        return false;

    // try out all possible ways to color current node, then call for next node
    for (int col = 1; col <= m; col++)
    {
        if (isPossible(node, col, adj, colors))
        {
            colors[node] = col;
            // call for next nodes
            if (solve(node + 1, m, adj, colors))
                return true;
            colors[node] = 0;
        }
    }

    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<int> colors(n, 0);
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int len = 0;
    bool ans = solve(0, m, adj, colors);
    if (ans)
        return "YES";
    return "NO";
}