if(NOT STATICLIB)
    enable_testing()

    if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang" AND ASAN)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address -shared-libasan")
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")

    add_executable(taint_reg taint_reg.cpp)
    target_link_libraries(taint_reg triton)
    add_test(TaintRegister taint_reg)
    add_dependencies(check taint_reg)

    add_executable(info_reg info_reg.cpp)
    target_link_libraries(info_reg triton)
    add_test(InfoRegister info_reg)
    add_dependencies(check info_reg)

    add_executable(ir ir.cpp)
    target_link_libraries(ir triton)
    add_test(IR ir)
    add_dependencies(check ir)

    add_executable(simplification simplification.cpp)
    target_link_libraries(simplification triton)
    add_test(Simplification simplification)
    add_dependencies(check simplification)

    add_executable(constraint constraint.cpp)
    target_link_libraries(constraint triton)
    add_test(Constraint constraint)
    add_dependencies(check constraint)

    add_executable(ctest_api ctest_api.cpp)
    target_link_libraries(ctest_api triton)
    add_test(TestAPI ctest_api)
    add_dependencies(check ctest_api)
endif()
