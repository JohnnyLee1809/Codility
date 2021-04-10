#include <iostream>
using namespace std;

#include <vector>

void printvec(vector<int> &A)
{
	for(auto &i : A)
		cout << i << " ";
	cout << endl;
}


/*** method 2 score:100
https://app.codility.com/demo/results/trainingA2QMUE-TM7/
***/
int solution(vector<int> &A, vector<int> &B, vector<int> &C)
{
	int N = A.size();
	int M = C.size();
	printvec(A);
	printvec(B);
	//printvec(C);
	
	int beg = 1;
	int end = M;
	// if nailing fail return -1
	int res = -1;
	
	while (beg <= end)
	{
		int mid = (beg + end)/2;
		// A,B,C is an integer within the range [1...2*M]
		vector<int> sum(2*M+1, 0);
		
		cout << "beg = " << beg << " end = "<<end <<endl;
		int i = 0;
		// calculate the nail position only use mid number of nail
		for(i = 0; i < mid; i++){
			sum[C[i]]++;
		}
		printvec(sum);
		// calculate the nail presum
		for(i = 1; i <= 2*M; i++){
			sum[i] += sum[i-1];
		}
		
		
		bool failed = false;
		for(i = 0; i < N; i++){
			// if there is no nail between B[i] and A[i]-1 then nailing failed
			if(sum[B[i]] == sum[A[i]-1]){
				failed = true;
			}
		}
		
		// if failed use more nails
		if(failed){
			beg = mid+1;
		}else{
			end = mid-1;
			res = mid;
		}
	}
	return res;
}



int main() {
	vector<int> A1 = {1,4,5,8};
	vector<int> B1 = {4,5,9,10};
	vector<int> C1 = {4,6,7,10,2};
	
	cout << solution(A1, B1, C1) << endl;

    system("pause");
    return 0;
}
