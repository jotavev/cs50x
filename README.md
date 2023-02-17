# CS50x

<img src="https://github.com/jotavev/cs50x/blob/master/assets/Harvard_University_logo.jpg" alt="Harvard Logo" width="700"/>

CS50 is a face-to-face and online computer science course at Harvard University.  

This course is divided into weeks, and each week has a central topic and problem to solve.  

I made this repository to show the things studied in this course.  

## Lecture 0 (Scratch)

During week 0, we covered the fundamental principles of the computer world, including:
- How to computer represent data using binary 
- The definition of algorithms 
- Measuring the time to solve problems using the big-O notation
- Introduction to Scratch, a visual programming language

### Problem Set 0

In this class, I learned about Scratch, a visual programming language. As part of the course, we were given the freedom to solve a problem using Scratch, and I chose to create a game.

<img src="https://github.com/jotavev/cs50x/blob/master/assets/1pong_demo.gif" alt="Screenshot" width="350" />

My project is a retro game, similar to pong, but designed for single player. To play, click [here!](https://scratch.mit.edu/projects/778158229/)

___

## Lecture 1 (C language)

In this class, I learned the fundamentals of programming with C. I was able to apply concepts that I had already learned with Scratch to this text-based language, while also learning new concepts such as correctness, design, style, syntax, IDE, compiling, functions, arguments, return values, types, operators, conditional statements, loops and variables.

## Problems Set 1

### Mario Pyramids 

the first problem set, is based in make a mario pyramid, using c.  

| Mario Pyramids|Program in c|
|:--------------------------------------------:| ---------------------------------------------- |
| <img src="./assets/mario2.png" width="300"/> | <pre>$ ./mario           <br>Height: 4<br>   #  #<br>  ##  ##<br> ###  ###<br>####  ####<br></pre> |

Can you check my solution clicking [here!](https://github.com/jotavev/cs50x/tree/master/lecture1/pset1/)

### Cash and Credit

The second problem set involves money.

Cash is a greedy algorithm used to minimize the number of coins required to give change to customers. The input is the value of the change, and the output is the number of coins that need to be dispensed.

| Cash                                        |
|---------------------------------------------|
| <pre>$ ./cash<br>Change Owed: -41               <br>Change Owed: foo<br>Change Owed: 41<br>4</pre> |



Credit is a program that checks credit card numbers. The program determines whether the input credit card number is invalid (returning `INVALID`) or, if valid, what type of card it is, returning `VISA`, `MASTERCARD`, or `AMEX` accordingly."

| Credit                                      |
|---------------------------------------------|
|  <pre>$ ./credit <br>Number: 4003600000000014       <br>VISA<br>$ ./credit<br>Number: 371449635398431<br>AMEX<br>Number: 6176292929<br>INVALID</pre> |

Can you check my solutions clicking [here!](https://github.com/jotavev/cs50x/tree/master/lecture1/pset1/)

___

## Lecture 2 (Arrays)

During the Lecture 2, I learned about:
- Debugging techniques and tools
- Command-line arguments (using argc and 
- Computer memory concepts, including what memory is, how to use arrays to store values, and their many applications.

## Problem set 2

This week, we were introduced to lab exercises, which are typically designed to help us practice specific concepts covered in class and/or introduce new concepts that will be used in the problem sets (psets)

### Lab 2: Scrabble

In this lab, I was tasked with implementing functions for a Scrabble game prompt, based on a given piece of code.

Scrabble is a word board game in which players create intersecting words on a board of numbered squares, using the letters on their game pieces to score points. The objective is to form words with higher scores, and players can earn extra points by utilizing special squares on the board. It's a popular game all over the world that requires both a good vocabulary and strategic thinking.

| | Scrable | |
|---------------------------------------------|---|---|
|<pre>$ ./scrable<br>Player 1: COMPUTER<br>Player 2: science<br>Player 1 wins!</pre> | <pre>$ ./scrable<br>Player 1: Question?<br>Player 2: Question!<br>Tie!</pre> | <pre>$ ./scrable<br>Player 1: Oh,<br>Player 2: hai!<br>Player 2 wins!</pre> |

## Readability

For this problem, I implemented a program that calculates the approximate grade level needed to comprehend some text, as described below.

<pre>$ ./readability<br>Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!<br>Grade 3
</pre>

to do this I used the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

<pre>index = 0.0588 * L - 0.296 * S - 15.8</pre>

where `L` is the average number of letters per 100 words in the text, and `S` is the average number of sentences per 100 words in the text.

| Readability |
|----|
|<pre>$ ./readability<br>Text: As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an twelfth-grade reading level.<br>Grade 12
</pre> |

## Caesar

The story goes that Caesar used to "encrypt" (i.e., hide reversibly) confidential messages by shifting each letter in them by a fixed number of positions. For example, if the number were 1, he would write A as B, B as C, C as D...

to illustrate, here's how encryptiong `HELLO`with a key of 1 yields `IFMMP`:
| plaintext |`H` | `E` | `L` | `L` | `O` |
|---|---|---|---|---|---|
| + 1 key | 1 | 1 | 1 | 1 | 1 | 1 |
| = ciphertext | `I` | `F` | `M` | `M` | `P` |

For this problem, I implemented a program that encrypts messages using Caesar’s cipher, per the below.

<pre>$ ./caesar 13<br>plaintext:  hello, world!<br>ciphertext: uryyb, jbeyq!</pre>

Can you check my solutions clicking [here!](https://github.com/valentejorge/cs50x/tree/master/lecture2)
