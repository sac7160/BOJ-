//1931번
#include <iostream>
#include <vector>
#include <algorithm>

class Class
{
public:
	int startTime;
	int endTime;
};

bool compare(Class a, Class b)
{
	if (a.endTime == b.endTime)
	{
		return a.startTime < b.startTime;
	}
	return a.endTime < b.endTime;
}

int main()
{
	using namespace std;

	int n;
	vector<Class> classes;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		Class tmp;
		cin >> tmp.startTime >> tmp.endTime;
		classes.push_back(tmp);
	}

	sort(classes.begin(), classes.end(), compare);

	int count = 1;
	int index = 0;

	for (int i = 1; i < classes.size(); i++)
	{
		if (classes[i].startTime >= classes[index].endTime)
		{
			count++;
			index = i;
		}
	}
	cout << count;
}

