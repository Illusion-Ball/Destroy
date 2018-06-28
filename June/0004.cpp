class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0;
        int high = n1;
        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (n1 + n2) / 2 - partition1;
            int left1 = (partition1 - 1) >= 0 ? nums1[partition1 - 1] : INT_MIN;
            int left2 = (partition2 - 1) >= 0 ? nums2[partition2 - 1] : INT_MIN;
            int right1 = (partition1 < n1) ? nums1[partition1] : INT_MAX;
            int right2 = (partition2 < n2) ? nums2[partition2] : INT_MAX;
            if (left1 > right2) {
                high = partition1 - 1;
            } else if (left2 > right1) {
                low = partition1 + 1;
            } else {
                if ((n1 + n2) & 1) {
                    return min(right1, right2); 
                } else {
                    return (max(left1, left2) + min(right1, right2)) / (double) 2;
                }
            }
        }
    }
};
