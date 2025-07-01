UNITTEST_FOR(cloud/blockstore/libs/vhost)

INCLUDE(${ARCADIA_ROOT}/cloud/storage/core/tests/recipes/small.inc)

SRCS(
    vhost_ut.cpp
    server_ut.cpp
)

END()
