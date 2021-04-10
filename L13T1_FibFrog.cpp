#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/*** method 1 score 100 O(N*logn(N))
https://app.codility.com/demo/results/training93C883-BY8/
***/

void printvec(vector<int> &A)
{
	for(auto &i : A)
		cout << i << "\t";
	cout <<endl;
	
}

int solution(vector<int> &A) 
{
	// Add destination 
	int N = A.size() + 1;
	cout << "\t\t\t\t\t\t\t\t";
	printvec(A);
	
	// Calculation Fibonacci numbers
	vector<int> F ={0, 1};
	int i = 1;
	while(F[i] < N)
	{
		i++;
		F.push_back(F[i-1] + F[i-2]);
	}
	
    vector<int> min_steps(N, 0);

	for(int pos = N-1; pos > -1; pos--)
	{
		// no leaf at the position
		// Not pass when pos is zero(start position)
		if(pos > 0 && A[pos-1] == 0)
			continue;
			
		// From destination jump back and check every Fibonacci numbers as step
        for (int i = F.size() - 1; i > 0; i--)
        {
            int step_count = 0;
            int des = pos + F[i];
            
            // if jump over the destination(N) or no leaf at last position 
            if (des > N || (des < N && A[des - 1] == 0))
                continue;
			
			// calculate the step_count in the position
            if (des == N){
                step_count = 1;
            }else{
                if (min_steps[des] != 0)
                    step_count = min_steps[des] +1;
            }
 
            if (step_count != 0 && (min_steps[pos] == 0 || step_count < min_steps[pos]))
                min_steps[pos] = step_count;
                
            cout << "pos = " << pos << " i = " << i << " min_steps =\t"; 
            printvec(min_steps);
        }
    }
    
    if(min_steps[0] == 0)
        return -1;
    else
        return min_steps[0];

}
int main() {

	vector<int> A1 = {0,0,0,1,1,0,1,0,0,0,0};
	vector<int> A2 = {1};
	vector<int> A3 = {1,1,0,0,0};
	vector<int> A4 = {0,0,0};
	
	cout << solution(A1) << endl;
	cout << solution(A2) << endl;
	cout << solution(A3) << endl;
	cout << solution(A4) << endl;

    system("pause");
    return 0;
}