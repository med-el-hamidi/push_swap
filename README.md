# Push_swap

Push_swap is a sorting algorithm project from [1337 School](https://1337.ma). The goal is to sort a stack of integers using two stacks (`A` and `B`) with a limited set of operations, aiming for the most efficient solution.

## Algorithm Used

This implementation is based on the **Chack algorithm**, an optimized method for sorting with a minimal number of moves.

## Features

- Efficient sorting of integers using stack-based operations.
- Handles various edge cases (duplicates, negative numbers, already sorted stacks).
- Includes a **bonus checker** to verify the correctness of the sorting.
- Optimized to use a minimal number of operations.

## Operations

- `sa` / `sb` / `ss` – Swap top two elements of stack A/B/both.
- `pa` / `pb` – Push top element from stack A to B or vice versa.
- `ra` / `rb` / `rr` – Rotate stack A/B/both (first element moves to the end).
- `rra` / `rrb` / `rrr` – Reverse rotate stack A/B/both (last element moves to the front).

## Make
```sh
make && make bonus
```
## Run push_swap
```sh
./push_swap "4 67 3 87 23"
```
# Test with checker
```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

✅ If the sorting is correct, it outputs "OK".

❌ If incorrect, it outputs "KO".

⚠️ If there are duplicates, non-integer values, or invalid instructions, it outputs "Error".
