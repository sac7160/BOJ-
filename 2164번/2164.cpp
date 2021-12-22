//2164번

#include <queue>
#include <iostream>

using namespace std;

int main()
{
    queue<int> cards;
    int maxNum;
    cin >> maxNum;
    
    for(int i=1; i <= maxNum; i++)
    {
        cards.push(i);
    }

    while(cards.size()>1)
    {
        cards.pop();
        int front = cards.front();
        cards.pop();
        cards.push(front);
    }
    cout << cards.front() << endl;
    return 0;
}
