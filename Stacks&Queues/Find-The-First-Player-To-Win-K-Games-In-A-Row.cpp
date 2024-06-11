// Leetcode 3175

// Approach: deque based simulation
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

class Solution {
public:
    int findWinningPlayer(std::vector<int>& skills, int k) {
        std::deque<int> playersDeque;
        std::map<int, int> skillToIndex;
        std::map<int, int> victoryCount;
        int maxSkillValue = 0;
        int maxSkillIndex = -1;
        
        initialize(skills, playersDeque, skillToIndex, victoryCount, maxSkillValue, maxSkillIndex);
        
        if (k >= skills.size()) {
            return maxSkillIndex;
        }
        
        while (playersDeque.size() >= 2) {
            if (processMatch(playersDeque, skillToIndex, victoryCount, k)) {
                return skillToIndex[playersDeque.front()];
            }
        }
        
        return -1;
    }

private:
    void initialize(const std::vector<int>& skills, std::deque<int>& playersDeque, 
                    std::map<int, int>& skillToIndex, std::map<int, int>& victoryCount, 
                    int& maxSkillValue, int& maxSkillIndex) {
        for (int i = 0; i < skills.size(); i++) {
            playersDeque.push_back(skills[i]);
            skillToIndex[skills[i]] = i;
            victoryCount[skills[i]] = 0;
            if (skills[i] > maxSkillValue) {
                maxSkillValue = skills[i];
                maxSkillIndex = i;
            }
        }
    }

    bool processMatch(std::deque<int>& playersDeque, std::map<int, int>& skillToIndex, 
                      std::map<int, int>& victoryCount, int k) {
        int firstPlayer = playersDeque.front();
        playersDeque.pop_front();
        int secondPlayer = playersDeque.front();
        playersDeque.pop_front();
        
        int winner = std::max(firstPlayer, secondPlayer);
        int loser = std::min(firstPlayer, secondPlayer);
        
        playersDeque.push_front(winner);
        playersDeque.push_back(loser);
        
        victoryCount[winner]++;
        
        return victoryCount[winner] == k;
    }
};
