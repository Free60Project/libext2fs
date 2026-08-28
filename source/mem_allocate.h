#ifndef _MEM_ALLOCATE_H
#define _MEM_ALLOCATE_H

#include <malloc.h>

#define mem_alloc(size) malloc(size)
#define mem_calloc(count, size) calloc(count, size)
#define mem_realloc(p, size) realloc(p, size)
#define mem_align(a,size) memalign(a, size)
#define mem_free(mem) free(mem)

#endif /* _MEM_ALLOCATE_H */
