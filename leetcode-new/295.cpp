class MedianFinder
{
private:
    priority_queue<int, vector<int>, greater<int>> minh{};
    priority_queue<int> maxh{};

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        minh.push(num);
        if (!maxh.empty() && minh.top() < maxh.top())
        {
            maxh.push(minh.top());
            minh.pop();
        }
        while (minh.size() >= maxh.size() + 2)
        {
            maxh.push(minh.top());
            minh.pop();
        }
        while (maxh.size() >= minh.size() + 2)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
    }

    double findMedian()
    {
        if (minh.size() == maxh.size())
            return (static_cast<double>(minh.top()) + maxh.top()) / 2;
        if (minh.size() > maxh.size())
            return minh.top();
        else
            return maxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
