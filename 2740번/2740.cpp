

#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    
    cin >> n >> m;
    
    int A[100][100];
    int B[100][100];
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> A[i][j];
        }
    }
    
    cin >> m >> k;
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<k; j++)
        {
            cin >> B[i][j];
        }
    }
    
    int ans[100][100];
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            for(int x=0; x<m; x++)
            {
                ans[i][j] += A[i][x] * B[x][j];
            }
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            cout << ans[i][j] << " " ;
        }
        cout << endl;
    }
}
