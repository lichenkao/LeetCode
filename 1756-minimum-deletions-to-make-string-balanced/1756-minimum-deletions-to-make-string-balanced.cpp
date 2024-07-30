class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int ans = 0;
        int bCount = 0;

        for(int i = 1; i <= n; i++){
            if(s[i-1] == 'b'){
                bCount++;
            }
            else{
                ans = min(ans + 1, bCount);
            }
        }

        return ans;
    }
};