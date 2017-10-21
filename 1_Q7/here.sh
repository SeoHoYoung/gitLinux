#!/bin/bash

grep -i $1 << EOF
a 10 20 30 korea
b 30 50 30 english
c 50 80 20 korea
d 80 28 39 china
e 38 02 74 japan
f 29 57 20 korea
EOF
