struct Node{
 int count=0;
};

class SegmentTree{
private:
	vector<Node>tree;
	int n;
	Node merge(Node lNode, Node rNode){
		Node res;
		res.count = lNode.count + rNode.count;
		return res;
	}

public:
	SegmentTree(){};
	SegmentTree(int sz){
		this->n = sz;
		tree.assign(4*n, Node());
		build(0, 0, n-1);
	};

	void build(int node, int l, int r){
		 if(l==r){
		 	tree[node] = Node();
		 	 return;
		 }

		 int m = l+((r-l)>>1);
		 build(2*node+1, l, m);
		 build(2*node+2, m+1, r);
		 tree[node] = merge(tree[2*node+1], tree[2*node+2]);
	}

	void update(int node, int l, int r, int id, int val){
		if(l==r){
			tree[node].count += val;
			return;
		}
		 int m = l+((r-l)>>1);
		 if(id<=m)
		   update(2*node+1, l, m,id, val);
		 else 
		   update(2*node+2, m+1, r, id, val);

		 tree[node] = merge(tree[2*node+1], tree[2*node+2]);

	}

	Node query(int node, int l, int r, int ql, int qr){
		//out of bound
			if(l>qr || r< ql) return Node{
				.count = 0
			};

		//complete overlap;
			if(ql<=l && qr>=r){
				return tree[node];
			}

			int m = l+((r-l)>>1);
		Node leftAns = query(2*node+1, l, m, ql, qr);
		Node rightAns = query(2*node+2, m+1, r, ql, qr);
		return merge(leftAns, rightAns);
		
	}
};


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n= nums.size();
        vector<long long>pre(n+1, 0);
        for(int i=0;i<n;i++){
            pre[i+1] = pre[i] + nums[i];
        }

        // lower <=P[j] -P[i]   <= upper 
        //     P[j] -lower  <=P[i]<= P[j]- upper
        //at every j: both boundary are constant. hecne fined all previous P[i]s that lies in this range/   
        vector<long long>compression;
        for(auto p:pre){
                compression.push_back(p);
                compression.push_back(p-upper);
                compression.push_back(p-lower);
        }
        //keep only unique in sorted order
        sort(compression.begin(), compression.end());
        compression.erase(unique(compression.begin(), compression.end()), compression.end()) ;
        int sz = compression.size();
        SegmentTree st(sz);
        int ans =0;
        for(auto p:pre){
            int leftRank = lower_bound(compression.begin(), compression.end(), p-upper) - compression.begin();
            int rightRank = lower_bound(compression.begin(), compression.end(), p-lower) - compression.begin();
            int pRank = lower_bound(compression.begin(), compression.end(), p) - compression.begin();
            int count = st.query(0,0,sz-1, leftRank, rightRank).count;
            ans += count;
            st.update(0, 0, sz-1, pRank, 1);
        }
      return ans;
    }
}; 