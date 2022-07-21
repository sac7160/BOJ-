#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int s,p;
    int ans = 0;
    char dna[1000001];
    
    cin >> s >> p;
    for(int i=0; i<s; i++)
    {
        cin >> dna[i];
    }
    
    int checkArr[4];    //ACGT 비밀번호 체크
    int myArr[4];   //검사할 배열
    
    for(int i=0; i<4; i++)
    {
        cin >> checkArr[i];
        myArr[i] = 0;
    }
    
   
    
    for(int i =0; i<p; i++)
    {
        if(dna[i]=='A') myArr[0]++;
        else if(dna[i]=='C') myArr[1]++;
        else if(dna[i]=='G') myArr[2]++;
        else if(dna[i]=='T') myArr[3]++;
    }
    bool correct = true;
    
    for(int i=0; i<4; i++)
    {
        if(myArr[i]<checkArr[i]) correct = false;
    }
    
    if(correct) ans++;
    
    correct = true;
    
    for(int i=p; i<s; i++)
    {
        int j = i-p;
        if(dna[i]=='A') myArr[0]++;
        else if(dna[i]=='C') myArr[1]++;
        else if(dna[i]=='G') myArr[2]++;
        else if(dna[i]=='T') myArr[3]++;
        
        if(dna[j]=='A') myArr[0]--;
        else if(dna[j]=='C') myArr[1]--;
        else if(dna[j]=='G') myArr[2]--;
        else if(dna[j]=='T') myArr[3]--;
        
        for(int i=0; i<4; i++)
        {
            if(myArr[i]<checkArr[i]) correct = false;
        }
        
        if(correct) ans++;
        correct = true;
    }
    
    cout << ans;
}

