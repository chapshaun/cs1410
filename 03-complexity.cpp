// Complexity
//	Criteria:
//		Space (how much memory something takes)
//		Time (how long does it take)



/*
'size' of an instance (how much memory does a single data take)

we can't look at how many elements in the array; we look at the size of each element in the array


basic Step (something that will exe in constant time)
	lines 1 and 2 are basic (they run at constant time)
	lines 4 and 5 are basic

1	sum = 0
2	k = 0
3	while k < n
4		sum = sum +2[k]
5		k = k + 1
6	end while


when n = 10; 2 basic steps; + 2; 22
when n = 100; 2 basic steps; + 2; 202

how long it takes is proportional to n


Worst Case, Average Case, Asymptotic Case

worst-case: 	what is the worst-case
average: 		normal
asymptotic: 	growth rate of complexity of an algorithm

worst-case:
	binary search: no value
			intitialization - 1 time cost
			each iteration = L (eleminate 1/2)
			# of steps is log_2(n)
			best case is 1 (the number is in the middle)

asymptotic:

	Big-0 "order":

	O(1)
	O(log_2(n)
	O(n)
	O(nlog(n))
	O(n^2)
	O(n^3)
*/
