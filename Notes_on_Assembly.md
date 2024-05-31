### 1,Instructions of commands

1. movz

```shell
mov #move
z # zero-extended. That means 0s will be added on the top bits.
b # byte. 1byte=8bits
w # word  1 word = 2 bytes
l # long  1 long = 4 bytes
```

```shell
movz # to convert an unsigned integer to a wider unsigned integer
# The low 8 bits of the destination will be replaced by the sorurce operand, 
# and the top bits are set to 0. The source operand is unaffectd.
movzbw # 1010,0111 -> 1010,0111,0000,0000
# The low 8 bits of the destination will be replaced by the source operand 
# The top 24 bits are set to 0. 
movzbl
```

