class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int totalGas = 0;
        int totalCost = 0;

        for(int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost) return -1;

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