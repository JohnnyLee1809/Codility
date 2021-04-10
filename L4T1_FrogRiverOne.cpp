#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*** method 1 score:100
https://app.codility.com/demo/results/trainingX8VKU9-HCV/
***/

#include <set>

int solution(int X, vector<int> &A) {
    set<int> s;
    for (size_t i = 0; i< A.size(); i++)
    {
        s.insert(A[i]);
        if(s.size() == X)
            return i;
    }
    return -1;
}

int main(void)
{
    int X = 5;
    vector<int> A = {1, 3, 1, 4, 2, 3, 5, 4};
    cout << solution(X, A) << endl; // 6

    system("pause");
    return 0;
}