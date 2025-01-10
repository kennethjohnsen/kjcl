//
// Created by Kenneth Johnsen on 10/01/2025.
//

#ifndef ARENA_H
#define ARENA_H

#include <stdlib.h>

typedef struct {
    char *memory;
    size_t size;
    size_t offset;
} ArenaAllocator;

// Initialize the arena allocator with a given size
void arena_init(ArenaAllocator *arena, size_t size);

// Allocate memory from the arena
void *arena_alloc(ArenaAllocator *arena, size_t size);

// Reset the arena for reuse
void arena_reset(ArenaAllocator *arena);

// Free the arena memory
void arena_free(ArenaAllocator *arena);

#endif //ARENA_H
