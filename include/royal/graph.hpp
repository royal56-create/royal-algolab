#pragma once
#include <functional>
#include <limits>
#include <queue>
#include <stdexcept>
#include <utility>
#include <vector>
namespace royal {
class Graph {
 std::vector<std::vector<std::pair<int,int>>> edges_;
 void dfsWalk(int u,std::vector<bool>& seen,std::vector<int>& out)const{seen[u]=true;out.push_back(u);for(auto [v,w]:edges_[u]){(void)w;if(!seen[v])dfsWalk(v,seen,out);}}
 void check(int v)const{if(v<0||v>=size())throw std::out_of_range("Vertex outside graph");}
public:
 explicit Graph(int n):edges_(n<0?throw std::invalid_argument("Negative vertex count"):static_cast<std::size_t>(n)){}
 int size()const noexcept{return static_cast<int>(edges_.size());}
 void addEdge(int u,int v,int w=1,bool undirected=true){check(u);check(v);if(w<0)throw std::invalid_argument("Dijkstra needs non-negative weights");edges_[u].push_back({v,w});if(undirected)edges_[v].push_back({u,w});}
 std::vector<int> bfs(int start)const{check(start);std::vector<bool>s(size());std::queue<int>q;std::vector<int>o;s[start]=true;q.push(start);while(!q.empty()){int u=q.front();q.pop();o.push_back(u);for(auto [v,w]:edges_[u]){(void)w;if(!s[v]){s[v]=true;q.push(v);}}}return o;}
 std::vector<int> dfs(int start)const{check(start);std::vector<bool>s(size());std::vector<int>o;dfsWalk(start,s,o);return o;}
 std::vector<long long> dijkstra(int start)const{check(start);const long long inf=std::numeric_limits<long long>::max()/4;std::vector<long long>d(size(),inf);using P=std::pair<long long,int>;std::priority_queue<P,std::vector<P>,std::greater<P>>q;d[start]=0;q.push({0,start});while(!q.empty()){auto [du,u]=q.top();q.pop();if(du!=d[u])continue;for(auto [v,w]:edges_[u])if(du+w<d[v]){d[v]=du+w;q.push({d[v],v});}}return d;}
};
}
