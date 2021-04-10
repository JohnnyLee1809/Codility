#include <iostream>
using namespace std;

#include <vector>

/*** method 2 score:100
 * https://app.codility.com/demo/results/training9G6DHM-RFT/
***/

bool check_block_nums(vector<int> &A, int mid, int K)
{
	int sum = 0;
	int blocks = 1;
    for(int i = 0; i<A.size(); i++)
    {
    	if(sum + A[i] <= mid){
    		sum += A[i];
    	}else{
    		sum = A[i];
    		blocks ++;
    	}
    }
    cout <<"blocks = " <<blocks <<endl;
	if(blocks <= K)
		return true;
	else
		return false;
}

int solution(int K, int M, vector<int> &A) {
    
    int end = 0;
    int start = 0;
    
    for(int i = 0; i<A.size(); i++)
    {
        end += A[i];
        start = max(start, A[i]);
    }

	// start is the block min sum, end is the block max sum
	while (start < end)
	{
		int mid = (start+end)/2;
		cout << start << " " << end << " " << mid << endl;
		if(check_block_nums(A, mid, K))
			end = mid;      // no need to minus 1
		else
			start = mid + 1;
	}

	return start;
}
int main() {
	int K1 = 3, M1 = 5;
	vector<int> A1 = {2, 1, 5, 1, 2, 2, 2};
    int K2 = 3, M2 = 6;
	vector<int> A2 = {5, 2, 3, 4, 6};

	cout << solution(K1, M1, A1) << endl; // 6
	cout << solution(K2, M2, A2) << endl; // 7

    system("pause");
    return 0;
}
