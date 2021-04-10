#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/***method 1 score:100
https://app.codility.com/demo/results/trainingRAYEXJ-F7A/
***/

int solution(vector<int> &A)
{
    int N = A.size();
    int res = 0;   
     
    if(N == 1)
        return A[0];

	sort(A.begin(), A.end());	
	
	for(int i = 0; i < N; i=i+2)
	{
		if(A[i] != A[i+1]){
			res = A[i];
			break;
		}
	}
	return res;
}


int main() {
	vector<int> A ={9,3,9,3,9,7,9};
	cout << solution(A) << endl;
    system("pause");
    return 0;
}