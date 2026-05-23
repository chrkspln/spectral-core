add_executable(spectral_tests
    test_ring_buffer.cpp
    test_strong_types.cpp
    test_transport.cpp
)

target_link_libraries(spectral_tests PRIVATE
    spectral_core
    GTest::gtest_main
    GTest::gmock
)

target_compile_features(spectral_tests PRIVATE cxx_std_23)

include(GoogleTest)
gtest_discover_tests(spectral_tests)
