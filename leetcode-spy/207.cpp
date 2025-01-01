class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> topo{};
        unordered_map<int, vector<int>> adj;
        vector<int> indeg(numCourses);
        for (auto &x : prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            ++indeg[x[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (!indeg[i])
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            topo.push_back(x);
            for (int node : adj[x])
            {
                if (!--indeg[node])
                    q.push(node);
            }
        }

        return (topo.size() == numCourses);
    }
};
