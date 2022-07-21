//15889번

#include <iostream>
#include <vector>

int main()
{
	
	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> pos;

	int n;
	int maxLength=0;

	cin >> n;
	int enter;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		pos.push_back(enter);
	}

	for (int i = 0; i < n - 1; i++)
	{
		cin >> enter;
		if(maxLength<enter+pos[i]) maxLength = enter + pos[i];

		if (pos[i + 1] > maxLength)
		{
			cout << "엄마 나 전역 늦어질 것 같아";
			return 0;
		}
		
	}
	cout << "권병장님, 중대장님이 찾으십니다";

}