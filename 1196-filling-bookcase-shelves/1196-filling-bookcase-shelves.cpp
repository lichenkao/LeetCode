class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= books.size(); i++){
            int height = 0;
            int width = 0;
            for(int j = i; j > 0; j--){
                width += books[j-1][0];
                if(width > shelfWidth)
                    break;
                height = max(height, books[j-1][1]);
                dp[i] = min(dp[j-1] + height, dp[i]);
            }
        }
        return dp[n];
    }
};