#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*** method 2  score:100
https://app.codility.com/demo/results/training85H8XC-FSW/
***/

int solution(vector<int> &A)
{
	int N = A.size();
	vector<int> scores(N,INT16_MIN);
	scores[0] = A[0];
	
	for(int pos = 1; pos < N; pos++)
	{
		// calculate the situation of step == 1  
		scores[pos] = scores[pos-1]; 
		
		for(int step = 2; step <= 6; step++)
		{
			cout << "pos = " << pos <<" step = " << step;
			cout << " scores[pos]= " << scores[pos] <<" A[pos] = " << A[pos] <<endl;
			if(pos >= step)
				scores[pos] = max(scores[pos], scores[pos-step]);
			else
				break;
		}
		scores[pos] += A[pos];
	}
	
	return scores[N-1];
}


int main(void)
{
    vector<int> A = {1, -2, 0, 9, -1, -2};
    cout << solution(A) << endl; //8

    system("pause");
    return 0;
}