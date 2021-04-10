#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;

/***method 1 score:100
 * https://app.codility.com/demo/results/training49T3R2-TPK/
 ***/

#include <set>
int solution(vector<int> &A)
{
    if(A.empty())
        return 0;
        
	set<int> nums;
	for(size_t i = 0; i< A.size(); i++)
	{
		nums.insert(A[i]);
	}
	return nums.size();
}


int main() {
	vector<int> t1 = {2, 1, 1, 2, 3, 1};
	cout << solution(t1) << endl; // 3
	
    system("pause");
    return 0;
}