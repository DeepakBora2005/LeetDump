class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<pair<int, int>> temp;
        
        for(int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0];
            int booked = reservedSeats[i][1];

            temp.push_back({row, booked});
        }

        sort(temp.begin(), temp.end());

        int ans = 2 * n;

        int i = 0;

        while(i < temp.size()) {
            int curr = temp[i].first;

            bool left = true;
            bool middle = true;
            bool right = true;

            while(i < temp.size() && temp[i].first == curr) {
                int seat = temp[i].second;

                if(seat >= 2 && seat <= 5) {
                    left = false;
                }
                if(seat >= 4 && seat <= 7) {
                    middle = false;
                }
                if(seat >= 6 && seat <= 9) {
                    right = false;
                }

                i++;
            }

            ans -= 2;

            if(left && right) ans += 2;
            if(left || middle || right) ans += 1;
        }

        return ans;
    }
};