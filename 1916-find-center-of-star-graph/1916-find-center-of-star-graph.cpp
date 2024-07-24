class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int size = edges.size();
        int a = edges[0][0];
        int counta = 0;
        int b = edges[0][1];
        int countb = 0;
        for(int i = 1; i < size; i++){
            if(edges[i][0] == a || edges[i][1] == a){
                counta = 1;    
            }
            if(edges[i][0] == b || edges[i][1] == b){
                    countb = 1;
            }
        }
        if(counta == 1)
            return a;
        else
            return b;
    }
};