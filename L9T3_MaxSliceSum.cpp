#include <iostream>
#include <vector>

using namespace std;
/*** method 1 scord:100
 * https://app.codility.com/demo/results/trainingYXB522-RTR/
***/
int solution(vector<int> &A)
{
    int tmp = 0, max_slice = INT32_MIN;

    if (A.empty()) 
        return 0;
        
    for (size_t i = 0; i < A.size(); i++)
    {
        if(tmp + A[i] > A[i])
            tmp += A[i];
        else
            tmp = A[i];
        

        if (tmp > max_slice)
            max_slice = tmp;
        }

    return max_slice;
}



int main(void)
{

    vector<int> A1 = {3, 2, -6, 4, 0};
    vector<int> A2 = {-10};

    cout << solution(A1) << endl;
    cout << solution(A2) << endl;
    

    system("pause");
    return 0;
}