#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m, n;

struct cmp {
  bool operator()(const pair<int, int>& A, const pair<int, int>& B) {
    if( A.first != B.first )
      return A.first > B.first;
    return A.second < B.second;
  }
};

vector< vector<int> > plist;

vector< vector<pair<int, int> > > pref;

int get_pos(const vector<int>& v, int x) {
  for( int i = 0; i < (int)v.size(); ++i )
    if( v[i] == x )
      return i;
  return -1;
}

void calc_pref(int A, int B) {
  int lenA = plist[A].size();
  int lenB = plist[B].size();
  int score = 0;
  for( int i = 0; i < lenA; ++i ) {
    int posB = get_pos(plist[B], plist[A][i]);
    int base_val = lenA-i;
    if( posB == -1 )
      score += base_val;
    else if( posB == i )
      score += base_val*base_val;
    else if( i < posB )
      score += base_val;
  }
  pref[A].push_back(make_pair(score, B));
}

void solve() {
  pref.resize(m);
  for( int a = 0; a < m/2; ++a )
    for( int b = m/2; b < m; ++b ) {
      calc_pref(a, b);
      calc_pref(b, a);
    }

  for( int i = 0; i < m/2; ++i )
    if( i < m/2 )
      sort(pref[i].begin(), pref[i].end(), cmp());

  /*
  for( int i = 0; i < m; ++i, printf("\n") )
    for( int j = 0; j < (int)pref[i].size(); ++j )
      printf("(%2d %2d)", pref[i][j].first, pref[i][j].second);
  */

  vector<int> assigned(m, -1);
  vector<int> from(m, 0);
  queue<int> upper;

  int itr = 0;

  for( int i = 0; i < m/2; ++i )
    upper.push(i);

  while( !upper.empty() ) {
    int a = upper.front();
    upper.pop();
    if( assigned[a] != -1 || from[a] >= (int)pref[a].size() )
      continue;
    upper.push(a);

    int b = pref[a][from[a]++].second;

    ++itr;

    if( assigned[b] == -1 ) {
      assigned[b] = a;
      assigned[a] = b;
      //printf("Paired(%d %d)\n", a, b);
    }
    else if( pref[b][a].first > pref[b][assigned[b]].first
             || pref[b][a].first == pref[b][assigned[b]].first
             && pref[b][a].second < pref[b][assigned[b]].second) {
      assigned[assigned[b]] = -1;
      //printf("Unpaired(%d %d)\n", assigned[b], b);
      assigned[b] = a;
      assigned[a] = b;
      //printf("Paired(%d %d)\n", a, b);
    }
  }

  //fprintf(stderr, "Iterations: %d\n", itr);

  vector< pair<int, int> > res(m/2);
  for( int i = 0; i < m/2; ++i )
    res[i] = make_pair(assigned[i+m/2], i+m/2);

  sort(res.begin(), res.end());

  for( int i = 0; i < m/2; ++i )
    printf("%d %d\n", res[i].first, res[i].second);
}

void input() {
  scanf("%d%d\n", &m, &n);
  plist.resize(m);
  for( int i = 0; i < n; ++i ) {
    char buff[1024];
    fgets(buff, sizeof(buff), stdin);
  }
  for( int offset = 0; offset ) ; //TODO:
  for( int i = 0; i < m; ++i ) {
    int id; char buff[1024];
    scanf("%d", &id);
    //TODO:
  }
}

int main() {
  input();
  solve();
  return 0;
}
