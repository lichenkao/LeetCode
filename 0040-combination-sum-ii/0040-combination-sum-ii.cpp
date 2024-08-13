class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> final;
        vector<int> combination;
        backtrack(candidates, target, 0, combination, final);
        return final;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& final) {
        if (target == 0) {
            final.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;

            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, combination, final);
            combination.pop_back();  // Backtrack
        }
    }
};
