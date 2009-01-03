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
#include <map>
#include <functional>
#include <numeric>
#include <algorithm>


#define EPS 1e-9
#define MAX
using namespace std;

typedef long long LL;


class BankLoans {
  public:
    double expectedProfit( vector <string> loans, vector <string> riskClasses ) {
      long double sol = 0;
      int n = loans.size();
      map<string, int> cl;
      vector<int> a( n, 0 ), in( n, 0 ), prob( n, 0 );
      
      for ( int i  = 0; i < riskClasses.size(); ++i ) {
        char tmp[64];
        int t;
        sscanf( riskClasses[i].c_str(), "%s%d", tmp, &t );
        cl.insert( make_pair( tmp, t ) );
      }
      
      for ( int i = 0; i < n; ++i ) {
        char tmp[64];
        sscanf( loans[i].c_str(), "%d%d%s", &a[i], &in[i], tmp );
        prob[i] = cl[( string )tmp];
      }
      
      for ( int i = 0; i < n; ++i ) {
        long double pr, lo;
        pr = in[i] * ( double )( 100 - prob[i] ) / 100;
        lo = a[i] * ( double )( prob[i] ) / 100;
        sol += pr - lo;
      }
      
      
      return ( double )sol;
      
    }
};
// BEGIN CUT HERE
namespace moj_harness {
  int run_test_case( int );
  void run_test( int casenum = -1 ) {
    if ( casenum != -1 ) {
      if ( run_test_case( casenum ) == -1 )
        cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
      return;
    }
    
    int correct = 0, total = 0;
    for ( int i = 0;; ++i ) {
      int x = run_test_case( i );
      if ( x == -1 ) {
        if ( i >= 100 )
          break;
        continue;
      }
      correct += x;
      ++total;
    }
    
    if ( total == 0 ) {
      cerr << "No test cases run." << endl;
    } else
      if ( correct < total ) {
        cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
      } else {
        cerr << "All " << total << " tests passed!" << endl;
      }
  }
  
