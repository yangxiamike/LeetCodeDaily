//
//  Target Sum.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/25.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
//O(LN) O(N)
class Solution{
public:
    int findTargetSumWays(vector<int>& nums, int S){
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (sum + S) % 2) return false;
        
        sort(nums.begin(), nums.end());
        const int sizeS = (sum + S) / 2, sizeN = upper_bound(nums.begin(), nums.end(), sizeS) - nums.begin();
        
        
        vector<int> dp(sizeS + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < sizeN; i++){
            const int temp = nums[i];
            for (int j = sizeS; j >= temp; --j) dp[j] += dp[j - temp];
        }
        return dp[sizeS];
    }
};
