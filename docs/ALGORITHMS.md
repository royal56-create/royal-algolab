# Complexity reference

| Algorithm | Average time | Worst time | Extra space |
|---|---:|---:|---:|
| Bubble sort | O(n²) | O(n²) | O(1) |
| Selection sort | O(n²) | O(n²) | O(1) |
| Insertion sort | O(n²) | O(n²) | O(1) |
| Merge sort | O(n log n) | O(n log n) | O(n) |
| Quick sort (standard library sort) | O(n log n) | O(n log n) | implementation-dependent |
| Linear search | O(n) | O(n) | O(1) |
| Binary search | O(log n) | O(log n) | O(1) |

Adjacency-list BFS and DFS are O(V + E). Dijkstra with a binary heap is
O((V + E) log V) for non-negative edge weights.
