#ifndef PUTILIMP_H
#define PUTILIMP_H

/**
 * Define malloc and related functions
 * @internal
 */
/* C defaults */
# define uprv_default_malloc(x) malloc(x)
# define uprv_default_realloc(x,y) realloc(x,y)
# define uprv_default_free(x) free(x)

#endif