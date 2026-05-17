#include "robots.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> appear;
vector<int> sizes;

bool check(int time)
{
    int n = appear.size();
    priority_queue<int> pq;
    for (int i = 0; i < n - 1; ++i)
    {
        int nn = appear[i].size();
        for (int j = 0; j < nn; ++j)
        {
            pq.push(appear[i][j]);
        }
        int pqsz = pq.size();
        // We no longer have to consider using this robot again because it's too weak for further toys
        for (int j = 0; j < min(time, pqsz); ++j)
        {
            pq.pop();
        }
    }
    for (int j = 0; j < appear[n - 1].size(); ++j)
    {
        pq.push(appear[n - 1][j]);
    }
    for (int i = 0; i < sizes.size(); ++i)
    {
        int pqsz = pq.size();
        for (int j = 0; j < min(pqsz, time); ++j)
        {
            int tsz = pq.top();
            if (tsz >= sizes[i]) break;
            pq.pop();
        }
    }
    if (pq.empty()) return true;
    return false;
}

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[])
{
    sizes.resize(B);
    for (int i = 0; i < B; ++i)
    {
        sizes[i] = Y[i];
    }
    appear.resize(A + 1);
    sort(X, X + A); // weight limit of robots
    sort(sizes.begin(), sizes.end(), greater<int>()); // size limit of robots
    for (int i = 0; i < T; ++i)
    {
        int oversize = 1;
        if (!sizes.empty())
        {
            oversize = (S[i] >= sizes[0]);
        }
        int idx = upper_bound(X, X + A, W[i]) - X;
        int overweight = (idx == A);
        if (oversize && overweight) return -1;
        appear[idx].push_back(S[i]);
    }
    for (int i = 0; i < A + 1; ++i)
    {
        sort(appear[i].begin(), appear[i].end(), greater<int>());
    }
    int l = 1, r = T + 10;
    while (l < r)
    {
        // cout << l << ' ' << r << endl;
        int m = l + (r - l) / 2;
        if (check(m))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}
