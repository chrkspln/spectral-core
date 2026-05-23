add_executable(spectral_app main.cpp)

target_link_libraries(spectral_app PRIVATE spectral_core)
target_compile_features(spectral_app PRIVATE cxx_std_23)

# spectral_app must NOT link to ftxui or any UI lib here — that's spectral-cli's job.
# This binary is the v0.1 proof-of-life CLI only.
