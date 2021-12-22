//1966번

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> weight;
    int caseNum;
    cin >> caseNum;
    
    int n;
    int m;
    int enter;
    int count =0;
    bool flag;

    while(caseNum--)
    {
        cin >> n >> m;
        for(int i=0; i<n;i++)
        {
            cin >> enter;
            weight.push_back(enter);
        }
        count =0;
        
        while(true)
        {
            flag = false;
            for(int i=1; i<n; i++)
            {
                if(weight[0]<weight[i])
                {
                    if(m==0) m = weight.size()-1;
                    else m--;
                    
                    weight.push_back(weight[0]);
                    weight.erase(weight.begin());
                    flag = true;
                    break;
                }
            }//큰게 있으면 뒤로 보내줌
            
            if(flag == false)
            {
                if( m == 0)
                {
                    count++;
                    break;
                }
                else
                {
                    count++;
                    weight.erase(weight.begin());
                    n--;
                    m--;
                }
            }
        }
        cout << count << endl;
        weight.clear();
    }
}
