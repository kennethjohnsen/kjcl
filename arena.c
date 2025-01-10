#include "arena.h"
#include <stdlib.h>
#include <stdio.h>

// Initialize the arena allocator with a given size
void arena_init(ArenaAllocator *arena, size_t size) {
    arena->memory = (char *)malloc(size);
    if (!arena->memory) {
        fprintf(stderr, "Failed to allocate memory for arena\n");
        exit(EXIT_FAILURE);
    }
    arena->size = size;
    arena->offset = 0;
}

// Allocate memory from the arena
void *arena_alloc(ArenaAllocator *arena, size_t size) {
    if (arena->offset + size > arena->size) {
        fprintf(stderr, "Arena out of memory\n");
        return NULL;
    }
    void *ptr = arena->memory + arena->offset;
    arena->offset += size;
    return ptr;
}

// Reset the arena for reuse
void arena_reset(ArenaAllocator *arena) {
    arena->offset = 0;
}

// Free the arena memory
void arena_free(ArenaAllocator *arena) {
    free(arena->memory);
    arena->memory = NULL;
    arena->size = 0;
    arena->offset = 0;
}
