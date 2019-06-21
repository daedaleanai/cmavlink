#!/bin/sh

go install github.com/daedaleanai/gomavgen

XMLDIR=/tmp/mavlink/message_definitions/v1.0/
mkdir -p include
mkdir -p src

for ddef in ${XMLDIR}*.xml; do
	dialect=$(basename -s .xml $ddef | tr '[A-Z]' '[a-z]')
	echo $dialect ...
	gomavgen h.tmpl     $ddef | clang-format > include/${dialect}.h
	gomavgen c_crc.tmpl $ddef | clang-format > src/${dialect}_crc.c
	gomavgen c_dec.tmpl $ddef | clang-format > src/${dialect}_dec.c
	gomavgen c_enc.tmpl $ddef | clang-format > src/${dialect}_enc.c
	gomavgen c_fmt.tmpl $ddef | clang-format > src/${dialect}_fmt.c
	(cd src; gcc -I../include -O3 -c ${dialect}_*.c)
	echo
done

(rm -f lib.a; cd src; ar -v -q ../lib.a *.o; rm *.o)
