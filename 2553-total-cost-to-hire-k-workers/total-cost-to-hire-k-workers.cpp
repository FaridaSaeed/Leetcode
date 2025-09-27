class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = costs.size();
        int left = candidates-1, right = n-candidates;
        for(int i=0;i<n;i++)
        {
            if(i<candidates || n-i-1<candidates)
            {
                if(i<candidates)
                    pq.push({costs[i],left});
                else 
                    pq.push({costs[i],right});
            }
        }
        long long ans = 0;
        while(k--)
        {
            pair<int,int>p = pq.top();
            pq.pop();
            ans+=p.first;
            int i = p.second;
            if(left+1>=right){
                continue;
            }
            if(i<=left){
                left++;
                pq.push({costs[left],left});
            }
            else{
                right--;
                pq.push({costs[right],right});
            }
            
        }
        return ans;
    }
};