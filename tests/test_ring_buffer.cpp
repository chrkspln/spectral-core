#include <gtest/gtest.h>
#include <thread>
#include <latch>
#include "utils/ring_buffer.hpp"

using namespace spectral::utils;
using Buffer = RingBuffer<float, 8>;  // Capacity=8 for easy boundary tests

// TODO: BasicPushPop
//   push one value, pop it, EXPECT_EQ result, EXPECT_TRUE return value of both calls

// TODO: FullBuffer
//   push 8 items (full), EXPECT_TRUE isFull()
//   push one more, EXPECT_FALSE (buffer full — push must reject)

// TODO: EmptyBuffer
//   pop from default-constructed buffer, EXPECT_FALSE
//   EXPECT_TRUE isEmpty()

// TODO: WrapAround
//   push 4, pop 4, push 6 more → exercises index wrapping past Capacity
//   verify all 6 values match what was pushed, in order

// TODO: SPSCConcurrent
//   producer std::jthread pushes 1024 floats (values 0..1023)
//   consumer std::jthread pops 1024 floats into a vector
//   use std::latch(2) to start both threads simultaneously
//   after join: EXPECT_EQ(received.size(), 1024) and values are in order
//   NOTE: this is the real test — proves the atomic ordering is correct
