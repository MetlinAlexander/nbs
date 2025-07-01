#include "server.h"
#include "vhost.h"

#include <cloud/blockstore/libs/diagnostics/critical_events.h>
#include <cloud/blockstore/libs/diagnostics/server_stats_test.h>
#include <cloud/blockstore/libs/diagnostics/volume_stats_test.h>
#include <cloud/blockstore/libs/service/device_handler.h>
#include <cloud/blockstore/libs/service/storage_test.h>

#include <cloud/storage/core/libs/common/error.h>
#include <cloud/storage/core/libs/common/sglist_test.h>
#include <cloud/storage/core/libs/diagnostics/logging.h>

#include <library/cpp/testing/unittest/registar.h>

#include <util/datetime/base.h>
#include <util/folder/path.h>
#include <util/generic/guid.h>
#include <util/generic/scope.h>
#include <util/system/tempfile.h>
#include <util/thread/factory.h>
#include <util/thread/lfqueue.h>

namespace NCloud::NBlockStore::NVhost {

using namespace NThreading;

////////////////////////////////////////////////////////////////////////////////

Y_UNIT_TEST_SUITE(TVhostTest)
{
    Y_UNIT_TEST(ShouldDeleteLoggerCorrectly)
    {
        auto logging = CreateLoggingService("console");
        InitVhostLog(logging);

        auto vhostQueueFactory = CreateVhostQueueFactory();

        auto vhostDevice = vhostQueueFactory->CreateQueue()->CreateDevice(
            CreateGuidAsString() + ".sock",
            "TestDevice",
            DefaultBlockSize,
            42,
            1,
            false,
            nullptr,
            TVhostCallbacks());
    }
}

}   // namespace NCloud::NBlockStore::NVhost
