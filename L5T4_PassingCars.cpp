#include <iostream>
#include <vector>

using namespace std;
/*** method 1 score 100
https://app.codility.com/demo/results/training6NV68B-DMU/

int solution(vector<int> &A)
{
	int N = A.size();
	vector<int> sum(N,0);
	
	sum[0] = A[0];
	
	for(size_t i = 0; i<N; i++)
	{
		sum[i] = sum[i-1] + A[i];	
	}
    
	if(sum[N-1] == 0)
        return 0;

	unsigned long pass_car = 0;
	
	for(int i = N-1; i>=0; i--)
	{
		if(A[i] == 0)
			pass_car += (sum[N-1] - sum[i]);
		
		if(pass_car > 1000000000)
			return -1;
	}

	return pass_car;
}
***/
/*** method 2 score:100
https://app.codility.com/demo/results/trainingWYM2ET-GHP/
***/
int solution(vector<int> &A)
{
	int N = A.size();
	unsigned long pass_car_pair = 0;
	unsigned long east_car = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(A[i] == 0)
			east_car++;
		else
			pass_car_pair += east_car;
	}
	
	if(pass_car_pair > 1000000000)
		return -1;

	return pass_car_pair;
}


int main(void)
{
    vector<int> t1 = {0, 1, 0, 1, 1};
    vector<int> t2 = {1};
    vector<int> t3 = {1, 0};
    cout << solution(t1);   //5
    cout << solution(t2); // 0
    cout << solution(t3); // 0   Notice minus

    system("pause");
    return 0;
}