#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int a[50];
	int b[50];
	bool enable[50];

	int ans = 0;


	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	for(int i=0; i<n; i++) enable[i] = true;

	sort(a,a+n);
	sort(b,b+n);

	for(int i=0; i<n; i++)
	{
		int index = 0;
		while(a[i]>b[index] && index<n-1) index++;

		while(index!=0 && (enable[index]==false || a[i] <= b[index]))index--;

		if(a[i]>b[index]&& enable[index] == true)
		{
			a[i] = 0;
			ans +=2;
			enable[index] = false;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(a[i]!=0)
		{
			for(int j =0; j<n; j++)
			{
				if(a[i] == b[j] && enable[j]==true) {
					ans += 1;
					enable[j] = false;
					break;
				}
			}
		}
	}

	cout << ans;

}
