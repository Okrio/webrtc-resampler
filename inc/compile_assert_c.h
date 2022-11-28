#ifndef RTC_BASE_COMPILE_ASSERT_C_H_
#define RTC_BASE_COMPILE_ASSERT_C_H_

// Use this macro to verify at compile time that certain restrictions are met.
// The argument is the boolean expression to evaluate.
// Example:
//   RTC_COMPILE_ASSERT(sizeof(foo) < 128);
// Note: In C++, use static_assert instead!
#define RTC_COMPILE_ASSERT(expression) \
  switch (0) {                         \
    case 0:                            \
    case expression:;                  \
  }

#endif  // RTC_BASE_COMPILE_ASSERT_C_H_