#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*** method 1 score:100
 * https://app.codility.com/demo/results/training8PD65H-TM8/
***/

int solution(vector<int> &A, vector<int> &B)
{
    int N = A.size();
    int count = 1;
    int end = B[0];

    if(N == 0)
        return 0;

    for (int i = 1; i < N; i++)
    {
        if(A[i] > end)
        {
            count++;
            end = B[i];
        }
    }
    return count;
}


int main(void)
{
    vector<int> A1 = {1, 3, 7, 9, 9};
    vector<int> B1 = {5, 6, 8, 9, 10};

    cout << solution(A1, B1) << endl;


    system("pause");
    return 0;
}