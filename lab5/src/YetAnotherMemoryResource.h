#pragma once

#include <list>
#include <map>
#include <memory_resource>

struct MemoryBlock {
    void *system_ptr;
    size_t size;

    bool operator==(const MemoryBlock &other) const {
        return system_ptr == other.system_ptr && size == other.size;
    }
};

class YetAnotherMemoryResource : public std::pmr::memory_resource {
public:
    YetAnotherMemoryResource() = default;

    YetAnotherMemoryResource(YetAnotherMemoryResource&&) = delete;

    ~YetAnotherMemoryResource() override;

    void *do_allocate(std::size_t bytes, std::size_t alignment) override;

    void do_deallocate(void *p, std::size_t bytes, std::size_t alignment) override;

    [[nodiscard]] bool do_is_equal(const memory_resource &other) const noexcept override;

private:
    void *do_allocate_new(std::size_t bytes, std::size_t alignment);

    std::map<uint8_t *, MemoryBlock> blocks;
    std::list<MemoryBlock> free_blocks;
};
