#pragma once

#include <vector>
#include <cstddef>
#include <cassert>
#include "strong_types.hpp"

namespace spectral::utils {

// Owns a block of audio samples in planar layout:
//   [ch0_s0, ch0_s1, ..., ch0_sN,  ch1_s0, ch1_s1, ..., ch1_sN]
// Planar (vs interleaved) keeps each channel contiguous — better cache behaviour for DSP.
// libsndfile delivers interleaved; deinterleave on load, once.
//
// Size is fixed at construction — no resize after creation (RT-safety requirement).
template<typename T = float>
class AudioBuffer {
public:
    // TODO: constructor(channels, frames, SampleRate)
    //   pre-allocate storage: data_.resize(channels * frames)
    //   store channels_, frames_, sampleRate_

    // TODO: data(channel) -> T*
    //   returns pointer to start of channel slice: data_.data() + channel * frames_
    //   assert channel < channels_

    // TODO: const overload data(channel) const -> const T*

    // TODO: frames() const -> std::size_t
    // TODO: channels() const -> std::size_t
    // TODO: sampleRate() const -> SampleRate
    // TODO: isEmpty() const -> bool   (frames_ == 0 || channels_ == 0)

    // TODO: clear()
    //   std::fill(data_.begin(), data_.end(), T{0})

    // TODO: copyFrom(const AudioBuffer& src, std::size_t srcChannel,
    //                std::size_t dstChannel, std::size_t frameCount)
    //   assert bounds on both sides before memcpy
    //   used when IO thread fills one channel at a time from libsndfile

    // TODO v0.2: applyGain(channel, T gain)  — multiply channel slice by scalar
    // TODO v0.2: addFrom(const AudioBuffer& src, std::size_t srcCh, std::size_t dstCh, T gain)
    //   used in EffectChain mixing

private:
    std::vector<T> data_;
    std::size_t    channels_{0};
    std::size_t    frames_{0};
    SampleRate     sampleRate_{0};
};

} // namespace spectral::utils
