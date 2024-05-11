#include <iostream>
// arrangment of data - data structure

using namespace std;

string mergeStringsAlternativeky(string s1, string s2)
{
    string resultant = "";

    int i = 0;
    while (i < s1.size() and i < s2.size())
    {
        resultant.push_back(s1[i]);
        resultant.push_back(s2[i]);

        i++;
    }

    if (s1.size() > s2.size())
    {
        resultant.append(s1.substr(i));
    }
    else
    {

        resultant.append(s2.substr(i));
    }

    for (int i = 0; i < resultant.size(); i++)
    {
        cout << resultant[i] << " ";
    }

    // cout << endl
    //      << s1.substr(0, 2);

    return resultant;
}

int main()
{
    // int A[10] = {0};
    // int n;
    // cout << "Hello World" << endl;
    // cout << "Input Size" << endl;
    // cin >> n;
    // int B[n];

    // for( int i=0; i<11;i++){
    //         printf("%d\n", i);

    // }

    // for( int i=0; i<10;i++){
    //         printf("%d \t%s\n", A[i],"ssssssssssssssssssssssssssssssssssssssss");

    // }

    // for (int x : B)
    // {
    //     cout << x << endl;
    // }

    mergeStringsAlternativeky("abcd", "pqrs");
}

/*
Physical data structures:   Array, Matrices,LinkedList
-they define how data is arranged in memory


Logical Data strcutures:    Stack,Queues,Tress,Graphs,Hashing
define how data can be utilized














*/