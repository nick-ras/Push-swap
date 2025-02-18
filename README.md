# Push_swap Project

## Description:
The **Push_swap** project challenges us to implement an efficient sorting algorithm for two stacks with the fewest operations possible. The task is to sort a list of integers using only three operations: `sa` (swap the top two elements of stack A), `sb` (swap the top two elements of stack B), and `pa` (push the top element of stack B onto stack A), `pb` (push the top element of stack A onto stack B), along with a combined `ss`, `pa`, or `pb` operation for efficiency. The goal is to write a program that sorts the integers while minimizing the number of operations used. This project emphasizes algorithmic thinking and optimization techniques.

## Project Requirements:
- **Input**: A list of integers (positive or negative) provided as command-line arguments. The integers are to be pushed into two stacks, and the sorting process should begin with them.

- **Operations**:
  - `sa`: Swap the first two elements of stack A.
  - `sb`: Swap the first two elements of stack B.
  - `ss`: Perform both `sa` and `sb` simultaneously.
  - `pa`: Push the top element of stack B onto stack A.
  - `pb`: Push the top element of stack A onto stack B.

- **Objective**: Sort the list of integers in ascending order using the least number of operations. Efficiency is key, as the project is designed to test algorithm optimization and understanding of sorting mechanisms.

## Chosen Strategy:
The algorithm is based on a math video recommendation, implemented with some additional tweaks for efficiency. It was a complex project requiring constant attention to the algorithm to avoid mistakes in the sorting process. The focus was on handling stack patterns to minimize redundant moves, especially with a large number of elements.

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
