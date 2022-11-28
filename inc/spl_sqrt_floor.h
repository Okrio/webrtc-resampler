#include <stdint.h>

//
// WebRtcSpl_SqrtFloor(...)
//
// Returns the square root of the input value |value|. The precision of this
// function is rounding down integer precision, i.e., sqrt(8) gives 2 as answer.
// If |value| is a negative number then 0 is returned.
//
// Algorithm:
//
// An iterative 4 cylce/bit routine
//
// Input:
//      - value     : Value to calculate sqrt of
//
// Return value     : Result of the sqrt calculation
//
int32_t WebRtcSpl_SqrtFloor(int32_t value);