# Week3

## Algorithms 

a process or set of rules to be followed in calculations or other problem-solving operations, especially by a computer

## Searching 

find information (browser in google, look for a contact in phone...)
searching is the most onipresent topics

## BigO notation

is a way to classify how scalable your function or algorithm is.

### Common Running Times

O(n²) | exponential | selection sort | bubble sort (if a big data)

O(n log n) | log-linear

O(n) | linear 

O(log n) | logarithmic

O(1) | constant

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

## Sorting and Searching vs Just Searching 

depend how big is data and how important is

## Data Structures

is a specialized format for organizing, processing, retrieving and storing data.

in c we have the habilit to invent new data types, similar to scratch when we build new custom blocks

```
typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";
}
```

## Sorting 

organize systematically from smallest to largest

6 3 8 5 2 7 4 1 → 🞎 → 1 2 3 4 5 6 7 8 

## Selection Sort

pseudocode
```
For i from 0 to n-1
    Find the smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]
```
O(n²) && Ω(n²)

## Bubble Sort 

pseudocode
```
Repeat n-1 times
    For i from 0 to n-2
        If numbers[i] and numbers[i+1] out of order 
            Swap them
    If no swaps
        Quit
```
O(n²) && Ω(n)


