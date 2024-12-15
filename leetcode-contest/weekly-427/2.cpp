class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int maxx = -1;
        int n = points.size();

        if (n < 4) {
            return maxx;
        }

        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                for (int k = j + 1; k < n - 1; ++k) {
                    for (int l = k + 1; l < n; ++l) {
                        vector<int> xVals = {points[i][0], points[j][0],
                                             points[k][0], points[l][0]
                                            };
                        vector<int> yVals = {points[i][1], points[j][1],
                                             points[k][1], points[l][1]
                                            };
                        sort(xVals.begin(), xVals.end());
                        sort(yVals.begin(), yVals.end());

                        if (xVals[0] == xVals[1] && xVals[2] == xVals[3] &&
                                yVals[0] == yVals[1] && yVals[2] == yVals[3]) {

                            int area =
                                (xVals[2] - xVals[0]) * (yVals[2] - yVals[0]);
                            bool valid = true;

                            for (auto& p : points) {
                                if (p != points[i] && p != points[j] &&
                                        p != points[k] && p != points[l] &&
                                        xVals[0] <= p[0] && p[0] <= xVals[2] &&
                                        yVals[0] <= p[1] && p[1] <= yVals[2]) {
                                    valid = false;
                                    break;
                                }
                            }

                            if (valid) {
                                maxx = max(maxx, area);
                            }
                        }
                    }
                }
            }
        }

        return maxx;
    }
};