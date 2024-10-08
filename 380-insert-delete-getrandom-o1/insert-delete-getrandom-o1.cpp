class RandomizedSet {
    unordered_set<int> set;
public:
    RandomizedSet() {
        set ={};
    }
    
    bool insert(int val) {
        if(set.count(val)) return false;
        set.insert(val);
        return true;
    }
    
    bool remove(int val) 
    {
        if(!set.count(val)) return false;
        set.erase(val);
        return true;    
    }
    
    int getRandom() {
        auto it = set.begin();
        std::advance(it, std::rand() % set.size());
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */