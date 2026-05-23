#include "audio_file.hpp"
#include "utils/exceptions.hpp"

#include <sndfile.h>

namespace spectral::io {

AudioFile::AudioFile(const std::filesystem::path& path) {
    // TODO:
    //   SF_INFO info{};
    //   file_ = sf_open(path.string().c_str(), SFM_READ, &info);
    //   if (!file_) throw FileFormatError("cannot open: " + path.string()
    //                                     + " — " + sf_strerror(nullptr))
    //   sampleRate_  = utils::SampleRate{static_cast<uint32_t>(info.samplerate)};
    //   channels_    = info.channels;
    //   totalFrames_ = static_cast<std::size_t>(info.frames);
}

AudioFile::~AudioFile() {
    // TODO: if (file_) sf_close(file_);
}

utils::SampleRate AudioFile::sampleRate()  const { return sampleRate_; }
int               AudioFile::channels()    const { return channels_; }
std::size_t       AudioFile::totalFrames() const { return totalFrames_; }

std::string AudioFile::formatString() const {
    // TODO: SF_INFO info{}; sf_command(file_, SFC_GET_FORMAT_INFO, &info, sizeof(info));
    //   build a string from info.name
    return "";
}

// TODO: implement readAll() and readFrames() (see header)

} // namespace spectral::io
