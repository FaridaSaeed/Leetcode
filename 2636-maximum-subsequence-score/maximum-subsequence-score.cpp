class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<pair<int,int>>v;
        int n = nums1.size();
        for(int i=0;i<n;i++)v.push_back({nums2[i],nums1[i]});
        sort(v.begin(),v.end(),greater<>());
        long long ans = 0,sum = 0;
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            pq.push(v[i].second);
            sum+=v[i].second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
                ans = max(ans,sum*v[i].first);
        }
        return ans;
    }
};