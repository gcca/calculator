cmake_minimum_required(VERSION 3.11)

if (NOT ARITHMETIC_ROOT)
	include(ExternalProject)

	ExternalProject_Add(external-arithmetic
		CMAKE_ARGS
			-DCMAKE_INSTALL_PREFIX=installation
		GIT_REPOSITORY git@github.com:gcca/arithmetic.git
		UPDATE_COMMAND ""
	)

	ExternalProject_Get_property(external-arithmetic BINARY_DIR)
	set(ARITHMETIC_ROOT ${BINARY_DIR}/installation)

	file(MAKE_DIRECTORY ${ARITHMETIC_ROOT}/include)
	file(MAKE_DIRECTORY ${ARITHMETIC_ROOT}/lib)
endif()

add_library(Math::Arithmetic INTERFACE IMPORTED)
add_dependencies(Math::Arithmetic external-arithmetic)
target_include_directories(Math::Arithmetic
	INTERFACE ${ARITHMETIC_ROOT}/include)
target_link_libraries(Math::Arithmetic
	INTERFACE ${ARITHMETIC_ROOT}/lib/libarithmetic.a)

add_executable(calculator calculator.cc)
target_link_libraries(calculator Math::Arithmetic)
