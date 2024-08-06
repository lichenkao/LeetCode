class Solution {
public:
    int minimumPushes(string word) {
        sort(word.begin(), word.end());
        vector<int> c(26);
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            c[index]++;
        }
        sort(c.begin(), c.end());
        int count = 0;
        int time = 1;
        int ans = 0;
        for(int i = 25; i >= 0; i--){
            if(c[i] > 0){
                count++;
                ans += (time * c[i]);
                if(count == 8){
                    time++;
                    count = 0;
                }
            }
        }
        return ans;
    }
};