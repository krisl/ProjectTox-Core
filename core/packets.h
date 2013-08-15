/*
 * packet.h -- Packet structure
 *
 * This file is donated to the Tox Project.
 * Copyright 2013  plutooo
 */
#ifndef PACKETS_H_PZ65T2IZ
#define PACKETS_H_PZ65T2IZ

typedef struct {
    uint8_t id[CLIENT_ID_SIZE];

} __attribute__((packed)) clientid_t;

typedef enum {
    PACKET_PING_REQ = 0,
    PACKET_PING_RES = 1

} packetid_t;

// Ping packet
typedef struct {
    uint8_t    magic;
    clientid_t client_id;
    uint8_t    nonce[crypto_box_NONCEBYTES];
    uint64_t   ping_id;
    uint8_t    padding[ENCRYPTION_PADDING];

} __attribute__((packed)) pingreq_t;

// Pong packet
typedef struct {
    uint8_t    magic;
    clientid_t client_id;
    uint8_t    nonce[crypto_box_NONCEBYTES];
    uint64_t   ping_id;
    uint8_t    padding[ENCRYPTION_PADDING];

} __attribute__((packed)) pingres_t;

#endif /* end of include guard: PACKETS_H_PZ65T2IZ */
