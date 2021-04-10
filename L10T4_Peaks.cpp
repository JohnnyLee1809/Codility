#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

/*** method 2 score:63 Correctness:100, Performace:20
https://app.codility.com/demo/results/training7EB2GJ-BS3/

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A)
{
	int N = A.size();
	vector<int> peaks(N, 0);
	bool peak_flag = true;
	int peak_num = 0;
	
	
	if(N < 3)
		return 0;
		
	for(auto &i : A)
		cout<<i<<" ";
	cout<<endl;	
	
	for(size_t i=1; i<N; i++)
	{
		if(A[i] > A[i-1] && A[i] > A[i+1])
			peaks[i] = peaks[i-1]+1;
		else
			peaks[i] = peaks[i-1];
	}
	
	if(peaks[N-1] == 0)
		return 0;
	
	for(auto &i : peaks)
		cout<<i<<" ";
	cout<<endl;
	
	
	for(size_t k=3; k<N+1; k++)
	{
		if(N%k == 0)
		{
			for(int i = k; i!= N; i+=k)
			{
				cout<< "k =" << k <<"i =" << i <<"peaks[i+1] ="<<peaks[i+1]<< "peak_num =" <<peak_num <<endl;

				peak_num++;
				if(peaks[i-1] != peak_num){
					peak_flag = false;
					break;
				}
				
			}
			
			if(peak_flag)
				return N/k;
		}
		peak_num = 0;
		peak_flag = true;
	}
		
			
	return 1;
}
***/

/***methode 3 score:100 O(N * log(log(N)))
https://app.codility.com/demo/results/trainingK5WE4K-MVV/
***/

int solution(vector<int> &A)
{
	int N = A.size();
	vector<int> peaks(N, 0);
	int peak_num = 0;

	if(N < 3)
		return 0;
		
	for(int i = 1; i < N-1; i++)
	{
		if(A[i] > A[i-1] && A[i] > A[i+1]){
			peaks[i] = 1;
			peak_num++;
		}
	}
	
	if(peak_num < 2)
		return peak_num;
	
	int groups = 0;
	bool peak_flag = true;	
	
	for(int i = peak_num; i >= 0; i--)
	{
		if(N%i != 0)
			continue;

		groups = N/i;
		
		for(int k = 0; k < N; k+=groups)
		{
			peak_flag = false;
			for(int j = k; j<k+groups; j++)
			{
				if(peaks[j] != 0){
					peak_flag = true;
				}
			}		
			if(peak_flag == false)
				break;
		}
		if(peak_flag == true)
			return i;
	}
	
	return 1;
}


int main() {
	
	vector<int> A1 = {1,2,3,4,3,4,1,2,3,4,6,2};
	vector<int> A2 = {0, 1, 0, 0, 1, 0, 0, 1, 0};
	cout << solution(A1) << endl;//3
	cout << solution(A2) << endl;//3
	

    system("pause");
    return 0;
}
