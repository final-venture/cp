// Brute force Prime Factorisation
class UF
{
private:
    vector<int> par;
    vector<int> rank;
public:
    UF(int n)
    {
        par.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
        rank.resize(n, 1);
    }
    int find(int x)
    {
        int p = par[x];
        while (p != par[p])
        {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    void unionn(int x1, int x2)
    {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2) return;
        if (rank[p1] > rank[p2])
        {
            par[p2] = par[p1];
        }
        else if (rank[p1] < rank[p2])
        {
            par[p1] = par[p2];
        }
        else
        {
            par[p1] = par[p2];
            ++rank[p2];
        }
    }
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        int maxx = *max_element(nums.begin(), nums.end());
        UF dsu(maxx + 1);
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        for (int num : nums)
        {
            for (int j = 2; j <= sqrt(num); ++j)
            {
                if (num % j == 0)
                {
                    dsu.unionn(num, j);
                    dsu.unionn(num, num / j);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (dsu.find(nums[i]) != dsu.find(sorted[i])) return false;
        }
        return true;
    }
};

// Sieve Prime Factorisation
class UF
{
private:
    vector<int> par;
    vector<int> rank;
public:
    UF(int n)
    {
        par.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
        rank.resize(n, 1);
    }
    int find(int x)
    {
        int p = par[x];
        while (p != par[p])
        {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    void unionn(int x1, int x2)
    {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2) return;
        if (rank[p1] > rank[p2])
        {
            par[p2] = par[p1];
        }
        else if (rank[p1] < rank[p2])
        {
            par[p1] = par[p2];
        }
        else
        {
            par[p1] = par[p2];
            ++rank[p2];
        }
    }
};

class Solution {
private:
    vector<int> spf;
public:
    void sieve(int n)
    {
        spf.resize(n + 1, -1);
        for (long long i = 2; i < n + 1; ++i)
        {
            if (spf[i] != -1)
                continue;
            spf[i] = i;
            for (long long j = i * i; j < n + 1; j += i)
            {
                if (spf[j] != -1)
                    continue;
                spf[j] = i;
            }
        }
    }
    vector<int> getFact(int x)
    {
        vector<int> ret;
        while (x > 1)
        {
            ret.push_back(spf[x]);
            x /= spf[x];
        }
        return ret;
    }

    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        int maxx = *max_element(nums.begin(), nums.end());
        UF dsu(maxx + 1);
        sieve(maxx);

        for (int num : nums)
        {
            for (int x : getFact(num))
            {
                dsu.unionn(x, num);
            }
        }

        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < n; ++i)
        {
            if (dsu.find(nums[i]) != dsu.find(sorted[i])) return false;
        }
        return true;
    }
};
