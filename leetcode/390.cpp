class Solution
{
public:
    int lastRemaining(int n)
    {
        int st = 1;
        int step = 1;
        int cnt = n;
        while (cnt > 1)
        {
            // cout << st << ' ' << step << ' ' << cnt << '\n';
            int lst = st + step * (cnt - 1);
            st = (cnt & 1) ? lst - step : lst;
            step *= -2;
            cnt /= 2;
        }
        return st;
    }
};