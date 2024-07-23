class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> ans;
        for(int i = 0; i < nums.size(); i++) {
            ans[nums[i]]++;
        }
        
        sort(nums.begin(), nums.end(), [&ans](int a, int b) {
            if (ans[a] != ans[b]) {
                return ans[a] < ans[b];
            }
            return a > b;
        });

        return nums;
    }
};
