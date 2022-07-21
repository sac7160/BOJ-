// 1655번

#include <iostream>
#include <queue>

using namespace std;

class Compare {
public:
    bool operator() (int a, int b) 
    { 
        return a > b; 
    }
};

int main(void)
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, Compare> minHeap;  //최소우선순위큐
    priority_queue<int> maxHeap;
    int num;
    int count = 0;


    cin >> num;

    for (int i = 0; i < num; i++)   
    {
        int enterNum;
        cin >> enterNum;

 
        if (!i) maxHeap.push(enterNum);
        else if(enterNum>maxHeap.top())
        {
            minHeap.push(enterNum);
        }
        else
        {
            maxHeap.push(enterNum);
        }

        while (minHeap.size() > maxHeap.size())  
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        while (minHeap.size()+1 < maxHeap.size()) 
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        cout << maxHeap.top() << '\n';
    }
   
    return 0;
}


