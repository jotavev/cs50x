# Week3

## Algorithms 

a process or set of rules to be followed in calculations or other problem-solving operations, especially by a computer

## Searching 

find information (browser in google, look for a contact in phone...)
searching is the most onipresent topics

## BigO notation

is a way to classify how scalable your function or algorithm is.

### Common Running Times

O(n²) exponential

O(n log n) log-linear

O(n) linear 

O(log n) logarithmic

O(1) constant

## Ω

omega is to describe the best of the cenarios for the function or algorithm

## Linear Search

```
For each door from left to right
    If number is behind door
        Return true
Return false
```
or 
```
For i from 0 to n-1
    If number behind doors[i]
        Return true
Return false
```

## Binary Search

```
If no doors
    Return false
If number behind middle door
    Return true
Else if number < middle door
    Search left half
Else if number > middle door 
    Search right half
```
or 
```
If no doors
    Return false
If number behind doors[middle]
    Return true
Else if number < doors[middle]
    Search doors[0] through doors[middle - 1]
Else if number > doors[middle]
    Search doors [middle + 1] through doors[n - 1]
```

