//10825번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class student
{
public:
	string name;
	int korean;
	int english;
	int math;
};
bool compare(student a, student b)
{
	if (a.korean != b.korean) return a.korean > b.korean;
	else if (a.english != b.english) return a.english < b.english;
	else if (a.math != b.math) return a.math > b.math;
	else return a.name < b.name;
};

int main()
{
	int enter,n;
	string enterName;
	vector<student>students;
	
	cin >> n;
	while (n--)
	{
		student x;
		cin >> enterName;
		x.name = enterName;
		cin >> enter;
		x.korean = enter;
		cin >> enter;
		x.english = enter;
		cin >> enter;
		x.math = enter;
		students.push_back(x);
	}

	sort(students.begin(), students.end(), compare);
	
	for (int i = 0; i < students.size(); i++)
	{
		cout << students[i].name << '\n';
	}
}