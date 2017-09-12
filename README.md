# Network-routing-algorithms
Course project for "Analysis of Algorithms" course
1. Random Graph Generation: Write subroutines that generate two kinds of “random”
graphs of 5000 vertices.
• In the first graph G1, every vertex has degree exactly 6.
• In the second graph G2, each vertex has edges going to about 20% of the other vertices.
• Randomly assign positive weights to edges in the graphs.

2. Heap Structure: Write subroutines for the max-heap structure. In particular, implementation 
should include subroutines for maximum, insert, and delete. 
• The vertices of a graph are named by integers 1, 2, . . ., n
• The heap is given by an array H[1..5000], where each element H[i] gives the name
of a vertex in the graph
• The vertex “values” are given in another array D[1..5000]. Thus, to find the value
of a vertex H[i] in the heap, we can use D[H[i]].

3. Routing Algorithms: Solve the Max-Bandwidth-Path problem for which I try have three different 
versions of implementations:
• An algorithm for Max-Bandwidth-Path based on a modification of Dijkstra’s algorithm without 
using a heap structure.
• An algorithm for Max-Bandwidth-Path based on a modification of Dijkstra’s
algorithm using a heap structure for fringes.
• An algorithm for Max-Bandwidth-Path based on a modification of Kruskal’s algorithm,
in which the edges are sorted by HeapSort.

4. Testing. Test the routing algorithms on 5 pairs of graphs, randomly generated using
the subroutines implemented in Step 1. For each generated graph, pick at least 5 pairs
of randomly selected source-destination vertices. For each source-destination pair (s, t) on
a graph G, do the following:
• add a path from s to t that goes through all vertices in the graph G — this is to
ensure that there are always paths connecting s and t, and randomly assign positive
weights to the new edges on the path.
• Run each of the three algorithms on the pair (s, t) and the graph G, and record
their running time (you should find a proper way to “count” the running time of an
algorithm).

