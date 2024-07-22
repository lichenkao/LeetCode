class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mapping;

        for(int i = 0; i < names.size(); i++){
            mapping[heights[i]] = names[i];
        }

        sort(heights.rbegin(), heights.rend());

        for(int i = 0; i < names.size(); i++){
            names[i] = mapping[heights[i]];
        }
        return names;
    }
};