# Solve in O(logN) Apply lazy propagation in Segment Tree.

# Code
```cpp []
//Apply lazy propagation in segment tree to achieve O(logN) for bulk range updates queries

const int MOD = 1e9+7;
struct Update{
 long long lazy_add =0;
 long long lazy_mul = 1; 
};
struct Node{
  long long val = 0;
  Update lazy = Update();
};
class SegmentTree{
    int n;
    vector<Node>tree;
    void push_down(int node, int l, int r){
        Update lazyObj = tree[node].lazy;
        long long m = lazyObj.lazy_mul;
        long long a = lazyObj.lazy_add;
        
        if (m == 1 && a == 0) return; // Nothing to push
        tree[node].val = (tree[node].val * m + a * (r - l + 1)) % MOD;
    

        if(l!=r){
            int left = 2 * node + 1;
            int right = 2 * node + 2;

            tree[left].lazy.lazy_add = (tree[left].lazy.lazy_add * m + a) % MOD;
            tree[left].lazy.lazy_mul = (tree[left].lazy.lazy_mul * m) % MOD;

            tree[right].lazy.lazy_add = (tree[right].lazy.lazy_add * m + a) % MOD;
            tree[right].lazy.lazy_mul = (tree[right].lazy.lazy_mul * m) % MOD;
        }
        tree[node].lazy = Update();
    }

     Node merge(Node lNode, Node rNode){
        return Node{
            .val = (lNode.val + rNode.val + MOD)%MOD,
            .lazy = Update()
        };
    }
    public: 
    SegmentTree(int n){
        tree.assign(4*n, Node());
    }
    void update(int node, int l ,int r, int ul, int ur, Update updateObj){
        //clear the desk
        push_down(node, l, r);
        if(ul<=l && ur>=r){
            tree[node].lazy = updateObj;
            push_down(node, l, r); 
            return;
         }
         if(l>ur || r<ul) return;
         int m = l+ ((r-l)>>1);

         update(2*node+1, l, m, ul, ur, updateObj);
         update(2*node+2, m+1, r, ul, ur, updateObj);
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
class Fancy {
    const int MAX_N = 100009; // <--- Move this to the top!
    SegmentTree st;
    int current_size;
public:
    Fancy(): st(MAX_N), current_size(0) {
    }
    
    void append(int val) {
        st.update(0, 0, MAX_N-1, current_size, current_size, Update{.lazy_add = val, .lazy_mul = 1});
        current_size++;
    }
    
    void addAll(int inc) {
        if (current_size == 0) return;
        st.update(0, 0, MAX_N-1, 0, current_size - 1, Update{.lazy_add = inc, .lazy_mul = 1});
    }
    
    void multAll(int m) {
        if (current_size == 0) return;
        st.update(0, 0, MAX_N-1, 0, current_size - 1, Update{.lazy_add = 0, .lazy_mul = m});
    }
    
    int getIndex(int idx) {
       if (idx >= current_size) return -1;
        return st.query(0, 0, MAX_N-1, idx, idx).val;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
```