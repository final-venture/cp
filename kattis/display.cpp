#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

std::vector<std::vector<std::string>> digits = {
    // 0 (Index 0)
    {
        "+---+",
        "|   |",
        "|   |",
        "+   +",
        "|   |",
        "|   |",
        "+---+"
    },
    // 1 (Index 1)
    {
        "    +",
        "    |",
        "    |",
        "    +",
        "    |",
        "    |",
        "    +"
    },
    // 2 (Index 2)
    {
        "+---+",
        "    |",
        "    |",
        "+---+",
        "|    ",
        "|    ",
        "+---+"
    },
    // 3 (Index 3)
    {
        "+---+",
        "    |",
        "    |",
        "+---+",
        "    |",
        "    |",
        "+---+"
    },
    // 4 (Index 4)
    {
        "+   +",
        "|   |",
        "|   |",
        "+---+",
        "    |",
        "    |",
        "    +"
    },
    // 5 (Index 5)
    {
        "+---+",
        "|    ",
        "|    ",
        "+---+",
        "    |",
        "    |",
        "+---+"
    },
    // 6 (Index 6)
    {
        "+---+",
        "|    ",
        "|    ",
        "+---+",
        "|   |",
        "|   |",
        "+---+"
    },
    // 7 (Index 7)
    {
        "+---+",
        "    |",
        "    |",
        "    +",
        "    |",
        "    |",
        "    +"
    },
    // 8 (Index 8)
    {
        "+---+",
        "|   |",
        "|   |",
        "+---+",
        "|   |",
        "|   |",
        "+---+"
    },
    // 9 (Index 9)
    {
        "+---+",
        "|   |",
        "|   |",
        "+---+",
        "    |",
        "    |",
        "+---+"
    },
    // Colon ':' (Index 10)
    {
        " ",
        " ",
        "o",
        " ",
        "o",
        " ",
        " "
    }
};

string s;

void solve()
{
    vector<int> toPrint(5);
    for (int i = 0; i < 5; ++i) {
        if (i == 2) {
            toPrint[i] = 10;
        }
        else {
            toPrint[i] = s[i] - '0';
        }
    }

    for (int j = 0; j < 7; ++j) {
        for (int i = 0; i < 5; ++i) {
            if (i != 0) {
                cout << "  ";
            }
            cout << digits[toPrint[i]][j];
        }
        cout << "\n";
    }
    cout << "\n\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> s;
        if (s == "end") {
            break;
        }
        solve();
    }
    cout << "end" << '\n';
    return 0;
}
