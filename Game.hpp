#pragma once
#include "helper.h"
#include "Console.hpp"

namespace CODWAW_SP {

	struct Offsets {
		//	BASIC
		int EntArrayPTR = 0x14E73C0;

		//	CVARS (these may change)
		int NOCLIP = 0x14EF2A4;
		int FOV = 0x1DB55D4;
		int GOD = 0x136C8A4;

		//	PATCHES
		int AMMO = 0x1E619;				//	7Bytes 89 84 8F FC 05 00 00    
		int RAPIDFIRE = 0x0;

		//	ESP
		int ScreenX = 0x004E8704;
		int ScreenY = 0x004E8708;
		int ViewMatrix = 0x004E870C;
	};

	class EntityObject
	{
	public:
		char pad_0000[4]; //0x0000
		int32_t Valid; //0x0004
		char pad_0008[16]; //0x0008
		Vector3 FeetPos; //0x0018
		char pad_0024[304]; //0x0024
		Vector3 HeadPos; //0x0154
		char pad_0160[104]; //0x0160
		int32_t Health; //0x01C8
		int32_t MaxHealth; //0x01CC
	}; //Size: 0x01D0

	class GameData
	{
	public:
		Offsets offsets{};
		EntityObject* EntObject{};

		//	CHEATS
		bool bINFINITEAMMO = FALSE;
		bool bINFINITEHEALTH = FALSE;
		bool bESP = FALSE;

		explicit GameData();
		~GameData() noexcept = default;
		GameData(GameData const&) = delete;
		GameData(GameData&&) = delete;
		GameData& operator=(GameData const&) = delete;
		GameData& operator=(GameData&&) = delete;

		uintptr_t ResolvePTRS(uintptr_t Ptr, std::vector<unsigned int> Offsets);
	};

	class GameVariables
	{
	public:
		//	Dx & ImGui
		int g_GamePid{};
		HANDLE g_GameHandle{};
		HWND g_GameWindow{};
		int g_GameWidth;
		int g_GameHeight;
		ImVec2 g_WindowSize{};
		LPCSTR g_GameTitle;
		LPCSTR g_ClassName;
		LPCSTR g_GamePath;

		//	MENU RELATED
		bool m_ShowMenu = FALSE;
		bool m_ShowConsole = FALSE;
		bool m_ShowHud{};
		bool m_ShowDemo{};

		explicit GameVariables();
		~GameVariables() noexcept = default;
		GameVariables(GameVariables const&) = delete;
		GameVariables(GameVariables&&) = delete;
		GameVariables& operator=(GameVariables const&) = delete;
		GameVariables& operator=(GameVariables) = delete;
	
		void Initialize();
	};

	inline std::unique_ptr<GameVariables> g_GameVariables;
	inline std::unique_ptr<GameData> g_GameData;
}