#include <iostream>
#include <vector>
#include <numeric> // std::accumulate
#include <algorithm>

using namespace std;

void printA(int arr[], int size)
{
    // array is acting as a pointer

    for (int i = 0; i < size; i++)
    {
        /* e */ cout << arr[i] << "\t";
    }
    cout << endl;
}
void printA(string arr[], int size)
{
    // array is acting as a pointer

    for (int i = 0; i < size; i++)
    {
        /* e */ cout << arr[i] << "\t";
    }
    cout << endl;
}

void printV(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    cout << endl;
}
void printVV(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << ",";
        }
        cout << "]";
        cout << ",";
    }
    cout << endl;
}
void printV(vector<string> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    cout << endl;
}

void insertV(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = i + 1;
    }
}

// void helper(string s, int idx, int n, string curr, vector<string> &result) // to know the current substring
// {

//     if (idx == n)
//     {
//         int size = sizeof(curr) / sizeof(curr[0]);
//         cout << curr << endl;

//         result.push_back(curr);
//         return;
//     }

//     // include
//     helper(s, idx + 1, n, curr + s[idx], result); // idx + 1 means going one level down in recursive tree

//     // exclude
//     helper(s, idx + 1, n, curr, result);
// }
// vector<string> AllpossibleStrings(string s)
// {
//     vector<string> result;
//     int n = 3;
//     string curr = "";

//     helper(s, 0, n, curr, result);
//     printV(result);
//     return result;
// }

// void hpelperP(string s, int len, int idx, string curr, vector<string> &result)
// {
//     if (idx >= len)
//     {
//         result.push_back(curr);
//         printV(result);
//         cout << endl;
//         return;
//     }

//     // cout << "|- " << curr;
//     helperP(s, len, idx + 1, curr + s[idx], result);
//     helperP(s, len, idx + 1, curr, result);
// }

// vector<string> pAllPossible(string s)
// {
//     vector<string> result;
//     // cout << s << endl;
//     // int n = sizeof(s) / sizeof(s[0]);
//     int n = s.length();
//     string curr = "";
//     // cout << "... " << n << endl;
//     helperP(s, n, 0, curr, result);
//     cout << endl
//          << endl
//          << endl
//          << result.size() << endl;
//     return result;
// }

// void helper(string s, int idx, int n, string curr, vector<string> &result)
// {
//     if (idx >= n)
//     {
//         result.push_back(curr);
//         printV(result);
//         return;
//     }
//     // cout << curr << endl;
//     helper(s, idx + 1, n, curr + s[idx], result);
//     helper(s, idx + 1, n, curr, result);
// }

// void AllPossible(string s)
// {
//     vector<string> result;
//     int n = s.length();

//     helper(s, 0, n, "", result);
//     // printV(result);
// }
// passing curr by refrence
void helperS(vector<int> &array, int idx, vector<int> &curr, vector<vector<int>> &result)
{
    if (idx >= array.size())
    {
        result.push_back(curr);

        printVV(result);
        // printV(curr);
        return;
    }

    // EXCLUDE
    helperS(array, idx + 1, curr, result);
    // INCLUDE
    curr.push_back(array[idx]);
    helperS(array, idx + 1, curr, result);
    curr.pop_back();
}

void AllPossibleArray(vector<int> &array)
{
    vector<vector<int>> result;
    vector<int> curr;
    helperS(array, 0, curr, result);
    // printV(result);
}

// passing curr by value
void helperSI(vector<int> &array, int idx, vector<int> curr, vector<vector<int>> &result)
{
    if (idx >= array.size())
    {
        result.push_back(curr);
        // cout << "result"
        //      << " : ";
        // printVV(result);
        // printV(curr);
        return;
    }

    // EXCLUDE
    helperSI(array, idx + 1, curr, result);
    // INCLUDE
    curr.push_back(array[idx]);
    helperSI(array, idx + 1, curr, result);
    // curr.pop_back();
    // cout << "current"
    //      << " : ";
    // printV(curr);
}

void AllPossibleArrayI(vector<int> &array)
{
    vector<vector<int>> result;
    vector<int> curr;
    helperSI(array, 0, curr, result);
    printVV(result);
}

///////////

