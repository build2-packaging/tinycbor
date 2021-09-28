#include <libtinycbor/cbor.h>

// Encode/decode an integer value to/from a buffer.
//

int
main ()
{
  uint8_t b[16]; // The buffer.
  int v = 123;   // The integer value.

  // Encode the value.
  //
  {
    CborEncoder e;
    cbor_encoder_init (&e, b, sizeof (b), 0);
    cbor_encode_int (&e, v);
  }

  v = 0;

  // Decode the value.
  //
  {
    CborParser p;
    CborValue cv;
    cbor_parser_init (b, sizeof (b), 0, &p, &cv);
    cbor_value_get_int (&cv, &v);
  }

  // Fail if the encoded and decoded values are not the same.
  //
  return v == 123 ? 0 : 1;
}
