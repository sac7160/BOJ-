#include <iostream>
#include <vector>

using namespace std;


long long nums[1000001];
long long tree [4000004];

long long init(int start, int end, long long node)
{
    if (start == end) return tree[node] = nums[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
long long sum(int start, int end, int left, int right, long long node)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);

}
void update(int start, int end, long long node, long long index, long long dif)
{
    if (index <start || index > end) return;
    tree[node] += dif;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)

    {
        cin >> nums[i];
    }

    init(1, n, 1);

    long long a, b;
    long long c;

    for (int i = 0; i < m + k; i++)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            update(1, n, 1, b, c-nums[b]);
            nums[b] = c;
        }
        else if (a == 2)
        {
            cout << sum( 1, n,b,c, 1) << '\n';
        }
    }

}
