#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void recursion(int n)
{
    if (n < 1)
    {
        return;
    }
    cout << n << "\t";
    recursion(n - 1);
}

void backtrackingAsc(int n)
{
    if (n < 1)
    {
        return;
    }
    backtrackingAsc(n - 1);
    cout << n << "\t";
}

//////////////////////////////////////////////////////////////////////

/* Recursion by
    -   parameterization
    -   function return value

*/

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void parameterizedSumOfn(int n, int sum)
{
    if (n < 1)
    {
        cout << sum;
        return;
    }
    parameterizedSumOfn(n - 1, sum + n);
}

int functionalSumOfn(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n + functionalSumOfn(n - 1);
}

/////////////////////////////////////////////////////////

bool palindrome(string str, int i, int len)
{
    if (i >= len)
    {
        cout << "Palindrome" << endl;
        return true;
    }
    if (str[i] != str[len - 1 - i])
    {
        return false;
    }

    return palindrome(str, i + 1, len);
}

/////////////////////////////////// Multiple Recursion calls:

// subsequences
// -powerset??
// recursionturn

void xhelper(vector<int> given, vector<int> current, int idx, vector<vector<int>> &resultant)
{
    if (idx >= given.size())
    {
        resultant.push_back(current);

        return;
    }

    current.push_back(given[idx]);

    xhelper(given, current, idx + 1, resultant);

    current.pop_back();
    xhelper(given, current, idx + 1, resultant);
}

void xsubsets()
{
    vector<int> givenArray = {1, 2, 3};
    vector<int> current;
    vector<vector<int>> resultant;
    xhelper(givenArray, current, 0, resultant);
}

void helper(vector<int> &array, int idx, vector<int> curr, vector<vector<int>> &resultant)
{
    if (idx >= array.size())
    {
        resultant.push_back(curr);
        return;
    }

    // take

    curr.push_back(array[idx]);
    helper(array, idx + 1, curr, resultant);
    curr.pop_back();
    helper(array, idx + 1, curr, resultant);
}

void subsets()
{
    vector<int> givenArray = {1, 2, 3};
    vector<int> curr;
    vector<vector<int>> resultant;

    helper(givenArray, 0, curr, resultant);

    for (int i = 0; i < resultant.size(); i++)
    {
        for (int j = 0; j < resultant[i].size(); j++)
        {
            cout << resultant[i][j] << "\t";
        }
        cout << endl;
    }
}

void subarraySumHelper(vector<int> &givenArray, int idx, vector<int> &curr,
                       vector<vector<int>> &resultant, int k, int sum)
{
    if (idx >= givenArray.size())
    {
        cout << "sum: " << sum << endl;
        if (accumulate(curr.begin(), curr.end(), 0) == k)
        {
            resultant.push_back(curr);
        }
        return;
    }

    curr.push_back(givenArray[idx]);

    subarraySumHelper(givenArray, idx + 1, curr, resultant, k, sum + givenArray[idx]);
    curr.pop_back();
    subarraySumHelper(givenArray, idx + 1, curr, resultant, k, sum);
}
void subarraySum(int k)
{
    vector<int> givenArray = {1, 2, 1};
    vector<vector<int>> resultant;
    vector<int> curr;

    subarraySumHelper(givenArray, 0, curr, resultant, k, 0);
    for (int i = 0; i < resultant.size(); i++)
    {
        for (int j = 0; j < resultant[i].size(); j++)
        {
            cout << resultant[i][j] << "\t";
        }
        cout << endl;
    }

    return;
}

// Technique to print only one answer:In base condition, if conidtion is satisfied, you will return true else false. And put fn call in if()

bool anySubSequenceHelper(vector<int> &givenArray, int idx, vector<int> &curr,
                          vector<vector<int>> &resultant, int k, int sum)
{
    if (idx >= givenArray.size())
    {
        cout << "sum: " << sum << endl;
        if (accumulate(curr.begin(), curr.end(), 0) == k)
        {
            resultant.push_back(curr);
            return true;
        }
        return false;
    }

    curr.push_back(givenArray[idx]);

    if (anySubSequenceHelper(givenArray, idx + 1, curr, resultant, k, sum + givenArray[idx]) == true)
    {
        return true;
    }
    curr.pop_back();
    if (anySubSequenceHelper(givenArray, idx + 1, curr, resultant, k, sum))
        return true;

    return false;
}
void anySubSequence(int k)
{
    vector<int> givenArray = {1, 2, 1};
    vector<vector<int>> resultant;
    vector<int> curr;

    anySubSequenceHelper(givenArray, 0, curr, resultant, k, 0);
    for (int i = 0; i < resultant.size(); i++)
    {
        for (int j = 0; j < resultant[i].size(); j++)
        {
            cout << resultant[i][j] << "\t";
        }
        cout << endl;
    }

    return;
}

// Count
/*
    int fn(){
        base case{
            return 1 if condition == true else 0
        }

        l=left()
        r=right()

        return l+r;

    }

    like in n-queeen
*/

int subarraySumCountHelper(vector<int> &givenArray, int idx, int k, int sum)
{
    if (idx >= givenArray.size())
    {
        // cout << "sum: " << sum << endl;
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    int l = subarraySumCountHelper(givenArray, idx + 1, k, sum + givenArray[idx]);
    int r = subarraySumCountHelper(givenArray, idx + 1, k, sum);

    return l + r;
}
void subarraySumCount(int k)
{
    vector<int> givenArray = {1, 2, 1};

    cout << "Count : " << subarraySumCountHelper(givenArray, 0, k, 0);

    return;
}

int main()
{

    // cout << "Recursion:\t";
    // recursion(9);
    // cout << "\nBacktracking:Asc\t";

    // backtrackingAsc(9);

    // parameterizedSumOfn(3, 0);
    // cout << functionalSumOfn(3);

    // return 0;

    // string str = "abcba";
    // int len = str.length();
    // cout << palindrome(str, 0, len);

    // subsets();

    // subarraySum(2);
    subarraySumCount(2);

    // vector<int> curr = {3, 5, 6, 7};

    // int x = *min_element(curr.begin(), curr.end());

    // cout << "x: " << x << endl;
}
