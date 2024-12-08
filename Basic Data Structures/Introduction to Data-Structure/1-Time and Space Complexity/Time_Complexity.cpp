/*
Big O
Linear Complexity --> O(N)
Logarithmic Complexity --> O(logN)
Sqrt Complexity --> O(sqrt(N))
Quadratic Complexity --> O(N*N)
Linearithmic Complexity --> O(NlogN)

Time Complexity vary on OS, same can code execute takes different time in different OS. Time Complexity don't fix with times.
In Short: Our Code Operate How Many Operation Response Of Input.

O(N) - Order of N/Big O of N

Asymptotic Notations:
-->Omega notation (Ω) - Best Case
-->Theta notation (θ) - Average Case
-->Big O notation (O) - Worst Case

Rules to calculate time complexity:
1. Always take the worst case
2. Ignore The Constant

O(N-1), O(N/2), O(2N) --> ignore the constant O(N)
ignore it because that doesn't make too much different if our code can execute O(N) it can execute O(N-1), O(N/2), O(2N).

sort(a, a+n) ---> time complexity: O(NlogN)

In every online judge the time limit upto 1 to 3s, most of the time it is 1s.

1s    -> 10^7
2s    -> 2 * 10^7
3s    -> 3 * 10^7

10s   -> 10^8
100s  -> 10^9
1000s -> 10^10
*/