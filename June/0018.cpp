class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int) nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < (int) nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int ptr1 = j + 1;
                int ptr2 = (int) nums.size() - 1;
                while (ptr1 < ptr2) {
                    int sum = nums[i] + nums[j] + nums[ptr1] + nums[ptr2];
                    if (sum <= target) {
                        if (sum == target) {
                            ans.push_back({nums[i], nums[j], nums[ptr1], nums[ptr2]});
                        }
                        ptr1++;
                        while (ptr1 < ptr2 && nums[ptr1] == nums[ptr1 - 1]) {
                            ptr1++;
                        }
                    } else {
                        ptr2--;
                    }
                } 
            }
        }
        return ans;
    }
};
