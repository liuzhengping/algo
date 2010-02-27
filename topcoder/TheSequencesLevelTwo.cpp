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
using namespace std; 

typedef long long LL;


class TheSequencesLevelTwo {
public:
  vector <int> find( vector <int> sequence ) {
    
    vector <int> sol;
    sol.resize(sequence.size());
    sort(sequence.begin(), sequence.end());
    int n = sequence.size();
    set<int> mi ( sequence.begin(), sequence.end() );
    for(int i = 0; i < n; ++i){
    	if( i % 2 == 0 ) {
    		sol[i] = *mi.begin();
    		mi.erase(mi.begin() );
    	}
    	else {
    		if( i == n-1 ) {
    			sol[i] = *mi.begin();
    			break;
    		}
    		__typeof(mi.begin()) it = mi.begin();
    		++it;
    		sol[i] = *it;
    		mi.erase(it);
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
			int sequence[]            = {1, 5, 10};
			int expected[]            = {1, 10, 5 };

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelTwo().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 1: {
			int sequence[]            = {47};
			int expected[]            = {47 };

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelTwo().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 2: {
			int sequence[]            = {7, 2, 5, 4};
			int expected[]            = {2, 5, 4, 7 };

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelTwo().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 3: {
			int sequence[]            = {51, 49, 97, 9, 10, 89, 90, 41, 58};
			int expected[]            = {9, 41, 10, 51, 49, 89, 58, 97, 90 };

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelTwo().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}

		// custom cases

/*      case 4: {
			int sequence[]            = ;
			int expected[]            = ;

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelTwo().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 5: {
			int sequence[]            = ;
			int expected[]            = ;

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelTwo().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 6: {
			int sequence[]            = ;
			int expected[]            = ;

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelTwo().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
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
