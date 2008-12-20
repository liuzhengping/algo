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
double sol;
class SpeedRadar {
public:
  double averageSpeed( int minLimit, int maxLimit, vector <int> readings ) {
    int infir=0;
    sol=0;
    for(int i = 0; i < readings.size(); ++i){
      if(readings[i] > maxLimit || readings[i] < minLimit){
	++infir;
      }
      else sol+=readings[i];
    }
    if(infir > readings.size()/10) return 0.0;
    return sol/(readings.size()-infir);
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
			int minLimit              = 1;
			int maxLimit              = 50;
			int readings[]            = {45, 40, 50};
			double expected           = 45.0;

			clock_t start             = clock();
			double received           = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			int minLimit              = 1;
			int maxLimit              = 50;
			int readings[]            = {42,43,44,45,46,47,48,49,50,51};
			double expected           = 46.0;

			clock_t start             = clock();
			double received           = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			int minLimit              = 1;
			int maxLimit              = 50;
			int readings[]            = {42,46,48,50,52};
			double expected           = 0.0;

			clock_t start             = clock();
			double received           = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			int minLimit              = 20;
			int maxLimit              = 60;
			int readings[]            = {25,45,45,43,24,9,51,55,60,34,61,23,40,40,47,49,33,23,47,54,54};
			double expected           = 41.68421052631579;

			clock_t start             = clock();
			double received           = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 4: {
			int minLimit              = ;
			int maxLimit              = ;
			int readings[]            = ;
			double expected           = ;

			clock_t start             = clock();
			double received           = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 5: {
			int minLimit              = ;
			int maxLimit              = ;
			int readings[]            = ;
			double expected           = ;

			clock_t start             = clock();
			double received           = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 6: {
			int minLimit              = ;
			int maxLimit              = ;
			int readings[]            = ;
			double expected           = ;

			clock_t start             = clock();
			double received           = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
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
