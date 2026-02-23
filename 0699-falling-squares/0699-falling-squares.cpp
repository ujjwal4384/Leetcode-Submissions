struct Node{
    int maxHeight = 0;
    int lazy = 0;
};

class SegmentTree{
  private:
    int n;
    vector<Node>tree;  

    Node merge(Node lNode, Node rNode){
        return Node{
            .maxHeight = max(lNode.maxHeight, rNode.maxHeight),
            .lazy = 0
        };
    }

    void push_down(int node, int l, int r){
        if(tree[node].lazy == 0) return ;
        tree[node].maxHeight = tree[node].lazy;

        if(l!=r){
            tree[2*node+1].lazy = tree[node].maxHeight;
            tree[2*node+2].lazy = tree[node].maxHeight;
        }
        tree[node].lazy = 0;
    }
  public:
    SegmentTree(int sz){
        this->n = sz;
        tree.assign(4*n, Node());
    }

  void  update(int node, int l, int r, int ul, int ur, int val){
         push_down(node, l, r);
         if(l>ur || r<ul) return;
         if(ul<=l && ur>=r){
            tree[node].lazy = val;
            push_down(node, l, r); 
            return;
         }
         int m = l+ ((r-l)>>1);

         update(2*node+1, l, m, ul, ur, val);
         update(2*node+2, m+1, r, ul, ur, val);
         tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    }

   Node query(int node, int l, int r, int ql, int qr){
         push_down(node, l, r);
         if(l>qr || r<ql) return Node();
         if(ql<=l && qr>=r){
            return tree[node];
         }
         int m = l+ ((r-l)>>1);

         Node lNode = query(2*node+1, l, m, ql, qr);
         Node rNode = query(2*node+2, m+1, r, ql, qr);
      return merge(lNode, rNode);
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int>compression;
        for(auto p:positions){
            int a = p[0];
            int b = p[1];
            compression.push_back(a);
            compression.push_back(a+b-1);
        }
        sort(compression.begin(), compression.end());
        compression.erase(unique(compression.begin(), compression.end()), compression.end());
        int sz = compression.size();
        SegmentTree st(sz);
        vector<int>ans;
        for(auto p:positions){
             int a = p[0];
            int b = p[1];
            int l= a;
            int r = a+b-1;
            int lRank = lower_bound(compression.begin(), compression.end(), l) - compression.begin();
            int rRank = lower_bound(compression.begin(), compression.end(), r)- compression.begin();
            int curMaxHeight = st.query(0, 0, sz-1, lRank, rRank).maxHeight; 
            st.update(0,0, sz-1, lRank, rRank, curMaxHeight + b);
            int maxHeight = st.query(0, 0, sz-1, 0, sz-1).maxHeight; 
            ans.push_back(maxHeight);
        }

        return ans;
    }
};