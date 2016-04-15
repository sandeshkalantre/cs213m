For the first problem, I have used the heurestic as half of the hamming distance between the two strings since it seemed plausible to expect that many swaps.

For the second problem, as a first try I used h  = 0 as heurestic.

I have used vector as a data stucture to store the open and closed set in A-star. Ideally one should be using something like a BST,RB-tree which is present as set in STL. However, I had the functions set API behaving unexpectedly and hence I dropped the idea. 
