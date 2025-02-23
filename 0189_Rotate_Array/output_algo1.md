The given array `[1,2,3,4,6]` with a shift required of `k=3` using Cyclic replacement will have the following output:

```bash
The arr at start= 0 and curr 3 and prev val 4 and count 0
1 2 3 1 5 6 
The arr at start= 0 and curr 0 and prev val 1 and count 1
4 2 3 1 5 6 
The arr at start= 1 and curr 4 and prev val 5 and count 2
4 2 3 1 2 6 
The arr at start= 1 and curr 1 and prev val 2 and count 3
4 5 3 1 2 6 
The arr at start= 2 and curr 5 and prev val 6 and count 4
4 5 3 1 2 3 
The arr at start= 2 and curr 2 and prev val 3 and count 5
4 5 6 1 2 3 
```

Notice that if the outer while loop was not there, the first two steps will be the only steps. And other elements wont be touched.

 Considering the case `nums = {1, 2, 3, 4, 5, 6, 7};` and `k=3`

```bash
The arr at start= 0 and curr 3 and prev val 4 and count 0
1 2 3 1 5 6 7 
The arr at start= 0 and curr 6 and prev val 7 and count 1
1 2 3 1 5 6 4 
The arr at start= 0 and curr 2 and prev val 3 and count 2
1 2 7 1 5 6 4 
The arr at start= 0 and curr 5 and prev val 6 and count 3
1 2 7 1 5 3 4 
The arr at start= 0 and curr 1 and prev val 2 and count 4
1 6 7 1 5 3 4 
The arr at start= 0 and curr 4 and prev val 5 and count 5
1 6 7 1 2 3 4 
The arr at start= 0 and curr 0 and prev val 1 and count 6
5 6 7 1 2 3 4
```
