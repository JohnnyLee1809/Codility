#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*** method 2 score:100 O(sqrt(N))
https://app.codility.com/demo/results/training3AUKA5-GWU/
***/

int solution(int N) {
    long i = 1, res = 0;
    while(i*i < N)
    {
        if(N%i == 0)
            res += 2;
        i++;
        
    }
    if(i*i == N)
        res +=1;
    
    return res;
}


int main()
{
	cout << solution(24) <<endl; // 8
	cout << solution(2) <<endl; // 2

    system("pause");
    return 0;
}