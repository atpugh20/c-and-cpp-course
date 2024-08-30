// Convert this program to C++
// change to C++ io
// change to one line comments
// change defines of constants to const
// change array to vector<>
// inline any short function */

// INIT //

#include <iostream>
#include <vector>
using namespace std;

const int N = 40;

// FUNCTIONS //

inline void sum(int& p, int n, vector<int> d) {
    // gets the sum of the vector d, then updates 
    // the pass by reference variable p with this sum
    p = 0;
    for (int i = 0; i < n; ++i) { 
        p += d[i]; 
    }
}

// MAIN //

int main() {
    int accum = 0;
    vector<int> data(N);

    // populates the vector with each instance of i
    for(int i = 0; i < N; ++i)
      data.at(i) = i;
    
    // gets the sum, the prints it out
    sum(accum, N, data);
    cout << "Sum is " << accum << endl; 
    
    return 0;
}
