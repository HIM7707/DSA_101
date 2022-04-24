#include <iostream>
#include <list>
using namespace std;

class Graph{
    // variables
    int V;
    list<int> *L;
    // now member functions
public:
    Graph(int v){
        V=v;
        L = new list<int>[V];
    }
    
    void addEdge(int u,int v,bool bidir = true){
        L[u].push_back(v);
        if (bidir == true){
            L[v].push_back(u);
        }
    }
    void print_the_graph(){
        for (int i=0;i<V;i++){
            cout<<i<<"->";
            for(int vertex:L[i]){
                cout<<vertex<<" ";
            }
            cout<<endl;
        }
    }
};




int main() {
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,3);
	
	g.print_the_graph();
	return 0;
      

    
}
