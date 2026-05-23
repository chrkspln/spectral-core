#include <gtest/gtest.h>
#include "utils/strong_types.hpp"

using namespace spectral::utils;

// TODO: DistinctTypes
//   static_assert(!std::is_same_v<Hz, Decibel>)
//   static_assert(!std::is_same_v<Hz, SampleRate>)
//   these catch accidental typedef aliases — put at namespace scope, not in a test body

// TODO: ExplicitConstruction
//   Hz f{440.0f};  EXPECT_FLOAT_EQ(f.value, 440.0f)
//   Decibel d{-6.0f};  EXPECT_FLOAT_EQ(d.value, -6.0f)
//   SampleRate sr{44100u};  EXPECT_EQ(sr.value, 44100u)

// TODO: NoImplicitConversion (compile-time test)
//   void takesHz(Hz) {}
//   // the line below must NOT compile — add it in a #if 0 block with a comment
//   // takesHz(440.0f);   // should fail: no implicit float→Hz conversion

// TODO: DefaultConstruction
//   Hz f{};  EXPECT_FLOAT_EQ(f.value, 0.0f)   — default-initialised to 0