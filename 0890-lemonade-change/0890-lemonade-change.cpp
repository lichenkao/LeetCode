class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map <int, int> map = {{5, 0},{10, 0}};
        int n = bills.size();
        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                map[5]++;
            }
            else if(bills[i] == 10){
                if(map[5] == 0)
                    return false;
                else{
                    map[5]--;
                    map[10]++;
                }
            }
            else{
                if(map[10] >= 1 && map[5] >= 1){
                    map[10]--;
                    map[5] -= 1;}
                else if(map[5] >= 3){
                    map[5] -= 3;
                }
                else
                    return false;
            }

        }
        return true;
    }
};