vector<int> Z(vector<int>& a)
{
    int nn = a.size();
    vector<int> z(nn);
    int l = 0, r = 0;
    for (int k = 1; k < nn; ++k)
    {
        if (k < r)
        {
            z[k] = min(r - k, z[k - l]);
        }
        while (k + z[k] < nn && a[z[k]] == a[k +  z[k]])
        {
            ++z[k];
        }
        if (k + z[k] > r)
        {
            l = k;
            r = k + z[k];
        }
    }
    return z;
}
