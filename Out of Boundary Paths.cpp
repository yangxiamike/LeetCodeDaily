//
//  Out of Boundary Paths.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/15.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
//brute force <time exceed qwq>
class Solution {
public:
    const int mod = 1e9+7;
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;
        if (m == 1 && n == 1) return 4;
        vector<vector<int>> choice = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        long sum = 0;
        explore(N, i, j, m, n, choice, sum);
        return sum;
    }
    void explore(int remain, int x, int y, int m, int n,
                 vector<vector<int>> choice, long& sum){
        if (x < 0 || y < 0 || x == m || y == n){
            sum += 1;
            return ;
        }
        if (remain > 0){
            for (vector<int> direction:choice){
                explore(remain - 1, x + direction[0], y + direction[1],
                        m, n, choice, sum);
            }
        }
    }
};


// brute force memoizaition
class Solution {
public:
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N+1, -1)));
        return explore(m, n, N, i, j, dp);
    }
    int explore(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& dp){
        if (N >= 0){
            if (i < 0 || j < 0 || i == m || j == n) return 1;
            if (dp[i][j][N] != -1) return dp[i][j][N];
            auto result = 0;
            result = (result + explore(m, n, N-1, i+1, j, dp)) % mod;
            result = (result + explore(m, n, N-1, i-1, j, dp)) % mod;
            result = (result + explore(m, n, N-1, i, j-1, dp)) % mod;
            result = (result + explore(m, n, N-1, i, j+1, dp)) % mod;
            return dp[i][j][N] = result;
        }
        return 0;
    }
};
