# gomavlink/C
MAVLink Encoding and Decoding in C

NOTE ON THE LICENSE: 
the generated files here are derived from XML code under the LGPL, i include them here as a service, but they are under the LGPL i think.

The generated code has no dependencies other than a handful of standard C include headers (stddef and stdint, string and assert) and is the functions keep no global state, so it is safe to include multiple dialects and be reading multiple streams.

The C code is split into a header include/${dialect}.h and separate source files src/${dialect}_enc.c, _dec.c and _crc.c used by both.

(_fmt.c, to print the messges in a debug format, is WIP)

the code is meant to be copied in-place to your project, you can always generate it in place by running the commands as exemplified in the update.sh script.


