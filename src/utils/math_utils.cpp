#include "math_utils.hpp"

#include <cmath>

namespace spectral::utils {

float dbToLinear(Decibel dB) {
    // TODO: return std::pow(10.0f, dB.value / 20.0f);
    return 0.0f;
}

Decibel linearToDb(float linear) {
    // TODO: guard against linear <= 0 (log of zero = -inf):
    //   if (linear <= 0.0f) return Decibel{-std::numeric_limits<float>::infinity()};
    //   return Decibel{20.0f * std::log10(linear)};
    return Decibel{0.0f};
}

float hzToMel(Hz freq) {
    // TODO: return 2595.0f * std::log10(1.0f + freq.value / 700.0f);
    return 0.0f;
}

Hz melToHz(float mel) {
    // TODO: return Hz{700.0f * (std::pow(10.0f, mel / 2595.0f) - 1.0f)};
    return Hz{0.0f};
}

} // namespace spectral::utils
