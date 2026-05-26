class CfgVehicles {
	
	class AllVehicles;
	class Air : AllVehicles 
	{
		class NewTurret;
		class ViewPilot;
		class AnimationSources;
	};
	class Ship : AllVehicles 
	{
		class NewTurret;
		class ViewPilot;
		class AnimationSources;
	};
	class Boat : Ship {
		class HitPoints
		{
			class HitEngine
			{
				armor = 1.2;
				material = 60;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				commanding = -1;
				startEngine = 0;
			};
		};
	};
	class Helicopter : Air 
	{
		class HitPoints {
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class HitVRotor;
			class HitHRotor;
		};
		class Turrets
        {
            class MainTurret: NewTurret
            {
                class Turrets;
            };
        };
		class AnimationSources;
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		ejectDeadGunner = 1;
		ejectDeadCargo = 1;
		ejectDeadDriver = 1;
		ejectDeadCommander = 1;
	};

	class Animal;
	class Pastor;
	class Fin;
	class DZAnimal: Animal
	{
		scope = 0;
		side = 1;
		accuracy = 0.25;
		boneHead = "head";
		bonePrimaryWeapon = "head";
		triggerAnim = "";
		picture = "";
		icon = "\Ca\animals2\data\mapicon_animals_ca.paa";
		mapSize = 10;
		weaponSlots = 0;
		fsmFormation = "";
		fsmDanger = "";
		agentTasks[] = {};
		moves = "CfgMovesAnimal";
		memoryPointHeadAxis = "head_axis";
		woman = 0;
		faceType = "Default";
		boneLEye = "l_eye";
		boneREye = "r_eye";
		boneLEyelidUp = "eye_upl";
		boneREyelidUp = "eye_upr";
		boneLEyelidDown = "eye_lwl";
		boneREyelidDown = "eye_lwr";
		boneLPupil = "l_pupila";
		boneRPupil = "r_pupila";
		memoryPointAim = "aimPoint";
		memoryPointCameraTarget = "camera";
		extCameraPosition[] = {0,0.5,-2.5};
		class EventHandlers{};
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
		class VariablesScalar {};
		class VariablesString {};
	};
	class DZ_Pastor : Pastor {
		scope = 2;
		model = "\ca\animals2\Dogs\Pastor\Pastor";
		displayName = "Alsatian";
		moves = "CfgMovesDogDZ";
		gestures = "CfgGesturesDogDZ";
		fsmDanger = "";
		fsmFormation = "";
	};
	
	class DZ_Fin : Fin {
		scope = 2;
		model = "\ca\animals2\Dogs\Fin\Fin";
		displayName = "Fin";
		moves = "CfgMovesDogDZ";
		gestures = "CfgGesturesDogDZ";
		fsmDanger = "";
		fsmFormation = "";
	};

	class Bag_Base_EP1;
	
	//CZ_VestPouch_EP1
	class DZ_Patrol_Pack_EP1: Bag_Base_EP1
	{
		scope = 2;
		displayName = "Patrol Pack (coyote)";
		picture = "\ca\weapons_e\data\icons\backpack_US_ASSAULT_COYOTE_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		mapsize = 2;
		model = "\ca\weapons_e\AmmoBoxes\backpack_us_assault_Coyote.p3d";
		transportMaxWeapons = 3;
		transportMaxMagazines = 16;
	};
	class DZ_Assault_Pack_EP1: Bag_Base_EP1
	{
		scope = 2;
		displayName = "Assault Pack (ACU)";
		picture = "\ca\weapons_e\data\icons\backpack_US_ASSAULT_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		mapSize = 2;
		model = "\ca\weapons_e\AmmoBoxes\backpack_us_assault.p3d";
		transportMaxWeapons = 3;
		transportMaxMagazines = 16;
	};
	
	class origins_school_1: Bag_Base_EP1
	{
		scope = 2;
		mapsize = 2;
		displayName = "School Bag(Owl)";
		model="\origins_pack\items\schoolruck.p3d";
		picture="\origins_pack\items\school_b_ca.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		transportMaxweapons = 3;
		transportMaxMagazines = 16;
	};
	class origins_school_2: Bag_Base_EP1
	{
		scope = 2;
		mapsize = 2;
		displayName = "Bad boy bag";
		model="\origins_pack\items\schoolruck_b.p3d";
		picture="\origins_pack\items\school_m_ca.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		transportMaxweapons = 3;
		transportMaxMagazines = 16;
	};
	class origins_school_3: Bag_Base_EP1
	{
		scope = 2;
		mapsize = 2;
		displayName = "Girls Bag(Dora)";
		model="\origins_pack\items\schoolruck_k.p3d";
		picture="\origins_pack\items\school_k_ca.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		transportMaxweapons = 3;
		transportMaxMagazines = 16;
	};
	
	class origins_bear: Bag_Base_EP1
	{
		scope = 2;
		mapsize = 2;
		displayName = "Bear Bag";
		model="\origins_pack\items\vil_misiopack.p3d";
		picture="\origins_pack\items\textures\bear_bacpack_ca.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		transportMaxweapons = 4;
		transportMaxMagazines = 20;
	};
	class origins_elephant1: Bag_Base_EP1
	{
		scope = 2;
		mapsize = 2;
		displayName = "Elephant Bag(Blue)";
		model="\origins_pack\items\elephruck.p3d";
		picture="\origins_pack\items\textures\eleph1_bacpack_ca.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		transportMaxweapons = 4;
		transportMaxMagazines = 20;
	};
	class origins_elephant2: Bag_Base_EP1
	{
		scope = 2;
		mapsize = 2;
		displayName = "Elephant Bag(Black)";
		model="\origins_pack\items\elephruck2.p3d";
		picture="\origins_pack\items\textures\eleph2_bacpack_ca.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		transportMaxweapons = 4;
		transportMaxMagazines = 20;
	};

	class DZ_ALICE_Pack_EP1: Bag_Base_EP1
	{
		scope = 2;
		displayName = "ALICE Pack";
		picture = "\ca\weapons_e\data\icons\backpack_TK_ALICE_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		mapsize = 2;
		model = "\ca\weapons_e\AmmoBoxes\backpack_tk_alice.p3d";
		transportMaxWeapons = 6;
		transportMaxMagazines = 24;
	};
	class DZ_CivilBackpack_EP1: Bag_Base_EP1
	{
		scope = 2;
		displayName = "Czech Backpack";
		picture = "\ca\weapons_e\data\icons\backpack_ACR_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		mapsize = 2;
		model = "\ca\weapons_e\AmmoBoxes\backpack_acr.p3d";
		transportMaxWeapons = 6;
		transportMaxMagazines = 24;
	};
	class DZ_Backpack_EP1: Bag_Base_EP1
	{
		scope = 2;
		displayName = "Backpack (coyote)";
		picture = "\ca\weapons_e\data\icons\backpack_US_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		mapsize = 2;
		model = "\ca\weapons_e\AmmoBoxes\backpack_us.p3d";
		transportMaxWeapons = 6;
		transportMaxMagazines = 24;
	};
	
	class O_TravelerPack_1: Bag_Base_EP1
	{
		scope = 2;
		displayName = "Traveler (Martin)";
		picture = "\ca\weapons_e\data\icons\backpack_CIVIL_ASSAULT_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		mapsize = 2;
		model = "\ca\weapons_e\AmmoBoxes\backpack_civil_assault.p3d";
		transportMaxWeapons = 10;
		transportMaxMagazines = 32;
	};
	class O_MegaPack_1: Bag_Base_EP1
	{
		scope = 2;
		displayName = "Mega";
		picture = "\ca\weapons_e\data\icons\backpack_RPG_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		mapsize = 2;
		model = "\ca\weapons_e\AmmoBoxes\backpack_rpg.p3d";
		transportMaxWeapons = 12;
		transportMaxMagazines = 40;
	};
	class ori_30l_Backpack: Bag_Base_EP1
	{
		scope = 2;
		displayName = "Explorer";
		picture = "\origins_pack\salvation\ui_explorer_backpack_ca.paa";
		model="\origins_pack\salvation\30l_ruck.p3d";
		icon = "\origins_pack\salvation\ui_explorer_backpack_ca.paa";
		transportMaxweapons = 12;
		transportMaxMagazines = 48;
	};

	class ori_bigrusruck: Bag_Base_EP1
	{
		scope = 2;
		displayName = "Adventurer";
		picture = "\origins_pack\items\ico_big_rus_pack_ca.paa";
		model="\origins_pack\items\bigrusruck.p3d";
		icon = "\origins_pack\items\ico_big_rus_pack_ca.paa";
		transportMaxweapons = 12;
		transportMaxMagazines = 56;
	};


	
	class Zodiac;
	class PBX;
	class Fishing_Boat;
	class Smallboat_1;
	class smallboat_2;
	
	class RHIB_Ori: Boat
	{
		scope = 2;
		displayName = "RHIB";
		vehicleClass = "Ship";
		accuracy = 0.5;
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {};
		weapons[] = {};
		magazines[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		transportMaxMagazines = 250;
		transportMaxWeapons = 100;
		transportMaxBackpacks = 10;
		side = 2;
		model = "\ca\water\rhib";
		picture = "\ca\water\data\ico\rhib_CA.paa";
		Icon = "\Ca\water\Data\map_ico\icomap_RHIB_CA.paa";
		mapSize = 8;
		unitInfoType = "UnitInfoShip";
		soundEnviron[] = {"",0.0562341,0.9};
		precision = 6;
		brakeDistance = 20;
		class SoundEvents
		{
		};
		insideSoundCoef = 1;
		soundEngineOnInt[] = {"ca\sounds\vehicles\water\rhib\ext-boat-start-01",0.1,1};
		soundEngineOnExt[] = {"ca\sounds\vehicles\water\rhib\ext-boat-start-01",1,1,150};
		soundEngineOffInt[] = {"ca\sounds\vehicles\water\rhib\ext-boat-stop-01",0.1,1};
		soundEngineOffExt[] = {"ca\sounds\vehicles\water\rhib\ext-boat-stop-01",1,1,150};
		class Sounds
		{
			class Engine
			{
				sound[] = {"ca\sounds\vehicles\water\rhib\ext-boat-engine-low-01",1,0.9,300};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "engineOn*(rpm factor[0.5, 0.1])";
			};
			class EngineHighOut
			{
				sound[] = {"ca\sounds\vehicles\water\rhib\ext-boat-engine-high-01",1,0.8,300};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "engineOn*(rpm factor[0.4, 1.3])";
			};
			class IdleOut
			{
				sound[] = {"ca\sounds\vehicles\water\rhib\ext-boat-engine-idle-03",0.562341,1,150};
				frequency = "1";
				volume = "engineOn*(rpm factor[0.3, 0])";
			};
			class WaternoiseOutW0
			{
				sound[] = {"ca\sounds\vehicles\water\water_sfx\ext-water-noise-nospeed",0.398107,1,100};
				frequency = "1";
				volume = "(speed factor[7, 0])";
			};
			class WaternoiseOutW1
			{
				sound[] = {"ca\sounds\vehicles\water\water_sfx\ext-boat-lospd-noise-02",0.398107,1,100};
				frequency = "1";
				volume = "((speed factor[2, 12]) min (speed factor[12, 2]))";
			};
			class WaternoiseOutW2
			{
				sound[] = {"ca\sounds\vehicles\water\water_sfx\ext-boat-hispd-noise-02",0.398107,1,100};
				frequency = "1";
				volume = "(speed factor[9, 18.7])";
			};
		};
		driverAction = "RHIB_Driver";
		cargoAction[] = {"RHIB_Cargo"};
		getInAction = "GetInMedium";
		getOutAction = "GetOutMedium";
		cargoGetInAction[] = {"GetInMedium"};
		cargoGetOutAction[] = {"GetOutMedium"};
		castDriverShadow = 1;
		castCargoShadow = 1;
		gunnerHasFlares = 0;
		maxSpeed = 60;
		enableGPS = 1;
		transportSoldier = 10;
		supplyRadius = 3;
		class Exhausts
		{
			class Exhaust1
			{
				position = "vyfuk start";
				direction = "vyfuk konec";
				effect = "";
			};
		};
		cost = 10000;
		armor = 30;
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "M2";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "M2";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "M2";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: NewTurret
			{
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.8;
						material = 60;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 0.6;
						material = 60;
						name = "zbran";
						visual = "zbran";
						passThrough = 1;
					};
				};
				stabilizedInAxes = 0;
				body = "MainTurret";
				gun = "MainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				gunnerAction = "RHIB_Gunner";
				gunnerGetInAction = "GetInMedium";
				gunnerGetOutAction = "GetOutMedium";
				ejectDeadGunner = 1;
				outGunnerMayFire = 1;
				inGunnerMayFire = 0;
				minElev = -25;
				maxElev = 60;
				initElev = 5;
				minTurn = -135;
				maxTurn = 135;
				initTurn = 0;
				soundServo[] = {"\ca\sounds\vehicles\servos\turret-1",0.00562341,1};
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				weapons[] = {"M2"};
				magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2"};
				gunnerName = "front gunner";
				gunnerOpticsModel = "\ca\weapons\optika_empty";
				gunnerForceOptics = 0;
				startEngine = 0;
				commanding = 2;
				primaryGunner = 0;
				primaryObserver = 1;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -65;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
			};
		};
		class Library
		{
			libTextDesc = "The Naval Special Warfare Rigid Hull Inflatable Boat is a fast, high-buoyancy all weather boat designed to transport a fully equipped team of eight-men and three crew members. It is also fully transportable by C-130 Hercules.";
		};
		extCameraPosition[] = {0,4,-14};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\water\data\rhib.rvmat","ca\water\data\rhib.rvmat","ca\water\data\rhib_destruct.rvmat","ca\water\data\rhib_dash.rvmat","ca\water\data\rhib_dash.rvmat","ca\water\data\rhib_dash_destruct.rvmat"};
		};
	};
	
	class Zodiac_Ori : Zodiac{
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		faction = "rth_copter_class";
	};
	class PBX_Ori : PBX{
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		faction = "rth_copter_class";
	};
	class Fishing_Boat_DZ : Fishing_Boat{
		transportMaxMagazines = 500;
		transportMaxWeapons = 200;	
		maxSpeed = 25;
	};
	class Smallboat_1_DZ : Smallboat_1{
		transportMaxMagazines = 500;
		transportMaxWeapons = 200;	
		maxSpeed = 25;
	};
	class smallboat_2_DZ : smallboat_2{
		transportMaxMagazines = 500;
		transportMaxWeapons = 200;	
		maxSpeed = 25;
	};

	class UH1H_Ori : Helicopter {
		expansion = 1;
		scope = 2;
		side = 2;
		crew = "";
		model = "Ca\air_E\UH1H\UH1H.p3d";
		displayName = "UH1H";
		faction = "rth_copter_class";
		typicalCargo[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		transportMaxMagazines = 250;
		transportMaxWeapons = 20;
		transportMaxBackpacks = 5;
		radarType = 0;
		weapons[] = {};
		magazines[] = {};
		hasGunner = true;
		enableSweep = false;
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelectionsTextures[] = {"ca\air_E\UH1H\data\UH1D_TKA_CO.paa", "ca\air_E\UH1H\data\UH1D_in_TKA_CO.paa", "ca\air_E\UH1H\data\default_TKA_co.paa"};
		
		picture = "\ca\air_e\data\UI\Picture_uh1h_CA.paa";
		icon = "\ca\air_e\data\UI\Icon_uh1h_CA.paa";
		mapSize = 14;
		destrType = "DestructWreck";
		ejectDeadGunner = 1;
		ejectDeadCargo = 1;
		ejectDeadDriver = 1;
		ejectDeadCommander = 1;
		
		class Library {
			libTextDesc = $STR_EP1_LIB_UH1H;
		};
		cargoAction[] = {"UH1H_Cargo_EP1", "UH1Y_Cargo03", "UH1Y_Cargo03", "UH1Y_Cargo02", "UH1Y_Cargo01", "UH1Y_Cargo01", "UH1Y_Cargo01"};
		cargoIsCoDriver[] = {0, 1};
		transportSoldier = 5;
		driverAction = "UH1H_Pilot_EP1";
		driverInAction = "UH1H_Pilot_EP1";
		driverOpticsModel = "";
		gunnerOpticsModel = "";
		threat[] = {0.4, 0, 0};
		mainRotorSpeed = 1.2;
		backRotorSpeed = 6.1;
		soundGetIn[] = {"Ca\Sounds_E\Air_E\UH1H\open_close", 0.316228, 1};
		soundGetOut[] = {"Ca\Sounds_E\Air_E\UH1H\open_close", 0.316228, 1, 40};
		soundEngineOnInt[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_start_int", 0.446684, 1.0};
		soundEngineOnExt[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_start_ext", 0.446684, 1.0, 700};
		soundEngineOffInt[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_stop_int", 0.446684, 1.0};
		soundEngineOffExt[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_stop_ext", 0.446684, 1.0, 700};
		enableManualFire = 0;
		
		class Sounds {
			class Engine {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_engine_ext_2", 1.0, 1.0, 800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			
			class RotorLowOut {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_rotor_ext_1", 2.51189, 1.0, 1400};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.6, 3.14, 2.0, 0.5};
			};
			
			class RotorHighOut {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_rotor_high_ext_1", 2.51189, 1.0, 1600};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.6, 3.14, 2.0, 0.5};
			};
			
			class EngineIn {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_engine_int_1", 1.0, 1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			
			class RotorLowIn {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_rotor_int_1", 1.77828, 1.0};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			
			class RotorHighIn {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_rotor_high_int_1", 3.16228, 1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
		
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				body = "mainTurret";
				gun = "mainGun";
				minElev = -60;
				maxElev = 30;
				initElev = -30;
				minTurn = -173;
				maxTurn = -3;
				initTurn = -70;
				soundServo[] = {"", 0.01, 1.0};
				stabilizedInAxes = "StabilizedInAxesNone";
				weapons[] = {"M240_veh"};
				magazines[] = {"100Rnd_762x51_M240", "100Rnd_762x51_M240", "100Rnd_762x51_M240"};
				gunBeg = "muzzle";
				gunEnd = "chamber";
				gunnerName = $STR_POSITION_DOORGUNNER;
				memoryPointsGetInGunner = "pos Gunner";
				memoryPointsGetInGunnerDir = "pos Gunner dir";
				gunnerOpticsModel = "\ca\weapons\optika_empty";
				memoryPointGunnerOptics = "gunnerview";
				gunnerOutOpticsShowCursor = 1;
				gunnerOpticsShowCursor = 0;
				gunnerAction = "UH1Y_Gunner";
				gunnerInAction = "UH1Y_Gunner";
				commanding = -3;
				primaryGunner = 0;
				gunnerCompartments = "Compartment1";
				
				class ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				LODTurnedOut = 1000;
				LODTurnedIn = 1000;
			};
			
			class LeftDoorGun : MainTurret {
				body = "Turret_2";
				gun = "Gun_2";
				animationSourceBody = "Turret_2";
				animationSourceGun = "Gun_2";
				weapons[] = {"M240_veh_2"};
				gunBeg = "muzzle_2";
				gunEnd = "chamber_2";
				memoryPointsGetInGunner = "pos Gunner";
				memoryPointsGetInGunnerDir = "pos Gunner dir";
				proxyIndex = 2;
				memoryPointGunnerOptics = "gunnerview_2";
				selectionFireAnim = "zasleh_1";
				gunnerName = $STR_POSITION_CREWCHIEF;
				commanding = -3;
				minElev = -50;
				maxElev = 30;
				initElev = -30;
				minTurn = 3;
				maxTurn = 173;
				initTurn = 80;
				primaryGunner = 1;
				gunnerCompartments = "Compartment1";
			};
		};
		
		class AnimationSources : AnimationSources {
			class ReloadAnim {
				source = "reload";
				weapon = "M240_veh";
			};
			
			class ReloadMagazine {
				source = "reloadmagazine";
				weapon = "M240_veh";
			};
			
			class Revolving {
				source = "revolving";
				weapon = "M240_veh";
			};
			
			class ReloadAnim_2 {
				source = "reload";
				weapon = "M240_veh_2";
			};
			
			class ReloadMagazine_2 {
				source = "reloadmagazine";
				weapon = "M240_veh_2";
			};
			
			class Revolving_2 {
				source = "revolving";
				weapon = "M240_veh_2";
			};
		};
		armor = 25;
		damageResistance = 0.00394;
		
		class HitPoints : HitPoints {
			class HitGlass1 : HitGlass1 {
				armor = 0.25;
			};
			
			class HitGlass2 : HitGlass2 {
				armor = 0.25;
			};
			
			class HitGlass3 : HitGlass3 {
				armor = 0.25;
			};
			
			class HitGlass4 : HitGlass4 {
				armor = 0.25;
			};
			
			class HitGlass5 : HitGlass5 {
				armor = 0.25;
			};
			
			class HitGlass6 : HitGlass5 {
				armor = 0.25;
			};
		};
		
		class Damage {
			tex[] = {};
			mat[] = {"ca\Air_E\UH1H\Data\UH1D.rvmat", "ca\Air_E\UH1H\Data\UH1D.rvmat", "ca\Air_E\UH1H\Data\UH1D_destruct.rvmat", "ca\Air_E\UH1H\Data\UH1D_cockpit1.rvmat", "ca\Air_E\UH1H\Data\UH1D_cockpit1.rvmat", "ca\Air_E\UH1H\Data\UH1D_cockpit1_destruct.rvmat", "ca\Air_E\UH1H\Data\UH1D_cockpit2.rvmat", "ca\Air_E\UH1H\Data\UH1D_cockpit2.rvmat", "ca\Air_E\UH1H\Data\UH1D_cockpit2_destruct.rvmat", "ca\Air_E\UH1H\Data\UH1D_cockpit3.rvmat", "ca\Air_E\UH1H\Data\UH1D_cockpit3.rvmat", "ca\Air_E\UH1H\Data\UH1D_cockpit3_destruct.rvmat", "ca\Air_E\UH1H\Data\UH1D_glass.rvmat", "ca\Air_E\UH1H\Data\UH1D_glass_damage.rvmat", "ca\Air_E\UH1H\Data\UH1D_glass_damage.rvmat", "ca\Air_E\UH1H\Data\UH1D_in.rvmat", "ca\Air_E\UH1H\Data\UH1D_in.rvmat", "ca\Air_E\UH1H\Data\UH1D_in_destruct.rvmat", "ca\Air_E\UH1H\Data\UH1D_instruments.rvmat", "ca\Air_E\UH1H\Data\UH1D_instruments.rvmat", "ca\Air_E\UH1H\Data\UH1D_instruments_destruct.rvmat", "ca\Air_E\UH1H\Data\UH1D_rotor.rvmat", "ca\Air_E\UH1H\Data\UH1D_rotor.rvmat", "ca\Air_E\UH1H\Data\UH1D_rotor_destruct.rvmat", "ca\data\data\default.rvmat", "ca\data\data\default.rvmat", "ca\Air_E\UH1H\Data\default_destruct.rvmat", "Ca\Ca_E\data\default.rvmat", "Ca\Ca_E\data\default.rvmat", "Ca\Ca_E\data\default_destruct.rvmat"};
		};
		hiddenSelections[] = {"Camo1", "Camo2", "Camo_mlod"};
		irScanRangeMin = 100;
		irScanRangeMax = 1000;
		irScanToEyeFactor = 2;
	};

	class Mi17_base : Helicopter 
	{
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		class Turrets: Turrets
		{	
			class MainTurret: MainTurret
			{
				minElev = -80;
				maxElev = 25;
				initElev = -80;
				minTurn = 30;
				maxTurn = 150;
				initTurn = 90;
				class ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class Turrets: Turrets {};
			};
			class BackTurret : MainTurret
			{
				minElev = -80;
				maxElev = 25;
				initElev = -80;
				minTurn = -185;
				maxTurn = -45;
				initTurn = -155;
				class Turrets: Turrets {};
			};
		};
		class AnimationSources;
		model = "\ca\Air_E\Mi17\Mi_8MT";
		destrType = "DestructWreck";
		weapons[] = {};
		armor = 25;
		magazines[] = {};
		LockDetectionSystem = 0;
		IncommingMisslieDetectionSystem = 0;
		radarType = 0;
		maxSpeed = 180;
		threat[] = {0.5, 0, 0};
		
		class HitPoints : HitPoints {
			class HitGlass1 : HitGlass1 {
				armor = 0.12;
			};
			
			class HitGlass2 : HitGlass2 {
				armor = 0.12;
			};
			
			class HitGlass3 : HitGlass3 {
				armor = 0.12;
			};
			
			class HitGlass4 : HitGlass4 {
				armor = 0.12;
			};
			
			class HitGlass5 : HitGlass5 {
				armor = 0.12;
			};
			
			class HitGlass6 : HitGlass6 {
				armor = 0.12;
			};
		};
		
		class Damage {
			tex[] = {};
			mat[] = {"Ca\Air_E\Mi17\data\mi8_body_amt.rvmat", "Ca\Air_E\Mi17\data\mi8_body_amt_damage.rvmat", "Ca\Air_E\Mi17\data\mi8_body_amt_destruct.rvmat", "Ca\Air_E\Mi17\data\mi8_det_g.rvmat", "Ca\Air_E\Mi17\data\mi8_det_g_damage.rvmat", "Ca\Air_E\Mi17\data\mi8_det_g_destruct.rvmat", "Ca\Air_E\Mi17\data\mi8_glass.rvmat", "Ca\Air_E\Mi17\data\mi8_glass_damage.rvmat", "Ca\Air_E\Mi17\data\mi8_glass_damage.rvmat", "Ca\Air_E\Mi17\data\mi8_glass_in.rvmat", "Ca\Air_E\Mi17\data\mi8_glass_in_damage.rvmat", "Ca\Air_E\Mi17\data\mi8_glass_in_damage.rvmat", "Ca\Air_E\Mi17\data\mi8_inter.rvmat", "Ca\Air_E\Mi17\data\mi8_inter_damage.rvmat", "Ca\Air_E\Mi17\data\mi8_inter_destruct.rvmat", "ca\weapons\data\pkm.rvmat", "ca\weapons\data\pkm.rvmat", "ca\weapons\data\pkm_destruct.rvmat", "Ca\Air_E\Mi17\data\mi8_body_mtv.rvmat", "Ca\Air_E\Mi17\data\mi8_body_mtv_damage.rvmat", "Ca\Air_E\Mi17\data\mi8_body_mtv_destruct.rvmat", "Ca\Ca_E\data\default.rvmat", "Ca\Ca_E\data\default.rvmat", "Ca\Ca_E\data\default_destruct.rvmat"};
		};
	};
	class Mi17_Ori: Mi17_base	
	{
		displayName = "Mi17";
		scope = 2;
		side = 2;
		faction = "rth_copter_class";
		crew = "";
		maxSpeed = 180;
		typicalCargo[] = {};
		hiddenSelectionsTextures[] = {"\ca\air_E\Data\mi17_body_IND_CO.paa", "\ca\air_E\Data\mi17_det_IND_CO.paa", "\ca\air\data\clear_empty.paa", "\ca\air\data\mi8_decals_ca.paa"};
		
		class Turrets : Turrets {
			class FrontTurret : MainTurret {
				weapons[] = {"PKT"};
				magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
				gunnerCompartments = "Compartment1";
				commanding = -3;
			};
			class BackTurret : BackTurret {
				weapons[] = {"PKT_2"};
				magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
				gunnerCompartments = "Compartment1";
				commanding = -3;
			};
		};
		weapons[] = {};
		magazines[] = {};
		
		class AnimationSources : AnimationSources {
			class ReloadAnim {
				source = "reload";
				weapon = "PKT";
			};
			class ReloadMagazine {
				source = "reloadmagazine";
				weapon = "PKT";
			};
			class Revolving {
				source = "revolving";
				weapon = "PKT";
			};
			class ReloadAnim_2 {
				source = "reload";
				weapon = "PKT_2";
			};
			class ReloadMagazine_2 {
				source = "reloadmagazine";
				weapon = "PKT_2";
			};
			class Revolving_2 {
				source = "revolving";
				weapon = "PKT_2";
			};
		};
		gunnerHasFlares = false;
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		transportMaxMagazines = 250;
		transportMaxWeapons = 100;
		transportMaxBackpacks = 10;
	};
	class Mi17_Civilian_Ori : Mi17_base
	{	
		vehicleClass = "Air";
		model = "\ca\air\Mi_8AMT";
		transportMaxMagazines = 250;
		transportMaxWeapons = 100;
		transportMaxBackpacks = 10;		
		radartype = 0;
		displayName = "Mi17c";
		scope = 2;
		side = 2;
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {};
		hiddenSelections[] = {};
		class TransportMagazines {};
		class TransportWeapons {};
		class Turrets: Turrets {};
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		weapons[] = {};
		magazines[] = {};
		gunnerHasFlares = false;
		threat[] = {0.0, 0.0, 0.0};
		hiddenSelectionsTextures[] = {"\CA\air\data\mi8civil_body_g_CO.paa", "\CA\air\data\mi8civil_det_g_CO.paa", "ca\air\data\clear_empty.paa", "ca\air\data\mi8_decals_ca.paa"};
		ejectDeadGunner = 1;
		ejectDeadCargo = 1;
		ejectDeadDriver = 1;
		ejectDeadCommander = 1;
	
	};
	
	//An2_TK_EP1
	class An2_Base_EP1;
	class AN2_Ori: An2_Base_EP1
	{
		displayName = "AN2";
		scope = 2;
		side = 2;
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {};
		hiddenSelections[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		weapons[] = {};
		magazines[] = {};
		gunnerHasFlares = false;
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		transportMaxMagazines = 350;
		transportMaxWeapons = 70;
		transportMaxBackpacks = 5;
	};
	//AH6X_EP1
	class AH6_Base_EP1;
	class AH6X_Ori : AH6_Base_EP1 
	{
		isUav = 0;
		accuracy = 2;
		scope = 2;
		displayName = "AH6X";
		faction = "rth_copter_class";
		gunnerHasFlares = false;
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		model = "\ca\air_e\ah6j\ah6x";
		picture = "\ca\air_e\data\UI\Picture_ah6x_CA.paa";
		icon = "\ca\air_e\data\UI\Icon_ah6x_CA.paa";
		side = 2;
		radarType = 0;
		camouflage = 4;
		audible = 6;
		crew = "";
		typicalCargo[] = {};
		class TransportMagazines {};
		class TransportWeapons {};
		enableManualFire = 0;
		weapons[] = {};
		magazines[] = {};
		transportMaxMagazines = 70;
		transportMaxWeapons = 20;
		transportMaxBackpacks = 2;
		class AnimationSources
		{
			class FLIR_gun
			{
				source = "user";
				animPeriod = 1e-005;
				initPhase = 0;
			};
			class FLIR_turret
			{
				source = "user";
				animPeriod = 1e-005;
				initPhase = 0;
			};
		};
		class Sounds {
			class Engine {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_engine_ext_1", 1.56228, 1.0, 180};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_rotor_ext_1", 1.56228, 1.0, 200};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8, 3.14, 2.0, 0.9};
			};
			class RotorHighOut {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_rotor_ext_high_1", 0.77828, 1.0, 210};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8, 3.14, 2.0, 0.9};
			};
			class EngineIn {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_engine_ext_1", 0.65893, 1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_rotor_ext_1", 0.65893, 1.0};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_rotor_ext_high_1", 0.89526, 1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
		class Turrets {};
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"ca\air_e\ah6j\data\ah6_merge1_co.paa"};
		ejectDeadGunner = 1;
		ejectDeadCargo = 1;
		ejectDeadDriver = 1;
		ejectDeadCommander = 1;
		armor = 27;
		class HitPoints {
			class HitHull {
				armor = 1;
				material = 51;
				name = "NEtrup";
				visual = "trup";
				passThrough = 1;
			};
			class HitEngine {
				armor = 0.5;
				material = 51;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitAvionics {
				armor = 0.25;
				material = 51;
				name = "elektronika";
				visual = "elektronika";
				passThrough = 1;
			};
			class HitVRotor {
				armor = 0.4;
				material = 51;
				name = "mala vrtule";
				visual = "mala vrtule staticka";
				passThrough = 0.3;
			};
			class HitHRotor {
				armor = 0.4;
				material = 51;
				name = "velka vrtule";
				visual = "velka vrtule staticka";
				passThrough = 0.1;
			};
			class HitGlass1 {
				armor = 0.6;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2 {
				armor = 0.6;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3 {
				armor = 0.6;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4 {
				armor = 0.6;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitRGlass {
				armor = 0.1;
				material = 51;
				name = "sklo predni P";
				visual = "sklo predni P";
				passThrough = 0;
			};
			class HitLGlass {
				armor = 0.1;
				material = 51;
				name = "sklo predni L";
				visual = "sklo predni L";
				passThrough = 0;
			};
		};
	};
	class MH6J_Ori : AH6_Base_EP1 
	{
		isUav = 0;
		accuracy = 2;
		scope = 2;
		displayName = "MH6J";
		faction = "rth_copter_class";
		gunnerHasFlares = false;
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		model = "\ca\air_e\ah6j\mh6j";
		picture = "\ca\air_e\data\UI\Picture_mh6j_CA.paa";
		icon = "\ca\air_e\data\UI\Icon_mh6j_CA.paa";
		side = 2;
		armor = 27;
		radarType = 0;
		camouflage = 4;
		audible = 6;
		transportSoldier = 5;
		crew = "";
		typicalCargo[] = {};
		cargoAction[] = {"AH6j_Cargo_EP1", "MH6_Cargo01", "MH6_Cargo02", "MH6_Cargo02", "MH6_Cargo02", "MH6_Cargo03"};
		cargoIsCoDriver[] = {1, 0};
		class TransportMagazines {};
		class TransportWeapons {};
		enableManualFire = 0;
		weapons[] = {};
		magazines[] = {};
		transportMaxMagazines = 70;
		transportMaxWeapons = 20;
		transportMaxBackpacks = 2;
		class Turrets {};
		class Sounds {
			class Engine {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_engine_ext_1", 1.56228, 1.0, 180};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_rotor_ext_1", 1.56228, 1.0, 200};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8, 3.14, 2.0, 0.9};
			};
			class RotorHighOut {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_rotor_ext_high_1", 0.77828, 1.0, 210};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8, 3.14, 2.0, 0.9};
			};
			class EngineIn {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_engine_ext_1", 0.65893, 1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_rotor_ext_1", 0.65893, 1.0};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn {
				sound[] = {"Ca\Sounds_E\Air_E\AH6\ah6_rotor_ext_high_1", 0.89526, 1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
		hiddenSelections[] = {"camo1", "camo2"};
		hiddenSelectionsTextures[] = {"ca\air_e\ah6j\data\ah6_merge1_co.paa", "ca\air_e\ah6j\data\default_co.paa"};
		ejectDeadGunner = 1;
		ejectDeadCargo = 1;
		ejectDeadDriver = 1;
		ejectDeadCommander = 1;
		class HitPoints {
			class HitHull {
				armor = 1;
				material = 51;
				name = "NEtrup";
				visual = "trup";
				passThrough = 1;
			};
			class HitEngine {
				armor = 0.25;
				material = 51;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitAvionics {
				armor = 0.15;
				material = 51;
				name = "elektronika";
				visual = "elektronika";
				passThrough = 1;
			};
			class HitVRotor {
				armor = 0.3;
				material = 51;
				name = "mala vrtule";
				visual = "mala vrtule staticka";
				passThrough = 0.3;
			};
			class HitHRotor {
				armor = 0.2;
				material = 51;
				name = "velka vrtule";
				visual = "velka vrtule staticka";
				passThrough = 0.1;
			};
			class HitGlass1 {
				armor = 0.6;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2 {
				armor = 0.6;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3 {
				armor = 0.6;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4 {
				armor = 0.6;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitRGlass {
				armor = 0.1;
				material = 51;
				name = "sklo predni P";
				visual = "sklo predni P";
				passThrough = 0;
			};
			class HitLGlass {
				armor = 0.1;
				material = 51;
				name = "sklo predni L";
				visual = "sklo predni L";
				passThrough = 0;
			};
		};
	};
	class MH60S_Ori : Helicopter 
	{
		scope = 2;
		displayName = "MH60S";
		faction = "rth_copter_class";
		destrType = "DestructWreck";
		vehicleClass = "Air";
		model = "\Ca\Air_E\UH60M\UH60M.p3d";
		mapSize = 17;
		picture = "\ca\air\data\ico\MH_60mg_CA.paa";
		Icon = "\ca\air\data\map_ico\icomap_MH60mg_CA.paa";
		side = 2;
		crew = "";
		accuracy = 1.5;
		attendant = 0;
		maxSpeed = 270;
		armor = 30;
		radarType = 0;
		damageResistance = 0.00242;
		mainRotorSpeed = 1.2;
		backRotorSpeed = 6.1;
		soundGetIn[] = {"Ca\Sounds_E\Air_E\UH1H\open_close", 0.316228, 1};
		soundGetOut[] = {"Ca\Sounds_E\Air_E\UH1H\open_close", 0.316228, 1, 40};
		soundEngineOnInt[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_start_int", 0.446684, 1.0};
		soundEngineOnExt[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_start_ext", 0.446684, 1.0, 700};
		soundEngineOffInt[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_stop_int", 0.446684, 1.0};
		soundEngineOffExt[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_stop_ext", 0.446684, 1.0, 700};
		
		class Sounds {
			class Engine {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_engine_ext_2", 1.0, 0.8, 800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			
			class RotorLowOut {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_rotor_ext_1", 2.51189, 1.1, 1400};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.6, 3.14, 2.0, 0.5};
			};
			
			class RotorHighOut {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_rotor_high_ext_1", 2.51189, 1.1, 1600};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.6, 3.14, 2.0, 0.5};
			};
			
			class EngineIn {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_engine_int_1", 1.0, 0.8};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			
			class RotorLowIn {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_rotor_int_1", 1.77828, 1.1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			
			class RotorHighIn {
				sound[] = {"Ca\Sounds_E\Air_E\UH1H\UH1H_rotor_high_int_1", 3.16228, 1.1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
		driverInAction = "UH60M_Pilot_EP1";
		driverAction = "UH60M_Pilot_EP1";
		cargoAction[] = {"UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02", "UH60_Cargo02"};
		transportSoldier = 13;
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		enableSweep = 0;
		transportAmmo = 0;
		supplyRadius = 2.5;
		initCargoAngleY = 10;
		minCargoAngleY = -60;
		maxCargoAngleY = 120;
		type = 2;
		threat[] = {0.3, 0, 0.4};
		typicalCargo[] = {};
		cargoIsCoDriver[] = {1, 0, 0};
		weapons[] = {};
		magazines[] = {};
		transportMaxMagazines = 250;
		transportMaxWeapons = 50;
		transportMaxBackpacks = 5;
		forceHideDriver = 1;
		castDriverShadow = 1;
		castCargoShadow = 1;
		ejectDeadGunner = 1;
		ejectDeadCargo = 1;
		ejectDeadDriver = 1;
		ejectDeadCommander = 1;

		class AnimationSources {
			class Gatling_1 {
				source = "revolving";
				weapon = M240_veh;
			};
			
			class Gatling_2 {
				source = "revolving";
				weapon = M240_veh_2;
			};
		};
		
		class Damage {
			tex[] = {};
			mat[] = {"ca\Air_E\UH60M\Data\uh60m_dust_filter.rvmat", "ca\Air_E\UH60M\Data\uh60m_dust_filter.rvmat", "ca\Air_E\UH60M\Data\uh60m_dust_filter_destruct.rvmat", "ca\Air_E\UH60M\Data\uh60m_engine.rvmat", "ca\Air_E\UH60M\Data\uh60m_engine.rvmat", "ca\Air_E\UH60M\Data\uh60m_engine_destruct.rvmat", "ca\Air_E\UH60M\Data\uh60m_fuselage.rvmat", "ca\Air_E\UH60M\Data\uh60m_fuselage.rvmat", "ca\Air_E\UH60M\Data\uh60m_fuselage_destruct.rvmat", "ca\Air_E\UH60M\Data\uh60m_interior.rvmat", "ca\Air_E\UH60M\Data\uh60m_interior.rvmat", "ca\Air_E\UH60M\Data\uh60m_interior_destruct.rvmat", "ca\Air_E\UH60M\Data\uh60m_navijak.rvmat", "ca\Air_E\UH60M\Data\uh60m_navijak.rvmat", "ca\Air_E\UH60M\Data\uh60m_navijak_destruct.rvmat", "ca\Air_E\UH60M\Data\uh60m_glass.rvmat", "ca\Air_E\UH60M\Data\uh60m_glass_damage.rvmat", "ca\Air_E\UH60M\Data\uh60m_glass_damage.rvmat", "ca\data\data\default.rvmat", "ca\data\data\default.rvmat", "ca\Air_E\UH60M\Data\default_destruct.rvmat", "ca\Air_E\UH60M\Data\uh60m_engine_MEV.rvmat", "ca\Air_E\UH60M\Data\uh60m_engine_MEV.rvmat", "ca\Air_E\UH60M\Data\uh60m_engine_MEV_destruct.rvmat", "ca\Air_E\UH60M\Data\uh60m_fuselage_MEV.rvmat", "ca\Air_E\UH60M\Data\uh60m_fuselage_MEV.rvmat", "ca\Air_E\UH60M\Data\uh60m_fuselage_MEV_destruct.rvmat", "Ca\Ca_E\data\default.rvmat", "Ca\Ca_E\data\default.rvmat", "Ca\Ca_E\data\default_destruct.rvmat"};
		};
		enableManualFire = 0;
		hiddenSelections[] = {"camo1", "camo2", "camo3"};
		hiddenSelectionsTextures[] = {"ca\air_e\uh60m\data\uh60m_fuselage_co.paa", "ca\air_e\uh60m\data\uh60m_engine_co.paa", "ca\air_e\uh60m\data\default_co.paa"};
		
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				body = "mainTurret";
				gun = "mainGun";
				minElev = -80;
				maxElev = 25;
				initElev = -80;
				minTurn = 30;
				maxTurn = 150;
				initTurn = 90;
				soundServo[] = {"", 0.01, 1.0};
				stabilizedInAxes = "StabilizedInAxesNone";
				gunBeg = "muzzle_1";
				gunEnd = "chamber_1";
				weapons[] = {"M240_veh"};
				magazines[] = {"100Rnd_762x51_M240", "100Rnd_762x51_M240", "100Rnd_762x51_M240"};
				gunnerName = $STR_POSITION_CREWCHIEF;
				gunnerOpticsModel = "\ca\weapons\optika_empty";
				gunnerOutOpticsShowCursor = 1;
				gunnerOpticsShowCursor = 1;
				gunnerAction = "UH60M_Gunner_EP1";
				gunnerInAction = "UH60M_Gunner_EP1";
				gunnerCompartments = "Compartment1";
				primaryGunner = 1;
				commanding = -3;
				
				
				class ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
			};
			
			class RightDoorGun : MainTurret {
				body = "Turret_2";
				gun = "Gun_2";
				animationSourceBody = "Turret_2";
				animationSourceGun = "Gun_2";
				animationSourceHatch = "";
				selectionFireAnim = "zasleh_1";
				proxyIndex = 2;
				gunnerName = $STR_POSITION_DOORGUNNER;
				commanding = -3;
				minTurn = -150;
				maxTurn = -30;
				initTurn = -90;
				weapons[] = {"M240_veh_2"};
				stabilizedInAxes = "StabilizedInAxesNone";
				gunBeg = "muzzle_2";
				gunEnd = "chamber_2";
				primaryGunner = 0;
				gunnerCompartments = "Compartment1";
				memoryPointGun = "machinegun_2";
				memoryPointGunnerOptics = "gunnerview_2";
			};
		};
		
		class Reflectors {
			class Left {
				color[] = {0.8, 0.8, 1.0, 1.0};
				ambient[] = {0.07, 0.07, 0.07, 1.0};
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 1;
				brightness = 1.0;
			};
			
			class Right {
				color[] = {0.8, 0.8, 1.0, 1.0};
				ambient[] = {0.07, 0.07, 0.07, 1.0};
				position = "P svetlo";
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 1;
				brightness = 1.0;
			};
		};
	};
	class HC3_Merlin_Ori: Helicopter	
	{
		scope = 2;
		side = 2;
		displayname = "HC3 Merlin";
		faction = "rth_copter_class";
		model = "\Ca\air_d_baf\MerlinHC3_BAF";
		picture = "\Ca\air_d_baf\Data\UI\picture_merlin_ca.paa";
		icon = "\Ca\air_d_baf\Data\UI\icon_merlin_ca.paa";
		mapSize = 20;
//		crewVulnerable = 1;
		crew = "";
		typicalCargo[] = {};
		driverAction = "Merlin_Pilot_BAF";
		cargoIsCoDriver[] = {1,0};
		GetInAction = "GetInHigh";
		GetOutAction = "GetOutHigh";
		cargoAction[] = {"Merlin_Cargo_BAF","Merlin_Cargo01_BAF","Merlin_Cargo_BAF","Merlin_Cargo01_BAF","Merlin_Cargo01_BAF","Merlin_Cargo_BAF","Merlin_Cargo01_BAF","Merlin_Cargo_BAF","Merlin_Cargo01_BAF","Merlin_Cargo01_BAF","Merlin_Cargo_BAF","Merlin_Cargo01_BAF","Merlin_Cargo01_BAF","Merlin_Cargo_BAF","Merlin_Cargo01_BAF","Merlin_Cargo_BAF","Merlin_Cargo01_BAF"};
		memoryPointsGetInCargo[] = {"pos codriver","pos cargo"};
		memoryPointsGetInCargoDir[] = {"pos codriver dir","pos cargo dir"};
		transportSoldier = 17;
		radarType = 0;
		enableManualFire = 0;
		class Reflectors
		{
			class Light
			{
				color[] = {0.8,0.8,1.0,1.0};
				ambient[] = {0.07,0.07,0.07,1.0};
				position = "light_1_1_pos";
				direction = "light_1_1_dir";
				hitpoint = "light_1_1_pos";
				selection = "L svetlo";
				size = 1;
				brightness = 1.0;
			};
		};
		class MarkerLights
		{
			class GreenStill
			{
				name = "light_nav_right";
				color[] = {0.006,0.12,0.006,1.0};
				ambient[] = {0.01,0.1,0.01,1.0};
				brightness = 0.001;
				blinking = 0;
			};
			class WhiteBlinking
			{
				name = "light_nav_top";
				color[] = {0.0388,0.0388,0.0388,1.0};
				ambient[] = {0.03,0.023,0.0056,1.0};
				brightness = 0.001;
				blinking = 1;
			};
			class RedStill
			{
				name = "light_nav_left";
				color[] = {0.12,0.006,0.006,1.0};
				ambient[] = {0.1,0.01,0.01,1.0};
				brightness = 0.001;
				blinking = 0;
			};
		};
		class AnimationSources: AnimationSources
		{
			class Doors
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class OpenRdoor
			{
				displayName = "$STR_BAF_CFGVEHICLES_BAF_MERLIN_HC3_D_USERACTIONS_OPENRDOOR0";
				position = "axis_door_side_pop";
				radius = 3.6;
				onlyForplayer = 0;
				condition = "this animationPhase ""dvere_p"" > 0.5 AND Alive(this)";
				statement = "this animate [""dvere_p"",0];this animate [""dvere_p_pop"",0];";
			};
			class CloseRdoor
			{
				displayName = "$STR_BAF_CFGVEHICLES_BAF_MERLIN_HC3_D_USERACTIONS_CLOSERDOOR0";
				position = "axis_door_side_pop";
				radius = 3.6;
				onlyForplayer = 0;
				condition = "this animationPhase ""dvere_p"" < 0.5 AND Alive(this)";
				statement = "this animate [""dvere_p"",1];this animate [""dvere_p_pop"",1];";
			};
			class OpenLdoor
			{
				displayName = "$STR_BAF_CFGVEHICLES_BAF_MERLIN_HC3_D_USERACTIONS_OPENLDOOR0";
				position = "axis_door_crew_pop";
				radius = 3.6;
				onlyForplayer = 0;
				condition = "this animationPhase ""dvere_l"" > 0.5 AND Alive(this)";
				statement = "this animate [""dvere_l"",0];this animate [""dvere_l_pop"",0];";
			};
			class CloseLdoor
			{
				displayName = "$STR_BAF_CFGVEHICLES_BAF_MERLIN_HC3_D_USERACTIONS_CLOSELDOOR0";
				position = "axis_door_crew_pop";
				radius = 3.6;
				onlyForplayer = 0;
				condition = "this animationPhase ""dvere_l"" < 0.5 AND Alive(this)";
				statement = "this animate [""dvere_l"",1];this animate [""dvere_l_pop"",1];";
			};
		};
		maxSpeed = 309;
		accuracy = 1.5;
		cost = 10000000;
		armor = 40;
		damageResistance = 0.00355;
		vehicleClass = "Air";
		laserScanner = 1;
		MainRotorSpeed = 1.0;
		backRotorSpeed = 1.0;
		gearRetracting = 1;
		gearUpTime = 1;
		gearDownTime = 1;
		weapons[] = {};
		magazines[] = {};
		LockDetectionSystem = 1118208;
		IncommingMisslieDetectionSystem = 16;
		irScanRangeMin = 0;
		irScanRangeMax = 1000;
		nightVision = 1;
		class Turrets: Turrets{};
		selectionFireAnim = "zasleh";
		threat[] = {0.4,0,0};
		destrType = "DestructWreck";
		class HitPoints: HitPoints
		{
			class HitHull
			{
				armor = 1;
				material = 51;
				name = "NEtrup";
				visual = "trup";
				passThrough = 0.5;
			};
			class HitEngine
			{
				armor = 0.5;
				material = 51;
				name = "motor";
				visual = "motor";
				passThrough = 0.5;
			};
			class HitAvionics
			{
				armor = 0.15;
				material = 51;
				name = "elektronika";
				visual = "elektronika";
				passThrough = 0.2;
			};
			class HitVRotor
			{
				armor = 0.3;
				material = 51;
				name = "mala vrtule";
				visual = "mala vrtule staticka";
				passThrough = 0.1;
			};
			class HitHRotor
			{
				armor = 0.2;
				material = 51;
				name = "velka vrtule";
				visual = "velka vrtule staticka";
				passThrough = 0.1;
			};
			class HitGlass1: HitGlass1
			{
				armor = 0.5;
			};
			class HitGlass2: HitGlass2
			{
				armor = 0.5;
			};
			class HitGlass3: HitGlass3
			{
				armor = 0.5;
			};
			class HitGlass4: HitGlass4
			{
				armor = 0.5;
			};
			class HitGlass5: HitGlass5
			{
				armor = 0.5;
			};
			
			class HitGlass6: HitGlass6
			{
				armor = 0.5;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\air_d_BAF\Data\merlin_int_01.rvmat","ca\air_d_BAF\Data\merlin_int_01_damage.rvmat","ca\air_d_BAF\Data\merlin_int_01_destruct.rvmat","ca\air_d_BAF\Data\merlin_int_02.rvmat","ca\air_d_BAF\Data\merlin_int_02_damage.rvmat","ca\air_d_BAF\Data\merlin_int_02_destruct.rvmat","ca\air_d_BAF\Data\Merlin_glass.rvmat","ca\air_d_BAF\Data\Merlin_glass_damage.rvmat","ca\air_d_BAF\Data\Merlin_glass_damage.rvmat","ca\air_d_BAF\Data\MerlinHc3_2_BAF.rvmat","ca\air_d_BAF\Data\MerlinHc3_2_BAF_damage.rvmat","ca\air_d_BAF\Data\MerlinHc3_2_BAF_destruct.rvmat","ca\air_d_BAF\Data\MerlinHc3_1_BAF.rvmat","ca\air_d_BAF\Data\MerlinHc3_1_BAF_damage.rvmat","ca\air_d_BAF\Data\MerlinHc3_1_BAF_destruct.rvmat"};
		};
		soundGetIn[] = {"Ca\sounds_baf\air\getin",0.31622776,1};
		soundGetOut[] = {"Ca\sounds_baf\air\getin",0.31622776,1,40};
		soundDammage[] = {"Ca\sounds_baf\air\int-alarm_loop",0.56234133,1};
		soundEngineOnInt[] = {"Ca\sounds_baf\air\uk_start_int_1",0.1,1.1};
		soundEngineOnExt[] = {"Ca\sounds_baf\air\uk_start_ext_1",0.56234133,1.1,800};
		soundEngineOffInt[] = {"\Ca\sounds_baf\air\uk_stop_int_1",0.1,1.1};
		soundEngineOffExt[] = {"Ca\sounds_baf\air\uk_stop_ext_2",0.56234133,1.1,800};
		soundLocked[] = {"Ca\sounds_baf\air\int-alarm_loop",0.00031622776,2};
		soundIncommingMissile[] = {"Ca\sounds_baf\air\int-alarm_loop",0.00031622776,4};
		class Sounds
		{
			class Engine
			{
				sound[] = {"Ca\sounds_baf\air\uk_engine_ext_3",3.1622777,1.0,1000};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"\Ca\sounds_baf\air\uk_rotor_4l",3.1622777,1,1200};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2.0,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"\Ca\sounds_baf\air\uk_rotor_4h_swist",1.7782794,1,1300};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8,3.14,2.0,0.9};
			};
			class EngineIn
			{
				sound[] = {"\Ca\sounds_baf\air\uk_engine_int_1",0.56234133,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"Ca\sounds_baf\air\uk_rotor_4l_int",1.7782794,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"Ca\sounds_baf\air\uk_rotor_4h_int",1.7782794,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
		supplyRadius = 5;
		class TransportMagazines {};
		class TransportWeapons {};
		transportMaxMagazines = 250;
		transportMaxWeapons = 100;
		transportMaxBackpacks = 15;
		ejectDeadGunner = 1;
		ejectDeadCargo = 1;
		ejectDeadDriver = 1;
		ejectDeadCommander = 1;
	};
	class Ka60c_Ori: Helicopter
	{
		expansion = 4;
		scope = 2;
		side = 2;
		destrType = "DestructWreck";
		armor = 25;
		radarType = 0;
		displayName = "Ka60C";
		faction = "rth_copter_class";
		model = "\Ca\Air_PMC\Ka60\Ka60_PMC.p3d";
		icon = "\Ca\Air_PMC\data\ui\Icon_ka60_PMC_ca.paa";
		picture = "\Ca\Air_PMC\data\ui\picture_ka60_PMC_ca.paa";
		driverAction = "UH1H_Pilot_EP1";
		driverInAction = "UH1H_Pilot_EP1";
		transportSoldier = 8;
		cargoAction[] = {"UH1H_Cargo_EP1","UH60_Cargo02"};
		cargoIsCoDriver[] = {1,0};
		weapons[] = {};
		magazines[] = {};
		enableManualFire = 0;
		transportMaxMagazines = 250;
		transportMaxWeapons = 20;
		transportMaxBackpacks = 5;
		ejectDeadGunner = 1;
		ejectDeadCargo = 1;
		ejectDeadDriver = 1;
		ejectDeadCommander = 1;
		class HitPoints: HitPoints
		{
			class HitGlass1 : HitGlass1 {
				armor = 0.12;
			};
			
			class HitGlass2 : HitGlass2 {
				armor = 0.12;
			};
			
			class HitGlass3 : HitGlass3 {
				armor = 0.12;
			};
			
			class HitGlass4 : HitGlass4 {
				armor = 0.12;
			};
			
			class HitGlass5 : HitGlass5 {
				armor = 0.12;
			};
			
			class HitGlass6 : HitGlass6 {
				armor = 0.12;
			};
			class HitVRotor: HitVRotor
			{
				armor = 1;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				body = "mainTurret";
				gun = "mainGun";
				minElev = -50;
				maxElev = 30;
				initElev = 0;
				minTurn = 20;
				maxTurn = 155;
				initTurn = 70;
				soundServo[] = {"",0.01,1.0};
				animationSourceHatch = "";
				stabilizedInAxes = "StabilizedInAxesNone";
				gunBeg = "muzzle_1";
				gunEnd = "chamber_1";
				weapons[] = {"PKT_spec"};
				maxHorizontalRotSpeed = 1.6;
				maxVerticalRotSpeed = 1.6;
				magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
				gunnerName = "$STR_POSITION_DOORGUNNER";
				gunnerForceOptics = 1;
				gunnerAction = "Mi8_Gunner";
				gunnerInAction = "Mi8_Gunner";
				commanding = -3;
				primaryGunner = 1;
				discreteDistance[] = {500,600,700,800,900};
				discreteDistanceInitIndex = 1;
				gunnerOpticsModel = "\ca\weapons\2Dscope_Pecheneg";
				//turretInfoType = "RscWeaponRangeZeroing";
				turretInfoType = "RscWeaponZeroing";

				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = -10;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.100;
						minFov = 0.100;
						maxFov = 0.100;
						visionMode[] = {"Normal", NVG};
						gunnerOpticsModel = "\ca\weapons\2Dscope_Pecheneg";
					};
					class Medium: Wide
					{
						opticsDisplayName = "M";
						initFov = 0.063;
						minFov = 0.063;
						maxFov = 0.063;
						gunnerOpticsModel = "\ca\weapons\2Dscope_Pecheneg";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "N";
						gunnerOpticsModel = "\ca\weapons\2Dscope_Pecheneg";
						initFov = 0.019;
						minFov = 0.019;
						maxFov = 0.019;
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = -10;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 1.1;
						minFov = 0.133;
						maxFov = 1.1;
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
			
				
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				
				gunnerCompartments = "Compartment1";
			};
		};
		
		class Damage
		{
			tex[] = {};
			mat[] = {"Ca\Air_PMC\Ka60\Data\ka60_ext.rvmat","Ca\Air_PMC\Ka60\Data\ka60_ext_damage.rvmat","Ca\Air_PMC\Ka60\Data\ka60_ext_destruct.rvmat","Ca\Air_PMC\Ka60\Data\ka60_glass.rvmat","Ca\Air_PMC\Ka60\Data\ka60_glass_damage.rvmat","Ca\Air_PMC\Ka60\Data\ka60_glass_destruct.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default_destruct.rvmat"};
		};
		soundGetIn[] = {"Ca\Sounds_PMC\Air_PMC\Ka_door",0.31622776,1};
		soundGetOut[] = {"Ca\Sounds_PMC\Air_PMC\Ka_door",0.31622776,1,40};
		soundDammage[] = {"Ca\Sounds_PMC\Air_PMC\int-alarm_loop",0.56234133,1};
		soundEngineOnInt[] = {"Ca\Sounds_PMC\Air_PMC\Ka_start_int_1",0.1,1.0};
		soundEngineOnExt[] = {"Ca\Sounds_PMC\Air_PMC\Ka_start_ext_1",0.56234133,1.0,800};
		soundEngineOffInt[] = {"Ca\Sounds_PMC\Air_PMC\Ka_stop_int_1",0.1,1.0};
		soundEngineOffExt[] = {"Ca\Sounds_PMC\Air_PMC\Ka_stop_ext_1",0.56234133,1.0,800};
		class Sounds
		{
			class Engine
			{
				sound[] = {"Ca\Sounds_PMC\Air_PMC\Ka_engi_r_ext",3.1622777,1.4,800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"Ca\Sounds_PMC\Air_PMC\KA_rotor_orig",3.1622777,1.0,1400};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2.0,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"Ca\Sounds_PMC\Air_PMC\KA_rotor_orig_high_swist",5.623413,1.0,1500};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.1,3.14,2.0,0.9};
			};
			class EngineIn
			{
				sound[] = {"Ca\Sounds_PMC\Air_PMC\Ka_engi_int_1",3.1622777,1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"Ca\Sounds_PMC\Air_PMC\KA_rotor_orig",0.56234133,1.0};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"Ca\Sounds_PMC\Air_PMC\KA_rotor_orig_high_swist",0.31622776,1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
		class Library
		{
			libTextDesc = "$STR_PMC_LIB_KA60";
		};
		class AnimationSources: AnimationSources
		{
			class Doors
			{
				source = "user";
				animPeriod = 1;
				initPhase = 1;
			};
			class HideWeapon
			{
				source = "user";
				animPeriod = 1e-005;
				initPhase = 0;
			};
			class ReloadAnim
			{
				source = "reload";
				weapon = "PKT_spec";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "PKT_spec";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "PKT_spec";
			};
			
		};
	};
	class Mi171ShCZ_Ori : Mi17_base
	{
		scope = 2;
		side = 2;
		model = "\ca\Air_E\Mi17\Mi_171";
		picture = "\ca\air\data\ico\mi17_HIP_CA.paa";
		Icon = "\ca\air\data\map_ico\icomap_mi17_CA.paa";
		enableSweep = 0;
		displayName = "Mi-171Sh";
		faction = "rth_copter_class";
		crew = "";
		armor = 20;
		typicalCargo[] = {};
		weapons[] = {};
		magazines[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		transportMaxMagazines = 250;
		transportMaxWeapons = 100;
		transportMaxBackpacks = 10;
		radarType = 0;
		threat[] = {1, 1, 1};
		LockDetectionSystem = 0;
		IncommingMisslieDetectionSystem = 0;
		hiddenSelectionsTextures[] = {"\CA\air_E\data\mi17_body_ACR_CO.paa","\CA\air_E\data\mi17_det_ACR_CO.paa","\ca\air_E\Data\mi17_decals2_ACR_CA.paa","\ca\air\data\mi8_decals_ca.paa"};
		class UserActions{};
		class Turrets: Turrets
		{
			class LeftTurret: MainTurret
			{
				proxyIndex = 2;
				primaryGunner = 0;
				//gunnerName = "door gunner";
				gunnerName = "crew chief";
				minElev = -50;
				maxElev = 30;
				initElev = 11;
				minTurn = 20;
				maxTurn = 155;
				initTurn = 80;
				gunnerCompartments = "Compartment1";
				commanding = -3;
				magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
			};
			class BackTurret: BackTurret
			{
				//gunnerName = "Rear gunner";
				gunnerName = "rear gunner";
				primaryGunner = 0;
				proxyIndex = 3;
				gunnerAction = "Mi171_Gunner_EP1";
				gunnerInAction = "Mi171_Gunner_EP1";
				minTurn = 130;
				maxTurn = 230;
				initTurn = 180;
				minElev = -50;
				maxElev = 10;
				initElev = 0;
				gunnerCompartments = "Compartment1";
				commanding = -3;
				magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
			};
			class RightTurret: MainTurret
			{
				proxyIndex = 1;
				//gunnerName = "crew chief";
				gunnerName = "door gunner";
				body = "Turret_3";
				gun = "Gun_3";
				animationSourceBody = "Turret_3";
				animationSourceGun = "Gun_3";
				minElev = -60;
				maxElev = 30;
				initElev = 11;
				minTurn = -155;
				maxTurn = -30;
				initTurn = -70;
				weapons[] = {"PKT_3"};
				stabilizedInAxes = "StabilizedInAxesNone";
				gunBeg = "muzzle_3";
				gunEnd = "chamber_3";
				gunnerAction = "Mi8_Gunner";
				gunnerInAction = "Mi8_Gunner";
				memoryPointGun = "muzzle_3";
				memoryPointGunnerOptics = "gunnerview3";
				selectionFireAnim = "zasleh3";
				primaryGunner = 1;
				gunnerCompartments = "Compartment1";
				commanding = -3;
				magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class HUDaction
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class HUDaction_Hide: HUDaction
			{
			};
			class ReloadAnim_3
			{
				source = "reload";
				weapon = "PKT_3";
			};
			class ReloadMagazine_3
			{
				source = "reloadmagazine";
				weapon = "PKT_3";
			};
			class Revolving_3
			{
				source = "revolving";
				weapon = "PKT_3";
			};
			class HIDE_weapon_holders
			{
				source = "user";
				animPeriod = 1e-007;
				initPhase = 1;
			};
			class HIDE_front_armor: HIDE_weapon_holders
			{
				initPhase = 1;
			};
			class HIDE_exhaust: HIDE_weapon_holders
			{
				initPhase = 1;
			};
		};
	};
	class HMMWV_Base;
	class HMMWV_Ori : HMMWV_Base
	{
		scope = 2;
		accuracy = 0.02;
		camouflage = 2;
		picture = "\Ca\wheeled\data\ico\HMMWV_CA.paa";
		Icon = "\Ca\wheeled\data\map_ico\icomap_hmwv_CA.paa";
		mapSize = 5;
		displayName = "HMMWV US";
		hasGunner = 0;
		armor = 40;
		class Turrets
		{
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\wheeled\hmmwv\data\hmmwv_details.rvmat","Ca\wheeled\HMMWV\data\hmmwv_details_damage.rvmat","Ca\wheeled\HMMWV\data\hmmwv_details_destruct.rvmat","ca\wheeled\hmmwv\data\hmmwv_body.rvmat","Ca\wheeled\HMMWV\data\hmmwv_body_damage.rvmat","Ca\wheeled\HMMWV\data\hmmwv_body_destruct.rvmat","ca\wheeled\hmmwv\data\hmmwv_clocks.rvmat","ca\wheeled\hmmwv\data\hmmwv_clocks.rvmat","ca\wheeled\data\hmmwv_clocks_destruct.rvmat","ca\wheeled\HMMWV\data\hmmwv_glass.rvmat","ca\wheeled\HMMWV\data\hmmwv_glass_Half_D.rvmat","ca\wheeled\HMMWV\data\hmmwv_glass_Half_D.rvmat","ca\wheeled\HMMWV\data\hmmwv_glass_in.rvmat","ca\wheeled\HMMWV\data\hmmwv_glass_in_Half_D.rvmat","ca\wheeled\HMMWV\data\hmmwv_glass_in_Half_D.rvmat"};
		};
		hiddenSelections[] = {"Camo1"};
		//hiddenSelectionsTextures[] = {"\ca\wheeled\hmmwv\data\hmmwv_body_co.paa"};
		hiddenSelectionsTextures[] = {"\origins_pack\vehicles\skins\hmmwv\hmmwv_telo_co.paa"};
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {};
		weapons[] = {};
		magazines[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		transportMaxMagazines = 150;
		transportMaxWeapons = 20;
		transportMaxBackpacks = 5;
		model = "ca\wheeled_E\HMMWV\HMMWV";
	};
	class Pickup_PK_base;
	class Pickup_PK_Ori : Pickup_PK_base {
		scope = 2;
		side = 2;
		displayName = "Pickup PK";
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {};
		weapons[] = {};
		magazines[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		hiddenSelectionsTextures[] = {"\ca\wheeled\datsun_armed\data\datsun_trup3_CO.paa"};
		transportMaxMagazines = 150;
		transportMaxWeapons = 20;
		class Damage {
			tex[] = {};
			mat[] = {"ca\wheeled\hilux_armed\data\detailmapy\coyota_armed.rvmat", "ca\wheeled\hilux_armed\data\detailmapy\coyota_armed.rvmat", "ca\wheeled\hilux_armed\data\detailmapy\coyota_armed_destruct.rvmat", "ca\weapons\data\dshk.rvmat", "ca\weapons\data\dshk.rvmat", "ca\weapons\data\dshk_destruct.rvmat", "ca\weapons\data\tripod_dshk.rvmat", "ca\weapons\data\tripod_dshk.rvmat", "ca\wheeled\hilux_armed\data\detailmapy\tripod_dshk_destruct.rvmat", "ca\weapons\data\pkm.rvmat", "ca\weapons\data\pkm.rvmat", "ca\weapons\data\pkm_destruct.rvmat", "ca\wheeled\data\detailmapy\datsun_interier.rvmat", "ca\wheeled\data\detailmapy\datsun_interier.rvmat", "ca\wheeled\data\detailmapy\datsun_interier_destruct.rvmat", "ca\wheeled\datsun_armed\data\detailmapy\datsun_trup.rvmat", "ca\wheeled\datsun_armed\data\detailmapy\datsun_trup.rvmat", "ca\wheeled\datsun_armed\data\detailmapy\datsun_trup_destruct.rvmat", "ca\wheeled\datsun_armed\data\detailmapy\datsun_trup_b.rvmat", "ca\wheeled\datsun_armed\data\detailmapy\datsun_trup_b.rvmat", "ca\wheeled\datsun_armed\data\detailmapy\datsun_trupb_destruct.rvmat", "ca\wheeled\data\detailmapy\coyota_kola.rvmat", "ca\wheeled\data\detailmapy\coyota_kola.rvmat", "ca\wheeled\data\detailmapy\coyota_kola_destruct.rvmat", "ca\wheeled\data\detailmapy\coyota_interier.rvmat", "ca\wheeled\data\detailmapy\coyota_interier.rvmat", "ca\wheeled\data\detailmapy\coyota_interier_destruct.rvmat", "ca\wheeled\data\detailmapy\auta_skla.rvmat", "ca\wheeled\data\detailmapy\auta_skla_damage.rvmat", "ca\wheeled\data\detailmapy\auta_skla_damage.rvmat", "ca\wheeled\data\detailmapy\auta_skla_in.rvmat", "ca\wheeled\data\detailmapy\auta_skla_in_damage.rvmat", "ca\wheeled\data\detailmapy\auta_skla_in_damage.rvmat"};
		};
	};
	class UAZ_MG_Base;
	class UAZ_MG_Ori : UAZ_MG_Base {
		scope = 2;
		side = 2;
		displayName = "UAZ MG";
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {};
		weapons[] = {};
		magazines[] = {};
		gunnerHasFlares = false;
		class TransportMagazines{};
		class TransportWeapons{};
		hiddenSelectionsTextures[] = {"\ca\wheeled\data\Uaz_main_002_CO.paa", "\ca\wheeled\data\uaz_mount_002_co.paa"};
		transportMaxMagazines = 150;
		transportMaxWeapons = 20;
	};
	class Offroad_DSHKM_base;
	class Offroad_MG_Ori : Offroad_DSHKM_base {
		htMin = 60;
		htMax = 1800;
		afMax = 200;
		mfMax = 100;
		mFact = 1;
		tBody = 250;
		expansion = 1;
		scope = 2;
		side = 2;
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {};
		weapons[] = {};
		magazines[] = {};
		displayName = "Offroad MG";
		hiddenSelectionsTextures[] = {"\CA\wheeled_E\Hilux_Armed\Data\coyota_trup1_EINS_CO.paa"};
		
		class TransportMagazines {};
		class TransportWeapons {};
		transportMaxMagazines = 150;
		transportMaxWeapons = 20;
	};
	
	class Land;	// External class reference
	class LandVehicle : Land {
		class NewTurret;	// External class reference
	};
	class Car : LandVehicle {
		class HitPoints {
			class HitLFWheel;	// External class reference
			class HitLBWheel;	// External class reference
			class HitLMWheel;	// External class reference
			class HitLF2Wheel;	// External class reference
			class HitRFWheel;	// External class reference
			class HitRBWheel;	// External class reference
			class HitRMWheel;	// External class reference
			class HitRF2Wheel;	// External class reference
			class HitGlass1;	// External class reference
			class HitGlass2;	// External class reference
			class HitGlass3;	// External class reference
		};
		class Turrets {
			class MainTurret : NewTurret {
				class ViewOptics;	// External class reference
			};
		};
		class AnimationSources;	// External class reference
	};
	class LandRover_Base_Ori : Car {
		brakeDistance = 12.5;
		expansion = 1;
		enableManualFire = 0;
		htMin = 60;
		htMax = 1800;
		afMax = 100;
		mfMax = 80;
		mFact = 1;
		tBody = 250;
		scope = 0;
		displayname = "$STR_EP1_DN_LandRover_Base";
		maxSpeed = 150;
		terrainCoef = 3.0;
		turnCoef = 3;
		armor = 30;
		damageResistance = 0.00719;
		model = "\ca\wheeled_E\LR\LR";
		Picture = "\CA\wheeled_e\Data\UI\Picture_lr_CA.paa";
		Icon = "\CA\wheeled_e\Data\UI\Icon_lr_transport_CA.paa";
		MapSize = 6;
		outsideSoundFilter = 1;
		insideSoundCoef = 0.9;
		soundGear[] = {"", 5.62341e-005, 1};
		soundGetIn[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_door", 1.0, 1};
		soundGetOut[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_door", 1.0, 1, 30};
		soundEngineOnInt[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_int_start", 1.0, 1.0};
		soundEngineOnExt[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_ext_start", 1.0, 1.0, 100};
		soundEngineOffInt[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_int_stop", 1.0, 1.0};
		soundEngineOffExt[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_ext_stop", 1.0, 1.0, 100};
		buildCrash0[] = {"Ca\sounds\Vehicles\Crash\tank_building_01", 0.707946, 1, 150};
		buildCrash1[] = {"Ca\sounds\Vehicles\Crash\tank_building_02", 0.707946, 1, 150};
		buildCrash2[] = {"Ca\sounds\Vehicles\Crash\tank_building_03", 0.707946, 1, 150};
		buildCrash3[] = {"Ca\sounds\Vehicles\Crash\tank_building_04", 0.707946, 1, 150};
		soundBuildingCrash[] = {"buildCrash0", 0.25, "buildCrash1", 0.25, "buildCrash2", 0.25, "buildCrash3", 0.25};
		WoodCrash0[] = {"Ca\sounds\Vehicles\Crash\tank_wood_01", 0.707946, 1, 150};
		WoodCrash1[] = {"Ca\sounds\Vehicles\Crash\tank_wood_02", 0.707946, 1, 150};
		WoodCrash2[] = {"Ca\sounds\Vehicles\Crash\tank_wood_03", 0.707946, 1, 150};
		WoodCrash3[] = {"Ca\sounds\Vehicles\Crash\tank_wood_04", 0.707946, 1, 150};
		soundWoodCrash[] = {"woodCrash0", 0.25, "woodCrash1", 0.25, "woodCrash2", 0.25, "woodCrash3", 0.25};
		ArmorCrash0[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_01", 0.707946, 1, 150};
		ArmorCrash1[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_02", 0.707946, 1, 150};
		ArmorCrash2[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_03", 0.707946, 1, 150};
		ArmorCrash3[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_04", 0.707946, 1, 150};
		soundArmorCrash[] = {"ArmorCrash0", 0.25, "ArmorCrash1", 0.25, "ArmorCrash2", 0.25, "ArmorCrash3", 0.25};
		
		class SoundEvents {
			class AccelerationIn {
				sound[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_int_acceleration", 0.562341, 1.0};
				limit = 0.15;
				expression = "engineOn*(1-camPos)*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
			
			class AccelerationOut {
				sound[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_ext_acceleration", 0.562341, 1.0, 300};
				limit = 0.15;
				expression = "engineOn*camPos*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
		};
		
		class Sounds {
			class Engine {
				sound[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_ext_low", 1.41254, 0.6, 200};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "camPos*engineOn*((rpm factor[0.3, 0.4]) min (rpm factor[0.7, 0.5]))";
			};
			
			class EngineHighOut {
				sound[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_ext_high", 1.41254, 0.6, 300};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "camPos*engineOn*(rpm factor[0.5, 0.8])";
			};
			
			class IdleOut {
				sound[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_ext_idle", 0.562341, 1.0, 100};
				frequency = "1";
				volume = "engineOn*camPos*(rpm factor[0.4, 0])";
			};
			
			class TiresRockOut {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-rock2", 0.1, 1.0, 50};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			
			class TiresSandOut {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-sand2", 0.1, 1.0, 50};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			
			class TiresGrassOut {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-grass3", 0.1, 1.0, 50};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			
			class TiresMudOut {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-mud2", 0.1, 1.0, 50};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			
			class TiresGravelOut {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-gravel2", 0.1, 1.0, 50};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			
			class TiresAsphaltOut {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-asphalt3", 0.1, 1.0, 50};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			
			class NoiseOut {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Noises\ext\noise3", 0.562341, 1.0, 50};
				frequency = "1";
				volume = "camPos*(damper0 max 0.04)*(speed factor[0, 8])";
			};
			
			class EngineLowIn {
				sound[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_int_low", 1.41254, 0.6};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "(1-camPos)*engineOn*((rpm factor[0.3, 0.4]) min (rpm factor[0.7, 0.5]))";
			};
			
			class EngineHighIn {
				sound[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_int_high", 1.41254, 0.6};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "(1-camPos)*engineOn*(rpm factor[0.5, 0.8])";
			};
			
			class IdleIn {
				sound[] = {"\ca\Sounds_E\Wheeled_E\LandRover\LRover_int_idle", 0.794328, 1.0};
				frequency = "1";
				volume = "engineOn*(rpm factor[0.4, 0])*(1-camPos)";
			};
			
			class TiresRockIn {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-rock2", 0.1, 1.0};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			
			class TiresSandIn {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-sand2", 0.1, 1.0};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			
			class TiresGrassIn {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-grass3", 0.1, 1.0};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			
			class TiresMudIn {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-mud2", 0.1, 1.0};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			
			class TiresGravelIn {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-gravel2", 0.1, 1.0};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			
			class TiresAsphaltIn {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-asphalt3", 0.1, 1.0};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			
			class NoiseIn {
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Noises\int\noise4", 0.316228, 1.0};
				frequency = "1";
				volume = "(damper0 max 0.04)*(speed factor[0, 8])*(1-camPos)";
			};
			
			class Movement {
				sound = "soundEnviron";
				frequency = "1";
				volume = "0";
			};
		};
		
		class Library {
			libTextDesc = "$STR_EP1_LIB_LandRover";
		};
		transportSoldier = 7;
		driverAction = "LR_Driver_EP1";
		cargoAction[] = {"LR_Cargo01_EP1", "LR_Cargo02_EP1", "LR_Cargo03_EP1", "LR_Cargo05_EP1", "LR_Cargo04_EP1", "LR_Cargo02_EP1", "LR_Cargo03_EP1"};
		cargoIsCoDriver[] = {1, 0};
		
		class HitPoints : HitPoints {
			class HitEngine {
				armor = 2;
				material = -1;
				name = "motor";
				passThrough = 0;
			};
			
			class HitFuel {
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0;
			};
			
			class HitLFWheel : HitLFWheel {
				armor = 0.5;
			};
			
			class HitLBWheel : HitLBWheel {
				armor = 0.5;
			};
			
			class HitRFWheel : HitRFWheel {
				armor = 0.5;
			};
			
			class HitRBWheel : HitRBWheel {
				armor = 0.5;
			};
		};
		threat[] = {0.0, 0.0, 0.0};
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"\ca\wheeled_e\lr\data\lr_base_ind_co.paa"};
	};
	class LandRover_MG_Ori : LandRover_Base_Ori {
		scope = 2;
		side = 2;
		faction = "rth_copter_class";
		model = "\ca\wheeled_E\LR\LR_MG";
		Picture = "\CA\wheeled_e\Data\UI\Picture_lr_mg_CA.paa";
		Icon = "\CA\wheeled_e\Data\UI\Icon_lr_mg_CA.paa";
		transportSoldier = 1;
		cargoAction[] = {"LR_Cargo01_EP1"};
		threat[] = {1, 0.1, 0.1};
		
		class Damage {
			tex[] = {};
			mat[] = {"ca\wheeled_E\LR\Data\LR_base.rvmat", "ca\wheeled_E\LR\Data\LR_base_damage.rvmat", "ca\wheeled_E\LR\Data\LR_base_destruct.rvmat", "ca\wheeled_E\LR\Data\LR_glass.rvmat", "ca\wheeled_E\LR\Data\LR_glass_damage.rvmat", "ca\wheeled_E\LR\Data\LR_glass_destruct.rvmat", "ca\wheeled_E\LR\Data\LR_MG-SPG9.rvmat", "ca\wheeled_E\LR\Data\LR_MG-SPG9_damage.rvmat", "ca\wheeled_E\LR\Data\LR_MG-SPG9_destruct.rvmat", "Ca\Ca_E\data\default.rvmat", "Ca\Ca_E\data\default.rvmat", "Ca\Ca_E\data\default_destruct.rvmat"};
		};
	
		crew = "";
		typicalCargo[] = {};
		weapons[] = {};
		magazines[] = {};
		displayName = "LandRover MG";
		
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"\ca\wheeled_e\lr\data\lr_base_ind_co.paa"};
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				body = "mainTurret";
				gun = "mainGun";
				hasGunner = 1;
				weapons[] = {"PKT"};
				minElev = -25;
				maxElev = 60;
				soundServo[] = {"\ca\wheeled\Data\Sound\servo3", 1e-006, 1.0};
				magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
				gunnerAction = "LR_Gunner_EP1";
				ejectDeadGunner = 1;
				castGunnerShadow = 1;
				stabilizedInAxes = "StabilizedInAxesNone";
			};
		};
		class AnimationSources : AnimationSources {
			class ReloadAnim {
				source = "reload";
				weapon = "PKT";
			};
			
			class ReloadMagazine {
				source = "reloadmagazine";
				weapon = "PKT";
			};
			
			class Revolving {
				source = "revolving";
				weapon = "PKT";
			};
		};
	};
	class Kamaz_Base;
	class Kamaz_Ori : Kamaz_Base {
		scope = 2;
		side = 2;
		displayName = $STR_DN_KAMAZ;
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {};
		weapons[] = {};
		magazines[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		model = "\ca\wheeled2\Kamaz\Kamaz";
		cargoAction[] = {"Truck_Cargo01", "Truck_Cargo01", "Truck_Cargo02", "Truck_Cargo03", "Truck_Cargo02", "Truck_Cargo02", "Truck_Cargo03", "Truck_Cargo02", "Truck_Cargo03", "Truck_Cargo02", "Truck_Cargo02", "Truck_Cargo03"};
		transportMaxMagazines = 250;
		transportMaxWeapons = 50;
		transportMaxBackpacks = 10;
		hiddenSelections[] = {"Camo1", "Camo2"};
		hiddenSelectionsTextures[] = {"\origins_pack\vehicles\skins\kamaz\kamaz_blue_co.paa", "\origins_pack\vehicles\skins\kamaz\kamaz_back_white_co.paa"};
	};
	class KamazOpen_Ori : Kamaz_Base {
		scope = 2;
		side = 2;
		displayName = $STR_DN_KAMAZ_OPEN;
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {};
		weapons[] = {};
		magazines[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		model = "\ca\wheeled2\Kamaz\Kamaz_Open";
		picture = "\Ca\wheeled2\data\ui\Picture_kamaz_open_CA.paa";
		Icon = "\Ca\wheeled2\data\ui\Icon_kamaz_open_CA.paa";
		castCargoShadow = 1;
		transportMaxMagazines = 250;
		transportMaxWeapons = 50;
		transportMaxBackpacks = 10;
		hiddenSelections[] = {"Camo1", "Camo2"};
		hiddenSelectionsTextures[] = {"\origins_pack\vehicles\skins\kamaz\kamaz_blue_co.paa", "\origins_pack\vehicles\skins\kamaz\kamaz_back_white_co.paa"};
		
		class Library {
			libTextDesc = $STR_LIB_KAMAZ_OPEN;
		};
	};
	class ATV_Base_EP1;
	class ATV_Ori : ATV_Base_EP1 {
		scope = 2;
		side = 2;
		displayName = "ATV";
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {};
		weapons[] = {};
		magazines[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		transportMaxMagazines = 50;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 2;
	};
	class M2StaticMG_base;
	class SectorMG_Ori : M2StaticMG_base
	{
		displayName = "Sector MG";
		scope = 1;
		side = 0;
		faction = "rth_copter_class";
		crew = "";
		typicalCargo[] = {""};
	};
	
	
	class House {
		class DestructionEffects;
	};
	class UH1Wreck_Ori: House
	{
		model = "\ca\air2\UH1Y\UH1Y_Crashed.p3d";
		icon = "\ca\air2\data\UI\icon_UH1Y_CA.paa";
		mapSize = 15;
		displayName = "Crashed UH-1Y";
		vehicleClass = "Wrecks";
	};
	
	class HouseDZ: House {
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0.0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = "false";
			};
		};
		class Reflectors
		{
			class MainLight
			{
				color[] = {0,0.0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				position = "";
				direction = "";
				hitpoint = "";
				selection = "";
				size = 0;
				period[] = {0,1};
			};
		};
	};
	
	class Strategic;
	class NonStrategic;

	class Land_A_FuelStation_Feed: Strategic
	{
		model = "\ca\structures\House\A_FuelStation\A_FuelStation_Feed";
		transportFuel = 0; //50000;
		nameSound = "fuelstation";
	};
	class Land_Ind_MalyKomin: House
	{
		scope = 1;
		armor = 100;
		featureSize = 40;
		model = "\Ca\buildings2\Ind_CementWorks\Ind_MalyKomin\Ind_MalyKomin";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\ca\Buildings2\Ind_CementWorks\Ind_MalyKomin\Ind_MalyKomin_ruins";
				position = "";
				intensity = 1;
				interval = 0.05;
				lifeTime = 1;
			};
		};
		ladders[] = {{"start","end"}};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_Rail_Semafor: House
	{
		scope = 1;
		model = "\CA\Structures\Rail\Rail_Misc\rail_Semafor";
		destrType = "DestructTree";
		class MarkerLights
		{
			class GreenStill
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_Rail_Zavora: House
	{
		scope = 1;
		model = "\CA\Structures\Rail\Rail_Misc\rail_Zavora";
		destrType = "DestructTree";
		class MarkerLights
		{
			class WhiteBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_majak: House
	{
		scope = 1;
		model = "\ca\buildings\majak";
		displayName = "Lighthouse";
		animated = 1;
		ladders[] = {{"start","end"}};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\ca\buildings\ruins\majak_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		armor = 1000;
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		class Reflectors
		{
			class MainLight
			{
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				position = "";
				direction = "";
				hitpoint = "";
				selection = "";
				size = 0;
				brightness = 0;
				period[] = {0,1};
			};
		};
	};
	class Land_majak2: Land_majak
	{
		model = "\ca\buildings\majak2";
		class Reflectors
		{
			class MainLight
			{
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				position = "";
				direction = "";
				hitpoint = "";
				selection = "";
				size = 0;
				brightness = 0;
				period[] = {0,1};
			};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\ca\buildings\ruins\majak_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Vysilac_FM: House
	{
		scope = 1;
		armor = 150;
		destrType = "DestructBuilding";
		ladders[] = {{"start","end"}};
		model = "\ca\buildings\Vysilac_FM";
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		class Destruction
		{
			animations[] = {{"ca\buildings\rtm\vysilac_fm.rtm",0.5,3}};
		};
		displayName = "Radio 1";
	};
	class Land_telek1: House
	{
		scope = 1;
		armor = 600;
		destrType = "DestructBuilding";
		model = "\ca\buildings\telek1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\ca\buildings\ruins\telek1_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		displayName = "Telek 1";
		ladders[] = {{"start1","end1"},{"start2","end2"},{"start3","end3"}};
	};
	class Land_komin: House
	{
		ladders[] = {{"start","end"}};
		model = "\ca\buildings\komin";
		armor = 300;
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\ca\buildings\ruins\komin_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_Stoplight01: House
	{
		scope = 1;
		model = "\ca\buildings\Misc\stoplight01";
		armor = 50;
		class MarkerLights
		{
			class YellowTopBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
			class YellowLowBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_Stoplight02: Land_Stoplight01
	{
		model = "\ca\buildings\Misc\stoplight02";
		class MarkerLights
		{
			class YellowTopBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_NavigLight: House
	{
		scope = 1;
		displayName = "";
		model = "\ca\buildings\Misc\NavigLight";
		armor = 50;
		class MarkerLights
		{
			class WhiteStill
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_runway_edgelight: House
	{
		scope = 1;
		displayName = "";
		model = "\ca\buildings\Misc\runway_edgelight";
		armor = 20;
		class MarkerLights
		{
			class RedStill
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_VASICore: NonStrategic
	{
		scope = 1;
		animated = 0;
		reversed = 0;
		vehicleClass = "Objects";
		icon = "";
		model = "";
		displayName = "VASI";
		accuracy = 0.2;
		typicalCargo[] = {};
		destrType = "DestructBuilding";
		irTarget = 0;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		cost = 0;
		armor = 100;
		mapSize = 6.4;
		simulation = "house";
	};
	class Land_HouseB_Tenement: House
	{
		armor = 180;
		model = "\Ca\Structures\House\HouseBT\HouseB_Tenement";
		scope = 1;
		featureSize = 50;
		class HitPoints
		{
			class Hit1
			{
				armor = 0.15;
				material = -1;
				name = "dam 1";
				visual = "damT1";
				passThrough = 0;
				convexComponent = "dam 1";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
		};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0.0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = "false";
			};
		};
		class AnimationSources
		{
			class Lights_1
			{
				source = "user";
				animPeriod = 0.001;
				initPhase = 0;
			};
			class Lights_2: Lights_1
			{
			};
		};
	};
	class Land_Mil_ControlTower: House
	{
		scope = 1;
		armor = 400;
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\Structures\Mil\Mil_ControlTower_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		class HitPoints
		{
			class Hit1
			{
				armor = 0.25;
				material = -1;
				name = "dam 1";
				visual = "damT1";
				passThrough = 1;
				convexComponent = "dam 1";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hit2
			{
				armor = 0.25;
				material = -1;
				name = "dam 2";
				visual = "damT2";
				passThrough = 1;
				convexComponent = "dam 2";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hit3
			{
				armor = 0.25;
				material = -1;
				name = "dam 3";
				visual = "damT3";
				passThrough = 1;
				convexComponent = "dam 3";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hit4
			{
				armor = 0.25;
				material = -1;
				name = "dam 4";
				visual = "damT4";
				passThrough = 1;
				convexComponent = "dam 4";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hit5
			{
				armor = 0.25;
				material = -1;
				name = "dam 5";
				visual = "damT5";
				passThrough = 1;
				convexComponent = "dam 5";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hit6
			{
				armor = 0.25;
				material = -1;
				name = "dam 6";
				visual = "damT6";
				passThrough = 1;
				convexComponent = "dam 6";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hitglass
			{
				armor = 0.0005;
				material = -1;
				name = "dam glass";
				visual = "damTglass";
				passThrough = 0;
				convexComponent = "dam glass";
			};
			class Hittower
			{
				armor = 0.0005;
				material = -1;
				name = "dam tower";
				visual = "damTtower";
				passThrough = 0;
				convexComponent = "dam tower";
			};
		};
		replaceDamagedHitpoints[] = {"Hit1","Hit2","Hit3","Hit4","Hit5","Hit6"};
		class Damage
		{
			tex[] = {};
			mat[] = {"CA\Structures\Mil\Data\Mil_ControlTower_windows1.rvmat","CA\Structures\Mil\Data\destruct_half_Mil_ControlTower_windows1.rvmat","CA\Structures\Mil\Data\destruct_full_Mil_ControlTower_windows1.rvmat"};
		};
		model = "\CA\Structures\Mil\Mil_ControlTower";
		ladders[] = {{"start1","end1"},{"start2","end2"}};
		class AnimationSources
		{
			class dvere_spodni_R
			{
				animPeriod = 1;
				initPhase = 0;
				source = "user";
			};
			class dvere_spodni_L
			{
				animPeriod = 1;
				initPhase = 1;
				source = "user";
			};
			class dvere_vrchni
			{
				animPeriod = 1;
				initPhase = 1;
				source = "user";
			};
			class HitTower
			{
				source = "Hit";
				hitpoint = "HitTower";
				raw = 1;
			};
		};
		class UserActions
		{
			class OpenDoors1
			{
				displayNameDefault = "<img image='\ca\ui\data\ui_action_open_ca.paa' size='4' />";
				displayName = "Open door";
				position = "Dvere_spodni_R_osa";
				radius = 3;
				onlyForPlayer = 0;
				condition = "this animationPhase ""Dvere_spodni_R"" < 0.5";
				statement = "this animate [""Dvere_spodni_R"", 1];this animate [""Dvere_spodni_L"", 1]";
			};
			class CloseDoors1: OpenDoors1
			{
				displayNameDefault = "<img image='\ca\ui\data\ui_action_close_ca.paa' size='4' />";
				displayName = "Close door";
				condition = "this animationPhase ""Dvere_spodni_R"" >= 0.5";
				statement = "this animate [""Dvere_spodni_R"", 0];this animate [""Dvere_spodni_L"", 0]";
			};
			class OpenDoors3
			{
				displayNameDefault = "<img image='\ca\ui\data\ui_action_open_ca.paa' size='4' />";
				displayName = "Open door";
				position = "Dvere_Vrchni_osa";
				radius = 2;
				onlyForPlayer = 0;
				condition = "this animationPhase ""dvere_vrchni"" < 0.5";
				statement = "this animate [""dvere_vrchni"", 1]";
			};
			class CloseDoors3: OpenDoors3
			{
				displayNameDefault = "<img image='\ca\ui\data\ui_action_close_ca.paa' size='4' />";
				displayName = "Close door";
				condition = "this animationPhase ""dvere_vrchni"" >= 0.5";
				statement = "this animate [""dvere_vrchni"", 0]";
			};
		};
		actionBegin1 = "OpenDoors1";
		actionEnd1 = "OpenDoors1";
		actionBegin2 = "OpenDoors3";
		actionEnd2 = "OpenDoors3";
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		replaceDamaged = "Land_Mil_ControlTower_dam";
	};
	class Land_NAV_Lighthouse: House
	{
		scope = 1;
		armor = 500;
		featureSize = 15;
		model = "\Ca\Structures\NAV\NAV_Lighthouse";
		ladders[] = {{"start1","end1"}};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		class Reflectors
		{
			class MainLight
			{
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				position = "";
				direction = "";
				hitpoint = "";
				selection = "";
				size = 0;
				brightness = 0;
				period[] = {0,1};
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\structures\nav\data\nav_lighthouse_multi.rvmat","ca\structures\nav\data\destruct_half_nav_lighthouse_multi.rvmat","ca\structures\nav\data\destruct_full_nav_lighthouse_multi.rvmat","ca\structures\nav\data\nav_lighthouse_windows.rvmat","ca\structures\nav\data\destruct_half_lighthouse_windows.rvmat","ca\structures\nav\data\destruct_full_lighthouse_windows.rvmat"};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\Structures\Nav\NAV_Lighthouse_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_NAV_Lighthouse2: Land_NAV_Lighthouse
	{
		model = "\Ca\Structures\NAV\NAV_Lighthouse2";
		class Reflectors: Reflectors
		{
			class MainLight: MainLight
			{
				period[] = {0,1};
			};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\Structures\Nav\NAV_Lighthouse_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_A_Crane_02b: House
	{
		scope = 1;
		armor = 110;
		featureSize = 30;
		model = "\ca\buildings2\A_Crane_02\A_Crane_02b";
		destrType = "DestructBuilding";
		ladders[] = {{"start3","end3"},{"start4","end4"},{"start5","end5"},{"start6","end6"}};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		class Destruction
		{
			animations[] = {{"ca\buildings2\A_Crane_02\data\anim\crane.rtm",0.5,3}};
		};
	};
	class Land_Farm_WTower: House
	{
		scope = 1;
		armor = 100;
		model = "\CA\buildings2\Farm_WTower\Farm_WTower";
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\buildings2\Farm_WTower\Farm_WTower_ruins";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_A_TVTower_Mid: House
	{
		scope = 1;
		destrType = "DestructNo";
		model = "\ca\Structures\A_TVTower\A_TVTower_Mid";
		featureSize = 150;
		class MarkerLights
		{
			class RedStill
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_A_TVTower_Top: House
	{
		scope = 1;
		destrType = "DestructNo";
		model = "\ca\Structures\A_TVTower\A_TVTower_Top";
		featureSize = 150;
		class MarkerLights
		{
			class RedLight
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class GraveCrossHelmet_DZ: NonStrategic {
		scope = 2;
		model = "\ca\buildings\Misc\hrobecek_krizekhelma.p3d";
		vehicleClass = "Dead_bodies";
		destrType = "DestructTree";
		armor = 10;
		accuracy = 500;	
		displayName = "Survival RIP"; ///$STR_DN_GRAVECROSSHELMET_DZ;
	};
};
class CfgNonAIVehicles {
	access = ReadAndWrite;
	
	class StreetLamp {
		colorDiffuse[] = {0.9, 0.8, 0.6};
		colorAmbient[] = {0.02, 0.02, 0.02};
		brightness = 0.15;
	};
	
	class StreetLamp_BaseWeakYellow : StreetLamp {
		colorDiffuse[] = {0.5, 0.4, 0.1, 0.0};
		colorAmbient[] = {0.2, 0.15, 0.05, 0.0};
		brightness = 0.1;
	};
	
	class StreetLamp_BaseMediumOrange : StreetLamp {
		colorDiffuse[] = {0.6, 0.35, 0.0, 0.0};
		colorAmbient[] = {0.2, 0.1, 0.0, 0.0};
		brightness = 0.2;
	};
	
	class StreetLamp_BaseMediumPale : StreetLamp {
		colorDiffuse[] = {0.6, 0.7, 0.8, 0.0};
		colorAmbient[] = {0.06, 0.07, 0.1, 0.0};
		brightness = 0.15;
	};
	
	class StreetLamp_BaseStrongPale : StreetLamp {
		colorDiffuse[] = {0.6, 0.7, 0.85, 0.0};
		colorAmbient[] = {0.07, 0.1, 0.15, 0.0};
		brightness = 0.33;
	};
	
	class Land_lampa_sidl : StreetLamp_BaseMediumOrange {
		
		colorDiffuse[] = {0.6, 0.35, 0.0, 0.0};
		colorAmbient[] = {0.2, 0.1, 0.0, 0.0};
		brightness = 0.08;
		
		scope = public;
		model = "\ca\buildings\Misc\lampa_sidl";
	};
	
	class Land_lampa_sidl_2 : StreetLamp_BaseMediumOrange {
		
		colorDiffuse[] = {0.6, 0.35, 0.0, 0.0};
		colorAmbient[] = {0.2, 0.1, 0.0, 0.0};
		brightness = 0.16;
		
		scope = public;
		model = "\ca\buildings\Misc\lampa_sidl_2";
	};
	
	class Land_lampa_sidl_3 : StreetLamp_BaseMediumOrange {
		
		colorDiffuse[] = {0.6, 0.35, 0.0, 0.0};
		colorAmbient[] = {0.2, 0.1, 0.0, 0.0};
		brightness = 0.24;		
		
		scope = public;
		model = "\ca\buildings\Misc\lampa_sidl_3";
	};
	
	class Land_lampa_ind : StreetLamp_BaseWeakYellow {
		
		colorDiffuse[] = {0.5, 0.4, 0.1, 0.0};
		colorAmbient[] = {0.2, 0.15, 0.05, 0.0};
		brightness = 0.1;
		
		scope = public;
		model = "\ca\buildings\Misc\lampa_ind";
	};
	
	class Land_lampa_ind_zebr : StreetLamp_BaseWeakYellow {
		
		colorDiffuse[] = {0.5, 0.4, 0.1, 0.0};
		colorAmbient[] = {0.2, 0.15, 0.05, 0.0};
		brightness = 0.1;
		
		scope = public;
		model = "\ca\buildings\Misc\lampa_ind_zebr";
	};
};