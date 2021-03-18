# Push_swap

## Subject : 
- EN : https://cdn.intra.42.fr/pdf/pdf/19989/en.subject.pdf
- FR : https://cdn.intra.42.fr/pdf/pdf/650/push_swap.fr.pdf
#
## Testing :
 ```
make && ./push_swap <ARG> | ./checker <ARG>
  ```
Moreover, you can enter in a bash or sh shell and try : 
```
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
  ```
(1..100) is the range of random values, try to change it. Careful, 1 and 100 are counted so here, the range's size is 100 and not 99.
#
# Checker Steps :
## I :  Parsing : Error\n if...
- Isn't an int
- Has duplicates
- Space before or after instruction
- Instruction doesn't exist
- If no args, checker give the prompt
## II : Get commands : 
- So i use a very simple GNL loop on stdin (find it in the lib)
- Every time i pars the line, see overhead
- Then i store it in a simple chain list until Ctrl-D is pressed (EOF)
### III : Apply commands : 
- When EOF, i convert my chain list on a **char, i fill it the end to the begin, because else my dub tab will be revert
- Finally i apply my commands with the corrects functions until the dub tab is finished

# Push_swap Steps :
## I : Before start : 
- Same parsing as checker
- Same storage system with commands
- Same command apply system to simulate the algorithm before print
- Careful, if args are already sorted, push_swap must give the prompt 
## II : Algo for three args :
- Brut force explain here : https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
## III : Four and five args : 
- Find the smallest, then push it to stack B
- When A is empty, pa until B is empty
## IV : Hundred or less 
- First, i create a dup of stack A
- Then i sort this dup to find the median (tab[size / 2])
- Free this dup and start the algorithm
- if the top of A is less than med -> pb else ra
- When all number lass than med are pushed on B -> start sorting
- Until B isn't empty, i find the biggest and the smallest number of B
- Then dertemine wich is closer to the top and set the closer on the top of B
- Then if the closer was the smallest, push it to the bottom of A -> pa, ra else push it to the top -> pa
- Finally, do the exact same thing fot the numbers that are bigger or equal than med.
## V : Bigger than hundred
- Same algorithm but i do it with quarters too
- So, find q1, med and q2 with the dup tab
- Then same but do it less than q1
- Sort and repush to A, then do it less than med..
- Same less than q3
- Same less than the size of pa
#