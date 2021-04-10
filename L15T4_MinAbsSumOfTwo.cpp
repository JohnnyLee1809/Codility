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

/*** method 1 score:72 notice that we can choose (0,0), and N might be 1
 * https://app.codility.com/demo/results/trainingQDURHG-WWF/
 * 
int solution(vector<int> &A)
{
    int N = A.size();
    int beg = 0, end = N-1;
    int sum = INT16_MAX;
    sort(A.begin(), A.end());
    printvec(A);
    
    if(A[0] >=0)
        return A[0] + A[1];
    
    if(A[N-1] <= 0)
        return abs(A[N - 1] + A[N - 1]);

    while(beg <= end)
    {
        int tmp = abs(A[beg] + A[end]);

        if(tmp < sum){
            sum = tmp;
        }
        if(abs(A[beg]) > abs(A[end]))
            beg++;
        else
            end--;
    }

    return sum;
}
***/
/*** method 2 score:100
 * https://app.codility.com/demo/results/trainingEYA46G-ZY4/
***/

int solution(vector<int> &A)
{
    int N = A.size();
    int beg = 0, end = N-1;
    int sum = INT16_MAX;
    sort(A.begin(), A.end());
    printvec(A);
    
    if(A[0] >= 0 || N == 1)
        return abs(2 * A[0]);
    
    if(A[N-1] <= 0)
        return abs(2 * A[N - 1]);

    while(beg <= end)
    {
        int tmp = abs(A[beg] + A[end]);

        if(tmp < sum){
            sum = tmp;
        }
        if(abs(A[beg]) > abs(A[end]))
            beg++;
        else
            end--;
    }

    return sum;
}




int main(void)
{
    vector<int> A1 = {1, 4, -3};
    vector<int> A2 = {-8, 4, 5, -10, 3};

    cout << solution(A1) << endl;
    cout << solution(A2) << endl;

    system("pause");
    return 0;
}