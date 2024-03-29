#pragma once

// Generated enums and structures for Mavlink dialect test #0 version 3
// Generated by gomavlink, DO NOT EDIT.

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// This enum is used to switch the anonymous union in test_message.
enum TEST_MESSAGE { TEST_MESSAGE_TEST_TYPES = 0 };

// A message contains the information encoded in a mavlink v1 or v2 frame
// header, plus the frame payload. It can always be serialized into maximally
// 280 bytes.
struct test_message {
  // bytes consumed when deserializing, or needed when serializing.
  // This is the sum of header (v1/v2) + payload lengths, set by _serialize or
  // _deserialize functions.
  size_t len;
  // if non zero, the crc was bad on deserializing.  ignored when serializing.
  uint16_t crc;

  // System, Component and Link IDs
  uint8_t sys_id;
  uint8_t comp_id;
  uint8_t link_id; // only used on signed V2

  // These only used for signed V2 messages, should be zero otherwise.
  uint64_t timestamp; //  10 microsecond units since 1st January 2015 GMT (unix
                      //  time 1420070400)
  uint64_t signature;

  // Lower 8 bits of seqNr are used to set the seq byte on serialized messages.
  // On deserialized messages, used to update seqDropped (ignored for
  // serialization). The sequence number is supposed to be unique per stream
  // (sys/comp/link), so the caller must manage that explicitly if these change.
  uint64_t seq_nr;
  uint32_t seq_dropped;

  // msg_id determines which of the union members is set.
  enum TEST_MESSAGE msg_id;
  union {
    /* Test all field types */
    struct {
      uint64_t u64;          /* uint64_t */
      int64_t s64;           /* int64_t */
      double d;              /* double */
      uint64_t u64_array[3]; /* uint64_t_array */
      int64_t s64_array[3];  /* int64_t_array */
      double d_array[3];     /* double_array */
      uint32_t u32;          /* uint32_t */
      int32_t s32;           /* int32_t */
      float f;               /* float */
      uint32_t u32_array[3]; /* uint32_t_array */
      int32_t s32_array[3];  /* int32_t_array */
      float f_array[3];      /* float_array */
      uint16_t u16;          /* uint16_t */
      int16_t s16;           /* int16_t */
      uint16_t u16_array[3]; /* uint16_t_array */
      int16_t s16_array[3];  /* int16_t_array */
      char c;                /* char */
      char s[10];            /* string */
      uint8_t u8;            /* uint8_t */
      int8_t s8;             /* int8_t */
      uint8_t u8_array[3];   /* uint8_t_array */
      int8_t s8_array[3];    /* int8_t_array */
    } test_types;
  };
};

/* Sign[ed] sets/checks the signature field of message based on the shared
 * secret. Signed returns non-zero (true) iff the signature is zero (V1 or
 * unsigned V2) or correct (signed V2), zero (false) for a non-zero signature
 * field that does not match the shared secret (signed V2 only).
 *
 * implemented in test_sign.c
 */
void test_message_sign(struct test_message *msg, uint8_t shared[32]);
int test_message_signed(struct test_message *msg, uint8_t shared[32]);

/* Serialize_v1 and _v2 write the message to buf in mavlink V1/V2 frame
 * encoding. These functions takes care not to write more than size bytes, and
 * return the number of bytes needed, even if that exceeds size. On succesful
 * encoding, the sequence number is updated, so the same structure can be
 * re-used easily for sending a stream of messages. If the message can not be
 * encoded for whatever reason (e.g. msg id > 255), the return value is 0.
 *
 * implemented in test_enc.c
 */
size_t test_message_serialize_v1(struct test_message *msg, uint8_t *buf,
                                 size_t size);
size_t test_message_serialize_v2(struct test_message *msg, uint8_t *buf,
                                 size_t size);

/* Seek returns the number of bytes to skip to the start of a frame, or when buf
 * starts with a frame STX, it returns 0. If seek can not find the start of a
 * frame it returns size.
 *
 * implemented in test_dec.c
 */
size_t test_message_seek(const uint8_t *buf, size_t size);

/* Deserialize reads up to min(size, 280) bytes from buf and decodes a V1, V2
 * signed or unsigned message. if buf is too small, i.e. does not contain a
 * complete frame, or does not start with a valid STX, it returns zero, but msg
 * may have been modified with the partially decoded message.  It will not
 * increment seqnr/dropped in this case. If the frame is corrupt, its crc field
 * will be non zero.  This is the only integrity check if the message is not
 * _signed(); In case of a corrupt package, the advised way to proceed is to
 * call _seek on (++buf,--size) to find the next possible packet start. If the
 * message id is unknown by this library the payload will be ignored, but all
 * header fields will be set accordingly.
 *
 * implemented in test_dec.c
 */
size_t test_message_deserialize(const uint8_t *buf, size_t size,
                                struct test_message *msg);

/* _snprintf appends a debug representation of the message to a buffer
 * implemented in test_fmt.c
 */
size_t test_message_snprintf(char *buf, size_t size,
                             const struct test_message *msg);

#ifdef __cplusplus
}
#endif
