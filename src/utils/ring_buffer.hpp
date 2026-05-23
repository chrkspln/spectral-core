#pragma once

#include <atomic>
#include <array>
#include <cstddef>
#include <optional>
#include <type_traits>

namespace spectral::utils {

// Lock-free single-producer / single-consumer ring buffer.
// Used on two hot paths:
//   RingBuf①: IO thread (producer) → AUDIO callback (consumer)
//   RingBuf②: AUDIO callback (producer) → ANALYSIS thread (consumer)
//
// Capacity must be a power of 2 — enables bitmask wrap (index & (Capacity-1))
// instead of modulo, which is not RT-safe on some platforms.
// Enforced with static_assert below.
//
// RT contract: push() and pop() are both wait-free (single CAS-free path).
// No malloc, no mutex, no syscall on either side.
template<typename T, std::size_t Capacity>
class RingBuffer {
    static_assert((Capacity & (Capacity - 1)) == 0,
        "RingBuffer Capacity must be a power of 2");
    static_assert(std::is_trivially_copyable_v<T>,
        "RingBuffer<T>: T must be trivially copyable (no vtable, no heap in RT path)");

public:
    // TODO: push(const T& item) -> bool
    //   load head_ (relaxed), compute next = (head + 1) & mask
    //   if next == tail_.load(acquire): return false  (full)
    //   storage_[head] = item
    //   head_.store(next, release)
    //   return true

    // TODO: pop(T& out) -> bool
    //   load tail_ (relaxed)
    //   if tail == head_.load(acquire): return false  (empty)
    //   out = storage_[tail]
    //   tail_.store((tail + 1) & mask, release)
    //   return true

    // TODO: size() const -> std::size_t    (approximate — both atomics read separately)
    // TODO: isEmpty() const -> bool
    // TODO: isFull() const -> bool

    // TODO: clear()  — only safe when no concurrent push/pop is happening

private:
    static constexpr std::size_t kMask = Capacity - 1;

    // head_ and tail_ on separate cache lines to prevent false sharing between
    // producer thread and consumer thread (each has its own cache line).
    alignas(64) std::atomic<std::size_t> head_{0};
    alignas(64) std::atomic<std::size_t> tail_{0};

    std::array<T, Capacity> storage_{};
};

} // namespace spectral::utils
