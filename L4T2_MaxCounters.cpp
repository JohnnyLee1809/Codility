#include <iostream>
#include <vector>

/***Method 1 Score:77 correctness:100 Performace:60
 * https://app.codility.com/demo/results/trainingVQJ599-BCU/
vector<int> solution(int N, vector<int> &A) {
    std::vector<int> counter(N, 0);
    int max = 0;

    for(size_t i = 0; i < A.size(); i++)
    {
        if(A[i] != N+1){
            counter[A[i] - 1]++;
            if(counter[A[i]-1] > max)
                max = counter[A[i]-1];
        }else{
            std::fill(counter.begin(), counter.end(), max);
        }
    }
    return counter;

}
 ***/
/*** method 2 score 100
 * https://app.codility.com/demo/results/trainingQV25ST-DZQ/
***/

std::vector<int> solution(int N, std::vector<int> &A) {
    std::vector<int> counter(N, 0);
    int max = 0, base = 0;

    for(size_t i = 0; i < A.size(); i++)
    {
        if(A[i] != N+1){
            if((counter[A[i]-1] + 1) > base)
                counter[A[i] - 1]++;
            else
                counter[A[i] - 1] = base + 1;
            
            if(counter[A[i]-1] > max)
                max = counter[A[i]-1];
        }else{
            base = max;
        }
    }

    for (size_t i = 0; i < counter.size(); i++)
    {  
        if(counter[i] < base)
            counter[i] = base;
    }
    return counter;

}

int main()
{
    std::vector<int> test = {3, 4, 4, 6, 1, 4, 4};
    int N = 5;
    solution(N, test);

    system("pause");
    return 0;
}