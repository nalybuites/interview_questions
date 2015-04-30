#ifndef _UTIL_H_
#define _UTIL_H_

typedef int compar_t(const void *, const void *);
typedef void sort_t(int [], unsigned int, compar_t *);

#define max(a,b) \
	({ __typeof__ (a) _a = (a); \
		__typeof__ (b) _b = (b); \
		_a > _b ? _a : _b; })

#define min(a,b) \
	({ __typeof__ (a) _a = (a); \
		__typeof__ (b) _b = (b); \
		_a < _b ? _a : _b; })

#endif /* _UTIL_H_ */
