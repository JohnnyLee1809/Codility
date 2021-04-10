#include <iostream>
#include <vector>
#include <set>

using namespace std;


/*** Method 1 score:100
https://app.codility.com/demo/results/trainingXKQF7Q-69G/
***/

int solution(vector<int> &A)
{
	int N = A.size();
	int max_num = 0;
	set<int> nums;
	
	for(auto &i : A)
		cout << i <<" ";
	cout <<endl;
	
	for(size_t i = 0; i < N; i++)
	{
		nums.insert(A[i]);
		max_num = max(max_num, A[i]);
	}

	for(auto &i : nums)
		cout << i <<" ";
	cout <<endl;
	
	cout <<max_num <<endl;
	
	if(nums.size() != max_num || nums.size()!= N)
		return 0;
	else 
		return 1;
}



int main(void){
    vector<int> t1 = {4, 1, 3, 2};
    vector<int> t2 = {4, 1, 3};
    vector<int> t3 = {9, 5, 7, 3, 2, 7, 3, 1, 10, 8};
    vector<int> t4 = {1, 1};

    cout << solution(t1) << endl;
    cout << solution(t2) << endl;
    cout << solution(t3) << endl;

    system("pause");
}