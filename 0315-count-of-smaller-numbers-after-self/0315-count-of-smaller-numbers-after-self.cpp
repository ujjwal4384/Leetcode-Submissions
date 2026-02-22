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
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();

        vector<int>compression = nums;
        sort(compression.begin(), compression.end());
        compression.erase(unique(compression.begin(), compression.end()), compression.end());
        int sz = compression.size();
        SegmentTree st(sz);
        vector<int>ans(n, 0);

        // 0th rank number<= nums[j]<= nums[i]
        //traverse i from n-1->0. for every i: query how many nums i have seen so farf which are less than nums[i] and >= INT_MIN (0th rank number)
        for(int i=n-1;i>=0;i--){
        int  leftRank = 0;
        int nRank = lower_bound(compression.begin(), compression.end(), nums[i]) - compression.begin();   
        int rightRank = nRank -1;
        ans[i] = st.query(0, 0, sz-1, leftRank, rightRank).count ;
        st.update(0, 0, sz-1, nRank, 1);
        }
        return ans;
    }
};