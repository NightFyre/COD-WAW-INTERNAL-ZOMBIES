#pragma once
#include "helper.h"
#include "Console.hpp"
#include "Game.hpp"
#include "D3D9Window.hpp"

namespace CODWAW_SP {
	
	
	class Hooking
	{
	public:

		explicit Hooking();
		~Hooking() noexcept;
		Hooking(Hooking const&) = delete;
		Hooking(Hooking&&) = delete;
		Hooking& operator=(Hooking const&) = delete;
		Hooking& operator=(Hooking&&) = delete;

		void Hook();
		void Unhook();

		void Nop(BYTE* dst, unsigned int size);
		void Patch(BYTE* dst, BYTE* src, unsigned int size);
		uintptr_t ResolvePTRS(uintptr_t Ptr, std::vector<unsigned int> Offsets);
		uintptr_t ResolveOffset(uintptr_t offset);
	};
	inline std::unique_ptr<Hooking> g_Hooks;
}