  static const double MAX_DOUBLE_ERROR = 1e-9;
  static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) )
      { return isnan( result ); } else
      if ( isinf( expected ) )
        { if ( expected > 0 )
          { return result > 0 && isinf( result ); } else
        { return result < 0 && isinf( result ); } } else
        if ( isnan( result ) || isinf( result ) )
          { return false; } else
          if ( fabs( result - expected ) < MAX_DOUBLE_ERROR )
            { return true; } else
          { double mmin = min( expected * ( 1.0 - MAX_DOUBLE_ERROR ), expected * ( 1.0 + MAX_DOUBLE_ERROR ) ); double mmax = max( expected * ( 1.0 - MAX_DOUBLE_ERROR ), expected * ( 1.0 + MAX_DOUBLE_ERROR ) ); return result > mmin && result < mmax; } }
  double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 )
      return 0; return fabs( result -expected ) / fabs( expected ); }
      
  int verify_case( int casenum, const double &expected, const double &received, clock_t elapsed ) {
    cerr << "Example " << casenum << "... ";
    
    string verdict;
    vector<string> info;
    char buf[100];
    
    if ( elapsed > CLOCKS_PER_SEC / 200 ) {
      sprintf( buf, "time %.2fs", elapsed * ( 1.0 / CLOCKS_PER_SEC ) );
      info.push_back( buf );
    }
    
    if ( topcoder_fequ( expected, received ) ) {
      verdict = "PASSED";
      double rerr = moj_relative_error( expected, received );
      if ( rerr > 0 ) {
        sprintf( buf, "relative error %.3e", rerr );
        info.push_back( buf );
      }
    } else {
      verdict = "FAILED";
    }
    
    cerr << verdict;
    if ( !info.empty() ) {
      cerr << " (";
      for ( int i = 0; i < ( int )info.size(); ++i ) {
        if ( i > 0 )
          cerr << ", ";
        cerr << info[i];
      }
      cerr << ")";
    }
    cerr << endl;
    
    if ( verdict == "FAILED" ) {
      cerr << "    Expected: " << expected << endl;
      cerr << "    Received: " << received << endl;
    }
    
    return verdict == "PASSED";
  }
  
  int run_test_case( int casenum ) {
    switch ( casenum ) {
      case 0: {
        string loans[]            = {"1000 100 a", "500 80 b", "600 120 c"};
        string riskClasses[]      = {"a 0", "b 5", "c 10"};
        double expected           = 199.0;
        
        clock_t start             = clock();
        double received           = BankLoans().expectedProfit( vector <string>( loans, loans + ( sizeof loans / sizeof loans[0] ) ), vector <string>( riskClasses, riskClasses + ( sizeof riskClasses / sizeof riskClasses[0] ) ) );
        return verify_case( casenum, expected, received, clock() - start );
      }
      case 1: {
        string loans[]            = {"1000 150 beta", "1500 200 beta", "2000 250 beta"};
        string riskClasses[]      = {"alpha 0", "beta 10", "gamma 20"};
        double expected           = 90.0;
        
        clock_t start             = clock();
        double received           = BankLoans().expectedProfit( vector <string>( loans, loans + ( sizeof loans / sizeof loans[0] ) ), vector <string>( riskClasses, riskClasses + ( sizeof riskClasses / sizeof riskClasses[0] ) ) );
        return verify_case( casenum, expected, received, clock() - start );
      }
      case 2: {
        string loans[]            = {"1000 400 hopeless", "1000 400 bad", "1000 400 weak"};
        string riskClasses[]      = {"weak 50", "bad 75", "hopeless 100"};
        double expected           = -1950.0;
        
        clock_t start             = clock();
        double received           = BankLoans().expectedProfit( vector <string>( loans, loans + ( sizeof loans / sizeof loans[0] ) ), vector <string>( riskClasses, riskClasses + ( sizeof riskClasses / sizeof riskClasses[0] ) ) );
        return verify_case( casenum, expected, received, clock() - start );
      }
      case 3: {
        string loans[]            = {"500 55 ok", "1500 170 fine"};
        string riskClasses[]      = {"ok 10", "fine 10"};
        double expected           = 2.5;
        
        clock_t start             = clock();
        double received           = BankLoans().expectedProfit( vector <string>( loans, loans + ( sizeof loans / sizeof loans[0] ) ), vector <string>( riskClasses, riskClasses + ( sizeof riskClasses / sizeof riskClasses[0] ) ) );
        return verify_case( casenum, expected, received, clock() - start );
      }
      case 4: {
        string loans[]            = {"8132 19387 s",  "20219 1791 iarkhyvewuqo",  "19219 4464 s",  "6947 18098 s",  "28985 7338 iarkhyvewuqo",  "21878 7894 iarkhyvewuqo",  "21495 8307 s"};
        string riskClasses[]      = {"s 13", "iarkhyvewuqo 16"};
        double expected           = 39395.83;
        
        clock_t start             = clock();
        double received           = BankLoans().expectedProfit( vector <string>( loans, loans + ( sizeof loans / sizeof loans[0] ) ), vector <string>( riskClasses, riskClasses + ( sizeof riskClasses / sizeof riskClasses[0] ) ) );
        return verify_case( casenum, expected, received, clock() - start );
      }
      
      // custom cases
      
      /*      case 5: {
         string loans[]            = ;
         string riskClasses[]      = ;
         double expected           = ;
      
         clock_t start             = clock();
         double received           = BankLoans().expectedProfit( vector <string>( loans, loans + ( sizeof loans / sizeof loans[0] ) ), vector <string>( riskClasses, riskClasses + ( sizeof riskClasses / sizeof riskClasses[0] ) ) );
         return verify_case( casenum, expected, received, clock()-start );
        }*/
      /*      case 6: {
         string loans[]            = ;
         string riskClasses[]      = ;
         double expected           = ;
      
         clock_t start             = clock();
         double received           = BankLoans().expectedProfit( vector <string>( loans, loans + ( sizeof loans / sizeof loans[0] ) ), vector <string>( riskClasses, riskClasses + ( sizeof riskClasses / sizeof riskClasses[0] ) ) );
         return verify_case( casenum, expected, received, clock()-start );
        }*/
      /*      case 7: {
         string loans[]            = ;
         string riskClasses[]      = ;
         double expected           = ;
      
         clock_t start             = clock();
         double received           = BankLoans().expectedProfit( vector <string>( loans, loans + ( sizeof loans / sizeof loans[0] ) ), vector <string>( riskClasses, riskClasses + ( sizeof riskClasses / sizeof riskClasses[0] ) ) );
         return verify_case( casenum, expected, received, clock()-start );
        }*/
      default:
        return -1;
    }
  }
}


int main( int argc, char *argv[] ) {
  if ( argc == 1 ) {
    moj_harness::run_test();
  } else {
    for ( int i = 1; i < argc; ++i )
      moj_harness::run_test( atoi( argv[i] ) );
  }
}
// END CUT HERE
