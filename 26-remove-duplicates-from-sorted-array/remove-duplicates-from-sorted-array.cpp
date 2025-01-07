class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 0,ans = 0,lst=0;
        if(nums[0]==0)ind++;
        for(auto i:nums)
        {
            if(lst<0 && i>0){
                lst = i;
                nums[ind] = i;
                ind++;
                continue;
            }
            if(abs(lst)^abs(i)){
                nums[ind] = i;
                ind++;
                lst = i;
            }
        }
        return ind;
    }
};