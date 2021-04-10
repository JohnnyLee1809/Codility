#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*** method 1 score 100
 * https://app.codility.com/demo/results/trainingRGBPZ9-V2F/
***/

int solution(int A, int B, int K)
{
    int count = 0, start = -1, end = -1;

    for (size_t i = A; i <= B; i++)
    {
        if( i%K == 0 ){
            start = i;
            break;
        }
    }
    if(start == -1)
        return 0;

    for (size_t i = B; i >= A; i--)
    {
        if( i%K == 0 ){
            end = i;
            break;
        }
    }

    count = (end - start) / K + 1;
    return count;
}

int main(void){
    
    cout << solution(4, 4, 2) << endl;
    cout << solution(1, 1, 11) << endl;
    cout << solution(0, 0, 11) << endl;

    system("pause");
}