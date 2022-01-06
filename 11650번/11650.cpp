//11650번

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Pair
{
public:
	int x;
	int y;
};

bool compare(Pair a, Pair b)
{
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}


int main()
{
	vector<Pair> pairs;
	int n;
	cin >> n;
	

	for (int i = 0; i < n; i++)
	{
		Pair newPair;
		int x,y;
		cin >> x >> y;
		newPair.x = x;
		newPair.y = y;
		pairs.push_back(newPair);
	
	}

    sort(pairs.begin(), pairs.end(), compare);

	

	for (int i= 0; i < pairs.size(); i++)
	{
		cout << pairs[i].x << " " << pairs[i].y << '\n';
	}
}