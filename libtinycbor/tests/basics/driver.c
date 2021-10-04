#include <libtinycbor/cbor.h>

// Confirm that MinGW warning about 64-bit printf format is harmless (see
// README-DEV for details).
//
#include <stdio.h>              // sprintf
#include <inttypes.h>           // PRIu64

#undef NDEBUG
#include <assert.h>

int
main ()
{
  // Test that an integer can be successfully encoded to and decoded from a
  // buffer.
  //
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

    assert (v == 123);
  }

  // Test that the printf-like functions correctly convert a long long value
  // to string on MinGW.
  //
  {
    char s[32] = "";
    sprintf (s, "%" PRIu64, 18446744073709551615ULL);
    assert (strcmp (s, "18446744073709551615") == 0);
  }

  return 0;
}
