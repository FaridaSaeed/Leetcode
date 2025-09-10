class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<int>lst = intervals[0];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=lst[1])
            {
                if(intervals[i][1]>=lst[1])
                    lst[1] = intervals[i][1];
            }
            else
            {
                ans.push_back(lst);
                lst = intervals[i];
            }
        }
        ans.push_back(lst);
        return ans;
    }
};