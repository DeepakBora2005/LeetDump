class Solution {
public:
    int upper(vector<int> &arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] > target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int lower(vector<int> &arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();

        vector<int> result;
        
        vector<int> start(n);
        vector<int> end(n);

        for(int i = 0; i < n; i++) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.begin());

        for(int i = 0; i < people.size(); i++) {
            int target = people[i];
            int x = upper(start, target);
            int y = lower(end, target);

            int ans = (x - y);
            result.push_back(ans);
        }

        return result;
    }
};