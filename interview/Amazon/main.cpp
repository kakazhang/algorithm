/**
* Count steps to transfer a string to 
* another one
* */

#include <iostream>
#include <string>

using namespace std;
#define MIN(a,b) ((a) > (b) ? (b) : (a))
#define min(a, b, c) (MIN(a, b), c)

/*recursive way to get steps*/
int editDist(string str1, string str2, int len1, int len2) {
    if (len1 == 0)   //insert len2 characters
        return len2;
    if (len2 == 0)  //remove all len1 characters
        return len1;

    if (str1[len1-1] == str2[len2-1])
        return editDist(str1, str2, len1-1,len2-1);

    return 1 + min(editDist(str1, str2,len1, len2-1), editDist(str1, str2, len1-1, len2),
                  editDist(str1, str2, len1-1,len2-1));
}

int dynamic_way(string str1, string str2, int M, int N) {
    //i index : means length of str1' substrings
    //j index: means length of str2' substrings
    int table[M+1][N+1];

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == 0)
                table[i][j] = j;
            else if (j == 0)
                table[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                table[i][j] = dynamic_way(str1, str2, i-1, j-1);

            else 
                table[i][j] = 1 + min(table[i][j-1], table[i-1][j], table[i-1][j-1]);
        }
    }

    return table[M][N];
}

int main() {
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist( str1 , str2 , str1.length(), str2.length() ) << endl;
    cout << dynamic_way( str1 , str2 , str1.length(), str2.length() ) << endl;

    return 0;
}


