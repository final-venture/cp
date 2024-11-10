// Brute Force
class Solution
{
private:
    int n;
    unordered_map<string, vector<string>> adj;
    vector<string> res{"JFK"};

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        this->n = tickets.size();
        sort(tickets.begin(), tickets.end());
        for (auto &ticket : tickets)
        {
            adj[ticket[0]].push_back(ticket[1]);
        }
        dfs("JFK");
        return res;
    }
    int dfs(string node)
    {
        if (res.size() == n + 1)
            return true;
        if (adj[node].empty())
            return false;
        vector<string> copy = adj[node];
        for (int i = 0; i < copy.size(); ++i)
        {
            string x = copy[i];
            adj[node].erase(adj[node].begin() + i);
            res.push_back(x);
            if (dfs(x))
                return true;
            res.pop_back();
            adj[node].insert(adj[node].begin() + i, x);
        }
        return false;
    }
};

// Hierholzer's Algorithm
class Solution
{
private:
    unordered_map<string, vector<string>> adj;
    vector<string> res{};

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        sort(tickets.rbegin(), tickets.rend());
        for (auto &ticket : tickets)
        {
            adj[ticket[0]].push_back(ticket[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end()) return res;
    }

    void dfs(string node)
    {
        while (!adj[node].empty())
        {
            string x = adj[node].back();
            adj[node].pop_back();
            dfs(x);
        }
        res.push_back(node);
        return;
    }
};
