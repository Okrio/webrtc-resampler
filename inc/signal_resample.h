#ifndef COMMON_AUDIO_SIGNAL_PROCESSING_INCLUDE_SIGNAL_RESMPLE_H_
#define COMMON_AUDIO_SIGNAL_PROCESSING_INCLUDE_SIGNAL_RESMPLE_H_

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************
 * resample.c
 *
 * Includes the following resampling combinations
 * 22 kHz -> 16 kHz
 * 16 kHz -> 22 kHz
 * 22 kHz ->  8 kHz
 *  8 kHz -> 22 kHz
 *
 ******************************************************************/

// state structure for 22 -> 16 resampler
typedef struct {
  int32_t S_22_44[8];
  int32_t S_44_32[8];
  int32_t S_32_16[8];
} WebRtcSpl_State22khzTo16khz;

void WebRtcSpl_Resample22khzTo16khz(const int16_t* in,
                                    int16_t* out,
                                    WebRtcSpl_State22khzTo16khz* state,
                                    int32_t* tmpmem);

void WebRtcSpl_ResetResample22khzTo16khz(WebRtcSpl_State22khzTo16khz* state);

// state structure for 16 -> 22 resampler
typedef struct {
  int32_t S_16_32[8];
  int32_t S_32_22[8];
} WebRtcSpl_State16khzTo22khz;

void WebRtcSpl_Resample16khzTo22khz(const int16_t* in,
                                    int16_t* out,
                                    WebRtcSpl_State16khzTo22khz* state,
                                    int32_t* tmpmem);

void WebRtcSpl_ResetResample16khzTo22khz(WebRtcSpl_State16khzTo22khz* state);

// state structure for 22 -> 8 resampler
typedef struct {
  int32_t S_22_22[16];
  int32_t S_22_16[8];
  int32_t S_16_8[8];
} WebRtcSpl_State22khzTo8khz;

void WebRtcSpl_Resample22khzTo8khz(const int16_t* in,
                                   int16_t* out,
                                   WebRtcSpl_State22khzTo8khz* state,
                                   int32_t* tmpmem);

void WebRtcSpl_ResetResample22khzTo8khz(WebRtcSpl_State22khzTo8khz* state);

// state structure for 8 -> 22 resampler
typedef struct {
  int32_t S_8_16[8];
  int32_t S_16_11[8];
  int32_t S_11_22[8];
} WebRtcSpl_State8khzTo22khz;

void WebRtcSpl_Resample8khzTo22khz(const int16_t* in,
                                   int16_t* out,
                                   WebRtcSpl_State8khzTo22khz* state,
                                   int32_t* tmpmem);

void WebRtcSpl_ResetResample8khzTo22khz(WebRtcSpl_State8khzTo22khz* state);

/*******************************************************************
 * resample_fractional.c
 * Functions for internal use in the other resample functions
 *
 * Includes the following resampling combinations
 * 48 kHz -> 32 kHz
 * 32 kHz -> 24 kHz
 * 44 kHz -> 32 kHz
 *
 ******************************************************************/

void WebRtcSpl_Resample48khzTo32khz(const int32_t* In, int32_t* Out, size_t K);

void WebRtcSpl_Resample32khzTo24khz(const int32_t* In, int32_t* Out, size_t K);

void WebRtcSpl_Resample44khzTo32khz(const int32_t* In, int32_t* Out, size_t K);

/*******************************************************************
 * resample_48khz.c
 *
 * Includes the following resampling combinations
 * 48 kHz -> 16 kHz
 * 16 kHz -> 48 kHz
 * 48 kHz ->  8 kHz
 *  8 kHz -> 48 kHz
 *
 ******************************************************************/

typedef struct {
  int32_t S_48_48[16];
  int32_t S_48_32[8];
  int32_t S_32_16[8];
} WebRtcSpl_State48khzTo16khz;

void WebRtcSpl_Resample48khzTo16khz(const int16_t* in,
                                    int16_t* out,
                                    WebRtcSpl_State48khzTo16khz* state,
                                    int32_t* tmpmem);

void WebRtcSpl_ResetResample48khzTo16khz(WebRtcSpl_State48khzTo16khz* state);

typedef struct {
  int32_t S_16_32[8];
  int32_t S_32_24[8];
  int32_t S_24_48[8];
} WebRtcSpl_State16khzTo48khz;

void WebRtcSpl_Resample16khzTo48khz(const int16_t* in,
                                    int16_t* out,
                                    WebRtcSpl_State16khzTo48khz* state,
                                    int32_t* tmpmem);

void WebRtcSpl_ResetResample16khzTo48khz(WebRtcSpl_State16khzTo48khz* state);

typedef struct {
  int32_t S_48_24[8];
  int32_t S_24_24[16];
  int32_t S_24_16[8];
  int32_t S_16_8[8];
} WebRtcSpl_State48khzTo8khz;

void WebRtcSpl_Resample48khzTo8khz(const int16_t* in,
                                   int16_t* out,
                                   WebRtcSpl_State48khzTo8khz* state,
                                   int32_t* tmpmem);

void WebRtcSpl_ResetResample48khzTo8khz(WebRtcSpl_State48khzTo8khz* state);

typedef struct {
  int32_t S_8_16[8];
  int32_t S_16_12[8];
  int32_t S_12_24[8];
  int32_t S_24_48[8];
} WebRtcSpl_State8khzTo48khz;

void WebRtcSpl_Resample8khzTo48khz(const int16_t* in,
                                   int16_t* out,
                                   WebRtcSpl_State8khzTo48khz* state,
                                   int32_t* tmpmem);

void WebRtcSpl_ResetResample8khzTo48khz(WebRtcSpl_State8khzTo48khz* state);

/*******************************************************************
 * resample_by_2.c
 *
 * Includes down and up sampling by a factor of two.
 *
 ******************************************************************/

void WebRtcSpl_DownsampleBy2(const int16_t* in,
                             size_t len,
                             int16_t* out,
                             int32_t* filtState);

void WebRtcSpl_UpsampleBy2(const int16_t* in,
                           size_t len,
                           int16_t* out,
                           int32_t* filtState);
#ifdef __cplusplus
}
#endif  // __cplusplus
#endif  // COMMON_AUDIO_SIGNAL_PROCESSING_INCLUDE_SIGNAL_PROCESSING_LIBRARY_H_
