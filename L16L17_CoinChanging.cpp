#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print2dvec(int N, int K, const vector<vector<int>> &A)
{
	for (int i = 0; i <N; i++)
	{
		for (int j = 0; j <K; j++)
			cout<< A[i][j] << " ";
		cout<<endl;
	}
}

// Goal: Return the minimum number of coins
int solution_greedy(const int &K, const vector<int> &A)
{
    int N = A.size();
    int count = 0;
    int amount = K;

    for (int i = N-1; i >= 0; i--)
    {
        count += amount / A[i];
        amount %= A[i];
    }
    return count;
}

// dp1 Time O(N*K), Space(N*K)
int solution_dp1(const int &K, const vector<int> &A)
{
    int N = A.size(); 
    vector<vector<int>> dp(N,vector<int>(K+1, 0));
    print2dvec(N, K+1, dp);
    
    // i is the coins value
    for (int i = 1; i < N; i++)
    {
        // j is the amount
        for (int j = 0; j < A[i - 1]; j++)
            dp[i][j] = dp[i - 1][j];
        for (int j = A[i - 1]; j < K; j++)
            dp[i][j] = min(dp[i][j - A[i-1]], dp[i - 1][j]);
    }
    print2dvec(N, K+1, dp);

    return dp[N-1][K-1];
}

int main(void)
{
    // K is the amount, A is the values of coins
    // When coins value are not coprime, it can solves by Greedy Algorithm
    int K1 = 6;
    vector<int> A1 = {1, 3, 4};
    int K2 = 123;
    vector<int> A2 = {1, 5, 10, 20, 50};
    cout << solution_greedy(K1, A1) << endl;
    cout << solution_greedy(K2, A2) << endl;
    solution_dp1(K1, A1);


    system("pause");
    return 0;
}