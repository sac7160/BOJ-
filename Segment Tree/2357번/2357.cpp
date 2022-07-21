#include <iostream>

using namespace std;

long long *minTree = new long long[400004];
long long *maxTree = new long long[400004];
long long *nums = new long long[100001];
//bool isMin = true;

long long initMin(int start, int end, int node)
{
    if(start==end) return minTree[node] = nums[start];
    int mid = (start+end)/2;
    long long leftChild = initMin(start,mid,node*2);
    long long rightChild = initMin(mid+1, end, node*2+1);
    if(leftChild > rightChild) minTree[node] = rightChild;
    else minTree[node] = leftChild;
    return minTree[node];
}

long long initMax(int start, int end, int node)
{
    if(start==end) return maxTree[node] = nums[start];
    int mid = (start+end)/2;
    long long leftChild = initMax(start,mid,node*2);
    long long rightChild = initMax(mid+1, end, node*2+1);
    if(leftChild < rightChild) maxTree[node] = rightChild;
    else maxTree[node] = leftChild;
    return maxTree[node];
}


long long findMin(int left,int right, int start, int end, int node)    //left,right가 구하고자 하는 범위
{
    if(left>end|| right <start) return 0;
    if(left<=start && right>=end) return minTree[node];
    int mid = (start+end)/2;
    
    long long leftChild = findMin(left, right, start, mid, node*2);
    long long rightChild = findMin(left,right, mid+1,end, node*2+1);
    if(leftChild ==0) return rightChild;
    else if(rightChild == 0) return leftChild;
    else if(leftChild > rightChild) return rightChild;
    else return leftChild;
}

long long findMax(int left,int right, int start, int end, int node)    //left,right가 구하고자 하는 범위
{
    if(left>end|| right <start) return 0;
    if(left<=start && right>=end) return maxTree[node];
    int mid = (start+end)/2;
    
    long long leftChild = findMax(left, right, start, mid, node*2);
    long long rightChild = findMax(left,right, mid+1,end, node*2+1);
    if(leftChild ==0) return rightChild;
    else if(rightChild == 0) return leftChild;
    else if(leftChild < rightChild) return rightChild;
    else return leftChild;
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    nums[0] = 0;
    minTree[0] = 0;
    
    for(int i=1; i<=n; i++)
    {
        cin >> nums[i];
    }
    
    initMin(1,n,1);
    initMax(1,n,1);
    
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
    
        cout << findMin(a, b, 1, n, 1) << " " << findMax(a,b,1,n,1) << '\n';
    }
    
    delete[] nums;
    delete[] minTree;
    delete[] maxTree;
}
