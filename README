Bellman-Ford vs. Dijkstra algos
===============================

by Andrew Hoyle

usage
-----
There are two directories in this file.  One has Dijkstra’s algorithm, and the other has the Bellman-Ford algorithm.  To test each one, descend into the directory in which it resides, and then type g++ *.cpp.  Now, you can type the name of one of the many test input files located in the folder in argv[1].  Each of the directories has copies of the same test input files to test the programs.

Descriptions of one of the test input files that make the graphs:

* “exampleNeg” has a negative weight cycle.  BF should indicate that it can’t find an optimal solution.

There are other graphs to test data on already in each algorithm folder, and any graph can be made on a blank file following the layout of:

	#_of_vertices_in_graph start_node# end_node# weight_val

…(continue line above till you’re done with edges)
	
results, runtimes
-----------------
Dijkstra’s algorithm does NOT work on graphs with negative weights because it only considers the u value pulled from the queue ONE time before putting it into set S.  When it relaxes the v vertices adjacent to u, the next shortest path will only be one edge away if the values are positive, but if negative edge weights are allowed, the least-weighted path sum between u and v may be more than one edge away.  The outer loop in Bellman-Ford line 2 allows for BOTH u and v to be reconsidered and relaxed up to |G.V|-1 times.  (Number of nodes-1 assuming graph is connected.)

If there is a directed negative cycle in a graph for which you are trying to find the shortest path values, the minimum value could keep descending into negative infinity.  The latter part of the BF algorithm runs a check for this scenario after every node has been allowed to relax up to |G.V|-1 times.  If it detects a situation in which the v.key value is greater than u.key + their weight, the program knows that there is a negative-edge cycle in the graph and that a minimum cannot be found.  The next modification for this algorithm would be to have it assign negative infinity to those nodes involved in the negative cycle.

Bellman-Ford runs in O(|V|*|E|), Dijkstra runs in O(V^2) or O(|E|+|V|lg|V|) if you use a heap to sort the weights.  The u=extract_min(Q) portion of my Dijkstra code does not utilize a heap because creating a decrease key function was quite challenging.  I instead used a naïve bubble sort to get the min from an array made of simpVert structs.  If you can get Dijkstra’s algorithm running with the heap, it is preferable to use it for finding POSITIVE paths because of its better running time.  If you know that there are negative weights, then you must use Bellman-Ford, otherwise, negative edges will be underutilized.

