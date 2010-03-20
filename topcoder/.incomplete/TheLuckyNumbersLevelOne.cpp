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

void print(int mask, int len){
	for(int i = len-1; i >= 0; --i){
		printf("%d", !!((1 << i) & mask));
	}
	printf("\n");
}

int evenmask(int mask, int len){
	int tmp= 0;
	for(int i = 0; i < len; ++i){
		if((1 << i) & mask) tmp |= 1 << (len - i - 1);
	}
	tmp |= mask << len;
	return tmp;
}

int oddmask(int mask, int len){
	int tmp=0;
	for(int i = 1; i < len; ++i){
		if((1 << i) & mask) tmp |= 1 << (len - i - 1);
	}
	tmp |= mask << (len-1);
	return tmp;
}

long long toll(int mask, int len){
	long long ret=0;
	for(int i = 0; i < len; ++i){
		if((1 << i) & mask){
			ret = 10*ret + 7;
		}
		else ret = 10*ret + 4;
	}
	return ret;
}




class TheLuckyNumbersLevelOne {
public:
	long long find( long long a, long long b ) {
	long long sol=0;
	
	for(int len = 1; len <= 9; ++len)
		for ( int mask = 0; mask < (1 << len); ++mask ) {
			long long odd, even;
			odd = toll(oddmask(mask, len), 2*len-1);
			even= toll(evenmask(mask, len ), 2*len);
			if ( odd >= a && odd <= b) ++sol;
			if ( even >= a && even <= b) ++sol;
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
			long long a               = 1LL;
			long long b               = 100LL;
			long long expected        = 4LL;

			clock_t start             = clock();
			long long received        = TheLuckyNumbersLevelOne().find( a, b );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			long long a               = 45LL;
			long long b               = 54LL;
			long long expected        = 0LL;

			clock_t start             = clock();
			long long received        = TheLuckyNumbersLevelOne().find( a, b );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			long long a               = 477444774LL;
			long long b               = 477444774LL;
			long long expected        = 1LL;

			clock_t start             = clock();
			long long received        = TheLuckyNumbersLevelOne().find( a, b );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			long long a               = 456789123LL;
			long long b               = 789123456LL;
			long long expected        = 24LL;

			clock_t start             = clock();
			long long received        = TheLuckyNumbersLevelOne().find( a, b );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 4: {
			long long a               = LL;
			long long b               = LL;
			long long expected        = LL;

			clock_t start             = clock();
			long long received        = TheLuckyNumbersLevelOne().find( a, b );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 5: {
			long long a               = LL;
			long long b               = LL;
			long long expected        = LL;

			clock_t start             = clock();
			long long received        = TheLuckyNumbersLevelOne().find( a, b );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 6: {
			long long a               = LL;
			long long b               = LL;
			long long expected        = LL;

			clock_t start             = clock();
			long long received        = TheLuckyNumbersLevelOne().find( a, b );
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
