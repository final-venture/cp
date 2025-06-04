class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> sfxmin(n);
        vector<int> pfxmax(n);
        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
            {
                pfxmax[i] = arr[i];
                continue;
            }
            pfxmax[i] = max(pfxmax[i - 1], arr[i]);
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (i == n - 1)
            {
                sfxmin[i] = arr[i];
                continue;
            }
            sfxmin[i] = min(sfxmin[i + 1], arr[i]);
        }
        // for (int x : pfxmax) cout << x << ' ';
        // cout << '\n';
        // for (int x : sfxmin) cout << x << ' ';
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i == 0 || pfxmax[i - 1] < sfxmin[i]) ++cnt;
        }
        return cnt;
    }
};
