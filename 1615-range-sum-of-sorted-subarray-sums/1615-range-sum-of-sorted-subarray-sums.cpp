class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> tmp;
        for(int i = 0; i < n; i++){
            int sum = nums[i];
            tmp.push_back(sum);
            for(int j = i+1; j < n; j++){
                sum+=nums[j];
                tmp.push_back(sum);
            }
        }
        sort(tmp.begin(), tmp.end());
        int ans = 0;
        const int mod = 1e9 + 7;
        for(int i = left-1; i < right; i++){
            ans = (ans + tmp[i]) % mod;
        }        
        return ans;
    }
};