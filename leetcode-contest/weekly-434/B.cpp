class Solution
{
public:
    vector<int> getUsers(string &s)
    {
        vector<int> ret;
        string cand;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                ret.push_back(stoi(cand));
                cand = "";
                continue;
            }
            if (s[i] != 'i' && s[i] != 'd')
            {
                cand.push_back(s[i]);
            }
        }
        if (!cand.empty())
        {
            ret.push_back(stoi(cand));
        }
        return ret;
    }

    vector<int> countMentions(int n, vector<vector<string>> &events)
    {
        int nn = events.size();
        vector<int> ret(n, 0);
        vector<vector<int>> newEvents(nn);
        for (int i = 0; i < nn; ++i)
        {
            int cmd = (events[i][0] == "OFFLINE") ? 0 : 1;
            newEvents[i] = {stoi(events[i][1]), cmd, i};
        }
        sort(newEvents.begin(), newEvents.end());

        unordered_set<int> offline;
        unordered_map<int, int> to_online;
        for (auto &v : newEvents)
        {
            int idx = v[2];
            if (events[idx][0] == "MESSAGE")
            {
                if (events[idx][2] == "ALL")
                {
                    for (auto &x : ret)
                    {
                        ++x;
                    }
                }
                else if (events[idx][2] == "HERE")
                {
                    for (int i = 0; i < ret.size(); ++i)
                    {
                        while (to_online.find(i) != to_online.end() && stoi(events[idx][1]) >= to_online[i])
                        {
                            offline.erase(i);
                            to_online.erase(i);
                        }
                    }

                    for (int i = 0; i < ret.size(); ++i)
                    {
                        if (offline.find(i) != offline.end())
                        {
                            continue;
                        }
                        ++ret[i];
                    }
                }
                else
                {
                    vector<int> users = getUsers(events[idx][2]);
                    for (auto &user : users)
                    {
                        ++ret[user];
                    }
                }
            }
            else
            {
                int time = stoi(events[idx][1]) + 60;
                int id = stoi(events[idx][2]);
                to_online[id] = time;
                offline.insert(id);
            }
        }
        return ret;
    }
};
