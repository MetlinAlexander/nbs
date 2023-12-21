#pragma once

#include "public.h"

#include <cloud/blockstore/libs/kikimr/public.h>

#include <library/cpp/actors/core/actorid.h>

namespace NCloud::NBlockStore::NStorage {

////////////////////////////////////////////////////////////////////////////////

NActors::TActorId MakeUndeliveredHandlerServiceId();

NActors::IEventHandlePtr CreateRequestWithNondeliveryTracking(
    const NActors::TActorId& destination,
    NActors::IEventHandle& ev);

void ForwardRequestWithNondeliveryTracking(
    const NActors::TActorContext& ctx,
    const NActors::TActorId& destination,
    NActors::IEventHandle& ev);

}   // namespace NCloud::NBlockStore::NStorage
