class DisjointSet{
    public:
        vector<int>rank,size,parent;
        DisjointSet(int n){
            size.resize(n+1,1);
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findUparent(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findUparent(parent[node]);
        }

        void unionByRank(int u,int v){
            int uPu=findUparent(u);
            int uPv=findUparent(v);
            if(uPu==uPv) return;

            if(rank[uPu] < rank[uPv]){
                parent[uPu]=uPv;
            }
            else if(rank[uPu] > rank[uPv]){
                parent[uPv]=uPu;
            }
            else {
                parent[uPv]=uPu;
            }


        }

        void unionBySize(int u,int v){
            int upu=findUparent(u);
            int upv=findUparent(v);
            if(upu==upv) return;

            if(size[upu] < size[upv]){
                size[upv]+=size[upu];
                parent[upu]=upv;
            }
            else{
                size[upu]+=size[upv];
                parent[upv]=upu;
            }
        }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        // ds.unionBySize(1,2);
        // for(int i=0;i<=3;i++){
        // cout << ds.findUparent(i) << " ";
        // }

        for(auto temp:edges){
            int u=temp[0];
            int v=temp[1];
            if(ds.findUparent(u)==ds.findUparent(v)) return false;

            ds.unionBySize(u,v);
        }
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(ds.findUparent(i));
        }
        return s.size()==1;
    }
};
