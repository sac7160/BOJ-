//2822번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class ScoreIndex
{
public:
	int score;
	int index;
};
bool compare(ScoreIndex a, ScoreIndex b)
{
	return a.score > b.score;
}

int main()
{
	vector<ScoreIndex>score;
	int enter;

	for (int i = 0; i < 8; i++)
	{
		cin >> enter;
		ScoreIndex x;
		x.score = enter;
		x.index = i;
		score.push_back(x);
	}
	sort(score.begin(), score.end(), compare);
	int sum = 0;
	vector<int>index;

	for (int i = 0; i < 5; i++)
	{
		sum += score[i].score;
		index.push_back(score[i].index);
	}
	sort(index.begin(), index.end());

	cout << sum << '\n';
	for (int i = 0; i < 5; i++)
	{
		cout << index[i]+1 << " ";
	}
}