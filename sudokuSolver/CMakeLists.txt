INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_BINARY_DIR}
)

INSTALL(
    DIRECTORY src
    DESTINATION include/sudokuSolver
    COMPONENT headers
    FILES_MATCHING PATTERN "*.hpp"
)

INSTALL(
    FILES base.hpp io.hpp solver.hpp
    DESTINATION include/sudokuSolver
    COMPONENT headers
)