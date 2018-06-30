class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());    
        int closestSum = nums[0] + nums[1] + nums[2];       
        for (int i = 0; i < (int) nums.size() - 2; i++) {
            int l = i + 1;
            int r = (int) nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }
                if (sum > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return closestSum;
    }
};
