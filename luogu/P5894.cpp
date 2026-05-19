#include <bits/stdc++.h>

using namespace std;

// Helper function to simulate the assignment of toys to robots
bool check(int time, const vector<vector<int>>& appear, const vector<int>& sizes) {
    priority_queue<int> pq;
    int a_count = appear.size() - 1; 

    // Step 1: Greedily let weak robots pick up the toys with the largest volumes
    for (int i = 0; i < a_count; ++i) {
        for (int s : appear[i]) {
            pq.push(s);
        }
        int limit = min(time, (int)pq.size());
        for (int j = 0; j < limit; ++j) {
            pq.pop(); // Weak robot processes the item
        }
    }

    // Step 2: Push toys that NO weak robot can carry
    for (int s : appear[a_count]) {
        pq.push(s);
    }

    // Step 3: Let small robots process the remaining toys
    for (int s_limit : sizes) {
        int limit = min(time, (int)pq.size());
        for (int j = 0; j < limit; ++j) {
            // Optimization: If the largest available small robot can't pick up 
            // the largest remaining toy, no other smaller robot can either.
            if (pq.top() >= s_limit) {
                return false; 
            }
            pq.pop();
        }
    }

    // If the queue is empty, all toys were successfully put away
    return pq.empty();
}

int main() {
    // Fast I/O is critical for T = 10^6
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, T;
    if (!(cin >> A >> B >> T)) return 0;

    vector<int> X(A);
    for (int i = 0; i < A; ++i) cin >> X[i];

    vector<int> Y(B);
    for (int i = 0; i < B; ++i) cin >> Y[i];

    // Sort weight limits ascending and volume limits descending
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end(), greater<int>());

    // appear[i] will store the volumes of toys where X[i] is the WEAKEST robot that can lift it.
    vector<vector<int>> appear(A + 1);

    for (int i = 0; i < T; ++i) {
        int w, s;
        cin >> w >> s;

        // Check if the toy is too large for the best small robot
        bool oversize = (B == 0) || (s >= Y[0]);
        
        // Find the weakest robot that can lift this toy (strict inequality required: X[idx] > w)
        int idx = upper_bound(X.begin(), X.end(), w) - X.begin();
        bool overweight = (idx == A);

        // If it can't be carried by the best weak robot OR the best small robot, it's impossible.
        if (oversize && overweight) {
            cout << -1 << "\n";
            return 0; 
        }

        appear[idx].push_back(s);
    }

    // Binary Search for the minimum time
    int l = 1, r = T;
    int ans = -1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m, appear, Y)) {
            ans = m;       // Record valid time
            r = m - 1;     // Try to find a smaller valid time
        } else {
            l = m + 1;     // Increase time allowed
        }
    }

    cout << ans << "\n";
    return 0;
}
