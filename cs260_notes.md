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
