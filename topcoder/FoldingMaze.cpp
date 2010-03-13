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
#define MAX 55
using namespace std; 

typedef long long LL;
typedef pair< pair<int,int>, int > state;

int h, w;
int mem[MAX][MAX][MAX];
vector<string> fs, bs;
void setMem( state t, int val){
	mem[t.first.first][t.first.second][t.second] = val;
}
int getMem( state t){
	return mem[t.first.first][t.first.second][t.second];
}
char get( state t ){
	int ci = t.first.first, cj = t.first.second, fold = t.second; 
	if ( !fold ) return fs[ci][cj];
	if ( fold <= w/2 ) {// left is folded 
		if ( cj >= 2*fold ) return fs[ci][cj];
		return bs[ci][ w - 1 - (ci-fold) ];
	}
	else { // right is folded
		int tf = (w - fold);
		if ( cj+2*tf<w ) return fs[ci][cj];
		return bs[ci][ cj-tf ];
	}
}

bool canUnfold( state t){
	int ci = t.first.first, cj = t.first.second, fold = t.second; 
	if ( !fold ) return false;
	if ( fold <= w/2 && cj < 2*fold ) return false;
	if ( fold > w/2  && cj+2*(w-fold) >= w ) return false;
	return true;
}

bool canFold( state t ){
	int ci = t.first.first, cj = t.first.second, fold = t.second; 
	if ( fold <= w/2 ) {//left
		return cj >= 2*fold;
	}
	else{
		int tf = (w - fold);
		return cj+2*tf < w;
	}
}

bool ok(state t){
	int ci = t.first.first, cj = t.first.second, fold = t.second; 
	if(!fold){
		if ( ci < 0 || ci >= h || cj < 0 || cj >= w ) return false;
		return fs[ci][cj] != '#';
	}
	
	if ( fold <= w/2 ) {//left is folded
		if ( cj >= fold && cj < fold ) return false;
		return get(t) != '#';
	}
	else{
		int tf = (w-fold);
		if( cj >= w - tf && cj < w ) return false;
		return get(t) != '#';
	}
	
	return get(t) != '#';
}

class FoldingMaze {
public:
  int solve( vector <string> frontSide, vector <string> backSide ) {
    fs=frontSide; bs=backSide;
    h = frontSide.size(); w = frontSide[0].size();
    const int di[] = { 0, 1, 0, -1}, dj[] = { 1, 0, -1, 0 };
    state start;
    for(int i = 0; i < h; ++i)
    	for(int j = 0; j < w; ++j){
    		if( frontSide[i][j] == 'S')
    			start = state( make_pair(i, j), 0 );
    	}
    
    RES(mem);
    int sol=0;
    queue<state> q;
    q.push(start);
    while(!q.empty() ){
    	state curr = q.front();
    	q.pop();
    	if ( get( curr ) == 'E' ) return getMem( curr );
    	
    	for(int dir = 0; dir < 4; ++dir){
    		state next = state ( make_pair(curr.first.first + di[dir], curr.first.second+dj[dir] ),  curr.second);
    		if ( ok( next ) ) {
    			q.push( next );
    			setMem( next, getMem( curr )+1 );
    		}
    	}
    	if ( curr.second ){
    		state unfold = curr;
    		if ( canUnfold( curr ) ) {
    			unfold.second = 0;
    			q.push( unfold );
    			setMem( unfold, getMem( curr )+1 );
    		}
    	}
    	else {
    		state next = curr;
    		for( int fold = 1; fold <= w/2; ++fold){ // fold left side
    			next.second = fold;
    			if ( canFold(next) ){
    				q.push(next);
    				setMem( next, getMem(curr)+1);
    			}
    		}
    		for(int fold = w/2 + 1; fold <= (w-1); ++fold){ // fold right side
    			 if( canFold(next) ){
    			 	q.push(next);
    			 	setMem( next, getMem(curr)+1);
    			 }
    		}
    	}
    	return -1;
    	
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
			string frontSide[]        = {"...E",  "....",  "S..."};
			string backSide[]         = {"####",  "####",  "####"};
			int expected              = 5;

			clock_t start             = clock();
			int received              = FoldingMaze().solve( vector <string>( frontSide, frontSide + ( sizeof frontSide / sizeof frontSide[0] ) ), vector <string>( backSide, backSide + ( sizeof backSide / sizeof backSide[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			string frontSide[]        = {"...E",  "###.",  "S.#."};
			string backSide[]         = {"....",  "....",  "...."};
			int expected              = 9;

			clock_t start             = clock();
			int received              = FoldingMaze().solve( vector <string>( frontSide, frontSide + ( sizeof frontSide / sizeof frontSide[0] ) ), vector <string>( backSide, backSide + ( sizeof backSide / sizeof backSide[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			string frontSide[]        = {"....",  "S.#.",  "...."};
			string backSide[]         = {"#...",  "##.E",  ".#.#"};
			int expected              = 6;

			clock_t start             = clock();
			int received              = FoldingMaze().solve( vector <string>( frontSide, frontSide + ( sizeof frontSide / sizeof frontSide[0] ) ), vector <string>( backSide, backSide + ( sizeof backSide / sizeof backSide[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			string frontSide[]        = {"....####",  "#####..#",  "S#.....#",  ".#.....#",  ".####..#",  "....####"};
			string backSide[]         = {".##..#..",  "..#..#..",  "#.#..#.E",  "#.#..#..",  "..#..###",  ".##....#"};
			int expected              = 20;

			clock_t start             = clock();
			int received              = FoldingMaze().solve( vector <string>( frontSide, frontSide + ( sizeof frontSide / sizeof frontSide[0] ) ), vector <string>( backSide, backSide + ( sizeof backSide / sizeof backSide[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 4: {
			string frontSide[]        = {"....####",  "#####..#",  "S#.....#",  ".#.....#",  ".####..#",  "....####"};
			string backSide[]         = {".#####.#",  "..####..",  "#.####.E",  "#.####..",  "..######",  "........"};
			int expected              = -1;

			clock_t start             = clock();
			int received              = FoldingMaze().solve( vector <string>( frontSide, frontSide + ( sizeof frontSide / sizeof frontSide[0] ) ), vector <string>( backSide, backSide + ( sizeof backSide / sizeof backSide[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 5: {
			string frontSide[]        = ;
			string backSide[]         = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = FoldingMaze().solve( vector <string>( frontSide, frontSide + ( sizeof frontSide / sizeof frontSide[0] ) ), vector <string>( backSide, backSide + ( sizeof backSide / sizeof backSide[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 6: {
			string frontSide[]        = ;
			string backSide[]         = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = FoldingMaze().solve( vector <string>( frontSide, frontSide + ( sizeof frontSide / sizeof frontSide[0] ) ), vector <string>( backSide, backSide + ( sizeof backSide / sizeof backSide[0] ) ) );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 7: {
			string frontSide[]        = ;
			string backSide[]         = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = FoldingMaze().solve( vector <string>( frontSide, frontSide + ( sizeof frontSide / sizeof frontSide[0] ) ), vector <string>( backSide, backSide + ( sizeof backSide / sizeof backSide[0] ) ) );
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
