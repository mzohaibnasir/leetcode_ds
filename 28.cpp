
#include <iostream>


using namespace std;



int strStr(string haystack, string needle){
    int h = haystack.size();
    int n = needle.size();

    for(int i=0; i<h-n; i++){
        if (haystack.substr(i, n) == needle){
            return i;
        }
    }

    return -1;
}


int main() {
    string haystack = "hellolls";
    string needle = "llss";
    
    int result = strStr(haystack, needle);
    cout << "Index: " << result << endl; // Output the result
    
    return 0;
}



/*

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        
        // If needle is empty, return 0
        if (n == 0) {
            return 0;
        }

        // Loop through the haystack
        for (int i = 0; i <= h - n; i++) {
            int j = 0;
            // Compare the substring in haystack with needle
            while (j < n && haystack[i + j] == needle[j]) {
                j++;
            }
            // If the entire needle is found
            if (j == n) {
                return i;
            }
        }
        
        return -1;  // Return -1 if needle is not found
    }
};


*/


// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if (haystack.length() < needle.length()) {
//             return -1;
//         }
        
//         for (int i = 0; i <= haystack.length() - needle.length(); i++) {
//             if (haystack.substr(i, needle.length()) == needle) {
//                 return i;
//             }
//         }
        
//         return -1;        
//     }
// };