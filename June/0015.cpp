class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int numOfElements = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < numOfElements - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = numOfElements - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum >= 0) {
                    if (sum == 0) {
                        ans.push_back({nums[i], nums[l], nums[r]});
                    }
                    r--;
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
