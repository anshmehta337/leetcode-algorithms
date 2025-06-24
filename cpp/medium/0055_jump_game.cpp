// Leetcode 55: Jump Game
// Problem link: https://leetcode.com/problems/jump-game/

class Solution {
public:
  
    bool fn(vector<int>& nums, int n, vector<int>& dp, int i) {
        if (i >= n - 1) return true;
        if (dp[i] != -1) return dp[i];

        int maxJump = min(i + nums[i], n - 1);
        for (int j = i + 1; j <= maxJump; j++) {
            if (fn(nums, n, dp, j)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return fn(nums, n, dp, 0);
    }
};
