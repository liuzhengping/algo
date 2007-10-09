
// BEGIN CUT HERE
// headers begin
// END CUT HERE
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <set>
#include <functional>
#include <numeric>
#include <algorithm>
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define FC1(it, c, from) for(__typeof((c).begin()) it = from; it != (c).end(); ++it)
#define FC2(it, c, from, to) for(__typeof((c).begin()) it = from; it != to; ++it)
#define CLR(x) memset(x,  0, sizeof (x) )
#define RES(x) memset(x, -1, sizeof (x) )
#define EPS 1e-9
#define MAX 
// BEGIN CUT HERE
// headers end
// END CUT HERE

using namespace std;

// BEGIN CUT HERE 
// helper functions begin
// END CUT HERE
// BEGIN CUT HERE 
// helper functions end
template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }
template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }
// END CUT HERE

struct Containers {
   int wastedSpace( int[] containers, int[] packages ) { // caret here

   }

   
// BEGIN CUT HERE
int run_test_case(int);
	void run_test( int Case ) {
	if ( Case != -1 ) {
		if ( run_test_case( Case ) == -1 )
			cerr << "Illegal input! Test case " << Case << " does not exist." << endl;
		return;
	}
			
	int correct = 0, total;
	for ( total=0;; ++total ) {
		int x = run_test_case( total );
		if ( x == -1 ) break;
		correct += x;
	}
	
	if ( total == 0 )
		cerr << "No test cases run." << endl;
	else if ( correct < total )
		cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
	else 
		cerr << "All " << total << " tests passed!" << endl;
}

int verify_case( int Case, const int &Expected, const int &Received ) { cerr << "Test Case #" << Case << "... "; if ( Expected == Received ){ cerr << "PASSED" << endl; return 1; }else { cerr << "FAILED" << endl; cerr << "    tocno: " << Expected << endl; cerr << "    moje : " << Received << endl; } return 0; }

	int run_test_case( int Case ) {
	switch( Case ) {
	case 0: {
		int containers[]     = { 5, 5, 5 };
		int packages[]       = { 5, 5, 5 };
		int expected         = 0;

		return verify_case( Case, expected, Containers().wastedSpace( int[]( containers, containers + ( sizeof containers / sizeof containers[0] ) ), int[]( packages, packages + ( sizeof packages / sizeof packages[0] ) ) ) );
	}
	case 1: {
		int containers[]     = { 5, 6, 7 };
		int packages[]       = { 5, 5, 5 };
		int expected         = 3;

		return verify_case( Case, expected, Containers().wastedSpace( int[]( containers, containers + ( sizeof containers / sizeof containers[0] ) ), int[]( packages, packages + ( sizeof packages / sizeof packages[0] ) ) ) );
	}
	case 2: {
		int containers[]     = { 2, 3, 5 };
		int packages[]       = { 3 };
		int expected         = 7;

		return verify_case( Case, expected, Containers().wastedSpace( int[]( containers, containers + ( sizeof containers / sizeof containers[0] ) ), int[]( packages, packages + ( sizeof packages / sizeof packages[0] ) ) ) );
	}
	case 3: {
		int containers[]     = { 3, 4, 5, 6 };
		int packages[]       = { 3, 3, 3, 3, 3 };
		int expected         = 3;

		return verify_case( Case, expected, Containers().wastedSpace( int[]( containers, containers + ( sizeof containers / sizeof containers[0] ) ), int[]( packages, packages + ( sizeof packages / sizeof packages[0] ) ) ) );
	}

	// custom cases

/*	case 4: {
		int containers[]     = ;
		int packages[]       = ;
		int expected         = ;

		return verify_case( Case, expected, Containers().wastedSpace( int[]( containers, containers + ( sizeof containers / sizeof containers[0] ) ), int[]( packages, packages + ( sizeof packages / sizeof packages[0] ) ) ) );
	}*/
/*	case 5: {
		int containers[]     = ;
		int packages[]       = ;
		int expected         = ;

		return verify_case( Case, expected, Containers().wastedSpace( int[]( containers, containers + ( sizeof containers / sizeof containers[0] ) ), int[]( packages, packages + ( sizeof packages / sizeof packages[0] ) ) ) );
	}*/
	default:
		return -1;
	}
}

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main(void)
{
   Containers ___test; 
   ___test.run_test( -1 ); 
} 
// END CUT HERE 
