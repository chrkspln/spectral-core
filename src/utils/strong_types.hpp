#pragma once

#include <cstdint>

namespace spectral::utils {

// Strong wrapper macro — saves boilerplate for each type.
// Each type is a distinct C++ type: passing Hz where Decibel expected = compile error.
// explicit constructor prevents silent implicit conversions from raw numbers.
#define SPECTRAL_STRONG_TYPE(Name, Underlying, field) \
    struct Name {                                      \
        Underlying field{};                            \
        constexpr explicit Name(Underlying v) : field(v) {} \
        Name() = default;                              \
    }

// Frequency in Hertz — floating point (e.g. 440.0, 20000.5).
// uint would lose fractional precision needed for precise FFT bin mapping.
SPECTRAL_STRONG_TYPE(Hz, float, value);

// Amplitude in decibels — floating point, can be negative (e.g. -6.0 dB, -96.0 dB noise floor).
// uint would make silence and attenuation unrepresentable.
SPECTRAL_STRONG_TYPE(Decibel, float, value);

// Audio sample rate — always a positive integer (44100, 48000, 96000).
// uint32_t is sufficient; no fractional sample rates in practice.
SPECTRAL_STRONG_TYPE(SampleRate, uint32_t, value);

// TODO v0.2: add when DSP module lands
//   SPECTRAL_STRONG_TYPE(NormalizedGain, float, value);  // 0.0–1.0 linear amplitude
//   SPECTRAL_STRONG_TYPE(Milliseconds, float, value);    // attack/release times
//   SPECTRAL_STRONG_TYPE(BPM, float, value);             // beat detector output
//   SPECTRAL_STRONG_TYPE(MidiNote, uint8_t, value);      // 0–127, v0.5 MIDI

// TODO v0.2: consider user-defined literals for ergonomic construction:
//   440.0_hz, -6.0_db, 44100_sr
//   implement as constexpr operator""_hz(long double v) in a literals.hpp

#undef SPECTRAL_STRONG_TYPE

} // namespace spectral::utils
