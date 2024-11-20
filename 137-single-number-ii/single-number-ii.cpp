class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;

        int running = 0;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (map[nums[i]] == 0) {
                running ^= nums[i];
                map[nums[i]]++;
            }
            else if (map[nums[i]] == 1) {
                map[nums[i]]++;
            }
            else if (map[nums[i]] == 2) {
                running ^= nums[i];
                map[nums[i]]++;
            }
        }

        return running;
    }
};