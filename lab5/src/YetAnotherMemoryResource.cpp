#include "YetAnotherMemoryResource.h"


uint8_t *to_alignment(void *ptr, const size_t alignment) {
    const size_t block_num = reinterpret_cast<size_t>(ptr);

    if (block_num % alignment == 0)
        return static_cast<uint8_t *>(ptr);

    return reinterpret_cast<uint8_t *>((block_num / alignment + 1) * alignment);
}

YetAnotherMemoryResource::~YetAnotherMemoryResource() {
    for (auto mb: free_blocks) {
        const uint8_t *system_ptr = static_cast<uint8_t *>(mb.system_ptr);
        delete[] system_ptr;
    }
    for (auto pair: blocks) {
        const uint8_t *system_ptr = static_cast<uint8_t *>(pair.second.system_ptr);
        delete[] system_ptr;
    }
}

void *YetAnotherMemoryResource::do_allocate(const std::size_t bytes, const std::size_t alignment) {
    const size_t size = bytes + alignment;

    for (const auto &mb: free_blocks) {
        if (mb.size >= size) {
            MemoryBlock mb_copy(mb);
            free_blocks.remove(mb);

            uint8_t *return_block = to_alignment(mb_copy.system_ptr, alignment);

            blocks[return_block] = mb_copy;
            return return_block;
        }
    }

    return do_allocate_new(bytes, alignment);
}

void *YetAnotherMemoryResource::do_allocate_new(const std::size_t bytes, const std::size_t alignment) {
    const size_t size = bytes + alignment;

    uint8_t *block = static_cast<uint8_t *>(std::malloc(size));
    uint8_t *return_block = to_alignment(block, alignment);

    const MemoryBlock mb(block, size);
    blocks[return_block] = mb;
    return return_block;
}

void YetAnotherMemoryResource::do_deallocate(void *p, std::size_t bytes, std::size_t alignment) {
    uint8_t *ptr = static_cast<uint8_t *>(p);

    const MemoryBlock mb = blocks[ptr];
    blocks.erase(ptr);
    free_blocks.push_back(mb);
}

bool YetAnotherMemoryResource::do_is_equal(const memory_resource &other) const noexcept {
    return this == &other;
}
