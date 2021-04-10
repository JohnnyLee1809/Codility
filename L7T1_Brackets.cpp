#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*** method 1 score: 100 O(N)
https://app.codility.com/demo/results/trainingQTQUBD-HPT/
***/
#include <stack>

int check_item(const string &S, const int &i, 
stack<char> &A, const char &lhs, const char &rhs)
{
	if(S[i] == lhs)
	{
		if(A.top() == rhs)
		{
			A.pop();
			return 1;
		}else
			return 0;
	}
	return 1;
}

int solution(string &S)
{
    stack<char> bracket_stack;
	for(size_t i = 0; i<S.length(); i++)
	{
		int chk1, chk2, chk3;

        if(S[i] == '{' || S[i] == '[' || S[i] == '(')
        {
            bracket_stack.push(S[i]);
        }
		chk1 = check_item(S, i, bracket_stack, '}', '{');
		chk2 = check_item(S, i, bracket_stack, ']', '[');    
		chk3 = check_item(S, i, bracket_stack, ')', '(');    
        
        if (chk1 == 0 || chk2 == 0 || chk3 == 0)	return 0;
	}
	if(bracket_stack.size() == 0)
        return 1;
    else
        return 0;
}



int main() {
	string s1 = "{[()()]}";
	string s2 = "([)()]";
	cout << solution(s1) <<endl;
	cout << solution(s2) <<endl;

    system("pause");
    return 0;
}
