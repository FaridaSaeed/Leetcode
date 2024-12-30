class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size(),m = potions.size();
        vector<int>ans;
        for(auto i:spells)
        {
            long long x = (success+i-1)/i;
            int ind = lower_bound(potions.begin(),potions.end(),x)-potions.begin();
            ans.push_back(m-ind);
        }
        return ans;
    }
};