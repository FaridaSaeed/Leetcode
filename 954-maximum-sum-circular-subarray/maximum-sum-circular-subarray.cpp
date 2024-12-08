class Solution {
public:
    int kanade(vector<int>&nums){
        int sum=INT_MIN,c=0;
        for(int i=0;i<nums.size();i++){
            if(c<0){
                c=0;
            }
            c+=nums[i];
            sum=max(sum,c);
        }
        return sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int pos=kanade(nums);
        if(pos<0)return pos;
        for(auto &a:nums)a=-a;
        int neg=kanade(nums);
        return max(pos,total+neg);
    }
};