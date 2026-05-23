#pragma once

#include "i_audio_device.hpp"

// Forward-declare PA types to avoid leaking portaudio.h into public headers.
// Only audio_device.cpp includes <portaudio.h>.
struct PaStreamCallbackTimeInfo;
using PaStream = void;

namespace spectral::io {

// PortAudio RAII implementation of IAudioDevice.
// Owns a PaStream* — opened in open(), closed in close()/destructor.
//
// Thread safety: open/close/start/stop are called from the main thread only.
// The AudioCallback is invoked from PortAudio's internal AUDIO thread.
class AudioDevice final : public IAudioDevice {
public:
    AudioDevice() = default;
    ~AudioDevice() override;

    // Non-copyable — owns a hardware stream handle.
    AudioDevice(const AudioDevice&)            = delete;
    AudioDevice& operator=(const AudioDevice&) = delete;

    // Movable — transfer ownership of the stream handle.
    // TODO: implement move constructor and move assignment operator

    void open(utils::SampleRate sampleRate,
              int               channelCount,
              std::size_t       framesPerBuffer) override;
    void close() override;
    void start(AudioCallback callback) override;
    void stop() override;

    bool              isOpen()          const override;
    utils::SampleRate sampleRate()      const override;
    std::size_t       framesPerBuffer() const override;

private:
    // TODO: static int paCallback(const void* input, void* output,
    //     unsigned long frameCount, const PaStreamCallbackTimeInfo*,
    //     unsigned long statusFlags, void* userData)
    //   cast userData to AudioDevice*, invoke stored callback_
    //   return paContinue

    PaStream*     stream_{nullptr};
    AudioCallback callback_;
    utils::SampleRate sampleRate_{0};
    std::size_t   framesPerBuffer_{0};
    bool          isOpen_{false};
};

} // namespace spectral::io
