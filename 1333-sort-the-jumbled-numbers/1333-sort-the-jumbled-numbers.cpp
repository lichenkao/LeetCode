class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mapNumAndIndex(nums.size());
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 0){
                mapNumAndIndex[i] = {mapping[0], i};
                continue;
            }
            int cur = nums[i];
            int count = 1;
            int tmp = 0;
            
            while(cur > 0){
                tmp += (mapping[(cur%10)]) * count;
                cur /= 10;
                count *= 10;
            }
            mapNumAndIndex[i] = {tmp, i};
        }

        sort(mapNumAndIndex.begin(), mapNumAndIndex.end());
        vector<int> ans;
        for(const auto& pair: mapNumAndIndex){
            ans.push_back(nums[pair.second]);
        }
        return ans;

    }
};