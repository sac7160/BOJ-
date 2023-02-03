#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

vector<string>split(string s, string div) {
    vector<string> v;
    char* c = strtok((char*)s.c_str(), div.c_str());
    while (c) {
        v.push_back(c);
        c = strtok(NULL, div.c_str());
    }
    return v;
}

int GCD(int a, int b)
{
    return b ? GCD(b, a % b) : a;
}

int main()
{
    string input;
    cin >> input;
    int num1, num2;

    vector<string> v = split(input, ":");

    num1 = stoi(v[0]);
    num2 = stoi(v[1]);

    cout << num1 / GCD(num1, num2) << ":" << num2 / GCD(num1, num2);


}
