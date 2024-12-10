class MedianFinder {
public:
    priority_queue<int>maxheap;//store min numbers
    priority_queue <int, vector<int>, greater<int> > minheap; //stores max numbers
    MedianFinder() {}
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top()>num)
            maxheap.push(num);
        else minheap.push(num);
        
        if(maxheap.size()>minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size()>maxheap.size()+1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }

    }
    
    double findMedian() {
        if(minheap.size()>maxheap.size())return minheap.top();
        else if(maxheap.size()>minheap.size())return maxheap.top();
        else return (minheap.top()+maxheap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */