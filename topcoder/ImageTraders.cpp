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

vector<string> p;
int n;
int bio[20][10][1 << 16];

int rek(int who, char bought, short mask){
    int ret = 0;
    if(bio[who][bought-'0'][mask] >= 0) return bio[who][bought-'0'][mask];
    for(int i = 0; i < n; ++i){
        if(p[who][i] >= bought && (mask &  (1<<i))==0  ){
            ret = max(ret,1+rek(i, p[who][i], mask | (1 << i)  ) );
        }
    }
    return bio[who][bought-'0'][mask] = ret;
}

class ImageTraders {
public:
  int maxOwners( vector <string> price ) {
    p=price; n = p.size();
    memset(bio, -1, sizeof bio);
    int sol = rek(0, '0', 1);
    return sol+1;
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
			string price[]            = { "01", "10" };
			int expected              = 2;

			clock_t start             = clock();
			int received              = ImageTraders().maxOwners( vector <string>( price, price + ( sizeof price / sizeof price[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			string price[]            = { "022", "101", "110" } ;
			int expected              = 2;

			clock_t start             = clock();
			int received              = ImageTraders().maxOwners( vector <string>( price, price + ( sizeof price / sizeof price[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			string price[]            = { "01231", "00231", "00031", "00002", "00000" };
			int expected              = 4;

			clock_t start             = clock();
			int received              = ImageTraders().maxOwners( vector <string>( price, price + ( sizeof price / sizeof price[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			string price[]            = { "15555", "11111", "15111", "11111", "11111" };
			int expected              = 3;

			clock_t start             = clock();
			int received              = ImageTraders().maxOwners( vector <string>( price, price + ( sizeof price / sizeof price[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 4: {
			string price[]            = { "0100000000", "0020000000", "0003000000", "0000400000", "0000050000", "0000006000", "0000000700", "0000000080", "0000000009", "1111111111" };
			int expected              = 10;

			clock_t start             = clock();
			int received              = ImageTraders().maxOwners( vector <string>( price, price + ( sizeof price / sizeof price[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

       case 5: {
			string price[]            = {"9899998899898", "9360626187920", "2375922897361", "2931947845036", "1063206155476", "5693745254744", "3078688431492", "0689266495048", "7172722610615", "9490917711597", "7673656394812", "9390885096385", "6115984810304"};
			int expected              = 8;

			clock_t start             = clock();
			int received              = ImageTraders().maxOwners( vector <string>( price, price + ( sizeof price / sizeof price[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
/*      case 6: {
			string price[]            = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = ImageTraders().maxOwners( vector <string>( price, price + ( sizeof price / sizeof price[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 7: {
			string price[]            = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = ImageTraders().maxOwners( vector <string>( price, price + ( sizeof price / sizeof price[0] ) ) );
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
