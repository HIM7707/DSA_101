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
    void topological_sort_bfs(){
        // data structures required
        map <T,bool> visited;
        queue<T> Q;
        map <T,int> indegree;
        
        // giving initial values;
        for(auto a:adjList){
            // a contains both lhs and rhs of adjList
            T t = a.first;
            visited[t]=false;
            indegree[t]=0;
        }
        // assigning indegrees
        for(auto b: adjList){
            T t1 = b.first;
            for(T a:adjList[t1]){
                indegree[a]++;
            }
        }
        // find the 0 indegrees
        for(auto i:indegree){
            T t2 = i.first;
            if(indegree[t2]==0){
                Q.push(t2);
            }
        }
        // start with the real algorithn
        while(!Q.empty()){
            T node = Q.front();
            Q.pop();
            cout<<node<<" ";
            for(T neighbour:adjList[node]){
                indegree[neighbour]--;
                
                if(indegree[neighbour]==0){
                    Q.push(neighbour);
                }
            }
        }
    }
    
};




int main() {
	Graph<int> g;
	g.addEdge(1,2,false);
	g.addEdge(1,3,false);
	g.addEdge(2,4,false);
	g.addEdge(3,4,false);
	
	// calling todo_sorting_dfa + printing.
/*	g.topo_sorting_dfa(1);
	g.print_stack();
	return 0;*/
	g.topological_sort_bfs();
	return 0;
      

    
}
