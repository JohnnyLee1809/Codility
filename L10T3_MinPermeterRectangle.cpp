#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include <climits>

/***method 1 score:100 O(sqrt(N))
https://app.codility.com/demo/results/trainingRCUQHX-XBW/
***/

int solution(int N)
{
	unsigned long i = 1;
	unsigned long tmp = ULONG_MAX, min = ULONG_MAX;

	while(i*i < N)
	{
		if(N%i == 0)
		{
			tmp = 2*(i+(N/i));
			if(tmp < min)
				min = tmp;
		}
		i++;
	}
	
	if(i*i == N)
	{
		tmp = 4*i;
		if(tmp < min)
			min = tmp;
	}
	return min;
}

int main() {
	int N1 = 30;
	int N2 = 1;
	int N3 = 36;
	int N4 = 982451653;
	cout << solution(N1) << endl;
	cout << solution(N2) << endl;
	cout << solution(N3) << endl;
	cout << solution(N4) << endl;

    system("pause");
    return 0;
}