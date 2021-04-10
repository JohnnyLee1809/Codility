#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printvec(const vector<int> &A)
{
	for(auto &i : A)
		cout << i <<" ";
	cout <<endl;
}

/*** method 1 score:100
 * https://app.codility.com/demo/results/trainingMDG6AR-E3G/
***/

void swap(int &a, int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}

vector<int> solution(vector<int> &A, int K) {
    if (A.empty())
        return A;
    
    int N = A.size();
    int start = 0;

    while(N && (K %= N))
    {
        for (int i = 0; i < K; i++)
            swap(A[i+start], A[N-K+i+start]);
        
        N -= K;
        start += K;
    }
    return A;
}

int main(void)
{
    vector<int> A1 = {3, 8, 9, 7, 6};
    int K1 = 3;
    vector<int> A2 = {0, 0, 0};
    int K2 = 1;  
    vector<int> A3 = {1, 2, 3, 4};
    int K3 = 4;

    printvec(solution(A1, K1));
    printvec(solution(A2, K2));
    printvec(solution(A3, K3));

    system("pause");
    return 0;
}