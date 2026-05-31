#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXSZ = 4000;

void solve()
{
    int V, E, Q;
    cin >> V >> E >> Q;
    int sz = V;
    bool isComp = false, isTrans = false;

    // is the graph simple?
    vector<vector<bool>> adj(MAXSZ + 5, vector<bool>(MAXSZ + 5, false));
    for (int i = 0; i < E; ++i) {
        int X, Y;
        cin >> X >> Y;
        adj[X][Y] = 1;
    }

    // for (int u = 0; u < sz; ++u) {
    //     cout << u << ": ";
    //     for (auto v : adj[u]) {
    //         cout << v << ", ";
    //     }
    //     cout << '\n';
    // }

    while (Q--) {
        int cmd;
        cin >> cmd;
        switch (cmd) {
            case 1: {
                if (isComp) {
                    for (int i = 0; i < sz; ++i) {
                        adj[sz][i] = 1;
                        adj[i][sz] = 1;
                    }
                }
                ++sz;
                break;
            }
            case 2: {
                int X, Y;
                cin >> X >> Y;
                if (isTrans) {
                    swap(X, Y);
                }
                if (isComp) {
                    adj[X][Y] = 0;
                }
                else {
                    adj[X][Y] = 1;
                }
                break;
            }
            case 3: {
                int X;
                cin >> X;
                if (isComp) {
                    for (int i = 0; i < sz; ++i) {
                        if (i != X) {
                            adj[X][i] = 1;
                            adj[i][X] = 1;
                        }
                    }
                }
                else {
                    for (int i = 0; i < sz; ++i) {
                        adj[X][i] = 0;
                    }
                    for (int i = 0; i < sz; ++i) {
                        adj[i][X] = 0;
                    }
                }
                break;
            }
            case 4: {
                int X, Y;
                cin >> X >> Y;
                if (isTrans) {
                    swap(X, Y);
                }
                if (isComp) {
                    adj[X][Y] = 1;
                }
                else {
                    adj[X][Y] = 0;
                }
                break;
            }
            case 5: {
                isTrans = !isTrans;
                break;
            }
            case 6: {
                isComp = !isComp;
                break;
            }
            default: {
                break;
            }
        }

        // for (int u = 0; u < sz; ++u) {
        //     cout << u << ": ";
        //     for (auto v : adj[u]) {
        //         cout << v << ", ";
        //     }
        //     cout << '\n';
        // }
    }

    cout << sz << '\n';
    vector<vector<int>> newAdj(sz);
    for (int u = 0; u < sz; ++u) {
        for (int v = 0; v < sz; ++v) {
            if (u == v) {
                continue;
            }

            if (isComp && !adj[u][v] == 1) {
                int U = u, V = v;
                if (isTrans) {
                    swap(U, V);
                }
                newAdj[U].push_back(V);
            }
            else if (!isComp && adj[u][v] == 1) {
                int U = u, V = v;
                if (isTrans) {
                    swap(U, V);
                }
                newAdj[U].push_back(V);
            }
        }
    }
    for (int i = 0; i < sz; ++i) {
        sort(newAdj[i].begin(), newAdj[i].end());
    }

    // for (int u = 0; u < sz; ++u) {
    //     cout << u << ": ";
    //     for (auto v : newAdj[u]) {
    //         cout << v << ", ";
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < sz; ++i) {
        int outdeg = newAdj[i].size();
        long long po7 = 1;
        long long hash = 0;
        for (auto v : newAdj[i]) {
            hash += po7 * v;
            hash %= MOD;
            po7 *= 7;
            po7 %= MOD;
        }
        cout << outdeg << ' ' << hash << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
