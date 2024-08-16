class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min = arrays[0][0];
        int n = arrays[0].size();
        int max = arrays[0][n-1];
        int min_index = 0;
        int max_index = 0;
        n = arrays.size();

        for(int i = 1; i < n; i++){
            int m = arrays[i].size();
            if(arrays[i][0] <= min){
                min = arrays[i][0];
                min_index = i;
            }
            if(arrays[i][m-1] >= max){
                max = arrays[i][m-1];
                max_index = i;
            }
        }
        int ans = 0;
        if(max_index == min_index){
            int second_max, second_min;
            if(max_index == 0){
                int m = arrays[1].size();
                second_max = arrays[1][m-1];
                second_min = arrays[1][0];
            }
            else{
                int m = arrays[0].size();
                second_max = arrays[0][m-1];
                second_min = arrays[0][0];

            }
            for(int i = 0; i < n; i++){
                if(i == max_index)
                    continue;
                int m = arrays[i].size();
                if(arrays[i][m-1] >= second_max){
                    second_max = arrays[i][m-1];
                }
                if(arrays[i][0] <= second_min){
                    second_min = arrays[i][0];
                }
            }
            if(second_max - min > max - second_min){
                ans = second_max - min;
            }
            else{
                ans = max - second_min;
            }
        }
        else{
            ans = max - min;
        }
        return ans;
    }
};