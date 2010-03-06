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

#define MAX 100003
using namespace std; 

typedef long long LL;

vector<pair<int, int> > a;



class CornersDecoding {
public:
  int cnt ( char j, char k, char l ) { int c=0; if(j)++c; if(k)++c; if(l)++c; return c; }
  long long blackPixels( vector <int> rows, vector <int> cols ) {
    
    long long sol;
    a.resize(rows.size());
    for(int i = 0; i < rows.size(); ++i) a[i] = make_pair(rows[i]+1, cols[i]+1);
    
    int crow=0, lrow=0, ccol=0, lcol=0, c = 0;
    char last[MAX] = {}, lastcolor = 0;
    for(int i = 0; i < (int)a.size(); ++i){
    	lrow = crow;
		crow = a[i].first; 
		lcol = ccol;
		ccol = a[i].second;
		
		int count = cnt( last[ crow-1 ], last[ crow ], lastcolor );
		if ( count % 2 ) {
			c ^= 1;
		}
		else sol += -(lrow - crow) * -( lcol - ccol);
		
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
			int rows[]                = {0, 0, 5, 5};
			int cols[]                = {0, 5, 0, 5};
			long long expected        = 25LL;

			clock_t start             = clock();
			long long received        = CornersDecoding().blackPixels( vector <int>( rows, rows + ( sizeof rows / sizeof rows[0] ) ), vector <int>( cols, cols + ( sizeof cols / sizeof cols[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			int rows[]                = {0, 0, 0, 0, 4, 4, 5, 5};
			int cols[]                = {0, 1, 4, 5, 1, 4, 0, 5};
			long long expected        = 13LL;

			clock_t start             = clock();
			long long received        = CornersDecoding().blackPixels( vector <int>( rows, rows + ( sizeof rows / sizeof rows[0] ) ), vector <int>( cols, cols + ( sizeof cols / sizeof cols[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			int rows[]                = {1, 1, 3, 3, 5, 5};
			int cols[]                = {1, 3, 1, 5, 3, 5};
			long long expected        = 8LL;

			clock_t start             = clock();
			long long received        = CornersDecoding().blackPixels( vector <int>( rows, rows + ( sizeof rows / sizeof rows[0] ) ), vector <int>( cols, cols + ( sizeof cols / sizeof cols[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			int rows[]                = {0, 0, 1, 2};
			int cols[]                = {0, 2, 3, 4};
			long long expected        = -1LL;

			clock_t start             = clock();
			long long received        = CornersDecoding().blackPixels( vector <int>( rows, rows + ( sizeof rows / sizeof rows[0] ) ), vector <int>( cols, cols + ( sizeof cols / sizeof cols[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 4: {
			int rows[]                = ;
			int cols[]                = ;
			long long expected        = LL;

			clock_t start             = clock();
			long long received        = CornersDecoding().blackPixels( vector <int>( rows, rows + ( sizeof rows / sizeof rows[0] ) ), vector <int>( cols, cols + ( sizeof cols / sizeof cols[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 5: {
			int rows[]                = ;
			int cols[]                = ;
			long long expected        = LL;

			clock_t start             = clock();
			long long received        = CornersDecoding().blackPixels( vector <int>( rows, rows + ( sizeof rows / sizeof rows[0] ) ), vector <int>( cols, cols + ( sizeof cols / sizeof cols[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 6: {
			int rows[]                = ;
			int cols[]                = ;
			long long expected        = LL;

			clock_t start             = clock();
			long long received        = CornersDecoding().blackPixels( vector <int>( rows, rows + ( sizeof rows / sizeof rows[0] ) ), vector <int>( cols, cols + ( sizeof cols / sizeof cols[0] ) ) );
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
