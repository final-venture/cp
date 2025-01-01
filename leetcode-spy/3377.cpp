// Explicit graph - SLOW
class Solution {
public:
    bool check(int x)
    {
        if (x == 1) return false;
        int fct = 0;
        int y = sqrtl(x);
        for (int i = 2; i <= y; ++i)
        {
            if (x % i == 0) return false;
        }
        return true;
    }
    int minOperations(int n, int m)
    {
        vector<int> primes(10005, 0);
        for (int i = 0; i < 10005; ++i)
        {
            if (check(i)) primes[i] = 1;
        }
        if (primes[n]) return -1;
        vector<vector<int>> adj(10005);
        for (int i = 1; i < 10000; ++i)
        {
            for (int j = 1; j <= i; j *= 10)
            {
                int x = i / j;
                int d = x % 10;
                if (d > 0)
                {
                    int cand = i - d * j + (d - 1) * j;
                    if (!primes[cand]) adj[i].push_back(cand);
                }
                if (d < 9)
                {
                    int cand = i - d * j + (d + 1) * j;
                    if (!primes[cand]) adj[i].push_back(cand);
                }
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dists(10005, 1e6);
        dists[n] = n;
        pq.push({n, n});
        while (!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();
            for (int neiNode : adj[node])
            {
                if (dist + neiNode < dists[neiNode])
                {
                    dists[neiNode] = dist + neiNode;
                    pq.push({dist + neiNode, neiNode});
                }
            }
        }
        return (dists[m] == 1e6) ? -1 : dists[m];
    }
};

// Implicit graph - FAST
class Solution {
public:
    bool check(int x)
    {
        if (x == 1) return false;
        int fct = 0;
        int y = sqrtl(x);
        for (int i = 2; i <= y; ++i)
        {
            if (x % i == 0) return false;
        }
        return true;
    }
    int minOperations(int n, int m)
    {
        // generate primes
        vector<int> primes(10005, 0);
        for (int i = 0; i < 10005; ++i)
        {
            if (check(i)) primes[i] = 1;
        }

        if (primes[n] || primes[m]) return -1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dists(10005, 1e6);
        dists[n] = n;
        pq.push({n, n});
        while (!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();
            for (int i = 1; i <= node; i *= 10)
            {
                int x = node / i;
                int d = x % 10;
                if (d > 0)
                {
                    int cand = node - d * i + (d - 1) * i;
                    int newDist = dist + cand;
                    if (!primes[cand] && newDist < dists[cand])
                    {
                        dists[cand] = newDist;
                        pq.push({newDist, cand});
                    }
                }
                if (d < 9)
                {
                    int cand = node - d * i + (d + 1) * i;
                    int newDist = dist + cand;
                    if (!primes[cand] && newDist < dists[cand])
                    {
                        dists[cand] = newDist;
                        pq.push({newDist, cand});
                    }
                }
            }
        }
        return (dists[m] == 1e6) ? -1 : dists[m];
    }
};
