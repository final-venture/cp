#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

#define LOCAL

void init()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n, m, k;
string start;
string finish;
vector<string> words;
vector<vector<int>> diff;
vector<vector<int>> dist(105, vector<int>(1000));
int si;
int ei;

int getDiff(string& s1, string& s2)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cnt ++ (s1[i] != s2[i]);
    }
    return cnt;
}

void solve()
{

    cin >> n >> m >> k;
    cin >> start;
    cin >> finish;
    for (int i = 0; i < m; ++i)
    {
        string x;
        cin >> x;
        if (x == start) si = i;
        if (x == end) ei = i;
        words.push_back(x);
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            diff[i][j]  = getDiff(words[i], words[j]);
        }
    }
    priority_queue < pair<int, vector<int>>, vector<pair<int, vector<int>>, greater<>> pq;
    pq.push({0, {si, k}});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int word = pq.top().second[0];
        int remaining = pq.top().second[1];
        pq.pop();

        if (word == ei)
        {
            cout << d << '\n';
            return;
        }

        for (int i = 0; i < m; ++i)
        {

        }
    }
}

signed main()
{
    init();
#ifdef LOCAL
    int t;
    cin >> t;
    while (t--)
#endif
        solve();
    return 0;
}
