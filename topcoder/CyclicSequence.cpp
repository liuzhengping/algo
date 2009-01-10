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


#define EPS 1e-9
#define MAX 
using namespace std; 

typedef long long LL;


class CyclicSequence {
public:
  string minimalCycle( string s ) {
    
    string curr="";
    bool found;
    for(int l = 1; l < s.size(); ++l){
      curr = s.substr(0, l);
      found = true;
      for(int it = 0; it * l < s.size(); ++it){
        for(int i = 0; i < l; ++i){
          if(s[it*l+i] != curr[i]) found = false;;
        }
      }
      if(found) return curr;
    }
    
    return s;
    
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
	
	int verify_case( int casenum, const string &expected, const string &received, clock_t elapsed ) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string s                  = "11111";
			string expected           = "1";

			clock_t start             = clock();
			string received           = CyclicSequence().minimalCycle( s );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			string s                  = "234234234";
			string expected           = "234";

			clock_t start             = clock();
			string received           = CyclicSequence().minimalCycle( s );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			string s                  = "567890";
			string expected           = "567890";

			clock_t start             = clock();
			string received           = CyclicSequence().minimalCycle( s );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			string s                  = "0";
			string expected           = "0";

			clock_t start             = clock();
			string received           = CyclicSequence().minimalCycle( s );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 4: {
			string s                  = "678967";
			string expected           = "678967";

			clock_t start             = clock();
			string received           = CyclicSequence().minimalCycle( s );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 5: {
			string s                  = ;
			string expected           = ;

			clock_t start             = clock();
			string received           = CyclicSequence().minimalCycle( s );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 6: {
			string s                  = ;
			string expected           = ;

			clock_t start             = clock();
			string received           = CyclicSequence().minimalCycle( s );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 7: {
			string s                  = ;
			string expected           = ;

			clock_t start             = clock();
			string received           = CyclicSequence().minimalCycle( s );
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
