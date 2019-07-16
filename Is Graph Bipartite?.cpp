//
//  Is Graph Bipartite?.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/16.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
//O(E) Pure DFS without recursion
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), curr;
        if (n == 1) return true;
        vector<int> visited(n, 0);
        vector<int> que;
        for (int i = 0; i < n; i++){
            if (visited[i] == 0){
                que.push_back(i);
                visited[i] = 1;
                while (que.size() > 0){
                    curr = que[que.size() - 1];
                    que.pop_back();
                    for (int next:graph[curr]){
                        if (visited[next] == visited[curr]) return false;
                        if (visited[next] == 0){
                            que.push_back(next);
                            visited[next] = -visited[curr];
                        }
                    }
                }
            }
        }
        return true;
    }
};

//O(E)  dfs with recussion - faster than iteration
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return true;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++){
            if (visited[i] == 0 && !dfs(graph, visited, i, 1))
                return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int curr, int color){
        if (visited[curr] == 0) {
            visited[curr] = color;
            for (int node:graph[curr]){
                if (!dfs(graph, visited, node, -color))
                    return false;
            }
        }
        else if (visited[curr] != color)
            return false;
        return true;
    }
};
