#ifndef ARENA_H
#define ARENA_H

#include <stdlib.h>
#include <stdbool.h>

/**
* Arena allocator.
*/
struct ArenaAllocator {
    char *memory;
    size_t size;
    size_t offset;
};

/**
* Initialize the arena allocator.
* @param arena Arena allocator.
* @param size Size of the arena.
* @return True if the arena was initialized successfully, false otherwise.
*/
bool arena_init(struct ArenaAllocator *arena, size_t size);

/**
* Allocate memory from the arena.
* @param arena Arena allocator.
* @param size Size of the memory to allocate.
* @return Pointer to the allocated memory, or NULL if the allocation failed.
*/
void *arena_alloc(struct ArenaAllocator *arena, size_t size);

/**
* Reset the arena allocator.
* @param arena Arena allocator.
*/
void arena_reset(struct ArenaAllocator *arena);

/**
* Free the arena allocator.
* @param arena Arena allocator.
*/
void arena_free(struct ArenaAllocator *arena);

#endif //ARENA_H
