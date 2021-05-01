void modify(vector<int> &temp1, int idx)
{
    int n = a.size();
    int l = max(idx - 5, 0ll);
    int r = min(idx + 5, n - 1);
    int curr = l;
    while (curr <= r)
    {
        if (n - 1 > curr && curr >= 1)
        {
            temp1[curr] = 0;
            temp1[curr] += (a[curr] > a[curr + 1] && a[curr] > a[curr - 1]);
            temp1[curr] += (a[curr] < a[curr + 1] && a[curr] < a[curr - 1]);
        }
        curr++;
    }
}