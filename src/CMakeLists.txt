add_library(spectral_core STATIC)

# all modules include relative to src/ root:  #include "utils/strong_types.hpp"
target_include_directories(spectral_core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(spectral_core PUBLIC cxx_std_23)

target_compile_options(spectral_core PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)

# PortAudio target name may be PortAudio or PortAudio::PortAudio depending on version
target_link_libraries(spectral_core
    PUBLIC
        spdlog::spdlog
        PortAudio
        SndFile::sndfile
)
# kissfft::kissfft-float will be added here in v0.2

add_subdirectory(utils)
add_subdirectory(io)
add_subdirectory(engine)
