struct Node{
  long long val;
  long long lazy;
};

class SegmentTree{
    vector<Node>tree;
    int n;

  void clearDesk(int node, int l, int r){
          if(tree[node].lazy == 0)return;
          
           tree[node].val +=  ( r-l + 1LL)*tree[node].lazy;
          
          if(l<r){
             tree[2*node + 1].lazy += tree[node].lazy;
             tree[2*node + 2].lazy += tree[node].lazy;
          } 
          tree[node].lazy = 0;
  }  
  Node merge(Node left, Node right){
       Node node;
       node.val = left.val + right.val;
       node.lazy = 0;
       return node;
  }
 public:
   SegmentTree(){

   }
   SegmentTree(int n){
     this->n = n;
     tree.assign(4*n, Node());
     
   }

   void update(int node, int l, int r, int ql, int qr, int val){
            clearDesk(node, l, r);
            
            if(ql> r || qr<l) return ;
            if(ql<=l && qr>=r){
                tree[node].lazy += val;
                clearDesk(node, l, r);
                return ;
            }
            int m  = (l+r)>>1;
            update(2*node+1, l, m, ql, qr, val);
            update(2*node+2, m+1, r, ql, qr, val);
            tree[node] = merge(tree[2*node+1], tree[2*node+2]);
   }

   Node query(int node, int l, int r, int ql, int qr){
            clearDesk(node, l, r);

            if(ql> r || qr<l) return Node();
            if(ql<=l && qr>=r){
                return tree[node];
            }
                
            int m  = (l+r)>>1;
           
            Node leftNode = query(2*node+1, l, m, ql, qr);
            Node rightNode = query(2*node+2, m+1, r, ql, qr);
            return merge(leftNode, rightNode);
   }
};

class Solution {
public:


    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree st(n);
        for(auto q:queries){
            int l = q[0], r= q[1];
            st.update(0, 0, n-1, l, r, 1);
        }

        for(int i=0;i<n;i++){
            long long val = st.query(0, 0, n-1, i, i).val ;
            if(val < nums[i]) return false;
        }
        return true;
    }
};