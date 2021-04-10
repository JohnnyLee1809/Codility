#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <set>
/*** method 1 score = 100
https://app.codility.com/demo/results/trainingC578VZ-SPJ/
***/
int solution(vector<int> &A)
{
	int N = A.size();
	vector<int> sums(N,0);
	
	for(auto &i : A)
		cout << i <<" ";
	cout <<endl;
	
	sums[0] = A[0];
	
	for(size_t i = 1; i < N; i++)
	{
		sums[i] = A[i]+sums[i-1];	
	}
	
	for(auto &i : sums)
		cout << i <<" ";
	cout <<endl;

	int start = 0;
	int end = 1;
	int min_start = start;
	double min_avg = double(sums[end] - sums[start] + A[start]) / (end - start + 1);

	for (size_t i = 1; i < A.size(); i++) {
		double avg = double(sums[i] - sums[start] + A[start]) / (i - start + 1);
		
		if (avg < min_avg) {
			min_avg = avg;
			min_start = start;
		}
        cout <<"start ="<<start<<" i =" << i <<" avg ="<< avg <<" min_avg ="<<min_avg<<" min_start ="<<min_start <<endl;
		
		if (A[i] < min_avg) {
            start = i;
        }
    }

return min_start;
}



int main(void)
{
    vector<int> t1 = {4, 2, 2, 5, 1, 5, 8};
    cout << solution(t1) << endl;
    system("pause");
    return 0;
}