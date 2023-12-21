
# Chapter 18.1

# A simple assembly program which returns 4.
# 
# CLI commands:
# as test.s -o test.o
# ld test.o -o test
# 
# run:
# ./test
# echo$?


.section .data

.section .text

.globl _start

_start:
movl $1, %eax


movl $4, %ebx


#A segmentatioin error would occur if the following code were commented out.
int $0x80

