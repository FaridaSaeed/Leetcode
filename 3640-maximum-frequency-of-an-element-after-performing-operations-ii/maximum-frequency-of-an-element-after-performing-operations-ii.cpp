class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int>difArray, freq;
        int low = 2e9, high = -2e9, ans = 1, prevSum = 0;
        for(int i : nums){
            freq[i] ++;
            difArray[i - k] ++;
            difArray[i + k + 1] --;
            difArray[i] += 0;
        }
        for(auto it : difArray){
            it.second += prevSum;
            prevSum = it.second;
            int extra = it.second - freq[it.first];
            extra = min(extra, numOperations);
            ans = max(ans, extra + freq[it.first]);
        }
        return ans;
    }
};