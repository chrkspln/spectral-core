#pragma once

#include <spdlog/spdlog.h>
#include <memory>
#include <string_view>

namespace spectral::utils {

// Thin wrapper around spdlog.
// Provides per-category loggers ("io", "engine", "dsp") for filtered log output.
// All categories share one sink — set level once in init(), affects all.
//
// Never call from the AUDIO callback thread — spdlog is NOT RT-safe (heap alloc internally).
class Logger {
public:
    // TODO: static init(spdlog::level::level_enum level, std::string_view logFilePath = "")
    //   create a stdout sink + optional rotating file sink
    //   set global pattern: "[%H:%M:%S.%e] [%n] [%l] %v"
    //   call once from main() before any other spectral code

    // TODO: static get(std::string_view category) -> std::shared_ptr<spdlog::logger>
    //   spdlog::get(category) — returns existing or creates new logger with shared sink
    //   usage: Logger::get("io")->info("AudioDevice opened on {}", deviceName);

    // TODO: static flush()
    //   spdlog::apply_all([](auto l){ l->flush(); })
    //   call on shutdown or in a signal handler (SIGINT) to flush buffered entries

    Logger() = delete;  // static-only class, no instances
};

} // namespace spectral::utils
