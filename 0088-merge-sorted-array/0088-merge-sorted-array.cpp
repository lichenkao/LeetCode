class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
    int count1 = 0, count2 = 0; // 初始化计数器
    while(count1 < m && count2 < n){ // 使用&&逻辑操作符
        if(nums1[count1] < nums2[count2]){ // 修正拼写错误
            ans.push_back(nums1[count1]);
            count1++;
        }
        else{
            ans.push_back(nums2[count2]);
            count2++;
        }
    }
    
    // 把剩余元素加入ans
    while(count1 < m) {
        ans.push_back(nums1[count1]);
        count1++;
    }
    
    while(count2 < n) {
        ans.push_back(nums2[count2]);
        count2++;
    }
    
    // 将ans内容拷贝回nums1
    for(int i = 0; i < ans.size(); i++) {
        nums1[i] = ans[i];
    }

    }
       
};