//11651번

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class Pair
{
public:
	int age;
	string name;
};

bool compare(Pair a, Pair b)
{
		return a.age < b.age;
}


int main()
{
	vector<Pair> pairs;
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		Pair newPair;
		int a;
		string b;
		cin >> a >> b;
		newPair.age = a;
		newPair.name = b;
		pairs.push_back(newPair);

	}

	stable_sort(pairs.begin(), pairs.end(), compare);



	for (int i = 0; i < pairs.size(); i++)
	{
		cout << pairs[i].age << " " << pairs[i].name << '\n';
	}

}