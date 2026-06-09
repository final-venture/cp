#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

/*
A spy will pick up a car before returning it.

A spy will always return a car they picked up.

A spy can use at most one car at a time.

Accidents can only happen when a spy is using a car.
*/

// return car before pickup                     = returning when picked == false
// two pick ups in a row                        = picking when picked == true
// accidents happening when not using a car     = accidents when picked == false
// not returning a picked up car                = picked == true AFTER ALL EVENTS

void solve()
{
    int n, m;
    cin >> n >> m;
    unordered_map<string, tuple<int, int, int>> carData;

    // lsb is picked or not, msb is inconsistency
    unordered_map<string, int> personData;

    unordered_map<string, string> personCar;
    unordered_map<string, int> personBill;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        // price, pickup cost, cost per kilometer driven
        int p, q, k;
        cin >> p >> q >> k;
        carData[s] = {p, q, k};
    }

    for (int i = 0; i < m; ++i) {
        // time of event, name of spy, type of event
        int t;
        string S;
        char e;
        cin >> t >> S >> e;
        personBill[S];
        if (e == 'p') {
            // pickup
            string C;
            cin >> C;
            if (personData[S] & 1) {
                // picking when picked
                personData[S] |= (1 << 1);
            }
            else {
                personData[S] |= 1;
                personBill[S] += get<1>(carData[C]);
                personCar[S] = C;
            }
        }
        else if (e == 'r') {
            int d;
            cin >> d;
            string& C = personCar[S];
            if (!(personData[S] & 1)) {
                // returning when not picked
                personData[S] |= (1 << 1);
            }
            else {
                personData[S] &= (1 << 1);
                personBill[S] += (get<2>(carData[C]) * d);
            }
        }
        else if (e == 'a') {
            int s;
            cin >> s;
            string& C = personCar[S];
            if (!(personData[S] & 1)) {
                // accidents when not picked
                personData[S] |= (1 << 1);
            }
            else {
                personBill[S] += ( (s * get<0>(carData[C]) + 99) / 100 );
            }
        }
    }

    vector<pair<string, int>> ret;
    for (auto& [name, val] : personBill) {
        if ((personData[name] & 1) || (personData[name] & (1 << 1))) {
            ret.push_back({name, -1});
        }
        else {
            ret.push_back({name, val});
        }
    }
    sort(ret.begin(), ret.end());

    for (auto& [name, val] : ret) {
        cout << name << ' ';
        if (val == -1) {
            cout << "INCONSISTENT";
        }
        else {
            cout << val;
        }
        cout << '\n';
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
