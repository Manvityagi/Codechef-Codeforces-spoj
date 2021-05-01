#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums)
{
    int n = nums.size();
    vector<int> tree(4 * n);
    function<void(int, int, int, int)> update = [&](int node, int idx, int start, int end) {
        if (start == end)
            return void(tree[node] = 1);
        int mid = (start + end) / 2;
        if (mid >= idx)
            update(node * 2, idx, start, mid);
        else
            update(node * 2 + 1, idx, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    };

    function<int(int, int, int, int, int)> query = [&](int node, int l, int r, int start, int end) {
        if (l > end || r < start || l > r)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(node * 2, l, r, start, mid) + query(node * 2 + 1, l, r, mid + 1, end);
    };

    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i)
        s.emplace(nums[i], i);
    vector<int> ans;
    while (s.size())
    {
        int index = s.begin()->second;
        s.erase(s.begin());
        ans.emplace_back(index - query(1, 0, index, 0, n - 1));
        update(1, index, 0, n - 1);
    }
    return ans;
}
