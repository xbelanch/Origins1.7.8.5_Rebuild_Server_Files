
class RscDisplayMultiplayerSetup: RscStandardDisplay
{
	class controlsBackground
	{
		// удаляем ненужные бэкграунды
		delete SidesBack;
		delete SidesBorder;
		delete ValueRolesBack;
		delete ValueRolesBorder;
		class TextBack: RscPicture
		{
			x = "SafeZoneX";
			y = "SafeZoneY";
			w = "SafeZoneW";
			h = "SafeZoneH";
			colorbackground[] = {0, 0, 0, 1};
			text = "\origins_pack\ui\fon_co.paa";
		};
		delete MP_roles_TitleBorder;
		class MP_roles_TitleBorder_Ori : RscPicture {
			colorbackground[] = {0, 0, 0, 0};
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(02/100)	* SafeZoneH + SafeZoneY";
			w = "(96/100)	* SafeZoneW";
			h = "(06/100)	* SafeZoneH";
			text = "\origins_pack\ui\mp_topfon.paa";
		};
		class Origins_Slogo : RscPictureKeepAspect {
			x = "(0.7/100)	* SafeZoneW + SafeZoneX";
			y = "(0.1/100)	* SafeZoneH + SafeZoneY";
			w = "(10/100)	* SafeZoneW";
			h = "(7.5/100)	* SafeZoneH";
			text = "z\addons\dayz_code\gui\Origins_logo_ca.paa";
		};
		delete TextBorder;
		delete TextBack1;

		class ValuePoolBack: RscText
		// расширяем бэкграунд для Pool
		{
			x = "(20/100)	* SafeZoneW + SafeZoneX";
			y = "(12.5/100)	* SafeZoneH + SafeZoneY";
			w = "(78/100)	* SafeZoneW";
			h = "(76/100)	* SafeZoneH";
			//colorBackground[] = {0.1961,0.1451,0.0941,0.42};
			colorBackground[] = {0.42352,0.42352,0.42352, 0.43};
		};
		class ValuePoolBorder: RscText
		// расширяем для Pool
		{
			style = 64;
			colorText[] = {0,0,0,1};
			x = "(20/100)	* SafeZoneW + SafeZoneX";
			y = "(12.5/100)	* SafeZoneH + SafeZoneY";
			w = "(78/100)	* SafeZoneW";
			h = "(76/100)	* SafeZoneH";
		};
	};
	class controls
	{
		// удаляем ненужные кнопки
		delete CA_B_East;
		delete CA_B_Guerrila;
		delete CA_B_Civilian;
		delete CA_ValueRoles;
		delete CA_B_DSinterface;
		
		delete TextMission;
		delete ValueMission;
		delete TextIsland;
		delete ValueIsland;
		delete CA_TextDescription;
		delete CA_ValueDescription;
		//delete TextRoles;
		
		class TextSide : RscText {
			y = "(9.5/100)	* SafeZoneH + SafeZoneY";
		};
		
		class TextPool: RscText
		{
			style = 0;
			x = "(20/100)	* SafeZoneW + SafeZoneX";
			y = "(9.5/100)	* SafeZoneH + SafeZoneY";
		};
		
		class CA_MP_roles_Title : CA_Title {
			idc = 1001;
			style = 2;
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(02/100)	* SafeZoneH + SafeZoneY";
			w = "(96/100)	* SafeZoneW";
			h = "(06/100)	* SafeZoneH";
			font = "TahomaB";
			sizeEx = 0.05906536;
			colorText[] = {0, 0, 0, 0.9};
			colorBackground[] = {49/255, 36/255, 25/255, 0/255};
			text = $STR_DISP_MPSETUP_TITLE;
		};
		class OriginsSurv : RscPictureKeepAspect {
			w = "(12.7/100)	* SafeZoneW";
			h = "(12.7/100)	* SafeZoneH";
			x = "(4.15/100)	* SafeZoneW + SafeZoneX";
			y = "(15/100)	* SafeZoneH + SafeZoneY";
			text = "\origins_pack\ui\flag_origins_ca.paa";
		};
		delete CA_B_West;
		class CA_B_WestOri: RscActiveText
		// меняем флаг на кнопке на нейтральный
		{
			x = "(4.15/100)	* SafeZoneW + SafeZoneX";
			y = "(15/100)	* SafeZoneH + SafeZoneY";
			w = "(12.7/100)	* SafeZoneW";
			h = "(8/100)	* SafeZoneH";
			style = 0x02 + 0x100 + 0x40;
			type = 11;
			colorActive[] = {1, 1, 1, 1};
			colorDisabled[] = {1, 1, 1, 0.15};
			colorShade[] = {1, 1, 1, 1};
			colorText[] = {1, 1, 1, 1};
			pictureWidth = 1;
			pictureHeight = 1;
			textHeight = 0.35;
			sideDisabled = "origins_pack\ui\flag_origins_pustoj_ca.paa";
			sideToggle = "origins_pack\ui\flag_origins_pustoj_ca.paa";
			idc = 104;
			color[] = {1, 1, 1, 1};
			text = "SURVIVORS";
			picture = "\origins_pack\ui\flag_origins_pustoj_ca.paa";
		};
		
		class CA_ValuePool: RscIGUIListBox
		// расширяем Pool
		{
			x = "(20/100)	* SafeZoneW + SafeZoneX";
			y = "(12.5/100)	* SafeZoneH + SafeZoneY";
			w = "(78/100)	* SafeZoneW";
			h = "(72/100)	* SafeZoneH";
			rows = 25;
			canDrag = 0;
		};
		
		class CA_ButtonContinue : RscShortcutButton {
			idc = 1;
			default = 1;
			shortcuts[] = {0x00050000 + 0, 28, 57, 156};
			x = "(83/100)	* SafeZoneW + SafeZoneX";
			y = "(93/100)	* SafeZoneH + SafeZoneY";
			text = $STR_DISP_OK;
			font = "TahomaB";
			period = 0;
			periodFocus = 0;
			periodOver = 0;
			animTextureNormal 	= "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureDisabled = "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureOver 	= "\origins_pack\ui\esc_knopka_focus_ca.paa";
			animTextureFocused 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			animTexturePressed 	= "\origins_pack\ui\esc_knopka_down_ca.paa";
			animTextureDefault 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			h = 0.07;
			class TextPos {
				left = 0.07;
				top = 0.007;
				right = 0.005;
				bottom = 0.005;
			};
			class HitZone {
				left = 0.004;
				top = 0.004;
				right = 0.004;
				bottom = 0.004;
			};
		};
		
		class CA_ButtonCancel : RscShortcutButton {
			idc = 2;
			default = 0;
			shortcuts[] = {0x00050000 + 1};
			x = "(68/100)	* SafeZoneW + SafeZoneX";
			y = "(93/100)	* SafeZoneH + SafeZoneY";
			w = 0.203825;
			text = $STR_DISP_BACK;
			font = "TahomaB";
			period = 0;
			periodFocus = 0;
			periodOver = 0;
			animTextureNormal 	= "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureDisabled = "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureOver 	= "\origins_pack\ui\esc_knopka_focus_ca.paa";
			animTextureFocused 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			animTexturePressed 	= "\origins_pack\ui\esc_knopka_down_ca.paa";
			animTextureDefault 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			h = 0.07;
			class TextPos {
				left = 0.05;
				top = 0.007;
				right = 0.005;
				bottom = 0.005;
			};
			class HitZone {
				left = 0.004;
				top = 0.004;
				right = 0.004;
				bottom = 0.004;
			};
		};

	};
};
