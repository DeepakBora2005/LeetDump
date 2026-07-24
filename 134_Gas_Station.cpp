class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int totalGas = 0;
        int totalCost = 0;
        int start = 0;
        int fuel = 0;

        for(int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];

            fuel += gas[i] - cost[i];

            if(fuel < 0) {
                start = i + 1;
                fuel = 0;
            }
        }

        if(totalGas < totalCost) return -1;

        return start;
    }
};