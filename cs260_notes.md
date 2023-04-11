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

Bubble Function:

void bubble(array, size) {
	for (uint8_t i=0; i < size - 1; i++) {
		if (wrong(array[i], array[i+1])) {
			swap(array, i, i+1);
		}
	}
	return;
}
