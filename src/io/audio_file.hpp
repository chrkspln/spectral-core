#pragma once

#include "utils/strong_types.hpp"
#include "utils/audio_buffer.hpp"
#include <filesystem>
#include <cstddef>

// Forward-declare libsndfile handle — do not expose sndfile.h in public header.
struct SNDFILE_tag;
using SNDFILE = SNDFILE_tag;

namespace spectral::io {

// RAII wrapper around a libsndfile audio file.
// Constructor opens the file; destructor closes it.
// Throws FileFormatError if the file cannot be opened or the format is unsupported.
//
// Supported formats (via libsndfile): WAV, FLAC, OGG/Vorbis, AIFF, and others.
class AudioFile {
public:
    explicit AudioFile(const std::filesystem::path& path);
    ~AudioFile();

    // Non-copyable — owns a file handle.
    AudioFile(const AudioFile&)            = delete;
    AudioFile& operator=(const AudioFile&) = delete;

    // Movable.
    // TODO: implement move constructor and move assignment

    // Read all frames into an AudioBuffer (deinterleaved to planar layout).
    // Allocates the buffer; returns it by value (NRVO).
    // TODO: implement readAll() -> utils::AudioBuffer<float>
    //   sf_readf_float into a temporary interleaved buffer, then deinterleave

    // TODO: readFrames(utils::AudioBuffer<float>& dest, std::size_t frameCount) -> std::size_t
    //   incremental read for large files — fills dest, returns frames actually read
    //   used by IO thread in v0.1 streaming path

    utils::SampleRate sampleRate()   const;
    int               channels()     const;
    std::size_t       totalFrames()  const;
    std::string       formatString() const;  // e.g. "WAV/PCM_16"

private:
    SNDFILE*    file_{nullptr};
    utils::SampleRate sampleRate_{0};
    int         channels_{0};
    std::size_t totalFrames_{0};
};

} // namespace spectral::io
