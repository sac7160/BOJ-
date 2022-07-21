//1918번

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int isp(char x)    //In Stack Prioirity
{
	int isp = 0;
	switch (x)
	{
	    case '(':
	    case ')': 
			isp = 3; 
			break;
    	case '*':
	    case '/': 
			isp = 1;
			break;
		case '+':
		case '-':
			isp = 2;
	}
	return isp;
}

int icp(char x)    //In Coming Prioirity
{
	int icp = 0;
	switch (x)
	{
	case '(':
	case ')':
		icp = 0;
		break;
	case '*':
	case '/':
		icp = 1;
		break;
	case '+':
	case '-':
		icp = 2;
	}
	return icp;
}

int main()
{
	char* enter = new char[101];
	vector<char>ans;
	stack<char> tmp;   //icp 가 isp보다 작을때 push
	
	cin >> enter;
	for (int i = 0; enter[i]!='\0'; i++)
	{
		if (enter[i] != '+' && enter[i] != '-' && enter[i] != '*' && enter[i] != '/' && enter[i] != '(' && enter[i] != ')')
			ans.push_back(enter[i]);    //피연산자인 경우
		else    //연산자인 경우
		{
			if (tmp.empty() || isp(tmp.top()) > icp(enter[i]))
			{
				tmp.push(enter[i]);

				if (tmp.top() == ')')
				{
					tmp.pop();
					while (tmp.top() != '(')
					{
						ans.push_back(tmp.top());
						tmp.pop();
					}
					tmp.pop();
				}
			}
			else
			{
				while (!tmp.empty()&&icp(enter[i]) >= isp(tmp.top()))
				{
					
					ans.push_back(tmp.top());
					tmp.pop();
				}

				tmp.push(enter[i]);
			}
		}
	}
	while (!tmp.empty())
	{
		if (tmp.top() == '(' || tmp.top() == ')')
		{
			tmp.pop();
			continue;
		}
		ans.push_back(tmp.top());
		tmp.pop();
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
	}

	delete[] enter;
	return 0;
}

