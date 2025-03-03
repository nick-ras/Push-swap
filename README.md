# Push_swap Project

## Description:
The **Push_swap** project challenges us to implement an efficient sorting algorithm for two stacks with the fewest operations possible. They have to be sorted from lowest to highest. The task is to sort a list of integers using as few operations as possible. The allowed operations are as followed:

  - `sa`: Swap the first two elements of stack A.
  - `sb`: Swap the first two elements of stack B.
  - `ss`: Perform both `sa` and `sb` simultaneously.
  - `pa`: Push the top element of stack B onto stack A.
  - `pb`: Push the top element of stack A onto stack B.

## Requirements:
You get the inputs as command line arguments, and you have to put them into a linked lists, and from there you can push and swap into a second linked list, in order to end up having them sorted in the first linked list.

## Chosen Strategy:
The basic algorithm i used is Longest Increasing Subsequence. In this algorithm you find the longest increasing subsecuence, which is a list of numbers, where the next always is bigger than the previous. For example in {2, 1, 3, 4, 2, 5}, its (1, 3, 4, 5). This gives an advantage cause when you push to the other stack, you can rotate the list, and only push the numbers from the longest increasing subsequence. This is one proven way to derease the number of operations. In order to make it more efficient i have made some tweaks, so it got within second highest scoring range.

## Key Restrictions & Challenges:
- **Limited Operations**: Unlike traditional sorting algorithms like quicksort or mergesort, this project requires creativity in using only a set of operations to sort the stack.
  
- **Optimization**: Recognizing patterns in the stack's order is crucial to minimizing the total number of moves. Special attention is needed when the stack has a large volume.
  
- **Edge Case Handling**: The project requires handling edge cases such as very small or large stacks, and when the integers are already partially sorted.

## How to Run:

To compile and run the program:

1. **Compile the program**: Use `make` to compile the program.

```bash
make
```
2, **Try it out with a list of numbers***
For example
```bash
./push_swap 77 33 98 76 23
```
this will show of operations that is needed to sort the numbers into stack one, but following the above rules. 
The output of the above is:
```bash
pb
pb
sa
pa
ra
ra
pa
ra
ra
```
So for example pb pushes the top element of stack A onto stack B, as described above.
Try it out with 500 numbesr if you want.
