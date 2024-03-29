#pragma once

// Generated enums and structures for Mavlink dialect icarous #0 version 0
// Generated by gomavlink, DO NOT EDIT.

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum ICAROUS_TRACK_BAND_TYPES {
  ICAROUS_TRACK_BAND_TYPE_NONE = 0,
  ICAROUS_TRACK_BAND_TYPE_NEAR = 1,
  ICAROUS_TRACK_BAND_TYPE_RECOVERY = 2
};

enum ICAROUS_FMS_STATE {
  ICAROUS_FMS_STATE_IDLE = 0,
  ICAROUS_FMS_STATE_TAKEOFF = 1,
  ICAROUS_FMS_STATE_CLIMB = 2,
  ICAROUS_FMS_STATE_CRUISE = 3,
  ICAROUS_FMS_STATE_APPROACH = 4,
  ICAROUS_FMS_STATE_LAND = 5
};

// This enum is used to switch the anonymous union in icarous_message.
enum ICAROUS_MESSAGE {
  ICAROUS_MESSAGE_ICAROUS_HEARTBEAT = 42000,
  ICAROUS_MESSAGE_ICAROUS_KINEMATIC_BANDS = 42001
};

// A message contains the information encoded in a mavlink v1 or v2 frame
// header, plus the frame payload. It can always be serialized into maximally
// 280 bytes.
struct icarous_message {
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
  enum ICAROUS_MESSAGE msg_id;
  union {
    /* ICAROUS heartbeat */
    struct {
      enum ICAROUS_FMS_STATE status; /* (uint8_t) See the FMS_STATE enum. */
    } icarous_heartbeat;

    /* Kinematic multi bands (track) output from Daidalus */
    struct {
      float min1;      /* min angle (degrees) */
      float max1;      /* max angle (degrees) */
      float min2;      /* min angle (degrees) */
      float max2;      /* max angle (degrees) */
      float min3;      /* min angle (degrees) */
      float max3;      /* max angle (degrees) */
      float min4;      /* min angle (degrees) */
      float max4;      /* max angle (degrees) */
      float min5;      /* min angle (degrees) */
      float max5;      /* max angle (degrees) */
      int8_t numBands; /* Number of track bands */
      enum ICAROUS_TRACK_BAND_TYPES
          type1; /* (uint8_t) See the TRACK_BAND_TYPES enum. */
      enum ICAROUS_TRACK_BAND_TYPES
          type2; /* (uint8_t) See the TRACK_BAND_TYPES enum. */
      enum ICAROUS_TRACK_BAND_TYPES
          type3; /* (uint8_t) See the TRACK_BAND_TYPES enum. */
      enum ICAROUS_TRACK_BAND_TYPES
          type4; /* (uint8_t) See the TRACK_BAND_TYPES enum. */
      enum ICAROUS_TRACK_BAND_TYPES
          type5; /* (uint8_t) See the TRACK_BAND_TYPES enum. */
    } icarous_kinematic_bands;
  };
};

/* Sign[ed] sets/checks the signature field of message based on the shared
 * secret. Signed returns non-zero (true) iff the signature is zero (V1 or
 * unsigned V2) or correct (signed V2), zero (false) for a non-zero signature
 * field that does not match the shared secret (signed V2 only).
 *
 * implemented in icarous_sign.c
 */
void icarous_message_sign(struct icarous_message *msg, uint8_t shared[32]);
int icarous_message_signed(struct icarous_message *msg, uint8_t shared[32]);

/* Serialize_v1 and _v2 write the message to buf in mavlink V1/V2 frame
 * encoding. These functions takes care not to write more than size bytes, and
 * return the number of bytes needed, even if that exceeds size. On succesful
 * encoding, the sequence number is updated, so the same structure can be
 * re-used easily for sending a stream of messages. If the message can not be
 * encoded for whatever reason (e.g. msg id > 255), the return value is 0.
 *
 * implemented in icarous_enc.c
 */
size_t icarous_message_serialize_v1(struct icarous_message *msg, uint8_t *buf,
                                    size_t size);
size_t icarous_message_serialize_v2(struct icarous_message *msg, uint8_t *buf,
                                    size_t size);

/* Seek returns the number of bytes to skip to the start of a frame, or when buf
 * starts with a frame STX, it returns 0. If seek can not find the start of a
 * frame it returns size.
 *
 * implemented in icarous_dec.c
 */
size_t icarous_message_seek(const uint8_t *buf, size_t size);

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
 * implemented in icarous_dec.c
 */
size_t icarous_message_deserialize(const uint8_t *buf, size_t size,
                                   struct icarous_message *msg);

/* _snprintf appends a debug representation of the message to a buffer
 * implemented in icarous_fmt.c
 */
size_t icarous_message_snprintf(char *buf, size_t size,
                                const struct icarous_message *msg);

#ifdef __cplusplus
}
#endif
