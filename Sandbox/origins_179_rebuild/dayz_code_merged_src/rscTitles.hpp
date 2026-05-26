class RscPicture;
class RscButton;
class CA_IGUI_Title;
class RscText;
class RscControlsGroup;
class RscLineBreak;
class RscIGUIListNBox;
class RscActiveText;
class RscDisplayLoadMission;
class RscShortcutButton;
class CA_Title;
class RscIGUIListBox;
class RscEdit;
class RscCombo;
class RscXListBox;
class RscPictureKeepAspect;
class RscStandardDisplay;
class RscProgress;
class RscProgressNotFreeze;
class RscButtonTextOnly;
class RscShortcutButtonMain;
class RscGearShortcutButton;
class RscIGUIShortcutButton;

class RscMsgBox {
	movingEnable = 1;
	onLoad="endLoadingScreen";
	class Top {
		
		class CA_Background_Top : RscPicture {
			x = 0.13;
			y = 0.24;
			w = 1.2549;
			h = 0.104575;
			moving = 1;
			text = "\origins_pack\ui\ui_messagebox_top_ca.paa";
		};
	};
	
	class Middle {

		class CA_Background_Middle : RscPicture {
			x = 0.13;
			y = 0.344621;
			w = 1.2549;
			h = 0.032;
			text = "\origins_pack\ui\ui_messagebox_middle_ca.paa";
		};
		
		class CA_Text : RscStructuredText {
			idc = 101;
			x = 0.146045;
			y = 0.344621;
			w = 0.71;
			h = 0;
			size = 0.03921;
			
			class Attributes {
				color = "#e0d8a6";
			};
		};
	};
	
	class Bottom {
		
		class CA_Background_Bottom : RscPicture {
			x = 0.13;
			y = 0.376621;
			w = 1.2549;
			h = 0.20915;
			text = "\origins_pack\ui\ui_messagebox_bottom_ca.paa";
		};
		
		class CA_ButtonOK : RscShortcutButton {
			idc = 1;
			shortcuts[] = {0x00050000 + 0, 28, 57, 156};
			text = $STR_DISP_OK;
			default = 1;
			x = 0.4504;
			y = 0.401621;
			w = 0.2;
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
				left = 0.062;
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
		
		class CA_ButtonCancel : CA_ButtonOK {
			idc = 2;
			shortcuts[] = {0x00050000 + 1};
			text = $STR_DISP_CANCEL;
			x = 0.66;
		};
	};
};

class RscDisplayPassword : RscStandardDisplay {
	movingEnable = 0;
	simulationEnabled = 0;
	
	class controlsbackground {
		class MainbackFadedOrigins : RscPicture {
			x = "SafeZoneX";
			y = "SafeZoneY";
			w = "SafeZoneW";
			h = "SafeZoneH";
			colorText[] = {1, 1, 1, 1};
			text = "\origins_pack\ui\fon_co.paa";
		};
		delete CA_Background_Top;
		class CA_Background_TopOri : RscPicture {
			x = 0.13;
			y = 0.24;
			w = 1.2549;
			h = 0.418301;
			text = "\origins_pack\ui\ui_background_messagebox_ca.paa";
		};
	};
	
	class controls {
		delete SetPasswordTitle;
		class TextPassword : RscText {
			idc = 1002;
			x = 0.191;
			y = 0.354166;
			w = 0.161766;
			text = $STR_DISP_PASSWORD;
		};
		
		class ValuePassword : RscEdit {
			x = 0.361519;
			y = 0.356617;
			w = 0.330885;
			h = 0.039216;
			colorBackground[] = {0, 0, 0, 0.5};
		};
		
		class CA_ButtonCancel : RscShortcutButton {
			idc = 2;
			shortcuts[] = {0x00050000 + 1};
			text = $STR_DISP_CANCEL;
			x = 0.200196;
			y = 0.465924;
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
		
		class CA_ButtonOK : RscShortcutButton {
			idc = 1;
			shortcuts[] = {0x00050000 + 0, 28, 57, 156};
			text = $STR_DISP_OK;
			default = 1;
			x = 0.604981;
			y = 0.465924;
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
				left = 0.062;
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

class RscDisplayLoadCustom : RscDisplayLoadMission {
	enableSimulation = 0;
	onload = "_this call compile preprocessfilelinenumbers 'ca\ui\scripts\ui_loadingTextCustom.sqf';";
};

class RscDisplayLoading 
{
	class Variants 
	{
		class LoadingOne 
		{
			class controls 
			{
				class LoadingPic : RscPictureKeepAspect
				{
					text = "z\addons\dayz_code\gui\a2edc_loading_wallpaper_00.paa";
				};
			};
		};
	};
};

class RscDisplayStart 
{
	class controls
	{
		class LoadingPic: RscPictureKeepAspect
		{
			text = "z\addons\dayz_code\gui\a2edc_loading_wallpaper_00.paa";
		};
	};
};

class RscDisplayMain : RscStandardDisplay
{
	onKeyDown = " _dummy = _this execVM ""\origins_pack\ui\scripts\mainmenuShortcuts.sqf"";";
	class RscShortcutButtonMain2 : RscShortcutButtonMain {
		animTextureNormal 	= "\origins_pack\ui\ui_knopka_menu_disabled_ca.paa";
		animTextureDisabled = "\origins_pack\ui\ui_knopka_menu_disabled_ca.paa";
		animTextureOver 	= "\origins_pack\ui\ui_knopka_menu_over_ca.paa";
		animTextureFocused 	= "\origins_pack\ui\ui_knopka_menu_focus_ca.paa";
		animTexturePressed 	= "\origins_pack\ui\ui_knopka_menu_down_ca.paa";
		animTextureDefault 	= "\origins_pack\ui\ui_knopka_menu_disabled_ca.paa";
		period = 0.5;
		periodFocus = 1.2;
		periodOver = 0.8;
	};
	class controlsBackground 
	{
		class MainbackFadedOrigins : RscPicture {
			x = "SafeZoneX";
			y = "SafeZoneY";
			w = "SafeZoneW";
			h = "SafeZoneH";
			colorText[] = {1, 1, 1, 1};
			text = "\origins_pack\ui\fon_co.paa";
		};
		delete Mainback;
		class Mainback_Ori : RscPicture {
			idc = 1104;
			x = 0.045;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			text = "\origins_pack\ui\ui_menu_fon_ca.paa";
		};
		delete CA_ARMA2;
		class CA_ARMA2_Ori : RscPicture {
			idc = 1106;
			colorText[] = {1, 1, 1, 0.6+0.4};
			x = "(SafeZoneW + SafeZoneX) - (0.1568627*1.5 + 0.04)";
			y = "SafeZoneY + 0.00";
			w = 0.1568627*1.5;
			h = 0.2091503*1.5;
			text = "z\addons\dayz_code\gui\Origins_logo_ca.paa";
		};
		
	};

	class controls 
	{
		delete CA_Expansions;
		delete CA_SinglePlayer;
		
		class CA_Version;
		class DAYZ_Version : CA_Version
		{
			idc = -1;
			text = "Origins v.1.7.8.5 Alpha";
			y = "(SafeZoneH + SafeZoneY) - (1 - 0.95)";
		};
		class CA_MP: RscShortcutButtonMain2 { y = 0.2537; default = 0; };
		class CA_Options: RscShortcutButtonMain2 { y = 0.354519; default = 0; };
		class CA_PlayerProfile: RscShortcutButtonMain2 { y = 0.455421; default = 0; };
		
		class CA_Exit : RscShortcutButton {
			idc = 106;
			shortcuts[] = {0x00050000 + 3};
			x = 0.17431;
			y = 0.8799;
			//w = 0.207943;
			w = 0.153825;
			h = 0.08;
			text = $STR_CA_MAIN_QUIT;
			toolTip = $STR_TOOLTIP_MAIN_EXIT;
			period = 0;
			periodFocus = 0;
			periodOver = 0;
			animTextureNormal 	= "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureDisabled = "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureOver 	= "\origins_pack\ui\esc_knopka_focus_ca.paa";
			animTextureFocused 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			animTexturePressed 	= "\origins_pack\ui\esc_knopka_down_ca.paa";
			animTextureDefault 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			default = 1;
			class TextPos 
			{
				left = 0.040;
				top = 0.010;
				right = 0.005;
				bottom = 0.005;
			};
			class HitZone
			{
				left = 0.01;
				top = 0.01;
				right = 0.01;
				bottom = 0.01;
			};
		};
	};
};

class RscDisplayMultiplayer : RscStandardDisplay {
	class controlsbackground {
		class CA_TitleBack : RscPicture {
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(02/100)	* SafeZoneH + SafeZoneY";
			w = "(96/100)	* SafeZoneW";
			h = "(06/100)	* SafeZoneH";
			text = "\origins_pack\ui\mp_topfon.paa";
		};
		
		delete MainbackSessions;
		delete CA_New;
		class Origins_Slogo : RscPictureKeepAspect {
			idc = 1107;
			x = "(0.7/100)	* SafeZoneW + SafeZoneX";
			y = "(0.1/100)	* SafeZoneH + SafeZoneY";
			w = "(10/100)	* SafeZoneW";
			h = "(7.5/100)	* SafeZoneH";
			text = "z\addons\dayz_code\gui\Origins_logo_ca.paa";
		};

		delete GameSpy;
		class GameSpyOri : RscPictureKeepAspect {
			idc = 1106;
			x = "(82/100)	* SafeZoneW + SafeZoneX";
			y = "(2.5/100)	* SafeZoneH + SafeZoneY";
			w = "(15/100)	* SafeZoneW";
			h = "(5/100)	* SafeZoneH";
			text = "\origins_pack\ui\gamespy_logo.paa";
		};

		delete CA_Title2Border;
		delete CA_Title2;
		delete ValueSessionsBorder;
		class CA_Title2ori : RscText {
			idc = 101;
			style = 2;
			font = "TahomaB";
			sizeEx = 0.05906536;
			colorText[] = {0, 0, 0, 0.9};
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(02/100)	* SafeZoneH + SafeZoneY";
			w = "(96/100)	* SafeZoneW";
			h = "(06/100)	* SafeZoneH";
		};
		class CA_ServerDetailHost : RscText {
			idc = 129;
			SizeEx = 0.02674;
			font = "TahomaB";
			x = "(04/100)	* SafeZoneW + SafeZoneX";
			y = "(78/100)	* SafeZoneH + SafeZoneY";
			w = "(94/100)	* SafeZoneW";
			h = "(2/100)	* SafeZoneH";
			colorbackground[] = {0.1961, 0.1451, 0.0941, 0.42};
		};
		delete CA_TextServerDetailDifficulty;
		class CA_TextServerDetailDifficulty_Ori : CA_ServerDetailHost {
			text = $STR_CA_DIFFICULTY;
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(87/100)	* SafeZoneH + SafeZoneY";
			w = "(15/100)	* SafeZoneW";
			h = "(2/100)	* SafeZoneH";
		};
		delete CA_ServerDetailDifficulty;
		class CA_ServerDetailDifficulty_Ori : CA_ServerDetailHost {
			idc = 138;
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(90/100)	* SafeZoneH + SafeZoneY";
			w = "(15/100)	* SafeZoneW";
			h = "(2/100)	* SafeZoneH";
		};
		delete CA_TextServerDetailPlayers;
		class CA_TextServerDetailPlayers_Ori : CA_ServerDetailHost {
			text = $STR_DISP_MP_PLAYERS;
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(81/100)	* SafeZoneH + SafeZoneY";
			w = "(15/100)	* SafeZoneW";
			h = "(5/100)* SafeZoneH";
			SizeEx = 0.03;
		};
		delete CA_ServerDetailPlayers;
		class CA_ServerDetailPlayers_Ori : CA_ServerDetailHost {
			idc = 149;
			style = 0x10 + 0x200;
			lineSpacing = 0.9;
			x = "(18/100)	* SafeZoneW + SafeZoneX";
			y = "(81/100)	* SafeZoneH + SafeZoneY";
			w = "(80/100)	* SafeZoneW";
			h = "(12.75/100)* SafeZoneH";
		};
		class CA_ServerDetailPassword : RscPictureKeepAspect {
			idc = 143;
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(78/100)	* SafeZoneH + SafeZoneY";
			w = "(2/100)	* SafeZoneW";
			h = "(2/100)	* SafeZoneH";
		};
		//znachek treugolnika
		class CA_ServerIcon : RscPictureKeepAspect {
			idc = 111;
			x = "(01.5/100)	* SafeZoneW + SafeZoneX";
			y = "(9/100)	* SafeZoneH + SafeZoneY";
			w = 0.03;
			h = 0.03;
			colorText[] = {1, 1, 1, 1};
		};
		
