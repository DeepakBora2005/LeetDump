class Solution {
public: 
    bool find(int rem, int cnt0, int cnt1, int cnt2) {
        if(cnt0 > 0 && rem != 0) {
            if(!find(rem, cnt0 - 1, cnt1, cnt2))
                return true;
        }
        
        if(cnt1 > 0) {
            int next = (rem + 1) % 3;

            if(next != 0) {
                if(!find(next, cnt0, cnt1 - 1, cnt2))
                    return true;
            }
        }

        if(cnt2 > 0) {
            int next = (rem + 2) % 3;

            if(next != 0) {
                if(!find(next, cnt0, cnt1, cnt2 - 1))
                    return true;
            }
        } 

        return false;      
    }

    bool stoneGameIX(vector<int>& nums) {
        int n = nums.size();

        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] % 3 == 0) cnt0++;
            else if(nums[i] % 3 == 1) cnt1++;
            else cnt2++;
        }

        return find(0, cnt0, cnt1, cnt2);
    }
};