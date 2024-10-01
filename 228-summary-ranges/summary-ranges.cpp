class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<int>v;
        vector<string>ans;
        if(nums.size()==0)return ans; 
        int x = nums[0];
        v.push_back(x);
        for(int i=1;i<nums.size();i++)
        {
            long long sm = nums[i];
            sm-=x;
            if(sm==1)
            {
                x = nums[i];
                v.push_back(x);
            }
            else
            {
                string s;
                s+=to_string(v[0]);
                if(v.size()>1){
                    s+="->";
                    s+=to_string(v.back());
                }
                ans.push_back(s);
                x = nums[i];
                v.clear();
                v.push_back(x);
            }
        }
        string s;
        s+=to_string(v[0]);
        if(v.size()>1){
            s+="->";
            s+=to_string(v.back());
        }
        ans.push_back(s);
        return ans;
    }
};