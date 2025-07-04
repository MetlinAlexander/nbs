PROGRAM(nbsd-lightweight)

ALLOCATOR(TCMALLOC_TC)

SRCS(
    main.cpp
)

IF (BUILD_TYPE != "PROFILE" AND BUILD_TYPE != "DEBUG")
    SPLIT_DWARF()
ENDIF()

IF (SANITIZER_TYPE)
    NO_SPLIT_DWARF()
ENDIF()

PEERDIR(
    cloud/blockstore/libs/daemon/local
    cloud/blockstore/libs/service

    cloud/storage/core/libs/daemon
)

CHECK_DEPENDENT_DIRS(ALLOW_ONLY PEERDIRS
    build/internal/platform
    build/platform
    certs
    cloud/blockstore
    cloud/contrib
    cloud/storage
    contrib/libs
    contrib/restricted
    library/cpp
    contrib/ydb/core
    contrib/ydb/library
    contrib/ydb/public
    logbroker
    tools/enum_parser
    util
    yql/essentials
)

END()
