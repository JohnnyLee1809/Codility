#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*** method 1 score = 100  
https://app.codility.com/demo/results/trainingY66MCR-5PR/
***/

int solution(vector<int> &A)
{
	int max_profit = INT16_MIN;
	int sel_price = A[A.size()-1];
	int tmp =  A[A.size()-1];
	
	if(A.size() == 0)
		return 0;
		
	for(int i = A.size()-1; i>=0 ; i--)
	{
		if(A[i] > sel_price)
			sel_price = A[i];
		else
			tmp = sel_price - A[i];
		
		if(tmp > max_profit)
			max_profit = tmp;
	}
	return max_profit;
}

int main() {

	vector<int> A1 = {23171, 21011, 21123, 21366, 21013, 21367}; // 256
	vector<int> A2 = {0, 200000};	//200000
	vector<int> A3 = {-3, -2, -1};	// 2
	cout << solution(A1) <<endl;
	cout << solution(A2) <<endl;
	cout << solution(A3) <<endl;
	system("pause");
    return 0;
}
