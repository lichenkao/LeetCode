class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0)
        return true;
        if(flowerbed.size() == 1 && n == 1 && flowerbed[0] == 0)
        return true;
        if(flowerbed.size() == 1 && n > 0)
        return false;

        for(int i = 0; i < flowerbed.size(); i++){
            if(i == flowerbed.size()-1 && flowerbed[i] == 1)
            n += 0;
            else if(i == flowerbed.size()-1 && flowerbed[i] == 0)
            n--;
            else if(flowerbed[i] == 1 && flowerbed[i+1] != 1){
                flowerbed[i+1] = 2;
            }
            else if(flowerbed[i] == 0 && flowerbed[i+1] != 1){
                n--;
                flowerbed[i+1] = 2;
            }

            if(n <= 0)
            return true;
        }
        return false;
    }
};