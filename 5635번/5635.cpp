//5635번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class student
{
public:
	string name;
	int day;
	int month;
	int year;
};
bool compare(student a, student b)
{
	if (a.year != b.year) return a.year < b.year;
	else if (a.month != b.month) return a.month < b.month;
	else return a.day < b.day;
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
		x.day = enter;
		cin >> enter;
		x.month = enter;
		cin >> enter;
		x.year = enter;
		students.push_back(x);
	}

	sort(students.begin(), students.end(), compare);
	
	cout <<  students[students.size() - 1].name << '\n' << students[0].name  ;
}