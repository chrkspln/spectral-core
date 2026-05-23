#pragma once

#include <stdexcept>
#include <string>

namespace spectral {

// Base for all spectral runtime errors.
// Catch SpectralException to handle any library error generically.
class SpectralException : public std::runtime_error {
public:
    explicit SpectralException(const std::string& msg)
        : std::runtime_error(msg) {}
};

// PortAudio failed to open, initialise, or operate a device.
// Thrown from AudioDevice::open() and AudioDevice::start().
class AudioDeviceError : public SpectralException {
public:
    explicit AudioDeviceError(const std::string& msg)
        : SpectralException(msg) {}
    // TODO: add int paErrorCode field — store the raw PaError from PortAudio
    //   so the caller can distinguish device-busy from unsupported-format etc.
};

// libsndfile could not open or decode a file.
// Thrown from AudioFile constructor.
class FileFormatError : public SpectralException {
public:
    explicit FileFormatError(const std::string& msg)
        : SpectralException(msg) {}
    // TODO: add std::filesystem::path path field — include in what() message
};

// TODO v0.3: EQException, InvalidBandError, OutOfRangeError (inherit SpectralException)
// TODO v0.3: ConfigException (malformed JSON, missing required key)
// TODO v0.5: DatabaseException, NetworkException

} // namespace spectral
