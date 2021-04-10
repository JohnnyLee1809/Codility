#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*** method 1 score: 81 O(N^2)
https://app.codility.com/demo/results/trainingM8T95Q-583/

int solution(vector<int> &A)
{
	if(A.size() == 0)
		return 0;
	
	vector<long long> A_max(A.size()), A_min(A.size());
	for(size_t i = 0; i<A.size(); i++)
	{
		A_max[i] = i + A[i];
		A_min[i] = i - A[i];
	}
	
	unsigned int counter = 0;
	
	for(size_t i = 0; i< A.size() - 1; i++)
	{
		for (size_t j = i + 1; j < A.size(); j++)
		{
			if(A_max[i] >= A_min[j])
				counter++;
			else if(A_max[i] == A_max[j])
				counter++;
			else if(A_min[i] == A_min[j])
				counter++;
		}
	
		if (counter > 10000000)
			return -1;
	}
	
	return counter;
}
***/
/**method 2 score:100 
https://app.codility.com/demo/results/training3UH8Q8-TEJ/
***/

// void printA(auto & A)
// {
// 	for(auto&i : A)
// 		cout << i << ' ';
// 	cout << endl;
// }

int solution(vector<int> &A)
{
	if(A.size() == 0)
		return 0;
	
	vector<int> A_max(A.size()), A_min(A.size());
	for(size_t i = 0; i<A.size(); i++)
	{
		A_max[i] = i + A[i];
		A_min[i] = i - A[i];
	}
	
	// printA(A_max);
	// printA(A_min);
	
	sort(A_max.begin(), A_max.end());
	sort(A_min.begin(), A_min.end());

	// printA(A_max);
	// printA(A_min);
	
	unsigned int intersections = 0;
	unsigned int min_it = 0;
	unsigned int max_it = 0;
	unsigned int disks = 0;
	
	for(max_it = 0; max_it < A.size(); max_it++)
	{

		while(min_it < A.size() && A_max[max_it] < A_min[min_it])
			min_it++;
		
		disks = min_it -1;
		min_it = 0;
		intersections += disks;
		if (intersections > 10000000)
			return -1;

	}
	
	return intersections;
}



int main() {
	vector<int> t1 = {1, 5, 2, 1, 4, 0};
	
	cout << solution(t1) << endl;	// 11

	

    system("pause");
    return 0;
}