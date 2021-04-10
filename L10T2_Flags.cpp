#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*** method 1 score:100 O(N)
https://app.codility.com/demo/results/training8Y5NYA-4XD/
***/

#include <math.h>

int solution(vector<int> &A)
{
	int N = A.size();
	vector<int> peaks;
	
	for(auto &i:A)
		cout << i << " ";
	cout << endl;
	
	for(int i = 1; i < N-1; i++)
	{
		if(A[i] > A[i-1] && A[i] > A[i+1])
			peaks.push_back(i);
		
	}
	if(peaks.size() < 2)
		return peaks.size();
		
	for(auto &i:peaks)
		cout << i << " ";
	cout << endl;
	
	
	int root = sqrt(peaks[peaks.size()-1] - peaks[0]);
	cout << "root = " <<root <<endl;
	
	for(int i = root+1; i>0; i--)
	{
		int distance = 0;
		int flags = 1;
		
		for(int j = 0; j<peaks.size()-1; j++)
		{
			int gap = peaks[j+1] - peaks[j];
			if((gap+distance) >= i){
				flags ++;
				distance = 0;
			}else
				distance += gap;
			cout << "j = " << j << " gap = " <<gap <<" flags = "<<flags<<endl; 
			if(flags == i)
				return flags;
		}
	}
	return 1;
}


int main() {
	
	vector<int> A1 = {1,5,3,4,3,4,1,2,3,4,6,2};
	vector<int> A2 = {0,0,0,0,0,1,0,1,0,1};
	cout << solution(A1) << endl;//3
	cout << solution(A2) << endl;//2
	

    system("pause");
    return 0;
}