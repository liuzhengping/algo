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

#define CLR(x) memset(x,  0, sizeof (x) )
#define RES(x) memset(x, -1, sizeof (x) )

using namespace std; 

typedef long long LL;


class FlatCatsBreeding {
public:
  int days( int D, int K, int T ) {
    int sol=0;
    long long curr = 1;
    while(curr < T){
    	sol += D;
    	curr += curr*(K);
    }
    return sol;
    
  }
};
// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test( int casenum = -1 ) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case( int casenum, const int &expected, const int &received, clock_t elapsed ) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int D                     = 4;
			int K                     = 3;
			int T                     = 1;
			int expected              = 0;

			clock_t start             = clock();
			int received              = FlatCatsBreeding().days( D, K, T );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			int D                     = 4;
			int K                     = 3;
			int T                     = 4;
			int expected              = 4;

			clock_t start             = clock();
			int received              = FlatCatsBreeding().days( D, K, T );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			int D                     = 4;
			int K                     = 3;
			int T                     = 9;
			int expected              = 8;

			clock_t start             = clock();
			int received              = FlatCatsBreeding().days( D, K, T );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			int D                     = 4;
			int K                     = 3;
			int T                     = 1000000;
			int expected              = 40;

			clock_t start             = clock();
			int received              = FlatCatsBreeding().days( D, K, T );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 4: {
			int D                     = 91;
			int K                     = 6;
			int T                     = 10433;
			int expected              = 455;

			clock_t start             = clock();
			int received              = FlatCatsBreeding().days( D, K, T );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 5: {
			int D                     = 9;
			int K                     = 7;
			int T                     = 17079;
			int expected              = 45;

			clock_t start             = clock();
			int received              = FlatCatsBreeding().days( D, K, T );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

     case 6: {
			int D                     = 1;
			int K                     = 1;
			int T                     = 1000000;
			int expected              = 1000000;

			clock_t start             = clock();
			int received              = FlatCatsBreeding().days( D, K, T );
			return verify_case( casenum, expected, received, clock()-start );
		}
/*      case 7: {
			int D                     = ;
			int K                     = ;
			int T                     = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = FlatCatsBreeding().days( D, K, T );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 8: {
			int D                     = ;
			int K                     = ;
			int T                     = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = FlatCatsBreeding().days( D, K, T );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
