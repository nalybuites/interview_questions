#ifndef _UTIL_H_
#define _UTIL_H_

typedef int compar_t(const void *, const void *);
typedef void sort_t(int [], unsigned int, compar_t *);

#define BUILD_ASSERT_OR_ZERO(cond) \
    (sizeof(char [1 - 2*!(cond)]) - 1)

#define _array_size_check(arr) \
    BUILD_ASSERT_OR_ZERO(!__builtin_types_compatible_p(typeof(arr), \
		typeof(&(arr)[0])))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + _array_size_check(arr))

#define MAX(a,b) \
	({ __typeof__ (a) _a = (a); \
		__typeof__ (b) _b = (b); \
		_a > _b ? _a : _b; })

#define MIN(a,b) \
	({ __typeof__ (a) _a = (a); \
		__typeof__ (b) _b = (b); \
		_a < _b ? _a : _b; })

#endif /* _UTIL_H_ */
