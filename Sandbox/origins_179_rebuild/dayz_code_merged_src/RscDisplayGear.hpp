class RscIGUIShortcutButton : RscShortcutButton {
	w = 0.183825;
	h = 0.0522876;
	style = 2;
	color[] = {1, 1, 1, 1};
	color2[] = {1, 1, 1, 0.85};
	colorBackground[] = {1, 1, 1, 1};
	colorbackground2[] = {1, 1, 1, 0.85};
	colorDisabled[] = {1, 1, 1, 0.4};
	
	class HitZone {
		left = 0.002;
		top = 0.003;
		right = 0.002;
		bottom = 0.016;
	};
	
	class ShortcutPos {
		left = -0.006;
		top = -0.007;
		w = 0.0392157;
		h = 0.0522876;
	};
	
	class TextPos {
		left = 0.02;
		top = 0.0;
		right = 0.002;
		bottom = 0.016;
	};
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

	class Attributes {
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "center";
		shadow = "true";
	};
};

class RscGearShortcutButton : RscShortcutButton {
	w = 0.0392157;
	h = 0.0522876;
	style = 2;
	color[] = {1, 1, 1, 1};
	color2[] = {1, 1, 1, 0.85};
	colorBackground[] = {1, 1, 1, 1};
	colorbackground2[] = {1, 1, 1, 0.85};
	colorDisabled[] = {1, 1, 1, 0.4};
	
	class HitZone {
		left = 0.0;
		top = 0.0;
		right = 0.0;
		bottom = 0.0;
	};
	
	class ShortcutPos {
		left = -0.006;
		top = -0.007;
		w = 0.0392157;
		h = 0.0522876;
	};
	
	class TextPos {
		left = 0.003;
		top = 0.001;
		right = 0.0;
		bottom = 0.0;
	};
	sizeEx = 0.1;
	animTextureNormal = 	"\origins_pack\ui\gear\igui_gear_normal_ca.paa";
	animTextureDisabled = 	"\origins_pack\ui\gear\igui_gear_disabled_ca.paa";
	animTextureOver = 		"\origins_pack\ui\gear\igui_gear_over_ca.paa";
	animTextureFocused = 	"\origins_pack\ui\gear\igui_gear_focus_ca.paa";
	animTexturePressed = 	"\origins_pack\ui\gear\igui_gear_down_ca.paa";
	animTextureDefault = 	"\origins_pack\ui\gear\igui_gear_normal_ca.paa";
	
	class Attributes {
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "center";
		shadow = "false";
	};
};

