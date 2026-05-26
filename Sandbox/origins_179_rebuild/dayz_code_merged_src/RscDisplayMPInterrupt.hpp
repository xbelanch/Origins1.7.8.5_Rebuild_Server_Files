class RscShortcutButtonMainOri : RscShortcutButton
{
	idc = -1;
	style = 0;
	default = 0;
	w = 0.3137255;
	h = 0.1045752;
	color[] = {0.8784,0.8471,0.651,1.0};
	colorDisabled[] = {1,1,1,0.25};
	class HitZone
	{
		left = 0.0;
		top = 0.0;
		right = 0.0;
		bottom = 0.0;
	};
	class ShortcutPos
	{
		left = 0.0204;
		top = 0.026;
		w = 0.0392157;
		h = 0.0522876;
	};
	class TextPos
	{
		left = 0.08;
		top = 0.034;
		right = 0.005;
		bottom = 0.005;
	};
	//\origins_pack\ui\ui_menu_fon_ca.paa
	//\origins_pack\ui\ui_knopka_menu_disabled_ca.paa
	animTextureNormal 	= "\origins_pack\ui\ui_knopka_menu_normal_ca.paa";
	animTextureDisabled = "\origins_pack\ui\ui_knopka_menu_disabled_ca.paa";
	animTextureOver 	= "\origins_pack\ui\ui_knopka_menu_over_ca.paa";
	animTextureFocused 	= "\origins_pack\ui\ui_knopka_menu_focus_ca.paa";
	animTexturePressed 	= "\origins_pack\ui\ui_knopka_menu_down_ca.paa";
	animTextureDefault 	= "\origins_pack\ui\ui_knopka_menu_normal_ca.paa";
	period = 0.5;
	font = "Zeppelin32";
	size = 0.03921;
	sizeEx = 0.03921;
	text = "";
	soundEnter[] = {"\ca\ui\data\sound\onover",0.09,1};
	soundPush[] = {"\ca\ui\data\sound\new1",0.0,0};
	soundClick[] = {"\ca\ui\data\sound\onclick",0.07,1};
	soundEscape[] = {"\ca\ui\data\sound\onescape",0.09,1};
	action = "";
	class Attributes
	{
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "left";
		shadow = "false";
	};
	class AttributesImage
	{
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "false";
	};
};

class RscDisplayMPInterrupt: RscStandardDisplay
{
	class controlsBackground
	{
		class Mainback : RscPicture {
			text = "\origins_pack\ui\ui_menu_fon_ca.paa";
		};
		// add logo
		class ORI_Logo :RscPictureKeepAspect
		{ 
			x = 0.058;
			y = 0.403; 
			w = 0.3;
			h = 0.3;
			text = "z\addons\dayz_code\gui\Origins_logo_ca.paa";
		};

	};
	class controls
	{
		// delete classes
		delete CA_B_REVERT;
		delete CA_B_Respawn;
		class CA_B_SAVE : RscShortcutButtonMainOri 	{ onButtonClick = ""; text = ""; };
		class CA_B_Skip : CA_B_SAVE 		{ onButtonClick = ""; text = ""; };
		// move buttons to top
		class CA_B_Options :CA_B_SAVE 		{ y = "0.2537 + 0.101903 * 0"; };
		class CA_B_Abort :CA_B_SAVE 		{ y = "0.2537 + 0.101903 * 1"; };
		class Paused_Title : CA_Title {
			colorText[] = {0.95, 0.95, 0.95, 0.7};
		};
		class MissionTitle : RscText {
			colorText[] = {0.95, 0.95, 0.95, 0.7};
		};
		class DifficultyTitle : RscText {
			colorText[] = {0.95, 0.95, 0.95, 0.7};
		};
		class ButtonCancel : RscShortcutButton {
			animTextureNormal 	= "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureDisabled = "\origins_pack\ui\esc_knopka_normal_ca.paa";
			animTextureOver 	= "\origins_pack\ui\esc_knopka_over_ca.paa";
			animTextureFocused 	= "\origins_pack\ui\esc_knopka_focus_ca.paa";
			animTexturePressed 	= "\origins_pack\ui\esc_knopka_down_ca.paa";
			animTextureDefault 	= "\origins_pack\ui\esc_knopka_default_ca.paa";
			x = 0.1775;
			y = 0.8799;
			w = 0.153825;
			h = 0.08;
			period = 0;
			class TextPos {
				left = 0.045;
				top = 0.010;
				right = 0.005;
				bottom = 0.005;
			};
		};
	};
};
