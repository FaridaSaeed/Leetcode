class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(auto i:spells)
        {
            int l = 0 , r = m;
            while(l<r)
            {
                int mid = l+(r-l)/2;
                long long x = (long long)i*potions[mid];
                if(x<success)l = mid+1;
                else r = mid;
            }
            ans.push_back(m-l);
        }
        return ans;
    }
};