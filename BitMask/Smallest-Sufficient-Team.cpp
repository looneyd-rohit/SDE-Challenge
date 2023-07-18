// Leetcode 1125
// [IMP]: Bitmask + DP --> nice question

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size();
        int m = req_skills.size();
        unordered_map<string, int> skillmap;
        int cnt = 0;
        for(auto& skill: req_skills){
            skillmap[skill] = cnt++;
        }
        vector<int> peopleSkills(n, 0);
        for(int i=0; i<n; i++){
            for(auto& e: people[i]){
                peopleSkills[i] |= (1<<(skillmap[e]));
            }
        }
        
        vector<long long> dp((1<<m), (1LL<<n)-1);
        // skillset varies from 0 to all total skills
        dp[0] = 0;    // for 0 skill team we need a team with zero members
        for(int reqSkillSet=1; reqSkillSet<(1<<m); reqSkillSet++){
            // for a person to contribute to the team with reqSkillSet, the skills which
            // that person possess must not have intersection with other members of the
            // team, in other words that person should form a team with others having different
            // skill sets
            for(int i=0; i<n; i++){
                int otherSkillSet = reqSkillSet & (~peopleSkills[i]);
                if(otherSkillSet == reqSkillSet){
                    // i-th person has no effect, since he posses skill that is not required
                    // for current reqSkillSet
                }else{
                    long long peopleInNewTeamAsMask = dp[otherSkillSet] | (1LL<<i);
                    if(__builtin_popcountll(peopleInNewTeamAsMask) < __builtin_popcountll(dp[reqSkillSet])){
                        dp[reqSkillSet] = peopleInNewTeamAsMask;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(dp[(1<<m) - 1] & (1LL<<i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};