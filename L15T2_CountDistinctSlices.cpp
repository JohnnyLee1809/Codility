#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <set>

void printvec(vector<int> &A)
{
	for(auto &i : A)
		cout << i << " ";
	cout << endl;
}

/*** method 2  score:40
int solution(int M, vector<int> &A)
{
    int N = A.size();
    int count = 0;
    for(int beg = 0; beg < N; beg++)
	{
        vector<int> num(M, 0);
        
        printvec(num);
        for (int end = beg; end < N; end++)
        {
            cout << "begin = " << beg << " end = " << end;
            cout << A[end] << "¡@" << num[A[end]] << endl;

            if(num[A[end]] == 1)
                break;

            num[A[end]] = 1;
            
            count++;
        }
	}
	
	return count;
}
***/

/***method 4 score 100
https://app.codility.com/demo/results/trainingV7BBQX-EXQ/

int solution(int M, vector<int> &A)
{
    int N = A.size();
    long count = 0;
    int beg = 0, end = 0;
    vector<int> num(M+1,0);
    
    while(beg < N && end < N)
    {
        while(end < N && num[A[end]] != 1)
        {
            count += (end - beg +1);
    		num[A[end]] = 1;
    		end++;
    	}
       while(beg < N && end < N && A[beg] != A[end])
    	{     
    		num[A[beg]] = 0;
    		beg ++;
    	}
    	num[A[beg]] = 0;
    	beg++;
    }
    if(count > 1000000000)
        return 1000000000;
    else
        return count;
}
***/
int solution(int M, vector<int> &A)
{
    int N = A.size();
    long count = 0;
    int beg = 0, end = 0;
    vector<int> num(M+1,0);
    
    while(beg < N && end < N)
    {
        cout << "beg = " << beg << " end = " << end << endl;
        cout << "while 1 " << endl;
        // when the number is not duplicated then calculate the slice between beg to end
        // 0~0=>1 0~1=>2 0~2=>3 because A[2] == A[3] end the loop
        // second round
        // 3~3=>1 3~4=>2
        while(end < N && num[A[end]] != 1){
            
            cout << "beg = " << beg << " end = " << end << "count" << count << endl;
            count += (end - beg +1);
    		num[A[end]] = 1;
    		end++;
    	}
        printvec(num);
        cout << "while 2 " << endl;
        // clear not duplicated number count in num[]
        // A[0] != A[3] => clear num[A[0]] .... A[2] == A[3] => beg = 3
        while(beg < N && end < N && A[beg] != A[end])
    	{     
            cout << "beg = " << beg << " end = " << end << endl;
    		num[A[beg]] = 0;
    		beg ++;
    	}
    	printvec(num);
    	num[A[beg]] = 0;
    	beg++;
    }
    if(count > 1000000000)
        return 1000000000;
    else
        return count;
}


int main(void)
{
    int M1 = 6;
    vector<int> A1 = {3, 4, 5, 5, 2};
    cout << solution(M1, A1) << endl;



    system("pause");
    return 0;
}