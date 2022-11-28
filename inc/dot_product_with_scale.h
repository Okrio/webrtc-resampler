#ifndef COMMON_AUDIO_SIGNAL_PROCESSING_DOT_PRODUCT_WITH_SCALE_H_
#define COMMON_AUDIO_SIGNAL_PROCESSING_DOT_PRODUCT_WITH_SCALE_H_

#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

// Calculates the dot product between two (int16_t) vectors.
//
// Input:
//      - vector1       : Vector 1
//      - vector2       : Vector 2
//      - vector_length : Number of samples used in the dot product
//      - scaling       : The number of right bit shifts to apply on each term
//                        during calculation to avoid overflow, i.e., the
//                        output will be in Q(-|scaling|)
//
// Return value         : The dot product in Q(-scaling)
int32_t WebRtcSpl_DotProductWithScale(const int16_t* vector1,
                                      const int16_t* vector2,
                                      size_t length,
                                      int scaling);

#ifdef __cplusplus
}
#endif  // __cplusplus
#endif  // COMMON_AUDIO_SIGNAL_PROCESSING_DOT_PRODUCT_WITH_SCALE_H_
