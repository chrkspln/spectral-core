set(CMAKE_POLICY_VERSION_MINIMUM "3.5")

include(FetchContent)

# ── spdlog ──────────────────────────────────────────────────────────────────
FetchContent_Declare(spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        v1.17.0
)

# ── PortAudio ────────────────────────────────────────────────────────────────
set(PA_BUILD_STATIC   ON  CACHE BOOL "" FORCE)
set(PA_BUILD_SHARED   OFF CACHE BOOL "" FORCE)
set(PA_ENABLE_DEBUG_OUTPUT OFF CACHE BOOL "" FORCE)
set(PA_DLL OFF CACHE BOOL "" FORCE)
set(PA_CMAKE_BUILD_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_Declare(portaudio
    GIT_REPOSITORY https://github.com/PortAudio/portaudio.git
    GIT_TAG        v19.7.0
)

# ── libsndfile ───────────────────────────────────────────────────────────────
set(BUILD_SHARED_LIBS   OFF CACHE BOOL "" FORCE)
set(BUILD_PROGRAMS      OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES      OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING       OFF CACHE BOOL "" FORCE)
FetchContent_Declare(libsndfile
    GIT_REPOSITORY https://github.com/libsndfile/libsndfile.git
    GIT_TAG        1.2.2
)

# ── Google Test ──────────────────────────────────────────────────────────────
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # required on MSVC
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.17.0
)

# ── KissFFT (v0.2 DSP) ──
# set(KISSFFT_STATIC ON  CACHE BOOL "" FORCE)
# set(KISSFFT_TEST   OFF CACHE BOOL "" FORCE)
# set(KISSFFT_TOOLS  OFF CACHE BOOL "" FORCE)
# FetchContent_Declare(kissfft
#     GIT_REPOSITORY https://github.com/mborgerding/kissfft.git
#     GIT_TAG        131.2.0
# )

# ── nlohmann/json (v0.3 config) ──────────────────────────────────────────────
# FetchContent_Declare(nlohmann_json
#     GIT_REPOSITORY https://github.com/nlohmann/json.git
#     GIT_TAG        v3.12.0
# )

FetchContent_MakeAvailable(spdlog portaudio libsndfile googletest)
# kissfft and nlohmann_json added to MakeAvailable when their modules land
