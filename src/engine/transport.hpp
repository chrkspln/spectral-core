#pragma once

#include <cstddef>
#include <atomic>

namespace spectral::engine {

enum class TransportState { Stopped, Playing, Paused };

// Models playback lifecycle as an explicit state machine.
// Holds logical position (frame index) — has no audio data itself.
// The IO thread reads position() to know where to decode from next.
//
// State transitions:
//
//        play()              pause()
//  Stopped ──→ Playing ────────→ Paused
//     ↑             │               │
//     └─────────────┴───────────────┘
//              stop() (any state → Stopped, position reset to 0)
//
// seek() moves the playhead but does NOT change the current state.
// Thread safety: position_ is atomic — IO thread reads, main thread writes via seek().
// State transitions are main-thread-only in v0.1 (single controller).
class Transport {
public:
    // Transition Stopped/Paused → Playing. No-op if already Playing.
    void play();

    // Transition Playing → Paused. No-op if Stopped or already Paused.
    void pause();

    // Transition any state → Stopped. Resets position to 0.
    void stop();

    // Move playhead to framePosition without changing state.
    // Called by UI seek bar or when file loops.
    void seek(std::size_t framePosition);

    TransportState state()     const;
    std::size_t    position()  const;
    bool           isPlaying() const;

    // TODO v0.2: setLoopPoints(std::size_t loopStart, std::size_t loopEnd)
    //   IO thread checks position against loopEnd and seeks back to loopStart

private:
    TransportState           state_{TransportState::Stopped};
    std::atomic<std::size_t> position_{0};
};

} // namespace spectral::engine
