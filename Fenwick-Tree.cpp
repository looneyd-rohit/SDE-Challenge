// assume bit array to be always 1 indexed, since 0 indexing will cause infinite loops
const int n = 1e5;
int bit[N + 1];

int sum(int i)
{
    int ans = 0;
    for (; i > 0; i = i - (i & (-i)))
    {
        ans += bit[i];
    }
    return ans;
}

void update(int i, int x)
{
    for (; i <= N; i = i + (i & (-i)))
    {
        bit[i] += x;
    }
}