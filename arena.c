#include "arena.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool arena_init(struct ArenaAllocator *arena, size_t size) {
    arena->memory = (char *)malloc(size);
    if (!arena->memory) {
        return false;
    }
    arena->size = size;
    arena->offset = 0;
    return true;
}

void *arena_alloc(struct ArenaAllocator *arena, size_t size) {
    if (arena->offset + size > arena->size) {
        return NULL;
    }
    void *ptr = arena->memory + arena->offset;
    arena->offset += size;
    return ptr;
}

void arena_reset(struct ArenaAllocator *arena) {
    arena->offset = 0;
}

void arena_free(struct ArenaAllocator *arena) {
    free(arena->memory);
    arena->memory = NULL;
    arena->size = 0;
    arena->offset = 0;
}
