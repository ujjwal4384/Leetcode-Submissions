class SegmentTree{
 private:
  vector<int>nums;
  vector<int>tree;

 public:
    SegmentTree(vector<int>nums){
    this->nums = nums;
    
    tree.assign(4*nums.size(), 0); 
      
    build(0, 0, nums.size() - 1); 
        
    }

    void build(int node, int l, int r){
        if(l==r){
             tree[node] = nums[l];
             return ;
        }
        int m = (l+r)/2;
        build(2*node+1, l,  m);
        build(2*node+2, m+1,  r);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    void update(int node, int id, int val, int l, int r){
        if(l==r){
            nums[l] = val;
            tree[node] = nums[l];
            return;
        }
        int m = (l+r)/2;
        if(id>=l && id<=m)
         update(2*node+1,id, val, l, m);
        else 
         update(2*node+2,id,val, m+1, r);

         tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    int query(int node, int l, int r, int ql, int qr){
        //out of range
        if(ql>qr || ql>r || qr<l) return 0;

        //if node contains the range return whole value
        if(ql<=l && qr>=r) return tree[node];
        int m = (l+r)/2;

        return query(2*node+1, l, m, ql, qr) + query(2*node+2, m+1, r, ql, qr);  
    }
};

class NumArray {
private:    
    SegmentTree st; 
    int n;
public:
    NumArray(vector<int>& nums):st(nums), n(nums.size()) {
        
    }
    
    void update(int index, int val) {
        st.update(0, index, val, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return st.query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */