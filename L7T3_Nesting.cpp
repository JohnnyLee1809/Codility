#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <stack>
/***method 1 score:100
 * https://app.codility.com/demo/results/trainingPP3D6E-TWY/
***/

int solution(string &S)
{
    stack<char> S_stack;

    if(S.empty())
        return 1;
    
    for(size_t i = 0; i<S.length(); i++)
	{
        
        if(S[i] == '(')
            S_stack.push(S[i]);
        
        if(S[i] == ')')
        {
            if(S_stack.empty())
                return 0;
            else
                S_stack.pop();
        }
    }

    if(S_stack.empty())
        return 1;
    else
        return 0;
}

int main(void)
{
    string S1 = "(()(())())";
    string S2 = "())";
    cout << solution(S1) << endl;
    cout << solution(S2) << endl;

    system("pause");
    return 0;
}