// Brute force factorisation - Approach: https://leetcode.com/problems/count-connected-components-in-lcm-graph/solutions/6123172/c-dsu-factorization/
class UF
{
public:
    vector<int> par;
    vector<int> rank;
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
        else if (rank[p2] > rank[p1])
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
    int countComponents(vector<int>& nums, int threshold) {
        int add = 0;
        sort(nums.begin(), nums.end());
        while (!nums.empty() && nums.back() > threshold)
        {
            nums.pop_back();
            ++add;
        }
        if (nums.empty()) return add;
        int n = nums.size();
        UF dsu(n);
        unordered_map<int, int> fct2min;
        auto tryUnionn = [&] (int i, int fct)
        {
            if (fct2min.find(fct) != fct2min.end())
            {
                int other = fct2min[fct];
                if (lcm(nums[i], nums[other]) <= threshold)
                {
                    dsu.unionn(i, other);
                }
            }
            else
            {
                fct2min[fct] = i;
            }
        };

        for (int i = 0; i < n; ++i)
        {
            for (int fct = 1; fct * fct <= nums[i]; ++fct)
            {
                if (nums[i] % fct == 0)
                {
                    tryUnionn(i, fct);
                    tryUnionn(i, nums[i] / fct);
                }
            }
        }

        unordered_set<int> resSet;
        for (int i = 0; i < n; ++i)
        {
            resSet.insert(dsu.find(i));
        }
        return resSet.size() + add;
    }
};

// Sieve precomputation factorisation - runs slower lol
class UF
{
public:
    vector<int> par;
    vector<int> rank;
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
        else if (rank[p2] > rank[p1])
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
    int countComponents(vector<int>& nums, int threshold) {
        int add = 0;
        sort(nums.begin(), nums.end());
        while (!nums.empty() && nums.back() > threshold)
        {
            nums.pop_back();
            ++add;
        }
        if (nums.empty()) return add;

        int maxx = nums.back();
        int n = nums.size();

        UF dsu(n);
        unordered_map<int, int> fct2min;
        auto tryUnionn = [&] (int i, int fct)
        {
            if (fct2min.find(fct) != fct2min.end())
            {
                int other = fct2min[fct];
                if (lcm(nums[i], nums[other]) <= threshold)
                {
                    dsu.unionn(i, other);
                }
            }
            else
            {
                fct2min[fct] = i;
            }
        };

        vector<vector<int>> fcts(maxx + 1);
        for (int i = 1; i * i < maxx + 1; ++i)
        {
            for (int j = i; j < maxx + 1; j += i)
            {
                fcts[j].push_back(i);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int fct : fcts[nums[i]])
            {
                tryUnionn(i, fct);
                tryUnionn(i, nums[i] / fct);
            }
        }

        unordered_set<int> resSet;
        for (int i = 0; i < n; ++i)
        {
            resSet.insert(dsu.find(i));
        }
        return resSet.size() + add;
    }
};
