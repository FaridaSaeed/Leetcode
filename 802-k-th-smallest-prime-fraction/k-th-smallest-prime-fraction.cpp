class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<double,pair<int,int>>mp;
        int sz = arr.size();
        for(int i=0;i<sz;i++)
        {
            for(int j=i+1;j<sz;j++)
            {
                pair p = {arr[i],arr[j]};
                double a = 1.0*arr[i]/arr[j];
                mp[a] = p;
            }
        }
        auto it = mp.begin();
        for(int i=1;i<k;i++)
        {
            it++;
        }
        vector<int> ans;
        ans.push_back((it->second).first);
        ans.push_back((it->second).second);
        return ans;
    }
};