#include <iostream>

using namespace std;

long long * enter = new long long[100001];
long long * tree = new long long[400004];

long long init(int start, int end, int node)
{
    if(start == end) return tree[node] = enter[start];
    int middle = (start + end) /2;
    long long leftChild = init(start,middle, node*2);
    long long rightChild = init(middle+1, end, node*2+1);
    
    if(leftChild<rightChild)
    {
        return tree[node] = leftChild;
    }
    else{
        return tree[node] = rightChild;
    }
}

long long findMin(int start, int end, int left, int right, int node)
{
    if(left>end || right<start) return 0;
    if(start>=left && end <= right) return tree[node];
    
    int middle = (start + end)/2;
    long long leftChild = findMin(start, middle, left, right, node*2);
    long long rightChild = findMin(middle+1, end, left, right, node*2+1);
    
    if(leftChild == 0 ) return rightChild;
    else if(rightChild == 0) return leftChild;
    else if(leftChild > rightChild) return rightChild;
    else return leftChild;
}

long long update(int start, int end, int index, long long val, int node)
{
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] = val;
    int middle = (start + end) /2;
    long long leftChild = update(start,middle,index,val,node*2);
    long long rightChild = update(middle+1,end,index,val,node*2+1);
    if(leftChild<rightChild) return tree[node] = leftChild;
    else return tree[node] = rightChild;
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    
    cin >> n;
    
    for(int i=1; i<=n; i++) cin >> enter[i];
    
    cin >> m;
    
    init(1,n,1);
    
    for(int i=0 ; i<m; i++)
    {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        if(a == 2) cout << findMin(1,n,b,c,1) << '\n';
        else if(a==1)
        {
            enter[b] = c;
            update(1,n,b,c,1);
        }
        //cout << " \" " << tree[1] << tree[2] << tree[3] << tree[4] << tree[5] << tree [6] << tree[7] << " \" ";
    }

    delete[] enter;
    delete[] tree;
}
