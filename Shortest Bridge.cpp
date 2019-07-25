//
//  Shortest Bridge.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/17.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
//O(N^2) faster than 20%.......
class Solution {
private:
    vector<vector<int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    bool foundisland = false;
public:
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size(), sum = 0;
        queue<vector<int>> q;
        //find first island
        for (int i = 0; i < n; i++){
            if (foundisland) break;
            for (int j = 0; j < n; j++){
                if (foundisland) break;
                dfs(A, q, i, j);
            }
        }
        
        //bfs
        while (q.size() > 0){
            int count = q.size();
            for (int i = 0; i < count; i++){
                vector<int> coor = q.front();
                q.pop();
                int x = coor[0], y = coor[1];
                
                for (vector<int> direction:directions){
                    int a = x + direction[0], b = y + direction[1];
                    if (a < 0 || a >= A.size() || b < 0 || b >= A.size() ||
                        A[a][b] == 2) continue;
                    if (A[a][b] == 1) return sum;
                    A[a][b] = 2;
                    q.push({a, b});
                }
            }
            sum += 1;
        }
        return -1;
    }
    
    void dfs(vector<vector<int>>& A, queue<vector<int>>& q, int i, int j){
        if (A[i][j] == 0) return;
        A[i][j] = 2;
        foundisland = true;
        q.push({i, j});
        for (vector<int> direction:directions){
            int a = i + direction[0], b = j + direction[1];
            if (a < 0 || a >= A.size() || b < 0 || b >= A.size() || A[a][b] == 0 ||
                A[a][b] == 2) continue;
            dfs(A, q, a, b);
        }
    }
    
    
};
