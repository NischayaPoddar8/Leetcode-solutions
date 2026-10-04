class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int s = graph.size();
        vector<char>color(s,'r'); // Uncolored
        queue<int>q;

        for(int i=0;i<s;i++){
            if(color[i]=='r'){
                q.push(i);
                color[i] = 'b';
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int nbr : graph[node]){
                    if(color[nbr]=='r'){
                        q.push(nbr);
                        // Assign it color
                        if(color[node]=='b') color[nbr] = 'g';
                        else color[nbr] = 'b';
                    }
                    else if(color[nbr]==color[node]) return false; // Not Bipartite
                }
            }
        }
        
        return true;
    }
};