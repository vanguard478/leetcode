47\. Top K Frequent Elements
=============================

Level
-----

Medium

Description
-----------

Given a non-empty array of integers, return the **_k_** most frequent elements.

**Example 1:**

**Input:** nums = \[1,1,1,2,2,3\], k = 2

**Output:** \[1,2\]

**Example 2:**

**Input:** nums = \[1\], k = 1

**Output:** \[1\]

**Note:**

* You may assume k is always valid, 1 ≤ _k_ ≤ number of unique elements.
* Your algorithm’s time complexity **must be** better than `O(*n* log *n*)`, where _n_ is the array’s size.

Solution
--------

To obtain an algorithm with time complexity better than `O(*n* log *n*)`, use maps. This solution has time complexity `O(*n* log *k*)`.

Use `two maps` to store each number and its count and store each count and the numbers that have the count, respectively.

* The first map is a hash map
* the second map is a tree map

Loop over `nums` to obtain each number and its count, and store the numbers and the counts in the first map. Then loop over the entries of the first map to obtain each cound and the numbers that have the count, and store the counts and the numbers in the second map. Initialize the second map such that keys are sorted in descending order. Then loop over the second map to obtain the k most frequent elements.

### Pitfall

Clarify on: what if there is a tie?
