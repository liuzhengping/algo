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

class CreateGroups {
public:
  int minChanges( vector <int> groups, int minSize, int maxSize ) {
    int suma=0;
    int much=0,less=0;
    for(int i = 0; i < groups.size(); ++i){
        suma+=groups[i];
    }
    if(suma> maxSize*groups.size() || suma<minSize*groups.size()) return -1;
    
    for(int i = 0; i < groups.size(); i++){
        int curr = groups[i];
        //sol += max(abs(groups[i]-maxSize), abs(minSize-groups[i]));
        if(curr > maxSize) much += curr-maxSize;
        else if(curr < minSize) less += minSize-curr;
    }
    return max(less,much);
    
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
			int groups[]              = {10,20};
			int minSize               = 10;
			int maxSize               = 15;
			int expected              = 5;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			int groups[]              = {20,8,6};
			int minSize               = 10;
			int maxSize               = 15;
			int expected              = 6;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			int groups[]              = {10,20,30};
			int minSize               = 1;
			int maxSize               = 18;
			int expected              = -1;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			int groups[]              = {50,10,20,20,5};
			int minSize               = 15;
			int maxSize               = 30;
			int expected              = 20;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 4: {
			int groups[]              = {100,200,301};
			int minSize               = 200;
			int maxSize               = 200;
			int expected              = -1;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 5: {
			int groups[]              = {1,10,10}	;
			int minSize               = 9;
			int maxSize               = 20;
			int expected              = -1;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 6: {
			int groups[]              = {55,33,45,71,27,89,16,14,61};
			int minSize               = 33;
			int maxSize               = 56;
			int expected              = 53;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 7: {
			int groups[]              = {49,60,36,34,36,52,60,43,52,59};
			int minSize               = 45;
			int maxSize               = 51;
			int expected              = 31;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 8: {
			int groups[]              = {5,5,5,5,5};
			int minSize               = 5;
			int maxSize               = 5;
			int expected              = 0;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 9: {
			int groups[]              = ;
			int minSize               = ;
			int maxSize               = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 10: {
			int groups[]              = ;
			int minSize               = ;
			int maxSize               = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 11: {
			int groups[]              = ;
			int minSize               = ;
			int maxSize               = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = CreateGroups().minChanges( vector <int>( groups, groups + ( sizeof groups / sizeof groups[0] ) ), minSize, maxSize );
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
