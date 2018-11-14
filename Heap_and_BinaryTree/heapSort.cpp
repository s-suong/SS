// Sorts anArray[0..n-1].
heapSort (anArray: ArrayType, n:integer)
// Build initial heap
  for (index = n / 2 down to 0)
  {
// Assertion: The tree rooted at index is a semiheap
    heapRebuild (index, anArray, n)
// Assertion: The tree rooted at index is a heap
  }

// Assertion: anArray[0] is the largest item in heap anArray[0..n-1]
// Move the largest item in the Heap regionthe root anArray[0] to the beginning
// of the Sorted region by swapping items and then adjusting the size of the regions
Swap anArray[0]
     and
       anArray[n - 1]
       heapSize = n - 1		// Decrease the size of the Heap region, expand the Sorted region
       while (heapSize > 1)
  {
// Make the Heap region a heap again
    heapRebuild (0, anArray, heapSize)
// Move the largest item in the Heap regionthe root anArray[0] to the beginning
// of the Sorted region by swapping items and then adjusting the size of the regions
      Swap anArray[0] and anArray[heapSize - 1] heapSize	
// Decrease the size of the Heap region, expand the Sorted region
  }