class RscDisplayGear
{
	idd = 106;
	enableDisplay = 1;
	onLoad = "disableSerialization; private ['_d','_back','_target']; _d = _this select 0; _back = if (isNil 'A2EDC_onBack') then {player getVariable ['A2EDC_onBack','']} else {A2EDC_onBack}; _target = if (isNil 'A2EDC_onBackVisualTargetIDC') then {511} else {A2EDC_onBackVisualTargetIDC}; diag_log format['A2EDC:GEAR_ONLOAD_RAW this=%1 displayFromThisNull=%2 findDisplay106Null=%3 A2EDC_onBack=%4 targetIDC=%5',_this,isNull _d,isNull (findDisplay 106),_back,_target]; [_this,'initDialog'] call handleGear; if (!isNil 'A2EDC_fnc_onBackGearOpenRefresh') then {[_d,'onLoad'] spawn A2EDC_fnc_onBackGearOpenRefresh;};";
	onUnload = "[_this,'gearSync'] call handleGear;";
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
			h = 0.073;
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
					onSetFocus = "[_this,'onFocus'] call handleGear;";
					onButtonClick = "[_this,'onLBListSelChanged'] call handleGear;";
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
					//colorSelect[] = {0.5, 0.5, 0.5, 1};
					colorSelectBackground[] = {0.5, 0.5, 0.5, 1};
					colorSelectBackground2[] = {0.5, 0.5, 0.5, 1};
					onKeyDown = "[_this,'onKeyDown',0,107,0,107] call handleGear;";
					onLBSelChanged = "[_this,'onLBSelChanged'] call handleGear; [_this,'list'] call (compile preprocessFileLineNumbers '\z\addons\dayz_code\compile\a2edc_itemInfoPanel.sqf');";
					onLBListSelChanged = "[_this,'onLBListSelChanged'] call handleGear; [_this,'list'] call (compile preprocessFileLineNumbers '\z\addons\dayz_code\compile\a2edc_itemInfoPanel.sqf');";
					onKillFocus = "[_this,'onKillFocus'] call handleGear;";
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
					onSetFocus = "[_this,'onFocus'] call handleGear;";
					onButtonClick = "[_this,'onLBListSelChanged'] call handleGear;";
					text = "&gt;";
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
			x = 0.503;
			y = 0.250 * safezoneH;
			w = 0.143 * safezoneW;
			h = 0; //0.250 * safezoneH;
			onMouseMoving = "[_this,'gearOffMenu'] call handleGear;";
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
					w = 0.172;
					h = 0.151;
					style = "0x30 + 0x800";
					onMouseButtonDown = "if ((_this select 1) == 1) then {_this call player_selectSlot;} else {[_this,'selectSlot'] call handleGear;}; [_this,'slot'] call (compile preprocessFileLineNumbers '\z\addons\dayz_code\compile\a2edc_itemInfoPanel.sqf');";
					soundDoubleClick[] = {"",0.1,1};
					color[] = {1,1,1,1};
					colorBackground[] = {0.68,0.68,0.68,0.75};
					colorBackgroundSelected[] = {0.68,0.68,0.68,0.75};
					colorFocused[] = {0,0,0,0};
					canDrag = 1;
				};
				
				class CA_Gear_slot_secondary: CA_Gear_slot_primary
				{
					idc = 108;
					x = "0.6763 - 0.502";
					y = "0.398 - 0.09";
					w = 0.1117;
					h = 0.15;
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
					x = "0.676 - 0.502";
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
					x = "0.676 - 0.502";
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
					x = "0.676 - 0.502";
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
					x = "0.676 - 0.502";
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
				
				class bSmena1: RscActiveText {
					idc = 510;
					style = "0x30 + 0x800";
					text = "\origins_pack\ui\gear\ui_arrow_normal2_ca.paa";
					x = "0.502 - 0.502";
					y = "0.39 - 0.09";
					w = 0.1735;
					h = 0.045;
					color[] = {1,1,1,0.5};
					colorActive[] = {1,1,1,0.8};
					onMouseButtonDown = "diag_log 'A2EDC:BSMENA_RAW_CLICK fired=true idc=510 source=RscDisplayGear'; if (isNil 'A2EDC_fnc_bSmenaTrigger') then {diag_log 'A2EDC:BSMENA_TRIGGER_MISSING idc=510 source=RscDisplayGear'; if (isNil 'A2EDC_bSmenaRecoverAttempted') then {A2EDC_bSmenaRecoverAttempted = true; call compile preprocessFileLineNumbers '\z\addons\dayz_code\init\a2edc_load_onback.sqf'; ['bSmena_raw_click'] call A2EDC_fnc_loadOnBackCompile;}; diag_log format['A2EDC:BSMENA_TRIGGER_RECOVER result=%1',if (isNil 'A2EDC_fnc_bSmenaTrigger') then {'fail'} else {'ok'}];}; if (!isNil 'A2EDC_fnc_bSmenaTrigger') then {call A2EDC_fnc_bSmenaTrigger;};";
				};
				class CA_Gear_slot_shouder: RscActiveText
				{
					idc = 511;
					style = "0x30 + 0x800";
					x = "0.502 - 0.502";
					y = "0.43 - 0.09"; //y = "0.39 - 0.09";
					w = 0.173;
					h = 0.119;
					color[] = {1,1,1,0.82};
					colorActive[] = {1,1,1,0.82};
				};
				class OriMedB: RscActiveText
				{
					idc = 512;
					style = "0x30 + 0x800";
					text = "";
					x = "0.502 - 0.502";
					y = "0.552 - 0.09";
					w = 0.055;
					h = 0.15;
					color[] = {1,1,1,0.7};
					colorActive[] = {1,1,1,0.9};
					onMouseButtonDown = "if ((_this select 1) == 1) then {_this call player_selectSlot;} else {[_this,'selectSlot'] call handleGear;};";
					/*
						x = "0.503";
						y = "0.552";
						w = 0.055;
						h = 0.15;
					*/
				};
				class OriVest: CA_Gear_slot_primary
				{
					idc = 513;
					style = "0x30 + 0x800";
					text = "";
					x = "0.678 - 0.502";
					y = "0.245 - 0.09";
					w = 0.109;
					h = 0.150;
					color[] = {1,1,1,0.5};
					colorActive[] = {1,1,1,0.8};
					onMouseButtonDown = "if ((_this select 1) == 1) then {_this call player_selectSlot;} else {[_this,'selectSlot'] call handleGear;};";
				};
				
			};
		};
		class G_sMedBItems: RscControlsGroup
		{
			idc = 514;
			x = 0.977;
			y = 0.473;
			w = 0.056;
			h = 0.576;
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
				class OriMedB_slide1: RscActiveText {
					idc = 515;
					style = "0x30 + 0x800";
					text = "";
					x = "0";
					y = "0";
					w = 0.056;
					h = 0.076;
					color[] = {1,1,1,0.8};
					colorActive[] = {1,1,1,0.9};
					onMouseButtonDown = "if ((_this select 1) == 1) then {_this call player_selectSlot;} else {[_this,'selectSlot'] call handleGear;};";
					canDrag = 1;
				};
				class OriMedB_slide2: OriMedB_slide1 {
					idc = 516;
					y = "0.076";
				};
				class OriMedB_slide3: OriMedB_slide1 {
					idc = 517;
					y = "0.152";
				};
				class OriMedB_slide4: OriMedB_slide1 {
					idc = 518;
					y = "0.228";
				};
				class OriMedB_slide5: OriMedB_slide1 {
					idc = 519;
					y = "0.304";
				};
				class OriMedB_slide6: OriMedB_slide1 {
					idc = 520;
					y = "0.381";
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
			y = 0.8913;
			text = "Filter";
		};
		class ButtonRearm: RscIGUIShortcutButton
		{
			idc = 132;
			shortcuts[] = {"0x00050000 + 2"};
			x = 0.554743;
			y = 0.8913;
			w = 0;
			h = 0;
			text = "Rearm";
		};
		class ButtonOpenBag: RscIGUIShortcutButton
		{
			idc = 157;
			shortcuts[] = {"0x00050000 + 2"};
			x = 0.554743;
			y = 0.8913;
			text = "Open bag";
		};
		class ButtonCloseBag: RscIGUIShortcutButton
		{
			idc = 158;
			shortcuts[] = {"0x00050000 + 2"};
			x = 0.554743;
			y = 0.8913;
			text = "Close bag";
		};
		class ButtonContinue: RscIGUIShortcutButton
		{
			idc = 1;
			shortcuts[] = {"0x00050000 + 0",28,57,156};
			x = 0.76615;
			y = 0.8913;
			default = 1;
		};
		class ButtonClose: RscIGUIShortcutButton
		{
			idc = 2;
			shortcuts[] = {"0x00050000 + 1"};
			x = 0.046;
			y = 0.8911;
			text = "Close";
		};
	};
	class Filters
	{
		class All
		{
			name = "All";
			mask = -1;
			image = "\origins_pack\ui\gear\igui_gear_filter_1_ca.paa";
		};
		class Primary
		{
			name = "Primary";
			mask = 769;
			image = "\origins_pack\ui\gear\igui_gear_filter_2_ca.paa";
		};
		class Secondary
		{
			name = "Secondary";
			mask = 516;
			image = "\origins_pack\ui\gear\igui_gear_filter_3_ca.paa";
		};
		class HandGun
		{
			name = "HandGun";
			mask = 18;
			image = "\origins_pack\ui\gear\igui_gear_filter_4_ca.paa";
		};
		class Items
		{
			name = "Items";
			mask = 135168;
			image = "\origins_pack\ui\gear\igui_gear_filter_5_ca.paa";
		};
	};
	movingEnable = 1;
	emptyGun = "\origins_pack\ui\gear\ui_gear_gun_gs_ca.paa";
	emptySec = "\origins_pack\ui\gear\ui_gear_sec_gs_small_ca.paa";
	emptyEq = "\origins_pack\ui\gear\ui_gear_eq_gs_ca.paa";
	emptyMag = "\origins_pack\ui\gear\ui_gear_mag_gs_ca.paa";
	emptyMag2 = "\origins_pack\ui\gear\ui_gear_mag2_gs_ca.paa";
	emptyHGun = "\origins_pack\ui\gear\ui_gear_hgun_gs_ca.paa";
	emptyHGunMag = "\origins_pack\ui\gear\ui_gear_hgunmag_gs_ca.paa";
	onLoad = "disableSerialization; private ['_d','_back','_target']; _d = _this select 0; _back = if (isNil 'A2EDC_onBack') then {player getVariable ['A2EDC_onBack','']} else {A2EDC_onBack}; _target = if (isNil 'A2EDC_onBackVisualTargetIDC') then {511} else {A2EDC_onBackVisualTargetIDC}; diag_log format['A2EDC:GEAR_ONLOAD_RAW this=%1 displayFromThisNull=%2 findDisplay106Null=%3 A2EDC_onBack=%4 targetIDC=%5',_this,isNull _d,isNull (findDisplay 106),_back,_target]; [_this,'initDialog'] call handleGear; if (!isNil 'A2EDC_fnc_onBackGearOpenRefresh') then {[_d,'onLoad'] spawn A2EDC_fnc_onBackGearOpenRefresh;};";
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
			text = "\origins_pack\ui\gear\igui_background_gear_ca.paa";
		};
		class Ori_slot_bkW_bg: RscPicture
		{
			idc = 5011;
			x = "0.502";
			y = "0.43"; //y = "0.39 - 0.09";
			w = 0.173;
			h = 0.119;
			text = "\origins_pack\ui\gear\ui_gear_secondary_ca.paa";
		};
		
		class Ori_slot_vestH_bg: RscPicture
		{
			idc = 5012;
			x = "0.676";
			y = "0.093";
			w = 0.112;
			h = 0.1455;
			text = "\origins_pack\ui\gear\ui_gear_helmet_ca.paa";
			colorText[] = {0.88,0.88,0.88,0.6};
		};
		class CA_Gear_slot_vest_bg: RscPicture
		{
			idc = 5013;
			x = "0.677";
			y = "0.2445";
			w = 0.111;
			h = 0.152;
			text = "\origins_pack\ui\gear\ui_gear_vest_ca.paa";
		};
		class CA_Gear_slot_vest2_bg: RscPicture
		{
			idc = 5014; //5015;
			x = "0.781";
			y = "0.246";
			w = 0.003;
			h = 0.15;
			text = "";
		};
		class CA_Gear_slot_medb_bg: RscPicture
		{
			idc = 5015;
			x = "0.503";
			y = "0.552";
			w = 0.055;
			h = 0.15;
			text = "\origins_pack\ui\gear\ui_gear_medbg_empty_ca.paa";
		};
		class CA_Gear_slot_medbs_bg: RscPicture
		{
			idc = 5016;
			x = "0.965";
			y = "0.397";
			w = 0.072;
			h = 0.537;
			text = "";
		};
		class CA_Gear_slot_medbs1_bg: RscPicture
		{
			idc = 5017;
			x = "0.977";
			y = "0.4736";
			w = 0.055;
			h = 0.073;
			text = "";
		};
		class CA_Gear_slot_medbs2_bg: CA_Gear_slot_medbs1_bg
		{
			idc = 5018;
			y = "0.5498";
		};
		class CA_Gear_slot_medbs3_bg: CA_Gear_slot_medbs1_bg
		{
			idc = 5019;
			y = "0.6258";
		};
		class CA_Gear_slot_medbs4_bg: CA_Gear_slot_medbs1_bg
		{
			idc = 5020;
			y = "0.7018";
		};
		class CA_Gear_slot_medbs5_bg: CA_Gear_slot_medbs1_bg
		{
			idc = 5021;
			y = "0.7780";
		};
		class CA_Gear_slot_medbs6_bg: CA_Gear_slot_medbs1_bg
		{
			idc = 5022;
			y = "0.8548";
		};
	
	};
};
