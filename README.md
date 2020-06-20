# IRep
# Language: C++
# Input: TXT
# Output: TXT
# Tested with: PluMA 1.0, GCC 4.8.4

Calculate Index of Replication (Brown et al, 2016), to measure whether or
not the abundance of a gene or taxon is currently increasing or decreasing.

This plugin accepts as input a TXT file of tab-delimited keywords and values:
target: Target sequence (FNA)
sample1: First sample (SAM)
sample2: Second sample (SAM)

The user provides an output prefix.
The index, along with many other statistics, will be output to a TSV file (prefix.tsv)
Various other plots will be sent to a PDF with the same prefix (prefix.pdf)

Note: This plugin depends on iRep being in the system PATH.
