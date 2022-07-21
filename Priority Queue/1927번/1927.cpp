#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> pQ;
    int num;


    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int enterNum;
        cin >> enterNum;
        if (enterNum) pQ.push(-enterNum);
        else if (pQ.empty()) cout << '0' << '\n';
        else
        {
            cout << -pQ.top() << '\n';
            pQ.pop();
        }
    }
    return 0;
}