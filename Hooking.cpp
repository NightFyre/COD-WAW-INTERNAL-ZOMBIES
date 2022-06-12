#include "Hooking.hpp"
namespace CODWAW_SP {
	Hooking::Hooking()
	{
		MH_Initialize();
#if DEVELOPER
		g_Console->printdbg("Hooking::Initialized\n", g_Console->color.pink);
#endif
		return;
	}

	Hooking::~Hooking()
	{
		MH_RemoveHook(MH_ALL_HOOKS);
	}

	/// <summary>
	/// Initializing hook. Everything begins here
	/// - First we obtain information on our target process (Process ID, Window Name, Window Size & Location
	/// - Then we create a transparent window on top of the target process window
	/// </summary>
	void Hooking::Hook()
	{
		g_GameVariables->Initialize();
		g_D3D9Window->Start();
		MH_EnableHook(MH_ALL_HOOKS);
#if DEVELOPER
		g_Console->printdbg("Hooking::Hook Initialized\n", g_Console->color.pink);
#endif
		return;
	}

	/// <summary>
	/// 
	void Hooking::Unhook()
	{
		g_D3D9Window->Stop();
		MH_RemoveHook(MH_ALL_HOOKS);

#if DEVELOPER
		g_Console->DestroyConsole();
#endif

		return;
	}


	/// <summary>
	/// Patch Bytes
	/// </summary>
	/// <param name="dst">Address</param>
	/// <param name="src">Value</param>
	/// <param name="size">Size</param>
	void Hooking::Patch(BYTE* dst, BYTE* src, unsigned int size)
	{
		DWORD oldprotect;
		VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
		memcpy(dst, src, size);
		VirtualProtect(dst, size, oldprotect, &oldprotect);
	}

	/// <summary>
	/// Clear Bytes
	/// </summary>
	/// <param name="dst">Address</param>
	/// <param name="size">Size</param>
	void Hooking::Nop(BYTE* dst, unsigned int size)
	{
		DWORD oldprotect;
		VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
		memset(dst, 0x90, size);
		VirtualProtect(dst, size, oldprotect, &oldprotect);
	}


	/// <summary>
	/// 
	/// </summary>
	/// <param name="offset"></param>
	/// <returns></returns>
	uintptr_t Hooking::ResolveOffset(uintptr_t offset)
	{
		if (dwGameBase == NULL)
			dwGameBase = (uintptr_t)GetModuleHandle(NULL);

		uintptr_t Address = (dwGameBase + offset);
		return Address;
	}

	/// <summary>
	/// Resolves Address via Base Address & Offsets
	/// </summary>
	/// <param name="Ptr">BaseAddress</param>
	/// <param name="Offsets">Array of offsets</param>
	/// <returns>Address</returns>
	uintptr_t Hooking::ResolvePTRS(uintptr_t Ptr, std::vector<unsigned int> Offsets)
	{
		/// <USAGE EXAMPLE>
		/// uintptr_t PLAYER_OOBJECT = NULL;
		/// uintptr_t BASE_ADDR = 0x69420
		/// std::vector<unsigned int> ptr_Chain = { 0x69, 0x420, 0x666 };
		/// PLAYER_OBJECT = g_GameData->ResolverPTRS(BASE_ADDR, ptr_Chain);

		uintptr_t addr = (dwGameBase + Ptr);
		for (unsigned int i = 0; i < Offsets.size(); i++)
		{
			if (*(int*)addr == NULL) break;
			addr = *(uintptr_t*)addr;
			if (addr == NULL) break;
			addr += Offsets[i];
		}
		if (addr == NULL)
			return Ptr;
		return addr;
	}
}
