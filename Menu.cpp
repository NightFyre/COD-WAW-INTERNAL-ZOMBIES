#include "Menu.hpp"
float vMatrix[16];


namespace CODWAW_SP {
	namespace STYLES {
		void InitStyle()
		{
			ImGuiStyle& style = ImGui::GetStyle();
			ImVec4* colors = ImGui::GetStyle().Colors;

			//	STYLE PROPERTIES
			style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
			style.FrameRounding = 1.0f;
			style.GrabRounding = style.FrameRounding; // Make GrabRounding always the same value as FrameRounding
			style.WindowRounding = 4.0f;
			style.FrameBorderSize = 0.75f;
			style.WindowPadding = ImVec2(8.00f, 8.00f);
			style.FramePadding = ImVec2(5.00f, 2.00f);
			style.CellPadding = ImVec2(6.00f, 6.00f);
			style.ItemSpacing = ImVec2(6.00f, 6.00f);
			style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
			style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
			style.IndentSpacing = 25;
			style.ScrollbarSize = 15;
			style.GrabMinSize = 10;
			style.WindowBorderSize = 1;
			style.ChildBorderSize = 1;
			style.PopupBorderSize = 1;
			style.TabBorderSize = 1;
			style.ChildRounding = 4;
			style.PopupRounding = 4;
			style.ScrollbarRounding = 9;
			style.LogSliderDeadzone = 4;
			style.TabRounding = 0;
			colors[ImGuiCol_Text] = ImVec4(0.75f, 0.75f, 0.29f, 1.00f);
			colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 0.28f);
			colors[ImGuiCol_WindowBg] = ImVec4(0.059f, 0.059f, 0.059f, 0.80f);
			colors[ImGuiCol_ChildBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.58f);
			colors[ImGuiCol_PopupBg] = ImVec4(ImColor(20, 20, 20, 240));
			colors[ImGuiCol_Border] = ImVec4(1.00f, 1.00f, 1.00f, 0.25f);
			colors[ImGuiCol_BorderShadow] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
			colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.23f, 0.27f, 1.0f);
			colors[ImGuiCol_FrameBgHovered] = ImVec4(0.27f, 0.00f, 0.63f, 0.78f);
			colors[ImGuiCol_FrameBgActive] = ImVec4(0.27f, 0.00f, 0.63f, 1.00f);
			colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.47f);
			colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
			colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.23f, 0.00f, 0.53f, 1.00f);
			colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.27f, 0.00f, 0.63f, 0.78f);
			colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.27f, 0.00f, 0.63f, 1.00f);
			colors[ImGuiCol_CheckMark] = ImVec4(0.22f, 0.62f, 0.74f, 1.00f);
			colors[ImGuiCol_SliderGrab] = ImVec4(0.27f, 0.30f, 0.37f, 1.00f);
			colors[ImGuiCol_SliderGrabActive] = ImVec4(0.39f, 0.00f, 0.90f, 1.00f);
			colors[ImGuiCol_Button] = ImVec4(0.35f, 0.16f, 0.48f, 0.40f);
			colors[ImGuiCol_ButtonHovered] = ImVec4(0.27f, 0.00f, 0.63f, 1.00f);
			colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.00f, 0.90f, 1.00f);
			colors[ImGuiCol_Header] = ImVec4(0.27f, 0.00f, 0.63f, 0.76f);
			colors[ImGuiCol_HeaderHovered] = ImVec4(0.27f, 0.00f, 0.63f, 0.86f);
			colors[ImGuiCol_HeaderActive] = ImVec4(0.39f, 0.00f, 0.90f, 1.00f);
			colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
			colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.27f, 0.00f, 0.63f, 0.78f);
			colors[ImGuiCol_ResizeGripActive] = ImVec4(0.27f, 0.00f, 0.63f, 1.00f);
			colors[ImGuiCol_Tab] = ImVec4(0.20f, 0.22f, 0.27f, 0.40f);
			colors[ImGuiCol_TabHovered] = ImVec4(0.39f, 0.00f, 0.90f, 1.00f);
			colors[ImGuiCol_TabActive] = ImVec4(0.27f, 0.00f, 0.63f, 1.00f);
			colors[ImGuiCol_TabUnfocused] = ImVec4(0.20f, 0.22f, 0.27f, 0.40f);
			colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.20f, 0.22f, 0.27f, 0.70f);
			colors[ImGuiCol_PlotLines] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
			colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.27f, 0.00f, 0.63f, 1.00f);
			colors[ImGuiCol_PlotHistogram] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
			colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.27f, 0.00f, 0.63f, 1.00f);
			colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
			colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
			colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
			colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
			colors[ImGuiCol_TextSelectedBg] = ImVec4(0.27f, 0.00f, 0.63f, 0.43f);
			colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
			colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
			colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
			colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

			//	COLORS
			if (g_Menu->dbg_RAINBOW_THEME) {
				colors[ImGuiCol_Separator] = ImVec4(g_Menu->dbg_RAINBOW);
				colors[ImGuiCol_TitleBg] = ImVec4(0, 0, 0, 1.0f);
				colors[ImGuiCol_TitleBgActive] = ImVec4(0, 0, 0, 1.0f);
				colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0, 0, 0, 1.0f);
			}
			else {
				colors[ImGuiCol_TitleBg] = ImVec4(0.23f, 0.00f, 0.53f, 1.00f);
				colors[ImGuiCol_TitleBgActive] = ImVec4(0.39f, 0.00f, 0.90f, 1.00f);
				colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
				colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
			}
		}
	}

	namespace TABS {
		void MAIN()
		{
			ImGui::Text("PLAYER");
			ImGui::Spacing();
			if (ImGui::Checkbox("INFINITE HEALTH", &g_GameData->bINFINITEHEALTH))
				*(bool*)g_Hooks->ResolveOffset(g_GameData->offsets.GOD) = g_GameData->bINFINITEHEALTH;

			ImGui::SliderFloat("FOV", &*(float*)g_Hooks->ResolveOffset(g_GameData->offsets.FOV), 65, 120, "%.0f");

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			ImGui::Text("WEAPON");
			ImGui::Spacing();
			if (ImGui::Checkbox("INFINITE AMMO", &g_GameData->bINFINITEAMMO)) {
				switch (g_GameData->bINFINITEAMMO) {
				case (TRUE):
					g_Hooks->Nop((BYTE*)g_Hooks->ResolveOffset(g_GameData->offsets.AMMO), 7);
					break;
				case (FALSE):
					g_Hooks->Patch((BYTE*)g_Hooks->ResolveOffset(g_GameData->offsets.AMMO), (BYTE*)"\x89\x94\x8F\xFC\x05\x00\x00", 7);
					break;
				}
			}

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			ImGui::Text("ENVIRONMENT");
			ImGui::Spacing();

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			ImGui::Text("VISUALS");
			ImGui::Spacing();
			ImGui::Checkbox("ESP", &g_GameData->bESP);
			if (g_GameData->bESP) {
				ImGui::SameLine();
				ImGui::SetNextItemWidth(100);
				ImGui::Combo("POSITION", &g_Menu->m_dbg_drawpos, "Heaven\0Hell\0Corner\0Center\0");
			}
			ImGui::Checkbox("CROSSHAIR", &g_Menu->m_dbgCrosshair);
			if (g_Menu->m_dbgCrosshair)
			{
				//  SIZE
				ImGui::Text("CROSSHAIR SIZE:      ");
				ImGui::SameLine();
				ImGui::SetNextItemWidth(75);
				ImGui::SliderFloat("##SIZE ", &g_Menu->dbg_crosshair_radius, 1, 100, "%.2f");
				ImGui::Spacing();

				ImGui::Text("CROSSHAIR SEGMENTS:  ");
				ImGui::SameLine();
				ImGui::SetNextItemWidth(75);
				ImGui::SliderInt("##SIZE2 ", &g_Menu->dbg_crosshair_segments, 0, 12, "%.2f");
				ImGui::Spacing();

				ImGui::Text("CROSSHAIR THICKNESS: ");
				ImGui::SameLine();
				ImGui::SetNextItemWidth(75);
				ImGui::SliderFloat("##SIZE3 ", &g_Menu->dbg_crosshair_thickness, 0, 10, "%.2f");
				ImGui::Separator();
			}

		}

		void ABOUT()
		{
			ImGui::Text("[DX9] ImGui INTERNAL MENU (PREVIEW)");
			ImGui::Text("BUILD VERSION: v1.0");
			ImGui::Text("BUILD DATE: 5/30/2022");
			ImGui::Checkbox("RGB MODE", &g_Menu->dbg_RAINBOW_THEME);
			ImGui::Checkbox("SHOW IMGUI DEMO", &g_GameVariables->m_ShowDemo);
			if (ImGui::Checkbox("SHOW DEBUG CONSOLE", &g_GameVariables->m_ShowConsole)) {
				switch (g_GameVariables->m_ShowConsole) {
				case(TRUE):
					ShowWindow(g_Console->g_hWnd, SW_SHOW);
					break;
				case(FALSE):
					ShowWindow(g_Console->g_hWnd, SW_HIDE);
					break;
				}
			}

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			if (ImGui::Button("UNHOOK DLL", ImVec2(ImGui::GetWindowContentRegionWidth() - 3, 20))) g_Killswitch = TRUE;
		}
	}

	void Menu::Draw()
	{
		if (g_GameVariables->m_ShowMenu)
			MainMenu();

		if (g_GameVariables->m_ShowHud)
			HUD(&g_GameVariables->m_ShowHud);

		if (g_GameVariables->m_ShowDemo)
			ImGui::ShowDemoWindow();

		if (g_GameData->bESP)
			ESP(m_dbg_drawpos);

		if (m_dbgCrosshair)
			ImGui::GetBackgroundDrawList()->AddCircle(ImGui::GetMainViewport()->GetCenter(), g_Menu->dbg_crosshair_radius, ImColor(255, 0, 0, 255), g_Menu->dbg_crosshair_segments, g_Menu->dbg_crosshair_thickness);
	}

	void Menu::MainMenu()
	{
		STYLES::InitStyle();
		if (dbg_RAINBOW_THEME) {
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(g_Menu->dbg_RAINBOW));
			ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(g_Menu->dbg_RAINBOW));
			ImGui::PushStyleColor(ImGuiCol_BorderShadow, ImVec4(g_Menu->dbg_RAINBOW));
		}
		if (!ImGui::Begin("CoD::WaW Zombies", &g_GameVariables->m_ShowMenu, 96))
		{
			ImGui::End();
			return;
		}
		if (dbg_RAINBOW_THEME) {
			ImGui::PopStyleColor();
			ImGui::PopStyleColor();
			ImGui::PopStyleColor();
		}

		if (ImGui::BeginTabBar("##tabs", ImGuiTabBarFlags_None))
		{
			if (ImGui::BeginTabItem("MAIN"))
			{
				TABS::MAIN();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("ABOUT"))
			{
				TABS::ABOUT();
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		ImGui::End();
	}
	
	void Menu::HUD(bool* p_open)
	{
		//	Here you can draw a secondary window to show the user what menu items they have active
		// This makes it easier on the user , include a method to show and hide the HUD

	}
	
	void Menu::Loops()
	{
		///	Code inside this function body will execute every 1ms
		// Best used for constant writes and for anything that you need written while the menu is not shown
		//	NO DRAWING INSIDE THE LOOP

		if (g_GameData->bINFINITEHEALTH) {

		}

		if (g_GameData->bINFINITEAMMO) {
			
		}
	}

	void Menu::ESP(byte Pos)
	{
		/// <summary>
		/// Establish Colors
		ImColor cLines{};
		ImColor cText = { 255, 255, 255, 255 };
		if (dbg_RAINBOW_THEME)
			cLines = dbg_RAINBOW;
		else
			cLines = { 255, 0, 0, 255 };

		int dist = 0x88;
		float X = *(float*)g_Hooks->ResolveOffset(g_GameData->offsets.ScreenX);
		float Y = *(float*)g_Hooks->ResolveOffset(g_GameData->offsets.ScreenY);
		Vector2 pos = { ImGui::GetMainViewport()->GetCenter().x, ImGui::GetMainViewport()->GetCenter().y };

		/// <summary>
		/// Establish Position to draw from
		ImVec2 drawPosition{};
		switch (Pos) {

			//	Heaven
		case(0):
			drawPosition = { pos.x, 0 };
			break;

			//	Hell
		case(1):
			drawPosition = { pos.x, Y };
			break;

			// Corner
		case(2):
			drawPosition = { 0, 0 };
			break;

			// Center
		case(3):
			drawPosition = { pos.x, pos.y };
			break;
		}
		uintptr_t ViewMatrix = g_Hooks->ResolveOffset(g_GameData->offsets.ViewMatrix);
		memcpy(&vMatrix, (BYTE*)ViewMatrix, sizeof(vMatrix));
		for (int i = 0; i < 40; i++) {
			if (i == NULL) continue;
			//	Get Entity
			g_GameData->EntObject = (EntityObject*)*(uintptr_t*)g_Hooks->ResolveOffset(g_GameData->offsets.EntArrayPTR + i * dist);
			if (g_GameData->EntObject == NULL)
				continue;

			//	Get Health
			if (g_GameData->EntObject->Health <= NULL)
				continue;

			//	Get Validity
			if (g_GameData->EntObject->Valid != 16)
				continue;
			std::string HP = std::to_string(g_GameData->EntObject->Health);

			Vector2 screen;
			if (!g_D3D9Window->WorldToScreen(g_GameData->EntObject->FeetPos, screen, vMatrix, X, Y))
				continue;
			
			Vector2 head;
			if (!g_D3D9Window->WorldToScreen(g_GameData->EntObject->HeadPos, head, vMatrix, X, Y))
				continue;

			float vhead = head.y - screen.y;//These 3 lines define our head height
			float width = vhead / 2;
			float center = width / -2;

			ImGui::GetBackgroundDrawList()->AddLine(drawPosition, ImVec2(screen.x, screen.y), cLines, 1);
			ImGui::GetBackgroundDrawList()->AddText(ImVec2(screen.x, screen.y), cText, HP.c_str());
			ImGui::GetBackgroundDrawList()->AddRect(ImVec2(screen.x + center, screen.y), ImVec2(screen.x - center, head.y), cLines);

		}
	}
}
