//2675번

#include <iostream>

using namespace std;

int main()
{
    int caseNum;
    cin >> caseNum;
    
    char* text = new char[21];

    for(int i = 0; i<caseNum; i++)
    {
        int r;
       
        
        cin >> r >> text;
        for(int y = 0; text[y] !=0; y++)
        {
            for(int x = 0; x<r; x++)
            {
                cout << text[y];
            }
        }
        cout << endl;
    }
    delete[] text;
    return 0;
}
