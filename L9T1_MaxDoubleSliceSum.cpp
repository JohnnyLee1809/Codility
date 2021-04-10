#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*** method 1 score:53
 * https://app.codility.com/demo/results/training4JEMGB-PRZ/
 * 
int solution(vector<int> &A)
{
    int N = A.size();
    vector<int> max_l(N, INT16_MIN);
    vector<int> max_r(N, INT16_MIN);
    int max_slice = INT16_MIN;

    for (int i = 1; i < N - 2; i++)
    {
        max_l[i] = max(max_l[i - 1] + A[i], A[i]);
    }

    for(int &i :max_l)
        cout << i << " ";
    cout << endl;
   
    for (int i = N-2; i > 1; i--)
    {
        max_r[i] = max(max_r[i + 1] + A[i], A[i]);
    }
    for(int &i :max_r)
        cout << i << " ";
    cout << endl;

    max_slice = max_l[0] + max_r[2];

    for (int i = 1; i < N - 1; i++)
    {
        max_slice = max(max_slice, max_l[i - 1] + max_r[i + 1]);
    }

    return max_slice;
}
***/
/*** method 2 score : 69
 * ***https://app.codility.com/demo/results/trainingQK5A3X-8WB/


int solution(vector<int> &A)
{
    int N = A.size();
    vector<int> max_l(N, 0);
    vector<int> max_r(N, 0);
    int max_slice = INT16_MIN;

    for (int i = 1; i < N - 2; i++)
        max_l[i] = max(max_l[i - 1] + A[i], A[i]);

    for(int &i :max_l)
        cout << i << " ";
    cout << endl;
    for (int i = N-2; i > 1; i--)
        max_r[i] = max(max_r[i + 1] + A[i], A[i]);
    
    for(int &i :max_r)
        cout << i << " ";
    cout << endl;

    max_slice = max_l[0] + max_r[2];
    cout << max_slice << endl;
    for (int i = 1; i < N - 1; i++)
    {
        max_slice = max(max_slice, max_l[i - 1] + max_r[i + 1]);
        cout << max_slice << " ";
    }

    return max_slice;
}
***/
/*** method 3 score 100
https://app.codility.com/demo/results/training4ZBHF7-DCZ/
***/

int solution(vector<int> &A)
{
    int N = A.size();
    vector<int> max_l(N, 0);
    vector<int> max_r(N, 0);
    int max_slice = INT16_MIN;

    for (int i = 1; i < N; i++)
        max_l[i] = max(max_l[i - 1] + A[i], 0);

    for(int &i :max_l)
        cout << i << " ";
    cout << endl;
    for (int i = N-2; i >= 0; i--)
        max_r[i] = max(max_r[i + 1] + A[i], 0);
    
    for(int &i :max_r)
        cout << i << " ";
    cout << endl;

    for (int i = 1; i < N - 1; i++)
        max_slice = max(max_slice, max_l[i - 1] + max_r[i + 1]);
    

    return max_slice;
}

int main(void)
{
    vector<int> A1 = {3, 2, 6, -1, 4, 5, -1, 2};
    vector<int> A2 = {5, 5, 5};
    vector<int> A3 = {0, 10, -5, -2, 0};
    cout << solution(A1) << endl; // (0, 3, 6) -> 2+6+4+5 = 17
    cout << solution(A2) << endl; // return 0;
    cout << solution(A3) << endl; // return 10;
    system("pause");
    return 0;
}