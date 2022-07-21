//18115번

#include <iostream>
#include <deque>
#include <vector>

int main()
{
	using namespace std;

	int n,enter;
	vector<int>skill;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		skill.push_back(enter);
	}

	int input = 1;
	deque<int>card;

	for (int i = 1;i <= n; i++)
	{
		if (skill[n-i] == 1)
		{
			card.push_front(input++);
		}
		else if (skill[n-i] == 2)
		{
			int tmp = card.front();
			card.pop_front();
			card.push_front(input++);
			card.push_front(tmp);
		}
		else if (skill[n-i] == 3)
		{
			card.push_back(input++);
		}
	}

	for (int i = 0; i < card.size(); i++)
	{
		cout << card[i] << " ";
	}
}