class Solution {
public:
    bool checkDivisibility(int n) {

        int original = n;
        int sum = 0;
        int product = 1;

        while (n > 0) {
            int rem = n % 10;

            sum += rem;
            product *= rem;

            n /= 10;
        }

        int total = sum + product;

        return original % total == 0;
    }
};