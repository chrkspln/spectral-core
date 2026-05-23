#include "logger.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

namespace spectral::utils {

// TODO: implement Logger::init(level, logFilePath)
//   auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
//   consoleSink->set_pattern("[%H:%M:%S.%e] [%n] [%l] %v");
//   if (!logFilePath.empty()) {
//       auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(...);
//       spdlog::set_default_logger(make_shared<spdlog::logger>("spectral",
//           spdlog::sinks_init_list{consoleSink, fileSink}));
//   }
//   spdlog::set_level(level);

// TODO: implement Logger::get(category)
//   auto existing = spdlog::get(std::string(category));
//   if (existing) return existing;
//   return spdlog::stdout_color_mt(std::string(category));

// TODO: implement Logger::flush()

} // namespace spectral::utils
