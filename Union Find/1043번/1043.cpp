#include <iostream>
#include <vector>

using namespace std;


int * parent;
vector<vector<int>> party;

int find(int a)
{
    if(a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if(a!=b) parent[b] = a;
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    int ans = 0;
    
    cin >> n >> m;  //사람 n명, 파티 m개
    
    
    
    int num;
    cin >> num;
    
    int * fact = new int[num];
    
    for(int i=0; i<num; i++) cin >> fact[i];       //진실을 아는 사람
    
    parent = new int[n+1];
    
    for(int i=1; i<=n; i++) parent[i] = i;
    
    vector<int> tmp;
    for(int i=0; i<m; i++) party.push_back(tmp);
    
    for(int i=0; i<m; i++)
    {
        int tmp;
        cin >> tmp;
        for(int j=0; j<tmp; j++)
        {
            int tmp2;
            cin >> tmp2;
            party[i].push_back(tmp2);
        }
    }
    
    //초기화,입력 완료
    
    for(int i=0; i<m; i++)  //각 파티에 참가한 사람들 묶어주기
    {
        int first = party[i][0];
        for(int j=1; j<party[i].size(); j++) Union(first,party[i][j]);
    }
    
    for(int i=0; i<m; i++)
    {
        bool isPossible = true;
        int cur = party[i][0];
        for(int j=0; j<num; j++)
        {
            if(find(cur) == find(fact[j]))
            {
                isPossible = false;
                break;
            }
        }
        if(isPossible) ans++;
    }
    
    cout << ans;
    
    
    delete[] parent;
    delete[] fact;
   
}

