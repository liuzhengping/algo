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

using namespace std; 
typedef long long LL;

class BitwiseEquations {
public:
  long long kthPlusOrSolution( int xa, int ka ) {
        long long sol=0LL, x=xa, k=ka;
        int i = 0;
        for(int w = 0; w < 64; ++w){
            if((1LL << w) & x) continue;
            //sol |= (((k & (1 << i++))?1:0)  << w);
            if(k & (1LL << i++)){
                sol |= 1LL << (w);
            }
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
	
	int verify_case( int casenum, const long long &expected, const long long &received, clock_t elapsed ) { 
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
			int x                     = 5;
			int k                     = 1;
			long long expected        = 2LL;

			clock_t start             = clock();
			long long received        = BitwiseEquations().kthPlusOrSolution( x, k );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			int x                     = 5;
			int k                     = 5;
			long long expected        = 18LL;

			clock_t start             = clock();
			long long received        = BitwiseEquations().kthPlusOrSolution( x, k );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			int x                     = 10;
			int k                     = 3;
			long long expected        = 5LL;

			clock_t start             = clock();
			long long received        = BitwiseEquations().kthPlusOrSolution( x, k );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			int x                     = 1;
			int k                     = 1000000000;
			long long expected        = 2000000000LL;

			clock_t start             = clock();
			long long received        = BitwiseEquations().kthPlusOrSolution( x, k );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 4: {
			int x                     = ;
			int k                     = ;
			long long expected        = LL;

			clock_t start             = clock();
			long long received        = BitwiseEquations().kthPlusOrSolution( x, k );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 5: {
			int x                     = ;
			int k                     = ;
			long long expected        = LL;

			clock_t start             = clock();
			long long received        = BitwiseEquations().kthPlusOrSolution( x, k );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 6: {
			int x                     = ;
			int k                     = ;
			long long expected        = LL;

			clock_t start             = clock();
			long long received        = BitwiseEquations().kthPlusOrSolution( x, k );
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