		class CA_TypeIcon : CA_ServerIcon {
			idc = 140;
			x = "(39.25/100)	* SafeZoneW + SafeZoneX";
		};
		
		class CA_MissionIcon : CA_ServerIcon {
			idc = 113;
			x = "(45.5/100)	* SafeZoneW + SafeZoneX";
		};
		
		class CA_StateIcon : CA_ServerIcon {
			idc = 115;
			x = "(78.25/100)	* SafeZoneW + SafeZoneX";
		};
		
		class CA_PlayersIcon : CA_ServerIcon {
			idc = 117;
			x = "(85.5/100)	* SafeZoneW + SafeZoneX";
		};
		
		class CA_PingIcon : CA_ServerIcon {
			idc = 119;
			x = "(91.75/100)	* SafeZoneW + SafeZoneX";
		};
		
		//knopki filtrov
		class CA_FilterPasswordedServers : RscPictureKeepAspect {
			idc = 150;
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(75/100)	* SafeZoneH + SafeZoneY";
			w = "(2/100)	* SafeZoneW";
			h = "(3/100)	* SafeZoneH";
		};
		
		class CA_FilterFullServers : CA_FilterPasswordedServers {
			idc = 151;
			x = "(5/100)	* SafeZoneW + SafeZoneX";
		};
		
		class CA_ServerBEFilter : CA_FilterPasswordedServers {
			idc = 154;
			x = "(8/100)	* SafeZoneW + SafeZoneX";
		};
		
		class CA_ServerExpansionsFilter : CA_FilterPasswordedServers {
			idc = 155;
			x = "(11/100)	* SafeZoneW + SafeZoneX";
		};
		//dannie iz filtra
		class CA_ServerFilter : RscText {
			idc = 125;
			SizeEx = 0.02674;
			x = "(16/100)	* SafeZoneW + SafeZoneX";
			y = "(75/100)	* SafeZoneH + SafeZoneY";
			w = "(20/100)	* SafeZoneW";
			h = "(3/100)	* SafeZoneH";
			text = "Official Dayz Origins";
			font = "TahomaB";
		};
		
		class CA_TypeFilter : CA_ServerFilter {
			idc = 152;
			x = "(40/100)	* SafeZoneW + SafeZoneX";
			w = "(8/100)	* SafeZoneW";
		};
		
		class CA_MissionFilter : CA_ServerFilter {
			idc = 126;
			x = "(55/100)	* SafeZoneW + SafeZoneX";
		};
		
		class CA_PlayersFilter : CA_ServerFilter {
			idc = 127;
			style = 2;
			x = "(86.5/100)	* SafeZoneW + SafeZoneX";
			w = "(6/100)	* SafeZoneW";
		};
		
		class CA_PingFilter : CA_ServerFilter {
			idc = 128;
			x = "(93/100)	* SafeZoneW + SafeZoneX";
			w = "(4/100)	* SafeZoneW";
		};
		
		//knopki
		class CA_Cancel : RscShortcutButton {
			idc = 2;
			default = 0;
			x = "(85/100)	* SafeZoneW + SafeZoneX";
			y = "(95/100)	* SafeZoneH + SafeZoneY";
			shortcuts[] = {0x00050000 + 1};
			text = $STR_CA_CANCEL;
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
				left = 0.0492;
				top = 0.005;
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
		
		class CA_Internet_Lan : CA_Cancel {
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(95/100)	* SafeZoneH + SafeZoneY";
			w = 0.283825;
			default = 0;
			class TextPos {
				left = 0.056;
				top = 0.005;
				right = 0.005;
				bottom = 0.005;
			};
			shortcuts[] = {};
			idc = 122;
		};
		
		class CA_Refresh : CA_Cancel {
			x = "(29/100)	* SafeZoneW + SafeZoneX";
			y = "(95/100)	* SafeZoneH + SafeZoneY";
			idc = 123;
			default = 0;
			text = $STR_DISP_MULTI_REFRESH;
			shortcuts[] = {0x00050000 + 3};
			class TextPos {
				left = 0.046;
				top = 0.005;
				right = 0.005;
				bottom = 0.005;
			};
		};
		
		class CA_Join : CA_Cancel {
			x = "(43/100)	* SafeZoneW + SafeZoneX";
			y = "(95/100)	* SafeZoneH + SafeZoneY";
			idc = 105;
			shortcuts[] = {0x00050000 + 0, 28, 57, 156};
			default = 1;
			text = $STR_CA_MULTI_JOIN;
			class TextPos {
				left = 0.048;
				top = 0.005;
				right = 0.005;
				bottom = 0.005;
			};
		};
		
		class CA_BFilter : CA_Cancel {
			x = "(57/100)	* SafeZoneW + SafeZoneX";
			y = "(95/100)	* SafeZoneH + SafeZoneY";
			idc = 124;
			default = 0;
			shortcuts[] = {0x00050000 + 2};
			text = $STR_DISP_MULTI_FILTER;
			class TextPos {
				left = 0.046;
				top = 0.005;
				right = 0.005;
				bottom = 0.005;
			};
		};
		
		class CA_BRemote : CA_Cancel {
			x = "(71/100)	* SafeZoneW + SafeZoneX";
			y = "(95/100)	* SafeZoneH + SafeZoneY";
			idc = 103;
			default = 0;
			shortcuts[] = {};
			text = $STR_CA_MULTI_REMOTE;
			class TextPos {
				left = 0.033;
				top = 0.005;
				right = 0.005;
				bottom = 0.005;
			};
		};
		
		
		delete CA_ServerDetailType;
		delete CA_TextServerDetailExpansions;
		delete CA_ServerDetailExpansion;
		delete CA_ServerDetailVersionRequired;
		delete CA_ServerDetailIsland;
		delete CA_TextServerDetailIsland;
		delete CA_TextServerDetailTimeLeft;
		delete CA_ServerDetailTimeLeft;
		delete CA_ServerDetailVersion;
		delete CA_TextServerDetailPlatform;
		delete CA_ServerDetailPlatform;
		delete CA_TextServerDetailountry;
		delete CA_ServerDetailCountry;
		delete CA_TextServerDetailBE;
		delete CA_ServerDetailBE;
		delete CA_TextServerDetailType;
		delete CA_TextServerDetailMission;
		class Mainback : RscPicture {
			x = "SafeZoneX";
			y = "SafeZoneY";
			w = "SafeZoneW";
			h = "SafeZoneH";
			colorbackground[] = {0, 0, 0, 0};
			text = "\origins_pack\ui\fon_co.paa";
		};
	};
	class controls {
		delete CA_MissionColumn;
		delete CA_TypeColumn;
		class CA_ServerColumn : RscButtonTextOnly {
			idc = 112;
			text = $STR_MP_SERVER;
			font = "TahomaB";
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(9/100)	* SafeZoneH + SafeZoneY";
			w = "(75/100)	* SafeZoneW";
			h = "(2/100)	* SafeZoneH";
			colorBackgroundActive[] = {1, 1, 1, 0.55};
			colorBackgroundDisabled[] = {1, 1, 1, 1};
		};
		
		class CA_StateColumn : CA_ServerColumn {
			idc = 116;
			text = $STR_MENU_STATUS;
			font = "TahomaB";
			x = "(78.5/100)	* SafeZoneW + SafeZoneX";
			w = "(8/100)	* SafeZoneW";
		};
		
		class CA_PlayersColumn : CA_ServerColumn {
			idc = 118;
			text = $STR_MP_PLAYERS;
			font = "TahomaB";
			x = "(87/100)	* SafeZoneW + SafeZoneX";
			w = "(6/100)	* SafeZoneW";
		};
		
		class CA_PingColumn : CA_ServerColumn {
			idc = 120;
			text = $STR_DISP_MULTI_PING;
			font = "TahomaB";
			x = "(93/100)	* SafeZoneW + SafeZoneX";
			w = "(4/100)	* SafeZoneW";
		};
		class CA_ValueSessions : RscIGUIListBox {
			idc = 102;
			style = 16;
			shadow = 2;
			font = "TahomaB";
			colorSelect[] = {0.69, 0.769, 0.871, 1};
			colorPingUnknown[] = {0.4, 0.4, 0.4, 1};
			colorPingGood[] = {0, 1, 0, 1};
			colorPingPoor[] = {1, 0.6, 0, 1};
			colorPingBad[] = {1, 0, 0, 1};
			rowHeight = 0.025;
			colorSelectBackground[] = {0, 0, 0, 1};
			colorSelectBackground2[] = {0.58, 0.1147, 0.1108, 1};
			password = "ca\ui\data\ui_server_password_ca.paa";
			locked = "ca\ui\data\ui_server_locked_ca.paa";
			version = "ca\ui\data\ui_wrong_version_ca.paa";
			none = "ca\ui\data\ui_server_connect_ca.paa";
			star = "ca\ui\data\ui_mission_done_ca.paa";
			addons = "ca\ui\data\ui_server_addons_ca.paa";
			mods = "ca\ui\data\ui_server_red_mark_ca.paa";
			x = "(02/100)	* SafeZoneW + SafeZoneX";
			y = "(12/100)	* SafeZoneH + SafeZoneY";
			w = "(96/100)	* SafeZoneW";
			h = "(61.25/100)	* SafeZoneH";
			SizeEx = 0.025;
			columns[] = {0.81, 0, 0, 0.10, 0.05, 0.04};
		};
	};
};

class RscDisplayFilter : RscStandardDisplay {
	class controlsBackground {

		class MainbackFadedOrigins : RscPicture {
			x = "SafeZoneX";
			y = "SafeZoneY";
			w = "SafeZoneW";
			h = "SafeZoneH";
			colorText[] = {1, 1, 1, 1};
			text = "\origins_pack\ui\fon_co.paa";
		};
		
		delete MainbackFaded1;
		class MainbackFaded1_ori : RscPicture {
			idc = 1106;
			x = 0.045;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			colorText[] = {1, 1, 1, 0.25};
			text = "\origins_pack\ui\ui_menu_fonf_ca.paa";
		};
		
		delete MainbackFaded2;
		class MainbackFaded2_ori : RscPicture {
			idc = 1107;
			x = 0.092;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			colorText[] = {1, 1, 1, 0.5};
			text = "\origins_pack\ui\ui_menu_fonf_ca.paa";
		};
		
		delete Mainback;
		class Mainback_ori : RscPicture {
			idc = 1104;
			x = 0.138;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			text = "\origins_pack\ui\ui_menu_fonf_ca.paa";
		};
	
	};
	
	class controls {
		
		class CA_FilterTitle : CA_Title {
			x = 0.18;
			y = 0.192;
			text = $STR_DISP_FILTER_TITLE;
		};
		
		class CA_TextServer : RscText {
			x = 0.159803;
			y = (0.416549 + -3*0.0500);
			w = 0.235296;
			text = $STR_DISP_FILTER_SERVER;
		};
		
		class CA_ValueServer : RscEdit {
			idc = 101;
			x = 0.400534;
			y = (0.416549 + -3*0.0500);
			w = 0.3;
		};
		
		class CA_TextMaxPing : CA_TextServer {
			x = 0.159803;
			y = (0.416549 + -2*0.0500);
			text = $STR_DISP_FILTER_MAXPING;
		};
		
		class CA_ValueMaxPing : CA_ValueServer {
			idc = 103;
			x = 0.400534;
			y = (0.416549 + -2*0.0500);
			w = 0.1;
		};
		
		class CA_TextMinPlayers : CA_TextServer {
			x = 0.159803;
			y = (0.416549 + -1*0.0500);
			text = $STR_DISP_FILTER_MINPLAYERS;
		};
		
		class CA_ValueMinPlayers : CA_ValueMaxPing {
			idc = 104;
			x = 0.400534;
			y = (0.416549 + -1*0.0500);
		};
		
		class CA_TextMaxPlayers : CA_TextServer {
			x = 0.159803;
			y = (0.416549 + 0*0.0500);
			text = $STR_DISP_FILTER_MAXPLAYERS;
		};
		
		class CA_ValueMaxPlayers : CA_ValueMaxPing {
			idc = 105;
			x = 0.400534;
			y = (0.416549 + 0*0.0500);
		};
		
