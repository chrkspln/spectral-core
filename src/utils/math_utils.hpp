#pragma once

#include "strong_types.hpp"

namespace spectral::utils {

// dB ↔ linear amplitude conversion.
// db_to_linear(-6.0_db) ≈ 0.501  (half power)
// linear_to_db(1.0f)    =  0.0 dB
float dbToLinear(Decibel dB);
Decibel linearToDb(float linear);

// Clamp a value to [lo, hi] inclusive.
// Used in BiquadFilter coefficient clamping and gain normalisation.
template<typename T>
constexpr T clamp(T value, T lo, T hi) {
    // TODO: implement — or just delegate to std::clamp once you verify the include
    //   return std::clamp(value, lo, hi);
    return value;
}

// Convert linear frequency to Mel scale.
// mel(f) = 2595 * log10(1 + f/700)
// Needed by SpectralAnalyser filterbank in v0.2.
float hzToMel(Hz freq);
Hz    melToHz(float mel);

// TODO v0.2: nextPowerOfTwo(n) — used to pick FFT window size
// TODO v0.2: hzToFftBin(Hz freq, SampleRate sr, std::size_t fftSize) -> std::size_t
// TODO v0.2: complex magnitude helpers wrapping std::complex<float>

} // namespace spectral::utils
