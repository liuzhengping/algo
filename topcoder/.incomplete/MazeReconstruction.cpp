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

#define MAX 110
using namespace std; 
typedef long long LL;


int dij[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
///                  D,      R,       U,      L

int ni(int i,int dir){  return i+dij[dir][0]; }
int nj(int j,int dir){  return j+dij[dir][1]; }
void nd(int &dir, char d){
  if(d=='R'){
    --dir;
    if(dir==-1) dir = 3;
  }
  else if(d=='L'){
    ++dir;
    if(dir==4) dir = 0;
  }
}
int n;
char p[MAX][MAX];

class MazeReconstruction {
public:
  vector <string> mazeMap( string moves ) {
    CLR(p);
    n = moves.size();
    
    int ci = MAX/2, cj = MAX/2, cd = 0;
    int mini=ci, minj=cj, maxi=ci, maxj=cj;
    p[ci][cj] = 1;
    
    
    for(int i = 0; i < n; ++i){
      if(moves[i] == 'F'){
        ci = ni(ci,cd);
        cj = nj(cj,cd);
      }
      else nd(cd, moves[i]);
      
      p[ci][cj] = 1;
      mini = min(mini, ci);
      maxi = max(maxi, ci);
      minj = min(minj, cj);
      maxj = max(maxj, cj);
      
    }
    
    int I = maxi - mini + 1;
    int J = maxj - minj + 1;
    
    vector <string> sol (I, string(J, '#') );
    for(int i = mini; i <= maxi; ++i){
      for(int j = minj; j <= maxj; ++j){
        if(p[i][j]) sol[i - mini][j-minj] = '.';
        printf("%c",sol[i-mini][j-minj]);
      }
      printf("\n");
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
			string moves              = "RRFRF";
			string expected[]         = {"..", ".#" };

			clock_t start             = clock();
			vector <string> received  = MazeReconstruction().mazeMap( moves );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 1: {
			string moves              = "LFFRFF";
			string expected[]         = {"...", "##.", "##." };

			clock_t start             = clock();
			vector <string> received  = MazeReconstruction().mazeMap( moves );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 2: {
			string moves              = "LFLFRRFLFRRFLF";
			string expected[]         = {"#.#", "...", "#.#" };

			clock_t start             = clock();
			vector <string> received  = MazeReconstruction().mazeMap( moves );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 3: {
			string moves              = "FLFRFFRFFFRFFRFLFLL";
			string expected[]         = {"#..#", "....", ".##.", "...." };

			clock_t start             = clock();
			vector <string> received  = MazeReconstruction().mazeMap( moves );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 4: {
			string moves              = "FRFFFFFFLLFRFFFFFLLFRFFFFLFFLFF";
			string expected[]         = {"######.", ".......", "#.#####", "#.#...#", "#.###.#", "#.....#", "#.#####" };

			clock_t start             = clock();
			vector <string> received  = MazeReconstruction().mazeMap( moves );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 5: {
			string moves              = "FFFFFFFFFFFFFFFFFFFFFFFFLFFFFFFFFFFFFFFFFFFFFFFFF";
			string expected[]         = {".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", ".########################", "........................." };

			clock_t start             = clock();
			vector <string> received  = MazeReconstruction().mazeMap( moves );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 6: {
			string moves              = "";
			string expected[]         = {"." };

			clock_t start             = clock();
			vector <string> received  = MazeReconstruction().mazeMap( moves );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}

		// custom cases

/*      case 7: {
			string moves              = ;
			string expected[]         = ;

			clock_t start             = clock();
			vector <string> received  = MazeReconstruction().mazeMap( moves );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 8: {
			string moves              = ;
			string expected[]         = ;

			clock_t start             = clock();
			vector <string> received  = MazeReconstruction().mazeMap( moves );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}*/
/*      case 9: {
			string moves              = ;
			string expected[]         = ;

			clock_t start             = clock();
			vector <string> received  = MazeReconstruction().mazeMap( moves );
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
