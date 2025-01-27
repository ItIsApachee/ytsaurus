#pragma once

#include <yt/yt/server/lib/job_proxy/public.h>

#include <yt/yt/ytlib/exec_node/public.h>

#include <yt/yt/core/misc/error_code.h>

#include <yt/yt/client/job_tracker_client/public.h>

#include <library/cpp/yt/memory/ref_counted.h>

#include <library/cpp/yt/containers/enum_indexed_array.h>

namespace NYT::NExecNode {

////////////////////////////////////////////////////////////////////////////////

using NJobTrackerClient::TJobId;
using NJobTrackerClient::TOperationId;
using NJobTrackerClient::EJobType;
using NJobTrackerClient::EJobState;

////////////////////////////////////////////////////////////////////////////////

DEFINE_ENUM(ESandboxKind,
    (User)
    (Udf)
    (Home)
    (Pipes)
    (Tmp)
    (Cores)
    (Logs)
);

DEFINE_ENUM(EJobProxyLoggingMode,
    (Simple)
    (PerJobDirectory)
);

DEFINE_ENUM(EExecNodeThrottlerKind,
    //! Controls incoming bandwidth used by Artifact Cache downloads.
    (ArtifactCacheIn)
    //! Controls incoming bandwidth consumed by local jobs.
    (JobIn)
    //! Controls outcoming bandwidth consumed by local jobs.
    (JobOut)
);

DEFINE_ENUM(EThrottlerTrafficType,
    (Bandwidth)
    (Rps)
);

////////////////////////////////////////////////////////////////////////////////

extern const TEnumIndexedArray<ESandboxKind, TString> SandboxDirectoryNames;
extern const TString EmptyCpuSet;

////////////////////////////////////////////////////////////////////////////////

DECLARE_REFCOUNTED_CLASS(TSlotLocationConfig)
DECLARE_REFCOUNTED_CLASS(TNumaNodeConfig)
DECLARE_REFCOUNTED_CLASS(TSlotManagerTestingConfig)
DECLARE_REFCOUNTED_CLASS(TSlotManagerConfig)
DECLARE_REFCOUNTED_CLASS(TSlotManagerDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TChunkCacheDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TVolumeManagerDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TUserJobSensor)
DECLARE_REFCOUNTED_CLASS(TUserJobStatisticSensor)
DECLARE_REFCOUNTED_CLASS(TUserJobMonitoringDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TControllerAgentConnectorDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TMasterConnectorDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TSchedulerConnectorDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TGpuManagerTestingConfig)
DECLARE_REFCOUNTED_CLASS(TGpuManagerConfig)
DECLARE_REFCOUNTED_CLASS(TGpuManagerDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TShellCommandConfig)
DECLARE_REFCOUNTED_CLASS(TTestingConfig)
DECLARE_REFCOUNTED_CLASS(TJobCommonConfig)
DECLARE_REFCOUNTED_CLASS(TAllocationConfig)
DECLARE_REFCOUNTED_CLASS(TJobControllerDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TJobInputCacheDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TNbdConfig)
DECLARE_REFCOUNTED_CLASS(TNbdClientConfig)
DECLARE_REFCOUNTED_CLASS(TJobProxyLoggingConfig)
DECLARE_REFCOUNTED_CLASS(TJobProxyConfig)
DECLARE_REFCOUNTED_CLASS(TLogDumpConfig)
DECLARE_REFCOUNTED_CLASS(TJobProxyLogManagerConfig)
DECLARE_REFCOUNTED_CLASS(TJobProxyLogManagerDynamicConfig)
DECLARE_REFCOUNTED_CLASS(TExecNodeConfig)
DECLARE_REFCOUNTED_CLASS(TExecNodeDynamicConfig)

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NExecNode
