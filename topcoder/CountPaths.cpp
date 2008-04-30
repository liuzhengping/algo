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
#define MAX 55
#define MOD 1000007
using namespace std; 
typedef long long LL;
vector <int> sol;
int n, m, k, dp[MAX][MAX][MAX], grid[MAX][MAX];
int rec(int r, int c, int d) {
  
  if(d > k) return 0;
  if(r == n && c == m) return 1; 
  //printf("[%d %d %d]", r, c, d);
  int &ret = dp[r][c][d];
  if(ret != -1) return ret;
  ret = 0;
  if(r+1 <= n) ret = (ret + rec(r+1, c, d+grid[r+1][c]))%MOD;
  if(c+1 <= m) ret = (ret + rec(r, c+1, d+grid[r][c+1]))%MOD;
  return ret;
}
class CountPaths {
public:
  vector <int> difPaths( int r, int c, vector <int> fieldrow, vector <int> fieldcol ) {
    RES(dp);
    CLR(grid);
    sol.clear();
    k = fieldrow.size();
    sol.resize(k+1);
    n = r; m = c;
    for(int i = 0; i < k; ++i)
      grid[ fieldrow[i] ][ fieldcol[i] ] = 1;
    
    rec(1, 1, grid[1][1]);
    for(int i = 0; i <= k; ++i)
      sol[i] = dp[n][m][k-i];
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed ) { 
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
			int r                     = 3;
			int c                     = 3;
			int fieldrow[]            = {2, 3};
			int fieldcol[]            = {2, 2};
			int expected[]            = {1, 3, 2 };

			clock_t start             = clock();
			vector <int> received     = CountPaths().difPaths( r, c, vector <int>( fieldrow, fieldrow + ( sizeof fieldrow / sizeof fieldrow[0] ) ), vector <int>( fieldcol, fieldcol + ( sizeof fieldcol / sizeof fieldcol[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 1: {
			int r                     = 6;
			int c                     = 4;
			int fieldrow[]            = {5, 3};
			int fieldcol[]            = {3, 2};
			int expected[]            = {14, 24, 0 };

			clock_t start             = clock();
			vector <int> received     = CountPaths().difPaths( r, c, vector <int>( fieldrow, fieldrow + ( sizeof fieldrow / sizeof fieldrow[0] ) ), vector <int>( fieldcol, fieldcol + ( sizeof fieldcol / sizeof fieldcol[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 2: {
			int r                     = 5;
			int c                     = 5;
			int fieldrow[]            = {1, 2, 3};
			int fieldcol[]            = {3, 4, 5};
			int expected[]            = {42, 14, 10, 4 };

			clock_t start             = clock();
			vector <int> received     = CountPaths().difPaths( r, c, vector <int>( fieldrow, fieldrow + ( sizeof fieldrow / sizeof fieldrow[0] ) ), vector <int>( fieldcol, fieldcol + ( sizeof fieldcol / sizeof fieldcol[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 3: {
			int r                     = 35;
			int c                     = 37;
			int fieldrow[]            = {3, 28, 28, 27, 27, 5, 15, 23, 21, 3, 8, 25, 34, 31, 33, 35, 13, 34};
			int fieldcol[]            = {12, 34, 3, 9, 34, 3, 18, 17, 26, 5, 23, 14, 20, 7, 3, 20, 19, 23};
			int expected[]            = {830519, 709835, 755976, 219563, 868547, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			clock_t start             = clock();
			vector <int> received     = CountPaths().difPaths( r, c, vector <int>( fieldrow, fieldrow + ( sizeof fieldrow / sizeof fieldrow[0] ) ), vector <int>( fieldcol, fieldcol + ( sizeof fieldcol / sizeof fieldcol[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 4: {
			int r                     = 50;
			int c                     = 50;
			int fieldrow[]            = {50, 1};
			int fieldcol[]            = {50, 1};
			int expected[]            = {0, 0, 0 };

			clock_t start             = clock();
			vector <int> received     = CountPaths().difPaths( r, c, vector <int>( fieldrow, fieldrow + ( sizeof fieldrow / sizeof fieldrow[0] ) ), vector <int>( fieldcol, fieldcol + ( sizeof fieldcol / sizeof fieldcol[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}

		// custom cases

/*      case 5: {
			int r                     = ;
			int c                     = ;
			int fieldrow[]            = ;
			int fieldcol[]            = ;
			int expected[]            = ;

			clock_t start             = clock();
			vector <int> received     = CountPaths().difPaths( r, c, vector <int>( fieldrow, fieldrow + ( sizeof fieldrow / sizeof fieldrow[0] ) ), vector <int>( fieldcol, fieldcol + ( sizeof fieldcol / sizeof fieldcol[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 6: {
			int r                     = ;
			int c                     = ;
			int fieldrow[]            = ;
			int fieldcol[]            = ;
			int expected[]            = ;

			clock_t start             = clock();
			vector <int> received     = CountPaths().difPaths( r, c, vector <int>( fieldrow, fieldrow + ( sizeof fieldrow / sizeof fieldrow[0] ) ), vector <int>( fieldcol, fieldcol + ( sizeof fieldcol / sizeof fieldcol[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 7: {
			int r                     = ;
			int c                     = ;
			int fieldrow[]            = ;
			int fieldcol[]            = ;
			int expected[]            = ;

			clock_t start             = clock();
			vector <int> received     = CountPaths().difPaths( r, c, vector <int>( fieldrow, fieldrow + ( sizeof fieldrow / sizeof fieldrow[0] ) ), vector <int>( fieldcol, fieldcol + ( sizeof fieldcol / sizeof fieldcol[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
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
