class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> temp;
            if(ans.empty()){
            temp.push_back(1);
            }else{
            temp.push_back(1);
            for(int j=1; j<ans.back().size(); j++){
                temp.push_back(ans.back()[j-1] + ans.back()[j]);
            }
            temp.push_back(1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};