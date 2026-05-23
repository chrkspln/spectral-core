#include "audio_device.hpp"
#include "utils/exceptions.hpp"

#include <portaudio.h>

namespace spectral::io {

AudioDevice::~AudioDevice() {
    // TODO: call close() — ensures PA stream is always released even on exception paths
}

void AudioDevice::open(utils::SampleRate sampleRate,
                       int               channelCount,
                       std::size_t       framesPerBuffer) {
    // TODO:
    //   Pa_Initialize() — returns PaError; throw AudioDeviceError if != paNoError
    //   Pa_OpenDefaultStream(&stream_, 0, channelCount, paFloat32,
    //       sampleRate.value, framesPerBuffer, paCallback, this)
    //   throw AudioDeviceError on failure, including Pa_GetErrorText(err) in message
    //   set isOpen_ = true, sampleRate_ = sampleRate, framesPerBuffer_ = framesPerBuffer
}

void AudioDevice::close() {
    // TODO:
    //   if (!isOpen_) return;
    //   stop() if running
    //   Pa_CloseStream(stream_)
    //   Pa_Terminate()
    //   stream_ = nullptr; isOpen_ = false
}

void AudioDevice::start(AudioCallback callback) {
    // TODO:
    //   if (!isOpen_) throw AudioDeviceError("device not open")
    //   callback_ = std::move(callback)
    //   Pa_StartStream(stream_) — throw on error
}

void AudioDevice::stop() {
    // TODO:
    //   if (!isOpen_) return
    //   Pa_StopStream(stream_) — log warning on error, do not throw (called from destructor path)
}

bool              AudioDevice::isOpen()          const { return isOpen_; }
utils::SampleRate AudioDevice::sampleRate()      const { return sampleRate_; }
std::size_t       AudioDevice::framesPerBuffer() const { return framesPerBuffer_; }

// TODO: implement paCallback static method (see header)

} // namespace spectral::io
