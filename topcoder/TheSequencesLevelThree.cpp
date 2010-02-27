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

#define MOD 1234567891
#define MAX 53
using namespace std; 

typedef long long LL;


class TheSequencesLevelThree {
public:
  int K, N;
  vector<int> a;
  int memo[MAX][MAX][MAX];
  int rek( int n, int idx, int idx2){
    if( n == N ){
    	if( idx2 == 51 ) idx2 = a.size()-1;
    	
    	return abs( a[idx] - a[a.size()-1] ) <= K;
    	
    	
    	
    	
    }
    if ( memo[n][idx][idx2] != -1 ) return memo[n][idx][idx2];
    int ret = 0;
    for(int i = idx%51+1; i < (int)a.size() && (idx==51 || abs(a[idx] - a[i]) <= K); ++i){
    	if ( i == idx%51+1  || idx2 == 51 || abs(a[i] - a[idx2] ) <= K){
    		ret = LL(ret + rek( n+1,  i, (i == idx+1)?(idx2):(i) ) ) % MOD;
    	}
    }
    
    return memo[n][idx][idx2] = ret % MOD;
  }
  int find( vector <int> sequence, int k ) {
    a = sequence; K=k;
    sort(a.begin(), a.end());
    int sol;
    
    for(int l1 = 1; l1 < (int)sequence.size()-1; ++l1){
    	memset(memo, -1, sizeof(memo) );
    	N=l1;
    	sol = (LL)(sol + rek(0, 51, 51) ) % MOD;
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
			int sequence[]            = {1, 5, 10, 4};
			int k                     = 10;
			int expected              = 6;

			clock_t start             = clock();
			int received              = TheSequencesLevelThree().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			int sequence[]            = {1, 5, 10, 4};
			int k                     = 6;
			int expected              = 4;

			clock_t start             = clock();
			int received              = TheSequencesLevelThree().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			int sequence[]            = {4, 44, 7, 77};
			int k                     = 1;
			int expected              = 0;

			clock_t start             = clock();
			int received              = TheSequencesLevelThree().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			int sequence[]            = {96, 29, 21, 90, 46, 77, 31, 63, 79};
			int k                     = 44;
			int expected              = 126;

			clock_t start             = clock();
			int received              = TheSequencesLevelThree().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 4: {
			int sequence[]            = ;
			int k                     = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = TheSequencesLevelThree().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 5: {
			int sequence[]            = ;
			int k                     = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = TheSequencesLevelThree().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 6: {
			int sequence[]            = ;
			int k                     = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = TheSequencesLevelThree().find( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
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
