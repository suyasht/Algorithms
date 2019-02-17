------------------------------Task A---------------------------------

Step 1: We create the hello.c and makefile and run make command to compile the hello.c. This creates the module file by the name "hello.kc".

Step 2: Now, we load this file in the kernel with the command 'insmod ./hello.kc". To check, we can run "lsmod" which lists all the modules, and we can see our module "hello".

Step 3: Using "dmesg" we can see that our module has been added as we can see "Hello World!".

Step 4: To remove the module form the kernel, we use "rmmod hello.kc", and then run dmesg and we see "GOodbye, Cruel world!" meaning that the module has left the kernel.

A named pipe, is a pipe created in UNIX, which behaves in FIFO manner. One of the difference between the regualr pipe and named pipe is that the regular pipe lasts as long as the process lasts, but named pipe can last longer than a lifetime of process associated with it.

To create a UNIX pipe, run command "mkfifo <pipename>". This creates a pipe that has to be open at both end simulteneously to function.

------------------------------Task B---------------------------------


1: When producer is killed and consumer keeps running.

Explanation: When this happens, the execution moves to the else block in the while condition in the consumer code.
Because the read operation is success but the number of bytes read are 0, it prints out "Success" and ret=0.
This happens because the comsuer reads from a queue, where there is no data as the producer has died.

2: When consumer is killed and producer keeps running.

Explanation: When this happens, it means that the pipe is broken which can be seen in the error printed on the console, and the write functions returns -1(error), which means that it was an error executing the write() call. 
The pipe broken error is there because the pipe can exist only when there is a producer producing the data and a consumer consuiming it. If/when either one of the producer or consumer dies, the pipe ceases to exist.

3: One consumer, multiple producers.(1C, 2P)

Observation: The consumer reads two values from the pipe at a time, one for each consumer.
Explanation: Both producers keep on writing the data in the pipe randomly. The consumer, reads the data in the pipe in FIFO format, and since there is a sleep(1), it prints the value(s) read after a sleep of 1 sec.

4: Multiple Consumers, one Producer. (2C, 1P)

Observation: Both consumers read the data from the pipe in FIFO order.
Explanation: The producer keeps pushing the data in the queue, and both the consumers read from the the queue in a scheduled manner in FIFO order. The OS scheduling algorithm takes care of this scheduling.

5: Multiple Consumers, Multiple Producer (2C, 2P)

Observation: Both the consumer reads the data, and both producers produce the data.

Explanation: Both the consumers reads in FIFO order as the data is inserted by the producers. This is so, as the producer keeps entering the data in the queue, the consumers are scheduled bu the CPU to read one by one.


Q: Do you see any race conditions? 
Ans: No, becuase the there is no condition during this, when both read and write at the same time becasue this scheduling is handled by the CPU.


------------------Brief Plan for Task C--------------------------

From the looks of it, Task C is basically a combination of Task A and B.

Task B teaches us how the Consumer and Producer problem works in different scenarios, and Task A is to learn how to build our own kernel modules.

For Task C, we will create a kernel module that mimics the UNIX pipe, and load it into the kernel. Then using the producer code we will put data in the pipe module, and on the the other end the consumer will consume the data, and make sure that all the scenarios are taken care of.





