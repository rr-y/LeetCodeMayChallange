class Solution {
 public:
 vector<int> adj[2001];// declare a adjacency list
 int colors[2001]; // declare a array for inserting the colors
        
 bool possibleBipartition(int N, vector<vector<int>>& dislikes)
 {       
     for(int i=1;i<=N;i++)
        colors[i]=0;// making all nodes to be of '0' color
        
        
     for(auto v : dislikes)
     {
        adj[v[0]].push_back(v[1]); // connecting u--v
        adj[v[1]].push_back(v[0]);  // connecting v--u
     }
        
     for(int i=1;i<=N;i++)
     {
        if(colors[i]==0) // node is not colored yet !!
          {
             queue<int>q; 
             q.push(i); // pushing into the Queue
             colors[i]=1; // coloring the node-->'i' to '1'
                
             while(!q.empty()) // will check until the queue is empty
              {

                int f=q.front(); // taking the parent
                q.pop(); // poping it

                for(int neigh : adj[f]) // will traverse through level ordering
                {
                  if(colors[neigh]==colors[f])
                     return false; // if parent and its neighbourer 
                        //have same color return false
                        
                  if(colors[neigh]==0) // if not yet colored
                  {
                     colors[neigh]=-colors[f]; // coloring it with just opposite 
                            // sign of parent
                     q.push(neigh);// pushing it into the queue
                  }
                }    
             }
          }
      }
      return true;
    }
    
};
