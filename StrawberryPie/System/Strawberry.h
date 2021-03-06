#pragma once

#include <Common.h>

#include <Network/NetworkManager.h>

#include <System/Settings.h>
#include <System/Interface/MainMenu.h>
#include <System/Interface/Chat.h>
#include <System/Interface/FPSCounter.h>

#include <Entities/LocalPlayer.h>

NAMESPACE_BEGIN;

class Strawberry
{
public:
	HMODULE m_hInstance;
	//HWND m_hWnd = nullptr;
	uint8_t m_keyStates[256];

	NetworkManager m_network;
	Settings m_settings;

	LocalPlayer m_player;

	//TODO: Move these somewhere else
	MainMenu m_mainMenu;
	Chat m_chat;
	FPSCounter m_fpsCounter;
	UIText m_strVersion;

	int m_gameTime = 0;

	uint32_t m_pedRelGroup = 0;

public:
	Strawberry(HMODULE hInstance);
	~Strawberry();

	void Initialize();
	void Update(float dt);
	void Render();

	void OnConnected();
	void OnDisconnected();

	void OnKeyDown(uint32_t key);
	void OnKeyUp(uint32_t key);

	bool IsKeyDown(uint8_t key);
};

extern Strawberry* _pGame;

NAMESPACE_END;
