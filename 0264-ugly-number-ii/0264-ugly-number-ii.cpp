class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n);

        ans[0] = 1;
        int two = 0, three = 0, five = 0;

        for(int i = 1; i < n; i++){
            int twoans = ans[two] *2;
            int threeans = ans[three] *3;
            int fiveans = ans[five] *5;

            int tmp = min(twoans, min(threeans, fiveans));
            ans[i] = tmp;
            if(tmp == twoans)
                two++;
            if(tmp == threeans)
                three++;
            if(tmp == fiveans)
                five++;
        }
        return ans[n-1];
    }
};