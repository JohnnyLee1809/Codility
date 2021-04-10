#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/***method 1 score: 100 
https://app.codility.com/demo/results/trainingPG7SNF-ES4/
***/

int solution(vector<int> &A)
{
	int ans = 1, tmp = 1;
	if(A.size() > 3)
	{
		sort(A.begin(), A.end(), [](int a, int b){return a > b;});
		ans = A[0] * A[1] * A[2];
		tmp = A[0] * A[A.size()-1] * A[A.size()-2];
		if(ans < tmp)
			ans = tmp;
	}else
	{
		for (size_t i = 0; i<A.size(); i++)
			ans *= A[i];
	}
	return ans;
}


int main() {
	vector<int> t1 = {-3, 1, 2, -2, 5, 6};
	vector<int> t2 = {-5, 5, -5, 4};
	cout << solution(t1) << endl;	// 60
	cout << solution(t2) << endl;	// 125
	
    system("pause");
    return 0;
}