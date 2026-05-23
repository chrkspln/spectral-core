#include <iostream>
#include <string>
#include <filesystem>

#include "utils/logger.hpp"
#include "utils/exceptions.hpp"
#include "io/audio_file.hpp"
#include "io/audio_device.hpp"
#include "io/audio_callback.hpp"
#include "engine/transport.hpp"

// v0.1 proof-of-life entry point.
// Goal: load a WAV file, stream it through PortAudio, print peak RMS to stdout.
// No UI. One file argument. Ctrl+C to stop.
//
// TODO: main(int argc, char* argv[])
//
//   1. Validate argument: argc == 2, argv[1] is a readable file path
//      print usage and return 1 otherwise
//
//   2. Logger::init(spdlog::level::info)
//
//   3. AudioFile file{argv[1]}
//      print sampleRate, channels, totalFrames to stdout
//
//   4. Transport transport;
//
//   5. RingBuffer<float, 4096> ringBuf;  // IO → AUDIO
//
//   6. IO thread (std::jthread): reads frames from AudioFile into ringBuf
//      checks transport.isPlaying() before each read
//      signals end-of-file by stopping transport
//
//   7. AudioDevice device;
//      device.open(file.sampleRate(), file.channels(), 256)
//      device.start([&](const float*, float* out, std::size_t frames) {
//          // pop from ringBuf into out
//          // compute peak RMS over this frame block
//          // store in std::atomic<float> rms
//      })
//
//   8. transport.play()
//
//   9. Main loop: while transport.isPlaying():
//          std::cout << "\rRMS: " << rms.load() << "  " << std::flush
//          std::this_thread::sleep_for(50ms)
//
//  10. transport.stop(); device.close(); Logger::flush()

int main() {
    std::cout << "spectral v0.1\n";
    return 0;
}
