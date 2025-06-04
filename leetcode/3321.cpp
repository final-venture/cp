#define ll long long
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<ll> ret;
        int n = nums.size();
        map<ll, ll> n2c;
        for (int i = 0; i < k; ++i)
        {
            ++n2c[nums[i]];
        }
        ll summ = 0;
        set<pair<ll, ll>> s1; // top has the worst ones that is soonest to be kicked out
        set<pair<ll, ll>, greater<>> s2; // top has the best cands for s1
        for (auto& [num, cnt] : n2c)
        {
            s1.insert({cnt, num});
            summ += cnt * num;
        }
        while (s1.size() > x)
        {
            auto it = s1.begin();
            s2.insert(*it);
            summ -= (it -> first) * (it -> second);
            s1.erase(it);
        }
        ret.push_back(summ);
        for (int j = k; j < n; ++j)
        {
            int i = j - k;
            // first process removed element
            // can be in 1, or in 2, can't be in none

            // in 1
            auto find1 = s1.find({n2c[nums[i]], nums[i]});
            auto find2 = s2.find({n2c[nums[i]], nums[i]});
            if (find1 != s1.end())
            {
                summ -= (find1 -> first) * (find1 -> second);
                s1.erase(find1);
                --n2c[nums[i]];
                if (n2c[nums[i]] <= 0)
                    n2c.erase(nums[i]);
                else
                    s1.insert({n2c[nums[i]], nums[i]});
                summ += (n2c[nums[i]] * nums[i]);
            }
            else if (find2 != s2.end())
            {
                s2.erase(find2);
                --n2c[nums[i]];
                if (n2c[nums[i]] <= 0)
                    n2c.erase(nums[i]);
                else
                    s2.insert({n2c[nums[i]], nums[i]});
            }

            // now process added element
            // can be in 1, or in 2, or in none.
            find1 = s1.find({n2c[nums[j]], nums[j]});
            find2 = s2.find({n2c[nums[j]], nums[j]});
            if (find1 != s1.end())
            {
                summ += (find1 -> second);
                s1.erase(find1);
                ++n2c[nums[j]];
                s1.insert({n2c[nums[j]], nums[j]});
            }
            else if (find2 != s2.end())
            {
                s2.erase(find2);
                ++n2c[nums[j]];
                s2.insert({n2c[nums[j]], nums[j]});
            }
            else
            {
                ++n2c[nums[j]];
                s2.insert({n2c[nums[j]], nums[j]});
            }

            // balance size in case we removed stuff
            while (s1.size() < x && !s2.empty())
            {
                auto it = s2.begin();
                s1.insert(*it);
                summ += (it -> first) * (it -> second);
                s2.erase(it);
            }

            // ensure s1 top is bigger than s2 top.
            while (!s2.empty())
            {
                auto it1 = s1.begin();
                auto it2 = s2.begin();
                if ((it1 -> first) < (it2 -> first) ||
                        ((it1 -> first) == (it2 -> first) && (it1 -> second) < (it2 -> second)))
                {
                    summ -= (it1 -> first) * (it1 -> second);
                    summ += (it2 -> first) * (it2 -> second);
                    s1.insert({it2 -> first, it2 -> second});
                    s2.insert({it1 -> first, it1 -> second});
                    s1.erase(it1);
                    s2.erase(it2);
                }
                else break;
            }
            ret.push_back(summ);
        }
        return ret;
    }
};
