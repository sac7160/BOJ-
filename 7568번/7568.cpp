#include <iostream>
#include <vector>

class person
{
public:
    int weight;
    int height;
};

int main()
{
    using namespace std;
    
    int n;
    cin >> n;
    
    vector<person> people;
    
    for(int i=0; i<n; i++)
    {
        person tmp;
        cin >> tmp.weight >> tmp.height;
        people.push_back(tmp);
    }
    int count;
    
    for(int i=0; i<n; i++)
    {
        count = 1;
        for(int j=0; j<n; j++)
        {
            if(i == j) continue;
            if(people[i].height < people[j].height && people[i].weight < people[j].weight) count++;
        }
        cout << count << " ";
    }
}
