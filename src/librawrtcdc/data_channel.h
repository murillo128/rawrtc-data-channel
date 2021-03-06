#pragma once
#include <rawrtcdc.h>

/*
 * Data channel flags.
 */
enum {
    RAWRTC_DATA_CHANNEL_FLAGS_INITIALIZED = 1 << 0,
    RAWRTC_DATA_CHANNEL_FLAGS_STREAMED = 1 << 1,
};

/*
 * Data channel type unordered bit flag.
 */
enum {
    RAWRTC_DATA_CHANNEL_TYPE_IS_UNORDERED = 0x80
};

struct rawrtc_data_channel {
    uint_fast8_t flags;
    enum rawrtc_data_channel_state state;
    struct rawrtc_data_transport* transport; // referenced
    void* transport_arg; // referenced
    struct rawrtc_data_channel_parameters* parameters; // referenced
    rawrtc_data_channel_open_handler open_handler; // nullable
    rawrtc_data_channel_buffered_amount_low_handler buffered_amount_low_handler; // nullable
    rawrtc_data_channel_error_handler error_handler; // nullable
    rawrtc_data_channel_close_handler close_handler; // nullable
    rawrtc_data_channel_message_handler message_handler; // nullable
    void* arg; // nullable
};
