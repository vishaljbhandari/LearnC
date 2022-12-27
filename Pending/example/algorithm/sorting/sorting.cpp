A Sorting Algorithm is used to rearrange a given array or list elements according to a comparison operator on the elements.
The comparison operator is used to decide the new order of element in the respective data structure.

What is in-place sorting?
An in-place sorting algorithm uses constant extra space for producing the output (modifies the given array only).
It sorts the list only by modifying the order of the elements within the list.
For example, Insertion Sort and Selection Sorts are in-place sorting algorithms as they do not use any additional space for sorting the list and a typical implementation of Merge Sort is not in-place, also the implementation for counting sort is not in-place sorting algorithm.

What are Internal and External Sortings?
When all data that needs to be sorted cannot be placed in-memory at a time, the sorting is called external sorting.
External Sorting is used for massive amount of data.

Merge Sort and its variations are typically used for external sorting. Some external storage like hard-disk, CD, etc is used for external storage.
When all data is placed in-memory, then sorting is called internal sorting.

// ====================================

External Sorting
External sorting is a term for a class of sorting algorithms that can handle massive amounts of data.
External sorting is required when the data being sorted do not fit into the main memory of a computing device (usually RAM) and instead they must reside in the slower external memory (usually a hard drive).
External sorting typically uses a hybrid sort-merge strategy. In the sorting phase, chunks of data small enough to fit in main memory are read, sorted, and written out to a temporary file.
In the merge phase, the sorted sub-files are combined into a single larger file.

One example of external sorting is the external merge sort algorithm, which sorts chunks that each fit in RAM, then merges the sorted chunks together.
We first divide the file into runs such that the size of a run is small enough to fit into main memory.
Then sort each run in main memory using merge sort sorting algorithm. Finally merge the resulting runs together into successively bigger runs, until the file is sorted.

// ==========================================

Stability in sorting algorithms
Stability is mainly important when we have key value pairs with duplicate keys possible (like people names as keys and their details as values).
And we wish to sort these objects by keys.

What is it?
A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted.

Formally stability may be defined as,
Let A be an array, and let < be a strict weak ordering on the elements of A.
A sorting algorithm is stable if-
i < j\:\:and\:\:A[i]\equiv A[j]\:\:implies\:\:\pi (i) < \pi (j)
where \pi is the sorting permutation ( sorting moves A[i] to position \pi(i) )
Informally, stability means that equivalent elements retain their relative positions, after sorting.

Do we care for simple arrays like array of integers?
When equal elements are indistinguishable, such as with integers, or more generally, any data where the entire element is the key, stability is not an issue.
Stability is also not an issue if all keys are different.

Here the relative order between different tuples is maintained. It may be the case that the relative order is maintained in an Unstable Sort but that is highly unlikely.

Which sorting algorithms are stable?
Some Sorting Algorithms are stable by nature, such as Bubble Sort, Insertion Sort, Merge Sort, Count Sort etc.
Comparison based stable sorts such as Merge Sort and Insertion Sort, maintain stability by ensuring that-
Element A[j] comes before A[i] if and only if A[j] < A[i], here i, j are indices and i < j.
Since i<j, the relative order is preserved if A[i]\equiv A[j] i.e. A[i] comes before A[j].
Other non-comparison based sorts such as Counting Sort maintain stability by ensuring that the Sorted Array is filled in a reverse order so that elements with equivalent keys have the same relative position.
Some sorts such as Radix Sort depend on another sort, with the only requirement that the other sort should be stable.

Which sorting algorithms are unstable?
Quick Sort, Heap Sort etc., can be made stable by also taking the position of the elements into consideration. This change may be done in a way which does not compromise a lot on the performance and takes some extra space, possibly \theta(n).

Can we make any sorting algorithm stable?
Any given sorting algo which is not stable can be modified to be stable. There can be sorting algo specific ways to make it stable, but in general, any comparison based sorting algorithm which is not stable by nature can be modified to be stable by changing the key comparison operation so that the comparison of two keys considers position as a factor for objects with equal keys.

stable Sorting algorithms
Merge Sort, Insertion Sort, Bubble Sort, Binary Tree Sort.

Unstable Sorting Algorithm
QuickSort, Heap Sort, Selection

// =============================================

Algorithm Time Complexity (Best Average Worst)
Selection Sort Ω(n^2) θ(n^2) O(n^2)
Bubble Sort Ω(n) θ(n^2) O(n^2)
Insertion Sort Ω(n) θ(n^2) O(n^2)
Heap Sort Ω(n log(n)) θ(n log(n)) O(n log(n))
Quick Sort Ω(n log(n)) θ(n log(n)) O(n^2)
Merge Sort Ω(n log(n)) θ(n log(n)) O(n log(n))
Bucket Sort Ω(n+k) θ(n+k) O(n^2)
Radix Sort Ω(nk) θ(nk) O(nk)

