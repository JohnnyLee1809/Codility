#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*** method 1 score:100
 * https://app.codility.com/demo/results/trainingFMWJAZ-UD2/
***/

int solution(int K, vector<int> &A)
{
    int N = A.size();
    int count = 0;
    int tmp = 0;

    if(N == 0)
        return 0;

    for (int i = 0; i < N; i++)
    {
        cout << "i = " << i << " tmp = " << tmp << " count = " << count << endl;
        if (tmp >= K){
            count++;
            tmp = A[i];
        }else{
            tmp += A[i];
        }
    }

    if (tmp >= K)
        count++;

    return count;
}


int main(void)
{
    int K1 = 4;
    vector<int> A1 = {1, 2, 3, 4, 1, 1, 3};
    cout << solution(K1, A1) << endl;


    system("pause");
    return 0;
}