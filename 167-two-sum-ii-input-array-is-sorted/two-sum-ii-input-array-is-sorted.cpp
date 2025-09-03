class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<numbers.size();i++)
        {
            if(mp[target-numbers[i]])
                return {mp[target-numbers[i]],i+1};
            mp[numbers[i]] = i+1;
        }
        return {-1,-1};
    }
};