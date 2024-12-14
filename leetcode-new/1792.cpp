class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double accu = 0;
        priority_queue<pair<double, pair<double, double>>> pq;
        for (int i = 0; i < n; ++i)
        {
            double pass = classes[i][0], total = classes[i][1];
            accu += pass / total;
            double d = (pass + 1) / (total + 1) - pass / total;
            pq.push({d, {pass + 1, total + 1}});
        }
        while (extraStudents--)
        {
            auto [d, x] = pq.top();
            accu += d;
            auto [pass, total] = x;
            pq.pop();
            double dd = (pass + 1) / (total + 1) - pass / total;
            pq.push({dd, {pass + 1, total + 1}});
        }
        return accu / n;
    }
};
