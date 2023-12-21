#pragma once

#include <cloud/blockstore/libs/kikimr/public.h>
#include <cloud/blockstore/libs/storage/core/public.h>

#include <library/cpp/actors/core/actorid.h>

namespace NCloud::NBlockStore::NStorage {

////////////////////////////////////////////////////////////////////////////////

NActors::IActorPtr CreateTestTablet(
    const NActors::TActorId& owner,
    NKikimr::TTabletStorageInfoPtr storage);

}   // namespace NCloud::NBlockStore::NStorage
