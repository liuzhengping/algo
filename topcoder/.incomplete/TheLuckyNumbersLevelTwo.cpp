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


vector<long long> lucky;
vector<int> nums;

vector<pair<long long, int> > rightsums;

void masktostr(char *dest, int mask, int len){
	dest[len]='\0';
	for(int i = 0; i < len; ++i){
		if((1ll << i) & mask) dest[len-i-1] = '1';
		else dest[len-i-1] = '0';
	}
}

int sz;
void generate(){
	long long t = 0;
	lucky.clear();
	while (t < 34000000003LL){
		t = (t *10)+4;
		lucky.push_back(t);
	}
	t = 0;
	while (t < 34000000003LL){
		t = (t *10)+7;
		lucky.push_back(t);
	}
	
	sort(lucky.begin(), lucky.end()) ;
}


long long toll(int mask, bool right){
	long long ret=0;
	int to;
	if(right)
		to = sz - sz/2;
	else to = sz/2;
	for(int i = 0; i < to; ++i){
		if(mask & (1ll << i) ){
			ret += nums[ right*sz/2 + i];
		}
	}
	return ret;
}

vector< pair<long long , int > >get(long long target){
	vector<pair<long long , int > > ret;
	pair<long long, int> t ( target, -1 );
	vector<pair<long long , int > >::iterator it = lower_bound ( rightsums.begin(), rightsums.end(),  t);
	while( it != rightsums.end() && it->first == target){
		ret.push_back(*it);
		++it;
	}
	return ret;
}

pair<long long , int > getp(long long target){
	pair<long long , int > ret ((long long)-1,-1);
	pair<long long, int> t ( target, -1 );
	vector<pair<long long , int > >::iterator it = lower_bound ( rightsums.begin(), rightsums.end(),  t);
	if( it != rightsums.end() && it->first == target){
		return *it;
	}
	return ret;
}

pair<long long, long long > best;
bool cmp(const pair<long long, long long>& a, const pair<long long, long long>& b){
	if(a.first != b.first) return a.first < b.first;
	long long m1 = a.second, m2 = b.second;
	for(int i = 0; i < sz; ++i){
		bool b1 = (1LL << i) & m1, b2 = (1LL << i) & m2;
		if(b1 != b2){
			return !b1;
		}
	}
	return false;
}

