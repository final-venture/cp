#include <bits/stdc++.h>
#define ll long long

using namespace std;



int main() 
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i];
    }

    vector<ll> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) 
    {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    vector<vector<int>> splits(n + 1, vector<int>(k + 1, -1)); 

    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= min(i - 1, k); ++j) 
        { 
            dp[i][j] = LLONG_MIN;
            for (int k = 1; k < i; ++k) 
            {
                ll points = (prefixSum[k]) * (prefixSum[i] - prefixSum[k]);
                ll totalPoints = dp[k][j - 1] + points;
                if (totalPoints >= dp[i][j]) 
                {
                    dp[i][j] = totalPoints;
                    splits[i][j] = k;
                }
            }
        }
    }

    cout << dp[n][k] << '\n';

    vector<int> splitPositions;
    int cur_n = n, cur_k = k;
    while (cur_k > 0) 
    {
        int splitPos = splits[cur_n][cur_k];
        splitPositions.push_back(splitPos);
        cur_n = splitPos;
        cur_k--;
    }

    // Print split positions in reverse order
    for (int i = splitPositions.size() - 1; i >= 0; --i) 
    {
        cout << splitPositions[i] << " ";
    }
    cout << '\n';

    return 0;
}
