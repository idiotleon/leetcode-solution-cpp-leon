#include <vector>
#include <queue>

using namespace std;

class Solution {        
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        const int n_rows = maze.size(), n_cols = maze[0].size();
        if(n_rows == 0 || n_cols == 0) return -1;
        
        vector<vector<int>> distances(n_rows, vector<int>(n_cols, -1));
        distances[start[0]][start[1]] = 0;
        
        queue<pair<int, int>> queue;
        queue.push({start[0], start[1]});
        
        while(!queue.empty()){
            auto cur = queue.front();
            queue.pop();
            
            int cur_row = cur.first, cur_col = cur.second;
            // cannot be commented out
            // if(cur_row == destination[0] && cur_col == destination[1]) break;
            
            for(int d = 0; d < 4; ++d){
                int next_row = cur_row, next_col = cur_col, distance = distances[cur_row][cur_col];
                
                while(isValid(next_row + dirs[d], next_col + dirs[d + 1], maze)){
                    next_row += dirs[d];
                    next_col += dirs[d + 1];
                    ++distance;
                }
                
                if(distances[next_row][next_col] == -1 || distance < distances[next_row][next_col]){
                    distances[next_row][next_col] = distance;
                    queue.push({next_row, next_col});
                }
            }
        }
        
        return distances[destination[0]][destination[1]];
    }
    
private:
    static const int EMPTY = 0;
    const int dirs[5] = {0, -1, 0, 1, 0};
    
    bool isValid(int row, int col, vector<vector<int>>& maze){
        int n_rows = maze.size(), n_cols = maze[0].size();
        
        return row >= 0 && row < n_rows && col >= 0 && col < n_cols && maze[row][col] == EMPTY;
    }
};