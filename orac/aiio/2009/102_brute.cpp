#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void brute(int n, int k, int p)
{
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1);
    int should_remove = 0;
    queue<int> lst_removed;
    while (!nums.empty())
    {
        vector<int> survivors;
        for (int x : nums)
        {
            if (should_remove % k == 0)
            {
                lst_removed.push(x);
                if (lst_removed.size() > p)
                {
                    lst_removed.pop();
                }
            }
            else
            {
                survivors.push_back(x);
            }
            ++should_remove;
        }
        nums = survivors;
    }

    cout << "N=" << n << ", K=" << k << ": ";
    while (!lst_removed.empty())
    {
        cout << lst_removed.front() << ' ';
        lst_removed.pop();
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 100; ++i)
    {
        brute(i, 4, 1);
    }
    return 0;
}
