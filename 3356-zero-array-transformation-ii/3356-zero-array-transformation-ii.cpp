struct Node{
  long long val;
  long long lazy;
};

class SegmentTree{
    vector<Node>tree;
    vector<int> nums;
    int n;

  void clearDesk(int node, int l, int r){
          if(tree[node].lazy == 0)return;
          
           tree[node].val +=  tree[node].lazy;
          
          if(l<r){
             tree[2*node + 1].lazy += tree[node].lazy;
             tree[2*node + 2].lazy += tree[node].lazy;
          } 
          tree[node].lazy = 0;
  }  
  Node merge(Node left, Node right){
       Node node;
       node.val = max(left.val, right.val);
       node.lazy = 0;
       return node;
  }
 public:
   SegmentTree(){

   }
   SegmentTree(int n, vector<int>&nums){
     this->n = n;
     this->nums = nums;
     tree.assign(4*n, Node());
     build(0, 0, n-1);
     
   }

   void build(int node, int l, int r) {
    if (l == r) {
        tree[node].val = nums[l];
        return;
    }
    int m = (l + r) >> 1;
    build(2 * node + 1, l, m);
    build(2 * node + 2, m + 1, r);
    tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         int n = nums.size();
        SegmentTree st(n, nums);
        int k=0;
        if(st.query(0, 0, n-1, 0, n-1).val <= 0)return k;
        for(auto q:queries){
            k++;
            int l = q[0], r= q[1], val = q[2];
            st.update(0, 0, n-1, l, r, -val);
            if(st.query(0, 0, n-1, 0, n-1).val <= 0)return k;
        }

        return -1;
    }
};