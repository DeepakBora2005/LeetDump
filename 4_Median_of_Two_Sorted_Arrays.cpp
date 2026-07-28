class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m + n == 0) return 0.0;  

        int left = 0;
        int right = 0;
        int k = 0;

        vector<int> temp(m + n);

        while(left < m && right < n) {
            if(nums1[left] <= nums2[right]) {
                temp[k++] = nums1[left++];
            }
            else {
                temp[k++] = nums2[right++];
            }
        }

        while(left < m) {
            temp[k++] = nums1[left++];
        }

        while(right < n) {
            temp[k++] = nums2[right++];
        }

        double ans = 0;

        if((m + n) % 2 == 0) {
            ans = ((double)temp[(m + n) / 2] + temp[((m + n) / 2) - 1]) / 2;
        }
        else {
            ans = temp[(m + n) / 2];
        }

        return ans;
    }
};