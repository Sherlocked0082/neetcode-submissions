class MedianFinder {
    priority_queue<int> mxheap;
    priority_queue<int, vector<int>, greater<int>> mnheap;

public:
    MedianFinder() {}

    void addNum(int num) {

        // Smaller half
        if (mxheap.empty() || num < mxheap.top()) {
            mxheap.push(num);
        }
        // Larger half
        else {
            mnheap.push(num);
        }

        // Balance
        if (mxheap.size() > mnheap.size() + 1) {
            mnheap.push(mxheap.top());
            mxheap.pop();
        }
        else if (mnheap.size() > mxheap.size() + 1) {
            mxheap.push(mnheap.top());
            mnheap.pop();
        }
    }

    double findMedian() {

    if (mxheap.size() == mnheap.size()) {
        return ((double)mxheap.top() + mnheap.top()) / 2.0;
    }
    else if (mxheap.size() > mnheap.size()) {
        return mxheap.top();
    }
    else {
        return mnheap.top();
    }
    }
};