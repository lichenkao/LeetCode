class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        int i = 2;
        int ans = 0;

        while(n > 1){
            while(n % i == 0){
                n /= i;
                ans += i;
            }
            i++;
        }
        return ans;


    }
};