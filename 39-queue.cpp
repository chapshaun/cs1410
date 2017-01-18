/*
queue

FIFO: first in first out

buffer
	communication
	printer

two types
	static: fixed size
	dynamic: not fixed

two options
	enqueue: adding something from front
	dequeue: adding something from end

head and tail pointer: both point to nullptr

	with dynamic
		you add it, have the node point to it
		have the tail point to it
		always append at the end

	with static:
		allocate a fixed size of memory
			keep track of size, front, and back

			capacity: 
			size:
			front: -1
			back: -1

*/