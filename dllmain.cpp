// dllmain.cpp : Defines the entry point for the DLL application.
#include "helper.h"
#include "Console.hpp"
#include "Game.hpp"
#include "D3D9Window.hpp"
#include "Hooking.hpp"
#include "Menu.hpp"

int COUNT = 0;
void BackgroundWorker()
{
    using namespace CODWAW_SP;
    while (g_Running) {
        if (COUNT >= 5000) {

            COUNT = NULL;
        }
        g_Menu->Loops();
        COUNT++;
        std::this_thread::sleep_for(1ms);
    }
    return;
}

DWORD WINAPI MainThread()
{
    using namespace CODWAW_SP;
    g_Console = std::make_unique<Console>();
    g_GameVariables = std::make_unique<GameVariables>();
    g_GameData = std::make_unique<GameData>();
    g_D3D9Window = std::make_unique<D3D9Window>();
    g_Menu = std::make_unique<Menu>();
    g_Hooks = std::make_unique<Hooking>();
    g_Hooks->Hook();

    g_Running = TRUE;
    std::thread UPDATE(BackgroundWorker);
    while (g_Running) {
        if (GetAsyncKeyState(VK_INSERT) & 1) g_GameVariables->m_ShowMenu = !g_GameVariables->m_ShowMenu;
    }

    UPDATE.join();
    FreeLibraryAndExitThread(g_hModule, EXIT_SUCCESS);
    return EXIT_SUCCESS;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    using namespace CODWAW_SP;
    g_hModule = hModule;

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(g_hModule);
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, g_hModule, NULL, NULL);
        break;
    case DLL_PROCESS_DETACH:
        g_Killswitch = TRUE;
        break;
    }
    return TRUE;
}

