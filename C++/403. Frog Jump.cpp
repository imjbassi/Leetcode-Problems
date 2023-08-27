class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> jumpMap; // Stores possible jump distances
        
        for (int stone : stones) {
            jumpMap[stone] = unordered_set<int>(); // Initialize jump distances for each stone
        }
        jumpMap[0].insert(1); // Initialize first jump
        
        for (int i = 0; i < n; ++i) {
            for (int jump : jumpMap[stones[i]]) {
                int nextStone = stones[i] + jump;
                if (jumpMap.find(nextStone) != jumpMap.end()) {
                    if (jump - 1 > 0) jumpMap[nextStone].insert(jump - 1);
                    jumpMap[nextStone].insert(jump);
                    jumpMap[nextStone].insert(jump + 1);
                }
            }
        }
        
        return !jumpMap[stones.back()].empty(); // Check if last stone has valid jump distances
    }
};
