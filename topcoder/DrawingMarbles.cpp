
// BEGIN CUT HERE
// headers begin
// END CUT HERE
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
typedef long long LL;
// BEGIN CUT HERE
// headers end
// END CUT HERE
using namespace std;
double sol = 0;
// BEGIN CUT HERE 
// helper functions begin
// END CUT HERE
// BEGIN CUT HERE 
// helper functions end
template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }
template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }
// END CUT HERE
struct DrawingMarbles {
   double sameColor( vector <int> colors, int n ) { // caret here
      int sum = 0;
      
      for(int curr = 0; curr < colors.size(); ++curr) sum += colors[curr];
      for(int curr = 0; curr < colors.size(); ++curr) {
        double r = 0;
        for(int i = 0; i < n; ++i) {
          int naz = sum - i;
          int br = colors[curr]-i;
          if(br <= 0) { r = 0; break; }
          if(naz <= 0) { r = 0; break; }
          if(!i) r = 1;
          r *= (double) br/naz;
        }   
        sol += r;
      }
     // if(sol > 1) sol = 1;
      return sol;
   }

   
// BEGIN CUT HERE
//int run_test_case(int);
	void run_test( int Case ) {
	if ( Case != -1 ) {
		if ( run_test_case( Case ) == -1 )
			cerr << "Illegal input! Test case " << Case << " does not exist." << endl;
		return;
	}
			
	int correct = 0, total;
	for ( total=0;; ++total ) {
		int x = run_test_case( total );
		if ( x == -1 ) break;
		correct += x;
	}
	
	if ( total == 0 )
		cerr << "No test cases run." << endl;
	else if ( correct < total )
		cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
	else 
		cerr << "All " << total << " tests passed!" << endl;
}

static const double MAX_DOUBLE_ERROR = 1E-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) ) return 0; return fabs( result-expected ) / fabs( expected ); }
int verify_case( int Case, const double &Expected, const double &Received ) { cerr << "Test Case #" << Case << "... "; if ( topcoder_fequ( Expected, Received ) ) { cerr << "PASSED"; { double rerr = moj_relative_error( Expected, Received ); if ( rerr > 0 ) cerr << " (relative error " << rerr << ")"; } cerr << endl; return 1; }else { cerr << "FAILED" << endl; cerr << "    tocno: " << Expected << endl; cerr << "    moje : " << Received << endl; } return 0; }

	int run_test_case( int Case ) {
	switch( Case ) {
	case 0: {
		int colors[]         = { 13 };
		int n                = 8;
		double expected      = 1.0;

		return verify_case( Case, expected, DrawingMarbles().sameColor( vector <int>( colors, colors + ( sizeof colors / sizeof colors[0] ) ), n ) );
	}
	case 1: {
		int colors[]         = { 5, 7 };
		int n                = 1;
		double expected      = 1.0;

		return verify_case( Case, expected, DrawingMarbles().sameColor( vector <int>( colors, colors + ( sizeof colors / sizeof colors[0] ) ), n ) );
	}
	case 2: {
		int colors[]         = { 5, 6, 7 };
		int n                = 2;
		double expected      = 0.3006535947712418;

		return verify_case( Case, expected, DrawingMarbles().sameColor( vector <int>( colors, colors + ( sizeof colors / sizeof colors[0] ) ), n ) );
	}
	case 3: {
		int colors[]         = { 12, 2, 34, 13, 17 };
		int n                = 4;
		double expected      = 0.035028830818304504;

		return verify_case( Case, expected, DrawingMarbles().sameColor( vector <int>( colors, colors + ( sizeof colors / sizeof colors[0] ) ), n ) );
	}

	// custom cases
/*
	case 4: {
		int colors[]         = {5, 2, 3};
		int n                = 5;
		double expected      = 0;

		return verify_case( Case, expected, DrawingMarbles().sameColor( vector <int>( colors, colors + ( sizeof colors / sizeof colors[0] ) ), n ) );
	}
/*	case 5: {
		int colors[]         = ;
		int n                = ;
		double expected      = ;

		return verify_case( Case, expected, DrawingMarbles().sameColor( vector <int>( colors, colors + ( sizeof colors / sizeof colors[0] ) ), n ) );
	}*/
	default:
		return -1;
	}
}

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main(void)
{
   DrawingMarbles ___test; 
   ___test.run_test( -1 ); 
   scanf("\n");
} 
// END CUT HERE 
