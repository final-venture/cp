#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

int n;
int known;
int num;

inline bool IK(int i) {
    return ((known >> i) & 1);
}
inline bool IS(int i) {
    return ((num >> i) & 1);
}
inline void S(int i, int& numm) {
    numm |= (1 << i);
}
inline void US(int i, int& numm) {
    numm &= ~(1 << i);
}

void solve()
{
    known = 0;
    num = 0;
    for (int it = 0; it < n; ++it) {
        string cmd;
        int i;
        cin >> cmd >> i;
        if (cmd[0] == 'C') {
            S(i, known);
            US(i, num);
        }
        else if (cmd[0] == 'S') {
            S(i, known);
            S(i, num);
        }
        else if (cmd[0] == 'O') {
            int j;
            cin >> j;
            // if we just know one of bit i or bit j is S, then we can know the answer.
            // only case when i changes is when i'th bit is 0 and j'th bit is 1
            if (IK(j) && IK(i)) {
                if (IS(i) || IS(j)) {
                    S(i, num);
                }
                else {
                    US(i, num);
                }
            }
            else if (IK(j)) {
                if (IS(j)) {
                    S(i, known);
                    S(i, num);
                }
            }
            else if (IK(i)) {
                if (!IS(i)) {
                    US(i, known);
                }
            }
        }
        else if (cmd[0] == 'A') {
            int j;
            cin >> j;
            // if we know one of them is S to 0 then both are zero
            if (IK(j) && IK(i)) {
                if (IS(i) && IS(j)) {
                    S(i, num);
                }
                else {
                    US(i, num);
                }
            }
            else if (IK(j)) {
                if (!IS(j)) {
                    S(i, known);
                    US(i, num);
                }
            }
            else if (IK(i)) {
                if (IS(i)) {
                    US(i, known);
                }
            }
        }
    }

    vector<char> ret;
    for (int i = 0; i < 32; ++i) {
        if ((known >> i) & 1) {
            int bit = (num >> i) & 1;
            ret.push_back(bit + '0');
        }
        else {
            ret.push_back('?');
        }
    }

    reverse(ret.begin(), ret.end());
    for (auto x : ret) {
        cout << x;
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        solve();
    }
    return 0;
}
