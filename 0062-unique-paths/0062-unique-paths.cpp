class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pro(n, 1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                pro[j] = (pro[j] + pro[j-1]);
            }
        }
        return pro[n-1];
    }
};