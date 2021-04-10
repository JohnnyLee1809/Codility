#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*** method 1 score:100
https://app.codility.com/demo/results/training7K7J4J-83B/
***/

#include <set>
int solution(vector<int> &A)
{
	set<int> num;
	for(int i = 0; i<A.size(); i++)
	{
		num.insert(abs(A[i]));
	}
	return num.size();
}

int main() {
	
	vector<int> A = {-5, -3, -1, 0, 3, 6};
	cout << solution(A) << endl;

    return 0;
}