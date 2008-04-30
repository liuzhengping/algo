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
using namespace std; 
typedef long long LL;
int sol;
class CountExpressions {
public:
  int calcExpressions( int x, int y, int val ) {
    printf("(%d %d %d)", x, y, val);
    int var[2] = {x, y};
    int op[2] = {1, -1};
    vector<int> a;
    a.push_back(0); a.push_back(0); a.push_back(1); a.push_back(1);
    sol = 0;
    do {
      for(int b = 0; b < 8; ++b) {
        int sum = var[ a[0] ];
        for(int i = 0; i < 3; ++i)
          sum += op[ ((1 << i) & b) > 0 ] * var[ a[i+1] ];
        printf("%d ", sum);
        if(sum == val)
          ++sol;
      }
    } while( next_permutation(a.begin(), a.end()) );
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
			int x                     = 7;
			int y                     = 8;
			int val                   = 16;
			int expected              = 9;

			clock_t start             = clock();
			int received              = CountExpressions().calcExpressions( x, y, val );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			int x                     = 3;
			int y                     = 5;
			int val                   = 7;
			int expected              = 5;

			clock_t start             = clock();
			int received              = CountExpressions().calcExpressions( x, y, val );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			int x                     = 99;
			int y                     = 100;
			int val                   = 98010000;
			int expected              = 6;

			clock_t start             = clock();
			int received              = CountExpressions().calcExpressions( x, y, val );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			int x                     = -99;
			int y                     = 42;
			int val                   = -1764;
			int expected              = 2;

			clock_t start             = clock();
			int received              = CountExpressions().calcExpressions( x, y, val );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 4: {
			int x                     = 100;
			int y                     = -100;
			int val                   = -100000000;
			int expected              = 0;

			clock_t start             = clock();
			int received              = CountExpressions().calcExpressions( x, y, val );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 5: {
			int x                     = 1;
			int y                     = 2;
			int val                   = 5;
			int expected              = 17;

			clock_t start             = clock();
			int received              = CountExpressions().calcExpressions( x, y, val );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 6: {
			int x                     = ;
			int y                     = ;
			int val                   = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = CountExpressions().calcExpressions( x, y, val );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 7: {
			int x                     = ;
			int y                     = ;
			int val                   = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = CountExpressions().calcExpressions( x, y, val );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 8: {
			int x                     = ;
			int y                     = ;
			int val                   = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = CountExpressions().calcExpressions( x, y, val );
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
