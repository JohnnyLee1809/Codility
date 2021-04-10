#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include <stack>
/*** method 1 score: 100
https://app.codility.com/demo/results/training3XBVQF-F8T/
***/

int solution(vector<int> &A)
{
	stack<int> A_stack;
	int len = A.size();
	int leader = -1;
	int counts = 0;
	int ans = 0;
	
    if(len == 0)
        return -1;

	for(size_t i=0; i<len; i++)
	{
		if(A_stack.empty()){
			A_stack.push(A[i]);
		}else{
			if(A_stack.top() == A[i])
			{
				A_stack.push(A[i]);
			}else{
				A_stack.pop();
			}
		}
	}
	
	if(A_stack.empty())
		return -1;
    else
        leader = A_stack.top();
	
	for(size_t i=0; i<len; i++)
	{
		if(A[i] == leader){
			counts++;
			ans = i;
		}
	}
	
	if(counts > len/2)
		return ans;
	else
		return -1;
}



int main() {

	vector<int> A = {3, 4, 3, 2, 3, -1, 3, 3};
	
	cout << solution(A) << endl;

    system("pause");
    return 0;
}