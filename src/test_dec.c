// Generated enums and structures for Mavlink dialect test #0 version 3
// Generated by gomavlink, DO NOT EDIT.

#include <assert.h>
#include <string.h>

#include "test.h"

// defined in test_crc.h
uint8_t test_crcextra(enum TEST_MESSAGE mid);

inline static uint8_t read_byte(const uint8_t **p) { return *(*p)++; }
inline static int8_t read_int8(const uint8_t **p) { return *(*p)++; }
inline static int16_t read_int16(const uint8_t **p) {
  int16_t r = *(*p)++;
  r |= *(*p)++ << 8;
  return r;
}
inline static uint16_t read_uint16(const uint8_t **p) {
  uint16_t r = *(*p)++;
  r |= *(*p)++ << 8;
  return r;
}
inline static int32_t read_int32(const uint8_t **p) {
  int32_t r = *(*p)++;
  r |= *(*p)++ << 8;
  r |= *(*p)++ << 16;
  r |= *(*p)++ << 24;
  return r;
}
inline static uint32_t read_uint32(const uint8_t **p) {
  uint32_t r = *(*p)++;
  r |= *(*p)++ << 8;
  r |= *(*p)++ << 16;
  r |= *(*p)++ << 24;
  return r;
}
inline static int64_t read_int64(const uint8_t **p) {
  int64_t r = read_uint32(p);
  r |= ((int64_t)read_int32(p)) << 32;
  return r;
}
inline static uint64_t read_uint64(const uint8_t **p) {
  uint64_t r = read_uint32(p);
  r |= ((uint64_t)read_uint32(p)) << 32;
  return r;
}

inline static float read_float32(const uint8_t **p) {
  uint32_t v = read_uint32(p);
  return *(float *)&v;
}
inline static double read_float64(const uint8_t **p) {
  uint64_t v = read_uint64(p);
  return *(double *)&v;
}

inline static uint16_t x25(uint16_t crc, uint8_t v) {
  v ^= crc;
  v ^= v << 4;
  return (crc >> 8) ^ (v << 8) ^ (v << 3) ^
         (v >> 4); // (uint8_t << int) is promoted to int (!!)
}

static void read_payload_base(const uint8_t **p, struct test_message *msg) {
  switch (msg->msg_id) {

  case TEST_MESSAGE_TEST_TYPES:
    msg->test_types.u64 = read_uint64(p);
    msg->test_types.s64 = read_int64(p);
    msg->test_types.d = read_float64(p);
    for (size_t i = 0; i < 3; i++)
      msg->test_types.u64_array[i] = read_uint64(p);
    for (size_t i = 0; i < 3; i++)
      msg->test_types.s64_array[i] = read_int64(p);
    for (size_t i = 0; i < 3; i++)
      msg->test_types.d_array[i] = read_float64(p);
    msg->test_types.u32 = read_uint32(p);
    msg->test_types.s32 = read_int32(p);
    msg->test_types.f = read_float32(p);
    for (size_t i = 0; i < 3; i++)
      msg->test_types.u32_array[i] = read_uint32(p);
    for (size_t i = 0; i < 3; i++)
      msg->test_types.s32_array[i] = read_int32(p);
    for (size_t i = 0; i < 3; i++)
      msg->test_types.f_array[i] = read_float32(p);
    msg->test_types.u16 = read_uint16(p);
    msg->test_types.s16 = read_int16(p);
    for (size_t i = 0; i < 3; i++)
      msg->test_types.u16_array[i] = read_uint16(p);
    for (size_t i = 0; i < 3; i++)
      msg->test_types.s16_array[i] = read_int16(p);
    msg->test_types.c = read_byte(p);
    for (size_t i = 0; i < 10; i++)
      msg->test_types.s[i] = read_byte(p);
    msg->test_types.u8 = read_byte(p);
    msg->test_types.s8 = read_int8(p);
    for (size_t i = 0; i < 3; i++)
      msg->test_types.u8_array[i] = read_byte(p);
    for (size_t i = 0; i < 3; i++)
      msg->test_types.s8_array[i] = read_int8(p);
    break;
  };
}

static void read_payload_ext(const uint8_t **p, struct test_message *msg) {
  switch (msg->msg_id) {

  default:; // nix
  };
}

size_t test_message_deserialize(const uint8_t *buf, size_t size,
                                struct test_message *msg) {
  if (size < 3) {
    return 0;
  }
  switch (buf[0]) {
  case 0xFE:
    if (size < 8 + buf[1]) {
      return 0;
    }
    break;
  case 0xFD:
    if (size < 11 + buf[1] + ((buf[2] & 0x1) ? 13 : 0)) {
      return 0;
    }
    break;
  default:
    return 0;
  }

  const uint8_t *p = buf + 1;

  msg->len = *p++;

  if (buf[0] == 0xFD) {
    p += 2; // skip incompat + compat flags
  }

  msg->seq_dropped =
      *p++ - 1 -
      (uint8_t)(msg->seq_nr); // add difference in least significant byte
  msg->seq_nr += 1 + msg->seq_dropped;

  msg->sys_id = *p++;
  msg->comp_id = *p++;
  msg->msg_id = *p++;
  if (buf[0] == 0xFD) {
    msg->msg_id |= (uint32_t)(*p++) << 8;
    msg->msg_id |= (uint32_t)(*p++) << 16;
  }

  uint8_t tmp[256];
  memset(tmp, 0, sizeof tmp);
  memmove(tmp, p, msg->len);
  p += msg->len;

  uint16_t crc = 0xffff;
  for (const uint8_t *pp = buf + 1; pp < p; ++pp) {
    crc = x25(crc, *pp);
  }
  crc = x25(crc, test_crcextra(msg->msg_id));

  crc ^= *p++;
  crc ^= *p++ << 8;
  msg->crc = crc; // should be zero now

  const uint8_t *q = tmp;
  read_payload_base(&q, msg);
  if (buf[0] == 0xFD) {
    read_payload_ext(&q, msg);
  }
  assert(q - tmp < sizeof tmp);

  msg->link_id = 0;
  if ((buf[0] == 0xFD) && (buf[2] & 0x1)) {
    msg->link_id = *p++;
    msg->timestamp = read_uint16(&p);
    msg->timestamp |= read_uint32(&p) << 16;
    msg->signature = read_uint16(&p);
    msg->signature |= read_uint32(&p) << 16;
  }

  return p - buf;
}

size_t test_message_seek(const uint8_t *buf, size_t size) {
  for (size_t r = 0; r < size; r++) {
    switch (buf[r]) {
    case 0xFD:
    case 0xFE:
      return r;
    }
  }
  return size;
}
