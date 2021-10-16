//18258번

#include <iostream>

using namespace std;

class Que
{
private:
    int instruct_num;
    int end;
    int *nums;
    int start;
    
public:
    Que(int num)
    {
        instruct_num = num;
        nums = new int[num];
        end = 0;
        start = 0;
    }
    bool empty()
    {
        if(end == start)
        {
            cout << 1 << endl;
            return true;
        }
        else
        {
            cout << 0 << endl;
            return false;
        }
    }
    void push(int n)
    {
        nums[end] = n;
        end++;
        
      
    }
    
    void pop()
    {
        if(end == start) cout << -1 << endl;
        else
        {
            cout << nums[start++] <<endl;
        }
    }
    void front()
    {
        if(end == start) cout << -1 << endl;
        else cout << nums[start] << endl;
    }
    void back()
    {
        if(end == start) cout << -1 << endl;
        else cout << nums[end - 1]<< endl;
    }
    int getSize()
    {
        return end-start;
    }
    
};

int main()
{
    int n;
    cin >> n;
    string instruction;
    Que que(n);
    
    for(int i =0; i< n; i++)
    {
        int x;
        cin >> instruction;
        if(instruction == "push")
        {
            cin >> x;
            que.push(x);
        }
        else if (instruction == "pop")
        {
            que.pop();
        }
        else if (instruction == "size")
        {
            cout << que.getSize() << endl;;
        }
        else if (instruction == "empty")
        {
            que.empty();
        }
        else if (instruction == "front")
        {
            que.front();
        }
        else if (instruction == "back")
        {
            que.back();
        }
    }
    
    return 0;
}