		class CA_TextMission : CA_TextServer {
			x = 0.159803;
			y = (0.416549 + 1*0.0500);
			text = $STR_DISP_FILTER_MISSION;
		};
		
		class ValueMission : CA_ValueServer {
			idc = 102;
			x = 0.400534;
			y = (0.416549 + 1*0.0500);
		};
		
		class CA_TextFilterType : CA_TextServer {
			x = 0.159803;
			y = (0.416549 + 2*0.0500);
			text = $STR_DISP_ARCGRP_TYPE;
		};
		
		class CA_FilterType : RscCombo {
			idc = 109;
			x = 0.400534;
			y = (0.416549 + 2*0.0500);
			w = 0.3;
		};
		
		class CA_TextExpansionsType : CA_TextServer {
			x = 0.159803;
			y = (0.416549 + 3*0.0500);
			text = $STR_DISP_EXPANSIONS;
		};
		
		class CA_FilterExpansions : RscXListBox {
			idc = 111;
			x = 0.400534;
			y = (0.416549 + 3*0.0500);
			w = 0.3;
		};
		
		class CA_TextHideFull : CA_TextServer {
			x = 0.159803;
			y = (0.416549 + 4*0.0500);
			text = $STR_FILTER_FULL_TEXT;
		};
		
		class CA_FullServers : RscXListBox {
			idc = 106;
			x = 0.400534;
			y = (0.416549 + 4*0.0500);
			w = 0.3;
		};
		
		class CA_TextPassworded : CA_TextServer {
			x = 0.159803;
			y = (0.416549 + 5*0.0500);
			text = $STR_FILTER_PASSWORDED_TEXT;
		};
		
		class CA_PasswordedServers : CA_FullServers {
			idc = 107;
			x = 0.400534;
			y = (0.416549 + 5*0.0500);
		};
		
		class CA_TextBattlEye : CA_TextServer {
			x = 0.159803;
			y = (0.416549 + 6*0.0500);
			text = $STR_FILTER_BATTLEYE_TEXT;
		};
		
		class CA_BEServers : CA_FullServers {
			idc = 110;
			x = 0.400534;
			y = (0.416549 + 6*0.0500);
			w = 0.3;
		};
		
		class CA_Filter_Default : RscShortcutButton {
			idc = 108;
			shortcuts[] = {0x00050000 + 2};
			x = 0.3395;
			y = 0.7625;
			text = $STR_DISP_DEFAULT;
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
			class TextPos 
			{
				left = 0.040;
				top = 0.007;
				right = 0.005;
				bottom = 0.005;
			};
			class HitZone
			{
				left = 0.01;
				top = 0.01;
				right = 0.01;
				bottom = 0.01;
			};
		};
		
		class CA_Filter_Ok : RscShortcutButton {
			idc = 1;
			shortcuts[] = {0x00050000 + 0, 28, 57, 156};
			x = 0.525;
			y = 0.7625;
			text = $STR_DISP_OK;
			default = 1;
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
			class TextPos 
			{
				left = 0.06;
				top = 0.007;
				right = 0.005;
				bottom = 0.005;
			};
			class HitZone
			{
				left = 0.01;
				top = 0.01;
				right = 0.01;
				bottom = 0.01;
			};
		};
		
		class CA_Filter_Cancel : RscShortcutButton {
			idc = 2;
			shortcuts[] = {0x00050000 + 1};
			x = 0.157;
			y = 0.7625;
			text = $STR_DISP_CANCEL;
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
			class TextPos 
			{
				left = 0.05;
				top = 0.007;
				right = 0.005;
				bottom = 0.005;
			};
			class HitZone
			{
				left = 0.01;
				top = 0.01;
				right = 0.01;
				bottom = 0.01;
			};
		};
	};
};

class RscDisplayIPAddress : RscStandardDisplay {
	class controlsBackground {
		
		class MainbackFadedOrigins : RscPicture {
			x = "SafeZoneX";
			y = "SafeZoneY";
			w = "SafeZoneW";
			h = "SafeZoneH";
			colorText[] = {1, 1, 1, 1};
			text = "\origins_pack\ui\fon_co.paa";
		};
		
		delete MainbackFaded1;
		class MainbackFaded1_ori : RscPicture {
			idc = 1106;
			x = 0.045;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			colorText[] = {1, 1, 1, 0.25};
			text = "\origins_pack\ui\ui_menu_fon_ca.paa";
		};
		delete MainbackFaded2;
		class MainbackFaded2_ori : RscPicture {
			idc = 1107;
			x = 0.092;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			colorText[] = {1, 1, 1, 0.5};
			text = "\origins_pack\ui\ui_menu_fon_ca.paa";
		};
		delete Mainback;
		class Mainback_ori : RscPicture {
			idc = 1104;
			x = 0.138;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			text = "\origins_pack\ui\ui_menu_fon_ca.paa";
		};
	};
	
	class controls {
				
		class CA_IPTitle : CA_Title {
			x = 0.18;
			y = 0.192;
			text = $STR_DISP_IP_TITLE;
		};
		
		class CA_TextAddress : RscText {
			x = 0.160706;
			y = 0.279628;
			w = 0.169119;
			text = $STR_DISP_IP_ADDRESS;
		};
		
		class CA_ValueAddress : RscEdit {
			idc = 101;
			x = 0.26178;
			y = 0.279628;
			w = 0.180;
			h = 0.039216;
		};
		
		class CA_TextPort : CA_TextAddress {
			y = 0.328648;
			text = $STR_DISP_IP_PORT;
		};
		
		class CA_ValuePort : CA_ValueAddress {
			idc = 102;
			y = 0.328648;
			w = 0.110295;
		};
		
		class ButtonContinue : RscShortcutButton {
			idc = 1;
			default = 1;
			shortcuts[] = {0x00050000 + 0, 28, 57, 156};
			x = 0.26178;
			y = 0.398648;
			
			text = $STR_DISP_OK;
			w = 0.153825;
			h = 0.07;
			period = 0;
			periodFocus = 0;
			periodOver = 0;
			animTextureNormal 	= "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureDisabled = "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureOver 	= "\origins_pack\ui\esc_knopka_focus_ca.paa";
			animTextureFocused 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			animTexturePressed 	= "\origins_pack\ui\esc_knopka_down_ca.paa";
			animTextureDefault 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			class TextPos 
			{
				left = 0.05;
				top = 0.005;
				right = 0.005;
				bottom = 0.005;
			};
			class HitZone
			{
				left = 0.01;
				top = 0.01;
				right = 0.01;
				bottom = 0.01;
			};
		};
		
		class ButtonCancel : RscShortcutButton {
			idc = 2;
			default = 0;
			shortcuts[] = {0x00050000 + 1};
			x = 0.27;
			y = 0.8825;
			text = $STR_DISP_BACK;
			h = 0.07;
			w = 0.153825;
			period = 0;
			periodFocus = 0;
			periodOver = 0;
			animTextureNormal 	= "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureDisabled = "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureOver 	= "\origins_pack\ui\esc_knopka_focus_ca.paa";
			animTextureFocused 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			animTexturePressed 	= "\origins_pack\ui\esc_knopka_down_ca.paa";
			animTextureDefault 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			class TextPos 
			{
				left = 0.040;
				top = 0.005;
				right = 0.005;
				bottom = 0.005;
			};
			class HitZone
			{
				left = 0.01;
				top = 0.01;
				right = 0.01;
				bottom = 0.01;
			};
		};
	};
};


class dStronghold {
	#define CT_STATIC	0
	#define CT_BUTTON	1
	#define CT_EDIT	2
	#define CT_SLIDER	3
	#define CT_COMBO	4
	#define CT_LISTBOX	5
	#define CT_TOOLBOX	6
	#define CT_CHECKBOXES	7
	#define CT_PROGRESS	8
	#define CT_HTML	9
	#define CT_STATIC_SKEW	10
	#define CT_ACTIVETEXT	11
	#define CT_TREE	12
	#define CT_STRUCTURED_TEXT	13
	#define CT_CONTEXT_MENU	14
	#define CT_CONTROLS_GROUP	15
	#define CT_XKEYDESC	40
	#define CT_XBUTTON	41
	#define CT_XLISTBOX	42
	#define CT_XSLIDER	43
	#define CT_XCOMBO	44
	#define CT_ANIMATED_TEXTURE	45
	#define CT_OBJECT	80
	#define CT_OBJECT_ZOOM	81
	#define CT_OBJECT_CONTAINER	82
	#define CT_OBJECT_CONT_ANIM	83
	#define CT_LINEBREAK	98
	#define CT_USER	99
	#define CT_MAP	100
	#define CT_MAP_MAIN	101
	#define ST_POS	0x0F
	#define ST_HPOS	0x03
	#define ST_VPOS	0x0C
	#define ST_LEFT	0x00
	#define ST_RIGHT	0x01
	#define ST_CENTER	0x02
	#define ST_DOWN	0x04
	#define ST_UP	0x08
	#define ST_VCENTER	0x0c
	#define ST_TYPE	0xF0
	#define ST_SINGLE	0
	#define ST_MULTI	16
	#define ST_TITLE_BAR	32
	#define ST_PICTURE	48
	#define ST_FRAME	64
	#define ST_BACKGROUND	80
	#define ST_GROUP_BOX	96
	#define ST_GROUP_BOX2	112
	#define ST_HUD_BACKGROUND	128
	#define ST_TILE_PICTURE	144
	#define ST_WITH_RECT	160
	#define ST_LINE	176
	#define ST_SHADOW	0x100
	#define ST_NO_RECT	0x200
	#define ST_KEEP_ASPECT_RATIO	0x800
	#define ST_TITLE	ST_TITLE_BAR + ST_CENTER
	#define SL_DIR	0x400
	#define SL_VERT	0
	#define SL_HORZ	0x400
	#define SL_TEXTURES	0x10
	#define LB_TEXTURES	0x10
	#define LB_MULTI	0x20
	#define FontM	"TahomaB"
	#define FontHTML	"TahomaB"
	//--- Ressources.
	class RscPictureK {
		type = 0;
		style = 48;
		colorText[] = {0.75, 0.75, 0.75, 1};
		colorBackground[] = {0, 0, 0, 0};
		font = "Bitstream";
		sizeEx = 0.025;
		soundClick[] = {"", 0.2, 1};
		soundEnter[] = {"", 0.2, 1};
		soundEscape[] = {"", 0.2, 1};
		soundPush[] = {"", 0.2, 1};
		w = 0.275;
		h = 0.04;
		text = "";
	};

	class RscButtonK
	{
		type=CT_BUTTON;
		style=ST_CENTER;
		colorText[]={0, 0, 0, 1};
		font=FontHTML;
		sizeEx=0.05;
		soundPush[]={"", 0.2, 1};
		soundClick[]={"\ca\ui\data\sound\new1", 0.2, 1};
		soundEscape[]={"\ca\ui\data\sound\new1", 0.2, 1};
		default=false;
		text="";
		action="";
		colorActive[]={0, 0, 0, 0};
		colorDisabled[]={0, 0, 0, 0.1};
		colorBackground[]={0,0,0,0.3};
		colorBackgroundActive[]={0,0,0,0.4};
		colorBackgroundDisabled[]={0,0,0,0.3};
		colorFocused[]={0.84,1,0.55,1};
		colorShadow[]={1, 1, 1, 0.1};
		colorBorder[]={0, 0, 0, 0.1};
		offsetX=0;
		offsetY=0;
		offsetPressedX=0;
		offsetPressedY=0;
		borderSize=0;
		soundEnter[]={"", 0.15, 1};
		period = 0;
	};
	class Ori_Button
	{
		type = 16;
		style = 0;
		default = false;
		x = 0.1;
		y = 0.1;
		w = 0.183825;
		h = 0.104575;
		color[] = {0.543, 0.5742, 0.4102, 1.0};
		color2[] = {0.95, 0.95, 0.95, 1};
		colorBackground[] = {1, 1, 1, 1};
		colorbackground2[] = {1, 1, 1, 1};
		colorDisabled[] = {1, 1, 1, 0.25};
		periodFocus = 1.2;
		periodOver = 0.8;

		class HitZone
		{
			left = 0.004;
			top = 0.009;
			right = 0.004;
			bottom = 0.009;
		};

		class ShortcutPos
		{
			left = 0.0145;
			top = 0.026;
			w = 0.0392157;
			h = 0.0522876;
		};

