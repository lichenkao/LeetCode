class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(const auto& detail:details){
            int ten = detail[11] - '0';
            int digit = detail[12] - '0';
            if((ten*10 + digit) > 60){
                ans++;
            }
        }
        return ans;
    }
};