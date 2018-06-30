class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = (int) height.size() - 1;
        int maximumArea = 0;
        while (l < r) {
            int currentArea = min(height[l], height[r]) * (r - l);
            maximumArea = max(maximumArea, currentArea);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maximumArea;
    }
};
