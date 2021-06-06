# mitr

This project is the result of the Computer Architecture Course assignment. It is a simple linux command quite similar to tr command with 3 possibilities:

1. Replacing a text by another text from an input file into an ouput file. There is no restriction since output file and input file can be the same. Also, the size of the text and the size the replacement could be different. It is used in this way:

```
mitr text replacement input-file output-file
```
---------------------------------------

2. Deleting a text from an input file into output file. 

```
mitr -d text input-file output-file
```
----------------------------------------

3. Counting the number of occurrences of a text from an input file

```
mitr -i text input-file
```
