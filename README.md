Push_swap Project
Description:
The Push_swap project challenges us to implement an efficient sorting algorithm for two stacks with the fewest operations possible. The task is to sort a list of integers using only three operations: sa (swap the top two elements of stack A), sb (swap the top two elements of stack B), and pa (push the top element of stack B onto stack A), pb (push the top element of stack A onto stack B), along with a combined ss, pa, or pb operation for efficiency. The goal is to write a program that sorts the integers while minimizing the number of operations used. This project emphasizes algorithmic thinking and optimization techniques.

Project Requirements:
Input: A list of integers (positive or negative) provided as command-line arguments. The integers are to be pushed into two stacks, and the sorting process should begin with them.
Operations:
sa: Swap the first two elements of stack A.
sb: Swap the first two elements of stack B.
ss: Perform both sa and sb simultaneously.
pa: Push the top element of stack B onto stack A.
pb: Push the top element of stack A onto stack B.
Objective: Sort the list of integers in ascending order using the least number of operations. Efficiency is key, as the project is designed to test algorithm optimization and understanding of sorting mechanisms.

Chosen strategy:
I dont recall the strategy, i just remember i was recommended a math video, and i implemented that in code, with some extra tweaks to make it efficient enough to have almost perfect mark. I remember this as the most complicated project, because you always had to have the full view of the algorithm in your head, in order not to make mistakes in the proces.


Key Restrictions & Challenges:
Limited Operations:
Unlike more traditional sorting algorithms like quicksort or mergesort, the solution requires creativity in utilizing these operations to minimize the total number of moves.

Optimization:
This involves recognizing patterns in the stack’s order and creating strategies to minimize redundant moves. Especially when stack has a large volume.

Edge Case Handling:
The project requires special attention to edge cases:
