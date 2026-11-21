#pragma once
#include <algorithm>
#include <stdexcept>
#include <vector>
namespace royal {
struct SortStats { std::size_t comparisons=0, swaps=0; };
inline SortStats bubbleSort(std::vector<int>& a) {
 SortStats s;
 for(std::size_t n=a.size();n>1;--n){bool changed=false;for(std::size_t i=1;i<n;++i){++s.comparisons;if(a[i-1]>a[i]){std::swap(a[i-1],a[i]);++s.swaps;changed=true;}}if(!changed)break;}return s;
}
inline SortStats selectionSort(std::vector<int>& a) {
 SortStats s;for(std::size_t i=0;i<a.size();++i){auto m=i;for(std::size_t j=i+1;j<a.size();++j){++s.comparisons;if(a[j]<a[m])m=j;}if(m!=i){std::swap(a[i],a[m]);++s.swaps;}}return s;
}
inline SortStats insertionSort(std::vector<int>& a) {
 SortStats s;for(std::size_t i=1;i<a.size();++i){int key=a[i];std::size_t j=i;while(j>0){++s.comparisons;if(a[j-1]<=key)break;a[j]=a[j-1];--j;++s.swaps;}a[j]=key;}return s;
}
inline void mergeSort(std::vector<int>& a) {
 if(a.size()<2)return;auto m=a.size()/2;std::vector<int> l(a.begin(),a.begin()+static_cast<std::ptrdiff_t>(m)),r(a.begin()+static_cast<std::ptrdiff_t>(m),a.end());mergeSort(l);mergeSort(r);std::merge(l.begin(),l.end(),r.begin(),r.end(),a.begin());
}
inline void quickSort(std::vector<int>& a) { std::sort(a.begin(),a.end()); }
inline int linearSearch(const std::vector<int>& a,int x){for(std::size_t i=0;i<a.size();++i)if(a[i]==x)return static_cast<int>(i);return -1;}
inline int binarySearch(const std::vector<int>& a,int x){if(!std::is_sorted(a.begin(),a.end()))throw std::invalid_argument("Binary search needs sorted input");auto i=std::lower_bound(a.begin(),a.end(),x);return i!=a.end()&&*i==x?static_cast<int>(i-a.begin()):-1;}
}
