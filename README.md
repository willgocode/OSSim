# OSSim
A program to simulate processes and their journey through the pipeline.
The simulator uses a continguous worst-fit memory allocation technique.

# Compiling:
Use the command make all in order to compile.

# Running:
Type h in the program for help. The recognized commands here are:

A - Arriving process. This adds a new process to the CPU.
d(number) - Send current process to disk queue.
p(number) - Send current process to printer queue.
D(number) - Sends process currently using disk back to CPU.
P(number) - Sends process currently using printer back to CPU.
t - Terminates current running process in CPU.

S - Snapshot mode. The following commands are supported in this mode: 
	m - memory status. Will print out the processes that are in memory.
	i - io queues. Will print out the processes that are waiting for the IO Device.
	r - ready queue. Will print out the processes that are in CPU ready queue.

