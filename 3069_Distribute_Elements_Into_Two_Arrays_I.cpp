class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int left = nums[0];
        int right  = nums[1];

        for(int i = 2; i < n; i++) {
            if(left > right) {
                arr1.push_back(nums[i]);
                left = nums[i];
            }
            else {
                arr2.push_back(nums[i]);
                right = nums[i];
            }
        }

        vector<int> result;

        int i = 0;
        int j = 0;

        while(i < arr1.size()) {
            result.push_back(arr1[i++]);
        }

        while(j < arr2.size()) {
            result.push_back(arr2[j++]);
        }
        
        return result;
    }
};