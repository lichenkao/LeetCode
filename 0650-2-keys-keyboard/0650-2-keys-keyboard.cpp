class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        vector<int> pro;
        int i = 2;

        while(n > 1){
            while(n % i == 0){
                pro.push_back(i);
                n /= i;
            }
            i++;
        }
        int ans = 0;
        for(int i = 0; i< pro.size(); i++){
            ans += pro[i];
        }
        return ans;


    }
};