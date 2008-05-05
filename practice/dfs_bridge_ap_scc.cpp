#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define dis first
#define low second
using namespace std;

vector< vector<int> > BCC;
stack<int> S;
vector< vector<int> > veze;
vector<int> AP;
vector< pair<int, int> > bs;
pair<int,int> info[10001];
int bio[10001];
int n, m, t;

void load() {
   scanf( "%d%d", &n, &m );
   veze.resize( n );
   for( int i = 0; i < m; ++i ) {
      int t1, t2;
      scanf( "%d%d", &t1, &t2 );
      veze[t1-1].push_back( t2-1 );
      veze[t2-1].push_back( t1-1 );
   }
}

int dfs( int node, int d ) {
   bio[node] = 1;
   info[node].dis = info[node].low = t++;
   
   int c = 0, tl;
   for( int i = 0; i < (int)veze[node].size(); ++i ) 
      if( !bio[ veze[node][i] ] ) {
         tl = dfs( veze[node][i], node );
         info[node].low <?= tl;

         // Articulation point
         if( tl >= info[node].dis ) 
            ++c;

         // Bridges
         if( tl > info[node].dis && ( t == info[node].dis+2 || AP.back() ==  veze[node][i] ) )
            bs.push_back( make_pair( node, veze[node][i] ) );

         // Biconnected components
         if( tl >= info[node].dis ) {            
            BCC.push_back( vector<int> () );
            if( tl == info[node].dis ) BCC.back().push_back( node );
            for( ; !S.empty() && info[S.top()].low >= info[node].dis; S.pop() ) 
               BCC.back().push_back( S.top() );
         }
      }
      else if( bio[ veze[node][i] ] == 1 && veze[node][i] != d ) 
         info[node].low <?= info[ veze[node][i] ].dis;

   if( !node && c >= 2 || node && c >= 1 )
      AP.push_back( node );
   
   S.push( node );
   
   bio[node] = 2;
   return info[node].low;
}


int main() {
   load();
   dfs( 0, 0 );
   
   cout << "DFS:" << endl;
   for( int i = 0; i < n; ++i )
      printf( "%d disc: %d lowlink: %d\n", i+1, info[i].dis, info[i].low );

   cout << "Articulation points:" << endl;
   for( int i = 0; i < (int)AP.size(); ++i ) 
      cout << AP[i]+1 << endl;

   cout << "Bridges:" << endl;
   for( int i = 0; i < (int)bs.size(); ++i ) 
      cout << bs[i].first+1 << " " << bs[i].second+1 << endl;

   cout << "Biconnnected components:" << endl;
   for( int i = 0; i < (int)BCC.size(); ++i, cout << endl ) 
      for( int j = 0; j < (int)BCC[i].size(); ++j ) 
         cout << BCC[i][j]+1 << " ";
   
   return 0;
}
