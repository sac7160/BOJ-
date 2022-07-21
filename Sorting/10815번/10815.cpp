//10814번

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	using namespace std;

	vector<int>n_array;
	vector<int>m_array;

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int enter;
		cin >> enter;
		n_array.push_back(enter);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int enter;
		cin >> enter;
		m_array.push_back(enter);
	}

	sort(n_array.begin(), n_array.end());
	for (int i = 0; i < m; i++)
	{
		int m_element = m_array[i];
		if (binary_search(n_array.begin(), n_array.end(), m_element)) cout << 1 << " ";
		else cout << 0 << " ";
	}

}