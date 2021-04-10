#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*** method 1  score:62 Correctness:100, Performace:20
https://app.codility.com/demo/results/training6F8WPF-G9H/

int solution(int N, int M)
{
	vector<int> X(N, 0);
	int i = 0;
	int count = 0;
	
	while(X[i] == 0) 
	{
		cout << i << " " << X[i] << endl;
        X[i] = 1;
        i = (i + M) % N;            
        count++;
        
	}
	return count;
}
***/
/*** method 2 score: 100
https://app.codility.com/c/close/training96VYCE-B9V/?final_task_completed=1
***/

int gcd (int a, int b)
{
	if(a % b == 0) 
		return b;
	return gcd(b, a%b);
}

int solution(int N, int M)
{
	return N/gcd(N,M);
}


int main() {
	int N1 = 10, M1 = 4;
	
	cout << solution(N1, M1) << endl;
	

    system("pause");
    return 0;
}