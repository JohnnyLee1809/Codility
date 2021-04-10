#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <stack>

/***
 * method 1 score:100
 * https://app.codility.com/demo/results/trainingQWXEXW-6RY/
 * 
 * ***/

int solution(vector<int> &H)
{
    int N = H.size();
    if(N<2)
        return N;
    unsigned long stones = 0;
    stack<int> base_stones;

    for (size_t i = 0; i < N; i++)
    {   
        while((!base_stones.empty()) && (H[i] < base_stones.top()))
        {
            base_stones.pop();
            stones++;
        }
        if(base_stones.empty() || (H[i] > base_stones.top()))
            base_stones.push(H[i]);

        cout << "i =" << i << " stones =" << stones << " stacksize =" << base_stones.size() << " stacktop =" << base_stones.top()<<endl;
    }

    stones += base_stones.size();

    return stones;
}


int main(void)
{
    vector<int> H1 = {8, 8, 5, 7, 9, 8, 7, 4, 8};
    vector<int> H2 = {2, 3, 2, 1};
    vector<int> H3 = {3, 2, 1};
    cout << solution(H1) << endl;   // 7
    cout << solution(H2) << endl;   // 3
    cout << solution(H3) << endl;   // 3

    system("pause");
    return 0;
}