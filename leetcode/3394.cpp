class Solution {
public:
    bool merge(vector<pair<int, int>>& a)
    {
        vector<pair<int, int>> cand;
        cand.push_back(a[0]);
        int n = a.size();
        for (int i = 1; i < n; ++i)
        {
            if (a[i].first < cand.back().second)
            {
                cand.back().second = max(a[i].second, cand.back().second);
            }
            else
            {
                cand.push_back(a[i]);
            }
        }
        // for (auto [a, b] : cand) cout << a << ' ' << b << '\n';
        return (cand.size() >= 3) ? true : false;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int nn = rectangles.size();
        vector<pair<int, int>> h(nn);
        vector<pair<int, int>> v(nn);
        for (int i = 0; i < nn; ++i)
        {
            h[i] = {rectangles[i][0], rectangles[i][2]};
            v[i] = {rectangles[i][1], rectangles[i][3]};
        }
        // for (auto [s, e] : h) cout << s << ' ' << e << ' ';
        sort(h.begin(), h.end()); sort(v.begin(), v.end());
        return (merge(h) || merge(v));
    }
};
