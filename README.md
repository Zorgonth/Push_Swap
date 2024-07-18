# PUSH_SWAP
Push_swap is a program meant to sort a stack of intergers using only two stacks with the following contorls:
- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
- pb (push b): Take the first element at the top of a and put it at the top of b.
- ra (rotate a): Shift up all elements of stack a by 1.
- rb (rotate b): Shift up all elements of stack b by 1.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
- rrr : rra and rrb at the same time.
## Algorithms
For Smaller amount of intergers (between 1 and 5 numbers) i have a simple checker to choose the best way to sort them. And also i have used Int Arrays which are reallocated everytime if needed to be memory friendly.
But for larger amounts of intergers(more than 5 numbers) I have used Rdix sortring algorithm. `Radix` sort is an efficient algorithm to sort non-negative integers with time complexity O (n).

## USAGE
As Always all you need to compile to code is to using the following command:
```
$make
```
Then to use it all you have to do is run it as such:
```
./push_swap "1 2 3 4 5 6 7"
```
Or you can input it as such:
```
./push_swap 1 3 5 2 4 4
```
Or you can use a combination of both inputs. Duplicates aren't allowed and Of course if the input is already sorted the program will state that!.
