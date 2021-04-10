#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printvec(vector<int> &A)
{
	for(auto &i : A)
		cout << i << " ";
	cout << endl;
}

/*** method 1 score: 72
 * https://app.codility.com/demo/results/trainingAWVAA7-AN6/
 * 
int solution(vector<int> &A)
{
    int N = A.size();
    int count = 0;
    for (int beg = 0; beg < N - 2; beg++)
    {
        for (int mid = beg + 1; mid < N-1; mid++)
        {
            for (int end = mid + 1; end < N; end++)
            {
                vector<int> triangle = {A[beg], A[mid], A[end]};
                sort(triangle.begin(), triangle.end());

                if((triangle[0] + triangle[1]) > triangle[2] &&  (triangle[2] - triangle[1]) < triangle[0] )
                {
                    count++;
                }
                    
            }
        }
    }
    return count;
} 
***/
/*** method 2 score:100
 * https://app.codility.com/demo/results/trainingXGXJSN-XM8/
 ***/

int solution(vector<int> &A)
{
    int N = A.size();
    int count = 0;

    sort(A.begin(), A.end());
    printvec(A);
    for (int beg = 0; beg < N - 2; beg++)
    {
        int mid = beg + 1;
        int end = beg + 2;
        while(mid < N-1)
        {
            if(end < N && (A[beg] + A[mid]) > A[end]){
                cout << "mid = " << mid << " end = " << end << endl;
                end++;
            }else{
                
                count += end - mid - 1;
                mid++;
            }

        }
    }
    return count;
} 

int main(void)
{
    vector<int> A = {10, 2, 5, 1, 8, 12};

    cout << solution(A) << endl;


    system("pause");
    return 0;
}