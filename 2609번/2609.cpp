//2609번
#include <iostream>

int main()
{
	using namespace std;

	int enter_x, enter_y;
	int x,y;
	int ans;

	cin >> enter_x >> enter_y;
	
	x = enter_x;
	y = enter_y;

	int r = x % y;

	while (true)
	{
		if (r == 0)
		{
			ans = y;
			break;
		}
		else
		{
			x = y;
			y = r;
			r = x % y;
		}
	}
	cout << ans << '\n' << enter_x*enter_y/ans;

}
