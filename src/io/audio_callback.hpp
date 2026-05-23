#pragma once

#include <functional>
#include <cstddef>

namespace spectral::io {

// Real-time audio processing callback signature.
// Registered via IAudioDevice::start() — PortAudio calls this from its AUDIO thread.
//
// RT CONTRACT (must be honoured by every implementation):
//   - no heap allocation (new / delete / malloc / std::vector resize)
//   - no mutex or condition_variable lock/unlock
//   - no file I/O, no spdlog, no syscalls
//   - must complete within ~5ms at 256 frames / 44100 Hz
//
// inputBuffer:  interleaved input samples (nullptr for output-only devices)
// outputBuffer: interleaved output buffer to fill — write exactly frameCount frames
// frameCount:   number of sample frames in this invocation (matches framesPerBuffer)
using AudioCallback = std::function<void(
    const float* inputBuffer,
    float*       outputBuffer,
    std::size_t  frameCount
)>;

// NOTE: std::function has a small internal allocation but it is incurred once at
// registration time (IAudioDevice::start), not on every callback invocation.
// If profiling shows overhead, replace with a raw fn ptr + void* userData pair
// matching PortAudio's own PaStreamCallback signature.

} // namespace spectral::io
