#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*** method 1 score:100
https://app.codility.com/demo/results/trainingNBXA85-5U4/
***/

int solution(vector<int> &A)
{
	int N = A.size();
	vector<int> sum(N,0);
	
	for(auto &i : A)
		cout << i <<" ";
	cout << endl;
	
	sum[0] = A[0];
	for(size_t i = 0; i<N; i++)
	{
		sum[i] = sum[i-1] + A[i];	
	}
	
	for(auto &i : sum)
		cout << i <<" ";
	cout << endl;    
	
	int min = INT16_MAX;
	int tmp = INT16_MAX;
	for(int i = 1; i < N; i++)
	{
		tmp = abs(sum[N-1] - 2*sum[i-1]);
	
		if(tmp < min)
			min = tmp;
	}

	return min;
}

int main()
{
	vector<int> A = {3,1,2,4,3};
	cout<<solution(A)<<endl; //1

    system("pause");
    return 0;
}
