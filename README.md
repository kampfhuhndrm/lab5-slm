Lab 5: Small Language Model (slm)

This is a C++ project for Lab 5. It implements a simple statistical language model based on k-grams.

The program trains a model by reading a given text file. It calculates the frequency of all k-grams and the transition probabilities of the characters that follow them. It can then use this model to generate new, randomized text that mimics the style of the input text.

How to Use

The program is a command-line tool that takes exactly three arguments.

Usage Syntax
```
./slm <k> <filename> <num_chars>
```

Arguments


<k> (Integer): The length of the k-gram to be used (e.g., 2 for bigrams, 3 for trigrams).

<filename> (String): The path to the input text file that the model will be trained on (e.g., test.txt).

<num_chars> (Integer): The total number of characters you want the program to generate.

Example

To train a 4-gram model on the file test.txt and generate 150 characters of new text:
```
./slm 4 test.txt 150
```