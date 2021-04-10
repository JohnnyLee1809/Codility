#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*** method 1 score 62 run time error
 * https://app.codility.com/demo/results/trainingYRRXX2-W3M/
 * 
vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    vector<int> min_impact(P.size(), 5);
    for (size_t i = 0; i < P.size(); i++)
    {
        for (auto j = P[i]; j < Q[i] + 1; j++)
        {
            int tmp = 0;
            if (S[j] == 'A')
            {
                min_impact[i] = 1;
                break;
            }
            if (S[j] == 'C')
                tmp = 2;
            else if (S[j] == 'G')
                tmp = 3;
            else if (S[j] == 'T')
                tmp = 4;                

            if( tmp < min_impact[i])
                min_impact[i] = tmp;
        }
    }

    for (auto &i :min_impact)
        cout << i << " ";
    cout << endl;
    return min_impact;
}
***/
/***method 2 score 62 run time error
 * https://app.codility.com/demo/results/trainingMJDXX3-TKD/
 * 
vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    vector<int> min_impact(P.size(), 5);

    for (size_t i = 0; i < P.size(); i++)
    {
        string sub_string = S.substr(P[i], (Q[i]-P[i] +1));
        cout << sub_string << endl;

        if(sub_string.find('A') != string::npos)
            min_impact[i] = 1;
        else if(sub_string.find('C') != string::npos)
            min_impact[i] = 2;
        else if(sub_string.find('G') != string::npos)
            min_impact[i] = 3;
        else if(sub_string.find('T') != string::npos)
            min_impact[i] = 4;
    }
    for (auto &i :min_impact)
        cout << i << " ";
    cout << endl;
    return min_impact;
}
***/
/*** method 3 score 100
 * https://app.codility.com/demo/results/trainingMZU6EE-499/
 * ***/
vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    vector<int> min_impact(P.size(), 5);
    vector<int> pre_sum_A;
    vector<int> pre_sum_C;
    vector<int> pre_sum_G;

    int count_A = 0, count_C = 0, count_G = 0;

    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == 'A') count_A++;
        else if (S[i] == 'C') count_C++;
        else if (S[i] == 'G') count_G++;
 
        pre_sum_A.push_back(count_A);
        pre_sum_C.push_back(count_C);
        pre_sum_G.push_back(count_G);
    }
    cout << "A array:" << endl;
    for (auto &i :pre_sum_A)
        cout << i << " ";
    cout << endl;

    cout << "C array:" << endl;
    for (auto &i :pre_sum_C)
        cout << i << " ";
    cout << endl;

    cout << "G array:" << endl;
    for (auto &i :pre_sum_G)
        cout << i << " ";
    cout << endl;

    for(size_t i = 0; i < P.size(); i++)
    {
        int A_start = 0, C_start= 0, G_start= 0;
        if (S[P[i]] == 'A')
            A_start = 1;
        if (S[P[i]] == 'C')
            C_start = 1;
        if (S[P[i]] == 'G')
            G_start = 1;
            
        if (pre_sum_A[Q[i]] - pre_sum_A[P[i]] + A_start > 0)
            min_impact[i] = 1;
        else if (pre_sum_C[Q[i]] - pre_sum_C[P[i]] + C_start > 0)
            min_impact[i] = 2;
        else if (pre_sum_G[Q[i]] - pre_sum_G[P[i]] + G_start > 0)
            min_impact[i] = 3;
        else
            min_impact[i] = 4;
    }
    for (auto &i :min_impact)
        cout << i << " ";
    cout << endl;

    return min_impact;
}

int main(void)
{
    string S1 = "CAGCCTA"; // N = 6
    vector<int> P1 = {2, 5, 0}; // M = 3
    vector<int> Q1 = {4, 5, 6};

    string S2 = "GT"; // N = 6
    vector<int> P2 = {0, 0, 1}; // M = 3
    vector<int> Q2 = {0, 1, 1};
    // find P[K] & Q[K] minimal impact factor
    solution(S1, P1, Q1);   //2 4 1
    solution(S2, P2, Q2);   //3 3 4

    system("pause");
    return 0;
}