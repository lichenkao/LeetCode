class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> ans;
        for(auto& count: arr)
            ans[count]++;
        for(auto& count: arr){
            if(ans[count] == 1){
            k--;
            if(!k)
                return count;
            }
        }
        return "";
    }
};