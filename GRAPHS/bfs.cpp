#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;
template <typename T>
class Graph{
    // define data types
    map<T,list<T>> adjList;
    // mamber function
public:    
    Graph(){
    }
    void addEdge(T u,T v, bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void print(){
        for(auto i:adjList){    // way to traverse a graph..
            cout<<i.first<<"->";
            for(T j:i.second){  // way to traverse a list.
                cout<<j<<",";
            }
            cout<<endl;
        }
        
    }
    void bfs(T inception){
        queue<int> Q;
        map <T,bool> visited;
        Q.push(inception);
        visited[inception]=true;
        
        while(!Q.empty()){
            T curr = Q.front();
            cout<<curr<<",";
            Q.pop();
            // add adjacent values to queue.
            
            for( T temp : adjList[curr]){
                if(visited[temp]==false){
                    Q.push(temp);
                    visited[temp]=true;
                }
            }
        }
    }
};




int main() {
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(3,4);
	
	
	g.bfs(0);
	return 0;
      

    
}