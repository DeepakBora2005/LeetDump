class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        
        while(n > 0) {
            arr.push_back(n % 10);
            n /= 10;
        }

        sort(arr.begin(), arr.end());

        int m = arr.size();

        int a = arr[m - 1];
        int b = arr[m - 2];

        return a * b;    
    }
};