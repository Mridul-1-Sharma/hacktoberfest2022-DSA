class Solution {
public:
    
    void findCombination(vector<int>& candidates, int target, int i, vector<vector<int>>& ans, vector<int>&ds){
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            findCombination(candidates, target-candidates[i], i, ans, ds);   
            ds.pop_back();
        }
        findCombination(candidates, target, i+1, ans, ds);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(candidates, target, 0, ans, ds);
        return ans;
    }
};
