#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*** method 1 score 100 O(Z * log(max(A) + max(B))**2)
https://app.codility.com/demo/results/training9MWV7N-BRR/
***/

int gcd (int a, int b)
{
	if(a % b == 0) 
		return b;
	return gcd(b, a%b);
}
bool check_prime_divior(int a, int b)
{
	int gcd_ab = gcd(a,b);
	int gcd_a = 0;
	int gcd_b = 0;
	
    while(gcd_a != 1) {
    	cout << a << " " << gcd_a << endl;
        gcd_a = gcd(a, gcd_ab);
        a /= gcd_a;
    }
        
    while(gcd_b != 1) {    	
    	cout << b << " " << gcd_b << endl;
        gcd_b = gcd(b, gcd_ab);
        b /= gcd_b;
    }
    
	return (a==1 && b==1);
}
int solution(vector<int> &A, vector<int> &B)
{
	int count = 0;
	
	for(size_t i = 0; i<A.size(); i++)
	{
		if(check_prime_divior(A[i], B[i]))
			count++;
	}
	return count;
}

int main() {
	vector<int> A1 ={15,10,3};
	vector<int> B1 ={75,30,5};
	
	cout << solution(A1, B1) << endl;

    system("pause");
    return 0;
}