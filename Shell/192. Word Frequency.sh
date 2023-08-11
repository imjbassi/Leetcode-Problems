#!/bin/bash

# Read the words from the file and calculate word frequency
awk '
{
    for (i = 1; i <= NF; i++) {
        words[$i]++;
    }
}
END {
    for (word in words) {
        print word, words[word];
    }
}
' words.txt | sort -k2,2nr