void helperSubsetSum(vector<int> &array, int idx, vector<int> curr, vector<vector<int>> &result, vector<int> &sums)
{
    if (idx >= array.size())
    {
        result.push_back(curr);
        sums.push_back(accumulate(curr.begin(), curr.end(), 0));
        cout << "result:";
        printVV(result);
        cout << "sums:";
        printV(sums);
        return;
    }
    //
    // include
    curr.push_back(array[idx]);
    helperSubsetSum(array, idx + 1, curr, result, sums);
    // exclude
    curr.pop_back();
    helperSubsetSum(array, idx + 1, curr, result, sums);
}

void subsetSum(vector<int> &array, int sum)
{
    // printV(array);
    // cout << sum;
    vector<vector<int>> result;
    vector<int> curr;
    vector<int> sums;
    // cout << accumulate(array.begin(), array.end(), 0);

    helperSubsetSum(array, 0, curr, result, sums);
}

bool helperSubsetSumWithoutResult(vector<int> &array, int idx, int sum, int &target)
{
    if (sum == target)
    {
        cout << "Found: " << sum << endl;
        return true;
    }
    if (idx >= array.size())
    {
        cout << "Index out of range: " << idx << endl;
        return false;
    }
    cout << sum << endl;
    return helperSubsetSumWithoutResult(array, idx + 1, sum + array[idx], target);
    // helperSubsetSumWithoutResult(array, idx + 1, sum, target);
}
void subsetSumWithoutResult(vector<int> &array, int &target)
{
    // int sum = 0;
    helperSubsetSumWithoutResult(array, 0, 0, target);
    printV(array);
}

// void helperPermutations(string s, int idx, vector<string> &res)
// {
//     if (idx >= s.length() - 1)
//     {
//         cout << "\tEntered: " << s << endl;
//         res.push_back(s);
//         return;
//     }

//     for (int i = idx; i < s.length(); i++)
//     {
//         cout << idx << " : " << i << "\t|\t";
//         swap(s[idx], s[i]);

//         cout << s << endl;
//         helperPermutations(s, idx + 1, res);
//         swap(s[idx], s[i]); // swap back
//     }
//     // printV(array);
//     // helperPermutations(s, idx + 1, res);
//     // return;
// }

void helperPermutations(string s, int idx, vector<string> &res)
{
    // cout << s << endl;
    if (idx >= s.length() - 1)
    {
        cout << "\n Entered " << s << endl;
        res.push_back(s);
        return;
    }

    for (int i = idx; i < s.length(); i++)
    {
        cout << "before: " << s << endl;

        cout << "idx " << idx << " : "
             << "i " << i << "\t|\t";
        swap(s[idx], s[i]);
        cout << endl
             << "after: " << s << endl;
        helperPermutations(s, idx + 1, res);
        swap(s[idx], s[i]);
    }

    // printV(array);
}
vector<string>
permutations(string str)
{
    vector<string> res;
    // printV(array);

    helperPermutations(str, 0, res);
    printV(res);
    sort(res.begin(), res.end());
    printV(res);
    return res;
}
int main()
{
    // AllPossible("abcd");
    // int arr[] = {1, 2, 3};
    vector<int> array = {1, 2, 3};
    int sum = 5;
    // AllPossibleArrayI(array);
    // AllPossibleArray(array);
    // subsetSum(array, sum);
    int target = 3;
    // subsetSumWithoutResult(array, target);
    permutations("abc");
    // array
    // int array[] = {1, 2, 3, 4};
    // int size = sizeof(array) / sizeof(array[0]);
    // printA(array, size);

    /*
    vector: automatic resizing, dynamic memory management, and built-in functions for manipulating and accessing elements.

    */
    // vector<int> rainfall(7); // empty will be assigned 0

    // vector<int>
    //     rainfall = {9, 8, 7, 6, 5, 4, 3};
    // printV(rainfall);
    // insertV(rainfall);
    // printV(rainfall);
    // /////////////////////////////////////
    // vector<int> newVector;

    // Adding elements dynamically

    // newVector.push_back(11);
    // newVector.push_back(22);
    // newVector.push_back(33);
    // newVector.push_back(44);
    // newVector.push_back(55);
    // newVector.push_back(66);
    // printV(newVector);

    // // modification

    // newVector[3] = 99999;
    // printV(newVector);

    // // Insertion

    // cout << newVector.size() << endl;
    // cout << *newVector.begin() << endl;      // pointer
    // newVector.insert(newVector.begin(), 77); // myVector.begin() :iter
    // printV(newVector);

    // newVector.resize(10, 777); // Increasing the size to 5 //(n,val)  initialize val to new elements
    // printV(newVector);

    // newVector.pop_back();
    // printV(newVector);
    // AllpossibleStrings("abc");
}