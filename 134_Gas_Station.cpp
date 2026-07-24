class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for(int i = 0; i < n; i++) {
            int curr = i;
            int count = 0;
            int temp = 0;

            while(count < n) {
                temp += gas[curr];
                temp -= cost[curr];

                if(temp < 0) break;

                curr = (curr + 1) % n;

                count++;
            }

            if(count == n) return i;
        }

        return -1;
    }
};