#include "stdafx.h"
#include "ESP.h"



_ESP* _ESP::m_pInstance;
void __fastcall _ESP::Manu()
{
	VMProtectBegin(__FUNCTION__);
	auto& style = ImGui::GetStyle();
	if (!mMenu)
	{
		mMenu = new MenuItem;
		mMenu->DisplayName = CProcess.StringToUtf8(XORSTR("ESP"));
		mMenu->IsMenu = false;
		mMenu->Id = Menu->ItemMenu.size();
		Menu->ItemMenu.push_back(mMenu);
	}
	else
	{
		if (mMenu->IsMenu)
		{
			style.Colors[ImGuiCol_WindowBg] = ImColor(0,0,0);
			auto tmp= style.Colors[ImGuiCol_Text];
			style.Colors[ImGuiCol_Text] = ImColor(255,255,100);
			ImGui::Begin(mMenu->DisplayName.c_str(), &mMenu->IsMenu, ImVec2(200, 200), 0.70, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
			{
				ImGui::Text(CProcess.StringToUtf8(XORSTR("BOX:")).c_str());
				ImGui::Separator();
				{
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("���K")).c_str(), &b2DBox);
					ImGui::SameLine(0, 25);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("���")).c_str(), &bTeam);
					ImGui::SameLine(0, 35);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("���x")).c_str(), &bDistance);

					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("Ѫ��")).c_str(), &bHealth);
					ImGui::SameLine(0, 25);
					//ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("����")).c_str(), &bName);				
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("Ӣ��")).c_str(), &bHero);
					ImGui::SameLine(0, 35);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("����")).c_str(), &bBone);

				}
				ImGui::Separator();
				ImGui::Text(CProcess.StringToUtf8(XORSTR("��ʾ��Χ:")).c_str());
				{
					ImGui::PushItemWidth(179);
					ImGui::SliderInt(CProcess.StringToUtf8(XORSTR("M")).c_str(), &iPlayerShow, 0, 600);
					ImGui::PopItemWidth();
				}
				ImGui::Separator();
				ImGui::Text(CProcess.StringToUtf8(XORSTR("��ɫ��")).c_str());
				{
					ImGui::PushItemWidth(150);
					ImGui::ColorEdit3(CProcess.StringToUtf8(XORSTR("������ɫ")).c_str(), (float*)&cPlayer);
					ImGui::PopItemWidth();
					ImGui::PushItemWidth(150);
					ImGui::ColorEdit3(CProcess.StringToUtf8(XORSTR("�ɼ�������ɫ")).c_str(), (float*)&cTeam);
					ImGui::PopItemWidth();
				}
				ImGui::Separator();
				ImGui::Text(CProcess.StringToUtf8(XORSTR("FLΨһ����W�P")).c_str());
				ImGui::Text(CProcess.StringToUtf8(XORSTR("ApexFL.cccpan.com�ܴa6666")).c_str());
				ImGui::Separator();
			}ImGui::End();
			style.Colors[ImGuiCol_Text] = tmp;
		}
	}
	VMProtectEnd;
}

_ESP* _ESP::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new _ESP();

	return m_pInstance;
}