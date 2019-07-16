//
//  Find Islands.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/15.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
//O(N)
class Solution {
private:
    vector<int> X = {-1, 1, 0, 0};
    vector<int> Y = {0, 0, -1, 1};
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        int sum = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    sum += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return sum;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        for (int a = 0; a < X.size(); a++){
            if (isvalid(i + X[a], j + Y[a]) == 1 && grid[i + X[a]][j + Y[a]] == '1'){
                grid[i + X[a]][j + Y[a]] = 't';
                dfs(grid, i + X[a], j + Y[a]);
            }
        }
    }
    int isvalid(int i, int j){
        if (i < 0 || j < 0 || i == m || j == n) return 0;
        else return 1;
    }
};
