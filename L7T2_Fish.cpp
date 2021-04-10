#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*** method 2 score:100
https://app.codility.com/demo/results/trainingEN79C9-DPX/
***/

#include <stack>

int solution(vector<int> &A, vector<int> &B)
{
	stack<int> downstream;
	int alive_fish = 0;
	for(size_t i = 0; i<A.size(); i++)
	{
		if(B[i] == 1)
			downstream.push(A[i]);
		
		while(!downstream.empty()){
			if(downstream.top() < A[i])
				downstream.pop();
			else
				break;
		}
		if (downstream.empty())
			alive_fish++;
	}
	
	alive_fish += downstream.size();
	return alive_fish;
}

int main(void)
{
    vector<int> A = {4, 3, 2, 1, 5};
    vector<int> B = {0, 1, 0, 0, 0};

    cout << solution(A, B) << endl;
    system("pause");
    return 0;
}