class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexOfOccurrence;
        for (int i = 0; i < nums.size(); i++) {
            if (indexOfOccurrence.count(target - nums[i]) > 0) {
                return {indexOfOccurrence[target - nums[i]], i};
            }
            indexOfOccurrence[nums[i]] = i;
        }
    }
};
