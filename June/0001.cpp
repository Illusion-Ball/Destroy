class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> occurred;
        for (int i = 0; i < nums.size(); i++) {
            int posOccurred = occurred[target - nums[i]];
            if (posOccurred >= 1) {
                return {posOccurred - 1, i};
            }
            occurred[nums[i]] = i + 1;
        }
    }
};
