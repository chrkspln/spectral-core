#include "transport.hpp"

namespace spectral::engine {

void Transport::play() {
    // TODO: if state_ == Stopped || state_ == Paused → state_ = Playing
    //   (else no-op)
}

void Transport::pause() {
    // TODO: if state_ == Playing → state_ = Paused
    //   (else no-op)
}

void Transport::stop() {
    // TODO: state_ = Stopped; position_.store(0, std::memory_order_relaxed)
}

void Transport::seek(std::size_t framePosition) {
    // TODO: position_.store(framePosition, std::memory_order_relaxed)
    //   state_ unchanged — seeking while playing stays playing
}

TransportState Transport::state()     const { return state_; }
std::size_t    Transport::position()  const { return position_.load(std::memory_order_relaxed); }
bool           Transport::isPlaying() const { return state_ == TransportState::Playing; }

} // namespace spectral::engine
