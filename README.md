// See https://github.com/jupyterlab/jupyterlab/issues/4039 for cross referencing in math mode in md.

# PushSwap
**Push Swap project from 42 school**


In the beginning I was really unhappy about this project, because I thought it was about sorting algorithms, and all sorting algorithms that other people and I could imagine work quadratically.
However, at some point I realized that the project is not about sorting, but about substitutions, and the latter admits elegant solutions that work linearly.

The difference between the sorting problem and the problem of bringing an arbitrary substitution to the identity one is as follows. In the sorting, you assume no knowledge of the initial numbers, and you are only allowed to compare numbers. On the other hand, if you want to bring a substitution to the identity one, you may assume all your numbers are the numbers between 0 and n-1.
So the solution is first to redefine the original numbers by the numbers from 0 to n-1 (using a standard sorting algorithm), and then operate with these numbers.

***Preliminary observations.***
Below we will describe three different algorithms, but first let us look at some small n cases.

n = 2. In this case the worst number is 1.
n = 3. In this case the worst number is 2.
n = 4. In this case the worst number is 5.

Looking at these small n cases, we get a belief that the worst case scenario correspond to the following orientation of the numbers:
$\left(k, k-1, \ldots, 1, n, n-1, \ldots, 1\right)^T$
for some k.

Besides, we see that for these cases it is enough to consider only the following operations:
sa, <s>sb</s>, ~~ss~~, pa, pb, ra, rra, <s>rb, rr, rrb, rrr</s>

In what follows we will use only that limited set of operations.
Denote <br>-by $A_n$ the minimal numbers of operations to push_swap the configuration $\left(n, n-1, \ldots, 2, 1\right)^T$, <br>-by $B_n$ the minimal numbers of operations to push_swap the configuration 
$\left(k, k-1, \ldots, 1, n, n-1, \ldots, 1\right)^T$, for all $k,$ and <br>-by $C_n$ the minimal numbers of operations to push_swap an arbitrary configuration.<br>
Obviously $$A_n\leq B_n\leq C_n.$$ Furthermore, we have the following simple estimates:
$$A_n \leq 3 + A_{n-1},\mbox{ and }$$
$$B_n \leq \lfloor\frac{n}{2}\rfloor + 3 + A_{n-1}.$$
$$C_n \leq \lfloor\frac{n}{2}\rfloor + 3 + C_{n-1}.\tag{estimatesCn}$$
Now, from $$A_1 = 0, A_2 = 1, A_3 = 2, A_4 = 4, $$ we obtain $$A_5\leq 7, A_6\leq 10, A_7\leq 13, A_8\leq 16, A_9\leq19, A_{10}\leq 22,\mbox{ and, in general, }A_n\leq3n-8\mbox{ for }n\geq4.$$ 
I do believe that the estimates are actually the equality.

Hence, for $B_n$ we obtain $$B_n\leq\lfloor\frac{n}{2}\rfloor + 3 + A_{n-1}\leq\frac{n}{2} + 3 + 3n - 11 = \frac72n-8\mbox{ for }n\geq 5.$$
Recall now, that if we believe that $B_n = C_n$ (i.e. the cases considered in $B_n$ are the worst case scenarios), this gives us linear estimates for $C_n.$

However, it is not easy to obtain linear estimate for $C_n.$ The above estimates \eqref{estimatesCn}, \ref{estimatesCn} give us only a quadratic estimate for $C_n.$ However, I do believe that such an estimate is a a rough estimate, and that the actual value should be smaller.
