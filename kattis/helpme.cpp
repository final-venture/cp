#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// white pieces: upper case
// black pieces: lower case
// k, q, r, b, n, p

// The description of a piece consists of a single upper-case letter that denotes the type of the 
// piece (except for pawns, for that this identifier is omitted)

// the piece with the smaller row number must be described before the other one if the pieces are white, 
// and the one with the larger row number must be described first if the pieces are black. 
// If two pieces of the same type appear in the same row, the one with the smaller column letter must appear first.

const int N = 8;
const string order {'K', 'Q', 'R', 'B', 'N', 'P'};

void solve()
{
    vector<pair<char, pair<char, int>>> white;
    vector<pair<char, pair<char, int>>> black;
    
    for (int r = 0; r < 8 * 2 + 1; ++r) {
        for (int c = 0; c < 8 * 4 + 1; ++c) {
            char in;
            cin >> in;

            if (!isalpha(in)) {
                continue;
            }

            char currCol = (c / 4) + 'a';
            int currRow = 8 - ((r / 2) + 1) + 1;

            if (isupper(in)) {
                white.push_back({toupper(in), {currCol, currRow}});
                
            }
            else if (islower(in)) {
                black.push_back({toupper(in), {currCol, currRow}});
            }
        }
    }

    sort(white.begin(), white.end(), [](auto& p1, auto& p2) {
        if (p1.first != p2.first) {
            return order.find(p1.first) < order.find(p2.first);
        }
        else if (p1.second.second != p2.second.second) {
            return p1.second.second < p2.second.second;
        }
        else {
            return p1.second.first < p2.second.first;
        }
    });

    sort(black.begin(), black.end(), [](auto& p1, auto& p2) {
        if (p1.first != p2.first) {
            return order.find(p1.first) < order.find(p2.first);
        }
        else if (p1.second.second != p2.second.second) {
            return p1.second.second > p2.second.second;
        }
        else {
            return p1.second.first < p2.second.first;
        }
    });

    cout << "White: ";
    bool comma = false;
    for (auto& [p, co] : white) {
        auto [c, r] = co;
        if (comma) {
            cout << ',';
        }
        if (p != 'P') {
            cout << p;
        }
        cout << c << r;
        comma = true;
    }
    cout << '\n';

    cout << "Black: ";
    comma = false;
    for (auto& [p, co] : black) {
        auto [c, r] = co;
        if (comma) {
            cout << ',';
        }
        if (p != 'P') {
            cout << p;
        }
        cout << c << r;
        comma = true;
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
