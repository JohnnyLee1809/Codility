#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*** method 1 score: 100
https://app.codility.com/demo/results/training66JJ8M-JJY/
***/
int solution(vector<int> &A)
{
	int counter = 0;
    long len1 = 0, len2 = 0;
	
	if(A.size() < 3)
		return 0;

	sort(A.begin(), A.end());
	
	for(size_t i = A.size()-1; i > 1; i--)
	{
		len1 = (long)A[i];
		len2 = (long)A[i-1]+A[i-2];
		if(len2 > len1)
			return 1;
	}
	return counter;
}

int main() {

	vector<int> t1 ={10, 2, 5, 1, 8, 20};
	vector<int> t2 ={10, 50, 5, 1};
	vector<int> t3 ={1, 1, 1, 1, 5, 5, 5};
	vector<int> t4 ={3, INT16_MAX, INT16_MAX};
	cout << solution(t1) <<endl;
	cout << solution(t2) <<endl;
	cout << solution(t3) <<endl;
	cout << solution(t4) <<endl;

    system("pause");
    return 0;
}