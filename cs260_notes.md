# CS260 Notes

4/4/2023

## Binary Search
Use target, array, start, stop
if start > stop, bad inputs, do not search

## Bubble sort

"terrible stupid" - mark boady

Search list for false comps, switch elements so the comparisons are true

### Bubble Sort Setup:

Helper funcs to determine if elements are wrong and to swap them

Bubble Function for the hw:

// O(size)
bool bubble(array, size) {
	uint8_t i = 0; // O(1)
	bool swapped = false; // O(1)
	// O(1) * O(size-1) = O(size) 
	for (i; i < size - 1; i++) { // O(1)
		/* O(1 + 1 + 1 = 3) = O(1) */
		if (wrong(array[i], array[i+1])) { // O(1)
			swap(array, i, i+1); // O(1)
			swapped = true; // O(1)
		}
	}
	return swapped; // O(1)
}

Bubble sort will only 'bubble' larger numbers to the top one at a time ! 

it is very inefficient as mark board stated

### Analyzing the runtime!

Assignment commands and general statements are constant time O(1) as in one instruction

If statements WEC count all lines inside

### Total algorithm runtime : O(size^2)

Since bubble runtime WEC is O(size) needs to be run size times in WEC

Therefore O(size^2)

## Hash Tables

Using strings as indices of an array

### Hash Function

`hash(v, n)`

v: arbitrary index

n: size of the array

Maps arbitrary value to index of the array

For example, for integer values of v, return v % n for mapping

For values with the same v % n result, we can implement queues/linked list to populate the cells

Collision: when two vals are supposed to go to the same place in the array 

## Trees

Like linked lists except nodes can have multiple children

Movement can only be done in one direction. If movement was bidirectional, it would be a Graph

### Unary tree

Linked list

All LL are trees, but not all trees are LL

### Binary tree

Every node has at most 2 children

### Terminology

Root - Starting node

Leaves - End nodes that do not point to anything else

Branches - Middle nodes 

Parent / Child / Sibling - Relations

Ancestor / Descendant - Distant relation (Append w/ Proper to exclude yourself)

## Binary Search Tree

Sortable and easily insertable

Order in which elements are inserted creates the unique tree

### Requirements

Left is always smaller

Right is always larger

### Notes

#### Best Case

Balanced trees

Number of nodes: n = 2^(h+1) - 1

Height: h = log2(n+1) - 1

#### Worst Case

All elements on one side

log2(n) <= h <= n - 1

### Deleting Nodes

If deleting Root, replace it with Minimum on Right or Maximum on the Left
