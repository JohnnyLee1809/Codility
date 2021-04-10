#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*** method 1  score:100
https://app.codility.com/demo/results/training649MNR-VBD/
***/

int solution(int N)
{
	unsigned long gap_tmp = 0;
	unsigned long gap_max = 0;
	unsigned short binary_num = 0;
	unsigned short binary_num_pre = 0;
	bool gap_start_flag = 0;
	
	do
	{
		if(N % 2)
			binary_num = 1;
		else
			binary_num = 0;
		
		if(binary_num_pre == 1 && binary_num == 0)
			gap_start_flag = true;
		else if (binary_num_pre == 0 && binary_num == 1)
			gap_start_flag = false;
		
		if (gap_start_flag == true)
			gap_tmp ++;
		else{
			if (gap_tmp > gap_max)
				gap_max = gap_tmp;
			gap_tmp = 0;
		}
		N /= 2;
		binary_num_pre = binary_num;

	}	while (N >= 1);
	
	return gap_max;
}

int main() {
	solution(1376796946);
	solution(1610612737);

    system("pause");
    return 0;
}
