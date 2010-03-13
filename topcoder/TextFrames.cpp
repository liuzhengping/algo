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


class TextFrames {
public:
  vector <string> generateFrame( int width, int height, string phrase, int x1, int y1, int x2, int y2 ) {
    
    phrase += '.';
    vector <string> sol = vector<string> (y2-y1, string (x2-x1,'.') );
    int ci = 0, cj = 0;
    const int di[] = { 0, 1, 0, -1}, dj[] = { 1, 0, -1, 0 };
    int dir = 0;
    for(int i = 0; i < 2*width + 2*height - 4; ++i){
    	if ( ci >= y1 && ci < y2 && cj >= x1 && cj < x2 ){
    		sol[ci-y1][cj-x1] = phrase[i%(int)phrase.size()];
    	}
    	ci += di[dir];
    	cj += dj[dir];
    	if(
    	(cj == width-1  && dir == 0) ||
    	(cj == 0        && dir == 2) ||
    	(ci == 0        && dir == 3) ||
    	(ci == height-1 && dir == 1))
    		dir = (dir+1)%4;
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
	template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case( int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed ) { 
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
			int width                 = 29;
			int height                = 5;
			string phrase             = "I.LOVE.TOPCODER";
			int x1                    = 0;
			int y1                    = 0;
			int x2                    = 29;
			int y2                    = 5;
			string expected[]         = {"I.LOVE.TOPCODER.I.LOVE.TOPCOD", "............................E", "R...........................R", "E............................", "DOCPOT.EVOL.I.REDOCPOT.EVOL.I" };

			clock_t start             = clock();
			vector <string> received  = TextFrames().generateFrame( width, height, phrase, x1, y1, x2, y2 );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 1: {
			int width                 = 10;
			int height                = 10;
			string phrase             = "THIS.SHOWS.A.CORNER";
			int x1                    = 5;
			int y1                    = 5;
			int x2                    = 10;
			int y2                    = 10;
			string expected[]         = {"....O", "....R", "....N", "....E", "IHT.R" };

			clock_t start             = clock();
			vector <string> received  = TextFrames().generateFrame( width, height, phrase, x1, y1, x2, y2 );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 2: {
			int width                 = 4;
			int height                = 4;
			string phrase             = "THE.PHRASE.CAN.BE.LONGER.THAN.THE.PERIMETER";
			int x1                    = 1;
			int y1                    = 2;
			int x2                    = 4;
			int y2                    = 4;
			string expected[]         = {"..H", "SAR" };

			clock_t start             = clock();
			vector <string> received  = TextFrames().generateFrame( width, height, phrase, x1, y1, x2, y2 );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 3: {
			int width                 = 777;
			int height                = 896;
			string phrase             = "THE.PORTION.MAY.NOT.CONTAIN.ANY.LETTER";
			int x1                    = 30;
			int y1                    = 20;
			int x2                    = 50;
			int y2                    = 30;
			string expected[]         = {"....................", "....................", "....................", "....................", "....................", "....................", "....................", "....................", "....................", "...................." };

			clock_t start             = clock();
			vector <string> received  = TextFrames().generateFrame( width, height, phrase, x1, y1, x2, y2 );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 4: {
			int width                 = 1000000;
			int height                = 1000000;
			string phrase             = "LIVE";
			int x1                    = 0;
			int y1                    = 508;
			int x2                    = 4;
			int y2                    = 528;
			string expected[]         = {"E...", "V...", "I...", "L...", "....", "E...", "V...", "I...", "L...", "....", "E...", "V...", "I...", "L...", "....", "E...", "V...", "I...", "L...", "...." };

			clock_t start             = clock();
			vector <string> received  = TextFrames().generateFrame( width, height, phrase, x1, y1, x2, y2 );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}

		// custom cases

/*      case 5: {
			int width                 = ;
			int height                = ;
			string phrase             = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			string expected[]         = ;

			clock_t start             = clock();
			vector <string> received  = TextFrames().generateFrame( width, height, phrase, x1, y1, x2, y2 );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 6: {
			int width                 = ;
			int height                = ;
			string phrase             = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			string expected[]         = ;

			clock_t start             = clock();
			vector <string> received  = TextFrames().generateFrame( width, height, phrase, x1, y1, x2, y2 );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 7: {
			int width                 = ;
			int height                = ;
			string phrase             = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			string expected[]         = ;

			clock_t start             = clock();
			vector <string> received  = TextFrames().generateFrame( width, height, phrase, x1, y1, x2, y2 );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
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
