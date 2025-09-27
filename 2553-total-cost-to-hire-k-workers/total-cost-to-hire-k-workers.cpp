class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>>pqleft, pqright;
        int n = costs.size();
        if(candidates>n/2)candidates = (n+1)/2;
        int left = candidates, right = n-candidates-1;
        for(int i=0;i<n;i++)
        {
            if(i<candidates)
                pqleft.push(costs[i]);
            else if(n-i-1<candidates)
                pqright.push(costs[i]);
            
        }
        long long ans = 0;
        while(k--)
        {
            int l = pqleft.empty()?INT_MAX:pqleft.top();
            int r = pqright.empty()?INT_MAX:pqright.top();
            ans+=min(l,r);
            if(l<=r)
            {
                pqleft.pop();
                if(left>right)continue;
                pqleft.push(costs[left++]);
            }
            else 
            {
                pqright.pop();
                if(left>right)continue;
                pqright.push(costs[right--]);
            }   
        }
        return ans;
    }
};