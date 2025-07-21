void dfs(int v, int parent)
{
    up[v][0] = parent; // Direct parent
    depth[v] = (parent == -1) ? 0 : depth[parent] + 1;

    for (int j = 1; j < LOG; j++)
    {
        if (up[v][j - 1] != -1)
            up[v][j] = up[up[v][j - 1]][j - 1]; // Binary lifting
        else
            up[v][j] = -1;
    }

    for (int u : adj[v])
    {
        if (u != parent)
            dfs(u, v);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    // Lift u to the same level as v
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[u][j] != -1 && depth[up[u][j]] >= depth[v])
            u = up[u][j];
    }

    if (u == v)
        return u;

    // Lift both u and v until their ancestors match
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0]; // Parent of u (or v) is LCA
}