		class TextPos
		{
			left = 0.005;
			top = 0.01;
			right = 0.005;
			bottom = 0.005;
		};

		textureNoShortcut = "";
		//animTextureNormal = "\ca\ui\data\ui_button_normal_ca.paa";
		animTextureNormal 	= "\origins_pack\ui\knopka_normal.paa";
		animTextureDisabled = "\origins_pack\ui\knopka_normal.paa";
		animTextureOver 	= "\origins_pack\ui\knopka_hover.paa";
		animTextureFocused 	= "\origins_pack\ui\knopka_hover.paa";
		animTexturePressed 	= "\origins_pack\ui\knopka_press.paa";
		animTextureDefault 	= "\origins_pack\ui\knopka_normal.paa";
		period = 0.4;
		font = "Zeppelin32";
		size = 0.05;
		sizeEx = 0.05;
		text = "";
		soundEnter[] = {"", 0.09, 1};
		soundPush[] = {"", 0.09, 1};
		soundClick[] = {"", 0.07, 1};
		soundEscape[] = {"", 0.09, 1};
		action = "";
		toolTip = "";

		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "center";
			shadow = "true";
		};

		class AttributesImage
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "center";
			shadow = "true";
		};
	};
	class RscListBoxK {
		type = 5;
		canDrag = 0;
		style = 0 + 0x10;
		font = "Zeppelin32";
		sizeEx = 0.04221;
		rowHeight = 0.03;
		colorBackground[] = { 0.8, 0.8, 1, 0.7};
		//color[] = {1, 1, 1, 1};
		colorText[] = {1, 1, 1, 0.75};
		colorScrollbar[] = {0.95, 0.95, 0.95, 1};
		colorSelect[] = {0.95, 0.95, 0.95, 1};
		colorSelect2[] = {0.95, 0.95, 0.95, 1};
		colorSelectBackground[] = {0.6, 0.8392, 0.4706, 1.0};
		colorSelectBackground2[] = {0.6, 0.8392, 0.4706, 1.0};
		columns[] = {0.1, 0.7, 0.1, 0.1};
		period = 0;
		maxHistoryDelay = 1.0;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
		soundSelect[] = {"\ca\ui\data\sound\new1", 0.09, 1};
		
		class ScrollBar {
			color[] = {1, 1, 1, 0.6};
			colorActive[] = {1, 1, 1, 1};
			colorDisabled[] = {1, 1, 1, 0.3};
			thumb = "\ca\ui\data\igui_scrollbar_thumb_ca.paa";
			arrowFull = "\ca\ui\data\igui_arrow_top_active_ca.paa";
			arrowEmpty = "\ca\ui\data\igui_arrow_top_ca.paa";
			border = "\ca\ui\data\igui_border_scroll_ca.paa";
		};
	};
	class RscTextK {
		type = 0;
		style = 0x02;
		
		colorText[] = {0, 1, 0.5, 1};
		//color[] = {1, 1, 1, 1};
		font = FontM;
		sizeEx = 0.08;
		x = 0;
		y = 0;
		w = 0.1;
		h = 0.2;
	};

	//--- Dialog.

	name = dStronghold;
	movingEnable = 0; 
	idd = 10001;
	controlsBackground[]={bg}; 
	objects[] = {};
	
	class controls {
		
		class listboxA : RscListBoxK {
			idc = 10002;
			x = 0.247 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.165 * safezoneW;
			h = 0.181 * safezoneH;
		};
		
		class listboxA2 : RscListBoxK {
			idc = 10003;
			x = 0.45 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.165 * safezoneW;
			h = 0.181 * safezoneH;
		};
		
		class but_del : Ori_Button {
			idc=-1;
			x = 0.245 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.1 * safezoneW;
			h = 0.04 * safezoneH;
			size = 0.045;
			sizeEx = 0.045;
			text = "REMOVE";
			action = "_index = lbCurSel 10002; if(_index > -1) then { selected_sl = []; selected_sl_n = []; selected_sl set [count selected_sl, playersID_arr select _index]; selected_sl_n set [count selected_sl_n, playersID_arr_n select _index]; playersID_arr = playersID_arr - selected_sl; playersID_arr_n = playersID_arr_n - selected_sl_n; playersID_arr2 set [count playersID_arr2, selected_sl select 0]; playersID_arr2_n set [count playersID_arr2_n, selected_sl_n select 0]; _text = lbText [10002, _index]; lbAdd [10003, _text]; lbDelete [10002, _index]; selected_sl = []; selected_sl_n = []; };";
		};
		
		class but_add : Ori_Button {
			idc=-1;
			x = 0.45 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.1 * safezoneW;
			h = 0.04 * safezoneH;
			size = 0.045;
			sizeEx = 0.045;
			text = "ADD";
			action = "_index = lbCurSel 10003; if(_index > -1) then { selected_sl = []; selected_sl_n = []; selected_sl set [count selected_sl, playersID_arr2 select _index]; selected_sl_n set [count selected_sl_n, playersID_arr2_n select _index]; hint format[""%1\n%2\n"",selected_sl,selected_sl_n]; playersID_arr2 = playersID_arr2 - selected_sl; playersID_arr2_n = playersID_arr2_n - selected_sl_n; playersID_arr set [count playersID_arr, selected_sl select 0]; playersID_arr_n set [count playersID_arr_n, selected_sl_n select 0]; _text = lbText [10003, _index];  lbAdd [10002, _text]; lbDelete [10003, _index]; selected_sl = []; selected_sl_n = []; };";
		};
		
		class but_ok : Ori_Button {
			idc=-1;
			x = 0.54 * safezoneW + safezoneX;
			y = 0.54 * safezoneH + safezoneY;
			w = 0.1 * safezoneW;
			h = 0.04 * safezoneH;
			size = 0.045;
			sizeEx = 0.045;
			text = "OK";
			action = "_vsego = count playersID_arr; if(_vsego > 3) then { NaDobavku = [] + playersID_arr; ctrlSetText [10004, ""OK""]; closeDialog 0; } else { NaDobavku = []; ctrlSetText [10004, ""Minimum 4 people""]; };";
		};
		
		class zagolvok : RscTextK {
			idc = -1;
			x = 0.305  * safezoneW + safezoneX;
			y = 0.20 * safezoneH + safezoneY;
			w = 0.27 * safezoneW;
			h = 0.04 * safezoneH;
			size = 0.065;
			sizeEx = 0.065 * (safezoneW + safezoneX);
			text = "Stronghold Team";
			colorText[] = {0, 0, 0, 0.9 };
			colorBackground[] = { 0, 0.128, 0, 0 };
		};
		class zagolvok_team : RscTextK {
			idc = -1;
			x = 0.24  * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.17 * safezoneW;
			h = 0.04 * safezoneH;
			text = "Members";
			size = 0.045;
			sizeEx = 0.045;
			colorText[] = {0.75, 0.75, 0.75, 0.8 };
			colorBackground[] = { 0, 0.128, 0, 0 };
		};
		class zagolvok_new : RscTextK {
			idc = -1;
			x = 0.45  * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.17 * safezoneW;
			h = 0.04 * safezoneH;
			text = "New members";
			size = 0.045;
			sizeEx = 0.045;
			colorText[] = {0.75, 0.75, 0.75, 0.8 };
			colorBackground[] = { 0, 0.128, 0, 0 };
		};
		class zagolvok_error : RscTextK {
			idc = 10004;
			x = 0.305  * safezoneW + safezoneX;
			y = 0.53 * safezoneH + safezoneY;
			w = 0.17 * safezoneW;
			h = 0.04 * safezoneH;
			text = "";
			size = 0.035;
			sizeEx = 0.035;
			colorText[] = {1, 1, 1, 0.75};
			colorBackground[] = { 0, 0.128, 0, 0 };
		};
		
	};
				
	class bg : RscPictureK {
		idc = -1;
		x = 0.20  * safezoneW + safezoneX;
		y = 0.20  * safezoneH + safezoneY;
		w = 0.47 * safezoneW;
		h = 0.40 * safezoneH;
		text = "\origins_pack\ui\fon.paa";
		colorBackground[] = { 0, 0.128, 0, 1 };
	};

};
class KeypadHouse {
// Control types
#define CT_STATIC 0
#define CT_BUTTON 1
#define CT_EDIT 2
#define CT_SLIDER 3
#define CT_COMBO 4
#define CT_LISTBOX 5
#define CT_TOOLBOX 6
#define CT_CHECKBOXES 7
#define CT_PROGRESS 8
#define CT_HTML 9
#define CT_STATIC_SKEW 10
#define CT_ACTIVETEXT 11
#define CT_TREE 12
#define CT_STRUCTURED_TEXT 13
#define CT_CONTEXT_MENU 14
#define CT_CONTROLS_GROUP 15
#define CT_SHORTCUT_BUTTON 16 // Arma 2 - textured button

#define CT_XKEYDESC 40
#define CT_XBUTTON 41
#define CT_XLISTBOX 42
#define CT_XSLIDER 43
#define CT_XCOMBO 44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT 80
#define CT_OBJECT_ZOOM 81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK 98
#define CT_USER 99
#define CT_MAP 100
#define CT_MAP_MAIN 101
#define CT_List_N_Box 102 // Arma 2 - N columns list box


// Static styles
#define ST_POS 0x0F
#define ST_HPOS 0x03
#define ST_VPOS 0x0C
#define ST_LEFT 0x00
#define ST_RIGHT 0x01
#define ST_CENTER 0x02
#define ST_DOWN 0x04
#define ST_UP 0x08
#define ST_VCENTER 0x0c

#define ST_TYPE 0xF0
#define ST_SINGLE 0
#define ST_MULTI 16
#define ST_TITLE_BAR 32
#define ST_PICTURE 48
#define ST_FRAME 64
#define ST_BACKGROUND 80
#define ST_GROUP_BOX 96
#define ST_GROUP_BOX2 112
#define ST_HUD_BACKGROUND 128
#define ST_TILE_PICTURE 144
#define ST_WITH_RECT 160
#define ST_LINE 176

#define ST_SHADOW 0x100
#define ST_NO_RECT 0x200 // this style works for CT_STATIC in conjunction with ST_MULTI
#define ST_KEEP_ASPECT_RATIO 0x800

#define ST_TITLE ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR 0x400
#define SL_VERT 0
#define SL_HORZ 0x400

#define SL_TEXTURES 0x10

// Listbox styles
#define LB_TEXTURES 0x10
#define LB_MULTI 0x20

// #define FontM "Zeppelin32"

	idd = 20900;
	movingEnable = false;
	controlsBackground[] = {};
	controls[] = {
		"B1",
		"B2",
		"B3",
		"B4",
		"B5",
		"B6",
		"B7",
		"B8",
		"B9",
		"B0",
		"BEnter",
		"BAbort",
		"KeypadImage",
		"NumberDisplay"
	};
	objects[] = {};
	class B1 {
		idc = -1;
		type = 1;
		style = 2;
		moving = false;
		x = 0.45;
		y = 0.46;
		h = 0.06;
		w = 0.04;
		font = "Zeppelin32";
		sizeEx = 0.05;
		action = "CODEINPUT set [count CODEINPUT, 1]; if ((count CODEINPUT) ==7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 1];};";
		text = "";
		default = false;
		colorText[] = {0,0,0,1};
		colorFocused[] = {0.1,0.1,0.1,0.1};
		colorShadow[] = {0,0,0,0};
		colorBorder[] = {0.5,0.5,0.5,0};
		colorBackground[] = {0.7,0.7,0.7,1};
		colorBackgroundActive[] = {0.1,0.1,0.1,0.3};
		colorDisabled[] = {1,0,0,1};
		colorBackgroundDisabled[] = {0.5,0.5,0.5,0};
		borderSize = 0.015;
		offsetX = 0.005;
		offsetY = 0.005;
		offsetPressedX = 0.002;
		offsetPressedY = 0.002;
		soundEnter[] = {"",0,1};
		soundPush[] = {"",0,1};
		soundClick[] = {"",0,1};
		soundEscape[] = {"",0,1};
	};
	class B2 : B1 {
		x = 0.52;
		text = "";
		action = "CODEINPUT set [count CODEINPUT, 2]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 2];};";
	};
	class B3 : B1 {
		x = 0.59;
		text = "";
		action = "CODEINPUT set [count CODEINPUT, 3]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 3];};";
	};
	class B4 : B1 {
		y = 0.57;
		text = "";
		action = "CODEINPUT set [count CODEINPUT, 4]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 4];};";
	};
	class B5 : B4 {
		x = 0.52;
		text = "";
		action = "CODEINPUT set [count CODEINPUT, 5]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 5];};";
	};
	class B6 : B4 {
		x = 0.59;
		text = "";
		action = "CODEINPUT set [count CODEINPUT, 6]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 6];};";
	};
	class B7 : B1 {
		y = 0.67;
		text = "";
		action = "CODEINPUT set [count CODEINPUT, 7]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 7];};";
	};
	class B8 : B7 {
		x = 0.52;
		text = "";
		action = "CODEINPUT set [count CODEINPUT, 8]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 8];};";
	};
	class B9 : B7 {
		x = 0.59;
		text = "";
		action = "CODEINPUT set [count CODEINPUT, 9]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 9];};";
	};

