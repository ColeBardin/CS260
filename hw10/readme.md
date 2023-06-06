
# CS260-001: Homework 10

By Cole Bardin : CAB572

## Questions

### What was the most difficult problem you encountered doing this assignment?

Honestly, nothing was that challenging. But if I had to choose, finding the bridging nodes was the most difficult.

### How did you resolve it?

I resovled this in my helper function named `findBridgingNodes`. This function iterates through the unique edges in the adjacency matrix. If it finds an edge with only one node in the MST Node LinkedList, it adds the edge to the list. It always will enter it as the old node as nodeA and new node as nodeB. This allowed me to easy parse out the desired node values in the minimum Heap value.
