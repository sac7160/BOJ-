#include <iostream>
#include <stack>
#include <string>

int main()
{
	using namespace std;

	int nums;
	cin >> nums;

	for (int i = 0; i < nums; i++)
	{
		int leftNum = 0;
		int rightNum = 0;
		stack<char> stack;

		string input;
		cin >> input;

		for (int j = 0; j < input.size(); j++)    //스택에 넣는 반복문
		{
			stack.push(input[j]);
		}

		while (leftNum <= rightNum)     //leftNum이 더 커지면 바로 NO , 다 검사했을때 다르면 no
		{
			if (stack.top() == ')') rightNum++;
			if (stack.top() == '(') leftNum++;
			stack.pop();

			if (stack.empty() && leftNum == rightNum)
			{
				cout << "YES" << endl;
				break;
			}
			if (stack.empty() && leftNum != rightNum) {    //  다 검사했는데 다름
				break;
			}
		}

		if(leftNum > rightNum || (stack.empty() && leftNum != rightNum))cout << "NO" << endl;    //
	
		while (!stack.empty()) stack.pop();
		
	}
	return 0;
	
}