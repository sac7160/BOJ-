//1755번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
class Number
{
public:
	int num;
	string name;
};
string read(int a)
{
	if (a == 9) return "nine";
	else if (a == 8) return "eight";
	else if (a == 7) return "seven";
	else if (a == 6) return "six";
	else if (a == 5) return "five";
	else if (a == 4) return "four";
	else if (a == 3) return "three";
	else if (a == 2) return "two";
	else if (a == 1) return "one";
	else if (a == 0) return "zero";
}

bool compare(Number a, Number b) {
	return a.name < b.name;
}

int main()
{
	int min,max;
	cin >> min >> max;
	vector<Number>nums;

	for (int i = min; i <= max; i++)
	{
		Number x;
		if (i < 10) x.name = read(i);
		else {
			x.name = read(i / 10) + read(i % 10);
		}
		x.num = i;
			nums.push_back(x);
	}

	sort(nums.begin(), nums.end(), compare);
	
	for (int i = 0; i < max - min + 1; i++)
	{
		cout << nums[i].num << " ";
		if ((i + 1) % 10 == 0) cout << '\n';
	}
}

