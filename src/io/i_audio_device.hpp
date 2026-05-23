#pragma once

#include "audio_callback.hpp"
#include "utils/strong_types.hpp"
#include <cstddef>

namespace spectral::io {

// Pure virtual interface for audio output hardware.
// Write tests against this interface (gmock), not against PortAudio directly.
// AudioDevice is the only production implementation for v0.1.
//
// Lifecycle: construct → open() → start() → [running] → stop() → close() → destruct
// RAII rule: destructor must call close() if still open — never leak a PA stream.
class IAudioDevice {
public:
    virtual ~IAudioDevice() = default;

    // Allocate hardware resources. Throws AudioDeviceError on failure.
    // Must be called before start(). Sets sampleRate and framesPerBuffer.
    virtual void open(utils::SampleRate sampleRate,
                      int               channelCount,
                      std::size_t       framesPerBuffer) = 0;

    // Release hardware resources. Safe to call even if not open (no-op).
    virtual void close() = 0;

    // Begin streaming. Registers callback — called from AUDIO thread hereafter.
    // Throws AudioDeviceError if not open or already started.
    virtual void start(AudioCallback callback) = 0;

    // Halt streaming. Callback will not be invoked after this returns.
    // Does not close the device — can call start() again.
    virtual void stop() = 0;

    virtual bool             isOpen()          const = 0;
    virtual utils::SampleRate sampleRate()      const = 0;
    virtual std::size_t       framesPerBuffer() const = 0;
};

} // namespace spectral::io
