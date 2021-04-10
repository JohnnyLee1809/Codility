#include <iostream>

using namespace std;
/***method 1 score:100
https://app.codility.com/demo/results/trainingVHFVH4-P9N/
***/

int solution(int X, int Y, int D)
{
	unsigned long res = (Y-X)/D + ((Y-X)%D != 0);
	return res;
}

int main() {
	cout << solution(10, 85, 30) << endl;

    system("pause");   
    return 0;

}