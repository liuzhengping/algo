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

#define EPS 1e-9
#define MAX 
using namespace std; 

typedef long long LL;


class SubwayTrip {
public:
  double earlierTrain( int Ve, int Vy, int L, int T ) {
    
    long double sol;
    
    long double t1 = (long double)L / Ve, t2 = (long double) L / (Ve+Vy);
    
    sol = ( t1 - t2 ) / T;
    
    if(sol > 1) sol = 1;
    
    return (double)sol;
    
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case( int casenum, const double &expected, const double &received, clock_t elapsed ) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( topcoder_fequ( expected, received ) ) {
			verdict = "PASSED";
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int Ve                    = 10;
			int Vy                    = 10;
			int L                     = 20;
			int T                     = 2;
			double expected           = 0.5;

			clock_t start             = clock();
			double received           = SubwayTrip().earlierTrain( Ve, Vy, L, T );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			int Ve                    = 50;
			int Vy                    = 5;
			int L                     = 55;
			int T                     = 20;
			double expected           = 0.005000000000000004;

			clock_t start             = clock();
			double received           = SubwayTrip().earlierTrain( Ve, Vy, L, T );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			int Ve                    = 34;
			int Vy                    = 3;
			int L                     = 85;
			int T                     = 7;
			double expected           = 0.028957528957528934;

			clock_t start             = clock();
			double received           = SubwayTrip().earlierTrain( Ve, Vy, L, T );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			int Ve                    = 10;
			int Vy                    = 10;
			int L                     = 100;
			int T                     = 4;
			double expected           = 1.0;

			clock_t start             = clock();
			double received           = SubwayTrip().earlierTrain( Ve, Vy, L, T );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 4: {
			int Ve                    = ;
			int Vy                    = ;
			int L                     = ;
			int T                     = ;
			double expected           = ;

			clock_t start             = clock();
			double received           = SubwayTrip().earlierTrain( Ve, Vy, L, T );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 5: {
			int Ve                    = ;
			int Vy                    = ;
			int L                     = ;
			int T                     = ;
			double expected           = ;

			clock_t start             = clock();
			double received           = SubwayTrip().earlierTrain( Ve, Vy, L, T );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 6: {
			int Ve                    = ;
			int Vy                    = ;
			int L                     = ;
			int T                     = ;
			double expected           = ;

			clock_t start             = clock();
			double received           = SubwayTrip().earlierTrain( Ve, Vy, L, T );
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
