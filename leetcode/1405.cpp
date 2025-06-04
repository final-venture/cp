class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});
        string res;

        while (!pq.empty())
        {
            auto [ccount1, cchar1] = pq.top();
            pq.pop();
            if (res.size() >= 2 && res.back() == cchar1 && res[res.size() - 2] == cchar1)
            {
                if (pq.empty())
                    break;
                auto [ccount2, cchar2] = pq.top();
                pq.pop();
                res += cchar2;
                ccount2--;
                if (ccount2)
                {
                    pq.push({ccount2, cchar2});
                }
                pq.push({ccount1, cchar1});
            }
            else
            {
                res += cchar1;
                ccount1--;
                if (ccount1)
                {
                    pq.push({ccount1, cchar1});
                }
            }
        }
        return res;
    }
};
