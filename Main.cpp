#include "ConSkrybeInternals.h"
#include "VersionInfo.h"

extern "C"
{
	bool SKSEPlugin_Query(const SKSEInterface * skse, PluginInfo * info)
	{
		_MESSAGE("ConSkrybe Initializing...");

		info->infoVersion =	PluginInfo::kInfoVersion;
		info->name =		"ConSkrybe";
		info->version =		PACKED_SME_VERSION;

		g_pluginHandle = skse->GetPluginHandle();

		if(skse->isEditor)
			return false;
		else if(skse->runtimeVersion != RUNTIME_VERSION_1_9_32_0)
		{
			_MESSAGE("Unsupported runtime version %08X", skse->runtimeVersion);
			return false;
		}

		// supported runtime version
		return true;
	}

	bool SKSEPlugin_Load(const SKSEInterface * skse)
	{
		_MESSAGE("Skrybing, plotting, positing...\n\n");
		gLog.Indent();
		gLog.Indent();

		StartSkrybing();
		return true;
	}
};