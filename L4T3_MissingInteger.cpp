#include <iostream>
#include <vector>
#include <set>

using namespace std;

#include <set>
/***
 * method 1 score 100
 * https://app.codility.com/demo/results/trainingAEZ32U-3SU/
 * edit A.size() to  A.size()+1 in the second for loop
***/
int solution(vector<int> &A)
{
    set<long> nums;
    for (unsigned long i = 0; i < A.size(); i++)
    {
        if (A[i] > 0)
            nums.insert(A[i]);
    }
    for (unsigned long i = 1; i < nums.size()+1; i++)
    {
        if(nums.count(i) == 0)
            return i;
    }
    return nums.size() + 1;;
}

int main(void){
    vector<int> t1 = {1, 3, 6, 4, 1, 2};
    vector<int> t2 = {1, 2, 3};
    vector<int> t3 = {-1, -3};

    cout << solution(t1) << endl;
    cout << solution(t2) << endl;
    cout << solution(t3) << endl;

    system("pause");
}