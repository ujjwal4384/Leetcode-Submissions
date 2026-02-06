class Solution
{
    multiset<int> l, r;

public:
    long long minimumCost(vector<int> &nums, int k, int dist)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        long long cnt = nums[0];
        k--;

        // Add the first 'dist + 1' elements to the left multiset
        for (int i = 1; i <= dist + 1; i++)
        {
            cnt += nums[i];
            l.insert(nums[i]);
        }

        // Balance the left multiset to have 'k' elements
        while (l.size() > k)
        {
            int temp = *l.rbegin();
            cnt -= temp;
            r.insert(temp);
            l.erase(l.find(temp));
        }

        long long ans = cnt;

        // Iterate through the array from index 'dist + 2'
        for (int i = dist + 2; i < n; i++)
        {
            int pre = nums[i - dist - 1];

            // Remove the element at index 'i - dist - 1' from the appropriate multiset
            if (l.find(pre) != l.end())
            {
                cnt -= pre;
                l.erase(l.find(pre));
            }
            else
            {
                r.erase(r.find(pre));
            }

            // Add the element at index 'i' to the appropriate multiset
            int cur = nums[i];
            if (cur < *l.rbegin())
            {
                cnt += cur;
                l.insert(cur);
            }
            else
            {
                r.insert(cur);
            }

            // Balance the left multiset to have 'k' elements
            while (l.size() < k)
            {
                int temp = *r.begin();
                cnt += temp;
                l.insert(temp);
                r.erase(r.find(temp));
            }

            // Balance the left multiset to have 'k' elements
            while (l.size() > k)
            {
                int temp = *l.rbegin();
                cnt -= temp;
                r.insert(temp);
                l.erase(l.find(temp));
            }

            // Update the answer as the minimum between the current answer and 'cnt'
            ans = min(ans, cnt);
        }

        return ans;
    }
};