	#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
using namespace std;
template <typename T>
class Graph{
    // define data types
    map<T,list<T>> adjList;
    map<int,bool>node_details;
    stack<int> topo_stack;
    map<int,bool> topo_map;
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
    // at first i put T return type instead of void bcoz i thought that we need a return type for recurison but that was not true 
    void Dfs (T inception){
        // marks it visited
        node_details[inception]=true;
        cout<<inception<<" ";
        for (int a:adjList[inception]){
            if(!node_details[a]){
                Dfs(a);
            }
        }
        //return 0;   // does not affect my code at all if i return 0 or 1 or anything.
        
    }
    void topo_sorting(T inception){
        for(int a:adjList[inception]){
            if(!topo_map[a]){
                topo_sorting(a);
            }
           
        }
        //cout<<inception<<" ";
        topo_map[inception]=true;
        topo_stack.push(inception);
        
    }
    void print_stack(){
        while(!topo_stack.empty()){
            cout<<topo_stack.top();
            topo_stack.pop();
        }
    }
};




int main() {
	Graph<int> g;
	g.addEdge(1,2,false);
	g.addEdge(1,3,false);
	g.addEdge(2,4,false);
	g.addEdge(3,4,false);
	
	
	g.topo_sorting(1);
	g.print_stack();
	return 0;
      

    
}