class TheLuckyNumbersLevelTwo {
public:
	vector <int> find( vector <int> numbers ) {
	if(numbers.size() == 1){
		int t = numbers[0];
		if(binary_search(lucky.begin(), lucky.end(), t) ) {
			return vector<int> (1, t);
		}
	}
	
	best = make_pair(-1ll, -1ll);
	generate();
	nums=numbers;
	sz=nums.size();
	sort(nums.begin(), nums.end() );
	
	int to = sz - sz/2;
	vector <int> sol;
	
	rightsums.clear();
	rightsums.reserve( 1ll << (sz/2)); 
	for(int mask = 0; mask < 1ll<< to; ++mask){
		rightsums.push_back( make_pair( toll(mask,1), mask ) );
	}
	sort(rightsums.begin(), rightsums.end());
	
#ifdef moj_debug2
	for(int i = 0; i < (int)rightsums.size(); ++i){
		char *buf = new char[to+1];
		masktostr(buf,rightsums[i].second,to);
		printf("(%lld,%s)",rightsums[i].first, buf);
		delete buf;
	}printf("\n");
#endif
	for(int mask = 0; mask < 1ll << (sz/2); ++mask){
		long long lsum = toll(mask, 0);
		for(int i = (int)lucky.size()-1; i >= 0; --i){
			long long target = lucky[i]-lsum;
			vector <pair<long long , int > > right = get( target );
			if(right.size()==0) {
				continue;
			}
			for(int it = 0; it < (int)right.size(); ++it){
				pair<long long, long long> curr (lucky[i] , (long long)right[it].second << (sz/2) | mask);
				best = max ( curr, best, cmp  );
				
#ifdef moj_debug1
				if(lucky[i]<=444) continue;
				// 78493915
				char* buf = new char[to+1];
				masktostr(buf,mask,to);
				fprintf(stderr,"got(%lld,%s),t=%lld, ",lsum,buf,target);
				if(buf) delete(buf);
//				cerr << "crash";
//				cin.get();
				
				buf = new char[(sz/2+1)];
				masktostr(buf, right[it].second, sz/2 );
				fprintf(stderr,"found(%lld,%s), ",right[it].first, buf);
				if(buf) delete(buf);
				
				fprintf(stderr,"sum=%lld\n",lucky[i]);
				
				fprintf(stderr,"{");
				int h = 0;
				for(int i = 0; i < (int)nums.size(); ++i){
					long long mask = curr.second;
					if( mask & (1LL << i ) ){
						if(h) fprintf(stderr,", ");
						++h;
						fprintf(stderr,"%d",nums[i]);
					}
				}
				fprintf(stderr,"}\n");
#endif
			}
		}
	}
	if(best == make_pair((long long)-1, (long long)-1) ) return vector<int> ();
	for(int i = 0; i < (int)nums.size(); ++i){
		long long mask = best.second;
		if( mask & (1LL << i ) ){	
			sol.push_back(nums[i]);
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
//			cin.get();
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
			int numbers[]             = {1, 2, 3, 4};
			int expected[]            = {1, 2, 4 };

			clock_t start             = clock();
			vector <int> received     = TheLuckyNumbersLevelTwo().find( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 1: {
			int numbers[]             = {12, 43, 29};
			int expected[]            = { };

			clock_t start             = clock();
			vector <int> received     = TheLuckyNumbersLevelTwo().find( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 2: {
			int numbers[]             = {4, 7};
			int expected[]            = {7 };

			clock_t start             = clock();
			vector <int> received     = TheLuckyNumbersLevelTwo().find( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 3: {
			int numbers[]             = {41, 2, 28, 44, 7, 42, 21};
			int expected[]            = {7, 28, 42 };

			clock_t start             = clock();
			vector <int> received     = TheLuckyNumbersLevelTwo().find( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 4: {
			int numbers[]             = {15, 10, 28, 3, 13, 27, 7};
			int expected[]            = {7, 15, 27, 28 };

			clock_t start             = clock();
			vector <int> received     = TheLuckyNumbersLevelTwo().find( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 5: {
			int numbers[]             = {18, 45, 6};
			int expected[]            = { };

			clock_t start             = clock();
			vector <int> received     = TheLuckyNumbersLevelTwo().find( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
		case 6: {
			int numbers[]             = {34, 20, 26, 28, 33, 23, 44, 40, 25, 10, 36, 14, 7, 29, 21, 27, 17, 13, 19, 24, 32, 41, 31};
			int expected[]            = {7, 10, 13, 14, 17, 19, 20, 21, 23, 24, 25, 26, 27, 28, 29, 31, 32, 34, 44 };

			clock_t start             = clock();
			vector <int> received     = TheLuckyNumbersLevelTwo().find( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}

		// custom cases

      case 31: {
			int numbers[]             = {137399504, 111382064, 531558886, 665519827, 112257950, 150719316, 346320068, 230882602, 148310835, 447812596, 650288361, 329965181, 161550745, 121225052, 195990057, 581787720, 139543355, 627058461, 629466942, 656552725, 275026758, 676040102, 101737675, 616227032, 666034540, 149002050, 640378273, 666395713, 546895175, 628775727, 127489416, 111743237, 502751019, 431457709};
			int expected[]            = {101737675, 676040102};

			clock_t start             = clock();
			vector <int> received     = TheLuckyNumbersLevelTwo().find( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
      case 36: {
			int numbers[]             = {201190239, 634409719, 630617807, 424263961, 147159970, 374900356, 371406802, 491406347, 87904743, 590387000, 286371430, 562052779, 402877421, 78493915, 101265960, 269716629, 689873034, 143368058, 466225280, 406370975, 508061148, 215724998, 493406434, 449834792, 353513816, 525140618, 699283862, 676511817, 576587538, 425096255, 311552497, 187390777, 327942985, 352681522};
			int expected[]            = {78493915, 699283862};

			clock_t start             = clock();
			vector <int> received     = TheLuckyNumbersLevelTwo().find( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-start );
		}
/*      case 9: {
			int numbers[]             = ;
			int expected[]            = ;

			clock_t start             = clock();
			vector <int> received     = TheLuckyNumbersLevelTwo().find( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
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
