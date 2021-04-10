#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*** method 1 score:100
https://app.codility.com/demo/results/trainingV9EE9Y-UY4/
***/

#include <stack>

int solution(vector<int> &A)
{
	stack<int> A_stack,A_group;
	int len = A.size();
	int leader = -1;
	int leader_num = 0;
	int counts = 0;
	int ans = 0;
	
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
		return 0;
    else
        leader = A_stack.top();

	for(size_t i=0; i<len; i++)
	{
		if(leader == A[i])
			leader_num++;
	}

    if(leader_num < len/2)
        return 0;

	for(size_t i=0; i< len-1; i++)
	{
		int l_num = 0, r_num = 0;
		
		if(leader == A[i])
			counts ++;
		l_num = (i+1)/2;
		r_num = (len-(i+1))/2;

		if(counts > l_num && (leader_num-counts) > r_num)
			ans ++;
	}
	return ans;
}

 
int main() {

	vector<int> A1 = {4, 3, 4, 4, 4, 2};
    vector<int> A2 = {1, 2};

    cout << solution(A1) << endl;
    cout << solution(A2) << endl;

    system("pause");
    return 0;
}