#include <iostream>  
#include <fstream>  
#include <vector>  
#include <algorithm>  
#include <queue>  
  
using namespace std;  
  
queue <int> q;  
vector <bool> pTown;  
  
class Graph{  
    int V;  
    vector< pair<int, int> > *l;  
public:  
    Graph(int V){  
        this->V = V;  
        l = new vector< pair<int, int> >[V];  
    }  
    void addEdge(int x, int y, int z){  
        l[x].push_back(make_pair(y, z));  
        l[y].push_back(make_pair(x, z));  
    }  
    void findAvailablePaths(int x, int w){  
        for(vector<pair<int, int> > :: iterator it = l[x].begin(); it != l[x].end(); it++){  
            if(it->second <= w && !pTown[it->first - 1]){  
                q.push(it->first);  
                pTown[it->first - 1] = true;  
            }  
        }  
    }  
};  
int n, m, u, v, w;  
vector<int> minL;  
vector<bool> falseState;  
int main () {  
    ifstream input ("smalltank.in");  
    ofstream output;  
    output.open("smalltank.out", ios::out | ios::trunc);  
    input>>n>>m;  
    Graph g(n+1);  
    for(int i = 0; i < n; i++){  
        minL.push_back(100000);  
        falseState.push_back(false);  
    }  
    for(int i = 0; i < m; i++){  
        input>>u>>v>>w;  
        g.addEdge(u, v, w);   
        if(minL[u-1]>=w){  
            minL[u-1]=w;  
        }  
        if(minL[v-1]>=w){  
            minL[v-1]=w;  
        }  
    }  
    int max = *max_element(minL.begin(), minL.end());  
    do{  
        pTown.assign(falseState.begin(), falseState.end());  
        q.push(1);  
        do{  
            g.findAvailablePaths(q.front(), max);  
            q.pop();  
        }while(!q.empty());  
        max++;  
    }while(find(pTown.begin(), pTown.end(), false) != pTown.end());  
    output<<max-1;  
    output.close();  
    input.close();  
    return 0;  
} 
