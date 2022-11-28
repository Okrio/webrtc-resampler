/*
 * This header file contains some internal resampling functions.
 *
 */

#ifndef COMMON_AUDIO_SIGNAL_PROCESSING_RESAMPLE_BY_2_INTERNAL_H_
#define COMMON_AUDIO_SIGNAL_PROCESSING_RESAMPLE_BY_2_INTERNAL_H_

#include <stdint.h>

/*******************************************************************
 * resample_by_2_fast.c
 * Functions for internal use in the other resample functions
 ******************************************************************/
void WebRtcSpl_DownBy2IntToShort(int32_t* in,
                                 int32_t len,
                                 int16_t* out,
                                 int32_t* state);

void WebRtcSpl_DownBy2ShortToInt(const int16_t* in,
                                 int32_t len,
                                 int32_t* out,
                                 int32_t* state);

void WebRtcSpl_UpBy2ShortToInt(const int16_t* in,
                               int32_t len,
                               int32_t* out,
                               int32_t* state);

void WebRtcSpl_UpBy2IntToInt(const int32_t* in,
                             int32_t len,
                             int32_t* out,
                             int32_t* state);

void WebRtcSpl_UpBy2IntToShort(const int32_t* in,
                               int32_t len,
                               int16_t* out,
                               int32_t* state);

void WebRtcSpl_LPBy2ShortToInt(const int16_t* in,
                               int32_t len,
                               int32_t* out,
                               int32_t* state);

void WebRtcSpl_LPBy2IntToInt(const int32_t* in,
                             int32_t len,
                             int32_t* out,
                             int32_t* state);

#endif  // COMMON_AUDIO_SIGNAL_PROCESSING_RESAMPLE_BY_2_INTERNAL_H_