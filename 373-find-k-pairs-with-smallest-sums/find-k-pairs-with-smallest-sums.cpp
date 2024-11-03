class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto i:nums1)
        {
            for(auto j:nums2)
            {
                int sum = i+j;
                if(pq.size()<k)
                    pq.push({sum,{i,j}});
                else if(sum<pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{i,j}});
                }
                else break;
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty())
        {
            auto p = pq.top().second;
            pq.pop();
            ans.push_back({p.first,p.second});
        }
        return ans;
    }
};