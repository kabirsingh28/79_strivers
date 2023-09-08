class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isPossible(int idx, unordered_map<int, vector<int>> &adj, vector<int> &color, int n, int m){
        if(idx == n)
            return true;
            
        for(int i=1; i<=m; i++){
            bool flag = false;
            
            for(auto x : adj[idx]){
                if(color[x] == i){
                    flag = true;
                    break;
                }
            }
            
            if(!flag){
                color[idx] = i;
                
                if(isPossible(idx+1, adj, color, n, m))
                    return true;
                    
                color[idx] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                if(graph[i][j]){
                    adj[i].push_back(j);
                    // adj[j].push_back(i);
                }
            }
        }
        vector<int> color(n, 0);
        
        return isPossible(0, adj, color, n, m);
    }
};