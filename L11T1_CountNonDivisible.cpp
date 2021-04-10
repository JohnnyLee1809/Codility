#include <iostream>
//#include <string>
#include <vector>
//#include <algorithm>

using namespace std;
void printvec(vector<int> &A)
{
    for(auto &i: A)
        cout << i << " ";
    cout << endl;
}
/*** method 1 score: 66
 * https://app.codility.com/demo/results/trainingYG7KC9-C2X/
 * 
vector<int> solution(vector<int> &A)
{
    int N = A.size();
    vector<int> res(N, 0);
    for (int i = 0; i < N;i++)
    {
        int non_dividors = 0;
        for (int j = 0; j < N;j++)
        {
            if(j == i)
                continue;
            if(A[i]%A[j] != 0)
                non_dividors++;
        }
        res[i] = non_dividors;
    }

    return res;
}
***/
#include <math.h>

/*** method 2 score:100
 * https://app.codility.com/demo/results/trainingK62HXD-WWD/
***/

vector<int> solution(vector<int> &A)
{
    int max_num = 0;
    for(auto &i : A)
        max_num = max(max_num, i);
    int N = A.size();
    printvec(A);
    vector<int> nums_count(max_num+1, 0);
    for (int i = 0; i < N; i++)
    {
        nums_count[A[i]]++;
    }
    printvec(nums_count);

    vector<int> divisor_count(N, 0);
    for (int i = 0; i < N; i++)
    {
        int divisor = 0;
        for (int j = 1; j * j <= A[i]; j++)
        {
            // j is the divisor of A[i]
            if(A[i] % j == 0)   
            {
                cout << "\tdivisor = " << divisor << "\tnums_count[j] = " << nums_count[j];
                divisor += nums_count[j]; 
                // if A[i]/j == j then no need to add divisor
                // A[i]/j is the another divisor of A[i]
                if(A[i]/j != j)
                {
                    cout << "\tdivisor = " << divisor << "\tnums_count[A[i]/j] = " << nums_count[A[i]/j];
                    // cout << "i = " << i << "\tj = " << j;
                    // cout << "\tA[i] = " << A[i] << "\tnums_count[j] = " << nums_count[j] << endl;
                    divisor += nums_count[A[i]/j];            
                }        
            }
        }   
        divisor_count[i] = N - divisor;
    }
    return divisor_count;
}

int main(void)
{

    vector<int> A1 = {3, 1, 2, 3, 6};
    vector<int> AnsA1 = solution(A1);

    printvec(AnsA1);

    system("pause");
    return 0;
}