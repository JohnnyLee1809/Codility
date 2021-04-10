#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/***method 1 score: 100
https://app.codility.com/demo/results/training33QHD3-26V/
***/

void printvec(const vector<int> &A)
{
	for(auto &i : A)
		cout << i <<" ";
	cout <<endl;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
	int M = P.size();
	vector<int> primefactor_min(N+1, 0);
	vector<int> semiprime_count(N+1, 0);
	vector<int> res(M, 0);
	// calculate the minimum prime factor
	for(int i = 2; i*i <= N; i++)
	{
		if(primefactor_min[i])
			continue;
		
		int k = i*i;
		while(k <= N)
		{
			if(!primefactor_min[k])
				primefactor_min[k] = i;
			k+=i;
		}
	}
	for(int i = 4; i<=N; i++)
	{
		// if primefactor_min[i] is zero, i is prime.
		if(!primefactor_min[i]){
			semiprime_count[i] = semiprime_count[i-1];
		}else{
			// if primefactor_min[i/primefactor_min[i]] is zero, i is semiprime.
			if(!primefactor_min[i/primefactor_min[i]]){
				semiprime_count[i] = semiprime_count[i-1]+1;
			// esle i is other composite number.
			}else{
				semiprime_count[i] = semiprime_count[i-1];
			}
		}
	}
	
	for(int i = 0; i < M; i++)
	{
		res[i] = semiprime_count[Q[i]] - semiprime_count[P[i]-1];
	}
	
	return res;
}

int main() {
	// int N1 = 10;
	// vector<int> P1 = {1, 4, 7};
	// vector<int> Q1 = {10, 8, 9};
	int N1 = 26;
	vector<int> P1 = {1, 4, 16};
	vector<int> Q1 = {26, 10, 20};
	
	printvec(solution(N1, P1, Q1));

    system("pause");
    return 0;
}