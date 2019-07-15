//
//  Possible Bipartition.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/15.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
//O(N+E) graph
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        vector<int> colors(N);
        for (vector<int> neighbor:dislikes){
            graph[neighbor[0] -1].push_back(neighbor[1] - 1);
            graph[neighbor[1] -1].push_back(neighbor[0] - 1);
        }
        for (int i = 0; i < N; i++){
            if (colors[i] == 0 && !dfs(graph, colors, i, 1)) return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int idx, int color){
        if (colors[idx] != 0) return colors[idx] == color;
        colors[idx] = color;
        
        for (int num:graph[idx]){
            if (!dfs(graph, colors, num, -color)) return false;
        }
        return true;
    }
    
    
};
