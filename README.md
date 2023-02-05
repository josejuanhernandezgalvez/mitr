# mitr: A Command Line Utility for Text Replacements and Deletions
[![My Skills](https://skillicons.dev/icons?i=c&perline=)](https://skillicons.dev)

This project was created as part of the Computer Architecture course assignment. It is a simple command line utility for Linux that is similar to the "tr" command, but with a few additional features. There are three main functionalities provided by mitr:

## 1. Replacing Text in a File

This feature allows you to replace a text string in an input file with another text string, and write the result to an output file. There is no restriction on the size of the text strings being replaced, and the input and output files can even be the same file. To use this feature, run the following command:


```
mitr text replacement input-file output-file
```
---------------------------------------

## 2. Deleting Text from a File

This feature allows you to delete a specific text string from an input file, and write the result to an output file. To use this feature, run the following command:

```
mitr -d text input-file output-file
```
----------------------------------------

## 3. Counting Occurrences of Text in a File

This feature allows you to count the number of occurrences of a specific text string in an input file. To use this feature, run the following command:

```
mitr -i text input-file
```
