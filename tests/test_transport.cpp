#include <gtest/gtest.h>
#include "engine/transport.hpp"

using namespace spectral::engine;

// TODO: InitialState
//   Transport t;
//   EXPECT_EQ(t.state(), TransportState::Stopped)
//   EXPECT_EQ(t.position(), 0)
//   EXPECT_FALSE(t.isPlaying())

// TODO: PlayFromStopped
//   t.play();  EXPECT_EQ(t.state(), TransportState::Playing)

// TODO: PauseWhilePlaying
//   t.play(); t.pause();  EXPECT_EQ(t.state(), TransportState::Paused)

// TODO: PlayFromPaused
//   t.play(); t.pause(); t.play();  EXPECT_EQ(t.state(), TransportState::Playing)

// TODO: StopFromAnyState
//   t.play(); t.stop();  EXPECT_EQ(t.state(), TransportState::Stopped)
//   EXPECT_EQ(t.position(), 0)   — stop must reset position

// TODO: SeekPreservesState
//   t.play(); t.seek(1000);
//   EXPECT_EQ(t.position(), 1000)
//   EXPECT_EQ(t.state(), TransportState::Playing)  — state unchanged by seek

// TODO: PauseNoOpWhenStopped
//   Transport t; t.pause();  EXPECT_EQ(t.state(), TransportState::Stopped)