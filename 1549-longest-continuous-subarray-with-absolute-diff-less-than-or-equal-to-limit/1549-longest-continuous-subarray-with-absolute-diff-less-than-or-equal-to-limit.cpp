class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int size = nums.size();
        int count = 0;
        int maxLength = 0;
        int big = 0;
        int small = 0;
        int big_count = 0;
        int small_count = 0;

        for(int i = 0; i < size; i++) {
            if(big < (i - count)){
                big = i - count;
                for(big_count = big; big_count <= i; big_count++) {
                    if(nums[big] <= nums[big_count]) {
                        big = big_count;
                    }
                }
            }
            if(small < (i - count)){
                small = i - count;
                for(small_count = small; small_count <= i; small_count++) {
                    if(nums[small] >= nums[small_count]) {
                        small = small_count;
                    }
                }
            }
            if(nums[i] >= nums[big]) {
                big = i;
            }
            if(nums[i] <= nums[small]) {
                small = i;
            }
            if((nums[big] - nums[small]) <= limit) {
                count++;
                maxLength = max(maxLength, count);
            } else {
                count = i - min(big, small);
            }
        }
        return maxLength;
    }

};