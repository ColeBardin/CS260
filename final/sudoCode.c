/* Check if two graphs are isomorphic */
bool isIsomorphic(Graph G1, Graph G2) {
    /* If number of edges are different, return false */
    if(G1.numEdges != G2.numEdges){
        return false;
    }
    /* If number of nodes are different, return false */
    if(G1.numNodes != G2.numNodes){
        return false;
    }
    /* If their sorted degree sequences are not the same, return false */
    if(sort(G1.degreeSequence) != sort(G2.degreeSequence)){
        return false;
    }

    /* If the graphs are identical, they are isomorphic */
    if(G1.edges == G2.edges){
        return true;
    }

    /* Generate a list of all the new permutations of the numbers 0 to N
    ex: N = 2:
    [0,2,1], [1,0,2], [1,2,0], [2,0,1], [2,1,0] 
    Note that [0,1,2] is skipped because that would not create a new remapping */
    list permutations = generateNewPermutations(G1.numNodes - 1);
    /* Try each remapping permutation */
    for(newMapping in permutations){
        /* Make a new test graph */
        Graph T1;
        /* Iterate over each edge in G1 */
        for(edge in G1.edges){
            /* Remap the to and from edges to this permutation of mappings */
            T1.edges.add(newMapping[edge.to], newMapping[edge.from], edge.weight);
        }
        
        /* If the list of edges are now identical, graphs are isomorphic */
        if(T1.edges == G2.edges){
            return true;
        }
        delete T1;
    }
    /* If no permutation of remappings worked, graphs are not isomorphic */
    return false;
}