# libtinycbor

Concise Binary Object Representation (CBOR) library.

For documentation, see https://intel.github.io/tinycbor/current/

Note that unlike upstream, this package expects you to include the library's
header as `<libtinycbor/cbor.h>` rather `<cbor.h>` in order to avoid conflict
with other CBOR libraries (which also naturally have the `cbor.h` header).