	class B0 : B8 {
		y = 0.77;
		text = "";
		action = "CODEINPUT set [count CODEINPUT, 0]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = []; } else { ctrlSetText [1099, (ctrlText 1099) + str 0]; };";
	};
	class BEnter : B9 {
		y = 0.77;
		text = "";
		action = "CODE = ctrlText (findDisplay 20900 displayCtrl 1099); closeDialog 0;";
	};
	class BAbort : B7 {
		y = 0.77;
		text = "";
		action = "CODE = """"; CODEINPUT = []; closeDialog 0;";
	};
	class KeypadImage {
		idc = -1;
		type = CT_STATIC;
		style = ST_PICTURE;
		colorText[] = { };
		colorBackground[] = { };
		font = "Zeppelin32";
		sizeEx = 0.023;
		x = 0.35; y = 0.2;
		w = 0.4; h = 0.8;
		text = "\origins_pack\structures\textures\pin_machine_co.paa";
	};
	class NumberDisplay {
		idc = 1099;
		type = CT_STATIC ; // defined constant
		style = ST_LEFT; // defined constant
		colorText[] = { 1, 0, 0, 1 };
		colorBackground[] = { 1, 1, 1, 0 };
		font = FontM; // defined constant
		sizeEx = 0.072;
		x = 0.44; y = 0.28;
		w = 0.21; h = 0.1;
		text = "";
	};
};

class ZadanieOrigins { 
	#define CT_STATIC	0
	#define CT_BUTTON	1
	#define CT_EDIT	2
	#define CT_SLIDER	3
	#define CT_COMBO	4
	#define CT_LISTBOX	5
	#define CT_TOOLBOX	6
	#define CT_CHECKBOXES	7
	#define CT_PROGRESS	8
	#define CT_HTML	9
	#define CT_STATIC_SKEW	10
	#define CT_ACTIVETEXT	11
	#define CT_TREE	12
	#define CT_STRUCTURED_TEXT	13
	#define CT_CONTEXT_MENU	14
	#define CT_CONTROLS_GROUP	15
	#define CT_XKEYDESC	40
	#define CT_XBUTTON	41
	#define CT_XLISTBOX	42
	#define CT_XSLIDER	43
	#define CT_XCOMBO	44
	#define CT_ANIMATED_TEXTURE	45
	#define CT_OBJECT	80
	#define CT_OBJECT_ZOOM	81
	#define CT_OBJECT_CONTAINER	82
	#define CT_OBJECT_CONT_ANIM	83
	#define CT_LINEBREAK	98
	#define CT_USER	99
	#define CT_MAP	100
	#define CT_MAP_MAIN	101
	#define ST_POS	0x0F
	#define ST_HPOS	0x03
	#define ST_VPOS	0x0C
	#define ST_LEFT	0x00
	#define ST_RIGHT	0x01
	#define ST_CENTER	0x02
	#define ST_DOWN	0x04
	#define ST_UP	0x08
	#define ST_VCENTER	0x0c
	#define ST_TYPE	0xF0
	#define ST_SINGLE	0
	#define ST_MULTI	16
	#define ST_TITLE_BAR	32
	#define ST_PICTURE	48
	#define ST_FRAME	64
	#define ST_BACKGROUND	80
	#define ST_GROUP_BOX	96
	#define ST_GROUP_BOX2	112
	#define ST_HUD_BACKGROUND	128
	#define ST_TILE_PICTURE	144
	#define ST_WITH_RECT	160
	#define ST_LINE	176
	#define ST_SHADOW	0x100
	#define ST_NO_RECT	0x200
	#define ST_KEEP_ASPECT_RATIO	0x800
	#define ST_TITLE	ST_TITLE_BAR + ST_CENTER
	#define SL_DIR	0x400
	#define SL_VERT	0
	#define SL_HORZ	0x400
	#define SL_TEXTURES	0x10
	#define LB_TEXTURES	0x10
	#define LB_MULTI	0x20
	#define FontM	"TahomaB"
	#define FontHTML	"TahomaB"
	//--- Ressources.
	class RscPictureZ {
		type = 0;
		style = 48;
		colorText[] = {0.75, 0.75, 0.75, 1};
		colorBackground[] = {0, 0, 0, 0};
		font = "Bitstream";
		sizeEx = 0.025;
		soundClick[] = {"", 0.2, 1};
		soundEnter[] = {"", 0.2, 1};
		soundEscape[] = {"", 0.2, 1};
		soundPush[] = {"", 0.2, 1};
		w = 0.275;
		h = 0.04;
		text = "";
	};
	class Ori_B_Zadanie	{
		type = 16;
		style = 0;
		default = false;
		x = 0.1;
		y = 0.1;
		w = 0.183825;
		h = 0.104575;
		color[] = {0.543, 0.5742, 0.4102, 1.0};
		color2[] = {0.95, 0.95, 0.95, 1};
		colorBackground[] = {1, 1, 1, 1};
		colorbackground2[] = {1, 1, 1, 1};
		colorDisabled[] = {1, 1, 1, 0.25};
		periodFocus = 1.2;
		periodOver = 0.8;

		class HitZone
		{
			left = 0.004;
			top = 0.009;
			right = 0.004;
			bottom = 0.009;
		};

		class ShortcutPos
		{
			left = 0.0145;
			top = 0.026;
			w = 0.0392157;
			h = 0.0522876;
		};

		class TextPos
		{
			left = 0.005;
			top = 0.01;
			right = 0.005;
			bottom = 0.005;
		};

		textureNoShortcut = "";
		animTextureNormal 	= "\origins_pack\ui\power_normal_ca.paa";
		animTextureDisabled = "\origins_pack\ui\power_normal_ca.paa";
		animTextureOver 	= "\origins_pack\ui\power_hover_ca.paa";
		animTextureFocused 	= "\origins_pack\ui\power_hover_ca.paa";
		animTexturePressed 	= "\origins_pack\ui\power_down_ca.paa";
		animTextureDefault 	= "\origins_pack\ui\power_normal_ca.paa";
		period = 0.4;
		font = "Zeppelin32";
		size = 0.05;
		sizeEx = 0.05;
		text = "";
		soundEnter[] = {"", 0.09, 1};
		soundPush[] = {"", 0.09, 1};
		soundClick[] = {"", 0.07, 1};
		soundEscape[] = {"", 0.09, 1};
		action = "";
		toolTip = "";

		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "center";
			shadow = "true";
		};

		class AttributesImage
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "center";
			shadow = "true";
		};
	};
	class RscListBoxZ {
		type = 5;
		canDrag = 0;
		style = 0 + 0x10;
		font = "Zeppelin32";
		sizeEx = 0.03221;
		rowHeight = 0.03;
		colorBackground[] = { 0.8, 0.8, 1, 0.3};
		color[] = {1, 1, 1, 1};
		colorText[] = {1, 1, 1, 0.65};
		colorScrollbar[] = {0.95, 0.95, 0.95, 1};
		colorSelect[] = {0.95, 0.95, 0.95, 1};
		colorSelect2[] = {0.95, 0.95, 0.95, 1};
		colorSelectBackground[] = {0.6, 0.8392, 0.4706, 0.3};
		colorSelectBackground2[] = {0.6, 0.8392, 0.4706, 0.3};
		columns[] = {0.02, 0.78, 0.1};
		period = 0;
		maxHistoryDelay = 1.0;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
		soundSelect[] = {"\ca\ui\data\sound\new1", 0.09, 1};
		
		class ScrollBar {
			color[] = {1, 1, 1, 0.6};
			colorActive[] = {1, 1, 1, 1};
			colorDisabled[] = {1, 1, 1, 0.3};
			thumb = "\ca\ui\data\igui_scrollbar_thumb_ca.paa";
			arrowFull = "\ca\ui\data\igui_arrow_top_active_ca.paa";
			arrowEmpty = "\ca\ui\data\igui_arrow_top_ca.paa";
			border = "\ca\ui\data\igui_border_scroll_ca.paa";
		};
	};
	class RscTextZ {
		type = 0;
		style = 0x02;
		
		colorText[] = {0, 1, 0.5, 1};
		//color[] = {1, 1, 1, 1};
		colorBackground[] = {1,0,0,0.5};
		font = FontM;
		sizeEx = 0.05;
		x = 0;
		y = 0;
		w = 0.1;
		h = 0.2;
	};
	class RscTextZ2 {
		type=CT_STATIC;
		idc=-1;
		access = 0;
		lineSpacing = 1;
		style=ST_MULTI+0x200;
		colorBackground[]={0, 0, 0, 0};
		colorText[]={1, 1, 1, 0.75};
		font="Zeppelin32";
		size = 0.029; 
		sizeEx=0.028;
		text="";
		
		class ScrollBar {
			color[] = {1, 1, 1, 0.6};
			colorActive[] = {1, 1, 1, 1};
			colorDisabled[] = {1, 1, 1, 0.3};
			thumb = "\ca\ui\data\igui_scrollbar_thumb_ca.paa";
			arrowFull = "\ca\ui\data\igui_arrow_top_active_ca.paa";
			arrowEmpty = "\ca\ui\data\igui_arrow_top_ca.paa";
			border = "\ca\ui\data\igui_border_scroll_ca.paa";
		};
	};
	movingEnable = false; 
	name = "ZadanieOrigins";
	idd = 10055;
	enableSimulation = true;
	controlsBackground[]={bg}; 
	objects[] = {};
	
	class controls {
		class listZadaniy : RscListBoxZ {
			idc = 10056;
			x = 0.165 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.20 * safezoneW;
			h = 0.181 * safezoneH;
		};
		class TextZadaniy : RscTextZ2 {
			idc = 10057;
			x = 0.364 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.365 * safezoneW;
			h = 0.419 * safezoneH;
			text = "tut text";
		};
		class ZakrZadan : Ori_B_Zadanie {
			idc=-1;
			x = 0.64 * safezoneW + safezoneX;
			y = 0.16 * safezoneH + safezoneY;
			w = 0.10 * safezoneW;
			h = 0.03 * safezoneH;
			size = 0.045;
			sizeEx = 0.045;
			text = "";
			action = "closeDialog 0;";
		};
		class zagolvok_zadanie : RscTextZ {
			idc = -1;
			x = 0.184  * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.17 * safezoneW;
			h = 0.04 * safezoneH;
			text = "Curent Missions:";
			size = 0.045;
			sizeEx = 0.045;
			colorText[] = {0.75, 0.75, 0.75, 0.8 };
			colorBackground[] = { 0, 0.128, 0, 0 };
		};
		class zagolvok_descr : RscTextZ {
			idc = -1;
			x = 0.45  * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.17 * safezoneW;
			h = 0.04 * safezoneH;
			text = "Description:";
			size = 0.045;
			sizeEx = 0.045;
			colorText[] = {0.75, 0.75, 0.75, 0.8 };
			colorBackground[] = { 0, 0.128, 0, 0 };
		};
	};
	class bg : RscPictureZ {
		idc = -1;
		x = 0.15  * safezoneW + safezoneX;
		y = 0.15  * safezoneH + safezoneY;
		w = 0.6 * safezoneW;
		h = 0.57 * safezoneH;
		text = "\origins_pack\ui\pager_ca.paa";
		colorBackground[] = { 0, 0.128, 0, 1 };
	};
};



class RscButtonActionMenu: RscButton
{
	SizeEx = 0.02674;
	colorBackground[] = {0.44,0.7,0.44,1};
	colorBackgroundActive[] = {0.24,0.5,0.24,1};
	colorBackgroundDisabled[] = {1,1,1,0};
	colorFocused[] = {0.2,0.5,0.2,1};
	colorShadow[] = {1,1,1,0};
	borderSize = 0;
	w = 0.115 * safezoneW;
	h = 0.025 * safezoneH;
};
class RscDisplayGenderSelect
{
	idd = 6902;
	enableDisplay = 1;
	class controls
	{
		class GenderPic_Man : RscActiveText
		{
			idc = -1;
			style = 48;
			text = "z\addons\dayz_code\gui\gender_menu_man.paa";
			x = 0.28 * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.117188 * safezoneW;
			h = 0.542373 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;dayz_selectGender = 'New_Random';";
		};
		class GenderPic_Woman : RscActiveText
		{
			idc = -1;
			style = 48;
			text = "z\addons\dayz_code\gui\gender_menu_woman.paa";
			x = 0.6 * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.117188 * safezoneW;
			h = 0.542373 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;dayz_selectGender = 'New_Random2';";
		};
		class Gender_Title: RscStructuredText
		{
			idc = -1;
			text = "$STR_UI_GENDER_TITLE";
			x = 0.4 * safezoneW + safezoneX;
			y = 0.221864 * safezoneH + safezoneY;
			w = 0.2 * safezoneW;
			h = 0.05 * safezoneH;
			colorBackground[] = {-1,-1,-1,0};
		};
		class Gender_Description: RscStructuredText
		{
			idc = -1;
			text = "$STR_UI_GENDER_DESC";
			x = 0.4 * safezoneW + safezoneX;
			y = 0.366134 * safezoneH + safezoneY;
			w = 0.2 * safezoneW;
			h = 0.3 * safezoneH;
			colorBackground[] = {-1,-1,-1,0};
		};
	};
};

class RscDisplaySpawnlocationSelect {
	idd = 6903;
	enableDisplay = 1;
	class controls
	{
		class RscSelectedRegion1 : RscActiveText
		{
			idc = -1;
			style = 48;
			text = "\origins_pack\ui\ui_kameni_co.paa";
			x = 0.19 * safezoneW + safezoneX;
			y = 0.05 * safezoneH + safezoneY;
			w = 0.190 * safezoneW;
			h = 0.390 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;dayz_selectRegion = 0;";
		};
		class RscSelectedRegion2 : RscActiveText
		{
			idc = -1;
			style = 48;
			text = "\origins_pack\ui\ui_mitrovice_co.paa";
			x = 0.40 * safezoneW + safezoneX;
			y = 0.05 * safezoneH + safezoneY;
			w = 0.190 * safezoneW;
			h = 0.390 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;dayz_selectRegion = 1;";
		};
		class RscSelectedRegionR : RscActiveText
		{
			idc = -1;
			style = 48;
			text = "\origins_pack\ui\ui_random_co.paa";
			x = 0.61 * safezoneW + safezoneX;
			y = 0.05 * safezoneH + safezoneY;
			w = 0.190 * safezoneW;
			h = 0.390 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;dayz_selectRegion = 2;";
		};
		class RscSelectedRegion4 : RscActiveText
		{
			idc = -1;
			style = 48;
			text = "\origins_pack\ui\ui_seven_co.paa";
			x = 0.19 * safezoneW + safezoneX;
			y = 0.46 * safezoneH + safezoneY;
			w = 0.190 * safezoneW;
			h = 0.390 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;dayz_selectRegion = 3;";
		};
		class RscSelectedRegion5 : RscActiveText
		{
			idc = -1;
			style = 48;
			text = "\origins_pack\ui\ui_byelov_co.paa";
			x = 0.40 * safezoneW + safezoneX;
			y = 0.46 * safezoneH + safezoneY;
			w = 0.190 * safezoneW;
			h = 0.390 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;dayz_selectRegion = 4;";
		};
		class RscSelectedRegion6 : RscActiveText
		{
			idc = -1;
			style = 48;
			text = "\origins_pack\ui\ui_etanovsk_co.paa";
			x = 0.61 * safezoneW + safezoneX;
			y = 0.46 * safezoneH + safezoneY;
			w = 0.190 * safezoneW;
			h = 0.390 * safezoneH;
			color[] = { 0.5, 0.5, 0.5, 1 };
			colorActive[] = { 1, 1, 1, 1 };
			action = "closeDialog 0;dayz_selectRegion = 5;";
		};
		
	};
};

class RscDisplayGear
{
	idd = 106;
	enableDisplay = 1;
	onUnload = "call player_gearSync;";
	class controls
	{
		class CA_Filter_Icon: RscPicture
		{
			idc = 148;
			style = "0x30 + 0x800";
			x = 0.04;
			y = 0.544098;
			w = 0.458;
			h = 0.075;
			text = "\ca\ui\data\igui_gear_filter_1_ca.paa";
		};
		class CA_Filter_Left_Icon: RscPicture
		{
			idc = 1301;
			style = "0x30 + 0x800";
			x = 0.05;
			y = 0.545098;
			w = 0.036;
			h = 0.075;
			text = "\ca\ui\data\arrow_left_ca.paa";
		};
		class CA_Filter_Right_Icon: RscPicture
		{
			idc = 1302;
			style = "0x30 + 0x800";
			x = 0.453;
			y = 0.545098;
			w = 0.036;
			h = 0.075;
			text = "\ca\ui\data\arrow_right_ca.paa";
		};
		class CA_Filter_Arrow_Left: RscButton
		{
			idc = 150;
			colorText[] = {1,1,1,0};
			colorDisabled[] = {1,1,1,0};
			colorBackground[] = {1,1,1,0};
			colorBackgroundDisabled[] = {1,1,1,0};
			colorBackgroundActive[] = {1,1,1,0};
			colorShadow[] = {1,1,1,0};
			colorFocused[] = {1,1,1,0};
			x = 0.041;
			y = 0.545098;
			w = 0.056;
			h = 0.075;
			text = "";
		};
		class CA_Filter_Arrow_Right: RscButton
		{
			idc = 151;
			colorText[] = {1,1,1,0};
			colorDisabled[] = {1,1,1,0};
			colorBackground[] = {1,1,1,0};
			colorBackgroundDisabled[] = {1,1,1,0};
			colorBackgroundActive[] = {1,1,1,0};
			colorShadow[] = {1,1,1,0};
			colorFocused[] = {1,1,1,0};
			x = 0.443;
			y = 0.545098;
			w = 0.056;
			h = 0.075;
			text = "";
		};
		class CA_Filter_Icon1: RscButton
		{
			idc = 149;
			colorText[] = {1,1,1,0};
			colorDisabled[] = {1,1,1,0};
			colorBackground[] = {1,1,1,0};
			colorBackgroundDisabled[] = {1,1,1,0};
			colorBackgroundActive[] = {1,1,1,0};
			colorShadow[] = {1,1,1,0};
			colorFocused[] = {1,1,1,0};
			x = 0.099;
			y = 0.545098;
			w = 0.341;
			h = 0.075;
			text = "";
		};
		class Gear_Title: CA_IGUI_Title
		{
			idc = 1001;
			x = 0.047634;
			y = -0.00102941;
			text = "Gear";
		};
		class Unit_Title: RscText
		{
			idc = 101;
			style = 2;
			x = 0.502419;
			y = 0.0492156;
			w = 0.456;
		};
		class Available_items_Text: RscText
		{
			idc = 156;
			x = 0.0433014;
			y = 0.0526966;
			w = 0.389709;
			h = 0.029412;
		};
		class CA_ItemName: Available_items_Text
		{
			idc = 1101;
			x = 0.0416704;
			y = 0.627451;
			text = "Gear of the unit:";
		};
		class CA_Money: RscText
		{
			idc = 1102;
			style = 1;
			show = 0;
			x = -2.50409;
			y = -2.85784;
			w = 0.228;
			text = "Money:";
		};
		class CA_Money_Value: RscText
		{
			idc = 1103;
			x = -2.72794;
			y = -2.85784;
			w = 0.228;
			text = "0";
		};
		class ListboxArrows: RscControlsGroup
		{
			x = 0.04;
			y = 0.0892447;
			w = 0.48;
			h = 0.449;
			idc = 155;
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class CA_B_Add: RscGearShortcutButton
				{
					idc = 146;
					x = -2;
					style = 2048;
					onSetFocus = "private [""_dummy""]; _dummy = [_this,""onFocus""] execVM	""\ca\ui\scripts\handleGear.sqf""; _dummy;";
					onButtonClick = "private [""_dummy""]; _dummy = [_this,""onLBListSelChanged""] execVM ""\ca\ui\scripts\handleGear.sqf""; _dummy;";
					text = "&lt;";
				};
				class Available_items: RscIGUIListNBox
				{
					idc = 105;
					columns[] = {0.075,0.175,0.81,0.67};
					drawSideArrows = 1;
					idcRight = 147;
					idcLeft = 146;
					colorPlayerItem[] = {0.8784,0.8471,0.651,1};
					onKeyDown = "private [""_dummy""]; _dummy = [_this,""onKeyDown"",0,107,0,107] execVM	""\ca\ui\scripts\handleGear.sqf""; _dummy;";
					onLBSelChanged = "private [""_dummy""]; _dummy = [_this,""onLBSelChanged""] execVM ""\ca\ui\scripts\handleGear.sqf""; _dummy;";
					onLBListSelChanged = "private [""_dummy""]; _dummy = [_this,""onLBListSelChanged""] execVM ""\ca\ui\scripts\handleGear.sqf""; _dummy;";
					onKillFocus = "private [""_dummy""]; _dummy = [_this,""onKillFocus""] execVM	""\ca\ui\scripts\handleGear.sqf""; _dummy;";
					x = 0;
					y = 0;
					w = 0.46;
					h = 0.449;
					canDrag = 1;
				};
				class CA_B_Remove: CA_B_Add
				{
					idc = 147;
					x = -2;
					onSetFocus = "private [""_dummy""]; _dummy = [_this,""onFocus""] execVM ""\ca\ui\scripts\handleGear.sqf""; _dummy;";
					onButtonClick = "private [""_dummy""]; _dummy = [_this,""onLBListSelChanged""] execVM ""\ca\ui\scripts\handleGear.sqf""; _dummy;";
					text = ">";
				};
			};
		};
		class CA_CustomDescription: RscStructuredText
		{
			idc = 1106;
			x = 0.0414969;
			y = 0.663641;
			w = 0.458;
			h = 0.152;
			colorText[] = {0.95,0.95,0.95,1};
			class Attributes
			{
				font = "Zeppelin32";
				color = "#F2F2F2";
				align = "left";
				shadow = 1;
			};
		};
		class CA_Item_Picture: RscPicture
		{
			idc = 1104;
			style = "0x30 + 0x800";
			x = 0.330883;
			y = 0.785541;
			w = 0.156863;
			h = 0.104575;
			text = "";
		};
		class G_Interaction: RscControlsGroup
		{
			idc = 6902;
			x = 0.502;
			y = 0.250 * safezoneH;
			w = 0.145 * safezoneW;
			h = 0; //0.250 * safezoneH;
			onMouseMoving = "_this call gear_ui_offMenu;";
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class RscButton_1600: RscButtonActionMenu
				{
					idc = 1600;
					text = "";
					x = 0;
					y = 0 * safezoneH;
				};
				class RscButton_1601: RscButtonActionMenu
				{
					idc = 1601;
					text = "";
					x = 0;
					y = 0.025 * safezoneH;
				};
				class RscButton_1602: RscButtonActionMenu
				{
					idc = 1602;
					text = "";
					x = 0;
					y = 0.05 * safezoneH;
				};
				class RscButton_1603: RscButtonActionMenu
				{
					idc = 1603;
					text = "";
					x = 0;
					y = 0.075 * safezoneH;
				};
				class RscButton_1604: RscButtonActionMenu
				{
					idc = 1604;
					text = "";
					x = 0;
					y = 0.1 * safezoneH;
				};
				class RscButton_1605: RscButtonActionMenu
				{
					idc = 1605;
					text = "";
					x = 0;
					y = 0.125 * safezoneH;
				};
				class RscButton_1606: RscButtonActionMenu
				{
					idc = 1606;
					text = "";
					x = 0;
					y = 0.15 * safezoneH;
				};
				class RscButton_1607: RscButtonActionMenu
				{
					idc = 1607;
					text = "";
					x = 0;
					y = 0.175 * safezoneH;
				};
				class RscButton_1608: RscButtonActionMenu
				{
					idc = 1608;
					text = "";
					x = 0;
					y = 0.2 * safezoneH;
				};
				class RscButton_1609: RscButtonActionMenu
				{
					idc = 1609;
					text = "";
					x = 0;
					y = 0.225 * safezoneH;
				};
			};
		};
		class G_GearItems: RscControlsGroup
		{
			idc = 160;
			x = 0.502;
			y = 0.09;
			w = 0.463;
			h = 0.776;
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class CA_Gear_slot_primary: RscActiveText
				{
					idc = 107;
					x = "0.502 - 0.502";
					y = "0.244 - 0.09";
					w = 0.286;
					h = 0.15;
					style = "0x30 + 0x800";
					onMouseButtonDown = "_this call player_selectSlot;";
					soundDoubleClick[] = {"",0.1,1};
					color[] = {1,1,1,1};
					colorBackground[] = {0.8784,0.8471,0.651,1};
					colorBackgroundSelected[] = {0.8784,0.8471,0.651,1};
					colorFocused[] = {0,0,0,0};
					canDrag = 1;
				};
				class CA_Gear_slot_secondary: CA_Gear_slot_primary
				{
					idc = 108;
					y = "0.398 -0.09";
				};
				class CA_Gear_slot_item1: CA_Gear_slot_primary
				{
					idc = 109;
					x = "0.790 - 0.502";
					y = "0.244 - 0.09";
					w = 0.055;
					h = 0.074;
				};
				class CA_Gear_slot_item2: CA_Gear_slot_item1
				{
					idc = 110;
					x = "0.847 - 0.502";
					y = "0.244 - 0.09";
				};
				class CA_Gear_slot_item3: CA_Gear_slot_item1
				{
					idc = 111;
					x = "0.904366 - 0.502";
					y = "0.244 - 0.09";
				};
				class CA_Gear_slot_item4: CA_Gear_slot_item1
				{
					idc = 112;
					x = "0.790 - 0.502";
					y = "0.321 - 0.09";
				};
				class CA_Gear_slot_item5: CA_Gear_slot_item1
				{
					idc = 113;
					x = "0.847 - 0.502";
					y = "0.321 - 0.09";
				};
				class CA_Gear_slot_item6: CA_Gear_slot_item1
				{
					idc = 114;
					x = "0.904366 - 0.502";
					y = "0.321 - 0.09";
				};
				class CA_Gear_slot_item7: CA_Gear_slot_item1
				{
					idc = 115;
					x = "0.790 - 0.502";
					y = "0.398 - 0.09";
				};
				class CA_Gear_slot_item8: CA_Gear_slot_item7
				{
					idc = 116;
					x = "0.847 - 0.502";
					y = "0.398 - 0.09";
				};
				class CA_Gear_slot_item9: CA_Gear_slot_item7
				{
					idc = 117;
					x = "0.904366 - 0.502";
					y = "0.398 - 0.09";
				};
				class CA_Gear_slot_item10: CA_Gear_slot_item7
				{
					idc = 118;
					x = "0.790 - 0.502";
					y = "0.474 - 0.09";
				};
				class CA_Gear_slot_item11: CA_Gear_slot_item7
				{
					idc = 119;
					x = "0.847 - 0.502";
					y = "0.474 - 0.09";
				};
				class CA_Gear_slot_item12: CA_Gear_slot_item7
				{
					idc = 120;
					x = "0.904366 - 0.502";
					y = "0.474 - 0.09";
				};
				class CA_Gear_slot_handgun: CA_Gear_slot_primary
				{
					idc = 121;
					x = "0.560 - 0.502";
					y = "0.551 - 0.09";
					w = 0.113;
					h = 0.15;
				};
				class CA_Gear_slot_handgun_item1: CA_Gear_slot_item1
				{
					idc = 122;
					x = "0.674 - 0.502";
					y = "0.551 - 0.09";
					w = 0.055;
					h = 0.074;
				};
				class CA_Gear_slot_handgun_item2: CA_Gear_slot_handgun_item1
				{
					idc = 123;
					x = "0.733 - 0.502";
					y = "0.551 - 0.09";
				};
				class CA_Gear_slot_handgun_item3: CA_Gear_slot_handgun_item1
				{
					idc = 124;
					x = "0.790 - 0.502";
				};
				class CA_Gear_slot_handgun_item4: CA_Gear_slot_handgun_item1
				{
					idc = 125;
					x = "0.847 - 0.502";
				};
				class CA_Gear_slot_handgun_item5: CA_Gear_slot_handgun_item1
				{
					idc = 126;
					x = "0.674 - 0.502";
					y = "0.628 - 0.09";
				};
				class CA_Gear_slot_handgun_item6: CA_Gear_slot_handgun_item5
				{
					idc = 127;
					x = "0.733 - 0.502";
					y = "0.628 - 0.09";
				};
				class CA_Gear_slot_handgun_item7: CA_Gear_slot_handgun_item5
				{
					idc = 128;
					x = "0.790 - 0.502";
					y = "0.628 - 0.09";
				};
				class CA_Gear_slot_handgun_item8: CA_Gear_slot_handgun_item5
				{
					idc = 129;
					x = "0.847 - 0.502";
					y = "0.628 - 0.09";
				};
				class CA_Gear_slot_special1: CA_Gear_slot_item1
				{
					idc = 130;
					x = "0.502 - 0.502";
					y = "0.09 - 0.09";
					w = 0.113;
					h = 0.15;
				};
				class CA_Gear_slot_special2: CA_Gear_slot_special1
				{
					idc = 131;
					x = "0.847 - 0.502";
					y = "0.09 - 0.09";
					w = 0.113;
					h = 0.15;
				};
				class CA_Gear_slot_inventory1: CA_Gear_slot_special1
				{
					idc = 134;
					x = "0.560 - 0.502";
					y = "0.705 - 0.09";
					w = 0.055;
					h = 0.074;
				};
				class CA_Gear_slot_inventory2: CA_Gear_slot_inventory1
				{
					idc = 135;
					x = "0.617 - 0.502";
					y = "0.705 - 0.09";
				};
				class CA_Gear_slot_inventory3: CA_Gear_slot_inventory1
				{
					idc = 136;
					x = "0.674 - 0.502";
					y = "0.705 - 0.09";
				};
				class CA_Gear_slot_inventory4: CA_Gear_slot_inventory1
				{
					idc = 137;
					x = "0.733 - 0.502";
					y = "0.705 - 0.09";
				};
				class CA_Gear_slot_inventory5: CA_Gear_slot_inventory1
				{
					idc = 138;
					x = "0.790 - 0.502";
					y = "0.705 - 0.09";
				};
				class CA_Gear_slot_inventory6: CA_Gear_slot_inventory1
				{
					idc = 139;
					x = "0.847 - 0.502";
					y = "0.705 - 0.09";
				};
				class CA_Gear_slot_inventory7: CA_Gear_slot_inventory1
				{
					idc = 140;
					x = "0.560 - 0.502";
					y = "0.782 - 0.09";
				};
				class CA_Gear_slot_inventory8: CA_Gear_slot_inventory7
				{
					idc = 141;
					x = "0.617 - 0.502";
					y = "0.782 - 0.09";
				};
				class CA_Gear_slot_inventory9: CA_Gear_slot_inventory7
				{
					idc = 142;
					x = "0.674 - 0.502";
					y = "0.782 - 0.09";
				};
				class CA_Gear_slot_inventory10: CA_Gear_slot_inventory7
				{
					idc = 143;
					x = "0.733 - 0.502";
					y = "0.782 - 0.09";
				};
				class CA_Gear_slot_inventory11: CA_Gear_slot_inventory7
				{
					idc = 144;
					x = "0.790 - 0.502";
					y = "0.782 - 0.09";
				};
				class CA_Gear_slot_inventory12: CA_Gear_slot_inventory7
				{
					idc = 145;
					x = "0.847 - 0.502";
					y = "0.782 - 0.09";
				};
				class CA_Gear_slot_inventory13: CA_Gear_slot_inventory7
				{
					idc = 1122;
					x = 10.1;
					y = 10.1;
				};
			};
		};
		class BagItemsGroup: RscControlsGroup
		{
			x = 0.502;
			y = 0.09;
			w = 0.463;
			h = 0.776;
			idc = 159;
			magW = 0.055;
			magH = 0.074;
			weaponW = 0.226;
			weaponH = 0.15;
			gunW = 0.113;
			gunH = 0.15;
			spacing = 0.002;
			text = "";
			color[] = {1,1,1,1};
			colorBackground[] = {1,1,1,1};
			colorBackgroundSelected[] = {1,1,1,1};
			colorFocused[] = {1,1,1,1};
			soundPush[] = {"",0.1,1};
			soundClick[] = {"",0.1,1};
			soundDoubleClick[] = {"",0.1,1};
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class ScrollBar
			{
				color[] = {1,1,1,0.6};
				colorActive[] = {1,1,1,1};
				colorDisabled[] = {1,1,1,0.3};
				thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
				arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
				arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
				border = "\ca\ui\data\ui_border_scroll_ca.paa";
			};
			class Controls
			{
			};
		};
		class Break_7: RscLineBreak
		{
		};
		class ButtonFilters: RscIGUIShortcutButton
		{
			idc = 148;
			shortcuts[] = {"0x00050000 + 3"};
			x = 0.333336;
			y = 0.897067;
			text = "Filter";
		};
		class ButtonRearm: RscIGUIShortcutButton
		{
			idc = 132;
			shortcuts[] = {"0x00050000 + 2"};
			x = 0.554743;
			y = 0.897067;
			text = "Rearm";
		};
		class ButtonOpenBag: RscIGUIShortcutButton
		{
			idc = 157;
			shortcuts[] = {"0x00050000 + 2"};
			x = 0.554743;
			y = 0.897067;
			text = "Open bag";
		};
		class ButtonCloseBag: RscIGUIShortcutButton
		{
			idc = 158;
			shortcuts[] = {"0x00050000 + 2"};
			x = 0.554743;
			y = 0.897067;
			text = "Close bag";
		};
		class ButtonContinue: RscIGUIShortcutButton
		{
			idc = 1;
			shortcuts[] = {"0x00050000 + 0",28,57,156};
			x = 0.77615;
			y = 0.897066;
			default = 1;
		};
		class ButtonClose: RscIGUIShortcutButton
		{
			idc = 2;
			shortcuts[] = {"0x00050000 + 1"};
			x = 0.0392216;
			y = 0.897066;
			text = "Close";
		};
	};
	class Filters
	{
		class All
		{
			name = "All";
			mask = -1;
			image = "\ca\ui\data\igui_gear_filter_1_ca.paa";
		};
		class Primary
		{
			name = "Primary";
			mask = 769;
			image = "\ca\ui\data\igui_gear_filter_2_ca.paa";
		};
		class Secondary
		{
			name = "Secondary";
			mask = 516;
			image = "\ca\ui\data\igui_gear_filter_3_ca.paa";
		};
		class HandGun
		{
			name = "HandGun";
			mask = 18;
			image = "\ca\ui\data\igui_gear_filter_4_ca.paa";
		};
		class Items
		{
			name = "Items";
			mask = 135168;
			image = "\ca\ui\data\igui_gear_filter_5_ca.paa";
		};
	};
	movingEnable = 1;
	emptyGun = "\ca\ui\data\ui_gear_gun_gs.paa";
	emptySec = "\ca\ui\data\ui_gear_sec_gs.paa";
	emptyEq = "\ca\ui\data\ui_gear_eq_gs.paa";
	emptyMag = "\ca\ui\data\ui_gear_mag_gs.paa";
	emptyMag2 = "\ca\ui\data\ui_gear_mag2_gs.paa";
	emptyHGun = "\ca\ui\data\ui_gear_hgun_gs.paa";
	emptyHGunMag = "\ca\ui\data\ui_gear_hgunmag_gs.paa";
	onLoad = "call gear_ui_init;if (isNil('IGUI_GEAR_activeFilter')) then { IGUI_GEAR_activeFilter = 0;}; private ['_dummy']; _dummy = [_this,'initDialog'] call compile preprocessFile	'\ca\ui\scripts\handleGear.sqf'; _dummy = [_this,'onLoad'] execVM	'\ca\ui\scripts\handleGear.sqf'; _dummy;";
	class ControlsBackground
	{
		class Mainback: RscPicture
		{
			idc = 1005;
			x = 0.04;
			y = 0.01;
			w = 1.2549;
			h = 1.6732;
			moving = 1;
			text = "\ca\ui\data\igui_background_gear_ca.paa";
		};
	};
};
class DZ_ItemInteraction {
	idd = 6901;
	movingEnable = 0;
	class controlsBackground { 
		// define controls here
	};
	class objects { 
		// define controls here
	};
	class controls { 
		// define controls here

	};
};

class RscTitles
{
	class Default
	{
		idd = -1;
		movingEnable = 0;
		duration = 4;
	};
	class playerKillScore 
	{
		idd = 6902;
		movingEnable = 0;
		duration = 5;
		name = "playerKillScore";
		onLoad = "uiNamespace setVariable ['DAYZ_GUI_kills', _this select 0];";
		class ControlsBackground {
			class RscPicture_1201: RscPictureGUI
			{
				idc = 1400;
				text = "\z\addons\dayz_code\gui\stats_kills_human_ca.paa";
				x = 0.044687 * safezoneW + safezoneX;
				y = 0.934779 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1200: RscPictureGUI
			{
				idc = 1401;
				text = "\z\addons\dayz_code\gui\stats_kills_zombie_ca.paa";
				x = 0.044687 * safezoneW + safezoneX;
				y = 0.876025 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
		};
		class Controls{
			class RscText1: RscStructuredTextGUI
			{
				idc = 1410;
				text = "0";
				x = (0.044687 * safezoneW + safezoneX) - 0.01;
				y = 0.934779 * safezoneH + safezoneY;
				w = 0.08;
				h = 0.08;
			};
			class RscText2: RscStructuredTextGUI
			{
				idc = 1411;
				text = "0";
				x = (0.044687 * safezoneW + safezoneX) - 0.01;
				y = 0.876025 * safezoneH + safezoneY;
				w = 0.08;
				h = 0.08;
			};
		};
	};
	
	class playerStatusWaiting
	{
		idd = 6901;
		movingEnable = 0;
		duration = 100000;
		name = "playerStatusWaiting";
		onLoad = "uiNamespace setVariable ['DAYZ_GUI_waiting', _this select 0];";
		class ControlsBackground {
			class RscText_1402: RscPicture
			{
				idc = 1402;
				text = "#(argb,8,8,3)color(1,1,1,1)";
				x = 0.48 * safezoneW + safezoneX;
				y = 0.42 * safezoneH + safezoneY;
				w = 0.052 * safezoneW;
				h = 0.133 * safezoneH;
				colorText[] = {1,1,1,1};
			};
			class RscText_1400: RscPicture
			{
				idc = 1400;
				text = "#(argb,8,8,3)color(1,1,1,1)";
				x = 0.48 * safezoneW + safezoneX;
				y = 0.42 * safezoneH + safezoneY;
				w = 0.052 * safezoneW;
				h = 0; //0.133 * safezoneH;
				colorText[] = {0,0,0,1};
			};
		};
		class Controls {
			class RscPicture_1401: RscPictureGUI
			{
				idc = 1401;
				text = "\z\addons\dayz_code\gui\status_waiting_ca.paa";
				x = 0.434999 * safezoneW + safezoneX;
				y = 0.392207 * safezoneH + safezoneY;
				w = 0.141 * safezoneW;
				h = 0.188013 * safezoneH;
				colorText[] = {0.38,0.63,0.26,1};
			};
		};
	};

	class playerStatusGUI
	{
		idd = 6900;
		movingEnable = 0;
		duration = 100000;
		name = "statusBorder";
		onLoad = "uiNamespace setVariable ['DAYZ_GUI_display', _this select 0];";
		class ControlsBackground {
			class RscPicture_1200: RscPictureGUI
			{
				idc = 1200;
				text = "\z\addons\dayz_code\gui\status_blood_border_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.859 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
				colorText[] = {1,1,1,0.4};
			};
			class RscPicture_1201: RscPictureGUI
			{
				idc = 1201;
				text = "\z\addons\dayz_code\gui\status_food_border_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.929 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
				colorText[] = {1,1,1,0.4};
			};
			class RscPicture_1202: RscPictureGUI
			{
				idc = 1202;
				text = "\z\addons\dayz_code\gui\status_thirst_border_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.789 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
				colorText[] = {1,1,1,0.4};
			};
			class RscPicture_1203: RscPictureGUI
			{
				idc = 1203;
				text = "\z\addons\dayz_code\gui\status_fracture_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.579 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
				colorText[] = {1,1,1,0.7};
			};
			class RscPicture_1204: RscPictureGUI
			{
				idc = 1204;
				text = "\z\addons\dayz_code\gui\status_connection_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.509 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
				colorText[] = {1,1,1,0.4};
			};/*
			class RscPicture_1205: RscPictureGUI
			{
				idc = 1205;
				text = "\origins_pack\ui\gui\ico_quest_yellow.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.439 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
				colorText[] = {1,1,1,0.4};
			};
			class RscPicture_1206: RscPictureGUI
			{
				idc = 1206;
				text = "\origins_pack\ui\gui\st_humanity_survivor.paa";
				x = 0.959313 * safezoneW + safezoneX;
				y = 0.16 * safezoneH + safezoneY;
				w = 0.037 * safezoneW;
				h = 0.047 * safezoneH;
				colorText[] = {1,1,1,0.7};
			};*/
			class RscPicture_1207: RscPictureGUI {
				idc = 1207;
				text = "\z\addons\dayz_code\gui\status_combat_border_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.649 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
				colorText[] = {1,1,1,0.4};
			};
			class RscPicture_1208: RscPictureGUI
			{
				idc = 1208;
				text = "\z\addons\dayz_code\gui\status_temp_outside_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.719 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
				colorText[] = {1,1,1,0.4};
			};/*
			class RscPicture_1209: RscPictureGUI
			{
				idc = 1209;
				text = "\origins_pack\ui\gui\st_humanity_hero.paa";
				x = 0.959313 * safezoneW + safezoneX;
				y = 0.202 * safezoneH + safezoneY;
				w = 0.037 * safezoneW;
				h = 0.047 * safezoneH;
				colorText[] = {1,1,1,0.75};
			};
			class RscPicture_1210: RscPictureGUI
			{
				idc = 1210;
				text = "\origins_pack\ui\gui\st_humanity_bandit.paa";
				x = 0.959313 * safezoneW + safezoneX;
				y = 0.246 * safezoneH + safezoneY;
				w = 0.037 * safezoneW;
				h = 0.047 * safezoneH;
				colorText[] = {1,1,1,0.75};
			};
			class RscPicture_1211: RscPictureGUI
			{
				idc = 1211;
				text = "\origins_pack\ui\gui\zombie.paa";
				x = 0.959313 * safezoneW + safezoneX;
				y = 0.288 * safezoneH + safezoneY;
				w = 0.037 * safezoneW;
				h = 0.047 * safezoneH;
				colorText[] = {1,1,1,0.75};
			};*/
			class RscPicture_1501: RscPictureGUI
			{
				idc = 1501;
				//text = "\z\addons\dayz_code\gui\status_food_border_ca.paa";
				x = 0.945313 * safezoneW + safezoneX;
				y = 0.95 * safezoneH + safezoneY; //1
				w = 0.04;
				h = 0.053333;
			};
			class RscPicture_1502: RscPictureGUI
			{
				idc = 1502;
				//text = "\z\addons\dayz_code\gui\status_thirst_border_ca.paa";
				x = 0.945313 * safezoneW + safezoneX;
				y = 0.816666 * safezoneH + safezoneY; //3
				w = 0.04;
				h = 0.053333;
			};
		};
		class Controls{
			class RscPicture_1300: RscPictureGUI
			{
				idc = 1300;
				text = "\z\addons\dayz_code\gui\status_blood_inside_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.859 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
			};
			class RscPicture_1301: RscPictureGUI
			{
				idc = 1301;
				text = "\z\addons\dayz_code\gui\status_food_inside_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.929 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
			};
			class RscPicture_1302: RscPictureGUI
			{
				idc = 1302;
				text = "\z\addons\dayz_code\gui\status_thirst_inside_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.789 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
			};
			class RscPicture_1303: RscPictureGUI
			{
				idc = 1303;
				text = "\z\addons\dayz_code\gui\status_bleeding_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.859 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
				colorText[] = {1,1,1,0.5};
			};
			class RscPicture_1304: RscPictureGUI
			{
				idc = 1304;
				text = "";
				x = 0.935313 * safezoneW + safezoneX;
				y = 0.3 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1305: RscPictureGUI
			{
				idc = 1305;
				text = "";
				x = 0.935313 * safezoneW + safezoneX;
				y = 0.37 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1306: RscPictureGUI
			{
				idc = 1306;
				text = "\z\addons\dayz_code\gui\status_temp_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.719 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
			};
			class RscPicture_1307 : RscPictureGUI 
			{
				idc = 1307;
				text = "\z\addons\dayz_code\gui\status_combat_inside_ca.paa";
				x = 0.954235 * safezoneW + safezoneX;
				y = 0.649 * safezoneH + safezoneY;
				w = 0.0435 * safezoneW;
				h = 0.0535 * safezoneH;
			};/*
			class RscPicture_1308 : RscPictureGUI 
			{
				idc = 1308;
				text = "\origins_pack\ui\gui\status_humanity_inside_survivor.paa";
				x = 0.929 * safezoneW + safezoneX;
				y = 0.06 * safezoneH + safezoneY;
				w = 0.068 * safezoneW;
				h = 0.088 * safezoneH;
				colorText[] = {1,1,1,1};
			};*/
			/*
			class RscText_1309: RscTextGUIK
			{
				idc = 1309;
				text = "0";
				x = 0.937 * safezoneW + safezoneX;
				y = 0.16 * safezoneH + safezoneY;
				w = 0.037 * safezoneW;
				h = 0.047 * safezoneH;
				colorText[] = {1,1,1,0.75};
			};
			class RscText_1310: RscTextGUIK
			{
				idc = 1310;
				text = "0";
				x = 0.937 * safezoneW + safezoneX;
				y = 0.202 * safezoneH + safezoneY;
				w = 0.037 * safezoneW;
				h = 0.047 * safezoneH;
				colorText[] = {1,1,1,0.75};
			};
			class RscText_1311: RscTextGUIK
			{
				idc = 1311;
				text = "3";
				x = 0.937 * safezoneW + safezoneX;
				y = 0.246 * safezoneH + safezoneY;
				w = 0.037 * safezoneW;
				h = 0.047 * safezoneH;
				colorText[] = {1,1,1,0.75};
			};
			class RscText_1312: RscTextGUIK
			{
				idc = 1312;
				text = "4";
				x = 0.937 * safezoneW + safezoneX;
				y = 0.288 * safezoneH + safezoneY;
				w = 0.037 * safezoneW;
				h = 0.047 * safezoneH;
				colorText[] = {1,1,1,0.75};
			};
			*//*
			class RscPicture_1313: RscPictureGUI
			{
				idc = 1313;
				text = "\origins_pack\ui\gui\status_humanity_border.paa";
				x = 0.929 * safezoneW + safezoneX;
				y = 0.07 * safezoneH + safezoneY;
				w = 0.068 * safezoneW;
				h = 0.085 * safezoneH;
				colorText[] = {1,1,1,0.3};
			};*/
			/*
			class RscText_1314: RscTextGUIK
			{
				idc = 1314;
				text = "2500";
				x = 0.944 * safezoneW + safezoneX;
				y = 0.122 * safezoneH + safezoneY;
				w = 0.037 * safezoneW;
				h = 0.047 * safezoneH;
				size = 0.0275;
				sizeEx = 0.0275;
				colorText[] = {1,1,1,0.85};
			};
			*/
			class RscPicture_1701: RscPictureGUI
			{
				idc = 1701;
				//text = "\z\addons\dayz_code\gui\status_food_inside_ca.paa";
				x = 0.945313 * safezoneW + safezoneX;
				y = 0.95 * safezoneH + safezoneY;
				w = 0.04;
				h = 0.053333;
			};
			class RscPicture_1702: RscPictureGUI
			{
				idc = 1702;
				//text = "\z\addons\dayz_code\gui\status_thirst_inside_ca.paa";
				x = 0.945313 * safezoneW + safezoneX;
				y = 0.816666 * safezoneH + safezoneY;
				w = 0.04;
				h = 0.053333;
			};
		};
	};
};
