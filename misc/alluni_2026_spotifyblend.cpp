#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, k;
    cin >> n >> k;

    // val, songName, (2 = both, 1 = A, 0 = B)
    unordered_map<string, int> songToValueA, songToValueB;
    vector<tuple<int, string, int>> song;
    for (int i = 0; i < 2 * k; ++i) {
        int val;
        string songName;
        cin >> songName >> val;
        if (i >= k) {
            songToValueB[songName] = val;
        }
        else {
            songToValueA[songName] = val;
        }
    }

    for (auto& [songName, val] : songToValueA) {
        if (songToValueB.find(songName) != songToValueB.end() && songToValueB[songName] == val) {
            song.push_back({val * 2, songName, 2});
        }
        else if (val > songToValueB[songName] || songToValueB.find(songName) == songToValueB.end()){
            song.push_back({val + songToValueB[songName], songName, 1});
        }
    }
    for (auto& [songName, val] : songToValueB) {
        if (val > songToValueA[songName] || songToValueA.find(songName) == songToValueA.end()) {
            song.push_back({val + songToValueA[songName], songName, 0});
        }
    }

    sort(song.begin(), song.end(), greater<>());
    int aLeft = n/2;
    int bLeft = n/2;
    int songsLeft = n;
    int idx = 0;
    int sz = song.size();

    vector<pair<int, string>> equal;
    vector<pair<string, char>> ret;
    while (idx < sz && songsLeft > 0 && aLeft > 0 && bLeft > 0) {
        auto& [val, songName, flag] = song[idx];
        if (flag == 2) {
            // both
            --songsLeft;
            equal.push_back({val, songName});
        }
        else if (flag == 1) {
            // A
            --aLeft;
            --songsLeft;
            ret.push_back({songName, 'A'});
        }
        else if (flag == 0) {
            // B
            --bLeft;
            --songsLeft;
            ret.push_back({songName, 'B'});
        }
        ++idx;
    }

    while (idx < sz && songsLeft > 0 && aLeft > 0) {
        auto& [val, songName, flag] = song[idx];
        if (flag != 0) {
            ret.push_back({songName, 'A'});
            --aLeft;
            --songsLeft;
        }
        ++idx;
    }
    while (idx < sz && songsLeft > 0 && bLeft > 0) {
        auto& [val, songName, flag] = song[idx];
        if (flag != 1) {
            ret.push_back({songName, 'B'});
            --bLeft;
            --songsLeft;
        }
        ++idx;
    }

    for (auto& [val, songName] : equal) {
        if (aLeft > 0) {
            --aLeft;
            ret.push_back({songName, 'A'});
        }
        else if (bLeft > 0) {
            --bLeft;
            ret.push_back({songName, 'B'});
        }
    }

    if (ret.size() == n) {
        for (auto& [songName, c] : ret) {
            cout << songName << ' ' << c << '\n';
        }
    }
    else {
        cout << -1 << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
