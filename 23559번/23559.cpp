//23559번

#include <iostream>
#include <algorithm>
#include <vector>

class meal
{
public:
	int a;
	int b;
	int sub;
};

bool compare(meal a, meal b)
{
	return a.sub > b.sub;
}

int main()
{
	using namespace std;
	int n, x,enter;

	cin >> n >> x;
	
	vector<meal>meals;

	for (int i = 0; i < n; i++)
	{
		meal tmp;
		cin >> enter;
		tmp.a = enter;
		cin >> enter;
		tmp.b = enter;
		tmp.sub = tmp.a - tmp.b;
		meals.push_back(tmp);
	}

	sort(meals.begin(), meals.end(), compare);
	
	int sum=0;
	int money = 0;

	for (int i = 0; i < n; i++)
	{
		if (meals[i].sub <= 0 || money + 1000 * (n - i - 1) + 5000 > x)
		{
			sum += meals[i].b;
			money += 1000;
		}
		else
		{
			if (money + 5000 <= x)
			{
				sum += meals[i].a;
				money += 5000;
			}
			else
			{
				sum += meals[i].b;
				money += 1000;
			}
		}
	}
	cout << sum;
}

