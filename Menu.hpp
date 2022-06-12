#pragma once
#include "helper.h"
#include "Console.hpp"
#include "Game.hpp"
#include "D3D9Window.hpp"
#include "Hooking.hpp"

namespace CODWAW_SP {

	class Menu
	{
	public:
		ImColor dbg_RAINBOW{};				//	RAINBOW THEME COLORS
		bool dbg_RAINBOW_THEME = FALSE;		//	RAINBOW THEME BOOLEAN

		//	CROSSHAIR OPTIONS
		bool m_dbgCrosshair = FALSE;	//	Crosshair Flag
		bool m_RGB_CROSSHAIR = FALSE;	//	RGB Crosshair Flag
		float	dbg_crosshair_radius{};
		int		dbg_crosshair_segments{};
		float	dbg_crosshair_thickness{};
		float	dbg_crosshair_a = 1.0;

		//	Draw Pos
		int m_dbg_drawpos = 0;

		Menu()  noexcept = default;
		~Menu() noexcept = default;
		Menu(Menu const&) = delete;
		Menu(Menu&&) = delete;
		Menu& operator=(Menu const&) = delete;
		Menu& operator=(Menu&&) = delete;

		//	FORWARD DECLARE FUNCTIONS
		void Draw();
		void MainMenu();
		void HUD(bool* p_open);
		void Loops();

		void ESP(byte Pos);
	};
	inline std::unique_ptr<Menu> g_Menu;
}