#ifndef RTC_BASE_CONSTRUCTOR_MAGIC_H_
#define RTC_BASE_CONSTRUCTOR_MAGIC_H_

// A macro to disallow the copy constructor and operator= functions. This should
// be used in the declarations for a class.
#define RTC_DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&) = delete;          \
  TypeName& operator=(const TypeName&) = delete

#endif  // RTC_BASE_CONSTRUCTOR_MAGIC_H_