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

#define MAX  102
using namespace std; 

typedef long long LL;



struct point{
	int x, y, z;
	point() : x(0), y(0), z(0) { }
	point(int x, int y, int z): x(x), y(y), z(z) { }
	point susj(int dir){
		switch(dir){
			case 0:
				return point( x, y, z+1);
			case 1:
				return point( x, y, z-1);
			case 2:
				return point( x, y+1, z);
			case 3:
				return point( x, y-1, z);
			case 4:
				return point( x+1, y, z);
			case 5:
				return point( x-1, y, z);
		}
		return point(0,0,0);\
	}
	bool eq( point b) {
		return x==b.x && y==b.y && z==b.z;
	}
};
  int dist[MAX][MAX][MAX];

class DistanceOnCube {
public:
  int s;
  bool ok_num( int t) {
  	return t >= 0 && t <= s;
  }
  bool ok(point a){
  	return ok_num(a.x) && ok_num(a.y) && ok_num(a.z) && ( min(a.x, min(a.y, a.z)) == 0 || max(a.x,max(a.y,a.z)) == s ) ;
  }
  int calculate( int S, int x1, int y1, int z1, int x2, int y2, int z2 ) {
  	memset(dist, -1, sizeof(dist) );
  	s=S;
  	point target ( x2, y2, z2);
    dist[x1][y1][z1] = 0;
    queue<point> q;
    q.push(point( x1,y1,z1 ) );
    while(!q.empty() ){
    	point curr = q.front();
    	q.pop();
    	if ( curr.eq(target) ) return dist[curr.x][curr.y][curr.z];
    	for( int i = 0; i < 6; ++i){
			point next = curr.susj(i);
			if ( ok( next ) && dist[next.x][next.y][next.z] == -1){
				q.push(next);
				dist[next.x][next.y][next.z] = 1+dist[curr.x][curr.y][curr.z];
			}
    	}	
	}
    
   	fprintf(stderr, "fail");
    return 0;
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
			int S                     = 4;
			int x1                    = 2;
			int y1                    = 2;
			int z1                    = 0;
			int x2                    = 3;
			int y2                    = 3;
			int z2                    = 0;
			int expected              = 2;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 1: {
			int S                     = 4;
			int x1                    = 3;
			int y1                    = 2;
			int z1                    = 0;
			int x2                    = 4;
			int y2                    = 3;
			int z2                    = 2;
			int expected              = 4;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 2: {
			int S                     = 4;
			int x1                    = 1;
			int y1                    = 1;
			int z1                    = 0;
			int x2                    = 1;
			int y2                    = 1;
			int z2                    = 4;
			int expected              = 6;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 3: {
			int S                     = 4;
			int x1                    = 2;
			int y1                    = 3;
			int z1                    = 0;
			int x2                    = 2;
			int y2                    = 3;
			int z2                    = 0;
			int expected              = 0;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 4: {
			int S                     = 87;
			int x1                    = 87;
			int y1                    = 10;
			int z1                    = 3;
			int x2                    = 44;
			int y2                    = 11;
			int z2                    = 0;
			int expected              = 47;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 5: {
			int S                     = 49;
			int x1                    = 0;
			int y1                    = 13;
			int z1                    = 43;
			int x2                    = 49;
			int y2                    = 10;
			int z2                    = 45;
			int expected              = 62;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 6: {
			int S                     = 48;
			int x1                    = 13;
			int y1                    = 0;
			int z1                    = 5;
			int x2                    = 8;
			int y2                    = 48;
			int z2                    = 1;
			int expected              = 59;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
			return verify_case( casenum, expected, received, clock()-start );
		}
		case 7: {
			int S                     = 77;
			int x1                    = 17;
			int y1                    = 20;
			int z1                    = 77;
			int x2                    = 2;
			int y2                    = 35;
			int z2                    = 0;
			int expected              = 111;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
			return verify_case( casenum, expected, received, clock()-start );
		}

		// custom cases

/*      case 8: {
			int S                     = ;
			int x1                    = ;
			int y1                    = ;
			int z1                    = ;
			int x2                    = ;
			int y2                    = ;
			int z2                    = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 9: {
			int S                     = ;
			int x1                    = ;
			int y1                    = ;
			int z1                    = ;
			int x2                    = ;
			int y2                    = ;
			int z2                    = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
			return verify_case( casenum, expected, received, clock()-start );
		}*/
/*      case 10: {
			int S                     = ;
			int x1                    = ;
			int y1                    = ;
			int z1                    = ;
			int x2                    = ;
			int y2                    = ;
			int z2                    = ;
			int expected              = ;

			clock_t start             = clock();
			int received              = DistanceOnCube().calculate( S, x1, y1, z1, x2, y2, z2 );
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
