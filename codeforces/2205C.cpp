#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

/*
    5
    4 2 3 3 4
    5 1 2 4 3 1
    2 4 1
    3 3 3 1
    5 4 3 2 2 2
*/

//    (1)       (2)       (3)       (5)       (4)
// [4,3,3,2] [1,3,4,2] [1,4,3,2] [1,2,3,4] [1,3,2,4]

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> allPosts(n);
    unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        vector<int> post(l);
        for (int j = 0; j < l; ++j) {
            cin >> post[j];
        }
        reverse(post.begin(), post.end());
        vector<int> processedPost;
        for (int j = 0; j < l; ++j) {
            if (seen.find(post[j]) != seen.end()) {
                continue;
            }
            processedPost.push_back(post[j]);
            seen.insert(post[j]);
        }
        allPosts[i] = processedPost;
        seen.clear();
    }

    // for (auto& v : allPosts) {
    //     for (auto x : v) {
    //         cout << x << ' ';
    //     }
    //     cout << '\n';
    // }

    vector<bool> isPosted(n, false);
    vector<int> ret;
    for (int i = 0; i < n; ++i) {
        int bestPostIdx = 0;
        vector<int> bestValidPost = {200000000};
        for (int j = 0; j < n; ++j) {
            if (isPosted[j]) {
                continue;
            }
            vector<int> validPost;
            for (auto x : allPosts[j]) {
                if (seen.find(x) == seen.end()) {
                    validPost.push_back(x);
                }
            }
            if (validPost < bestValidPost) {
                bestValidPost = validPost;
                bestPostIdx = j;
            }
        }
        for (auto x : bestValidPost) {
            ret.push_back(x);
            seen.insert(x);
        }
        isPosted[bestPostIdx] = true;
    }
    for (auto x : ret) {
        cout << x << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}