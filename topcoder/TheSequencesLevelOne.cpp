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
using namespace std; 

typedef long long LL;


class TheSequencesLevelOne {
public:
  vector <int> find( vector <int> sequence ) {
    
    vector <int> sol;
    sol.resize(sequence.size());
    for(int i = 0; i < (int)sequence.size(); ++i){
    	if(sequence[i]%4 == 0 || sequence[i]%7 == 0)
    		sol[i] = sequence[i];
    	else{
    		int x = sequence[i];
    		int f1 = x - (x % 4), s1 = x - (x % 7);
    		int f2 = f1 + 4, s2 = s1 + 7;
    		
    		int f;
    		if( abs(f1 - x) > abs(f2 - x) ) f = f2;
    		else f = f1;
    		
    		int s;
    		if( abs(s1 - x) > abs(s2 - x) ) s = s2;
    		else s = s1;
    		
    		if ( abs( s - x ) == abs( f - x) ) sol[i] = min(f,s);
    		else if( abs(s-x) < abs(f-x) ) sol[i] = s;
    		else sol[i] = f;
    		
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
			int sequence[]            = {1, 2, 3, 4, 5, 6, 7};
			int expected[]            = {0, 0, 4, 4, 4, 7, 7 };

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelOne().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 1: {
			int sequence[]            = {1000000000, 999999995};
			int expected[]            = {1000000000, 999999994 };

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelOne().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 2: {
			int sequence[]            = {4, 7, 7, 4};
			int expected[]            = {4, 7, 7, 4 };

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelOne().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 3: {
			int sequence[]            = {44, 47, 77, 74, 474, 444, 747, 7777777};
			int expected[]            = {44, 48, 77, 72, 472, 444, 748, 7777777 };

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelOne().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}

		// custom cases

      case 4: {
			int sequence[]            = {11};
			int expected[]            = {7};

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelOne().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
/*      case 5: {
			int sequence[]            = ;
			int expected[]            = ;

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelOne().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 6: {
			int sequence[]            = ;
			int expected[]            = ;

			clock_t start             = clock();
			vector <int> received     = TheSequencesLevelOne().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) );
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
