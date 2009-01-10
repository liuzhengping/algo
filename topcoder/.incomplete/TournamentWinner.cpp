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

int a[8][8];


class TournamentWinner {
public:
  vector <double> winningProbabilities( vector <int> P ) {
    CLR(a);    
    int n = P.size();

    
    for(int i = 0;  i < 8; ++i)       a[0][i]    = P[i], a[i][0] = 100 - a[0][i];
    for(int i = 8;  i < 14; ++i)      a[1][i-7]  = P[i], a[i][1] = 100 - a[1][i];
    for(int i = 14; i < 20; ++i)      a[2][i-13] = P[i], a[i][2] = 100 - a[2][i];
    for(int i = 20; i < 25; ++i)      a[3][i-19] = P[i], a[i][3] = 100 - a[3][i];
    for(int i = 25; i < 29; ++i)      a[4][i-24] = P[i], a[i][4] = 100 - a[4][i];
    for(int i = 29; i < 32; ++i)      a[5][i-31] = P[i], a[i][5] = 100 - a[5][i];
    for(int i = 32; i < 34; ++i)      a[6][i-33] = P[i], a[i][6] = 100 - a[6][i];
    for(int i = 34; i < 35; ++i)      a[7][i-35] = P[i], a[i][7] = 100 - a[7][i];
    
    vector <double> sol;
    
    //r1
    for(int i = 0; i < 4; ++i){
      int p = 2*i, q = 2*i+1;
      sol[p] = a[p][q];
      sol[q] = a[q][p];
    }
    
    //r2
    for(int i = 0; i < 3; ++i){
      int p = 2*i, q = 2*i+1;
      sol[
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	static bool topcoder_fequ( const vector<double> &a, const vector<double> &b ) { if ( a.size() != b.size() ) return false; for ( size_t i=0; i<a.size(); ++i ) if ( !topcoder_fequ( a[i], b[i] ) ) return false; return true; }
	double moj_relative_error( const vector<double> &expected, const vector<double> &result ) { double ret = 0.0; for ( size_t i=0; i<expected.size(); ++i ) { ret = max( ret, moj_relative_error( expected[i], result[i] ) ); } return ret; }
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <double> &expected, const vector <double> &received, clock_t elapsed ) { 
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
			int P[]                   = {5,   0,  10,  15,  20,  25,  30,       0,  35,  40,  45,  50,  55,          100, 100, 100, 100, 100,                60,  65,  70,  75,                     80,  85,  90,                          95,  50,                               50};
			double expected[]         = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

			clock_t start             = clock();
			vector <double> received  = TournamentWinner().winningProbabilities( vector <int>( P, P + ( sizeof P / sizeof P[0] ) ) );
			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 1: {
			int P[]                   = {100,  25,   0,  25,  25,  25,  25,        25,  25,  25,  25,  25,  25,              0,  25,  25,  25,  25,                  50,  25,  25,  25,                      100,  25, 100,                            25,  25,                                  0};
			double expected[]         = {0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.0 };

			clock_t start             = clock();
			vector <double> received  = TournamentWinner().winningProbabilities( vector <int>( P, P + ( sizeof P / sizeof P[0] ) ) );
			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 2: {
			int P[]                   = {50,  50,  50,  50,  50,  50,  50,       50,  50,  50,  50,  50,  50,            50,  50,  50,  50,  50,                 50,  50,  50,  50,                      50,  50,  50,                           50,  50,                                50};
			double expected[]         = {0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125 };

			clock_t start             = clock();
			vector <double> received  = TournamentWinner().winningProbabilities( vector <int>( P, P + ( sizeof P / sizeof P[0] ) ) );
			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 3: {
			int P[]                   = {100, 50,  50,  50,  50,  50,  50,        0,  50,  50,  50,  50,  50,           100,  50,  50,  50,  50,                  0,  50,  50,  50,                     100,  50,  50,                            0,  50,                               100};
			double expected[]         = {0.25, 0.0, 0.25, 0.0, 0.25, 0.0, 0.25, 0.0 };

			clock_t start             = clock();
			vector <double> received  = TournamentWinner().winningProbabilities( vector <int>( P, P + ( sizeof P / sizeof P[0] ) ) );
			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 4: {
			int P[]                   = { 50, 50,  50,  50,  50,  50,  50,       50,  50,  50,  50,  50,  50,            50,  50,  50,  50,  50,                 50,  50,  50,  50,                     100, 100, 100,                           10,  20,                                30};
			double expected[]         = {0.125, 0.125, 0.125, 0.125, 0.5, 0.0, 0.0, 0.0 };

			clock_t start             = clock();
			vector <double> received  = TournamentWinner().winningProbabilities( vector <int>( P, P + ( sizeof P / sizeof P[0] ) ) );
			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 5: {
			int P[]                   = {  1,  2,   4,   7,  11,  16,  22,        3,   5,   8,  12,  17,  23,             6,   9,  13,  18,  24,                 10,  14,  19,  25,                      15,  20,  26,                           21,  27,                                28};
			double expected[]         = {6.88919608E-5, 0.009061234459199999, 0.011498979459599998, 0.1853675541204, 0.0328889066112, 0.18542493028680002, 0.17985791390280004, 0.3958315891991999 };

			clock_t start             = clock();
			vector <double> received  = TournamentWinner().winningProbabilities( vector <int>( P, P + ( sizeof P / sizeof P[0] ) ) );
			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}

		// custom cases

/*      case 6: {
			int P[]                   = ;
			double expected[]         = ;

			clock_t start             = clock();
			vector <double> received  = TournamentWinner().winningProbabilities( vector <int>( P, P + ( sizeof P / sizeof P[0] ) ) );
			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 7: {
			int P[]                   = ;
			double expected[]         = ;

			clock_t start             = clock();
			vector <double> received  = TournamentWinner().winningProbabilities( vector <int>( P, P + ( sizeof P / sizeof P[0] ) ) );
			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 8: {
			int P[]                   = ;
			double expected[]         = ;

			clock_t start             = clock();
			vector <double> received  = TournamentWinner().winningProbabilities( vector <int>( P, P + ( sizeof P / sizeof P[0] ) ) );
			return verify_case( casenum, vector <double>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
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
