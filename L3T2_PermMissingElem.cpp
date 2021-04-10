#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include <set>
/*** method 1 score:100
 * https://app.codility.com/demo/results/trainingS36222-M73/
 ***/

int solution(vector<int> &A) {
    unsigned long N = A.size() + 1;
    unsigned long total = (N+1)*N/2;

    for (auto &i : A)
    {
        total -= i;
    }   
    return total;
}

int main() {
	
	vector<int> A1 = {2, 3, 1, 5};
	cout << solution(A1) << endl;   //4

    system("pause");	
	return 0;
}