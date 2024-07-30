class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> ans(n+1, 0);
        int bCount = 0;

        for(int i = 1; i <= n; i++){
            if(s[i-1] == 'b'){
                ans[i] = ans[i-1];
                bCount++;
            }
            else{
                ans[i] = min(ans[i-1] + 1, bCount);
            }
        }

        return ans[n];
    }
};