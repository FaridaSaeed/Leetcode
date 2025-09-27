class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>, greater<int>>pq;
    unordered_map<int,int>mp;
    SmallestInfiniteSet() {
        for(int i = 1;i<1001;i++){
            pq.push(i);
            mp[i] = 1;
        }
    }
    
    int popSmallest() {
        if(!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            mp[x] = 0;
            return x;
        }
        return 0;
        
    }
    
    void addBack(int num) {
        if(!mp[num]){
            pq.push(num);
            mp[num] = 1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */