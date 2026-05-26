class CfgPatches
{
    class dayz_code
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.100000001;
        requiredAddons[] = {"dayz_equip", "dayz_weapons", "CAMisc3", "CABuildingParts", "CABuildingParts_Signs", "CAStructuresHouse", "CAStructuresLand_Ind_Stack_Big", "CAStructures_Misc_Powerlines", "CAStructures", "CABuildings", "CABuildings2", "Ind_MalyKomin", "CAStructures_A_CraneCon", "CAStructures_Mil", "CAStructures_Nav", "CAStructures_Rail", "A_Crane_02", "A_TVTower", "CAStructures_Railway", "CAStructuresHouse", "CAStructuresHouse_HouseBT", "CAWeapons", "osshdy", "ori_scrapTank", "ori_ScrapBuggy", "ori_smallRaft", "ori_bigRaft", "ori_pragaCopter", "rth_small_tent", "ori_titanic", "ori_vil_pack", "ori_dc3", "base_buildings", "origins_pack_cars", "ori_flying_fortress", "ori_submarine", "vil_ori_autogyro"};
    };
};
class CfgMods
{
    class DayZ
    {
        dir = "DayZ";
        name = "DayZ";
        picture = "z\\addons\\dayz_code\\gui\\Origins_logo_ca.paa";
        hidePicture = 0;
        hideName = 0;
        action = "http://www.OriginsMod.info";
        version = "1.7.9";
        hiveVersion = 0.96;
    };
};
class CfgAddons
{
    access = 1;
    class PreloadBanks
    {
    };
    class PreloadAddons
    {
        class dayz
        {
            list[] = {"dayz_code", "dayz", "dayz_equip", "dayz_weapons"};
        };
    };
};
class RscPictureGUI
{
    access = 0;
    type = 0;
    idc = -1;
    colorBackground[] = {0, 0, 0, 0};
    colorText[] = {0.379999995, 0.629999995, 0.25999999, 0.75};
    font = "TahomaB";
    sizeEx = 0;
    lineSpacing = 0;
    text = "";
    style = "0x30 + 0x100 + 0x800";
    x = 0;
    y = 0;
    w = 0.200000003;
    h = 0.150000006;
};
class RscTextGUIK
{
    type = 0;
    idc = -1;
    style = 2;
    colorBackground[] = {0, 0, 0, 0};
    colorText[] = {1, 1, 1, 0.5};
    font = "TahomaB";
    size = 0.0299999993;
    sizeEx = 0.0299999993;
    x = 0;
    y = 0;
    w = 0.100000001;
    h = 0.200000003;
};
class RscStructuredText
{
    class Attributes;
};
class RscStructuredTextGUI: RscStructuredText
{
    colorBackground[] = {0, 0, 0, 0};
    colorText[] = {1, 1, 1, 1};
    class Attributes: Attributes
    {
        align = "center";
        valign = "middle";
    };
};
class CfgMovesAnimalsBase
{
    class ManActions;
    class StandBase;
    class DefaultDie;
    class BlendAnims;
};
class CfgMovesDogBase
{
    class Default
    {
        actions = "";
        access = 3;
        file = "";
        looped = 1;
        speed = 0.5;
        disableWeapons = 1;
        enableOptics = 0;
        disableWeaponsLong = 1;
        showWeaponAim = 0;
        enableMissile = 0;
        enableBinocular = 0;
        showItemInHand = 0;
        showItemInRightHand = 0;
        showHandGun = 0;
        onLandBeg = 0;
        onLandEnd = 0;
        onLadder = 0;
        canPullTrigger = 1;
        duty = -0.50999999;
        predictSpeedCoef = 1;
        visibleSize = 1;
        aimPrecision = 1;
        relSpeedMin = 1;
        relSpeedMax = 1;
        soundEnabled = 0;
        controlHead = 0;
        headBobMode = 0;
        headBobStrength = 0;
        soundOverride = "";
        soundEdge[] = {0.5, 1};
        terminal = 0;
        limitGunMovement = 1;
        variantsPlayer[] = {};
        variantsAI[] = {""};
        equivalentTo = "";
        connectAs = "";
        variantAfter[] = {5, 10, 20};
        connectFrom[] = {};
        connectTo[] = {};
        interpolateWith[] = {};
        interpolateTo[] = {};
        interpolateFrom[] = {};
        aiming = "aimingNo";
        leaning = "aimingNo";
        untiltWeapon = "aimingNo";
        aimingBody = "aimingUpDefault";
        legs = "legsNo";
        head = "headDefault";
        leaningFactorBeg = 0;
        leaningFactorEnd = 0;
        leaningFactorZeroPoint = -1;
        leaningCorrectionAngleBeg = 0;
        leaningCorrectionAngleEnd = 0;
        interpolationSpeed = 6;
        interpolationRestart = 0;
        collisionShape = "ca\\animals2\\data\\geom\\basicColide.p3d";
        hasCollShapeSafe = 0;
        collisionShapeSafe = "";
        boundingSphere = 1;
        enableDirectControl = 1;
        enableAutoActions = 0;
        leftHandIKBeg = 0;
        leftHandIKEnd = 0;
        rightHandIKBeg = 0;
        rightHandIKEnd = 0;
        weaponIK = 0;
        preload = 0;
        walkcycles = 1;
        forceAim = 0;
        rightHandIKCurve[] = {};
        leftHandIKCurve[] = {};
    };
    class StandBase: Default
    {
        aiming = "aimingDefault";
        disableWeapons = 1;
        leaningFactorBeg = 1;
        leaningFactorEnd = 1;
    };
    class DefaultDie: Default
    {
        aiming = "aimingNo";
        legs = "legsNo";
        head = "headNo";
        disableWeapons = 1;
        interpolationRestart = 1;
        soundOverride = "fallbody";
        soundEdge[] = {0.449999988};
        soundEnabled = 0;
    };
    class ManActions
    {
        Stop = "";
        StopRelaxed = "";
        TurnL = "";
        TurnR = "";
        TurnLRelaxed = "";
        TurnRRelaxed = "";
        Default = "";
        JumpOff = "";
        ReloadMagazine = "";
        ReloadMGun = "";
        ReloadAT = "";
        ReloadMortar = "";
        ThrowGrenade = "";
        WalkF = "";
        WalkLF = "";
        WalkRF = "";
        WalkL = "";
        WalkR = "";
        WalkLB = "";
        WalkRB = "";
        WalkB = "";
        SlowF = "";
        SlowLF = "";
        SlowRF = "";
        SlowL = "";
        SlowR = "";
        SlowLB = "";
        SlowRB = "";
        SlowB = "";
        FastF = "";
        FastLF = "";
        FastRF = "";
        FastL = "";
        FastR = "";
        FastLB = "";
        FastRB = "";
        FastB = "";
        EvasiveForward = "";
        EvasiveLeft = "";
        EvasiveRight = "";
        EvasiveBack = "";
        StartSwim = "";
        StopSwim = "";
        Down = "";
        Up = "";
        PlayerStand = "";
        PlayerCrouch = "";
        PlayerProne = "";
        Lying = "";
        Stand = "";
        Combat = "";
        Crouch = "";
        CanNotMove = "";
        Civil = "";
        CivilLying = "";
        FireNotPossible = "";
        Die = "";
        WeaponOn = "";
        WeaponOff = "";
        StrokeFist = "";
        StrokeGun = "";
        SitDown = "";
        Salute = "";
        BinocOn = "";
        BinocOff = "";
        PutDown = "";
        PutDownEnd = "";
        Medic = "";
        Treated = "";
        LadderOnDown = "";
        LadderOnUp = "";
        LadderOff = "";
        LadderOffTop = "";
        LadderOffBottom = "";
        GetInLow = "";
        GetInMedium = "";
        GetInHigh = "";
        GetOutLow = "";
        GetOutMedium = "";
        GetOutHigh = "";
        TakeFlag = "";
        HandGunOn = "";
        LookAround = "";
        Eat = "";
        StopEat = "";
        Rest = "";
        StopRest = "";
        GestureBark = " ";
        GestureIdle1 = " ";
        GestureIdle2 = " ";
        GestureSniff = " ";
        GestureHeadL = " ";
        GestureHeadR = " ";
    };
    class BlendAnims
    {
        aimingDefault[] = {};
        untiltWeaponDefault[] = {};
        legsDefault[] = {};
        headDefault[] = {};
        aimingNo[] = {};
        legsNo[] = {};
        headNo[] = {};
        aimingUpDefault[] = {};
    };
    collisionVertexPattern[] = {"1a", "2a", "3a", "4a", "5a", "6a", "7a", "8a", "9a", "10a", "11a", "12a", "13a", "14a", "15a", "16a", "17a", "18a", "19a", "20a", "21a", "22a", "23a", "24a", "25a", "26a", "27a", "28a", "29a", "30a", "31a", "32a", "33a", "34a"};
    collisionGeomCompPattern[] = {1};
};
class CfgMovesDogDZ: CfgMovesDogBase
{
    primaryActionMaps[] = {"DogActions", "NoActions"};
    skeletonName = "DogSkeleton";
    gestures = "CfgGesturesDogDZ";
    class States
    {
        class Dog_Stop: StandBase
        {
            actions = "DogActions";
            duty = -1;
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogStop";
            speed = 1e+10;
            relSpeedMin = 0.699999988;
            relSpeedMax = 1.10000002;
            looped = 1;
            ConnectTo[] = {"Dog_TurnR", 0.100000001, "Dog_StopV2", 0.100000001, "Dog_StopV1", 0.100000001, "Dog_TurnL", 0.100000001, "Dog_Sprint", 0.0199999996, "Dog_Run", 0.0199999996, "Dog_Walk", 0.200000003};
            InterpolateTo[] = {"Dog_TurnR", 0.100000001, "Dog_Die", 0.0199999996, "Dog_TurnL", 0.100000001, "Dog_Sprint", 0.0199999996, "Dog_Run", 0.0199999996, "Dog_Walk", 0.200000003};
        };
        class Dog_TurnL: Dog_Stop
        {
            file = "\\CA\\animals2\\Dogs\\data\\anim\\dog_rotateL.rtm";
            speed = 1;
            ConnectTo[] = {"Dog_Stop", 0.100000001};
            InterpolateTo[] = {"Dog_Stop", 0.100000001};
        };
        class Dog_TurnR: Dog_TurnL
        {
            file = "\\CA\\animals2\\Dogs\\data\\anim\\dog_rotateR.rtm";
            ConnectTo[] = {"Dog_Stop", 0.100000001};
            InterpolateTo[] = {"Dog_Stop", 0.100000001};
        };
        class Dog_StopV1: Dog_Stop
        {
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogIDLE";
            speed = 2.1400001;
            variantAfter[] = {5, 7, 10};
            looped = 0;
            ConnectTo[] = {"Dog_Stop", 0.100000001};
            InterpolateTo[] = {"Dog_Die", 0.0199999996};
        };
        class Dog_StopV2: Dog_Stop
        {
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogBark";
            speed = 1;
            variantAfter[] = {1, 1, 1};
            looped = 0;
            ConnectTo[] = {"Dog_Stop", 0.100000001};
            InterpolateTo[] = {"Dog_Die", 0.0199999996};
        };
        class Dog_Attack: Dog_Stop
        {
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogAttack";
            speed = 1;
            variantAfter[] = {1, 1, 1};
            looped = 0;
            ConnectTo[] = {"Dog_Stop", 0.100000001};
            InterpolateTo[] = {"Dog_Die", 0.0199999996};
        };
        class Dog_Sniff: Dog_Stop
        {
            file = "\\dayz_anim\\dog\\dogGestureSniff";
            speed = 0.300000012;
            mask = "frontBody";
            variantAfter[] = {1, 1, 1};
            looped = 0;
            ConnectTo[] = {"Dog_Stop", 0.100000001};
            InterpolateTo[] = {"Dog_Die", 0.0199999996};
        };
        class Dog_SitDown: Dog_Stop
        {
            actions = "DogSit";
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogSit1In";
            speed = 1.42999995;
            variantAfter[] = {1, 1, 1};
            looped = 0;
            relSpeedMin = 0.996671975;
            relSpeedMax = 0.996671975;
            ConnectTo[] = {};
            InterpolateTo[] = {"Dog_Die", 0.0199999996};
        };
        class Dog_LieDown: Dog_Stop
        {
            actions = "DogSit";
            file = "\\dayz_anim\\dog\\dogStandDown";
            speed = 1.42857099;
            variantAfter[] = {1, 1, 1};
            looped = 0;
            relSpeedMin = 0.996671975;
            relSpeedMax = 0.996671975;
            ConnectTo[] = {};
            InterpolateTo[] = {"Dog_Die", 0.0199999996};
        };
        class Dog_GetUp: Dog_Stop
        {
            actions = "DogSit";
            file = "\\dayz_anim\\dog\\dogDownStand";
            speed = 1.42857099;
            variantAfter[] = {1, 1, 1};
            looped = 0;
            relSpeedMin = 0.996671975;
            relSpeedMax = 0.996671975;
            ConnectTo[] = {"Dog_Stop", 0.100000001, "Dog_Run", 0.100000001, "Dog_Walk", 0.100000001, "Dog_Sprint", 0.100000001};
            InterpolateTo[] = {"Dog_Die", 0.0199999996, "Dog_Run", 0.100000001, "Dog_Walk", 0.100000001, "Dog_Sprint", 0.100000001};
        };
        class Dog_Siting: Dog_Stop
        {
            actions = "DogSit";
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogSit2Idle";
            speed = 1.58000004;
            variantAfter[] = {1, 1, 1};
            looped = 1;
            ConnectTo[] = {};
            InterpolateTo[] = {"Dog_Die", 0.0199999996};
        };
        class Dog_SitUp: Dog_Stop
        {
            actions = "DogSit";
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogSit3Out";
            speed = 1.08000004;
            variantAfter[] = {1, 1, 1};
            looped = 0;
            relSpeedMin = 0.996671975;
            relSpeedMax = 0.996671975;
            ConnectTo[] = {"Dog_Stop", 0.100000001, "Dog_Run", 0.100000001, "Dog_Walk", 0.100000001, "Dog_Sprint", 0.100000001};
            InterpolateTo[] = {"Dog_Die", 0.0199999996, "Dog_Run", 0.100000001, "Dog_Walk", 0.100000001, "Dog_Sprint", 0.100000001};
        };
        class Dog_Sprint: Dog_Stop
        {
            actions = "DogSprint";
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogSprint";
            duty = 0.5;
            speed = 4.5;
            ConnectTo[] = {"Dog_Stop", 0.0199999996, "Dog_Run", 0.0199999996, "Dog_Walk", 0.0199999996};
            InterpolateTo[] = {"Dog_Die", 0.0199999996, "Dog_Stop", 0.0199999996, "Dog_Run", 0.0199999996, "Dog_Walk", 0.0199999996};
        };
        class Dog_Run: Dog_Stop
        {
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogRun";
            duty = -0.5;
            speed = 1.79999995;
            ConnectTo[] = {"Dog_Stop", 0.0199999996, "Dog_Sprint", 0.0199999996, "Dog_Walk", 0.0199999996};
            InterpolateTo[] = {"Dog_Die", 0.0199999996, "Dog_Stop", 0.0199999996, "Dog_Sprint", 0.0199999996, "Dog_Walk", 0.0199999996};
        };
        class Dog_Walk: Dog_Stop
        {
            duty = -0.699999988;
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogWalk";
            speed = 1.29999995;
            variantAfter[] = {3, 10, 20};
            ConnectTo[] = {"Dog_Stop", 0.200000003, "Dog_Sprint", 0.200000003, "Dog_Run", 0.200000003};
            InterpolateTo[] = {"Dog_Die", 0.0199999996, "Dog_Stop", 0.200000003, "Dog_Sprint", 0.200000003, "Dog_Run", 0.200000003};
        };
        class Dog_Die: DefaultDie
        {
            enableDirectControl = 0;
            actions = "NoActions";
            file = "\\CA\\animals2\\dogs\\data\\Anim\\dogDeath";
            speed = 1.20000005;
            looped = 0;
            variantsPlayer[] = {};
            variantsAI[] = {""};
            variantAfter[] = {0, 0, 0};
            terminal = 1;
            soundEnabled = 0;
            ConnectTo[] = {};
            InterpolateTo[] = {};
        };
    };
    class Actions
    {
        class NoActions: ManActions
        {
            turnSpeed = 8;
            limitFast = 5.5;
            useFastMove = 0;
            upDegree = 0;
            GestureBark[] = {"GestureBark", "Gesture"};
            GestureIdle1[] = {"GestureIdle1", "Gesture"};
            GestureIdle2[] = {"GestureIdle2", "Gesture"};
            GestureSniff[] = {"GestureSniff", "Gesture"};
            GestureHeadL[] = {"GestureHeadL", "Gesture"};
            GestureHeadR[] = {"GestureHeadR", "Gesture"};
        };
        class DogActions: NoActions
        {
            Stop = "Dog_Stop";
            StopRelaxed = "Dog_Stop";
            TurnL = "Dog_TurnL";
            TurnR = "Dog_TurnR";
            TurnLRelaxed = "Dog_TurnL";
            TurnRRelaxed = "Dog_TurnR";
            Default = "Dog_Stop";
            JumpOff = "Dog_Stop";
            WalkF = "Dog_Walk";
            SlowF = "Dog_Run";
            FastF = "Dog_Sprint";
            EvasiveForward = "Dog_Sprint";
            Down = "Dog_Stop";
            Up = "Dog_Stop";
            PlayerStand = "Dog_Stop";
            PlayerProne = "Dog_Stop";
            PlayerCrouch = "";
            Crouch = "";
            Lying = "Dog_Stop";
            Stand = "Dog_Stop";
            Combat = "Dog_Stop";
            CanNotMove = "Dog_Stop";
            Civil = "Dog_Stop";
            CivilLying = "Dog_Stop";
            FireNotPossible = "Dog_StopV1";
            Die = "Dog_Die";
            turnSpeed = 8;
            limitFast = 5.5;
            useFastMove = 0;
            upDegree = "ManPosNoWeapon";
            StartSwim = "Dog_Die";
        };
        class DogSprint: DogActions
        {
            Die = "Dog_Die";
            turnSpeed = 4;
            limitFast = 5.5;
            useFastMove = 1;
        };
        class DogSit: NoActions
        {
            Up = "Dog_Stop";
            PlayerStand = "Dog_Stop";
            Stand = "Dog_Stop";
            WalkF = "Dog_Walk";
            SlowF = "Dog_Run";
            FastF = "Dog_Sprint";
            EvasiveForward = "Dog_Sprint";
            PlayerCrouch = "Dog_Stop";
            Crouch = "Dog_Stop";
            Die = "Dog_Die";
            upDegree = "ManPosNoWeapon";
            StartSwim = "Dog_Die";
        };
    };
    class Interpolations
    {
    };
    transitionsInterpolated[] = {};
    transitionsSimple[] = {};
    transitionsDisabled[] = {};
    class BlendAnims: BlendAnims
    {
        aimingDefault[] = {"head", 1, "Jaw", 1, "Neck1", 0.5, "Tongue1", 1, "Tongue2", 1};
        untiltWeaponDefault[] = {};
        legsDefault[] = {};
        headDefault[] = {"head", 1, "Jaw", 1, "Neck1", 0.5, "Tongue1", 1, "Tongue2", 1};
        aimingNo[] = {};
        legsNo[] = {};
        headNo[] = {};
        aimingUpDefault[] = {};
        frontBody[] = {"neck", 1, "neck1", 1, "head", 1, "Jaw", 1, "Tongue1", 1, "Tongue2", 1, "leftArm", 0.5, "rightArm", 0.5, "leftEar", 1, "rightEar", 1};
    };
};
class CfgGesturesDogDZ
{
    skeletonName = "DogSkeleton";
    class ManActions
    {
    };
    class Actions
    {
        class NoActions: ManActions
        {
            turnSpeed = 0;
            upDegree = 0;
            limitFast = 1;
            useFastMove = 0;
        };
    };
    class Default
    {
        actions = "NoActions";
        file = "";
        looped = 1;
        speed = 0.5;
        relSpeedMin = 1;
        relSpeedMax = 1;
        soundEnabled = 0;
        soundOverride = "";
        soundEdge[] = {0.5, 1};
        terminal = 0;
        equivalentTo = "";
        connectAs = "";
        connectFrom[] = {};
        connectTo[] = {};
        interpolateWith[] = {};
        interpolateTo[] = {};
        interpolateFrom[] = {};
        mask = "empty";
        interpolationSpeed = 6;
        interpolationRestart = 0;
        preload = 0;
        disableWeapons = 1;
        enableOptics = 1;
        showWeaponAim = 1;
        enableMissile = 1;
        enableBinocular = 1;
        showItemInHand = 0;
        showItemInRightHand = 0;
        showHandGun = 0;
        canPullTrigger = 1;
        walkcycles = 1;
        headBobMode = 0;
        headBobStrength = 0;
        leftHandIKBeg = 0;
        leftHandIKEnd = 0;
        rightHandIKBeg = 0;
        rightHandIKEnd = 0;
        leftHandIKCurve[] = {1};
        rightHandIKCurve[] = {1};
        forceAim = 0;
    };
    class States
    {
        class GestureBark: Default
        {
            file = "\\dayz_anim\\dog\\dogBarkOnce";
            looped = 0;
            speed = 3;
            mask = "barking";
        };
        class GestureIdle1: Default
        {
            file = "\\dayz_anim\\dog\\dogGestureIdle1";
            looped = 0;
            speed = 0.300000012;
            mask = "idle";
        };
        class GestureIdle2: Default
        {
            file = "\\dayz_anim\\dog\\dogGestureIdle2";
            looped = 0;
            speed = 0.300000012;
            mask = "idle";
        };
        class GestureHeadL: Default
        {
            file = "\\dayz_anim\\dog\\dogGestureHeadL";
            looped = 0;
            speed = 0.300000012;
            mask = "idle";
        };
        class GestureHeadR: Default
        {
            file = "\\dayz_anim\\dog\\dogGestureHeadR";
            looped = 0;
            speed = 0.300000012;
            mask = "idle";
        };
        class GestureSniff: Default
        {
            file = "\\dayz_anim\\dog\\dogGestureSniff";
            looped = 0;
            speed = 0.300000012;
            mask = "frontBody";
        };
    };
    class BlendAnims
    {
        barking[] = {"head", 1, "Jaw", 1, "Neck1", 0.5, "Tongue1", 1, "Tongue2", 1, "Tail1", 0.300000012, "Tail2", 0.600000024, "Tail3", 1};
        idle[] = {"head", 1, "Jaw", 1, "Neck1", 0.600000024, "Tongue1", 1, "Tongue2", 1, "Tail1", 0.300000012, "Tail2", 0.600000024, "Tail3", 1, "Spine", 0.100000001, "Spine1", 0.200000003, "Spine2", 0.400000006};
        frontBody[] = {"spine", 0.100000001, "spine1", 0.300000012, "spine2", 0.600000024, "neck", 1, "neck1", 1, "head", 1, "Jaw", 1, "Tongue1", 1, "Tongue2", 1, "leftArm", 0.5, "rightArm", 0.5, "leftEar", 1, "rightEar", 1};
    };
    class Interpolations
    {
    };
    transitionsInterpolated[] = {};
    transitionsSimple[] = {};
    transitionsDisabled[] = {};
};
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
class RscMsgBox
{
    movingEnable = 1;
    onLoad = "endLoadingScreen";
    class Top
    {
        class CA_Background_Top: RscPicture
        {
            x = 0.129999995;
            y = 0.239999995;
            w = 1.25489998;
            h = 0.104575001;
            moving = 1;
            text = "\\origins_pack\\ui\\ui_messagebox_top_ca.paa";
        };
    };
    class Middle
    {
        class CA_Background_Middle: RscPicture
        {
            x = 0.129999995;
            y = 0.344621003;
            w = 1.25489998;
            h = 0.0320000015;
            text = "\\origins_pack\\ui\\ui_messagebox_middle_ca.paa";
        };
        class CA_Text: RscStructuredText
        {
            idc = 101;
            x = 0.146044999;
            y = 0.344621003;
            w = 0.709999979;
            h = 0;
            size = 0.0392099991;
            class Attributes
            {
                color = "#e0d8a6";
            };
        };
    };
    class Bottom
    {
        class CA_Background_Bottom: RscPicture
        {
            x = 0.129999995;
            y = 0.376621008;
            w = 1.25489998;
            h = 0.209150001;
            text = "\\origins_pack\\ui\\ui_messagebox_bottom_ca.paa";
        };
        class CA_ButtonOK: RscShortcutButton
        {
            idc = 1;
            shortcuts[] = {"0x00050000+0", 28, 57, 156};
            text = "$STR_DISP_OK";
            default = 1;
            x = 0.450399995;
            y = 0.401621014;
            w = 0.200000003;
            font = "TahomaB";
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            h = 0.0700000003;
            class TextPos
            {
                left = 0.061999999;
                top = 0.00700000022;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00400000019;
                top = 0.00400000019;
                right = 0.00400000019;
                bottom = 0.00400000019;
            };
        };
        class CA_ButtonCancel: CA_ButtonOK
        {
            idc = 2;
            shortcuts[] = {"0x00050000+1"};
            text = "$STR_DISP_CANCEL";
            x = 0.660000026;
        };
    };
};
class RscDisplayPassword: RscStandardDisplay
{
    movingEnable = 0;
    simulationEnabled = 0;
    class controlsbackground
    {
        class MainbackFadedOrigins: RscPicture
        {
            x = "SafeZoneX";
            y = "SafeZoneY";
            w = "SafeZoneW";
            h = "SafeZoneH";
            colorText[] = {1, 1, 1, 1};
            text = "\\origins_pack\\ui\\fon_co.paa";
        };
        delete CA_Background_Top;
        class CA_Background_TopOri: RscPicture
        {
            x = 0.129999995;
            y = 0.239999995;
            w = 1.25489998;
            h = 0.418300986;
            text = "\\origins_pack\\ui\\ui_background_messagebox_ca.paa";
        };
    };
    class controls
    {
        delete SetPasswordTitle;
        class TextPassword: RscText
        {
            idc = 1002;
            x = 0.191;
            y = 0.354166001;
            w = 0.161765993;
            text = "$STR_DISP_PASSWORD";
        };
        class ValuePassword: RscEdit
        {
            x = 0.361519009;
            y = 0.356617004;
            w = 0.330884993;
            h = 0.0392160006;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        class CA_ButtonCancel: RscShortcutButton
        {
            idc = 2;
            shortcuts[] = {"0x00050000+1"};
            text = "$STR_DISP_CANCEL";
            x = 0.200195998;
            y = 0.465923995;
            font = "TahomaB";
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            h = 0.0700000003;
            class TextPos
            {
                left = 0.0500000007;
                top = 0.00700000022;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00400000019;
                top = 0.00400000019;
                right = 0.00400000019;
                bottom = 0.00400000019;
            };
        };
        class CA_ButtonOK: RscShortcutButton
        {
            idc = 1;
            shortcuts[] = {"0x00050000+0", 28, 57, 156};
            text = "$STR_DISP_OK";
            default = 1;
            x = 0.604981005;
            y = 0.465923995;
            font = "TahomaB";
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            h = 0.0700000003;
            class TextPos
            {
                left = 0.061999999;
                top = 0.00700000022;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00400000019;
                top = 0.00400000019;
                right = 0.00400000019;
                bottom = 0.00400000019;
            };
        };
    };
};
class RscDisplayLoadCustom: RscDisplayLoadMission
{
    enableSimulation = 0;
    onload = "_this call compile preprocessfilelinenumbers 'ca\\ui\\scripts\\ui_loadingTextCustom.sqf';";
};
class RscDisplayLoading
{
    class Variants
    {
        class LoadingOne
        {
            class controls
            {
                class LoadingPic: RscPictureKeepAspect
                {
                    text = "z\\addons\\dayz_code\\gui\\a2edc_loading_wallpaper_00.paa";
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
            text = "z\\addons\\dayz_code\\gui\\a2edc_loading_wallpaper_00.paa";
        };
    };
};
class RscDisplayMain: RscStandardDisplay
{
    onKeyDown = " _dummy = _this execVM '\origins_pack\ui\scripts\mainmenuShortcuts.sqf';";
    class RscShortcutButtonMain2: RscShortcutButtonMain
    {
        animTextureNormal = "\\origins_pack\\ui\\ui_knopka_menu_disabled_ca.paa";
        animTextureDisabled = "\\origins_pack\\ui\\ui_knopka_menu_disabled_ca.paa";
        animTextureOver = "\\origins_pack\\ui\\ui_knopka_menu_over_ca.paa";
        animTextureFocused = "\\origins_pack\\ui\\ui_knopka_menu_focus_ca.paa";
        animTexturePressed = "\\origins_pack\\ui\\ui_knopka_menu_down_ca.paa";
        animTextureDefault = "\\origins_pack\\ui\\ui_knopka_menu_disabled_ca.paa";
        period = 0.5;
        periodFocus = 1.20000005;
        periodOver = 0.800000012;
    };
    class controlsBackground
    {
        class MainbackFadedOrigins: RscPicture
        {
            x = "SafeZoneX";
            y = "SafeZoneY";
            w = "SafeZoneW";
            h = "SafeZoneH";
            colorText[] = {1, 1, 1, 1};
            text = "\\origins_pack\\ui\\fon_co.paa";
        };
        delete Mainback;
        class Mainback_Ori: RscPicture
        {
            idc = 1104;
            x = 0.0450000018;
            y = 0.170000002;
            w = 0.627451003;
            h = 0.836601019;
            text = "\\origins_pack\\ui\\ui_menu_fon_ca.paa";
        };
        delete CA_ARMA2;
        class CA_ARMA2_Ori: RscPicture
        {
            idc = 1106;
            colorText[] = {1, 1, 1, "0.6+0.4"};
            x = "(SafeZoneW + SafeZoneX) - (0.1568627*1.5 + 0.04)";
            y = "SafeZoneY + 0.00";
            w = "0.1568627*1.5";
            h = "0.2091503*1.5";
            text = "z\\addons\\dayz_code\\gui\\Origins_logo_ca.paa";
        };
    };
    class controls
    {
        delete CA_Expansions;
        delete CA_SinglePlayer;
        class CA_Version;
        class DAYZ_Version: CA_Version
        {
            idc = -1;
            text = "Origins v.1.7.9 Alpha";
            y = "(SafeZoneH + SafeZoneY) - (1 - 0.95)";
        };
        class CA_MP: RscShortcutButtonMain2
        {
            y = 0.253699988;
            default = 0;
        };
        class CA_Options: RscShortcutButtonMain2
        {
            y = 0.35451901;
            default = 0;
        };
        class CA_PlayerProfile: RscShortcutButtonMain2
        {
            y = 0.455421001;
            default = 0;
        };
        class CA_Exit: RscShortcutButton
        {
            idc = 106;
            shortcuts[] = {"0x00050000+3"};
            x = 0.174309999;
            y = 0.879899979;
            w = 0.153825;
            h = 0.0799999982;
            text = "$STR_CA_MAIN_QUIT";
            toolTip = "$STR_TOOLTIP_MAIN_EXIT";
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            default = 1;
            class TextPos
            {
                left = 0.0399999991;
                top = 0.00999999978;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00999999978;
                top = 0.00999999978;
                right = 0.00999999978;
                bottom = 0.00999999978;
            };
        };
    };
};
class RscDisplayMultiplayer: RscStandardDisplay
{
    class controlsbackground
    {
        class CA_TitleBack: RscPicture
        {
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(02/100) * SafeZoneH + SafeZoneY";
            w = "(96/100) * SafeZoneW";
            h = "(06/100) * SafeZoneH";
            text = "\\origins_pack\\ui\\mp_topfon.paa";
        };
        delete MainbackSessions;
        delete CA_New;
        class Origins_Slogo: RscPictureKeepAspect
        {
            idc = 1107;
            x = "(0.7/100) * SafeZoneW + SafeZoneX";
            y = "(0.1/100) * SafeZoneH + SafeZoneY";
            w = "(10/100) * SafeZoneW";
            h = "(7.5/100) * SafeZoneH";
            text = "z\\addons\\dayz_code\\gui\\Origins_logo_ca.paa";
        };
        delete GameSpy;
        class GameSpyOri: RscPictureKeepAspect
        {
            idc = 1106;
            x = "(82/100) * SafeZoneW + SafeZoneX";
            y = "(2.5/100) * SafeZoneH + SafeZoneY";
            w = "(15/100) * SafeZoneW";
            h = "(5/100) * SafeZoneH";
            text = "\\origins_pack\\ui\\gamespy_logo.paa";
        };
        delete CA_Title2Border;
        delete CA_Title2;
        delete ValueSessionsBorder;
        class CA_Title2ori: RscText
        {
            idc = 101;
            style = 2;
            font = "TahomaB";
            sizeEx = 0.0590653606;
            colorText[] = {0, 0, 0, 0.899999976};
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(02/100) * SafeZoneH + SafeZoneY";
            w = "(96/100) * SafeZoneW";
            h = "(06/100) * SafeZoneH";
        };
        class CA_ServerDetailHost: RscText
        {
            idc = 129;
            SizeEx = 0.0267399997;
            font = "TahomaB";
            x = "(04/100) * SafeZoneW + SafeZoneX";
            y = "(78/100) * SafeZoneH + SafeZoneY";
            w = "(94/100) * SafeZoneW";
            h = "(2/100) * SafeZoneH";
            colorbackground[] = {0.196099997, 0.145099998, 0.0940999985, 0.419999987};
        };
        delete CA_TextServerDetailDifficulty;
        class CA_TextServerDetailDifficulty_Ori: CA_ServerDetailHost
        {
            text = "$STR_CA_DIFFICULTY";
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(87/100) * SafeZoneH + SafeZoneY";
            w = "(15/100) * SafeZoneW";
            h = "(2/100) * SafeZoneH";
        };
        delete CA_ServerDetailDifficulty;
        class CA_ServerDetailDifficulty_Ori: CA_ServerDetailHost
        {
            idc = 138;
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(90/100) * SafeZoneH + SafeZoneY";
            w = "(15/100) * SafeZoneW";
            h = "(2/100) * SafeZoneH";
        };
        delete CA_TextServerDetailPlayers;
        class CA_TextServerDetailPlayers_Ori: CA_ServerDetailHost
        {
            text = "$STR_DISP_MP_PLAYERS";
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(81/100) * SafeZoneH + SafeZoneY";
            w = "(15/100) * SafeZoneW";
            h = "(5/100)* SafeZoneH";
            SizeEx = 0.0299999993;
        };
        delete CA_ServerDetailPlayers;
        class CA_ServerDetailPlayers_Ori: CA_ServerDetailHost
        {
            idc = 149;
            style = "0x10 + 0x200";
            lineSpacing = 0.899999976;
            x = "(18/100) * SafeZoneW + SafeZoneX";
            y = "(81/100) * SafeZoneH + SafeZoneY";
            w = "(80/100) * SafeZoneW";
            h = "(12.75/100)* SafeZoneH";
        };
        class CA_ServerDetailPassword: RscPictureKeepAspect
        {
            idc = 143;
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(78/100) * SafeZoneH + SafeZoneY";
            w = "(2/100) * SafeZoneW";
            h = "(2/100) * SafeZoneH";
        };
        class CA_ServerIcon: RscPictureKeepAspect
        {
            idc = 111;
            x = "(01.5/100) * SafeZoneW + SafeZoneX";
            y = "(9/100) * SafeZoneH + SafeZoneY";
            w = 0.0299999993;
            h = 0.0299999993;
            colorText[] = {1, 1, 1, 1};
        };
        class CA_TypeIcon: CA_ServerIcon
        {
            idc = 140;
            x = "(39.25/100) * SafeZoneW + SafeZoneX";
        };
        class CA_MissionIcon: CA_ServerIcon
        {
            idc = 113;
            x = "(45.5/100) * SafeZoneW + SafeZoneX";
        };
        class CA_StateIcon: CA_ServerIcon
        {
            idc = 115;
            x = "(78.25/100) * SafeZoneW + SafeZoneX";
        };
        class CA_PlayersIcon: CA_ServerIcon
        {
            idc = 117;
            x = "(85.5/100) * SafeZoneW + SafeZoneX";
        };
        class CA_PingIcon: CA_ServerIcon
        {
            idc = 119;
            x = "(91.75/100) * SafeZoneW + SafeZoneX";
        };
        class CA_FilterPasswordedServers: RscPictureKeepAspect
        {
            idc = 150;
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(75/100) * SafeZoneH + SafeZoneY";
            w = "(2/100) * SafeZoneW";
            h = "(3/100) * SafeZoneH";
        };
        class CA_FilterFullServers: CA_FilterPasswordedServers
        {
            idc = 151;
            x = "(5/100) * SafeZoneW + SafeZoneX";
        };
        class CA_ServerBEFilter: CA_FilterPasswordedServers
        {
            idc = 154;
            x = "(8/100) * SafeZoneW + SafeZoneX";
        };
        class CA_ServerExpansionsFilter: CA_FilterPasswordedServers
        {
            idc = 155;
            x = "(11/100) * SafeZoneW + SafeZoneX";
        };
        class CA_ServerFilter: RscText
        {
            idc = 125;
            SizeEx = 0.0267399997;
            x = "(16/100) * SafeZoneW + SafeZoneX";
            y = "(75/100) * SafeZoneH + SafeZoneY";
            w = "(20/100) * SafeZoneW";
            h = "(3/100) * SafeZoneH";
            text = "Official Dayz Origins";
            font = "TahomaB";
        };
        class CA_TypeFilter: CA_ServerFilter
        {
            idc = 152;
            x = "(40/100) * SafeZoneW + SafeZoneX";
            w = "(8/100) * SafeZoneW";
        };
        class CA_MissionFilter: CA_ServerFilter
        {
            idc = 126;
            x = "(55/100) * SafeZoneW + SafeZoneX";
        };
        class CA_PlayersFilter: CA_ServerFilter
        {
            idc = 127;
            style = 2;
            x = "(86.5/100) * SafeZoneW + SafeZoneX";
            w = "(6/100) * SafeZoneW";
        };
        class CA_PingFilter: CA_ServerFilter
        {
            idc = 128;
            x = "(93/100) * SafeZoneW + SafeZoneX";
            w = "(4/100) * SafeZoneW";
        };
        class CA_Cancel: RscShortcutButton
        {
            idc = 2;
            default = 0;
            x = "(85/100) * SafeZoneW + SafeZoneX";
            y = "(95/100) * SafeZoneH + SafeZoneY";
            shortcuts[] = {"0x00050000+1"};
            text = "$STR_CA_CANCEL";
            font = "TahomaB";
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            h = 0.0700000003;
            class TextPos
            {
                left = 0.0491999984;
                top = 0.00499999989;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00400000019;
                top = 0.00400000019;
                right = 0.00400000019;
                bottom = 0.00400000019;
            };
        };
        class CA_Internet_Lan: CA_Cancel
        {
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(95/100) * SafeZoneH + SafeZoneY";
            w = 0.28382501;
            default = 0;
            class TextPos
            {
                left = 0.0560000017;
                top = 0.00499999989;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            shortcuts[] = {};
            idc = 122;
        };
        class CA_Refresh: CA_Cancel
        {
            x = "(29/100) * SafeZoneW + SafeZoneX";
            y = "(95/100) * SafeZoneH + SafeZoneY";
            idc = 123;
            default = 0;
            text = "$STR_DISP_MULTI_REFRESH";
            shortcuts[] = {"0x00050000+3"};
            class TextPos
            {
                left = 0.0460000001;
                top = 0.00499999989;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
        };
        class CA_Join: CA_Cancel
        {
            x = "(43/100) * SafeZoneW + SafeZoneX";
            y = "(95/100) * SafeZoneH + SafeZoneY";
            idc = 105;
            shortcuts[] = {"0x00050000+0", 28, 57, 156};
            default = 1;
            text = "$STR_CA_MULTI_JOIN";
            class TextPos
            {
                left = 0.0480000004;
                top = 0.00499999989;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
        };
        class CA_BFilter: CA_Cancel
        {
            x = "(57/100) * SafeZoneW + SafeZoneX";
            y = "(95/100) * SafeZoneH + SafeZoneY";
            idc = 124;
            default = 0;
            shortcuts[] = {"0x00050000+2"};
            text = "$STR_DISP_MULTI_FILTER";
            class TextPos
            {
                left = 0.0460000001;
                top = 0.00499999989;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
        };
        class CA_BRemote: CA_Cancel
        {
            x = "(71/100) * SafeZoneW + SafeZoneX";
            y = "(95/100) * SafeZoneH + SafeZoneY";
            idc = 103;
            default = 0;
            shortcuts[] = {};
            text = "$STR_CA_MULTI_REMOTE";
            class TextPos
            {
                left = 0.0329999998;
                top = 0.00499999989;
                right = 0.00499999989;
                bottom = 0.00499999989;
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
        class Mainback: RscPicture
        {
            x = "SafeZoneX";
            y = "SafeZoneY";
            w = "SafeZoneW";
            h = "SafeZoneH";
            colorbackground[] = {0, 0, 0, 0};
            text = "\\origins_pack\\ui\\fon_co.paa";
        };
    };
    class controls
    {
        delete CA_MissionColumn;
        delete CA_TypeColumn;
        class CA_ServerColumn: RscButtonTextOnly
        {
            idc = 112;
            text = "$STR_MP_SERVER";
            font = "TahomaB";
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(9/100) * SafeZoneH + SafeZoneY";
            w = "(75/100) * SafeZoneW";
            h = "(2/100) * SafeZoneH";
            colorBackgroundActive[] = {1, 1, 1, 0.550000012};
            colorBackgroundDisabled[] = {1, 1, 1, 1};
        };
        class CA_StateColumn: CA_ServerColumn
        {
            idc = 116;
            text = "$STR_MENU_STATUS";
            font = "TahomaB";
            x = "(78.5/100) * SafeZoneW + SafeZoneX";
            w = "(8/100) * SafeZoneW";
        };
        class CA_PlayersColumn: CA_ServerColumn
        {
            idc = 118;
            text = "$STR_MP_PLAYERS";
            font = "TahomaB";
            x = "(87/100) * SafeZoneW + SafeZoneX";
            w = "(6/100) * SafeZoneW";
        };
        class CA_PingColumn: CA_ServerColumn
        {
            idc = 120;
            text = "$STR_DISP_MULTI_PING";
            font = "TahomaB";
            x = "(93/100) * SafeZoneW + SafeZoneX";
            w = "(4/100) * SafeZoneW";
        };
        class CA_ValueSessions: RscIGUIListBox
        {
            idc = 102;
            style = 16;
            shadow = 2;
            font = "TahomaB";
            colorSelect[] = {0.689999998, 0.768999994, 0.870999992, 1};
            colorPingUnknown[] = {0.400000006, 0.400000006, 0.400000006, 1};
            colorPingGood[] = {0, 1, 0, 1};
            colorPingPoor[] = {1, 0.600000024, 0, 1};
            colorPingBad[] = {1, 0, 0, 1};
            rowHeight = 0.0250000004;
            colorSelectBackground[] = {0, 0, 0, 1};
            colorSelectBackground2[] = {0.579999983, 0.114699997, 0.110799998, 1};
            password = "ca\\ui\\data\\ui_server_password_ca.paa";
            locked = "ca\\ui\\data\\ui_server_locked_ca.paa";
            version = "ca\\ui\\data\\ui_wrong_version_ca.paa";
            none = "ca\\ui\\data\\ui_server_connect_ca.paa";
            star = "ca\\ui\\data\\ui_mission_done_ca.paa";
            addons = "ca\\ui\\data\\ui_server_addons_ca.paa";
            mods = "ca\\ui\\data\\ui_server_red_mark_ca.paa";
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(12/100) * SafeZoneH + SafeZoneY";
            w = "(96/100) * SafeZoneW";
            h = "(61.25/100) * SafeZoneH";
            SizeEx = 0.0250000004;
            columns[] = {0.810000002, 0, 0, 0.100000001, 0.0500000007, 0.0399999991};
        };
    };
};
class RscDisplayFilter: RscStandardDisplay
{
    class controlsBackground
    {
        class MainbackFadedOrigins: RscPicture
        {
            x = "SafeZoneX";
            y = "SafeZoneY";
            w = "SafeZoneW";
            h = "SafeZoneH";
            colorText[] = {1, 1, 1, 1};
            text = "\\origins_pack\\ui\\fon_co.paa";
        };
        delete MainbackFaded1;
        class MainbackFaded1_ori: RscPicture
        {
            idc = 1106;
            x = 0.0450000018;
            y = 0.170000002;
            w = 0.627451003;
            h = 0.836601019;
            colorText[] = {1, 1, 1, 0.25};
            text = "\\origins_pack\\ui\\ui_menu_fonf_ca.paa";
        };
        delete MainbackFaded2;
        class MainbackFaded2_ori: RscPicture
        {
            idc = 1107;
            x = 0.0920000002;
            y = 0.170000002;
            w = 0.627451003;
            h = 0.836601019;
            colorText[] = {1, 1, 1, 0.5};
            text = "\\origins_pack\\ui\\ui_menu_fonf_ca.paa";
        };
        delete Mainback;
        class Mainback_ori: RscPicture
        {
            idc = 1104;
            x = 0.137999997;
            y = 0.170000002;
            w = 0.627451003;
            h = 0.836601019;
            text = "\\origins_pack\\ui\\ui_menu_fonf_ca.paa";
        };
    };
    class controls
    {
        class CA_FilterTitle: CA_Title
        {
            x = 0.180000007;
            y = 0.192000002;
            text = "$STR_DISP_FILTER_TITLE";
        };
        class CA_TextServer: RscText
        {
            x = 0.159803003;
            y = "(0.416549 + -3*0.0500)";
            w = 0.235295996;
            text = "$STR_DISP_FILTER_SERVER";
        };
        class CA_ValueServer: RscEdit
        {
            idc = 101;
            x = 0.400534004;
            y = "(0.416549 + -3*0.0500)";
            w = 0.300000012;
        };
        class CA_TextMaxPing: CA_TextServer
        {
            x = 0.159803003;
            y = "(0.416549 + -2*0.0500)";
            text = "$STR_DISP_FILTER_MAXPING";
        };
        class CA_ValueMaxPing: CA_ValueServer
        {
            idc = 103;
            x = 0.400534004;
            y = "(0.416549 + -2*0.0500)";
            w = 0.100000001;
        };
        class CA_TextMinPlayers: CA_TextServer
        {
            x = 0.159803003;
            y = "(0.416549 + -1*0.0500)";
            text = "$STR_DISP_FILTER_MINPLAYERS";
        };
        class CA_ValueMinPlayers: CA_ValueMaxPing
        {
            idc = 104;
            x = 0.400534004;
            y = "(0.416549 + -1*0.0500)";
        };
        class CA_TextMaxPlayers: CA_TextServer
        {
            x = 0.159803003;
            y = "(0.416549 + 0*0.0500)";
            text = "$STR_DISP_FILTER_MAXPLAYERS";
        };
        class CA_ValueMaxPlayers: CA_ValueMaxPing
        {
            idc = 105;
            x = 0.400534004;
            y = "(0.416549 + 0*0.0500)";
        };
        class CA_TextMission: CA_TextServer
        {
            x = 0.159803003;
            y = "(0.416549 + 1*0.0500)";
            text = "$STR_DISP_FILTER_MISSION";
        };
        class ValueMission: CA_ValueServer
        {
            idc = 102;
            x = 0.400534004;
            y = "(0.416549 + 1*0.0500)";
        };
        class CA_TextFilterType: CA_TextServer
        {
            x = 0.159803003;
            y = "(0.416549 + 2*0.0500)";
            text = "$STR_DISP_ARCGRP_TYPE";
        };
        class CA_FilterType: RscCombo
        {
            idc = 109;
            x = 0.400534004;
            y = "(0.416549 + 2*0.0500)";
            w = 0.300000012;
        };
        class CA_TextExpansionsType: CA_TextServer
        {
            x = 0.159803003;
            y = "(0.416549 + 3*0.0500)";
            text = "$STR_DISP_EXPANSIONS";
        };
        class CA_FilterExpansions: RscXListBox
        {
            idc = 111;
            x = 0.400534004;
            y = "(0.416549 + 3*0.0500)";
            w = 0.300000012;
        };
        class CA_TextHideFull: CA_TextServer
        {
            x = 0.159803003;
            y = "(0.416549 + 4*0.0500)";
            text = "$STR_FILTER_FULL_TEXT";
        };
        class CA_FullServers: RscXListBox
        {
            idc = 106;
            x = 0.400534004;
            y = "(0.416549 + 4*0.0500)";
            w = 0.300000012;
        };
        class CA_TextPassworded: CA_TextServer
        {
            x = 0.159803003;
            y = "(0.416549 + 5*0.0500)";
            text = "$STR_FILTER_PASSWORDED_TEXT";
        };
        class CA_PasswordedServers: CA_FullServers
        {
            idc = 107;
            x = 0.400534004;
            y = "(0.416549 + 5*0.0500)";
        };
        class CA_TextBattlEye: CA_TextServer
        {
            x = 0.159803003;
            y = "(0.416549 + 6*0.0500)";
            text = "$STR_FILTER_BATTLEYE_TEXT";
        };
        class CA_BEServers: CA_FullServers
        {
            idc = 110;
            x = 0.400534004;
            y = "(0.416549 + 6*0.0500)";
            w = 0.300000012;
        };
        class CA_Filter_Default: RscShortcutButton
        {
            idc = 108;
            shortcuts[] = {"0x00050000+2"};
            x = 0.33950001;
            y = 0.762499988;
            text = "$STR_DISP_DEFAULT";
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            h = 0.0700000003;
            class TextPos
            {
                left = 0.0399999991;
                top = 0.00700000022;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00999999978;
                top = 0.00999999978;
                right = 0.00999999978;
                bottom = 0.00999999978;
            };
        };
        class CA_Filter_Ok: RscShortcutButton
        {
            idc = 1;
            shortcuts[] = {"0x00050000+0", 28, 57, 156};
            x = 0.524999976;
            y = 0.762499988;
            text = "$STR_DISP_OK";
            default = 1;
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            h = 0.0700000003;
            class TextPos
            {
                left = 0.0599999987;
                top = 0.00700000022;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00999999978;
                top = 0.00999999978;
                right = 0.00999999978;
                bottom = 0.00999999978;
            };
        };
        class CA_Filter_Cancel: RscShortcutButton
        {
            idc = 2;
            shortcuts[] = {"0x00050000+1"};
            x = 0.157000005;
            y = 0.762499988;
            text = "$STR_DISP_CANCEL";
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            h = 0.0700000003;
            class TextPos
            {
                left = 0.0500000007;
                top = 0.00700000022;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00999999978;
                top = 0.00999999978;
                right = 0.00999999978;
                bottom = 0.00999999978;
            };
        };
    };
};
class RscDisplayIPAddress: RscStandardDisplay
{
    class controlsBackground
    {
        class MainbackFadedOrigins: RscPicture
        {
            x = "SafeZoneX";
            y = "SafeZoneY";
            w = "SafeZoneW";
            h = "SafeZoneH";
            colorText[] = {1, 1, 1, 1};
            text = "\\origins_pack\\ui\\fon_co.paa";
        };
        delete MainbackFaded1;
        class MainbackFaded1_ori: RscPicture
        {
            idc = 1106;
            x = 0.0450000018;
            y = 0.170000002;
            w = 0.627451003;
            h = 0.836601019;
            colorText[] = {1, 1, 1, 0.25};
            text = "\\origins_pack\\ui\\ui_menu_fon_ca.paa";
        };
        delete MainbackFaded2;
        class MainbackFaded2_ori: RscPicture
        {
            idc = 1107;
            x = 0.0920000002;
            y = 0.170000002;
            w = 0.627451003;
            h = 0.836601019;
            colorText[] = {1, 1, 1, 0.5};
            text = "\\origins_pack\\ui\\ui_menu_fon_ca.paa";
        };
        delete Mainback;
        class Mainback_ori: RscPicture
        {
            idc = 1104;
            x = 0.137999997;
            y = 0.170000002;
            w = 0.627451003;
            h = 0.836601019;
            text = "\\origins_pack\\ui\\ui_menu_fon_ca.paa";
        };
    };
    class controls
    {
        class CA_IPTitle: CA_Title
        {
            x = 0.180000007;
            y = 0.192000002;
            text = "$STR_DISP_IP_TITLE";
        };
        class CA_TextAddress: RscText
        {
            x = 0.160705999;
            y = 0.279628009;
            w = 0.169119;
            text = "$STR_DISP_IP_ADDRESS";
        };
        class CA_ValueAddress: RscEdit
        {
            idc = 101;
            x = 0.261779994;
            y = 0.279628009;
            w = 0.180000007;
            h = 0.0392160006;
        };
        class CA_TextPort: CA_TextAddress
        {
            y = 0.328648001;
            text = "$STR_DISP_IP_PORT";
        };
        class CA_ValuePort: CA_ValueAddress
        {
            idc = 102;
            y = 0.328648001;
            w = 0.110294998;
        };
        class ButtonContinue: RscShortcutButton
        {
            idc = 1;
            default = 1;
            shortcuts[] = {"0x00050000+0", 28, 57, 156};
            x = 0.261779994;
            y = 0.398647994;
            text = "$STR_DISP_OK";
            w = 0.153825;
            h = 0.0700000003;
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            class TextPos
            {
                left = 0.0500000007;
                top = 0.00499999989;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00999999978;
                top = 0.00999999978;
                right = 0.00999999978;
                bottom = 0.00999999978;
            };
        };
        class ButtonCancel: RscShortcutButton
        {
            idc = 2;
            default = 0;
            shortcuts[] = {"0x00050000+1"};
            x = 0.270000011;
            y = 0.882499993;
            text = "$STR_DISP_BACK";
            h = 0.0700000003;
            w = 0.153825;
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            class TextPos
            {
                left = 0.0399999991;
                top = 0.00499999989;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00999999978;
                top = 0.00999999978;
                right = 0.00999999978;
                bottom = 0.00999999978;
            };
        };
    };
};
class dStronghold
{
    class RscPictureK
    {
        type = 0;
        style = 48;
        colorText[] = {0.75, 0.75, 0.75, 1};
        colorBackground[] = {0, 0, 0, 0};
        font = "Bitstream";
        sizeEx = 0.0250000004;
        soundClick[] = {"", 0.200000003, 1};
        soundEnter[] = {"", 0.200000003, 1};
        soundEscape[] = {"", 0.200000003, 1};
        soundPush[] = {"", 0.200000003, 1};
        w = 0.275000006;
        h = 0.0399999991;
        text = "";
    };
    class RscButtonK
    {
        type = 1;
        style = 2;
        colorText[] = {0, 0, 0, 1};
        font = "TahomaB";
        sizeEx = 0.0500000007;
        soundPush[] = {"", 0.200000003, 1};
        soundClick[] = {"\\ca\\ui\\data\\sound\\new1", 0.200000003, 1};
        soundEscape[] = {"\\ca\\ui\\data\\sound\\new1", 0.200000003, 1};
        default = 0;
        text = "";
        action = "";
        colorActive[] = {0, 0, 0, 0};
        colorDisabled[] = {0, 0, 0, 0.100000001};
        colorBackground[] = {0, 0, 0, 0.300000012};
        colorBackgroundActive[] = {0, 0, 0, 0.400000006};
        colorBackgroundDisabled[] = {0, 0, 0, 0.300000012};
        colorFocused[] = {0.839999974, 1, 0.550000012, 1};
        colorShadow[] = {1, 1, 1, 0.100000001};
        colorBorder[] = {0, 0, 0, 0.100000001};
        offsetX = 0;
        offsetY = 0;
        offsetPressedX = 0;
        offsetPressedY = 0;
        borderSize = 0;
        soundEnter[] = {"", 0.150000006, 1};
        period = 0;
    };
    class Ori_Button
    {
        type = 16;
        style = 0;
        default = 0;
        x = 0.100000001;
        y = 0.100000001;
        w = 0.183825001;
        h = 0.104575001;
        color[] = {0.542999983, 0.574199975, 0.4102, 1};
        color2[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorBackground[] = {1, 1, 1, 1};
        colorbackground2[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.25};
        periodFocus = 1.20000005;
        periodOver = 0.800000012;
        class HitZone
        {
            left = 0.00400000019;
            top = 0.00899999961;
            right = 0.00400000019;
            bottom = 0.00899999961;
        };
        class ShortcutPos
        {
            left = 0.0144999996;
            top = 0.0260000005;
            w = 0.0392156988;
            h = 0.0522876009;
        };
        class TextPos
        {
            left = 0.00499999989;
            top = 0.00999999978;
            right = 0.00499999989;
            bottom = 0.00499999989;
        };
        textureNoShortcut = "";
        animTextureNormal = "\\origins_pack\\ui\\knopka_normal.paa";
        animTextureDisabled = "\\origins_pack\\ui\\knopka_normal.paa";
        animTextureOver = "\\origins_pack\\ui\\knopka_hover.paa";
        animTextureFocused = "\\origins_pack\\ui\\knopka_hover.paa";
        animTexturePressed = "\\origins_pack\\ui\\knopka_press.paa";
        animTextureDefault = "\\origins_pack\\ui\\knopka_normal.paa";
        period = 0.400000006;
        font = "Zeppelin32";
        size = 0.0500000007;
        sizeEx = 0.0500000007;
        text = "";
        soundEnter[] = {"", 0.0900000036, 1};
        soundPush[] = {"", 0.0900000036, 1};
        soundClick[] = {"", 0.0700000003, 1};
        soundEscape[] = {"", 0.0900000036, 1};
        action = "";
        toolTip = "";
        class Attributes
        {
            font = "Zeppelin32";
            color = "#E5E5E5";
            align = "center";
            shadow = 1;
        };
        class AttributesImage
        {
            font = "Zeppelin32";
            color = "#E5E5E5";
            align = "center";
            shadow = 1;
        };
    };
    class RscListBoxK
    {
        type = 5;
        canDrag = 0;
        style = "0 + 0x10";
        font = "Zeppelin32";
        sizeEx = 0.0422100015;
        rowHeight = 0.0299999993;
        colorBackground[] = {0.800000012, 0.800000012, 1, 0.699999988};
        colorText[] = {1, 1, 1, 0.75};
        colorScrollbar[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorSelect[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorSelect2[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorSelectBackground[] = {0.600000024, 0.83920002, 0.470600009, 1};
        colorSelectBackground2[] = {0.600000024, 0.83920002, 0.470600009, 1};
        columns[] = {0.100000001, 0.699999988, 0.100000001, 0.100000001};
        period = 0;
        maxHistoryDelay = 1;
        autoScrollSpeed = -1;
        autoScrollDelay = 5;
        autoScrollRewind = 0;
        soundSelect[] = {"\\ca\\ui\\data\\sound\\new1", 0.0900000036, 1};
        class ScrollBar
        {
            color[] = {1, 1, 1, 0.600000024};
            colorActive[] = {1, 1, 1, 1};
            colorDisabled[] = {1, 1, 1, 0.300000012};
            thumb = "\\ca\\ui\\data\\igui_scrollbar_thumb_ca.paa";
            arrowFull = "\\ca\\ui\\data\\igui_arrow_top_active_ca.paa";
            arrowEmpty = "\\ca\\ui\\data\\igui_arrow_top_ca.paa";
            border = "\\ca\\ui\\data\\igui_border_scroll_ca.paa";
        };
    };
    class RscTextK
    {
        type = 0;
        style = 2;
        colorText[] = {0, 1, 0.5, 1};
        font = "TahomaB";
        sizeEx = 0.0799999982;
        x = 0;
        y = 0;
        w = 0.100000001;
        h = 0.200000003;
    };
    name = "dStronghold";
    movingEnable = 0;
    idd = 10001;
    controlsBackground[] = {"bg"};
    objects[] = {};
    class controls
    {
        class listboxA: RscListBoxK
        {
            idc = 10002;
            x = "0.247 * safezoneW + safezoneX";
            y = "0.28 * safezoneH + safezoneY";
            w = "0.165 * safezoneW";
            h = "0.181 * safezoneH";
        };
        class listboxA2: RscListBoxK
        {
            idc = 10003;
            x = "0.45 * safezoneW + safezoneX";
            y = "0.28 * safezoneH + safezoneY";
            w = "0.165 * safezoneW";
            h = "0.181 * safezoneH";
        };
        class but_del: Ori_Button
        {
            idc = -1;
            x = "0.245 * safezoneW + safezoneX";
            y = "0.478 * safezoneH + safezoneY";
            w = "0.1 * safezoneW";
            h = "0.04 * safezoneH";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            text = "REMOVE";
            action = "_index = lbCurSel 10002; if(_index > -1) then { selected_sl = []; selected_sl_n = []; selected_sl set [count selected_sl, playersID_arr select _index]; selected_sl_n set [count selected_sl_n, playersID_arr_n select _index]; playersID_arr = playersID_arr - selected_sl; playersID_arr_n = playersID_arr_n - selected_sl_n; playersID_arr2 set [count playersID_arr2, selected_sl select 0]; playersID_arr2_n set [count playersID_arr2_n, selected_sl_n select 0]; _text = lbText [10002, _index]; lbAdd [10003, _text]; lbDelete [10002, _index]; selected_sl = []; selected_sl_n = []; };";
        };
        class but_add: Ori_Button
        {
            idc = -1;
            x = "0.45 * safezoneW + safezoneX";
            y = "0.478 * safezoneH + safezoneY";
            w = "0.1 * safezoneW";
            h = "0.04 * safezoneH";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            text = "ADD";
            action = "_index = lbCurSel 10003; if(_index > -1) then { selected_sl = []; selected_sl_n = []; selected_sl set [count selected_sl, playersID_arr2 select _index]; selected_sl_n set [count selected_sl_n, playersID_arr2_n select _index]; hint format[\"%1\\n%2\\n\",selected_sl,selected_sl_n]; playersID_arr2 = playersID_arr2 - selected_sl; playersID_arr2_n = playersID_arr2_n - selected_sl_n; playersID_arr set [count playersID_arr, selected_sl select 0]; playersID_arr_n set [count playersID_arr_n, selected_sl_n select 0]; _text = lbText [10003, _index];  lbAdd [10002, _text]; lbDelete [10003, _index]; selected_sl = []; selected_sl_n = []; };";
        };
        class but_ok: Ori_Button
        {
            idc = -1;
            x = "0.54 * safezoneW + safezoneX";
            y = "0.54 * safezoneH + safezoneY";
            w = "0.1 * safezoneW";
            h = "0.04 * safezoneH";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            text = "OK";
            action = "_vsego = count playersID_arr; if(_vsego > 3) then { NaDobavku = [] + playersID_arr; ctrlSetText [10004, \"OK\"]; closeDialog 0; } else { NaDobavku = []; ctrlSetText [10004, \"Minimum 4 people\"]; };";
        };
        class zagolvok: RscTextK
        {
            idc = -1;
            x = "0.305 * safezoneW + safezoneX";
            y = "0.20 * safezoneH + safezoneY";
            w = "0.27 * safezoneW";
            h = "0.04 * safezoneH";
            size = 0.0649999976;
            sizeEx = "0.065 * (safezoneW + safezoneX)";
            text = "Stronghold Team";
            colorText[] = {0, 0, 0, 0.899999976};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class zagolvok_team: RscTextK
        {
            idc = -1;
            x = "0.24 * safezoneW + safezoneX";
            y = "0.24 * safezoneH + safezoneY";
            w = "0.17 * safezoneW";
            h = "0.04 * safezoneH";
            text = "Members";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            colorText[] = {0.75, 0.75, 0.75, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class zagolvok_new: RscTextK
        {
            idc = -1;
            x = "0.45 * safezoneW + safezoneX";
            y = "0.24 * safezoneH + safezoneY";
            w = "0.17 * safezoneW";
            h = "0.04 * safezoneH";
            text = "New members";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            colorText[] = {0.75, 0.75, 0.75, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class zagolvok_error: RscTextK
        {
            idc = 10004;
            x = "0.305 * safezoneW + safezoneX";
            y = "0.53 * safezoneH + safezoneY";
            w = "0.17 * safezoneW";
            h = "0.04 * safezoneH";
            text = "";
            size = 0.0350000001;
            sizeEx = 0.0350000001;
            colorText[] = {1, 1, 1, 0.75};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
    };
    class bg: RscPictureK
    {
        idc = -1;
        x = "0.20 * safezoneW + safezoneX";
        y = "0.20 * safezoneH + safezoneY";
        w = "0.47 * safezoneW";
        h = "0.40 * safezoneH";
        text = "\\origins_pack\\ui\\fon.paa";
        colorBackground[] = {0, 0.128000006, 0, 1};
    };
};
class KeypadHouse
{
    idd = 20900;
    movingEnable = 0;
    controlsBackground[] = {};
    controls[] = {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B0", "BEnter", "BAbort", "KeypadImage", "NumberDisplay"};
    objects[] = {};
    class B1
    {
        idc = -1;
        type = 1;
        style = 2;
        moving = 0;
        x = 0.449999988;
        y = 0.460000008;
        h = 0.0599999987;
        w = 0.0399999991;
        font = "Zeppelin32";
        sizeEx = 0.0500000007;
        action = "CODEINPUT set [count CODEINPUT, 1]; if ((count CODEINPUT) ==7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 1];};";
        text = "";
        default = 0;
        colorText[] = {0, 0, 0, 1};
        colorFocused[] = {0.100000001, 0.100000001, 0.100000001, 0.100000001};
        colorShadow[] = {0, 0, 0, 0};
        colorBorder[] = {0.5, 0.5, 0.5, 0};
        colorBackground[] = {0.699999988, 0.699999988, 0.699999988, 1};
        colorBackgroundActive[] = {0.100000001, 0.100000001, 0.100000001, 0.300000012};
        colorDisabled[] = {1, 0, 0, 1};
        colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 0};
        borderSize = 0.0149999997;
        offsetX = 0.00499999989;
        offsetY = 0.00499999989;
        offsetPressedX = 0.00200000009;
        offsetPressedY = 0.00200000009;
        soundEnter[] = {"", 0, 1};
        soundPush[] = {"", 0, 1};
        soundClick[] = {"", 0, 1};
        soundEscape[] = {"", 0, 1};
    };
    class B2: B1
    {
        x = 0.519999981;
        text = "";
        action = "CODEINPUT set [count CODEINPUT, 2]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 2];};";
    };
    class B3: B1
    {
        x = 0.589999974;
        text = "";
        action = "CODEINPUT set [count CODEINPUT, 3]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 3];};";
    };
    class B4: B1
    {
        y = 0.569999993;
        text = "";
        action = "CODEINPUT set [count CODEINPUT, 4]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 4];};";
    };
    class B5: B4
    {
        x = 0.519999981;
        text = "";
        action = "CODEINPUT set [count CODEINPUT, 5]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 5];};";
    };
    class B6: B4
    {
        x = 0.589999974;
        text = "";
        action = "CODEINPUT set [count CODEINPUT, 6]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 6];};";
    };
    class B7: B1
    {
        y = 0.670000017;
        text = "";
        action = "CODEINPUT set [count CODEINPUT, 7]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 7];};";
    };
    class B8: B7
    {
        x = 0.519999981;
        text = "";
        action = "CODEINPUT set [count CODEINPUT, 8]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 8];};";
    };
    class B9: B7
    {
        x = 0.589999974;
        text = "";
        action = "CODEINPUT set [count CODEINPUT, 9]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = [];} else { ctrlSetText [1099, (ctrlText 1099) + str 9];};";
    };
    class B0: B8
    {
        y = 0.769999981;
        text = "";
        action = "CODEINPUT set [count CODEINPUT, 0]; if ((count CODEINPUT) == 7) then { ctrlSetText [1099, '']; CODEINPUT = []; } else { ctrlSetText [1099, (ctrlText 1099) + str 0]; };";
    };
    class BEnter: B9
    {
        y = 0.769999981;
        text = "";
        action = "CODE = ctrlText (findDisplay 20900 displayCtrl 1099); closeDialog 0;";
    };
    class BAbort: B7
    {
        y = 0.769999981;
        text = "";
        action = "CODE = \"\"; CODEINPUT = []; closeDialog 0;";
    };
    class KeypadImage
    {
        idc = -1;
        type = 0;
        style = 48;
        colorText[] = {};
        colorBackground[] = {};
        font = "Zeppelin32";
        sizeEx = 0.023;
        x = 0.349999994;
        y = 0.200000003;
        w = 0.400000006;
        h = 0.800000012;
        text = "\\origins_pack\\structures\\textures\\pin_machine_co.paa";
    };
    class NumberDisplay
    {
        idc = 1099;
        type = 0;
        style = 0;
        colorText[] = {1, 0, 0, 1};
        colorBackground[] = {1, 1, 1, 0};
        font = "TahomaB";
        sizeEx = 0.0719999969;
        x = 0.439999998;
        y = 0.280000001;
        w = 0.209999993;
        h = 0.100000001;
        text = "";
    };
};
class ZadanieOrigins
{
    class RscPictureZ
    {
        type = 0;
        style = 48;
        colorText[] = {0.75, 0.75, 0.75, 1};
        colorBackground[] = {0, 0, 0, 0};
        font = "Bitstream";
        sizeEx = 0.0250000004;
        soundClick[] = {"", 0.200000003, 1};
        soundEnter[] = {"", 0.200000003, 1};
        soundEscape[] = {"", 0.200000003, 1};
        soundPush[] = {"", 0.200000003, 1};
        w = 0.275000006;
        h = 0.0399999991;
        text = "";
    };
    class Ori_B_Zadanie
    {
        type = 16;
        style = 0;
        default = 0;
        x = 0.100000001;
        y = 0.100000001;
        w = 0.183825001;
        h = 0.104575001;
        color[] = {0.542999983, 0.574199975, 0.4102, 1};
        color2[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorBackground[] = {1, 1, 1, 1};
        colorbackground2[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.25};
        periodFocus = 1.20000005;
        periodOver = 0.800000012;
        class HitZone
        {
            left = 0.00400000019;
            top = 0.00899999961;
            right = 0.00400000019;
            bottom = 0.00899999961;
        };
        class ShortcutPos
        {
            left = 0.0144999996;
            top = 0.0260000005;
            w = 0.0392156988;
            h = 0.0522876009;
        };
        class TextPos
        {
            left = 0.00499999989;
            top = 0.00999999978;
            right = 0.00499999989;
            bottom = 0.00499999989;
        };
        textureNoShortcut = "";
        animTextureNormal = "\\origins_pack\\ui\\power_normal_ca.paa";
        animTextureDisabled = "\\origins_pack\\ui\\power_normal_ca.paa";
        animTextureOver = "\\origins_pack\\ui\\power_hover_ca.paa";
        animTextureFocused = "\\origins_pack\\ui\\power_hover_ca.paa";
        animTexturePressed = "\\origins_pack\\ui\\power_down_ca.paa";
        animTextureDefault = "\\origins_pack\\ui\\power_normal_ca.paa";
        period = 0.400000006;
        font = "Zeppelin32";
        size = 0.0500000007;
        sizeEx = 0.0500000007;
        text = "";
        soundEnter[] = {"", 0.0900000036, 1};
        soundPush[] = {"", 0.0900000036, 1};
        soundClick[] = {"", 0.0700000003, 1};
        soundEscape[] = {"", 0.0900000036, 1};
        action = "";
        toolTip = "";
        class Attributes
        {
            font = "Zeppelin32";
            color = "#E5E5E5";
            align = "center";
            shadow = 1;
        };
        class AttributesImage
        {
            font = "Zeppelin32";
            color = "#E5E5E5";
            align = "center";
            shadow = 1;
        };
    };
    class RscListBoxZ
    {
        type = 5;
        canDrag = 0;
        style = "0 + 0x10";
        font = "Zeppelin32";
        sizeEx = 0.0322099999;
        rowHeight = 0.0299999993;
        colorBackground[] = {0.800000012, 0.800000012, 1, 0.300000012};
        color[] = {1, 1, 1, 1};
        colorText[] = {1, 1, 1, 0.649999976};
        colorScrollbar[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorSelect[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorSelect2[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorSelectBackground[] = {0.600000024, 0.83920002, 0.470600009, 0.300000012};
        colorSelectBackground2[] = {0.600000024, 0.83920002, 0.470600009, 0.300000012};
        columns[] = {0.0199999996, 0.779999971, 0.100000001};
        period = 0;
        maxHistoryDelay = 1;
        autoScrollSpeed = -1;
        autoScrollDelay = 5;
        autoScrollRewind = 0;
        soundSelect[] = {"\\ca\\ui\\data\\sound\\new1", 0.0900000036, 1};
        class ScrollBar
        {
            color[] = {1, 1, 1, 0.600000024};
            colorActive[] = {1, 1, 1, 1};
            colorDisabled[] = {1, 1, 1, 0.300000012};
            thumb = "\\ca\\ui\\data\\igui_scrollbar_thumb_ca.paa";
            arrowFull = "\\ca\\ui\\data\\igui_arrow_top_active_ca.paa";
            arrowEmpty = "\\ca\\ui\\data\\igui_arrow_top_ca.paa";
            border = "\\ca\\ui\\data\\igui_border_scroll_ca.paa";
        };
    };
    class RscTextZ
    {
        type = 0;
        style = 2;
        colorText[] = {0, 1, 0.5, 1};
        colorBackground[] = {1, 0, 0, 0.5};
        font = "TahomaB";
        sizeEx = 0.0500000007;
        x = 0;
        y = 0;
        w = 0.100000001;
        h = 0.200000003;
    };
    class RscTextZ2
    {
        type = 0;
        idc = -1;
        access = 0;
        lineSpacing = 1;
        style = "16+0x200";
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 1, 1, 0.75};
        font = "Zeppelin32";
        size = 0.0289999992;
        sizeEx = 0.0280000009;
        text = "";
        class ScrollBar
        {
            color[] = {1, 1, 1, 0.600000024};
            colorActive[] = {1, 1, 1, 1};
            colorDisabled[] = {1, 1, 1, 0.300000012};
            thumb = "\\ca\\ui\\data\\igui_scrollbar_thumb_ca.paa";
            arrowFull = "\\ca\\ui\\data\\igui_arrow_top_active_ca.paa";
            arrowEmpty = "\\ca\\ui\\data\\igui_arrow_top_ca.paa";
            border = "\\ca\\ui\\data\\igui_border_scroll_ca.paa";
        };
    };
    movingEnable = 0;
    name = "ZadanieOrigins";
    idd = 10055;
    enableSimulation = 1;
    controlsBackground[] = {"bg"};
    objects[] = {};
    class controls
    {
        class listZadaniy: RscListBoxZ
        {
            idc = 10056;
            x = "0.165 * safezoneW + safezoneX";
            y = "0.28 * safezoneH + safezoneY";
            w = "0.20 * safezoneW";
            h = "0.181 * safezoneH";
        };
        class TextZadaniy: RscTextZ2
        {
            idc = 10057;
            x = "0.364 * safezoneW + safezoneX";
            y = "0.28 * safezoneH + safezoneY";
            w = "0.365 * safezoneW";
            h = "0.419 * safezoneH";
            text = "tut text";
        };
        class ZakrZadan: Ori_B_Zadanie
        {
            idc = -1;
            x = "0.64 * safezoneW + safezoneX";
            y = "0.16 * safezoneH + safezoneY";
            w = "0.10 * safezoneW";
            h = "0.03 * safezoneH";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            text = "";
            action = "closeDialog 0;";
        };
        class zagolvok_zadanie: RscTextZ
        {
            idc = -1;
            x = "0.184 * safezoneW + safezoneX";
            y = "0.24 * safezoneH + safezoneY";
            w = "0.17 * safezoneW";
            h = "0.04 * safezoneH";
            text = "Curent Missions:";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            colorText[] = {0.75, 0.75, 0.75, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class zagolvok_descr: RscTextZ
        {
            idc = -1;
            x = "0.45 * safezoneW + safezoneX";
            y = "0.24 * safezoneH + safezoneY";
            w = "0.17 * safezoneW";
            h = "0.04 * safezoneH";
            text = "Description:";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            colorText[] = {0.75, 0.75, 0.75, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
    };
    class bg: RscPictureZ
    {
        idc = -1;
        x = "0.15 * safezoneW + safezoneX";
        y = "0.15 * safezoneH + safezoneY";
        w = "0.6 * safezoneW";
        h = "0.57 * safezoneH";
        text = "\\origins_pack\\ui\\pager_ca.paa";
        colorBackground[] = {0, 0.128000006, 0, 1};
    };
};
class OriginsExchange5
{
    class RscPictureZ
    {
        type = 0;
        style = 48;
        colorText[] = {0.75, 0.75, 0.75, 1};
        colorBackground[] = {0, 0, 0, 0};
        font = "Bitstream";
        sizeEx = 0.0250000004;
        soundClick[] = {"", 0.200000003, 1};
        soundEnter[] = {"", 0.200000003, 1};
        soundEscape[] = {"", 0.200000003, 1};
        soundPush[] = {"", 0.200000003, 1};
        w = 0.275000006;
        h = 0.0399999991;
        text = "";
    };
    class Ori_B_Zadanie
    {
        type = 16;
        style = 0;
        default = 0;
        x = 0.100000001;
        y = 0.100000001;
        w = 0.183825001;
        h = 0.104575001;
        color[] = {0.542999983, 0.574199975, 0.4102, 1};
        color2[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorBackground[] = {1, 1, 1, 1};
        colorbackground2[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.25};
        periodFocus = 1.20000005;
        periodOver = 0.800000012;
        class HitZone
        {
            left = 0.00400000019;
            top = 0.00899999961;
            right = 0.00400000019;
            bottom = 0.00899999961;
        };
        class ShortcutPos
        {
            left = 0.0144999996;
            top = 0.0260000005;
            w = 0.0392156988;
            h = 0.0522876009;
        };
        class TextPos
        {
            left = 0.00499999989;
            top = 0.00999999978;
            right = 0.00499999989;
            bottom = 0.00499999989;
        };
        textureNoShortcut = "";
        animTextureNormal = "\\origins_pack\\ui\\power_normal_ca.paa";
        animTextureDisabled = "\\origins_pack\\ui\\power_normal_ca.paa";
        animTextureOver = "\\origins_pack\\ui\\power_hover_ca.paa";
        animTextureFocused = "\\origins_pack\\ui\\power_hover_ca.paa";
        animTexturePressed = "\\origins_pack\\ui\\power_down_ca.paa";
        animTextureDefault = "\\origins_pack\\ui\\power_normal_ca.paa";
        period = 0.400000006;
        font = "Zeppelin32";
        size = 0.0500000007;
        sizeEx = 0.0500000007;
        text = "";
        soundEnter[] = {"", 0.0900000036, 1};
        soundPush[] = {"", 0.0900000036, 1};
        soundClick[] = {"", 0.0700000003, 1};
        soundEscape[] = {"", 0.0900000036, 1};
        action = "";
        toolTip = "";
        class Attributes
        {
            font = "Zeppelin32";
            color = "#E5E5E5";
            align = "center";
            shadow = 1;
        };
        class AttributesImage
        {
            font = "Zeppelin32";
            color = "#E5E5E5";
            align = "center";
            shadow = 1;
        };
    };
    class Ori_Button
    {
        type = 16;
        idc = -1;
        style = 0;
        default = 0;
        x = 0.100000001;
        y = 0.100000001;
        w = 0.183825001;
        h = 0.104575001;
        color[] = {0.542999983, 0.574199975, 0.4102, 1};
        color2[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorBackground[] = {1, 1, 1, 1};
        colorbackground2[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.25};
        periodFocus = 1.20000005;
        periodOver = 0.800000012;
        class HitZone
        {
            left = 0.0149999997;
            top = 0.00100000005;
            right = 0.0450000018;
            bottom = 0.00100000005;
        };
        class ShortcutPos
        {
            left = 0.0144999996;
            top = 0.0260000005;
            w = 0.0392156988;
            h = 0.0522876009;
        };
        class TextPos
        {
            left = 0.00499999989;
            top = 0.00999999978;
            right = 0.00499999989;
            bottom = 0.00499999989;
        };
        textureNoShortcut = "";
        animTextureNormal = "";
        animTextureDisabled = "";
        animTextureOver = "";
        animTextureFocused = "";
        animTexturePressed = "";
        animTextureDefault = "";
        period = 0.400000006;
        font = "Zeppelin32";
        size = 0.0399999991;
        sizeEx = 0.0399999991;
        text = "";
        soundEnter[] = {"", 0.0900000036, 1};
        soundPush[] = {"", 0.0900000036, 1};
        soundClick[] = {"", 0.0700000003, 1};
        soundEscape[] = {"", 0.0900000036, 1};
        action = "";
        toolTip = "";
        class Attributes
        {
            font = "Zeppelin32";
            color = "#E5E5E5";
            align = "center";
            shadow = 1;
        };
        class AttributesImage
        {
            font = "Zeppelin32";
            color = "#E5E5E5";
            align = "left";
            shadow = 1;
        };
    };
    class RscListBoxZ
    {
        type = 5;
        canDrag = 0;
        style = "0 + 0x10";
        font = "Zeppelin32";
        sizeEx = 0.0322099999;
        rowHeight = 0.0299999993;
        colorBackground[] = {0.800000012, 0.800000012, 1, 0.300000012};
        color[] = {1, 1, 1, 1};
        colorText[] = {1, 1, 1, 0.649999976};
        colorScrollbar[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorSelect[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorSelect2[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorSelectBackground[] = {0.600000024, 0.83920002, 0.470600009, 0.300000012};
        colorSelectBackground2[] = {0.600000024, 0.83920002, 0.470600009, 0.300000012};
        columns[] = {0.0199999996, 0.779999971, 0.100000001};
        period = 0;
        maxHistoryDelay = 1;
        autoScrollSpeed = -1;
        autoScrollDelay = 5;
        autoScrollRewind = 0;
        soundSelect[] = {"\\ca\\ui\\data\\sound\\new1", 0.0900000036, 1};
        class ScrollBar
        {
            color[] = {1, 1, 1, 0.600000024};
            colorActive[] = {1, 1, 1, 1};
            colorDisabled[] = {1, 1, 1, 0.300000012};
            thumb = "\\ca\\ui\\data\\igui_scrollbar_thumb_ca.paa";
            arrowFull = "\\ca\\ui\\data\\igui_arrow_top_active_ca.paa";
            arrowEmpty = "\\ca\\ui\\data\\igui_arrow_top_ca.paa";
            border = "\\ca\\ui\\data\\igui_border_scroll_ca.paa";
        };
    };
    class RscTextZ
    {
        type = 0;
        style = 2;
        colorText[] = {0, 1, 0.5, 1};
        colorBackground[] = {1, 0, 0, 0.5};
        font = "TahomaB";
        sizeEx = 0.0500000007;
        x = 0;
        y = 0;
        w = 0.100000001;
        h = 0.200000003;
    };
    class RscTextZ2
    {
        type = 0;
        idc = -1;
        access = 0;
        lineSpacing = 1;
        style = "16+0x200";
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 1, 1, 0.75};
        font = "Zeppelin32";
        size = 0.0289999992;
        sizeEx = 0.0280000009;
        text = "";
        class ScrollBar
        {
            color[] = {1, 1, 1, 0.600000024};
            colorActive[] = {1, 1, 1, 1};
            colorDisabled[] = {1, 1, 1, 0.300000012};
            thumb = "\\ca\\ui\\data\\igui_scrollbar_thumb_ca.paa";
            arrowFull = "\\ca\\ui\\data\\igui_arrow_top_active_ca.paa";
            arrowEmpty = "\\ca\\ui\\data\\igui_arrow_top_ca.paa";
            border = "\\ca\\ui\\data\\igui_border_scroll_ca.paa";
        };
    };
    movingEnable = 1;
    name = "OriginsExchange5";
    idd = 72055;
    enableSimulation = 1;
    controlsBackground[] = {"bg", "TraderIcon", "value1bg", "value2bg", "value1", "value2"};
    enableDisplay = 1;
    class controls
    {
        class listItems: RscListBoxZ
        {
            idc = 72056;
            x = "0.287 * safezoneW + safezoneX";
            y = "0.12 * safezoneH + safezoneY";
            w = "0.155 * safezoneW";
            h = "0.34 * safezoneH";
        };
        class listItems2: RscListBoxZ
        {
            idc = 72058;
            x = "0.564 * safezoneW + safezoneX";
            y = "0.125 * safezoneH + safezoneY";
            w = "0.155 * safezoneW";
            h = "0.34 * safezoneH";
        };
        class listItems3: RscListBoxZ
        {
            idc = 72057;
            x = "0.286 * safezoneW + safezoneX";
            y = "0.545 * safezoneH + safezoneY";
            w = "0.155 * safezoneW";
            h = "0.34 * safezoneH";
        };
        class listItems4: RscListBoxZ
        {
            idc = 72059;
            x = "0.564 * safezoneW + safezoneX";
            y = "0.545 * safezoneH + safezoneY";
            w = "0.155 * safezoneW";
            h = "0.34 * safezoneH";
        };
        class zagolvok1: RscTextZ
        {
            idc = -1;
            x = "0.275 * safezoneW + safezoneX";
            y = "0.07 * safezoneH + safezoneY";
            w = "0.17 * safezoneW";
            h = "0.04 * safezoneH";
            text = "Your items:";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            colorText[] = {0.75, 0.75, 0.75, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class zagolvok2: RscTextZ
        {
            idc = -1;
            x = "0.56 * safezoneW + safezoneX";
            y = "0.075 * safezoneH + safezoneY";
            w = "0.17 * safezoneW";
            h = "0.04 * safezoneH";
            text = "Trader's items:";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            colorText[] = {0.75, 0.75, 0.75, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class zagolvok3: RscTextZ
        {
            idc = -1;
            x = "0.28 * safezoneW + safezoneX";
            y = "0.9 * safezoneH + safezoneY";
            w = "0.17 * safezoneW";
            h = "0.04 * safezoneH";
            text = "You change:";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            colorText[] = {0.75, 0.75, 0.75, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class zagolvok4: RscTextZ
        {
            idc = -1;
            x = "0.56 * safezoneW + safezoneX";
            y = "0.9 * safezoneH + safezoneY";
            w = "0.17 * safezoneW";
            h = "0.04 * safezoneH";
            text = "Trader changes:";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            colorText[] = {0.75, 0.75, 0.75, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class zagolvok5: RscTextZ
        {
            idc = 72061;
            x = "0.410 * safezoneW + safezoneX";
            y = "0.01 * safezoneH + safezoneY";
            w = "0.20 * safezoneW";
            h = "0.06 * safezoneH";
            text = "";
            size = 0.0599999987;
            sizeEx = 0.0700000003;
            colorText[] = {0, 0, 0, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class zagolvok7: RscTextZ
        {
            idc = -1;
            x = "0.405 * safezoneW + safezoneX";
            y = "0.33 * safezoneH + safezoneY";
            w = "0.20 * safezoneW";
            h = "0.06 * safezoneH";
            text = "";
            size = 0.0599999987;
            sizeEx = 0.0399999991;
            colorText[] = {0.75, 0.75, 0.75, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class zagolvok8: RscTextZ
        {
            idc = -1;
            x = "0.405 * safezoneW + safezoneX";
            y = "0.37 * safezoneH + safezoneY";
            w = "0.20 * safezoneW";
            h = "0.06 * safezoneH";
            text = "";
            size = 0.0599999987;
            sizeEx = 0.0399999991;
            colorText[] = {0.75, 0.75, 0.75, 0.800000012};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
        class but_ok: Ori_Button
        {
            access = 1;
            idc = 72060;
            x = "0.453 * safezoneW + safezoneX";
            y = "0.7 * safezoneH + safezoneY";
            w = "0.10 * safezoneW";
            h = "0.045 * safezoneH";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            animTextureNormal = "\\origins_pack\\ui\\knopka_normal2.paa";
            animTextureDisabled = "\\origins_pack\\ui\\knopka_normal2.paa";
            animTextureOver = "\\origins_pack\\ui\\knopka_hover2.paa";
            animTextureFocused = "\\origins_pack\\ui\\knopka_hover2.paa";
            animTexturePressed = "\\origins_pack\\ui\\knopka_press2.paa";
            animTextureDefault = "\\origins_pack\\ui\\knopka_normal2.paa";
            text = "CHANGE";
            action = "CODEINPUT = []; closeDialog 0;";
        };
    };
    class TraderIcon: RscPictureZ
    {
        idc = 72064;
        x = "0.46 * safezoneW + safezoneX";
        y = "0.11 * safezoneH + safezoneY";
        w = "0.09 * safezoneW";
        h = "0.25 * safezoneH";
        text = "";
        colorBackground[] = {0, 0.128000006, 0, 1};
    };
    class bg: RscPictureZ
    {
        idc = -1;
        x = "0.255 * safezoneW + safezoneX";
        y = "0.01 * safezoneH + safezoneY";
        w = "0.50 * safezoneW";
        h = "0.96 * safezoneH";
        text = "\\origins_pack\\ui\\apooriginstraders.paa";
        colorBackground[] = {0, 0.128000006, 0, 1};
    };
    class value1bg: RscPictureZ
    {
        idc = -1;
        x = "0.284 * safezoneW + safezoneX";
        y = "0.49 * safezoneH + safezoneY";
        w = "0.272 * safezoneW";
        h = "0.025 * safezoneH";
        text = "\\origins_pack\\ui\\ui_messagebox_middle_ca.paa";
        colorBackground[] = {0, 0.128000006, 0, 1};
    };
    class value2bg: RscPictureZ
    {
        idc = -1;
        x = "0.561 * safezoneW + safezoneX";
        y = "0.491 * safezoneH + safezoneY";
        w = "0.275 * safezoneW";
        h = "0.025 * safezoneH";
        text = "\\origins_pack\\ui\\ui_messagebox_middle_ca.paa";
        colorBackground[] = {0, 0.128000006, 0, 1};
    };
    class value1: RscPictureZ
    {
        idc = 72062;
        x = "0.286 * safezoneW + safezoneX";
        y = "0.49 * safezoneH + safezoneY";
        w = "0 * safezoneW";
        h = "0.022 * safezoneH";
        text = "#(argb,8,8,3)color(1,1,1,0.4)";
    };
    class value2: RscPictureZ
    {
        idc = 72063;
        x = "0.563 * safezoneW + safezoneX";
        y = "0.491 * safezoneH + safezoneY";
        w = "0 * safezoneW";
        h = "0.022 * safezoneH";
        text = "#(argb,8,8,3)color(1,1,1,0.4)";
    };
};
class RscButtonActionMenu: RscButton
{
    SizeEx = 0.0267399997;
    colorBackground[] = {0.439999998, 0.699999988, 0.439999998, 1};
    colorBackgroundActive[] = {0.239999995, 0.5, 0.239999995, 1};
    colorBackgroundDisabled[] = {1, 1, 1, 0};
    colorFocused[] = {0.200000003, 0.5, 0.200000003, 1};
    colorShadow[] = {1, 1, 1, 0};
    borderSize = 0;
    w = "0.115 * safezoneW";
    h = "0.025 * safezoneH";
};
class RscDisplayGenderSelect
{
    class RscPictureK
    {
        type = 0;
        idc = -1;
        style = 48;
        colorText[] = {0.75, 0.75, 0.75, 1};
        colorBackground[] = {0, 0, 0, 0};
        font = "Bitstream";
        sizeEx = 0.0250000004;
        soundClick[] = {"", 0.200000003, 1};
        soundEnter[] = {"", 0.200000003, 1};
        soundEscape[] = {"", 0.200000003, 1};
        soundPush[] = {"", 0.200000003, 1};
        w = 0.275000006;
        h = 0.0399999991;
        text = "";
    };
    class Ori_Button
    {
        type = 16;
        idc = -1;
        style = 0;
        default = 0;
        x = 0.100000001;
        y = 0.100000001;
        w = 0.183825001;
        h = 0.104575001;
        color[] = {0.542999983, 0.574199975, 0.4102, 1};
        color2[] = {0.949999988, 0.949999988, 0.949999988, 1};
        colorBackground[] = {1, 1, 1, 1};
        colorbackground2[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.25};
        periodFocus = 1.20000005;
        periodOver = 0.800000012;
        class HitZone
        {
            left = 0.0149999997;
            top = 0.00100000005;
            right = 0.0450000018;
            bottom = 0.00100000005;
        };
        class ShortcutPos
        {
            left = 0.0144999996;
            top = 0.0260000005;
            w = 0.0392156988;
            h = 0.0522876009;
        };
        class TextPos
        {
            left = 0.00499999989;
            top = 0.00999999978;
            right = 0.00499999989;
            bottom = 0.00499999989;
        };
        textureNoShortcut = "";
        animTextureNormal = "";
        animTextureDisabled = "";
        animTextureOver = "";
        animTextureFocused = "";
        animTexturePressed = "";
        animTextureDefault = "";
        period = 0.400000006;
        font = "Zeppelin32";
        size = 0.0500000007;
        sizeEx = 0.0500000007;
        text = "";
        soundEnter[] = {"", 0.0900000036, 1};
        soundPush[] = {"", 0.0900000036, 1};
        soundClick[] = {"", 0.0700000003, 1};
        soundEscape[] = {"", 0.0900000036, 1};
        action = "";
        toolTip = "";
        class Attributes
        {
            font = "Zeppelin32";
            color = "#E5E5E5";
            align = "center";
            shadow = 1;
        };
        class AttributesImage
        {
            font = "Zeppelin32";
            color = "#E5E5E5";
            align = "left";
            shadow = 1;
        };
    };
    class RscTextK
    {
        type = 0;
        idc = -1;
        style = 2;
        colorText[] = {0, 1, 0.5, 1};
        font = "TahomaB";
        sizeEx = 0.0799999982;
        x = 0;
        y = 0;
        w = 0.100000001;
        h = 0.200000003;
    };
    class RscTextK2
    {
        type = 0;
        idc = -1;
        access = 0;
        lineSpacing = 1;
        style = 16;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 1, 1, 0.75};
        font = "Zeppelin32";
        size = 0.0289999992;
        sizeEx = 0.0280000009;
        text = "";
    };
    idd = 6902;
    enableDisplay = 1;
    controlsBackground[] = {"bg"};
    class controls
    {
        class but_left: Ori_Button
        {
            access = 0;
            x = "0.247 * safezoneW + safezoneX";
            y = "0.8 * safezoneH + safezoneY";
            w = "0.09 * safezoneW";
            h = "0.09 * safezoneH";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            textureNoShortcut = "";
            animTextureNormal = "\\origins_pack\\ui\\left_normal.paa";
            animTextureDisabled = "\\origins_pack\\ui\\left_normal.paa";
            animTextureOver = "\\origins_pack\\ui\\left_normal.paa";
            animTextureFocused = "\\origins_pack\\ui\\left_normal.paa";
            animTexturePressed = "\\origins_pack\\ui\\left_press.paa";
            animTextureDefault = "\\origins_pack\\ui\\left_normal.paa";
            text = "";
            action = "if(counter==0) then { counter=maxcounter; } else { counter=counter-1;}; _text_t = localize (workingar_d select counter); ctrlSetText [5151, ((workingar select counter) select 0)]; ctrlSetText [5152, _text_t]; dayz_selectGender = ((workingar select counter) select 1);";
        };
        class but_right: Ori_Button
        {
            access = 0;
            x = "0.388 * safezoneW + safezoneX";
            y = "0.8 * safezoneH + safezoneY";
            w = "0.09 * safezoneW";
            h = "0.09 * safezoneH";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            animTextureNormal = "\\origins_pack\\ui\\right_normal.paa";
            animTextureDisabled = "\\origins_pack\\ui\\right_normal.paa";
            animTextureOver = "\\origins_pack\\ui\\right_normal.paa";
            animTextureFocused = "\\origins_pack\\ui\\right_normal.paa";
            animTexturePressed = "\\origins_pack\\ui\\right_press.paa";
            animTextureDefault = "\\origins_pack\\ui\\right_normal.paa";
            text = "";
            action = "if(counter==maxcounter) then { counter=0; } else { counter=counter+1;}; _text_t = localize (workingar_d select counter); ctrlSetText [5151, ((workingar select counter) select 0)]; ctrlSetText [5152, _text_t]; dayz_selectGender = ((workingar select counter) select 1);";
        };
        class but_sman: Ori_Button
        {
            access = 0;
            x = "0.478 * safezoneW + safezoneX";
            y = "0.152 * safezoneH + safezoneY";
            w = "0.09 * safezoneW";
            h = "0.09 * safezoneH";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            animTextureNormal = "\\origins_pack\\ui\\man_normal.paa";
            animTextureDisabled = "\\origins_pack\\ui\\man_normal.paa";
            animTextureOver = "\\origins_pack\\ui\\man_hover.paa";
            animTextureFocused = "\\origins_pack\\ui\\man_normal.paa";
            animTexturePressed = "\\origins_pack\\ui\\man_press.paa";
            animTextureDefault = "\\origins_pack\\ui\\man_normal.paa";
            text = "";
            action = "workingar = orig_mans; workingar_d = mans_desc; maxcounter = 11; counter=0; ctrlSetText [5151, ((workingar select counter) select 0)]; _text_t = localize (workingar_d select counter); ctrlSetText [5152, _text_t]; dayz_selectGender = ((workingar select counter) select 1);";
        };
        class but_swoman: Ori_Button
        {
            access = 0;
            x = "0.571 * safezoneW + safezoneX";
            y = "0.152 * safezoneH + safezoneY";
            w = "0.09 * safezoneW";
            h = "0.09 * safezoneH";
            size = 0.0450000018;
            sizeEx = 0.0450000018;
            animTextureNormal = "\\origins_pack\\ui\\baba_normal.paa";
            animTextureDisabled = "\\origins_pack\\ui\\baba_normal.paa";
            animTextureOver = "\\origins_pack\\ui\\baba_hover.paa";
            animTextureFocused = "\\origins_pack\\ui\\baba_normal.paa";
            animTexturePressed = "\\origins_pack\\ui\\baba_press.paa";
            animTextureDefault = "\\origins_pack\\ui\\baba_normal.paa";
            text = "";
            action = "workingar = orig_womans; workingar_d = womans_desc; maxcounter = 6; counter=0; ctrlSetText [5151, ((workingar select counter) select 0)]; _text_t = localize (workingar_d select counter); ctrlSetText [5152, _text_t]; dayz_selectGender = ((workingar select counter) select 1);";
        };
        class but_ok: Ori_Button
        {
            access = 0;
            x = "0.479 * safezoneW + safezoneX";
            y = "0.687 * safezoneH + safezoneY";
            w = "0.25 * safezoneW";
            h = "0.055 * safezoneH";
            size = 0.0549999997;
            sizeEx = 0.0450000018;
            animTextureNormal = "\\origins_pack\\ui\\knopka_normal2.paa";
            animTextureDisabled = "\\origins_pack\\ui\\knopka_normal2.paa";
            animTextureOver = "\\origins_pack\\ui\\knopka_hover2.paa";
            animTextureFocused = "\\origins_pack\\ui\\knopka_hover2.paa";
            animTexturePressed = "\\origins_pack\\ui\\knopka_press2.paa";
            animTextureDefault = "\\origins_pack\\ui\\knopka_normal2.paa";
            text = "Let's go...";
            action = "closeDialog 0;";
        };
        class text: RscTextK2
        {
            idc = 5152;
            x = "0.481 * safezoneW + safezoneX";
            y = "0.241 * safezoneH + safezoneY";
            w = "0.29 * safezoneW";
            h = "0.42 * safezoneH";
            text = "";
        };
        class skinp: RscPictureK
        {
            idc = 5151;
            x = "0.2515 * safezoneW + safezoneX";
            y = "0.1722 * safezoneH + safezoneY";
            w = "0.1908 * safezoneW";
            h = "0.6135 * safezoneH";
            text = "";
            colorBackground[] = {0, 0.128000006, 0, 1};
        };
        class skloS: RscPictureK
        {
            x = "0.2515 * safezoneW + safezoneX";
            y = "0.1722 * safezoneH + safezoneY";
            w = "0.1908 * safezoneW";
            h = "0.6135 * safezoneH";
            text = "\\origins_pack\\ui\\sloj_steklo.paa";
        };
        class zagolvok: RscTextK
        {
            x = "0.385 * safezoneW + safezoneX";
            y = "0.077 * safezoneH + safezoneY";
            w = "0.27 * safezoneW";
            h = "0.04 * safezoneH";
            size = 0.0649999976;
            sizeEx = "0.065 * (safezoneW + safezoneX)";
            text = "Choose survivor";
            colorText[] = {0, 0, 0, 0.899999976};
            colorBackground[] = {0, 0.128000006, 0, 0};
        };
    };
    class bg: RscPictureK
    {
        x = "0.21 * safezoneW + safezoneX";
        y = "0.07 * safezoneH + safezoneY";
        w = "0.6 * safezoneW";
        h = "0.84 * safezoneH";
        text = "\\origins_pack\\ui\\fon2.paa";
        colorBackground[] = {0, 0.128000006, 0, 1};
    };
};
class RscDisplaySpawnlocationSelect
{
    idd = 6903;
    enableDisplay = 1;
    class controls
    {
        class RscSelectedRegion1: RscActiveText
        {
            idc = -1;
            style = 48;
            text = "\\origins_pack\\ui\\ui_kameni_co.paa";
            x = "0.19 * safezoneW + safezoneX";
            y = "0.05 * safezoneH + safezoneY";
            w = "0.190 * safezoneW";
            h = "0.390 * safezoneH";
            color[] = {0.5, 0.5, 0.5, 1};
            colorActive[] = {1, 1, 1, 1};
            action = "closeDialog 0;dayz_selectRegion = 0;";
        };
        class RscSelectedRegion2: RscActiveText
        {
            idc = -1;
            style = 48;
            text = "\\origins_pack\\ui\\ui_mitrovice_co.paa";
            x = "0.40 * safezoneW + safezoneX";
            y = "0.05 * safezoneH + safezoneY";
            w = "0.190 * safezoneW";
            h = "0.390 * safezoneH";
            color[] = {0.5, 0.5, 0.5, 1};
            colorActive[] = {1, 1, 1, 1};
            action = "closeDialog 0;dayz_selectRegion = 1;";
        };
        class RscSelectedRegionR: RscActiveText
        {
            idc = -1;
            style = 48;
            text = "\\origins_pack\\ui\\ui_random_co.paa";
            x = "0.61 * safezoneW + safezoneX";
            y = "0.05 * safezoneH + safezoneY";
            w = "0.190 * safezoneW";
            h = "0.390 * safezoneH";
            color[] = {0.5, 0.5, 0.5, 1};
            colorActive[] = {1, 1, 1, 1};
            action = "closeDialog 0;dayz_selectRegion = 2;";
        };
        class RscSelectedRegion4: RscActiveText
        {
            idc = -1;
            style = 48;
            text = "\\origins_pack\\ui\\ui_seven_co.paa";
            x = "0.19 * safezoneW + safezoneX";
            y = "0.46 * safezoneH + safezoneY";
            w = "0.190 * safezoneW";
            h = "0.390 * safezoneH";
            color[] = {0.5, 0.5, 0.5, 1};
            colorActive[] = {1, 1, 1, 1};
            action = "closeDialog 0;dayz_selectRegion = 3;";
        };
        class RscSelectedRegion5: RscActiveText
        {
            idc = -1;
            style = 48;
            text = "\\origins_pack\\ui\\ui_byelov_co.paa";
            x = "0.40 * safezoneW + safezoneX";
            y = "0.46 * safezoneH + safezoneY";
            w = "0.190 * safezoneW";
            h = "0.390 * safezoneH";
            color[] = {0.5, 0.5, 0.5, 1};
            colorActive[] = {1, 1, 1, 1};
            action = "closeDialog 0;dayz_selectRegion = 4;";
        };
        class RscSelectedRegion6: RscActiveText
        {
            idc = -1;
            style = 48;
            text = "\\origins_pack\\ui\\ui_etanovsk_co.paa";
            x = "0.61 * safezoneW + safezoneX";
            y = "0.46 * safezoneH + safezoneY";
            w = "0.190 * safezoneW";
            h = "0.390 * safezoneH";
            color[] = {0.5, 0.5, 0.5, 1};
            colorActive[] = {1, 1, 1, 1};
            action = "closeDialog 0;dayz_selectRegion = 5;";
        };
    };
};
class DZ_ItemInteraction
{
    idd = 6901;
    movingEnable = 0;
    class controlsBackground
    {
    };
    class objects
    {
    };
    class controls
    {
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
        class ControlsBackground
        {
            class RscPicture_1201: RscPictureGUI
            {
                idc = 1400;
                text = "\\z\\addons\\dayz_code\\gui\\stats_kills_human_ca.paa";
                x = "0.044687 * safezoneW + safezoneX";
                y = "0.934779 * safezoneH + safezoneY";
                w = 0.0599999987;
                h = 0.0799999982;
            };
            class RscPicture_1200: RscPictureGUI
            {
                idc = 1401;
                text = "\\z\\addons\\dayz_code\\gui\\stats_kills_zombie_ca.paa";
                x = "0.044687 * safezoneW + safezoneX";
                y = "0.876025 * safezoneH + safezoneY";
                w = 0.0599999987;
                h = 0.0799999982;
            };
        };
        class Controls
        {
            class RscText1: RscStructuredTextGUI
            {
                idc = 1410;
                text = "0";
                x = "(0.044687 * safezoneW + safezoneX) - 0.01";
                y = "0.934779 * safezoneH + safezoneY";
                w = 0.0799999982;
                h = 0.0799999982;
            };
            class RscText2: RscStructuredTextGUI
            {
                idc = 1411;
                text = "0";
                x = "(0.044687 * safezoneW + safezoneX) - 0.01";
                y = "0.876025 * safezoneH + safezoneY";
                w = 0.0799999982;
                h = 0.0799999982;
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
        class ControlsBackground
        {
            class RscText_1402: RscPicture
            {
                idc = 1402;
                text = "#(argb,8,8,3)color(1,1,1,1)";
                x = "0.48 * safezoneW + safezoneX";
                y = "0.42 * safezoneH + safezoneY";
                w = "0.052 * safezoneW";
                h = "0.133 * safezoneH";
                colorText[] = {1, 1, 1, 1};
            };
            class RscText_1400: RscPicture
            {
                idc = 1400;
                text = "#(argb,8,8,3)color(1,1,1,1)";
                x = "0.48 * safezoneW + safezoneX";
                y = "0.42 * safezoneH + safezoneY";
                w = "0.052 * safezoneW";
                h = 0;
                colorText[] = {0, 0, 0, 1};
            };
        };
        class Controls
        {
            class RscPicture_1401: RscPictureGUI
            {
                idc = 1401;
                text = "\\z\\addons\\dayz_code\\gui\\status_waiting_ca.paa";
                x = "0.434999 * safezoneW + safezoneX";
                y = "0.392207 * safezoneH + safezoneY";
                w = "0.141 * safezoneW";
                h = "0.188013 * safezoneH";
                colorText[] = {0.379999995, 0.629999995, 0.25999999, 1};
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
        class ControlsBackground
        {
            class RscPicture_1200: RscPictureGUI
            {
                idc = 1200;
                text = "\\z\\addons\\dayz_code\\gui\\status_blood_border_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.859 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.400000006};
            };
            class RscPicture_1201: RscPictureGUI
            {
                idc = 1201;
                text = "\\z\\addons\\dayz_code\\gui\\status_food_border_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.929 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.400000006};
            };
            class RscPicture_1202: RscPictureGUI
            {
                idc = 1202;
                text = "\\z\\addons\\dayz_code\\gui\\status_thirst_border_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.789 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.400000006};
            };
            class RscPicture_1203: RscPictureGUI
            {
                idc = 1203;
                text = "\\z\\addons\\dayz_code\\gui\\status_fracture_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.509 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.699999988};
            };
            class RscPicture_1204: RscPictureGUI
            {
                idc = 1204;
                text = "\\z\\addons\\dayz_code\\gui\\status_connection_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.439 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.400000006};
            };
            class RscPicture_1205: RscPictureGUI
            {
                idc = 1205;
                text = "\\origins_pack\\ui\\gui\\ico_quest_yellow.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.369 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.400000006};
            };
            class RscPicture_1206: RscPictureGUI
            {
                idc = 1206;
                text = "\\origins_pack\\ui\\gui\\st_humanity_survivor.paa";
                x = "0.959313 * safezoneW + safezoneX";
                y = "0.16 * safezoneH + safezoneY";
                w = "0.037 * safezoneW";
                h = "0.047 * safezoneH";
                colorText[] = {1, 1, 1, 0.699999988};
            };
            class RscPicture_1207: RscPictureGUI
            {
                idc = 1207;
                text = "\\z\\addons\\dayz_code\\gui\\status_combat_border_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.649 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.400000006};
            };
            class RscPicture_1208: RscPictureGUI
            {
                idc = 1208;
                text = "\\z\\addons\\dayz_code\\gui\\status_temp_outside_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.719 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.400000006};
            };
            class RscPicture_1209: RscPictureGUI
            {
                idc = 1209;
                text = "\\origins_pack\\ui\\gui\\st_humanity_hero.paa";
                x = "0.959313 * safezoneW + safezoneX";
                y = "0.202 * safezoneH + safezoneY";
                w = "0.037 * safezoneW";
                h = "0.047 * safezoneH";
                colorText[] = {1, 1, 1, 0.75};
            };
            class RscPicture_1210: RscPictureGUI
            {
                idc = 1210;
                text = "\\origins_pack\\ui\\gui\\st_humanity_bandit.paa";
                x = "0.959313 * safezoneW + safezoneX";
                y = "0.246 * safezoneH + safezoneY";
                w = "0.037 * safezoneW";
                h = "0.047 * safezoneH";
                colorText[] = {1, 1, 1, 0.75};
            };
            class RscPicture_1211: RscPictureGUI
            {
                idc = 1211;
                text = "\\origins_pack\\ui\\gui\\zombie.paa";
                x = "0.959313 * safezoneW + safezoneX";
                y = "0.288 * safezoneH + safezoneY";
                w = "0.037 * safezoneW";
                h = "0.047 * safezoneH";
                colorText[] = {1, 1, 1, 0.75};
            };
            class RscPicture_1501: RscPictureGUI
            {
                idc = 1501;
                x = "0.945313 * safezoneW + safezoneX";
                y = "0.95 * safezoneH + safezoneY";
                w = 0.0399999991;
                h = 0.0533329993;
            };
            class RscPicture_1502: RscPictureGUI
            {
                idc = 1502;
                x = "0.945313 * safezoneW + safezoneX";
                y = "0.816666 * safezoneH + safezoneY";
                w = 0.0399999991;
                h = 0.0533329993;
            };
            class RscPicture_1212: RscPictureGUI
            {
                idc = 1212;
                text = "\\origins_pack\\ui\\gui\\apo_weight_icon_border_ca.paa";
                x = "0.96 * safezoneW + safezoneX";
                y = "0.581 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.400000006};
            };
            class RscPicture_1213: RscPictureGUI
            {
                idc = 1213;
                text = "\\origins_pack\\ui\\gui\\apo_weight_indicator_border_ca.paa";
                x = "0.944235 * safezoneW + safezoneX";
                y = "0.581 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.400000006};
            };
        };
        class Controls
        {
            class RscPicture_1300: RscPictureGUI
            {
                idc = 1300;
                text = "\\z\\addons\\dayz_code\\gui\\status_blood_inside_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.859 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
            };
            class RscPicture_1301: RscPictureGUI
            {
                idc = 1301;
                text = "\\z\\addons\\dayz_code\\gui\\status_food_inside_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.929 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
            };
            class RscPicture_1302: RscPictureGUI
            {
                idc = 1302;
                text = "\\z\\addons\\dayz_code\\gui\\status_thirst_inside_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.789 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
            };
            class RscPicture_1303: RscPictureGUI
            {
                idc = 1303;
                text = "\\z\\addons\\dayz_code\\gui\\status_bleeding_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.859 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 0.5};
            };
            class RscPicture_1304: RscPictureGUI
            {
                idc = 1304;
                text = "";
                x = "0.935313 * safezoneW + safezoneX";
                y = "0.3 * safezoneH + safezoneY";
                w = 0.0599999987;
                h = 0.0799999982;
            };
            class RscPicture_1305: RscPictureGUI
            {
                idc = 1305;
                text = "";
                x = "0.935313 * safezoneW + safezoneX";
                y = "0.37 * safezoneH + safezoneY";
                w = 0.0599999987;
                h = 0.0799999982;
            };
            class RscPicture_1306: RscPictureGUI
            {
                idc = 1306;
                text = "\\z\\addons\\dayz_code\\gui\\status_temp_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.719 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
            };
            class RscPicture_1307: RscPictureGUI
            {
                idc = 1307;
                text = "\\z\\addons\\dayz_code\\gui\\status_combat_inside_ca.paa";
                x = "0.954235 * safezoneW + safezoneX";
                y = "0.649 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
            };
            class RscPicture_1308: RscPictureGUI
            {
                idc = 1308;
                text = "\\origins_pack\\ui\\gui\\status_humanity_inside_survivor.paa";
                x = "0.929 * safezoneW + safezoneX";
                y = "0.06 * safezoneH + safezoneY";
                w = "0.068 * safezoneW";
                h = "0.088 * safezoneH";
                colorText[] = {1, 1, 1, 1};
            };
            class RscText_1309: RscTextGUIK
            {
                idc = 1309;
                text = "0";
                x = "0.937 * safezoneW + safezoneX";
                y = "0.16 * safezoneH + safezoneY";
                w = "0.037 * safezoneW";
                h = "0.047 * safezoneH";
                colorText[] = {1, 1, 1, 0.75};
            };
            class RscText_1310: RscTextGUIK
            {
                idc = 1310;
                text = "0";
                x = "0.937 * safezoneW + safezoneX";
                y = "0.202 * safezoneH + safezoneY";
                w = "0.037 * safezoneW";
                h = "0.047 * safezoneH";
                colorText[] = {1, 1, 1, 0.75};
            };
            class RscText_1311: RscTextGUIK
            {
                idc = 1311;
                text = "3";
                x = "0.937 * safezoneW + safezoneX";
                y = "0.246 * safezoneH + safezoneY";
                w = "0.037 * safezoneW";
                h = "0.047 * safezoneH";
                colorText[] = {1, 1, 1, 0.75};
            };
            class RscText_1312: RscTextGUIK
            {
                idc = 1312;
                text = "4";
                x = "0.937 * safezoneW + safezoneX";
                y = "0.288 * safezoneH + safezoneY";
                w = "0.037 * safezoneW";
                h = "0.047 * safezoneH";
                colorText[] = {1, 1, 1, 0.75};
            };
            class RscPicture_1313: RscPictureGUI
            {
                idc = 1313;
                text = "\\origins_pack\\ui\\gui\\status_humanity_border.paa";
                x = "0.929 * safezoneW + safezoneX";
                y = "0.07 * safezoneH + safezoneY";
                w = "0.068 * safezoneW";
                h = "0.085 * safezoneH";
                colorText[] = {1, 1, 1, 0.300000012};
            };
            class RscText_1314: RscTextGUIK
            {
                idc = 1314;
                text = "2500";
                x = "0.944 * safezoneW + safezoneX";
                y = "0.122 * safezoneH + safezoneY";
                w = "0.037 * safezoneW";
                h = "0.047 * safezoneH";
                size = 0.0274999999;
                sizeEx = 0.0274999999;
                colorText[] = {1, 1, 1, 0.850000024};
            };
            class RscPicture_1315: RscPictureGUI
            {
                idc = 1315;
                text = "\\origins_pack\\ui\\gui\\apo_weight_icon_ca.paa";
                x = "0.96 * safezoneW + safezoneX";
                y = "0.581 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 1};
            };
            class RscPicture_1316: RscPictureGUI
            {
                idc = 1316;
                text = "\\origins_pack\\ui\\gui\\apo_weight_indicator_ca.paa";
                x = "0.944235 * safezoneW + safezoneX";
                y = "0.581 * safezoneH + safezoneY";
                w = "0.0435 * safezoneW";
                h = "0.0535 * safezoneH";
                colorText[] = {1, 1, 1, 1};
            };
            class RscPicture_1701: RscPictureGUI
            {
                idc = 1701;
                x = "0.945313 * safezoneW + safezoneX";
                y = "0.95 * safezoneH + safezoneY";
                w = 0.0399999991;
                h = 0.0533329993;
            };
            class RscPicture_1702: RscPictureGUI
            {
                idc = 1702;
                x = "0.945313 * safezoneW + safezoneX";
                y = "0.816666 * safezoneH + safezoneY";
                w = 0.0399999991;
                h = 0.0533329993;
            };
        };
    };
};
class RscDisplayDebriefing
{
    onLoad = "ctrlActivate ((_this select 0) displayCtrl 2);";
};
class RscIGUIShortcutButton: RscShortcutButton
{
    w = 0.183825001;
    h = 0.0522876009;
    style = 2;
    color[] = {1, 1, 1, 1};
    color2[] = {1, 1, 1, 0.850000024};
    colorBackground[] = {1, 1, 1, 1};
    colorbackground2[] = {1, 1, 1, 0.850000024};
    colorDisabled[] = {1, 1, 1, 0.400000006};
    class HitZone
    {
        left = 0.00200000009;
        top = 0.00300000003;
        right = 0.00200000009;
        bottom = 0.0160000008;
    };
    class ShortcutPos
    {
        left = -0.00600000005;
        top = -0.00700000022;
        w = 0.0392156988;
        h = 0.0522876009;
    };
    class TextPos
    {
        left = 0.0199999996;
        top = 0;
        right = 0.00200000009;
        bottom = 0.0160000008;
    };
    font = "TahomaB";
    period = 0;
    periodFocus = 0;
    periodOver = 0;
    animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
    animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
    animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
    animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
    animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
    animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
    class Attributes
    {
        font = "Zeppelin32";
        color = "#E5E5E5";
        align = "center";
        shadow = 1;
    };
};
class RscGearShortcutButton: RscShortcutButton
{
    w = 0.0392156988;
    h = 0.0522876009;
    style = 2;
    color[] = {1, 1, 1, 1};
    color2[] = {1, 1, 1, 0.850000024};
    colorBackground[] = {1, 1, 1, 1};
    colorbackground2[] = {1, 1, 1, 0.850000024};
    colorDisabled[] = {1, 1, 1, 0.400000006};
    class HitZone
    {
        left = 0;
        top = 0;
        right = 0;
        bottom = 0;
    };
    class ShortcutPos
    {
        left = -0.00600000005;
        top = -0.00700000022;
        w = 0.0392156988;
        h = 0.0522876009;
    };
    class TextPos
    {
        left = 0.00300000003;
        top = 0.00100000005;
        right = 0;
        bottom = 0;
    };
    sizeEx = 0.100000001;
    animTextureNormal = "\\origins_pack\\ui\\gear\\igui_gear_normal_ca.paa";
    animTextureDisabled = "\\origins_pack\\ui\\gear\\igui_gear_disabled_ca.paa";
    animTextureOver = "\\origins_pack\\ui\\gear\\igui_gear_over_ca.paa";
    animTextureFocused = "\\origins_pack\\ui\\gear\\igui_gear_focus_ca.paa";
    animTexturePressed = "\\origins_pack\\ui\\gear\\igui_gear_down_ca.paa";
    animTextureDefault = "\\origins_pack\\ui\\gear\\igui_gear_normal_ca.paa";
    class Attributes
    {
        font = "Zeppelin32";
        color = "#E5E5E5";
        align = "center";
        shadow = 0;
    };
};
class RscDisplayGear
{
    idd = 106;
    enableDisplay = 1;
	    onUnload = "[_this,'gearSync'] call handleGear;";
    class controls
    {
        class CA_Filter_Icon: RscPicture
        {
            idc = 148;
            style = "0x30 + 0x800";
            x = 0.0399999991;
            y = 0.54409802;
            w = 0.458000004;
            h = 0.075000003;
            text = "\\ca\\ui\\data\\igui_gear_filter_1_ca.paa";
        };
        class CA_Filter_Left_Icon: RscPicture
        {
            idc = 1301;
            style = "0x30 + 0x800";
            x = 0.0500000007;
            y = 0.545098007;
            w = 0.0359999985;
            h = 0.075000003;
            text = "\\ca\\ui\\data\\arrow_left_ca.paa";
        };
        class CA_Filter_Right_Icon: RscPicture
        {
            idc = 1302;
            style = "0x30 + 0x800";
            x = 0.453000009;
            y = 0.545098007;
            w = 0.0359999985;
            h = 0.075000003;
            text = "\\ca\\ui\\data\\arrow_right_ca.paa";
        };
        class CA_Filter_Arrow_Left: RscButton
        {
            idc = 150;
            colorText[] = {1, 1, 1, 0};
            colorDisabled[] = {1, 1, 1, 0};
            colorBackground[] = {1, 1, 1, 0};
            colorBackgroundDisabled[] = {1, 1, 1, 0};
            colorBackgroundActive[] = {1, 1, 1, 0};
            colorShadow[] = {1, 1, 1, 0};
            colorFocused[] = {1, 1, 1, 0};
            x = 0.0410000011;
            y = 0.545098007;
            w = 0.0560000017;
            h = 0.075000003;
            text = "";
        };
        class CA_Filter_Arrow_Right: RscButton
        {
            idc = 151;
            colorText[] = {1, 1, 1, 0};
            colorDisabled[] = {1, 1, 1, 0};
            colorBackground[] = {1, 1, 1, 0};
            colorBackgroundDisabled[] = {1, 1, 1, 0};
            colorBackgroundActive[] = {1, 1, 1, 0};
            colorShadow[] = {1, 1, 1, 0};
            colorFocused[] = {1, 1, 1, 0};
            x = 0.442999989;
            y = 0.545098007;
            w = 0.0560000017;
            h = 0.075000003;
            text = "";
        };
        class CA_Filter_Icon1: RscButton
        {
            idc = 149;
            colorText[] = {1, 1, 1, 0};
            colorDisabled[] = {1, 1, 1, 0};
            colorBackground[] = {1, 1, 1, 0};
            colorBackgroundDisabled[] = {1, 1, 1, 0};
            colorBackgroundActive[] = {1, 1, 1, 0};
            colorShadow[] = {1, 1, 1, 0};
            colorFocused[] = {1, 1, 1, 0};
            x = 0.0989999995;
            y = 0.545098007;
            w = 0.340999991;
            h = 0.0729999989;
            text = "";
        };
        class Gear_Title: CA_IGUI_Title
        {
            idc = 1001;
            x = 0.0476340018;
            y = -0.00102941005;
            text = "Gear";
        };
        class Unit_Title: RscText
        {
            idc = 101;
            style = 2;
            x = 0.502418995;
            y = 0.0492155999;
            w = 0.456;
        };
        class Available_items_Text: RscText
        {
            idc = 156;
            x = 0.0433013998;
            y = 0.0526966006;
            w = 0.389708996;
            h = 0.0294119995;
        };
        class CA_ItemName: Available_items_Text
        {
            idc = 1101;
            x = 0.0416704006;
            y = 0.627451003;
            text = "Gear of the unit:";
        };
        class CA_Money: RscText
        {
            idc = 1102;
            style = 1;
            show = 0;
            x = -2.50409007;
            y = -2.85784006;
            w = 0.228;
            text = "Money:";
        };
        class CA_Money_Value: RscText
        {
            idc = 1103;
            x = -2.72794008;
            y = -2.85784006;
            w = 0.228;
            text = "0";
        };
        class ListboxArrows: RscControlsGroup
        {
            x = 0.0399999991;
            y = 0.089244701;
            w = 0.479999989;
            h = 0.449000001;
            idc = 155;
            class VScrollbar
            {
                autoScrollSpeed = -1;
                autoScrollDelay = 5;
                autoScrollRewind = 0;
                color[] = {1, 1, 1, 0};
                width = 0.00100000005;
            };
            class HScrollbar
            {
                color[] = {1, 1, 1, 0};
                height = 0.00100000005;
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
                    columns[] = {0.075000003, 0.174999997, 0.810000002, 0.670000017};
                    drawSideArrows = 1;
                    idcRight = 147;
                    idcLeft = 146;
                    colorPlayerItem[] = {0.878400028, 0.847100019, 0.651000023, 1};
                    colorSelectBackground[] = {0.5, 0.5, 0.5, 1};
                    colorSelectBackground2[] = {0.5, 0.5, 0.5, 1};
                    onKeyDown = "[_this,'onKeyDown',0,107,0,107] call handleGear;";
                    onLBSelChanged = "[_this,'onLBSelChanged'] call handleGear; [_this,'list'] call (compile preprocessFileLineNumbers '\\z\\addons\\dayz_code\\compile\\a2edc_itemInfoPanel.sqf');";
                    onLBListSelChanged = "[_this,'onLBListSelChanged'] call handleGear; [_this,'list'] call (compile preprocessFileLineNumbers '\\z\\addons\\dayz_code\\compile\\a2edc_itemInfoPanel.sqf');";
                    onKillFocus = "[_this,'onKillFocus'] call handleGear;";
                    x = 0;
                    y = 0;
                    w = 0.460000008;
                    h = 0.449000001;
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
            x = 0.041496899;
            y = 0.663640976;
            w = 0.458000004;
            h = 0.151999995;
            colorText[] = {0.949999988, 0.949999988, 0.949999988, 1};
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
            x = 0.330882996;
            y = 0.785540998;
            w = 0.156863004;
            h = 0.104575001;
            text = "";
        };
        class G_Interaction: RscControlsGroup
        {
            idc = 6902;
            x = 0.503000021;
            y = "0.250 * safezoneH";
            w = "0.143 * safezoneW";
            h = 0;
            onMouseMoving = "[_this,'gearOffMenu'] call handleGear;";
            class VScrollbar
            {
                autoScrollSpeed = -1;
                autoScrollDelay = 5;
                autoScrollRewind = 0;
                color[] = {1, 1, 1, 0};
                width = 0.00100000005;
            };
            class HScrollbar
            {
                color[] = {1, 1, 1, 0};
                height = 0.00100000005;
            };
            class Controls
            {
                class RscButton_1600: RscButtonActionMenu
                {
                    idc = 1600;
                    text = "";
                    x = 0;
                    y = "0 * safezoneH";
                };
                class RscButton_1601: RscButtonActionMenu
                {
                    idc = 1601;
                    text = "";
                    x = 0;
                    y = "0.025 * safezoneH";
                };
                class RscButton_1602: RscButtonActionMenu
                {
                    idc = 1602;
                    text = "";
                    x = 0;
                    y = "0.05 * safezoneH";
                };
                class RscButton_1603: RscButtonActionMenu
                {
                    idc = 1603;
                    text = "";
                    x = 0;
                    y = "0.075 * safezoneH";
                };
                class RscButton_1604: RscButtonActionMenu
                {
                    idc = 1604;
                    text = "";
                    x = 0;
                    y = "0.1 * safezoneH";
                };
                class RscButton_1605: RscButtonActionMenu
                {
                    idc = 1605;
                    text = "";
                    x = 0;
                    y = "0.125 * safezoneH";
                };
                class RscButton_1606: RscButtonActionMenu
                {
                    idc = 1606;
                    text = "";
                    x = 0;
                    y = "0.15 * safezoneH";
                };
                class RscButton_1607: RscButtonActionMenu
                {
                    idc = 1607;
                    text = "";
                    x = 0;
                    y = "0.175 * safezoneH";
                };
                class RscButton_1608: RscButtonActionMenu
                {
                    idc = 1608;
                    text = "";
                    x = 0;
                    y = "0.2 * safezoneH";
                };
                class RscButton_1609: RscButtonActionMenu
                {
                    idc = 1609;
                    text = "";
                    x = 0;
                    y = "0.225 * safezoneH";
                };
            };
        };
        class G_GearItems: RscControlsGroup
        {
            idc = 160;
            x = 0.501999974;
            y = 0.0900000036;
            w = 0.463;
            h = 0.776000023;
            class VScrollbar
            {
                autoScrollSpeed = -1;
                autoScrollDelay = 5;
                autoScrollRewind = 0;
                color[] = {1, 1, 1, 0};
                width = 0.00100000005;
            };
            class HScrollbar
            {
                color[] = {1, 1, 1, 0};
                height = 0.00100000005;
            };
            class Controls
            {
                class CA_Gear_slot_primary: RscActiveText
                {
                    idc = 107;
                    x = "0.502 - 0.502";
                    y = "0.244 - 0.09";
                    w = 0.172000006;
                    h = 0.150999993;
                    style = "0x30 + 0x800";
                    onMouseButtonDown = "if ((_this select 1) == 1) then {_this call player_selectSlot;} else {[_this,'selectSlot'] call handleGear;}; [_this,'slot'] call (compile preprocessFileLineNumbers '\\z\\addons\\dayz_code\\compile\\a2edc_itemInfoPanel.sqf');";
                    soundDoubleClick[] = {"", 0.100000001, 1};
                    color[] = {1, 1, 1, 1};
                    colorBackground[] = {0.680000007, 0.680000007, 0.680000007, 0.75};
                    colorBackgroundSelected[] = {0.680000007, 0.680000007, 0.680000007, 0.75};
                    colorFocused[] = {0, 0, 0, 0};
                    canDrag = 1;
                };
                class CA_Gear_slot_secondary: CA_Gear_slot_primary
                {
                    idc = 108;
                    x = "0.6763 - 0.502";
                    y = "0.398 - 0.09";
                    w = 0.111699998;
                    h = 0.150000006;
                };
                class CA_Gear_slot_item1: CA_Gear_slot_primary
                {
                    idc = 109;
                    x = "0.790 - 0.502";
                    y = "0.244 - 0.09";
                    w = 0.0549999997;
                    h = 0.074000001;
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
                    w = 0.112999998;
                    h = 0.150000006;
                };
                class CA_Gear_slot_handgun_item1: CA_Gear_slot_item1
                {
                    idc = 122;
                    x = "0.676 - 0.502";
                    y = "0.551 - 0.09";
                    w = 0.0549999997;
                    h = 0.074000001;
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
                    w = 0.112999998;
                    h = 0.150000006;
                };
                class CA_Gear_slot_special2: CA_Gear_slot_special1
                {
                    idc = 131;
                    x = "0.847 - 0.502";
                    y = "0.09 - 0.09";
                    w = 0.112999998;
                    h = 0.150000006;
                };
                class CA_Gear_slot_inventory1: CA_Gear_slot_special1
                {
                    idc = 134;
                    x = "0.560 - 0.502";
                    y = "0.705 - 0.09";
                    w = 0.0549999997;
                    h = 0.074000001;
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
                    x = 10.1000004;
                    y = 10.1000004;
                };
                class bSmena1: RscActiveText
                {
                    idc = 510;
                    style = "0x30 + 0x800";
                    text = "\\origins_pack\\ui\\gear\\ui_arrow_normal2_ca.paa";
                    x = "0.502 - 0.502";
                    y = "0.39 - 0.09";
                    w = 0.173500001;
                    h = 0.0450000018;
                    color[] = {1, 1, 1, 0.5};
                    colorActive[] = {1, 1, 1, 0.800000012};
	                    onMouseButtonDown = "[_this,'selectSlot'] call handleGear;";
                };
                class CA_Gear_slot_shouder: RscActiveText
                {
                    idc = 511;
                    style = "0x30 + 0x800";
                    x = "0.502 - 0.502";
                    y = "0.43 - 0.09";
                    w = 0.172999993;
                    h = 0.119000003;
                    color[] = {1, 1, 1, 0.819999993};
                    colorActive[] = {1, 1, 1, 0.819999993};
                };
	                class OriMedB: RscActiveText
                {
                    idc = 512;
                    style = "0x30 + 0x800";
                    text = "";
                    x = "0.502 - 0.502";
                    y = "0.552 - 0.09";
                    w = 0.0549999997;
                    h = 0.150000006;
                    color[] = {1, 1, 1, 0.699999988};
                    colorActive[] = {1, 1, 1, 0.899999976};
                    onMouseButtonDown = "if ((_this select 1) == 1) then {_this call player_selectSlot;} else {[_this,'selectSlot'] call handleGear;};";
                };
                class OriVest: CA_Gear_slot_primary
                {
                    idc = 513;
                    style = "0x30 + 0x800";
                    text = "";
                    x = "0.678 - 0.502";
                    y = "0.245 - 0.09";
                    w = 0.108999997;
                    h = 0.150000006;
                    color[] = {1, 1, 1, 0.5};
                    colorActive[] = {1, 1, 1, 0.800000012};
                    onMouseButtonDown = "if ((_this select 1) == 1) then {_this call player_selectSlot;} else {[_this,'selectSlot'] call handleGear;};";
                };
            };
        };
        class G_sMedBItems: RscControlsGroup
        {
            idc = 514;
            x = 0.976999998;
            y = 0.47299999;
            w = 0.0560000017;
            h = 0.575999975;
            class VScrollbar
            {
                autoScrollSpeed = -1;
                autoScrollDelay = 5;
                autoScrollRewind = 0;
                color[] = {1, 1, 1, 0};
                width = 0.00100000005;
            };
            class HScrollbar
            {
                color[] = {1, 1, 1, 0};
                height = 0.00100000005;
            };
            class Controls
            {
                class OriMedB_slide1: RscActiveText
                {
                    idc = 515;
                    style = "0x30 + 0x800";
                    text = "";
                    x = "0";
                    y = "0";
                    w = 0.0560000017;
                    h = 0.0759999976;
                    color[] = {1, 1, 1, 0.800000012};
                    colorActive[] = {1, 1, 1, 0.899999976};
                    onMouseButtonDown = "if ((_this select 1) == 1) then {_this call player_selectSlot;} else {[_this,'selectSlot'] call handleGear;};";
                    canDrag = 1;
                };
                class OriMedB_slide2: OriMedB_slide1
                {
                    idc = 516;
                    y = "0.076";
                };
                class OriMedB_slide3: OriMedB_slide1
                {
                    idc = 517;
                    y = "0.152";
                };
                class OriMedB_slide4: OriMedB_slide1
                {
                    idc = 518;
                    y = "0.228";
                };
                class OriMedB_slide5: OriMedB_slide1
                {
                    idc = 519;
                    y = "0.304";
                };
                class OriMedB_slide6: OriMedB_slide1
                {
                    idc = 520;
                    y = "0.381";
                };
            };
        };
        class BagItemsGroup: RscControlsGroup
        {
            x = 0.501999974;
            y = 0.0900000036;
            w = 0.463;
            h = 0.776000023;
            idc = 159;
            magW = 0.0549999997;
            magH = 0.074000001;
            weaponW = 0.225999996;
            weaponH = 0.150000006;
            gunW = 0.112999998;
            gunH = 0.150000006;
            spacing = 0.00200000009;
            text = "";
            color[] = {1, 1, 1, 1};
            colorBackground[] = {1, 1, 1, 1};
            colorBackgroundSelected[] = {1, 1, 1, 1};
            colorFocused[] = {1, 1, 1, 1};
            soundPush[] = {"", 0.100000001, 1};
            soundClick[] = {"", 0.100000001, 1};
            soundDoubleClick[] = {"", 0.100000001, 1};
            class VScrollbar
            {
                autoScrollSpeed = -1;
                autoScrollDelay = 5;
                autoScrollRewind = 0;
                color[] = {1, 1, 1, 0};
                width = 0.00100000005;
            };
            class HScrollbar
            {
                color[] = {1, 1, 1, 0};
                height = 0.00100000005;
            };
            class ScrollBar
            {
                color[] = {1, 1, 1, 0.600000024};
                colorActive[] = {1, 1, 1, 1};
                colorDisabled[] = {1, 1, 1, 0.300000012};
                thumb = "\\ca\\ui\\data\\ui_scrollbar_thumb_ca.paa";
                arrowFull = "\\ca\\ui\\data\\ui_arrow_top_active_ca.paa";
                arrowEmpty = "\\ca\\ui\\data\\ui_arrow_top_ca.paa";
                border = "\\ca\\ui\\data\\ui_border_scroll_ca.paa";
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
            x = 0.333335996;
            y = 0.891300023;
            text = "Filter";
        };
        class ButtonRearm: RscIGUIShortcutButton
        {
            idc = 132;
            shortcuts[] = {"0x00050000 + 2"};
            x = 0.554742992;
            y = 0.891300023;
            w = 0;
            h = 0;
            text = "Rearm";
        };
        class ButtonOpenBag: RscIGUIShortcutButton
        {
            idc = 157;
            shortcuts[] = {"0x00050000 + 2"};
            x = 0.554742992;
            y = 0.891300023;
            text = "Open bag";
        };
        class ButtonCloseBag: RscIGUIShortcutButton
        {
            idc = 158;
            shortcuts[] = {"0x00050000 + 2"};
            x = 0.554742992;
            y = 0.891300023;
            text = "Close bag";
        };
        class ButtonContinue: RscIGUIShortcutButton
        {
            idc = 1;
            shortcuts[] = {"0x00050000 + 0", 28, 57, 156};
            x = 0.766149998;
            y = 0.891300023;
            default = 1;
        };
        class ButtonClose: RscIGUIShortcutButton
        {
            idc = 2;
            shortcuts[] = {"0x00050000 + 1"};
            x = 0.0460000001;
            y = 0.891099989;
            text = "Close";
        };
    };
    class Filters
    {
        class All
        {
            name = "All";
            mask = -1;
            image = "\\origins_pack\\ui\\gear\\igui_gear_filter_1_ca.paa";
        };
        class Primary
        {
            name = "Primary";
            mask = 769;
            image = "\\origins_pack\\ui\\gear\\igui_gear_filter_2_ca.paa";
        };
        class Secondary
        {
            name = "Secondary";
            mask = 516;
            image = "\\origins_pack\\ui\\gear\\igui_gear_filter_3_ca.paa";
        };
        class HandGun
        {
            name = "HandGun";
            mask = 18;
            image = "\\origins_pack\\ui\\gear\\igui_gear_filter_4_ca.paa";
        };
        class Items
        {
            name = "Items";
            mask = 135168;
            image = "\\origins_pack\\ui\\gear\\igui_gear_filter_5_ca.paa";
        };
    };
    movingEnable = 1;
    emptyGun = "\\origins_pack\\ui\\gear\\ui_gear_gun_gs_ca.paa";
    emptySec = "\\origins_pack\\ui\\gear\\ui_gear_sec_gs_small_ca.paa";
    emptyEq = "\\origins_pack\\ui\\gear\\ui_gear_eq_gs_ca.paa";
    emptyMag = "\\origins_pack\\ui\\gear\\ui_gear_mag_gs_ca.paa";
    emptyMag2 = "\\origins_pack\\ui\\gear\\ui_gear_mag2_gs_ca.paa";
    emptyHGun = "\\origins_pack\\ui\\gear\\ui_gear_hgun_gs_ca.paa";
    emptyHGunMag = "\\origins_pack\\ui\\gear\\ui_gear_hgunmag_gs_ca.paa";
    onLoad = "[_this,'initDialog'] call handleGear;";
    class ControlsBackground
    {
        class Mainback: RscPicture
        {
            idc = 1005;
            x = 0.0399999991;
            y = 0.00999999978;
            w = 1.25489998;
            h = 1.67320001;
            moving = 1;
            text = "\\origins_pack\\ui\\gear\\igui_background_gear_ca.paa";
        };
        class Ori_slot_bkW_bg: RscPicture
        {
            idc = 85011;
            x = "0.502";
            y = "0.43";
            w = 0.172999993;
            h = 0.119000003;
            text = "";
        };
        class Ori_slot_vestH_bg: RscPicture
        {
            idc = 85012;
            x = "0.676";
            y = "0.093";
            w = 0.112000003;
            h = 0.145500004;
            text = "\\origins_pack\\ui\\gear\\ui_gear_helmet_ca.paa";
            colorText[] = {0.879999995, 0.879999995, 0.879999995, 0.600000024};
        };
        class CA_Gear_slot_vest_bg: RscPicture
        {
            idc = 85013;
            x = "0.677";
            y = "0.2445";
            w = 0.111000001;
            h = 0.151999995;
            text = "";
        };
        class CA_Gear_slot_vest2_bg: RscPicture
        {
            idc = 85014;
            x = "0.781";
            y = "0.246";
            w = 0.00300000003;
            h = 0.150000006;
            text = "";
        };
        class CA_Gear_slot_medb_bg: RscPicture
        {
            idc = 85015;
            x = "0.503";
            y = "0.552";
            w = 0.0549999997;
            h = 0.150000006;
            text = "";
        };
        class CA_Gear_slot_medbs_bg: RscPicture
        {
            idc = 85016;
            x = "0.965";
            y = "0.397";
            w = 0.0719999969;
            h = 0.537;
            text = "";
        };
        class CA_Gear_slot_medbs1_bg: RscPicture
        {
            idc = 85017;
            x = "0.977";
            y = "0.4736";
            w = 0.0549999997;
            h = 0.0729999989;
            text = "";
        };
        class CA_Gear_slot_medbs2_bg: CA_Gear_slot_medbs1_bg
        {
            idc = 85018;
            y = "0.5498";
        };
        class CA_Gear_slot_medbs3_bg: CA_Gear_slot_medbs1_bg
        {
            idc = 85019;
            y = "0.6258";
        };
        class CA_Gear_slot_medbs4_bg: CA_Gear_slot_medbs1_bg
        {
            idc = 85020;
            y = "0.7018";
        };
        class CA_Gear_slot_medbs5_bg: CA_Gear_slot_medbs1_bg
        {
            idc = 85021;
            y = "0.7780";
        };
        class CA_Gear_slot_medbs6_bg: CA_Gear_slot_medbs1_bg
        {
            idc = 85022;
            y = "0.8548";
        };
    };
};
class RscShortcutButtonMainOri: RscShortcutButton
{
    idc = -1;
    style = 0;
    default = 0;
    w = 0.313725501;
    h = 0.104575202;
    color[] = {0.878400028, 0.847100019, 0.651000023, 1};
    colorDisabled[] = {1, 1, 1, 0.25};
    class HitZone
    {
        left = 0;
        top = 0;
        right = 0;
        bottom = 0;
    };
    class ShortcutPos
    {
        left = 0.0204000007;
        top = 0.0260000005;
        w = 0.0392156988;
        h = 0.0522876009;
    };
    class TextPos
    {
        left = 0.0799999982;
        top = 0.0340000018;
        right = 0.00499999989;
        bottom = 0.00499999989;
    };
    animTextureNormal = "\\origins_pack\\ui\\ui_knopka_menu_normal_ca.paa";
    animTextureDisabled = "\\origins_pack\\ui\\ui_knopka_menu_disabled_ca.paa";
    animTextureOver = "\\origins_pack\\ui\\ui_knopka_menu_over_ca.paa";
    animTextureFocused = "\\origins_pack\\ui\\ui_knopka_menu_focus_ca.paa";
    animTexturePressed = "\\origins_pack\\ui\\ui_knopka_menu_down_ca.paa";
    animTextureDefault = "\\origins_pack\\ui\\ui_knopka_menu_normal_ca.paa";
    period = 0.5;
    font = "Zeppelin32";
    size = 0.0392099991;
    sizeEx = 0.0392099991;
    text = "";
    soundEnter[] = {"\\ca\\ui\\data\\sound\\onover", 0.0900000036, 1};
    soundPush[] = {"\\ca\\ui\\data\\sound\\new1", 0, 0};
    soundClick[] = {"\\ca\\ui\\data\\sound\\onclick", 0.0700000003, 1};
    soundEscape[] = {"\\ca\\ui\\data\\sound\\onescape", 0.0900000036, 1};
    action = "";
    class Attributes
    {
        font = "Zeppelin32";
        color = "#E5E5E5";
        align = "left";
        shadow = 0;
    };
    class AttributesImage
    {
        font = "Zeppelin32";
        color = "#E5E5E5";
        align = 0;
    };
};
class RscDisplayMPInterrupt: RscStandardDisplay
{
    class controlsBackground
    {
        class Mainback: RscPicture
        {
            text = "\\origins_pack\\ui\\ui_menu_fon_ca.paa";
        };
        class ORI_Logo: RscPictureKeepAspect
        {
            x = 0.0579999983;
            y = 0.402999997;
            w = 0.300000012;
            h = 0.300000012;
            text = "z\\addons\\dayz_code\\gui\\Origins_logo_ca.paa";
        };
    };
    class controls
    {
        delete CA_B_REVERT;
        delete CA_B_Respawn;
        class CA_B_SAVE: RscShortcutButtonMainOri
        {
            onButtonClick = "";
            text = "";
        };
        class CA_B_Skip: CA_B_SAVE
        {
            onButtonClick = "";
            text = "";
        };
        class CA_B_Options: CA_B_SAVE
        {
            y = "0.2537 + 0.101903 * 0";
        };
        class CA_B_Abort: CA_B_SAVE
        {
            y = "0.2537 + 0.101903 * 1";
        };
        class Paused_Title: CA_Title
        {
            colorText[] = {0.949999988, 0.949999988, 0.949999988, 0.699999988};
        };
        class MissionTitle: RscText
        {
            colorText[] = {0.949999988, 0.949999988, 0.949999988, 0.699999988};
        };
        class DifficultyTitle: RscText
        {
            colorText[] = {0.949999988, 0.949999988, 0.949999988, 0.699999988};
        };
        class ButtonCancel: RscShortcutButton
        {
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_over_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            x = 0.177499995;
            y = 0.879899979;
            w = 0.153825;
            h = 0.0799999982;
            period = 0;
            class TextPos
            {
                left = 0.0450000018;
                top = 0.00999999978;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
        };
    };
};
class RscDisplayMultiplayerSetup: RscStandardDisplay
{
    class controlsBackground
    {
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
            text = "\\origins_pack\\ui\\fon_co.paa";
        };
        delete MP_roles_TitleBorder;
        class MP_roles_TitleBorder_Ori: RscPicture
        {
            colorbackground[] = {0, 0, 0, 0};
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(02/100) * SafeZoneH + SafeZoneY";
            w = "(96/100) * SafeZoneW";
            h = "(06/100) * SafeZoneH";
            text = "\\origins_pack\\ui\\mp_topfon.paa";
        };
        class Origins_Slogo: RscPictureKeepAspect
        {
            x = "(0.7/100) * SafeZoneW + SafeZoneX";
            y = "(0.1/100) * SafeZoneH + SafeZoneY";
            w = "(10/100) * SafeZoneW";
            h = "(7.5/100) * SafeZoneH";
            text = "z\\addons\\dayz_code\\gui\\Origins_logo_ca.paa";
        };
        delete TextBorder;
        delete TextBack1;
        class ValuePoolBack: RscText
        {
            x = "(20/100) * SafeZoneW + SafeZoneX";
            y = "(12.5/100) * SafeZoneH + SafeZoneY";
            w = "(78/100) * SafeZoneW";
            h = "(76/100) * SafeZoneH";
            colorBackground[] = {0.423519999, 0.423519999, 0.423519999, 0.430000007};
        };
        class ValuePoolBorder: RscText
        {
            style = 64;
            colorText[] = {0, 0, 0, 1};
            x = "(20/100) * SafeZoneW + SafeZoneX";
            y = "(12.5/100) * SafeZoneH + SafeZoneY";
            w = "(78/100) * SafeZoneW";
            h = "(76/100) * SafeZoneH";
        };
    };
    class controls
    {
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
        class TextSide: RscText
        {
            y = "(9.5/100) * SafeZoneH + SafeZoneY";
        };
        class TextPool: RscText
        {
            style = 0;
            x = "(20/100) * SafeZoneW + SafeZoneX";
            y = "(9.5/100) * SafeZoneH + SafeZoneY";
        };
        class CA_MP_roles_Title: CA_Title
        {
            idc = 1001;
            style = 2;
            x = "(02/100) * SafeZoneW + SafeZoneX";
            y = "(02/100) * SafeZoneH + SafeZoneY";
            w = "(96/100) * SafeZoneW";
            h = "(06/100) * SafeZoneH";
            font = "TahomaB";
            sizeEx = 0.0590653606;
            colorText[] = {0, 0, 0, 0.899999976};
            colorBackground[] = {"49/255", "36/255", "25/255", "0/255"};
            text = "$STR_DISP_MPSETUP_TITLE";
        };
        class OriginsSurv: RscPictureKeepAspect
        {
            w = "(12.7/100) * SafeZoneW";
            h = "(12.7/100) * SafeZoneH";
            x = "(4.15/100) * SafeZoneW + SafeZoneX";
            y = "(15/100) * SafeZoneH + SafeZoneY";
            text = "\\origins_pack\\ui\\flag_origins_ca.paa";
        };
        delete CA_B_West;
        class CA_B_WestOri: RscActiveText
        {
            x = "(4.15/100) * SafeZoneW + SafeZoneX";
            y = "(15/100) * SafeZoneH + SafeZoneY";
            w = "(12.7/100) * SafeZoneW";
            h = "(8/100) * SafeZoneH";
            style = "0x02 + 0x100 + 0x40";
            type = 11;
            colorActive[] = {1, 1, 1, 1};
            colorDisabled[] = {1, 1, 1, 0.150000006};
            colorShade[] = {1, 1, 1, 1};
            colorText[] = {1, 1, 1, 1};
            pictureWidth = 1;
            pictureHeight = 1;
            textHeight = 0.349999994;
            sideDisabled = "origins_pack\\ui\\flag_origins_pustoj_ca.paa";
            sideToggle = "origins_pack\\ui\\flag_origins_pustoj_ca.paa";
            idc = 104;
            color[] = {1, 1, 1, 1};
            text = "SURVIVORS";
            picture = "\\origins_pack\\ui\\flag_origins_pustoj_ca.paa";
        };
        class CA_ValuePool: RscIGUIListBox
        {
            x = "(20/100) * SafeZoneW + SafeZoneX";
            y = "(12.5/100) * SafeZoneH + SafeZoneY";
            w = "(78/100) * SafeZoneW";
            h = "(72/100) * SafeZoneH";
            rows = 25;
            canDrag = 0;
        };
        class CA_ButtonContinue: RscShortcutButton
        {
            idc = 1;
            default = 1;
            shortcuts[] = {"0x00050000+0", 28, 57, 156};
            x = "(83/100) * SafeZoneW + SafeZoneX";
            y = "(93/100) * SafeZoneH + SafeZoneY";
            text = "$STR_DISP_OK";
            font = "TahomaB";
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            h = 0.0700000003;
            class TextPos
            {
                left = 0.0700000003;
                top = 0.00700000022;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00400000019;
                top = 0.00400000019;
                right = 0.00400000019;
                bottom = 0.00400000019;
            };
        };
        class CA_ButtonCancel: RscShortcutButton
        {
            idc = 2;
            default = 0;
            shortcuts[] = {"0x00050000+1"};
            x = "(68/100) * SafeZoneW + SafeZoneX";
            y = "(93/100) * SafeZoneH + SafeZoneY";
            w = 0.203824997;
            text = "$STR_DISP_BACK";
            font = "TahomaB";
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            animTextureNormal = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureDisabled = "\\origins_pack\\ui\\esc_knopka_normal_ca.paa";
            animTextureOver = "\\origins_pack\\ui\\esc_knopka_focus_ca.paa";
            animTextureFocused = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            animTexturePressed = "\\origins_pack\\ui\\esc_knopka_down_ca.paa";
            animTextureDefault = "\\origins_pack\\ui\\esc_knopka_default_ca.paa";
            h = 0.0700000003;
            class TextPos
            {
                left = 0.0500000007;
                top = 0.00700000022;
                right = 0.00499999989;
                bottom = 0.00499999989;
            };
            class HitZone
            {
                left = 0.00400000019;
                top = 0.00400000019;
                right = 0.00400000019;
                bottom = 0.00400000019;
            };
        };
    };
};
class CfgVehicles
{
    class AllVehicles;
    class Air: AllVehicles
    {
        class NewTurret;
        class ViewPilot;
        class AnimationSources;
    };
    class Ship: AllVehicles
    {
        class NewTurret;
        class ViewPilot;
        class AnimationSources;
    };
    class Boat: Ship
    {
        class HitPoints
        {
            class HitEngine
            {
                armor = 1.20000005;
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
    class Helicopter: Air
    {
        class HitPoints
        {
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
        icon = "\\Ca\\animals2\\data\\mapicon_animals_ca.paa";
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
        extCameraPosition[] = {0, 0.5, -2.5};
        class EventHandlers
        {
        };
        class Wounds
        {
            tex[] = {};
            mat[] = {};
        };
        class VariablesScalar
        {
        };
        class VariablesString
        {
        };
    };
    class DZ_Pastor: Pastor
    {
        scope = 2;
        model = "\\ca\\animals2\\Dogs\\Pastor\\Pastor";
        displayName = "Alsatian";
        moves = "CfgMovesDogDZ";
        gestures = "CfgGesturesDogDZ";
        fsmDanger = "";
        fsmFormation = "";
    };
    class DZ_Fin: Fin
    {
        scope = 2;
        model = "\\ca\\animals2\\Dogs\\Fin\\Fin";
        displayName = "Fin";
        moves = "CfgMovesDogDZ";
        gestures = "CfgGesturesDogDZ";
        fsmDanger = "";
        fsmFormation = "";
    };
    class Bag_Base_EP1;
    class DZ_Patrol_Pack_EP1: Bag_Base_EP1
    {
        scope = 2;
        displayName = "Patrol Pack (coyote)";
        picture = "\\ca\\weapons_e\\data\\icons\\backpack_US_ASSAULT_COYOTE_CA.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        mapsize = 2;
        model = "\\ca\\weapons_e\\AmmoBoxes\\backpack_us_assault_Coyote.p3d";
        transportMaxWeapons = 3;
        transportMaxMagazines = 16;
    };
    class DZ_Assault_Pack_EP1: Bag_Base_EP1
    {
        scope = 2;
        displayName = "Assault Pack (ACU)";
        picture = "\\ca\\weapons_e\\data\\icons\\backpack_US_ASSAULT_CA.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        mapSize = 2;
        model = "\\ca\\weapons_e\\AmmoBoxes\\backpack_us_assault.p3d";
        transportMaxWeapons = 3;
        transportMaxMagazines = 16;
    };
    class origins_school_1: Bag_Base_EP1
    {
        scope = 2;
        mapsize = 2;
        displayName = "School Bag(Owl)";
        model = "\\origins_pack\\items\\schoolruck.p3d";
        picture = "\\origins_pack\\items\\school_b_ca.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        transportMaxweapons = 3;
        transportMaxMagazines = 16;
    };
    class origins_school_2: Bag_Base_EP1
    {
        scope = 2;
        mapsize = 2;
        displayName = "Bad boy bag";
        model = "\\origins_pack\\items\\schoolruck_b.p3d";
        picture = "\\origins_pack\\items\\school_m_ca.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        transportMaxweapons = 3;
        transportMaxMagazines = 16;
    };
    class origins_school_3: Bag_Base_EP1
    {
        scope = 2;
        mapsize = 2;
        displayName = "Girls Bag(Dora)";
        model = "\\origins_pack\\items\\schoolruck_k.p3d";
        picture = "\\origins_pack\\items\\school_k_ca.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        transportMaxweapons = 3;
        transportMaxMagazines = 16;
    };
    class origins_bear: Bag_Base_EP1
    {
        scope = 2;
        mapsize = 2;
        displayName = "Bear Bag";
        model = "\\origins_pack\\items\\vil_misiopack.p3d";
        picture = "\\origins_pack\\items\\textures\\bear_bacpack_ca.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        transportMaxweapons = 4;
        transportMaxMagazines = 20;
    };
    class origins_elephant1: Bag_Base_EP1
    {
        scope = 2;
        mapsize = 2;
        displayName = "Elephant Bag(Blue)";
        model = "\\origins_pack\\items\\elephruck.p3d";
        picture = "\\origins_pack\\items\\textures\\eleph1_bacpack_ca.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        transportMaxweapons = 4;
        transportMaxMagazines = 20;
    };
    class origins_elephant2: Bag_Base_EP1
    {
        scope = 2;
        mapsize = 2;
        displayName = "Elephant Bag(Black)";
        model = "\\origins_pack\\items\\elephruck2.p3d";
        picture = "\\origins_pack\\items\\textures\\eleph2_bacpack_ca.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        transportMaxweapons = 4;
        transportMaxMagazines = 20;
    };
    class DZ_ALICE_Pack_EP1: Bag_Base_EP1
    {
        scope = 2;
        displayName = "ALICE Pack";
        picture = "\\ca\\weapons_e\\data\\icons\\backpack_TK_ALICE_CA.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        mapsize = 2;
        model = "\\ca\\weapons_e\\AmmoBoxes\\backpack_tk_alice.p3d";
        transportMaxWeapons = 6;
        transportMaxMagazines = 24;
    };
    class DZ_CivilBackpack_EP1: Bag_Base_EP1
    {
        scope = 2;
        displayName = "Czech Backpack";
        picture = "\\ca\\weapons_e\\data\\icons\\backpack_ACR_CA.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        mapsize = 2;
        model = "\\ca\\weapons_e\\AmmoBoxes\\backpack_acr.p3d";
        transportMaxWeapons = 6;
        transportMaxMagazines = 24;
    };
    class DZ_Backpack_EP1: Bag_Base_EP1
    {
        scope = 2;
        displayName = "Backpack (coyote)";
        picture = "\\ca\\weapons_e\\data\\icons\\backpack_US_CA.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        mapsize = 2;
        model = "\\ca\\weapons_e\\AmmoBoxes\\backpack_us.p3d";
        transportMaxWeapons = 6;
        transportMaxMagazines = 28;
    };
    class O_TravelerPack_1: Bag_Base_EP1
    {
        scope = 2;
        displayName = "Traveler (Martin)";
        picture = "\\ca\\weapons_e\\data\\icons\\backpack_CIVIL_ASSAULT_CA.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        mapsize = 2;
        model = "\\ca\\weapons_e\\AmmoBoxes\\backpack_civil_assault.p3d";
        transportMaxWeapons = 10;
        transportMaxMagazines = 32;
    };
    class O_MegaPack_1: Bag_Base_EP1
    {
        scope = 2;
        displayName = "Mega";
        picture = "\\ca\\weapons_e\\data\\icons\\backpack_RPG_CA.paa";
        icon = "\\ca\\weapons_e\\data\\icons\\mapIcon_backpack_CA.paa";
        mapsize = 2;
        model = "\\ca\\weapons_e\\AmmoBoxes\\backpack_rpg.p3d";
        transportMaxWeapons = 12;
        transportMaxMagazines = 40;
    };
    class ori_30l_Backpack: Bag_Base_EP1
    {
        scope = 2;
        displayName = "Explorer";
        picture = "\\origins_pack\\salvation\\ui_explorer_backpack_ca.paa";
        model = "\\origins_pack\\salvation\\30l_ruck.p3d";
        icon = "\\origins_pack\\salvation\\ui_explorer_backpack_ca.paa";
        transportMaxweapons = 12;
        transportMaxMagazines = 48;
    };
    class ori_bigrusruck: Bag_Base_EP1
    {
        scope = 2;
        displayName = "Adventurer";
        picture = "\\origins_pack\\items\\ico_big_rus_pack_ca.paa";
        model = "\\origins_pack\\items\\bigrusruck.p3d";
        icon = "\\origins_pack\\items\\ico_big_rus_pack_ca.paa";
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
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        transportMaxMagazines = 250;
        transportMaxWeapons = 100;
        transportMaxBackpacks = 10;
        side = 2;
        model = "\\ca\\water\\rhib";
        picture = "\\ca\\water\\data\\ico\\rhib_CA.paa";
        Icon = "\\Ca\\water\\Data\\map_ico\\icomap_RHIB_CA.paa";
        mapSize = 8;
        unitInfoType = "UnitInfoShip";
        soundEnviron[] = {"", 0.056234099, 0.899999976};
        precision = 6;
        brakeDistance = 20;
        class SoundEvents
        {
        };
        insideSoundCoef = 1;
        soundEngineOnInt[] = {"ca\\sounds\\vehicles\\water\\rhib\\ext-boat-start-01", 0.100000001, 1};
        soundEngineOnExt[] = {"ca\\sounds\\vehicles\\water\\rhib\\ext-boat-start-01", 1, 1, 150};
        soundEngineOffInt[] = {"ca\\sounds\\vehicles\\water\\rhib\\ext-boat-stop-01", 0.100000001, 1};
        soundEngineOffExt[] = {"ca\\sounds\\vehicles\\water\\rhib\\ext-boat-stop-01", 1, 1, 150};
        class Sounds
        {
            class Engine
            {
                sound[] = {"ca\\sounds\\vehicles\\water\\rhib\\ext-boat-engine-low-01", 1, 0.899999976, 300};
                frequency = "(randomizer*0.05+0.95)*rpm";
                volume = "engineOn*(rpm factor[0.5, 0.1])";
            };
            class EngineHighOut
            {
                sound[] = {"ca\\sounds\\vehicles\\water\\rhib\\ext-boat-engine-high-01", 1, 0.800000012, 300};
                frequency = "(randomizer*0.05+0.95)*rpm";
                volume = "engineOn*(rpm factor[0.4, 1.3])";
            };
            class IdleOut
            {
                sound[] = {"ca\\sounds\\vehicles\\water\\rhib\\ext-boat-engine-idle-03", 0.562340975, 1, 150};
                frequency = "1";
                volume = "engineOn*(rpm factor[0.3, 0])";
            };
            class WaternoiseOutW0
            {
                sound[] = {"ca\\sounds\\vehicles\\water\\water_sfx\\ext-water-noise-nospeed", 0.398106992, 1, 100};
                frequency = "1";
                volume = "(speed factor[7, 0])";
            };
            class WaternoiseOutW1
            {
                sound[] = {"ca\\sounds\\vehicles\\water\\water_sfx\\ext-boat-lospd-noise-02", 0.398106992, 1, 100};
                frequency = "1";
                volume = "((speed factor[2, 12]) min (speed factor[12, 2]))";
            };
            class WaternoiseOutW2
            {
                sound[] = {"ca\\sounds\\vehicles\\water\\water_sfx\\ext-boat-hispd-noise-02", 0.398106992, 1, 100};
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
                        armor = 0.800000012;
                        material = 60;
                        name = "vez";
                        visual = "vez";
                        passThrough = 1;
                    };
                    class HitGun
                    {
                        armor = 0.600000024;
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
                soundServo[] = {"\\ca\\sounds\\vehicles\\servos\\turret-1", 0.00562340999, 1};
                gunBeg = "usti hlavne";
                gunEnd = "konec hlavne";
                weapons[] = {"M2"};
                magazines[] = {"100Rnd_127x99_M2", "100Rnd_127x99_M2", "100Rnd_127x99_M2"};
                gunnerName = "front gunner";
                gunnerOpticsModel = "\\ca\\weapons\\optika_empty";
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
                    initFov = 0.699999988;
                    minFov = 0.25;
                    maxFov = 1.10000002;
                };
                class ViewGunner
                {
                    initAngleX = 5;
                    minAngleX = -65;
                    maxAngleX = 85;
                    initAngleY = 0;
                    minAngleY = -150;
                    maxAngleY = 150;
                    initFov = 0.699999988;
                    minFov = 0.25;
                    maxFov = 1.10000002;
                };
            };
        };
        class Library
        {
            libTextDesc = "The Naval Special Warfare Rigid Hull Inflatable Boat is a fast, high-buoyancy all weather boat designed to transport a fully equipped team of eight-men and three crew members. It is also fully transportable by C-130 Hercules.";
        };
        extCameraPosition[] = {0, 4, -14};
        class Damage
        {
            tex[] = {};
            mat[] = {"ca\\water\\data\\rhib.rvmat", "ca\\water\\data\\rhib.rvmat", "ca\\water\\data\\rhib_destruct.rvmat", "ca\\water\\data\\rhib_dash.rvmat", "ca\\water\\data\\rhib_dash.rvmat", "ca\\water\\data\\rhib_dash_destruct.rvmat"};
        };
    };
    class Zodiac_Ori: Zodiac
    {
        transportMaxMagazines = 50;
        transportMaxWeapons = 10;
        faction = "rth_copter_class";
    };
    class PBX_Ori: PBX
    {
        transportMaxMagazines = 50;
        transportMaxWeapons = 10;
        faction = "rth_copter_class";
    };
    class Fishing_Boat_DZ: Fishing_Boat
    {
        transportMaxMagazines = 500;
        transportMaxWeapons = 200;
        maxSpeed = 25;
    };
    class Smallboat_1_DZ: Smallboat_1
    {
        transportMaxMagazines = 500;
        transportMaxWeapons = 200;
        maxSpeed = 25;
    };
    class smallboat_2_DZ: smallboat_2
    {
        transportMaxMagazines = 500;
        transportMaxWeapons = 200;
        maxSpeed = 25;
    };
    class UH1H_Ori: Helicopter
    {
        expansion = 1;
        scope = 2;
        side = 2;
        crew = "";
        model = "Ca\\air_E\\UH1H\\UH1H.p3d";
        displayName = "UH1H";
        faction = "rth_copter_class";
        typicalCargo[] = {};
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        commanderCanSee = "2+16+32";
        gunnerCanSee = "2+16+32";
        driverCanSee = "2+16+32";
        transportMaxMagazines = 250;
        transportMaxWeapons = 20;
        transportMaxBackpacks = 5;
        radarType = 0;
        weapons[] = {};
        magazines[] = {};
        hasGunner = 1;
        enableSweep = 0;
        driverCompartments = "Compartment1";
        cargoCompartments[] = {"Compartment1"};
        hiddenSelectionsTextures[] = {"ca\\air_E\\UH1H\\data\\UH1D_TKA_CO.paa", "ca\\air_E\\UH1H\\data\\UH1D_in_TKA_CO.paa", "ca\\air_E\\UH1H\\data\\default_TKA_co.paa"};
        picture = "\\ca\\air_e\\data\\UI\\Picture_uh1h_CA.paa";
        icon = "\\ca\\air_e\\data\\UI\\Icon_uh1h_CA.paa";
        mapSize = 14;
        destrType = "DestructWreck";
        ejectDeadGunner = 1;
        ejectDeadCargo = 1;
        ejectDeadDriver = 1;
        ejectDeadCommander = 1;
        class Library
        {
            libTextDesc = "$STR_EP1_LIB_UH1H";
        };
        cargoAction[] = {"UH1H_Cargo_EP1", "UH1Y_Cargo03", "UH1Y_Cargo03", "UH1Y_Cargo02", "UH1Y_Cargo01", "UH1Y_Cargo01", "UH1Y_Cargo01"};
        cargoIsCoDriver[] = {0, 1};
        transportSoldier = 5;
        driverAction = "UH1H_Pilot_EP1";
        driverInAction = "UH1H_Pilot_EP1";
        driverOpticsModel = "";
        gunnerOpticsModel = "";
        threat[] = {0.400000006, 0, 0};
        mainRotorSpeed = 1.20000005;
        backRotorSpeed = 6.0999999;
        soundGetIn[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\open_close", 0.316228002, 1};
        soundGetOut[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\open_close", 0.316228002, 1, 40};
        soundEngineOnInt[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_start_int", 0.446684003, 1};
        soundEngineOnExt[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_start_ext", 0.446684003, 1, 700};
        soundEngineOffInt[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_stop_int", 0.446684003, 1};
        soundEngineOffExt[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_stop_ext", 0.446684003, 1, 700};
        enableManualFire = 0;
        class Sounds
        {
            class Engine
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_engine_ext_2", 1, 1, 800};
                frequency = "rotorSpeed";
                volume = "camPos*((rotorSpeed-0.72)*4)";
            };
            class RotorLowOut
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_rotor_ext_1", 2.51188993, 1, 1400};
                frequency = "rotorSpeed";
                volume = "camPos*(0 max (rotorSpeed-0.1))";
                cone[] = {1.60000002, 3.1400001, 2, 0.5};
            };
            class RotorHighOut
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_rotor_high_ext_1", 2.51188993, 1, 1600};
                frequency = "rotorSpeed";
                volume = "camPos*10*(0 max (rotorThrust-0.9))";
                cone[] = {1.60000002, 3.1400001, 2, 0.5};
            };
            class EngineIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_engine_int_1", 1, 1};
                frequency = "rotorSpeed";
                volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
            };
            class RotorLowIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_rotor_int_1", 1.77828002, 1};
                frequency = "rotorSpeed";
                volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
            };
            class RotorHighIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_rotor_high_int_1", 3.16228008, 1};
                frequency = "rotorSpeed";
                volume = "(1-camPos)*3*(rotorThrust-0.9)";
            };
        };
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                body = "mainTurret";
                gun = "mainGun";
                minElev = -60;
                maxElev = 30;
                initElev = -30;
                minTurn = -173;
                maxTurn = -3;
                initTurn = -70;
                soundServo[] = {"", 0.00999999978, 1};
                stabilizedInAxes = "StabilizedInAxesNone";
                weapons[] = {"M240_veh"};
                magazines[] = {"100Rnd_762x51_M240", "100Rnd_762x51_M240", "100Rnd_762x51_M240"};
                gunBeg = "muzzle";
                gunEnd = "chamber";
                gunnerName = "$STR_POSITION_DOORGUNNER";
                memoryPointsGetInGunner = "pos Gunner";
                memoryPointsGetInGunnerDir = "pos Gunner dir";
                gunnerOpticsModel = "\\ca\\weapons\\optika_empty";
                memoryPointGunnerOptics = "gunnerview";
                gunnerOutOpticsShowCursor = 1;
                gunnerOpticsShowCursor = 0;
                gunnerAction = "UH1Y_Gunner";
                gunnerInAction = "UH1Y_Gunner";
                commanding = -3;
                primaryGunner = 0;
                gunnerCompartments = "Compartment1";
                class ViewOptics
                {
                    initAngleX = 0;
                    minAngleX = -30;
                    maxAngleX = 30;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = 0.699999988;
                    minFov = 0.25;
                    maxFov = 1.10000002;
                };
                LODTurnedOut = 1000;
                LODTurnedIn = 1000;
            };
            class LeftDoorGun: MainTurret
            {
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
                gunnerName = "$STR_POSITION_CREWCHIEF";
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
        class AnimationSources: AnimationSources
        {
            class ReloadAnim
            {
                source = "reload";
                weapon = "M240_veh";
            };
            class ReloadMagazine
            {
                source = "reloadmagazine";
                weapon = "M240_veh";
            };
            class Revolving
            {
                source = "revolving";
                weapon = "M240_veh";
            };
            class ReloadAnim_2
            {
                source = "reload";
                weapon = "M240_veh_2";
            };
            class ReloadMagazine_2
            {
                source = "reloadmagazine";
                weapon = "M240_veh_2";
            };
            class Revolving_2
            {
                source = "revolving";
                weapon = "M240_veh_2";
            };
        };
        armor = 25;
        damageResistance = 0.0039400002;
        class HitPoints: HitPoints
        {
            class HitGlass1: HitGlass1
            {
                armor = 0.25;
            };
            class HitGlass2: HitGlass2
            {
                armor = 0.25;
            };
            class HitGlass3: HitGlass3
            {
                armor = 0.25;
            };
            class HitGlass4: HitGlass4
            {
                armor = 0.25;
            };
            class HitGlass5: HitGlass5
            {
                armor = 0.25;
            };
            class HitGlass6: HitGlass5
            {
                armor = 0.25;
            };
        };
        class Damage
        {
            tex[] = {};
            mat[] = {"ca\\Air_E\\UH1H\\Data\\UH1D.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_destruct.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_cockpit1.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_cockpit1.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_cockpit1_destruct.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_cockpit2.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_cockpit2.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_cockpit2_destruct.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_cockpit3.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_cockpit3.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_cockpit3_destruct.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_glass.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_glass_damage.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_glass_damage.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_in.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_in.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_in_destruct.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_instruments.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_instruments.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_instruments_destruct.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_rotor.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_rotor.rvmat", "ca\\Air_E\\UH1H\\Data\\UH1D_rotor_destruct.rvmat", "ca\\data\\data\\default.rvmat", "ca\\data\\data\\default.rvmat", "ca\\Air_E\\UH1H\\Data\\default_destruct.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default_destruct.rvmat"};
        };
        hiddenSelections[] = {"Camo1", "Camo2", "Camo_mlod"};
        irScanRangeMin = 100;
        irScanRangeMax = 1000;
        irScanToEyeFactor = 2;
    };
    class Mi17_base: Helicopter
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
                class ViewOptics
                {
                    initAngleX = 0;
                    minAngleX = -30;
                    maxAngleX = 30;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = 0.699999988;
                    minFov = 0.25;
                    maxFov = 1.10000002;
                };
                class Turrets: Turrets
                {
                };
            };
            class BackTurret: MainTurret
            {
                minElev = -80;
                maxElev = 25;
                initElev = -80;
                minTurn = -185;
                maxTurn = -45;
                initTurn = -155;
                class Turrets: Turrets
                {
                };
            };
        };
        class AnimationSources;
        model = "\\ca\\Air_E\\Mi17\\Mi_8MT";
        destrType = "DestructWreck";
        weapons[] = {};
        armor = 25;
        magazines[] = {};
        LockDetectionSystem = 0;
        IncommingMisslieDetectionSystem = 0;
        radarType = 0;
        maxSpeed = 180;
        threat[] = {0.5, 0, 0};
        hiddenSelections[] = {"Camo1", "Camo2", "Camo3", "Camo4"};
        class Reflectors
        {
            class Left
            {
                color[] = {0.800000012, 0.800000012, 1, 1};
                ambient[] = {0.0700000003, 0.0700000003, 0.0700000003, 1};
                position = "L svetlo";
                direction = "konec L svetla";
                hitpoint = "L svetlo";
                selection = "L svetlo";
                size = 1;
                brightness = 1;
            };
            class Right
            {
                color[] = {0.800000012, 0.800000012, 1, 1};
                ambient[] = {0.0700000003, 0.0700000003, 0.0700000003, 1};
                position = "P svetlo";
                direction = "konec P svetla";
                hitpoint = "P svetlo";
                selection = "P svetlo";
                size = 1;
                brightness = 1;
            };
        };
        aggregateReflectors[] = {{"Left", "Right"}};
        class HitPoints: HitPoints
        {
            class HitGlass1: HitGlass1
            {
                armor = 0.119999997;
            };
            class HitGlass2: HitGlass2
            {
                armor = 0.119999997;
            };
            class HitGlass3: HitGlass3
            {
                armor = 0.119999997;
            };
            class HitGlass4: HitGlass4
            {
                armor = 0.119999997;
            };
            class HitGlass5: HitGlass5
            {
                armor = 0.119999997;
            };
            class HitGlass6: HitGlass6
            {
                armor = 0.119999997;
            };
        };
        class Damage
        {
            tex[] = {};
            mat[] = {"Ca\\Air_E\\Mi17\\data\\mi8_body_amt.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_body_amt_damage.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_body_amt_destruct.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_det_g.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_det_g_damage.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_det_g_destruct.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_glass.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_glass_damage.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_glass_damage.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_glass_in.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_glass_in_damage.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_glass_in_damage.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_inter.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_inter_damage.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_inter_destruct.rvmat", "ca\\weapons\\data\\pkm.rvmat", "ca\\weapons\\data\\pkm.rvmat", "ca\\weapons\\data\\pkm_destruct.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_body_mtv.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_body_mtv_damage.rvmat", "Ca\\Air_E\\Mi17\\data\\mi8_body_mtv_destruct.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default_destruct.rvmat"};
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
        hiddenSelectionsTextures[] = {"\\ca\\air_E\\Data\\mi17_body_IND_CO.paa", "\\ca\\air_E\\Data\\mi17_det_IND_CO.paa", "\\ca\\air\\data\\clear_empty.paa", "\\ca\\air\\data\\mi8_decals_ca.paa"};
        class Turrets: Turrets
        {
            class FrontTurret: MainTurret
            {
                weapons[] = {"PKT"};
                magazines[] = {"100Rnd_762x54_PK", "100Rnd_762x54_PK", "100Rnd_762x54_PK"};
                gunnerCompartments = "Compartment1";
                commanding = -3;
            };
            class BackTurret: BackTurret
            {
                weapons[] = {"PKT_2"};
                magazines[] = {"100Rnd_762x54_PK", "100Rnd_762x54_PK", "100Rnd_762x54_PK"};
                gunnerCompartments = "Compartment1";
                commanding = -3;
            };
        };
        weapons[] = {};
        magazines[] = {};
        class AnimationSources: AnimationSources
        {
            class ReloadAnim
            {
                source = "reload";
                weapon = "PKT";
            };
            class ReloadMagazine
            {
                source = "reloadmagazine";
                weapon = "PKT";
            };
            class Revolving
            {
                source = "revolving";
                weapon = "PKT";
            };
            class ReloadAnim_2
            {
                source = "reload";
                weapon = "PKT_2";
            };
            class ReloadMagazine_2
            {
                source = "reloadmagazine";
                weapon = "PKT_2";
            };
            class Revolving_2
            {
                source = "revolving";
                weapon = "PKT_2";
            };
        };
        gunnerHasFlares = 0;
        commanderCanSee = "2+16+32";
        gunnerCanSee = "2+16+32";
        driverCanSee = "2+16+32";
        transportMaxMagazines = 250;
        transportMaxWeapons = 100;
        transportMaxBackpacks = 10;
    };
    class Mi17_Civilian_Ori: Mi17_base
    {
        vehicleClass = "Air";
        model = "\\ca\\air\\Mi_8AMT";
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
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        class Turrets: Turrets
        {
        };
        commanderCanSee = "2+16+32";
        gunnerCanSee = "2+16+32";
        driverCanSee = "2+16+32";
        weapons[] = {};
        magazines[] = {};
        gunnerHasFlares = 0;
        threat[] = {0, 0, 0};
        hiddenSelections[] = {"Camo1", "Camo2", "Camo3", "Camo4"};
        hiddenSelectionsTextures[] = {"\\ca\\air\\data\\mi8_body_g_vsr_co.paa", "ca\\air\\data\\mi8_det_g_co.paa", "ca\\air\\data\\clear_empty.paa", "ca\\air\\data\\mi8_decals_ca.paa"};
        ejectDeadGunner = 1;
        ejectDeadCargo = 1;
        ejectDeadDriver = 1;
        ejectDeadCommander = 1;
    };
    class An2_Base_EP1;
    class AN2_Ori: An2_Base_EP1
    {
        displayName = "AN2";
        scope = 2;
        side = 2;
        faction = "rth_copter_class";
        crew = "";
        typicalCargo[] = {};
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        weapons[] = {};
        magazines[] = {};
        gunnerHasFlares = 0;
        commanderCanSee = "2+16+32";
        gunnerCanSee = "2+16+32";
        driverCanSee = "2+16+32";
        transportMaxMagazines = 350;
        transportMaxWeapons = 70;
        transportMaxBackpacks = 5;
        hiddenSelections[] = {"Camo1", "Camo2", "Camo3"};
        hiddenSelectionsTextures[] = {"ca\\Air_E\\An2\\Data\\an2_1_A_CO", "ca\\Air_E\\An2\\Data\\an2_2_A_CO", "ca\\Air_E\\An2\\Data\\an2_wings_A_CO"};
    };
    class AH6_Base_EP1;
    class AH6X_Ori: AH6_Base_EP1
    {
        isUav = 0;
        accuracy = 2;
        scope = 2;
        displayName = "AH6X";
        faction = "rth_copter_class";
        gunnerHasFlares = 0;
        commanderCanSee = "2+16+32";
        gunnerCanSee = "2+16+32";
        driverCanSee = "2+16+32";
        model = "\\ca\\air_e\\ah6j\\ah6x";
        picture = "\\ca\\air_e\\data\\UI\\Picture_ah6x_CA.paa";
        icon = "\\ca\\air_e\\data\\UI\\Icon_ah6x_CA.paa";
        side = 2;
        radarType = 0;
        camouflage = 4;
        audible = 6;
        crew = "";
        typicalCargo[] = {};
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
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
                animPeriod = 9.99999975e-06;
                initPhase = 0;
            };
            class FLIR_turret
            {
                source = "user";
                animPeriod = 9.99999975e-06;
                initPhase = 0;
            };
        };
        class Sounds
        {
            class Engine
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_engine_ext_1", 1.56228006, 1, 180};
                frequency = "rotorSpeed";
                volume = "camPos*((rotorSpeed-0.72)*4)";
            };
            class RotorLowOut
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_rotor_ext_1", 1.56228006, 1, 200};
                frequency = "rotorSpeed";
                volume = "camPos*(0 max (rotorSpeed-0.1))";
                cone[] = {1.79999995, 3.1400001, 2, 0.899999976};
            };
            class RotorHighOut
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_rotor_ext_high_1", 0.77828002, 1, 210};
                frequency = "rotorSpeed";
                volume = "camPos*10*(0 max (rotorThrust-0.95))";
                cone[] = {1.79999995, 3.1400001, 2, 0.899999976};
            };
            class EngineIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_engine_ext_1", 0.658930004, 1};
                frequency = "rotorSpeed";
                volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
            };
            class RotorLowIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_rotor_ext_1", 0.658930004, 1};
                frequency = "rotorSpeed";
                volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
            };
            class RotorHighIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_rotor_ext_high_1", 0.895259976, 1};
                frequency = "rotorSpeed";
                volume = "(1-camPos)*3*(rotorThrust-0.9)";
            };
        };
        class Turrets
        {
        };
        hiddenSelections[] = {"camo1"};
        hiddenSelectionsTextures[] = {"ca\\air_e\\ah6j\\data\\ah6_merge1_co.paa"};
        ejectDeadGunner = 1;
        ejectDeadCargo = 1;
        ejectDeadDriver = 1;
        ejectDeadCommander = 1;
        armor = 27;
        class HitPoints
        {
            class HitHull
            {
                armor = 1;
                material = 51;
                name = "NEtrup";
                visual = "trup";
                passThrough = 1;
            };
            class HitEngine
            {
                armor = 0.5;
                material = 51;
                name = "motor";
                visual = "motor";
                passThrough = 1;
            };
            class HitAvionics
            {
                armor = 0.25;
                material = 51;
                name = "elektronika";
                visual = "elektronika";
                passThrough = 1;
            };
            class HitVRotor
            {
                armor = 0.400000006;
                material = 51;
                name = "mala vrtule";
                visual = "mala vrtule staticka";
                passThrough = 0.300000012;
            };
            class HitHRotor
            {
                armor = 0.400000006;
                material = 51;
                name = "velka vrtule";
                visual = "velka vrtule staticka";
                passThrough = 0.100000001;
            };
            class HitGlass1
            {
                armor = 0.600000024;
                material = -1;
                name = "glass1";
                visual = "glass1";
                passThrough = 0;
            };
            class HitGlass2
            {
                armor = 0.600000024;
                material = -1;
                name = "glass2";
                visual = "glass2";
                passThrough = 0;
            };
            class HitGlass3
            {
                armor = 0.600000024;
                material = -1;
                name = "glass3";
                visual = "glass3";
                passThrough = 0;
            };
            class HitGlass4
            {
                armor = 0.600000024;
                material = -1;
                name = "glass4";
                visual = "glass4";
                passThrough = 0;
            };
            class HitRGlass
            {
                armor = 0.100000001;
                material = 51;
                name = "sklo predni P";
                visual = "sklo predni P";
                passThrough = 0;
            };
            class HitLGlass
            {
                armor = 0.100000001;
                material = 51;
                name = "sklo predni L";
                visual = "sklo predni L";
                passThrough = 0;
            };
        };
    };
    class MH6J_Ori: AH6_Base_EP1
    {
        isUav = 0;
        accuracy = 2;
        scope = 2;
        displayName = "MH6J";
        faction = "rth_copter_class";
        gunnerHasFlares = 0;
        commanderCanSee = "2+16+32";
        gunnerCanSee = "2+16+32";
        driverCanSee = "2+16+32";
        model = "\\ca\\air_e\\ah6j\\mh6j";
        picture = "\\ca\\air_e\\data\\UI\\Picture_mh6j_CA.paa";
        icon = "\\ca\\air_e\\data\\UI\\Icon_mh6j_CA.paa";
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
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        enableManualFire = 0;
        weapons[] = {};
        magazines[] = {};
        transportMaxMagazines = 70;
        transportMaxWeapons = 20;
        transportMaxBackpacks = 2;
        class Turrets
        {
        };
        class Sounds
        {
            class Engine
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_engine_ext_1", 1.56228006, 1, 180};
                frequency = "rotorSpeed";
                volume = "camPos*((rotorSpeed-0.72)*4)";
            };
            class RotorLowOut
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_rotor_ext_1", 1.56228006, 1, 200};
                frequency = "rotorSpeed";
                volume = "camPos*(0 max (rotorSpeed-0.1))";
                cone[] = {1.79999995, 3.1400001, 2, 0.899999976};
            };
            class RotorHighOut
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_rotor_ext_high_1", 0.77828002, 1, 210};
                frequency = "rotorSpeed";
                volume = "camPos*10*(0 max (rotorThrust-0.95))";
                cone[] = {1.79999995, 3.1400001, 2, 0.899999976};
            };
            class EngineIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_engine_ext_1", 0.658930004, 1};
                frequency = "rotorSpeed";
                volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
            };
            class RotorLowIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_rotor_ext_1", 0.658930004, 1};
                frequency = "rotorSpeed";
                volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
            };
            class RotorHighIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\AH6\\ah6_rotor_ext_high_1", 0.895259976, 1};
                frequency = "rotorSpeed";
                volume = "(1-camPos)*3*(rotorThrust-0.9)";
            };
        };
        hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[] = {"ca\\air_e\\ah6j\\data\\ah6_merge1_co.paa", "ca\\air_e\\ah6j\\data\\default_co.paa"};
        ejectDeadGunner = 1;
        ejectDeadCargo = 1;
        ejectDeadDriver = 1;
        ejectDeadCommander = 1;
        class HitPoints
        {
            class HitHull
            {
                armor = 1;
                material = 51;
                name = "NEtrup";
                visual = "trup";
                passThrough = 1;
            };
            class HitEngine
            {
                armor = 0.25;
                material = 51;
                name = "motor";
                visual = "motor";
                passThrough = 1;
            };
            class HitAvionics
            {
                armor = 0.150000006;
                material = 51;
                name = "elektronika";
                visual = "elektronika";
                passThrough = 1;
            };
            class HitVRotor
            {
                armor = 0.300000012;
                material = 51;
                name = "mala vrtule";
                visual = "mala vrtule staticka";
                passThrough = 0.300000012;
            };
            class HitHRotor
            {
                armor = 0.200000003;
                material = 51;
                name = "velka vrtule";
                visual = "velka vrtule staticka";
                passThrough = 0.100000001;
            };
            class HitGlass1
            {
                armor = 0.600000024;
                material = -1;
                name = "glass1";
                visual = "glass1";
                passThrough = 0;
            };
            class HitGlass2
            {
                armor = 0.600000024;
                material = -1;
                name = "glass2";
                visual = "glass2";
                passThrough = 0;
            };
            class HitGlass3
            {
                armor = 0.600000024;
                material = -1;
                name = "glass3";
                visual = "glass3";
                passThrough = 0;
            };
            class HitGlass4
            {
                armor = 0.600000024;
                material = -1;
                name = "glass4";
                visual = "glass4";
                passThrough = 0;
            };
            class HitRGlass
            {
                armor = 0.100000001;
                material = 51;
                name = "sklo predni P";
                visual = "sklo predni P";
                passThrough = 0;
            };
            class HitLGlass
            {
                armor = 0.100000001;
                material = 51;
                name = "sklo predni L";
                visual = "sklo predni L";
                passThrough = 0;
            };
        };
    };
    class MH60S_Ori: Helicopter
    {
        scope = 2;
        displayName = "MH60S";
        faction = "rth_copter_class";
        destrType = "DestructWreck";
        vehicleClass = "Air";
        model = "\\Ca\\Air_E\\UH60M\\UH60M.p3d";
        mapSize = 17;
        picture = "\\ca\\air\\data\\ico\\MH_60mg_CA.paa";
        Icon = "\\ca\\air\\data\\map_ico\\icomap_MH60mg_CA.paa";
        side = 2;
        crew = "";
        accuracy = 1.5;
        attendant = 0;
        maxSpeed = 270;
        armor = 30;
        radarType = 0;
        damageResistance = 0.00242000003;
        mainRotorSpeed = 1.20000005;
        backRotorSpeed = 6.0999999;
        soundGetIn[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\open_close", 0.316228002, 1};
        soundGetOut[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\open_close", 0.316228002, 1, 40};
        soundEngineOnInt[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_start_int", 0.446684003, 1};
        soundEngineOnExt[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_start_ext", 0.446684003, 1, 700};
        soundEngineOffInt[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_stop_int", 0.446684003, 1};
        soundEngineOffExt[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_stop_ext", 0.446684003, 1, 700};
        class Sounds
        {
            class Engine
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_engine_ext_2", 1, 0.800000012, 800};
                frequency = "rotorSpeed";
                volume = "camPos*((rotorSpeed-0.72)*4)";
            };
            class RotorLowOut
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_rotor_ext_1", 2.51188993, 1.10000002, 1400};
                frequency = "rotorSpeed";
                volume = "camPos*(0 max (rotorSpeed-0.1))";
                cone[] = {1.60000002, 3.1400001, 2, 0.5};
            };
            class RotorHighOut
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_rotor_high_ext_1", 2.51188993, 1.10000002, 1600};
                frequency = "rotorSpeed";
                volume = "camPos*10*(0 max (rotorThrust-0.9))";
                cone[] = {1.60000002, 3.1400001, 2, 0.5};
            };
            class EngineIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_engine_int_1", 1, 0.800000012};
                frequency = "rotorSpeed";
                volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
            };
            class RotorLowIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_rotor_int_1", 1.77828002, 1.10000002};
                frequency = "rotorSpeed";
                volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
            };
            class RotorHighIn
            {
                sound[] = {"Ca\\Sounds_E\\Air_E\\UH1H\\UH1H_rotor_high_int_1", 3.16228008, 1.10000002};
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
        threat[] = {0.300000012, 0, 0.400000006};
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
        class AnimationSources
        {
            class Gatling_1
            {
                source = "revolving";
                weapon = "M240_veh";
            };
            class Gatling_2
            {
                source = "revolving";
                weapon = "M240_veh_2";
            };
        };
        class Damage
        {
            tex[] = {};
            mat[] = {"ca\\Air_E\\UH60M\\Data\\uh60m_dust_filter.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_dust_filter.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_dust_filter_destruct.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_engine.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_engine.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_engine_destruct.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_fuselage.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_fuselage.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_fuselage_destruct.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_interior.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_interior.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_interior_destruct.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_navijak.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_navijak.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_navijak_destruct.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_glass.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_glass_damage.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_glass_damage.rvmat", "ca\\data\\data\\default.rvmat", "ca\\data\\data\\default.rvmat", "ca\\Air_E\\UH60M\\Data\\default_destruct.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_engine_MEV.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_engine_MEV.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_engine_MEV_destruct.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_fuselage_MEV.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_fuselage_MEV.rvmat", "ca\\Air_E\\UH60M\\Data\\uh60m_fuselage_MEV_destruct.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default_destruct.rvmat"};
        };
        enableManualFire = 0;
        hiddenSelections[] = {"camo1", "camo2", "camo3"};
        hiddenSelectionsTextures[] = {"ca\\air_e\\uh60m\\data\\uh60m_fuselage_co.paa", "ca\\air_e\\uh60m\\data\\uh60m_engine_co.paa", "ca\\air_e\\uh60m\\data\\default_co.paa"};
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                body = "mainTurret";
                gun = "mainGun";
                minElev = -80;
                maxElev = 25;
                initElev = -80;
                minTurn = 30;
                maxTurn = 150;
                initTurn = 90;
                soundServo[] = {"", 0.00999999978, 1};
                stabilizedInAxes = "StabilizedInAxesNone";
                gunBeg = "muzzle_1";
                gunEnd = "chamber_1";
                weapons[] = {"M240_veh"};
                magazines[] = {"100Rnd_762x51_M240", "100Rnd_762x51_M240", "100Rnd_762x51_M240"};
                gunnerName = "$STR_POSITION_CREWCHIEF";
                gunnerOpticsModel = "\\ca\\weapons\\optika_empty";
                gunnerOutOpticsShowCursor = 1;
                gunnerOpticsShowCursor = 1;
                gunnerAction = "UH60M_Gunner_EP1";
                gunnerInAction = "UH60M_Gunner_EP1";
                gunnerCompartments = "Compartment1";
                primaryGunner = 1;
                commanding = -3;
                class ViewOptics
                {
                    initAngleX = 0;
                    minAngleX = -30;
                    maxAngleX = 30;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = 0.699999988;
                    minFov = 0.25;
                    maxFov = 1.10000002;
                };
            };
            class RightDoorGun: MainTurret
            {
                body = "Turret_2";
                gun = "Gun_2";
                animationSourceBody = "Turret_2";
                animationSourceGun = "Gun_2";
                animationSourceHatch = "";
                selectionFireAnim = "zasleh_1";
                proxyIndex = 2;
                gunnerName = "$STR_POSITION_DOORGUNNER";
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
        class Reflectors
        {
            class Left
            {
                color[] = {0.800000012, 0.800000012, 1, 1};
                ambient[] = {0.0700000003, 0.0700000003, 0.0700000003, 1};
                position = "L svetlo";
                direction = "konec L svetla";
                hitpoint = "L svetlo";
                selection = "L svetlo";
                size = 1;
                brightness = 1;
            };
            class Right
            {
                color[] = {0.800000012, 0.800000012, 1, 1};
                ambient[] = {0.0700000003, 0.0700000003, 0.0700000003, 1};
                position = "P svetlo";
                direction = "konec P svetla";
                hitpoint = "P svetlo";
                selection = "P svetlo";
                size = 1;
                brightness = 1;
            };
        };
    };
    class HC3_Merlin_Ori: Helicopter
    {
        scope = 2;
        side = 2;
        displayname = "HC3 Merlin";
        faction = "rth_copter_class";
        model = "\\Ca\\air_d_baf\\MerlinHC3_BAF";
        picture = "\\Ca\\air_d_baf\\Data\\UI\\picture_merlin_ca.paa";
        icon = "\\Ca\\air_d_baf\\Data\\UI\\icon_merlin_ca.paa";
        mapSize = 20;
        crew = "";
        typicalCargo[] = {};
        driverAction = "Merlin_Pilot_BAF";
        cargoIsCoDriver[] = {1, 0};
        GetInAction = "GetInHigh";
        GetOutAction = "GetOutHigh";
        cargoAction[] = {"Merlin_Cargo_BAF", "Merlin_Cargo01_BAF", "Merlin_Cargo_BAF", "Merlin_Cargo01_BAF", "Merlin_Cargo01_BAF", "Merlin_Cargo_BAF", "Merlin_Cargo01_BAF", "Merlin_Cargo_BAF", "Merlin_Cargo01_BAF", "Merlin_Cargo01_BAF", "Merlin_Cargo_BAF", "Merlin_Cargo01_BAF", "Merlin_Cargo01_BAF", "Merlin_Cargo_BAF", "Merlin_Cargo01_BAF", "Merlin_Cargo_BAF", "Merlin_Cargo01_BAF"};
        memoryPointsGetInCargo[] = {"pos codriver", "pos cargo"};
        memoryPointsGetInCargoDir[] = {"pos codriver dir", "pos cargo dir"};
        transportSoldier = 17;
        radarType = 0;
        enableManualFire = 0;
        class Reflectors
        {
            class Light
            {
                color[] = {0.800000012, 0.800000012, 1, 1};
                ambient[] = {0.0700000003, 0.0700000003, 0.0700000003, 1};
                position = "light_1_1_pos";
                direction = "light_1_1_dir";
                hitpoint = "light_1_1_pos";
                selection = "L svetlo";
                size = 1;
                brightness = 1;
            };
        };
        class MarkerLights
        {
            class GreenStill
            {
                name = "light_nav_right";
                color[] = {0.00600000005, 0.119999997, 0.00600000005, 1};
                ambient[] = {0.00999999978, 0.100000001, 0.00999999978, 1};
                brightness = 0.00100000005;
                blinking = 0;
            };
            class WhiteBlinking
            {
                name = "light_nav_top";
                color[] = {0.0388000011, 0.0388000011, 0.0388000011, 1};
                ambient[] = {0.0299999993, 0.023, 0.0055999998, 1};
                brightness = 0.00100000005;
                blinking = 1;
            };
            class RedStill
            {
                name = "light_nav_left";
                color[] = {0.119999997, 0.00600000005, 0.00600000005, 1};
                ambient[] = {0.100000001, 0.00999999978, 0.00999999978, 1};
                brightness = 0.00100000005;
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
                radius = 3.5999999;
                onlyForplayer = 0;
                condition = "this animationPhase \"dvere_p\" > 0.5 AND Alive(this)";
                statement = "this animate [\"dvere_p\",0];this animate [\"dvere_p_pop\",0];";
            };
            class CloseRdoor
            {
                displayName = "$STR_BAF_CFGVEHICLES_BAF_MERLIN_HC3_D_USERACTIONS_CLOSERDOOR0";
                position = "axis_door_side_pop";
                radius = 3.5999999;
                onlyForplayer = 0;
                condition = "this animationPhase \"dvere_p\" < 0.5 AND Alive(this)";
                statement = "this animate [\"dvere_p\",1];this animate [\"dvere_p_pop\",1];";
            };
            class OpenLdoor
            {
                displayName = "$STR_BAF_CFGVEHICLES_BAF_MERLIN_HC3_D_USERACTIONS_OPENLDOOR0";
                position = "axis_door_crew_pop";
                radius = 3.5999999;
                onlyForplayer = 0;
                condition = "this animationPhase \"dvere_l\" > 0.5 AND Alive(this)";
                statement = "this animate [\"dvere_l\",0];this animate [\"dvere_l_pop\",0];";
            };
            class CloseLdoor
            {
                displayName = "$STR_BAF_CFGVEHICLES_BAF_MERLIN_HC3_D_USERACTIONS_CLOSELDOOR0";
                position = "axis_door_crew_pop";
                radius = 3.5999999;
                onlyForplayer = 0;
                condition = "this animationPhase \"dvere_l\" < 0.5 AND Alive(this)";
                statement = "this animate [\"dvere_l\",1];this animate [\"dvere_l_pop\",1];";
            };
        };
        maxSpeed = 309;
        accuracy = 1.5;
        cost = 10000000;
        armor = 40;
        damageResistance = 0.00355000002;
        vehicleClass = "Air";
        laserScanner = 1;
        MainRotorSpeed = 1;
        backRotorSpeed = 1;
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
        class Turrets: Turrets
        {
        };
        selectionFireAnim = "zasleh";
        threat[] = {0.400000006, 0, 0};
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
                armor = 0.150000006;
                material = 51;
                name = "elektronika";
                visual = "elektronika";
                passThrough = 0.200000003;
            };
            class HitVRotor
            {
                armor = 0.300000012;
                material = 51;
                name = "mala vrtule";
                visual = "mala vrtule staticka";
                passThrough = 0.100000001;
            };
            class HitHRotor
            {
                armor = 0.200000003;
                material = 51;
                name = "velka vrtule";
                visual = "velka vrtule staticka";
                passThrough = 0.100000001;
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
            mat[] = {"ca\\air_d_BAF\\Data\\merlin_int_01.rvmat", "ca\\air_d_BAF\\Data\\merlin_int_01_damage.rvmat", "ca\\air_d_BAF\\Data\\merlin_int_01_destruct.rvmat", "ca\\air_d_BAF\\Data\\merlin_int_02.rvmat", "ca\\air_d_BAF\\Data\\merlin_int_02_damage.rvmat", "ca\\air_d_BAF\\Data\\merlin_int_02_destruct.rvmat", "ca\\air_d_BAF\\Data\\Merlin_glass.rvmat", "ca\\air_d_BAF\\Data\\Merlin_glass_damage.rvmat", "ca\\air_d_BAF\\Data\\Merlin_glass_damage.rvmat", "ca\\air_d_BAF\\Data\\MerlinHc3_2_BAF.rvmat", "ca\\air_d_BAF\\Data\\MerlinHc3_2_BAF_damage.rvmat", "ca\\air_d_BAF\\Data\\MerlinHc3_2_BAF_destruct.rvmat", "ca\\air_d_BAF\\Data\\MerlinHc3_1_BAF.rvmat", "ca\\air_d_BAF\\Data\\MerlinHc3_1_BAF_damage.rvmat", "ca\\air_d_BAF\\Data\\MerlinHc3_1_BAF_destruct.rvmat"};
        };
        soundGetIn[] = {"Ca\\sounds_baf\\air\\getin", 0.316227764, 1};
        soundGetOut[] = {"Ca\\sounds_baf\\air\\getin", 0.316227764, 1, 40};
        soundDammage[] = {"Ca\\sounds_baf\\air\\int-alarm_loop", 0.562341332, 1};
        soundEngineOnInt[] = {"Ca\\sounds_baf\\air\\uk_start_int_1", 0.100000001, 1.10000002};
        soundEngineOnExt[] = {"Ca\\sounds_baf\\air\\uk_start_ext_1", 0.562341332, 1.10000002, 800};
        soundEngineOffInt[] = {"\\Ca\\sounds_baf\\air\\uk_stop_int_1", 0.100000001, 1.10000002};
        soundEngineOffExt[] = {"Ca\\sounds_baf\\air\\uk_stop_ext_2", 0.562341332, 1.10000002, 800};
        soundLocked[] = {"Ca\\sounds_baf\\air\\int-alarm_loop", 0.000316227757, 2};
        soundIncommingMissile[] = {"Ca\\sounds_baf\\air\\int-alarm_loop", 0.000316227757, 4};
        class Sounds
        {
            class Engine
            {
                sound[] = {"Ca\\sounds_baf\\air\\uk_engine_ext_3", 3.1622777, 1, 1000};
                frequency = "rotorSpeed";
                volume = "camPos*((rotorSpeed-0.72)*4)";
            };
            class RotorLowOut
            {
                sound[] = {"\\Ca\\sounds_baf\\air\\uk_rotor_4l", 3.1622777, 1, 1200};
                frequency = "rotorSpeed";
                volume = "camPos*(0 max (rotorSpeed-0.1))";
                cone[] = {1.79999995, 3.1400001, 2, 0.899999976};
            };
            class RotorHighOut
            {
                sound[] = {"\\Ca\\sounds_baf\\air\\uk_rotor_4h_swist", 1.77827942, 1, 1300};
                frequency = "rotorSpeed";
                volume = "camPos*10*(0 max (rotorThrust-0.95))";
                cone[] = {1.79999995, 3.1400001, 2, 0.899999976};
            };
            class EngineIn
            {
                sound[] = {"\\Ca\\sounds_baf\\air\\uk_engine_int_1", 0.562341332, 1};
                frequency = "rotorSpeed";
                volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
            };
            class RotorLowIn
            {
                sound[] = {"Ca\\sounds_baf\\air\\uk_rotor_4l_int", 1.77827942, 1};
                frequency = "rotorSpeed";
                volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
            };
            class RotorHighIn
            {
                sound[] = {"Ca\\sounds_baf\\air\\uk_rotor_4h_int", 1.77827942, 1};
                frequency = "rotorSpeed";
                volume = "(1-camPos)*3*(rotorThrust-0.9)";
            };
        };
        supplyRadius = 5;
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
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
        model = "\\Ca\\Air_PMC\\Ka60\\Ka60_PMC.p3d";
        icon = "\\Ca\\Air_PMC\\data\\ui\\Icon_ka60_PMC_ca.paa";
        picture = "\\Ca\\Air_PMC\\data\\ui\\picture_ka60_PMC_ca.paa";
        driverAction = "UH1H_Pilot_EP1";
        driverInAction = "UH1H_Pilot_EP1";
        transportSoldier = 8;
        cargoAction[] = {"UH1H_Cargo_EP1", "UH60_Cargo02"};
        cargoIsCoDriver[] = {1, 0};
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
            class HitGlass1: HitGlass1
            {
                armor = 0.119999997;
            };
            class HitGlass2: HitGlass2
            {
                armor = 0.119999997;
            };
            class HitGlass3: HitGlass3
            {
                armor = 0.119999997;
            };
            class HitGlass4: HitGlass4
            {
                armor = 0.119999997;
            };
            class HitGlass5: HitGlass5
            {
                armor = 0.119999997;
            };
            class HitGlass6: HitGlass6
            {
                armor = 0.119999997;
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
                soundServo[] = {"", 0.00999999978, 1};
                animationSourceHatch = "";
                stabilizedInAxes = "StabilizedInAxesNone";
                gunBeg = "muzzle_1";
                gunEnd = "chamber_1";
                weapons[] = {"PKT_spec"};
                maxHorizontalRotSpeed = 1.60000002;
                maxVerticalRotSpeed = 1.60000002;
                magazines[] = {"100Rnd_762x54_PK", "100Rnd_762x54_PK", "100Rnd_762x54_PK"};
                gunnerName = "$STR_POSITION_DOORGUNNER";
                gunnerForceOptics = 1;
                gunnerAction = "Mi8_Gunner";
                gunnerInAction = "Mi8_Gunner";
                commanding = -3;
                primaryGunner = 1;
                discreteDistance[] = {500, 600, 700, 800, 900};
                discreteDistanceInitIndex = 1;
                gunnerOpticsModel = "\\ca\\weapons\\2Dscope_Pecheneg";
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
                        initFov = 0.100000001;
                        minFov = 0.100000001;
                        maxFov = 0.100000001;
                        visionMode[] = {"Normal", "NVG"};
                        gunnerOpticsModel = "\\ca\\weapons\\2Dscope_Pecheneg";
                    };
                    class Medium: Wide
                    {
                        opticsDisplayName = "M";
                        initFov = 0.063000001;
                        minFov = 0.063000001;
                        maxFov = 0.063000001;
                        gunnerOpticsModel = "\\ca\\weapons\\2Dscope_Pecheneg";
                    };
                    class Narrow: Wide
                    {
                        opticsDisplayName = "N";
                        gunnerOpticsModel = "\\ca\\weapons\\2Dscope_Pecheneg";
                        initFov = 0.0189999994;
                        minFov = 0.0189999994;
                        maxFov = 0.0189999994;
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
                        initFov = 1.10000002;
                        minFov = 0.133000001;
                        maxFov = 1.10000002;
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
                    initFov = 0.699999988;
                    minFov = 0.25;
                    maxFov = 1.10000002;
                };
                gunnerCompartments = "Compartment1";
            };
        };
        class Damage
        {
            tex[] = {};
            mat[] = {"Ca\\Air_PMC\\Ka60\\Data\\ka60_ext.rvmat", "Ca\\Air_PMC\\Ka60\\Data\\ka60_ext_damage.rvmat", "Ca\\Air_PMC\\Ka60\\Data\\ka60_ext_destruct.rvmat", "Ca\\Air_PMC\\Ka60\\Data\\ka60_glass.rvmat", "Ca\\Air_PMC\\Ka60\\Data\\ka60_glass_damage.rvmat", "Ca\\Air_PMC\\Ka60\\Data\\ka60_glass_destruct.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default_destruct.rvmat"};
        };
        soundGetIn[] = {"Ca\\Sounds_PMC\\Air_PMC\\Ka_door", 0.316227764, 1};
        soundGetOut[] = {"Ca\\Sounds_PMC\\Air_PMC\\Ka_door", 0.316227764, 1, 40};
        soundDammage[] = {"Ca\\Sounds_PMC\\Air_PMC\\int-alarm_loop", 0.562341332, 1};
        soundEngineOnInt[] = {"Ca\\Sounds_PMC\\Air_PMC\\Ka_start_int_1", 0.100000001, 1};
        soundEngineOnExt[] = {"Ca\\Sounds_PMC\\Air_PMC\\Ka_start_ext_1", 0.562341332, 1, 800};
        soundEngineOffInt[] = {"Ca\\Sounds_PMC\\Air_PMC\\Ka_stop_int_1", 0.100000001, 1};
        soundEngineOffExt[] = {"Ca\\Sounds_PMC\\Air_PMC\\Ka_stop_ext_1", 0.562341332, 1, 800};
        class Sounds
        {
            class Engine
            {
                sound[] = {"Ca\\Sounds_PMC\\Air_PMC\\Ka_engi_r_ext", 3.1622777, 1.39999998, 800};
                frequency = "rotorSpeed";
                volume = "camPos*((rotorSpeed-0.72)*4)";
            };
            class RotorLowOut
            {
                sound[] = {"Ca\\Sounds_PMC\\Air_PMC\\KA_rotor_orig", 3.1622777, 1, 1400};
                frequency = "rotorSpeed";
                volume = "camPos*(0 max (rotorSpeed-0.1))";
                cone[] = {1.79999995, 3.1400001, 2, 0.899999976};
            };
            class RotorHighOut
            {
                sound[] = {"Ca\\Sounds_PMC\\Air_PMC\\KA_rotor_orig_high_swist", 5.62341309, 1, 1500};
                frequency = "rotorSpeed";
                volume = "camPos*10*(0 max (rotorThrust-0.95))";
                cone[] = {1.10000002, 3.1400001, 2, 0.899999976};
            };
            class EngineIn
            {
                sound[] = {"Ca\\Sounds_PMC\\Air_PMC\\Ka_engi_int_1", 3.1622777, 1};
                frequency = "rotorSpeed";
                volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
            };
            class RotorLowIn
            {
                sound[] = {"Ca\\Sounds_PMC\\Air_PMC\\KA_rotor_orig", 0.562341332, 1};
                frequency = "rotorSpeed";
                volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
            };
            class RotorHighIn
            {
                sound[] = {"Ca\\Sounds_PMC\\Air_PMC\\KA_rotor_orig_high_swist", 0.316227764, 1};
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
                animPeriod = 9.99999975e-06;
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
    class Mi171ShCZ_Ori: Mi17_base
    {
        scope = 2;
        side = 2;
        model = "\\ca\\Air_E\\Mi17\\Mi_171";
        picture = "\\ca\\air\\data\\ico\\mi17_HIP_CA.paa";
        Icon = "\\ca\\air\\data\\map_ico\\icomap_mi17_CA.paa";
        enableSweep = 0;
        displayName = "Mi-171Sh";
        faction = "rth_copter_class";
        crew = "";
        armor = 20;
        typicalCargo[] = {};
        weapons[] = {};
        magazines[] = {};
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        transportMaxMagazines = 250;
        transportMaxWeapons = 100;
        transportMaxBackpacks = 10;
        radarType = 0;
        threat[] = {1, 1, 1};
        LockDetectionSystem = 0;
        IncommingMisslieDetectionSystem = 0;
        hiddenSelections[] = {"Camo1", "Camo2", "Camo3", "Camo4"};
        hiddenSelectionsTextures[] = {"\\CA\\air_E\\data\\mi17_body_ACR_CO.paa", "\\CA\\air_E\\data\\mi17_det_ACR_CO.paa", "\\ca\\air_E\\Data\\mi17_decals2_ACR_CA.paa", "\\ca\\air\\data\\mi8_decals_ca.paa"};
        class UserActions
        {
        };
        class Turrets: Turrets
        {
            class LeftTurret: MainTurret
            {
                proxyIndex = 2;
                primaryGunner = 0;
                gunnerName = "crew chief";
                minElev = -50;
                maxElev = 30;
                initElev = 11;
                minTurn = 20;
                maxTurn = 155;
                initTurn = 80;
                gunnerCompartments = "Compartment1";
                commanding = -3;
                magazines[] = {"100Rnd_762x54_PK", "100Rnd_762x54_PK", "100Rnd_762x54_PK"};
            };
            class BackTurret: BackTurret
            {
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
                magazines[] = {"100Rnd_762x54_PK", "100Rnd_762x54_PK", "100Rnd_762x54_PK"};
            };
            class RightTurret: MainTurret
            {
                proxyIndex = 1;
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
                magazines[] = {"100Rnd_762x54_PK", "100Rnd_762x54_PK", "100Rnd_762x54_PK"};
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
                animPeriod = 1.00000001e-07;
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
    class HMMWV_Ori: HMMWV_Base
    {
        scope = 2;
        accuracy = 0.0199999996;
        camouflage = 2;
        picture = "\\Ca\\wheeled\\data\\ico\\HMMWV_CA.paa";
        Icon = "\\Ca\\wheeled\\data\\map_ico\\icomap_hmwv_CA.paa";
        mapSize = 5;
        displayName = "HMMWV US";
        hasGunner = 0;
        armor = 50;
        class Turrets
        {
        };
        class Damage
        {
            tex[] = {};
            mat[] = {"ca\\wheeled\\hmmwv\\data\\hmmwv_details.rvmat", "Ca\\wheeled\\HMMWV\\data\\hmmwv_details_damage.rvmat", "Ca\\wheeled\\HMMWV\\data\\hmmwv_details_destruct.rvmat", "ca\\wheeled\\hmmwv\\data\\hmmwv_body.rvmat", "Ca\\wheeled\\HMMWV\\data\\hmmwv_body_damage.rvmat", "Ca\\wheeled\\HMMWV\\data\\hmmwv_body_destruct.rvmat", "ca\\wheeled\\hmmwv\\data\\hmmwv_clocks.rvmat", "ca\\wheeled\\hmmwv\\data\\hmmwv_clocks.rvmat", "ca\\wheeled\\data\\hmmwv_clocks_destruct.rvmat", "ca\\wheeled\\HMMWV\\data\\hmmwv_glass.rvmat", "ca\\wheeled\\HMMWV\\data\\hmmwv_glass_Half_D.rvmat", "ca\\wheeled\\HMMWV\\data\\hmmwv_glass_Half_D.rvmat", "ca\\wheeled\\HMMWV\\data\\hmmwv_glass_in.rvmat", "ca\\wheeled\\HMMWV\\data\\hmmwv_glass_in_Half_D.rvmat", "ca\\wheeled\\HMMWV\\data\\hmmwv_glass_in_Half_D.rvmat"};
        };
        hiddenSelections[] = {"Camo1"};
        hiddenSelectionsTextures[] = {"\\origins_pack\\vehicles\\skins\\hmmwv\\hmmwv_telo_co.paa"};
        faction = "rth_copter_class";
        crew = "";
        typicalCargo[] = {};
        weapons[] = {};
        magazines[] = {};
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        transportMaxMagazines = 150;
        transportMaxWeapons = 20;
        transportMaxBackpacks = 5;
        model = "ca\\wheeled_E\\HMMWV\\HMMWV";
    };
    class Pickup_PK_base;
    class Pickup_PK_Ori: Pickup_PK_base
    {
        scope = 2;
        side = 2;
        displayName = "Pickup PK";
        faction = "rth_copter_class";
        crew = "";
        typicalCargo[] = {};
        weapons[] = {};
        magazines[] = {};
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        hiddenSelectionsTextures[] = {"\\ca\\wheeled\\datsun_armed\\data\\datsun_trup3_CO.paa"};
        transportMaxMagazines = 150;
        transportMaxWeapons = 20;
        class Damage
        {
            tex[] = {};
            mat[] = {"ca\\wheeled\\hilux_armed\\data\\detailmapy\\coyota_armed.rvmat", "ca\\wheeled\\hilux_armed\\data\\detailmapy\\coyota_armed.rvmat", "ca\\wheeled\\hilux_armed\\data\\detailmapy\\coyota_armed_destruct.rvmat", "ca\\weapons\\data\\dshk.rvmat", "ca\\weapons\\data\\dshk.rvmat", "ca\\weapons\\data\\dshk_destruct.rvmat", "ca\\weapons\\data\\tripod_dshk.rvmat", "ca\\weapons\\data\\tripod_dshk.rvmat", "ca\\wheeled\\hilux_armed\\data\\detailmapy\\tripod_dshk_destruct.rvmat", "ca\\weapons\\data\\pkm.rvmat", "ca\\weapons\\data\\pkm.rvmat", "ca\\weapons\\data\\pkm_destruct.rvmat", "ca\\wheeled\\data\\detailmapy\\datsun_interier.rvmat", "ca\\wheeled\\data\\detailmapy\\datsun_interier.rvmat", "ca\\wheeled\\data\\detailmapy\\datsun_interier_destruct.rvmat", "ca\\wheeled\\datsun_armed\\data\\detailmapy\\datsun_trup.rvmat", "ca\\wheeled\\datsun_armed\\data\\detailmapy\\datsun_trup.rvmat", "ca\\wheeled\\datsun_armed\\data\\detailmapy\\datsun_trup_destruct.rvmat", "ca\\wheeled\\datsun_armed\\data\\detailmapy\\datsun_trup_b.rvmat", "ca\\wheeled\\datsun_armed\\data\\detailmapy\\datsun_trup_b.rvmat", "ca\\wheeled\\datsun_armed\\data\\detailmapy\\datsun_trupb_destruct.rvmat", "ca\\wheeled\\data\\detailmapy\\coyota_kola.rvmat", "ca\\wheeled\\data\\detailmapy\\coyota_kola.rvmat", "ca\\wheeled\\data\\detailmapy\\coyota_kola_destruct.rvmat", "ca\\wheeled\\data\\detailmapy\\coyota_interier.rvmat", "ca\\wheeled\\data\\detailmapy\\coyota_interier.rvmat", "ca\\wheeled\\data\\detailmapy\\coyota_interier_destruct.rvmat", "ca\\wheeled\\data\\detailmapy\\auta_skla.rvmat", "ca\\wheeled\\data\\detailmapy\\auta_skla_damage.rvmat", "ca\\wheeled\\data\\detailmapy\\auta_skla_damage.rvmat", "ca\\wheeled\\data\\detailmapy\\auta_skla_in.rvmat", "ca\\wheeled\\data\\detailmapy\\auta_skla_in_damage.rvmat", "ca\\wheeled\\data\\detailmapy\\auta_skla_in_damage.rvmat"};
        };
    };
    class UAZ_MG_Base;
    class UAZ_MG_Ori: UAZ_MG_Base
    {
        scope = 2;
        side = 2;
        displayName = "UAZ MG";
        faction = "rth_copter_class";
        crew = "";
        typicalCargo[] = {};
        weapons[] = {};
        magazines[] = {};
        gunnerHasFlares = 0;
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        hiddenSelectionsTextures[] = {"\\ca\\wheeled\\data\\Uaz_main_002_CO.paa", "\\ca\\wheeled\\data\\uaz_mount_002_co.paa"};
        transportMaxMagazines = 150;
        transportMaxWeapons = 20;
    };
    class Offroad_DSHKM_base;
    class Offroad_MG_Ori: Offroad_DSHKM_base
    {
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
        hiddenSelectionsTextures[] = {"\\CA\\wheeled_E\\Hilux_Armed\\Data\\coyota_trup1_EINS_CO.paa"};
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        transportMaxMagazines = 150;
        transportMaxWeapons = 20;
    };
    class Land;
    class LandVehicle: Land
    {
        class NewTurret;
    };
    class Car: LandVehicle
    {
        class HitPoints
        {
            class HitLFWheel;
            class HitLBWheel;
            class HitLMWheel;
            class HitLF2Wheel;
            class HitRFWheel;
            class HitRBWheel;
            class HitRMWheel;
            class HitRF2Wheel;
            class HitGlass1;
            class HitGlass2;
            class HitGlass3;
        };
        class Turrets
        {
            class MainTurret: NewTurret
            {
                class ViewOptics;
            };
        };
        class AnimationSources;
    };
    class LandRover_Base_Ori: Car
    {
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
        terrainCoef = 3;
        turnCoef = 3;
        armor = 30;
        damageResistance = 0.0071899998;
        model = "\\ca\\wheeled_E\\LR\\LR";
        Picture = "\\CA\\wheeled_e\\Data\\UI\\Picture_lr_CA.paa";
        Icon = "\\CA\\wheeled_e\\Data\\UI\\Icon_lr_transport_CA.paa";
        MapSize = 6;
        outsideSoundFilter = 1;
        insideSoundCoef = 0.899999976;
        soundGear[] = {"", 5.62341011e-05, 1};
        soundGetIn[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_door", 1, 1, 30};
        soundGetOut[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_door", 1, 1, 30};
        soundEngineOnInt[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_int_start", 1, 1};
        soundEngineOnExt[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_ext_start", 1, 1, 100};
        soundEngineOffInt[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_int_stop", 1, 1};
        soundEngineOffExt[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_ext_stop", 1, 1, 100};
        buildCrash0[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_building_01", 0.707946002, 1, 150};
        buildCrash1[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_building_02", 0.707946002, 1, 150};
        buildCrash2[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_building_03", 0.707946002, 1, 150};
        buildCrash3[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_building_04", 0.707946002, 1, 150};
        soundBuildingCrash[] = {"buildCrash0", 0.25, "buildCrash1", 0.25, "buildCrash2", 0.25, "buildCrash3", 0.25};
        WoodCrash0[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_wood_01", 0.707946002, 1, 150};
        WoodCrash1[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_wood_02", 0.707946002, 1, 150};
        WoodCrash2[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_wood_03", 0.707946002, 1, 150};
        WoodCrash3[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_wood_04", 0.707946002, 1, 150};
        soundWoodCrash[] = {"woodCrash0", 0.25, "woodCrash1", 0.25, "woodCrash2", 0.25, "woodCrash3", 0.25};
        ArmorCrash0[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_vehicle_01", 0.707946002, 1, 150};
        ArmorCrash1[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_vehicle_02", 0.707946002, 1, 150};
        ArmorCrash2[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_vehicle_03", 0.707946002, 1, 150};
        ArmorCrash3[] = {"Ca\\sounds\\Vehicles\\Crash\\tank_vehicle_04", 0.707946002, 1, 150};
        soundArmorCrash[] = {"ArmorCrash0", 0.25, "ArmorCrash1", 0.25, "ArmorCrash2", 0.25, "ArmorCrash3", 0.25};
        class SoundEvents
        {
            class AccelerationIn
            {
                sound[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_int_acceleration", 0.562340975, 1};
                limit = 0.150000006;
                expression = "engineOn*(1-camPos)*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
            };
            class AccelerationOut
            {
                sound[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_ext_acceleration", 0.562340975, 1, 300};
                limit = 0.150000006;
                expression = "engineOn*camPos*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
            };
        };
        class Sounds
        {
            class Engine
            {
                sound[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_ext_low", 1.41253996, 0.600000024, 200};
                frequency = "(randomizer*0.05+0.95)*rpm";
                volume = "camPos*engineOn*((rpm factor[0.3, 0.4]) min (rpm factor[0.7, 0.5]))";
            };
            class EngineHighOut
            {
                sound[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_ext_high", 1.41253996, 0.600000024, 300};
                frequency = "(randomizer*0.05+0.95)*rpm";
                volume = "camPos*engineOn*(rpm factor[0.5, 0.8])";
            };
            class IdleOut
            {
                sound[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_ext_idle", 0.562340975, 1, 100};
                frequency = "1";
                volume = "engineOn*camPos*(rpm factor[0.4, 0])";
            };
            class TiresRockOut
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\ext\\ext-tires-rock2", 0.100000001, 1, 50};
                frequency = "1";
                volume = "camPos*rock*(speed factor[2, 20])";
            };
            class TiresSandOut
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\ext\\ext-tires-sand2", 0.100000001, 1, 50};
                frequency = "1";
                volume = "camPos*sand*(speed factor[2, 20])";
            };
            class TiresGrassOut
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\ext\\ext-tires-grass3", 0.100000001, 1, 50};
                frequency = "1";
                volume = "camPos*grass*(speed factor[2, 20])";
            };
            class TiresMudOut
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\ext\\ext-tires-mud2", 0.100000001, 1, 50};
                frequency = "1";
                volume = "camPos*mud*(speed factor[2, 20])";
            };
            class TiresGravelOut
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\ext\\ext-tires-gravel2", 0.100000001, 1, 50};
                frequency = "1";
                volume = "camPos*gravel*(speed factor[2, 20])";
            };
            class TiresAsphaltOut
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\ext\\ext-tires-asphalt3", 0.100000001, 1, 50};
                frequency = "1";
                volume = "camPos*asphalt*(speed factor[2, 20])";
            };
            class NoiseOut
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Noises\\ext\\noise3", 0.562340975, 1, 50};
                frequency = "1";
                volume = "camPos*(damper0 max 0.04)*(speed factor[0, 8])";
            };
            class EngineLowIn
            {
                sound[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_int_low", 1.41253996, 0.600000024};
                frequency = "(randomizer*0.05+0.95)*rpm";
                volume = "(1-camPos)*engineOn*((rpm factor[0.3, 0.4]) min (rpm factor[0.7, 0.5]))";
            };
            class EngineHighIn
            {
                sound[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_int_high", 1.41253996, 0.600000024};
                frequency = "(randomizer*0.05+0.95)*rpm";
                volume = "(1-camPos)*engineOn*(rpm factor[0.5, 0.8])";
            };
            class IdleIn
            {
                sound[] = {"\\ca\\Sounds_E\\Wheeled_E\\LandRover\\LRover_int_idle", 0.794327974, 1};
                frequency = "1";
                volume = "engineOn*(rpm factor[0.4, 0])*(1-camPos)";
            };
            class TiresRockIn
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\int\\int-tires-rock2", 0.100000001, 1};
                frequency = "1";
                volume = "(1-camPos)*rock*(speed factor[2, 20])";
            };
            class TiresSandIn
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\int\\int-tires-sand2", 0.100000001, 1};
                frequency = "1";
                volume = "(1-camPos)*sand*(speed factor[2, 20])";
            };
            class TiresGrassIn
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\int\\int-tires-grass3", 0.100000001, 1};
                frequency = "1";
                volume = "(1-camPos)*grass*(speed factor[2, 20])";
            };
            class TiresMudIn
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\int\\int-tires-mud2", 0.100000001, 1};
                frequency = "1";
                volume = "(1-camPos)*mud*(speed factor[2, 20])";
            };
            class TiresGravelIn
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\int\\int-tires-gravel2", 0.100000001, 1};
                frequency = "1";
                volume = "(1-camPos)*gravel*(speed factor[2, 20])";
            };
            class TiresAsphaltIn
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Tires\\int\\int-tires-asphalt3", 0.100000001, 1};
                frequency = "1";
                volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
            };
            class NoiseIn
            {
                sound[] = {"\\ca\\SOUNDS\\Vehicles\\Wheeled\\Noises\\int\\noise4", 0.316228002, 1};
                frequency = "1";
                volume = "(damper0 max 0.04)*(speed factor[0, 8])*(1-camPos)";
            };
            class Movement
            {
                sound = "soundEnviron";
                frequency = "1";
                volume = "0";
            };
        };
        class Library
        {
            libTextDesc = "$STR_EP1_LIB_LandRover";
        };
        transportSoldier = 7;
        driverAction = "LR_Driver_EP1";
        cargoAction[] = {"LR_Cargo01_EP1", "LR_Cargo02_EP1", "LR_Cargo03_EP1", "LR_Cargo05_EP1", "LR_Cargo04_EP1", "LR_Cargo02_EP1", "LR_Cargo03_EP1"};
        cargoIsCoDriver[] = {1, 0};
        class HitPoints: HitPoints
        {
            class HitEngine
            {
                armor = 2;
                material = -1;
                name = "motor";
                passThrough = 0;
            };
            class HitFuel
            {
                armor = 1;
                material = -1;
                name = "palivo";
                passThrough = 0;
            };
            class HitLFWheel: HitLFWheel
            {
                armor = 0.5;
            };
            class HitLBWheel: HitLBWheel
            {
                armor = 0.5;
            };
            class HitRFWheel: HitRFWheel
            {
                armor = 0.5;
            };
            class HitRBWheel: HitRBWheel
            {
                armor = 0.5;
            };
        };
        threat[] = {0, 0, 0};
        hiddenSelections[] = {"Camo1"};
        hiddenSelectionsTextures[] = {"\\ca\\wheeled_e\\lr\\data\\lr_base_ind_co.paa"};
    };
    class LandRover_MG_Ori: LandRover_Base_Ori
    {
        scope = 2;
        side = 2;
        faction = "rth_copter_class";
        model = "\\ca\\wheeled_E\\LR\\LR_MG";
        Picture = "\\CA\\wheeled_e\\Data\\UI\\Picture_lr_mg_CA.paa";
        Icon = "\\CA\\wheeled_e\\Data\\UI\\Icon_lr_mg_CA.paa";
        transportSoldier = 1;
        cargoAction[] = {"LR_Cargo01_EP1"};
        threat[] = {1, 0.100000001, 0.100000001};
        class Damage
        {
            tex[] = {};
            mat[] = {"ca\\wheeled_E\\LR\\Data\\LR_base.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_base_damage.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_base_destruct.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_glass.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_glass_damage.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_glass_destruct.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_MG-SPG9.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_MG-SPG9_damage.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_MG-SPG9_destruct.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default_destruct.rvmat"};
        };
        crew = "";
        typicalCargo[] = {};
        weapons[] = {};
        magazines[] = {};
        displayName = "LandRover MG";
        hiddenSelections[] = {"Camo1"};
        hiddenSelectionsTextures[] = {"\\ca\\wheeled_e\\lr\\data\\lr_base_ind_co.paa"};
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                body = "mainTurret";
                gun = "mainGun";
                hasGunner = 1;
                weapons[] = {"M2"};
                minElev = -25;
                maxElev = 60;
                soundServo[] = {"\\ca\\wheeled\\Data\\Sound\\servo3", 9.99999997e-07, 1};
                magazines[] = {"100Rnd_127x99_M2", "100Rnd_127x99_M2", "100Rnd_127x99_M2"};
                gunnerAction = "LR_Gunner_EP1";
                ejectDeadGunner = 1;
                castGunnerShadow = 1;
                stabilizedInAxes = "StabilizedInAxesNone";
            };
        };
        class AnimationSources: AnimationSources
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
    };
    class LandRover_Ori: LandRover_Base_Ori
    {
        scope = 2;
        side = 2;
        faction = "rth_copter_class";
        crew = "";
        typicalCargo[] = {};
        class Turrets
        {
        };
        class HitPoints: HitPoints
        {
            class HitGlass1: HitGlass1
            {
                armor = 0.150000006;
            };
            class HitGlass2: HitGlass2
            {
                armor = 0.100000001;
            };
            class HitGlass3: HitGlass3
            {
                armor = 0.100000001;
            };
        };
        class Damage
        {
            tex[] = {};
            mat[] = {"ca\\wheeled_E\\LR\\Data\\LR_base.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_base_damage.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_base_destruct.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_glass.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_glass_damage.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_glass_destruct.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_Special.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_Special_damage.rvmat", "ca\\wheeled_E\\LR\\Data\\LR_Special_destruct.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default.rvmat", "Ca\\Ca_E\\data\\default_destruct.rvmat"};
        };
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        class NVGMarkers
        {
            class NVGMarker01
            {
                name = "nvg_marker";
                color[] = {0.0299999993, 0.00300000003, 0.00300000003, 1};
                ambient[] = {0.00300000003, 0.000300000014, 0.000300000014, 1};
                brightness = 0.00100000005;
                blinking = 1;
            };
        };
        hiddenSelections[] = {"Camo1"};
        hiddenSelectionsTextures[] = {"\\ca\\wheeled_e\\lr\\data\\lr_base_ind_co.paa"};
    };
    class Kamaz_Base;
    class Kamaz_Ori: Kamaz_Base
    {
        scope = 2;
        side = 2;
        displayName = "$STR_DN_KAMAZ";
        faction = "rth_copter_class";
        crew = "";
        typicalCargo[] = {};
        weapons[] = {};
        magazines[] = {};
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        model = "\\ca\\wheeled2\\Kamaz\\Kamaz";
        cargoAction[] = {"Truck_Cargo01", "Truck_Cargo01", "Truck_Cargo02", "Truck_Cargo03", "Truck_Cargo02", "Truck_Cargo02", "Truck_Cargo03", "Truck_Cargo02", "Truck_Cargo03", "Truck_Cargo02", "Truck_Cargo02", "Truck_Cargo03"};
        transportMaxMagazines = 250;
        transportMaxWeapons = 50;
        transportMaxBackpacks = 10;
        hiddenSelections[] = {"Camo1", "Camo2"};
        hiddenSelectionsTextures[] = {"\\origins_pack\\vehicles\\skins\\kamaz\\kamaz_blue_co.paa", "\\origins_pack\\vehicles\\skins\\kamaz\\kamaz_back_white_co.paa"};
    };
    class KamazOpen_Ori: Kamaz_Base
    {
        scope = 2;
        side = 2;
        displayName = "$STR_DN_KAMAZ_OPEN";
        faction = "rth_copter_class";
        crew = "";
        typicalCargo[] = {};
        weapons[] = {};
        magazines[] = {};
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        model = "\\ca\\wheeled2\\Kamaz\\Kamaz_Open";
        picture = "\\Ca\\wheeled2\\data\\ui\\Picture_kamaz_open_CA.paa";
        Icon = "\\Ca\\wheeled2\\data\\ui\\Icon_kamaz_open_CA.paa";
        castCargoShadow = 1;
        transportMaxMagazines = 250;
        transportMaxWeapons = 50;
        transportMaxBackpacks = 10;
        hiddenSelections[] = {"Camo1", "Camo2"};
        hiddenSelectionsTextures[] = {"\\origins_pack\\vehicles\\skins\\kamaz\\kamaz_blue_co.paa", "\\origins_pack\\vehicles\\skins\\kamaz\\kamaz_back_white_co.paa"};
        class Library
        {
            libTextDesc = "$STR_LIB_KAMAZ_OPEN";
        };
    };
    class ATV_Base_EP1;
    class ATV_Ori: ATV_Base_EP1
    {
        scope = 2;
        side = 2;
        displayName = "ATV";
        faction = "rth_copter_class";
        crew = "";
        typicalCargo[] = {};
        weapons[] = {};
        magazines[] = {};
        class TransportMagazines
        {
        };
        class TransportWeapons
        {
        };
        transportMaxMagazines = 50;
        transportMaxWeapons = 10;
        transportMaxBackpacks = 2;
    };
    class M2StaticMG_base;
    class SectorMG_Ori: M2StaticMG_base
    {
        displayName = "Sector MG";
        scope = 1;
        side = 0;
        faction = "rth_copter_class";
        crew = "";
        typicalCargo[] = {""};
    };
    class House
    {
        class DestructionEffects;
    };
    class UH1Wreck_Ori: House
    {
        model = "\\ca\\air2\\UH1Y\\UH1Y_Crashed.p3d";
        icon = "\\ca\\air2\\data\\UI\\icon_UH1Y_CA.paa";
        mapSize = 15;
        displayName = "Crashed UH-1Y";
        vehicleClass = "Wrecks";
    };
    class HouseDZ: House
    {
        class MarkerLights
        {
            class RedBlinking
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
        class Reflectors
        {
            class MainLight
            {
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                position = "";
                direction = "";
                hitpoint = "";
                selection = "";
                size = 0;
                period[] = {0, 1};
            };
        };
    };
    class Strategic;
    class NonStrategic;
    class Land_A_FuelStation_Feed: Strategic
    {
        model = "\\ca\\structures\\House\\A_FuelStation\\A_FuelStation_Feed";
        transportFuel = 0;
        nameSound = "fuelstation";
    };
    class Land_Ind_MalyKomin: House
    {
        scope = 1;
        armor = 100;
        featureSize = 40;
        model = "\\Ca\\buildings2\\Ind_CementWorks\\Ind_MalyKomin\\Ind_MalyKomin";
        class DestructionEffects: DestructionEffects
        {
            class Ruin1
            {
                simulation = "ruin";
                type = "\\ca\\Buildings2\\Ind_CementWorks\\Ind_MalyKomin\\Ind_MalyKomin_ruins";
                position = "";
                intensity = 1;
                interval = 0.0500000007;
                lifeTime = 1;
            };
        };
        ladders[] = {{"start", "end"}};
        class MarkerLights
        {
            class RedBlinking
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
    };
    class Land_Rail_Semafor: House
    {
        scope = 1;
        model = "\\CA\\Structures\\Rail\\Rail_Misc\\rail_Semafor";
        destrType = "DestructTree";
        class MarkerLights
        {
            class GreenStill
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
    };
    class Land_Rail_Zavora: House
    {
        scope = 1;
        model = "\\CA\\Structures\\Rail\\Rail_Misc\\rail_Zavora";
        destrType = "DestructTree";
        class MarkerLights
        {
            class WhiteBlinking
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
    };
    class Land_majak: House
    {
        scope = 1;
        model = "\\ca\\buildings\\majak";
        displayName = "Lighthouse";
        animated = 1;
        ladders[] = {{"start", "end"}};
        class DestructionEffects: DestructionEffects
        {
            class Ruin1
            {
                simulation = "ruin";
                type = "\\ca\\buildings\\ruins\\majak_ruins.p3d";
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
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
        class Reflectors
        {
            class MainLight
            {
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                position = "";
                direction = "";
                hitpoint = "";
                selection = "";
                size = 0;
                brightness = 0;
                period[] = {0, 1};
            };
        };
    };
    class Land_majak2: Land_majak
    {
        model = "\\ca\\buildings\\majak2";
        class Reflectors
        {
            class MainLight
            {
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                position = "";
                direction = "";
                hitpoint = "";
                selection = "";
                size = 0;
                brightness = 0;
                period[] = {0, 1};
            };
        };
        class DestructionEffects: DestructionEffects
        {
            class Ruin1
            {
                simulation = "ruin";
                type = "\\ca\\buildings\\ruins\\majak_ruins.p3d";
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
        ladders[] = {{"start", "end"}};
        model = "\\ca\\buildings\\Vysilac_FM";
        class MarkerLights
        {
            class RedBlinking
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
        class Destruction
        {
            animations[] = {{"ca\\buildings\\rtm\\vysilac_fm.rtm", 0.5, 3}};
        };
        displayName = "Radio 1";
    };
    class Land_telek1: House
    {
        scope = 1;
        armor = 600;
        destrType = "DestructBuilding";
        model = "\\ca\\buildings\\telek1";
        class DestructionEffects: DestructionEffects
        {
            class Ruin1
            {
                simulation = "ruin";
                type = "\\ca\\buildings\\ruins\\telek1_ruins.p3d";
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
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
        displayName = "Telek 1";
        ladders[] = {{"start1", "end1"}, {"start2", "end2"}, {"start3", "end3"}};
    };
    class Land_komin: House
    {
        ladders[] = {{"start", "end"}};
        model = "\\ca\\buildings\\komin";
        armor = 300;
        class DestructionEffects: DestructionEffects
        {
            class Ruin1
            {
                simulation = "ruin";
                type = "\\ca\\buildings\\ruins\\komin_ruins.p3d";
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
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
    };
    class Land_Stoplight01: House
    {
        scope = 1;
        model = "\\ca\\buildings\\Misc\\stoplight01";
        armor = 50;
        class MarkerLights
        {
            class YellowTopBlinking
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
            class YellowLowBlinking
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
    };
    class Land_Stoplight02: Land_Stoplight01
    {
        model = "\\ca\\buildings\\Misc\\stoplight02";
        class MarkerLights
        {
            class YellowTopBlinking
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
    };
    class Land_NavigLight: House
    {
        scope = 1;
        displayName = "";
        model = "\\ca\\buildings\\Misc\\NavigLight";
        armor = 50;
        class MarkerLights
        {
            class WhiteStill
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
    };
    class Land_runway_edgelight: House
    {
        scope = 1;
        displayName = "";
        model = "\\ca\\buildings\\Misc\\runway_edgelight";
        armor = 20;
        class MarkerLights
        {
            class RedStill
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
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
        accuracy = 0.200000003;
        typicalCargo[] = {};
        destrType = "DestructBuilding";
        irTarget = 0;
        transportAmmo = 0;
        transportRepair = 0;
        transportFuel = 0;
        cost = 0;
        armor = 100;
        mapSize = 6.4000001;
        simulation = "house";
    };
    class Land_HouseB_Tenement: House
    {
        armor = 180;
        model = "\\Ca\\Structures\\House\\HouseBT\\HouseB_Tenement";
        scope = 1;
        featureSize = 50;
        class HitPoints
        {
            class Hit1
            {
                armor = 0.150000006;
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
                        lifeTime = 0.00999999978;
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
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
        class AnimationSources
        {
            class Lights_1
            {
                source = "user";
                animPeriod = 0.00100000005;
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
                type = "\\Ca\\Structures\\Mil\\Mil_ControlTower_ruins.p3d";
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
                        lifeTime = 0.00999999978;
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
                        lifeTime = 0.00999999978;
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
                        lifeTime = 0.00999999978;
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
                        lifeTime = 0.00999999978;
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
                        lifeTime = 0.00999999978;
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
                        lifeTime = 0.00999999978;
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
                armor = 0.000500000024;
                material = -1;
                name = "dam glass";
                visual = "damTglass";
                passThrough = 0;
                convexComponent = "dam glass";
            };
            class Hittower
            {
                armor = 0.000500000024;
                material = -1;
                name = "dam tower";
                visual = "damTtower";
                passThrough = 0;
                convexComponent = "dam tower";
            };
        };
        replaceDamagedHitpoints[] = {"Hit1", "Hit2", "Hit3", "Hit4", "Hit5", "Hit6"};
        class Damage
        {
            tex[] = {};
            mat[] = {"CA\\Structures\\Mil\\Data\\Mil_ControlTower_windows1.rvmat", "CA\\Structures\\Mil\\Data\\destruct_half_Mil_ControlTower_windows1.rvmat", "CA\\Structures\\Mil\\Data\\destruct_full_Mil_ControlTower_windows1.rvmat"};
        };
        model = "\\CA\\Structures\\Mil\\Mil_ControlTower";
        ladders[] = {{"start1", "end1"}, {"start2", "end2"}};
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
                displayNameDefault = "<img image='\\ca\\ui\\data\\ui_action_open_ca.paa' size='4' />";
                displayName = "Open door";
                position = "Dvere_spodni_R_osa";
                radius = 3;
                onlyForPlayer = 0;
                condition = "this animationPhase \"Dvere_spodni_R\" < 0.5";
                statement = "this animate [\"Dvere_spodni_R\", 1];this animate [\"Dvere_spodni_L\", 1]";
            };
            class CloseDoors1: OpenDoors1
            {
                displayNameDefault = "<img image='\\ca\\ui\\data\\ui_action_close_ca.paa' size='4' />";
                displayName = "Close door";
                condition = "this animationPhase \"Dvere_spodni_R\" >= 0.5";
                statement = "this animate [\"Dvere_spodni_R\", 0];this animate [\"Dvere_spodni_L\", 0]";
            };
            class OpenDoors3
            {
                displayNameDefault = "<img image='\\ca\\ui\\data\\ui_action_open_ca.paa' size='4' />";
                displayName = "Open door";
                position = "Dvere_Vrchni_osa";
                radius = 2;
                onlyForPlayer = 0;
                condition = "this animationPhase \"dvere_vrchni\" < 0.5";
                statement = "this animate [\"dvere_vrchni\", 1]";
            };
            class CloseDoors3: OpenDoors3
            {
                displayNameDefault = "<img image='\\ca\\ui\\data\\ui_action_close_ca.paa' size='4' />";
                displayName = "Close door";
                condition = "this animationPhase \"dvere_vrchni\" >= 0.5";
                statement = "this animate [\"dvere_vrchni\", 0]";
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
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
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
        model = "\\Ca\\Structures\\NAV\\NAV_Lighthouse";
        ladders[] = {{"start1", "end1"}};
        class MarkerLights
        {
            class RedBlinking
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
        class Reflectors
        {
            class MainLight
            {
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                position = "";
                direction = "";
                hitpoint = "";
                selection = "";
                size = 0;
                brightness = 0;
                period[] = {0, 1};
            };
        };
        class Damage
        {
            tex[] = {};
            mat[] = {"ca\\structures\\nav\\data\\nav_lighthouse_multi.rvmat", "ca\\structures\\nav\\data\\destruct_half_nav_lighthouse_multi.rvmat", "ca\\structures\\nav\\data\\destruct_full_nav_lighthouse_multi.rvmat", "ca\\structures\\nav\\data\\nav_lighthouse_windows.rvmat", "ca\\structures\\nav\\data\\destruct_half_lighthouse_windows.rvmat", "ca\\structures\\nav\\data\\destruct_full_lighthouse_windows.rvmat"};
        };
        class DestructionEffects: DestructionEffects
        {
            class Ruin1
            {
                simulation = "ruin";
                type = "\\Ca\\Structures\\Nav\\NAV_Lighthouse_ruins.p3d";
                position = "";
                intensity = 1;
                interval = 1;
                lifeTime = 1;
            };
        };
    };
    class Land_NAV_Lighthouse2: Land_NAV_Lighthouse
    {
        model = "\\Ca\\Structures\\NAV\\NAV_Lighthouse2";
        class Reflectors: Reflectors
        {
            class MainLight: MainLight
            {
                period[] = {0, 1};
            };
        };
        class DestructionEffects: DestructionEffects
        {
            class Ruin1
            {
                simulation = "ruin";
                type = "\\Ca\\Structures\\Nav\\NAV_Lighthouse_ruins.p3d";
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
        model = "\\ca\\buildings2\\A_Crane_02\\A_Crane_02b";
        destrType = "DestructBuilding";
        ladders[] = {{"start3", "end3"}, {"start4", "end4"}, {"start5", "end5"}, {"start6", "end6"}};
        class MarkerLights
        {
            class RedBlinking
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
        class Destruction
        {
            animations[] = {{"ca\\buildings2\\A_Crane_02\\data\\anim\\crane.rtm", 0.5, 3}};
        };
    };
    class Land_Farm_WTower: House
    {
        scope = 1;
        armor = 100;
        model = "\\CA\\buildings2\\Farm_WTower\\Farm_WTower";
        class MarkerLights
        {
            class RedBlinking
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
        class DestructionEffects: DestructionEffects
        {
            class Ruin1
            {
                simulation = "ruin";
                type = "\\Ca\\buildings2\\Farm_WTower\\Farm_WTower_ruins";
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
        model = "\\ca\\Structures\\A_TVTower\\A_TVTower_Mid";
        featureSize = 150;
        class MarkerLights
        {
            class RedStill
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
    };
    class Land_A_TVTower_Top: House
    {
        scope = 1;
        destrType = "DestructNo";
        model = "\\ca\\Structures\\A_TVTower\\A_TVTower_Top";
        featureSize = 150;
        class MarkerLights
        {
            class RedLight
            {
                name = "";
                color[] = {0, 0, 0, 0};
                ambient[] = {0, 0, 0, 0};
                brightness = 0;
                blinking = 0;
            };
        };
    };
    class GraveCrossHelmet_DZ: NonStrategic
    {
        scope = 2;
        model = "\\ca\\buildings\\Misc\\hrobecek_krizekhelma.p3d";
        vehicleClass = "Dead_bodies";
        destrType = "DestructTree";
        armor = 10;
        accuracy = 500;
        displayName = "Survival RIP";
    };
};
class CfgNonAIVehicles
{
    access = 0;
    class StreetLamp
    {
        colorDiffuse[] = {0.899999976, 0.800000012, 0.600000024};
        colorAmbient[] = {0.0199999996, 0.0199999996, 0.0199999996};
        brightness = 0.150000006;
    };
    class StreetLamp_BaseWeakYellow: StreetLamp
    {
        colorDiffuse[] = {0.5, 0.400000006, 0.100000001, 0};
        colorAmbient[] = {0.200000003, 0.150000006, 0.0500000007, 0};
        brightness = 0.100000001;
    };
    class StreetLamp_BaseMediumOrange: StreetLamp
    {
        colorDiffuse[] = {0.600000024, 0.349999994, 0, 0};
        colorAmbient[] = {0.200000003, 0.100000001, 0, 0};
        brightness = 0.200000003;
    };
    class StreetLamp_BaseMediumPale: StreetLamp
    {
        colorDiffuse[] = {0.600000024, 0.699999988, 0.800000012, 0};
        colorAmbient[] = {0.0599999987, 0.0700000003, 0.100000001, 0};
        brightness = 0.150000006;
    };
    class StreetLamp_BaseStrongPale: StreetLamp
    {
        colorDiffuse[] = {0.600000024, 0.699999988, 0.850000024, 0};
        colorAmbient[] = {0.0700000003, 0.100000001, 0.150000006, 0};
        brightness = 0.330000013;
    };
    class Land_lampa_sidl: StreetLamp_BaseMediumOrange
    {
        colorDiffuse[] = {0.600000024, 0.349999994, 0, 0};
        colorAmbient[] = {0.200000003, 0.100000001, 0, 0};
        brightness = 0.0799999982;
        scope = 2;
        model = "\\ca\\buildings\\Misc\\lampa_sidl";
    };
    class Land_lampa_sidl_2: StreetLamp_BaseMediumOrange
    {
        colorDiffuse[] = {0.600000024, 0.349999994, 0, 0};
        colorAmbient[] = {0.200000003, 0.100000001, 0, 0};
        brightness = 0.159999996;
        scope = 2;
        model = "\\ca\\buildings\\Misc\\lampa_sidl_2";
    };
    class Land_lampa_sidl_3: StreetLamp_BaseMediumOrange
    {
        colorDiffuse[] = {0.600000024, 0.349999994, 0, 0};
        colorAmbient[] = {0.200000003, 0.100000001, 0, 0};
        brightness = 0.239999995;
        scope = 2;
        model = "\\ca\\buildings\\Misc\\lampa_sidl_3";
    };
    class Land_lampa_ind: StreetLamp_BaseWeakYellow
    {
        colorDiffuse[] = {0.5, 0.400000006, 0.100000001, 0};
        colorAmbient[] = {0.200000003, 0.150000006, 0.0500000007, 0};
        brightness = 0.100000001;
        scope = 2;
        model = "\\ca\\buildings\\Misc\\lampa_ind";
    };
    class Land_lampa_ind_zebr: StreetLamp_BaseWeakYellow
    {
        colorDiffuse[] = {0.5, 0.400000006, 0.100000001, 0};
        colorAmbient[] = {0.200000003, 0.150000006, 0.0500000007, 0};
        brightness = 0.100000001;
        scope = 2;
        model = "\\ca\\buildings\\Misc\\lampa_ind_zebr";
    };
};
class CfgLoot
{
    trash[] = {{"TrashTinCan", "TrashJackDaniels", "ItemSodaEmpty"}, {1, 0.100000001, 0.5}};
    civilian[] = {{"TrashTinCan", "TrashJackDaniels", "ItemSodaEmpty", "ItemSodaCoke", "ItemSodaPepsi", "FoodCanBakedBeans", "FoodCanSardines", "FoodCanFrankBeans", "FoodCanPasta", "8Rnd_9x18_Makarov", "7Rnd_45ACP_1911", "2Rnd_shotgun_74Slug", "2Rnd_shotgun_74Pellets", "ItemBandage", "ItemPainkiller"}, {0.100000001, 0.100000001, 0.100000001, 0.0199999996, 0.0199999996, 0.0199999996, 0.0199999996, 0.0199999996, 0.0199999996, 0.0700000003, 0.0500000007, 0.0500000007, 0.0500000007, 0.00999999978, 0.0599999987}};
    newGenShop[] = {{"ItemSodaEmpty", "ItemSodaCoke", "ItemSodaPepsi", "FoodCanBakedBeans", "FoodCanSardines", "FoodCanFrankBeans", "FoodCanPasta", "ItemBandage", "7Rnd_45ACP_1911", "5x_22_LR_17_HMR", "10x_303", "6Rnd_45ACP", "2Rnd_shotgun_74Slug", "2Rnd_shotgun_74Pellets", "8Rnd_9x18_Makarov", "15Rnd_W1866_Slug", "ItemPainkiller", "HandChemGreen", "HandChemBlue", "HandChemRed", "ItemHeatPack", "Skin_Sniper1_DZ", "ItemAntibiotic", "ItemBattery", "ItemSodaMdew"}, {0.129999995, 0.129999995, 0.129999995, 0.0900000036, 0.129999995, 0.0900000036, 0.0900000036, 0.0299999993, 0.0900000036, 0.0399999991, 0.0299999993, 0.00999999978, 0.0399999991, 0.0399999991, 0.0500000007, 0.0500000007, 0.0900000036, 0.0199999996, 0.0199999996, 0.00999999978, 0.0299999993, 0.00999999978, 0.0399999991, 0.0399999991, 0.0199999996}};
    food[] = {{"TrashTinCan", "TrashJackDaniels", "ItemSodaEmpty", "ItemSodaCoke", "ItemSodaPepsi", "FoodCanBakedBeans", "FoodCanSardines", "FoodCanFrankBeans", "FoodCanPasta", "ItemBandage"}, {0.129999995, 0.129999995, 0.129999995, 0.0900000036, 0.129999995, 0.0900000036, 0.0900000036, 0.0900000036, 0.0900000036, 0.0199999996}};
    generic[] = {{"TrashTinCan", "ItemSodaEmpty", "ItemSodaCoke", "ItemSodaPepsi", "TrashJackDaniels", "FoodCanBakedBeans", "FoodCanSardines", "FoodCanFrankBeans", "FoodCanPasta", "ItemWaterbottleUnfilled", "ItemWaterbottle", "ItemBandage", "7Rnd_45ACP_1911", "5x_22_LR_17_HMR", "10x_303", "6Rnd_45ACP", "2Rnd_shotgun_74Slug", "2Rnd_shotgun_74Pellets", "8Rnd_9x18_Makarov", "15Rnd_W1866_Slug", "BoltSteel", "HandRoadFlare", "ItemPainkiller", "HandChemGreen", "HandChemBlue", "HandChemRed", "ItemHeatPack"}, {0.0599999987, 0.0299999993, 0.0199999996, 0.0399999991, 0.0399999991, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.0599999987, 0.0299999993, 0.00999999978, 0.0399999991, 0.0399999991, 0.0500000007, 0.0500000007, 0.0900000036, 0.0199999996, 0.0399999991, 0.0700000003, 0.0199999996, 0.00999999978, 0.0299999993, 0.0299999993, 0.0399999991}};
    medical[] = {{"ItemBandage", "ItemPainkiller", "ItemMorphine", "ItemEpinephrine", "ItemAntibiotic", "ItemHeatPack"}, {0.800000012, 0.5, 0.5, 0.200000003, 0.200000003, 0.200000003}};
    hospital[] = {{"ItemBandage", "ItemPainkiller", "ItemMorphine", "ItemEpinephrine", "ItemBloodbag", "ItemAntibiotic"}, {0.330000013, 0.170000002, 0.129999995, 0.0900000036, 0.170000002, 0.119999997}};
    military[] = {{"TrashTinCan", "ItemSodaEmpty", "ItemSodaCoke", "ItemSodaPepsi", "ItemBandage", "ItemAntibiotic", "ItemPainkiller", "ItemMorphine", "30Rnd_556x45_Stanag", "20Rnd_762x51_DMR", "17Rnd_9x19_glock17", "15Rnd_9x19_M9SD", "15Rnd_9x19_M9", "30Rnd_762x39_AK47", "30Rnd_545x39_AK", "5Rnd_762x51_M24", "7Rnd_45ACP_1911", "8Rnd_B_Beneli_74Slug", "1Rnd_HE_M203", "FlareWhite_M203", "FlareGreen_M203", "1Rnd_Smoke_M203", "200Rnd_556x45_M249", "HandGrenade_west", "SmokeShell", "SmokeShellRed", "SmokeShellGreen", "8Rnd_B_Beneli_Pellets", "30Rnd_556x45_StanagSD", "30Rnd_9x19_MP5", "30Rnd_9x19_MP5SD", "100Rnd_762x51_M240", "HandChemGreen", "HandChemBlue", "HandChemRed", "ItemHeatPack", "30Rnd_762x39_SA58", "30Rnd_556x45_G36", "30Rnd_556x45_G36SD", "1Rnd_HE_GP25", "75Rnd_545x39_RPK", "10Rnd_9x39_SP5_VSS", "20Rnd_9x39_SP5_VSS", "8Rnd_9x18_MakarovSD", "64Rnd_9x19_Bizon", "30Rnd_545x39_AKSD", "100Rnd_762x54_PK", "HandGrenade_East", "Ori_mosin_clip", "Ori_35Rnd_smg", "Ori_10Rnd_SKS", "Ori_12Rnd_maka", "Ori_8Rnd_TT", "Ori_20Rnd_APS", "Ori_20Rnd_APS_SD", "10Rnd_762x54_SVD", "FlareGreen_GP25", "FlareWhite_GP25", "FlareRed_GP25", "1Rnd_SMOKE_GP25", "1Rnd_SmokeRed_GP25", "1Rnd_SmokeGreen_GP25"}, {0.180000007, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.0399999991, 0.0399999991, 0.00999999978, 0.0399999991, 0.00999999978, 0.0500000007, 0.00999999978, 0.0199999996, 0.0399999991, 0.0399999991, 0.00999999978, 0.00999999978, 0.0399999991, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.0399999991, 0.0199999996, 0.0199999996, 0.0399999991, 0.00999999978, 0.0399999991, 0.00999999978, 0.00999999978, 0.0199999996, 0.0199999996, 0.0199999996, 0.0399999991, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.0399999991, 0.00999999978, 0.00999999978, 0.00999999978, 0.0199999996, 0.0199999996, 0.0199999996, 0.0199999996, 0.0500000007, 0.0500000007, 0.0500000007, 0.0399999991, 0.00999999978, 0.0199999996, 0.0199999996, 0.0199999996, 0.0199999996, 0.0199999996, 0.0199999996}};
    policeman[] = {{"ItemBandage", "7Rnd_45ACP_1911", "6Rnd_45ACP", "15Rnd_W1866_Slug", "8Rnd_B_Beneli_74Slug", "HandRoadFlare"}, {1, 0.800000012, 0.300000012, 0.300000012, 0.5, 0.300000012}};
    hunter[] = {{"ItemBandage", "5x_22_LR_17_HMR", "7Rnd_45ACP_1911", "10x_303", "ItemWaterbottleUnfilled", "BoltSteel", "ItemHeatPack"}, {1, 0.5, 0.200000003, 0.5, 0.200000003, 1, 0.200000003}};
    zBoss[] = {{"ItemGPS", "ItemMap", "ItemToolBox", "ItemEtool", "ItemSaw", "ItemHammer", "ItemPliers", "ItemRope"}, {0.300000012, 0.800000012, 0.600000024, 0.600000024, 0.5, 0.5, 0.5, 0.5}};
};
class CfgWrapperUI
{
    class Cursors
    {
        class Arrow
        {
            texture = "\\origins_pack\\ui\\mouse_cursor.paa";
            width = 32;
            height = 32;
            hotspotX = 0.1875;
            hotspotY = 0.03125;
        };
    };
};
class CfgSurvival
{
    class Inventory
    {
        class Default
        {
            magazines[] = {"ItemBandage", "ItemPainkiller", "8Rnd_9x18_Makarov"};
            weapons[] = {"Makarov", "ItemFlashlight"};
            backpackWeapon = "";
            backpack = "";
        };
    };
    class Meat
    {
        class Default
        {
            yield = 1;
        };
        class Cow: Default
        {
            yield = 6;
        };
        class Cow01: Cow
        {
        };
        class Cow02: Cow
        {
        };
        class Cow03: Cow
        {
        };
        class Cow04: Cow
        {
        };
        class Goat: Default
        {
            yield = 4;
        };
        class Sheep: Default
        {
            yield = 3;
        };
        class WildBoar: Default
        {
            yield = 2;
        };
    };
};
class CfgGlasses
{
    class None;
    class b_TacticalGlasses: None
    {
    };
    class Barett: None
    {
    };
    class Barett_g: None
    {
    };
    class Bdu_cap: None
    {
    };
    class Bdu_cap_g: None
    {
    };
    class BlackSun_sof_w: None
    {
    };
    class dive_mask: None
    {
    };
    class gasmask: None
    {
    };
    class gasmask_helmet: None
    {
    };
    class gasmask_helmet2: None
    {
    };
    class gasmask_red: None
    {
    };
    class gasmask2: None
    {
    };
    class goggles_winter: None
    {
    };
    class headset: None
    {
    };
    class headset_g: None
    {
    };
    class Kevlar_Helmet: None
    {
    };
    class Kevlar_Helmet_g: None
    {
    };
    class None_sof_w: None
    {
    };
    class pilot_mask: None
    {
    };
    class pilot_mask_v: None
    {
    };
    class pilot_v: None
    {
    };
    class Pro_Helmet: None
    {
    };
    class Pro_Helmet_2: None
    {
    };
    class Pro_Helmet_g: None
    {
    };
    class RedSun_sof_w: None
    {
    };
    class skull_cap: None
    {
    };
    class skull_cap2: None
    {
    };
    class taliban_hat_shadow: None
    {
    };
    class US_black_beret: None
    {
    };
    class US_green_beret: None
    {
    };
    class wdl_helmet: None
    {
    };
};
class CfgInGameUI
{
    class PeripheralVision
    {
        cueColor[] = {0, 0, 0, 0};
        cueFriendlyColor[] = {0, 0, 0, 0};
        cueEnemyColor[] = {0, 0, 0, 0};
    };
};
class CfgEnvSounds
{
    class Sea
    {
        sound[] = {"\\ca\\Sounds\\Enviroment\\wave_break_01", 0.00999999978, 1};
        volume = "sea";
        name = "Sea";
        soundNight[] = {"\\ca\\Sounds\\Enviroment\\wave_break_02", 0.00999999978, 1};
    };
};
class CfgBuildingLoot
{
    class Default
    {
        zombieChance = 0;
        minRoaming = 0;
        maxRoaming = 2;
        zombieClass[] = {"zZombie_Base", "z_policeman", "z_Boss_zed", "ori_zombie1", "ori_zombie1n", "ori_zombie2", "ori_zombie2n", "ori_zombie3", "ori_zombie3n", "ori_zombie4", "ori_zombie4n", "ori_zombie5", "ori_zombie5n", "ori_zombie6", "ori_zombie6n", "ori_zombie7", "ori_zombie7n", "ori_zombie8", "ori_zombie8n", "ori_zombie1L", "ori_zombie1Ln", "ori_zombie2L", "ori_zombie2Ln", "ori_zombie3L", "ori_zombie3Ln", "ori_zombie4L", "ori_zombie4Ln", "ori_zombie5L", "ori_zombie5Ln", "ori_zombie6L", "ori_zombie6Ln", "ori_zombie7L", "ori_zombie7Ln", "ori_zombie8L", "ori_zombie8Ln", "ori_vil_zombie_woman1", "ori_vil_zombie_woman2", "ori_vil_zombie_woman3", "ori_vil_zombie_woman4", "z_suit1", "z_suit2", "z_worker1", "z_worker2", "z_worker3", "z_doctor", "z_teacher", "z_hunter", "z_villager1", "z_villager2", "z_villager3", "z_priest", "z_soldier", "z_soldier_pilot", "z_soldier_heavy", "ori_pozarnik"};
        lootChance = 0;
        lootPos[] = {};
        itemType[] = {};
        itemChance[] = {};
        hangPos[] = {};
        vehPos[] = {};
    };
    class Master
    {
        weapons[] = {"SMAW", "Javelin", "G36C", "Stinger"};
    };
    class Residential: Default
    {
        zombieChance = 0.300000012;
        maxRoaming = 2;
        zombieClass[] = {"zZombie_Base", "z_hunter", "z_teacher", "z_villager1", "z_villager2", "z_villager3", "ori_zombie1", "ori_zombie2", "ori_zombie3", "ori_zombie4", "ori_zombie5", "ori_zombie6", "ori_zombie7", "ori_zombie8", "ori_zombie1L", "ori_zombie2L", "ori_zombie3L", "ori_zombie4L", "ori_zombie5L", "ori_zombie6L", "ori_zombie7L", "ori_zombie8L", "ori_vil_zombie_woman1", "ori_vil_zombie_woman2", "ori_vil_zombie_woman3", "ori_vil_zombie_woman4", "ori_zombie1Ln", "ori_zombie2n", "ori_zombie3n", "ori_zombie3Ln", "ori_zombie7Ln", "ori_zombie8n"};
        lootChance = 0.400000006;
        lootPos[] = {};
        itemType[] = {{"ItemSodaMdew", "magazine"}, {"ItemWatch", "generic"}, {"ItemCompass", "generic"}, {"ItemMap", "weapon"}, {"Makarov", "weapon"}, {"Colt1911", "weapon"}, {"ItemFlashlight", "generic"}, {"ItemKnife", "generic"}, {"ItemMatchbox", "generic"}, {"", "generic"}, {"LeeEnfield", "weapon"}, {"revolver_EP1", "weapon"}, {"CZ_VestPouch_EP1", "object"}, {"DZ_CivilBackpack_EP1", "object"}, {"DZ_ALICE_Pack_EP1", "object"}, {"Winchester1866", "weapon"}, {"ItemRestTent", "magazine"}, {"", "military"}, {"", "trash"}, {"Crossbow", "weapon"}, {"Binocular", "weapon"}, {"Skin_Sniper1_DZ", "magazine"}, {"MR43", "weapon"}, {"Sa61_EP1", "weapon"}, {"ItemBattery", "magazine"}, {"ItemPin", "magazine"}, {"ItemBpt_b1", "magazine"}, {"ItemBpt_h1", "magazine"}, {"origins_school_1", "object"}, {"origins_school_2", "object"}, {"origins_school_3", "object"}};
        itemChance[] = {0.00999999978, 0.150000006, 0.0500000007, 0.00999999978, 0.129999995, 0.0500000007, 0.0299999993, 0.0799999982, 0.0599999987, 0.800000012, 0.0199999996, 0.0399999991, 0.0299999993, 0.0299999993, 0.00999999978, 0.00999999978, 0.00999999978, 0.0299999993, 0.400000006, 0.0599999987, 0.0599999987, 0.00999999978, 0.0299999993, 0.0500000007, 0.0799999982, 0.0799999982, 0.0199999996, 0.0199999996, 0.0299999993, 0.0299999993, 0.0299999993};
    };
    class NoviShop: Default
    {
        zombieChance = 0.300000012;
        maxRoaming = 2;
        zombieClass[] = {"zZombie_Base", "z_hunter", "z_teacher", "z_villager1", "z_villager2", "z_villager3", "ori_zombie1", "ori_zombie2", "ori_zombie3", "ori_zombie4", "ori_zombie5", "ori_zombie6", "ori_zombie7", "ori_zombie8", "ori_zombie1L", "ori_zombie2L", "ori_zombie3L", "ori_zombie4L", "ori_zombie5L", "ori_zombie6L", "ori_zombie7L", "ori_zombie8L", "ori_vil_zombie_woman1", "ori_vil_zombie_woman2", "ori_vil_zombie_woman3", "ori_vil_zombie_woman4", "ori_zombie1Ln", "ori_zombie2n", "ori_zombie3n", "ori_zombie3Ln", "ori_zombie7Ln", "ori_zombie8n"};
        lootChance = 0.400000006;
        lootPos[] = {};
        itemType[] = {{"Binocular", "weapon"}, {"ItemMap", "weapon"}, {"", "newGenShop"}, {"ItemCompass", "weapon"}, {"ItemWatch", "weapon"}, {"ItemKnife", "weapon"}};
        itemChance[] = {0.100000001, 0.100000001, 0.899999976, 0.100000001, 0.100000001, 0.100000001};
    };
    class Office: Residential
    {
        maxRoaming = 5;
        zombieClass[] = {"z_suit1", "z_suit2", "ori_zombie2Ln", "ori_zombie5n", "ori_zombie3n", "ori_zombie3Ln"};
    };
    class TavianaDZ: Default
    {
        zombieChance = 0.899999976;
        zombieClass[] = {"z_soldier", "z_soldier_heavy", "ori_zombie6Ln"};
        minRoaming = 1;
        maxRoaming = 5;
        lootChance = 0.200000003;
        lootPos[] = {};
        itemType[] = {{"AK_74", "weapon"}, {"AKS_74", "weapon"}, {"AK_74_GL", "weapon"}, {"AK_74_GL_kobra", "weapon"}, {"AK_107_kobra", "weapon"}, {"AK_107_GL_kobra", "weapon"}, {"AK_107_pso", "weapon"}, {"AKS_74_kobra", "weapon"}, {"AKS_74_pso", "weapon"}, {"AKS_74_UN_kobra", "weapon"}, {"SVD_NSPU_EP1", "weapon"}, {"bizon", "weapon"}, {"M249_EP1_DZ", "weapon"}, {"M60A4_EP1_DZ", "weapon"}, {"MakarovSD", "weapon"}, {"M4SPR", "weapon"}, {"Sa58V_RCO_EP1", "weapon"}, {"Sa58V_CCO_EP1", "weapon"}, {"M16A4_GL", "weapon"}, {"M16A4_ACG_GL", "weapon"}, {"M4A1_Aim_camo", "weapon"}, {"RPK_74", "weapon"}, {"M4A1_RCO_GL", "weapon"}, {"M4A1_HWS_GL_SD_Camo", "weapon"}, {"M4A1_HWS_GL", "weapon"}, {"m16a4", "weapon"}, {"AK_47_S", "weapon"}, {"SVD", "weapon"}, {"M4A3_RCO_GL_EP1", "weapon"}, {"PK_DZ", "weapon"}, {"", "medical"}, {"DZ_Assault_Pack_EP1", "object"}, {"DZ_Patrol_Pack_EP1", "object"}, {"", "trash"}, {"DZ_Backpack_EP1", "object"}, {"", "trash"}, {"ItemFlashlightRed", "military"}, {"ItemKnife", "military"}, {"ItemGPS", "weapon"}, {"", "generic"}, {"ItemRestTent", "magazine"}, {"ItemBpt_b2", "magazine"}, {"ItemBpt_h2", "magazine"}};
        itemChance[] = {0.100000001, 0.100000001, 0.0399999991, 0.0399999991, 0.0299999993, 0.0299999993, 0.00999999978, 0.0299999993, 0.0199999996, 0.0299999993, 0.00999999978, 0.0399999991, 0.00999999978, 0.00999999978, 0.0500000007, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.0299999993, 0.0199999996, 0.0299999993, 0.0500000007, 0.0500000007, 0.00999999978, 0.0299999993, 0.00999999978, 0.300000012, 0.0500000007, 0.0500000007, 0.899999976, 0.00999999978, 0.899999976, 0.0399999991, 0.119999997, 0.0199999996, 0.800000012, 0.0199999996, 0.00999999978, 0.00999999978};
    };
    class IndNovistr: Default
    {
        zombieChance = 0.600000024;
        zombieClass[] = {"z_worker1", "z_worker2", "z_worker3", "ori_zombie7n", "ori_zombie8Ln"};
        maxRoaming = 5;
        lootChance = 0.300000012;
        lootPos[] = {};
        itemType[] = {{"PartGeneric", "magazine"}, {"", "generic"}, {"PartFueltank", "magazine"}, {"ItemKnife", "military"}, {"", "trash"}, {"PartPipe", "magazine"}, {"ItemCementBag", "magazine"}, {"", "trash"}, {"ItemTow", "weapon"}, {"PartAluminium", "magazine"}, {"ItemHose", "weapon"}, {"PartChipB", "magazine"}, {"", "trash"}, {"ItemScrews", "magazine"}, {"PartBlockV", "magazine"}, {"ItemBpt_wt", "magazine"}, {"ItemBlueSpr", "magazine"}, {"ItemGreenSpr", "magazine"}, {"ItemPinkSpr", "magazine"}, {"ItemBlackSpr", "magazine"}, {"ItemRedSpr", "magazine"}, {"ItemYellowSpr", "magazine"}, {"ItemWhiteSpr", "magazine"}, {"ItemSaw", "weapon"}, {"ItemHammer", "weapon"}, {"ItemPliers", "weapon"}, {"ItemCrane", "magazine"}};
        itemChance[] = {0.0399999991, 0.150000006, 0.0399999991, 0.0500000007, 0.349999994, 0.0399999991, 0.0399999991, 0.25, 0.00999999978, 0.0500000007, 0.00999999978, 0.0500000007, 0.200000003, 0.0199999996, 0.0199999996, 0.0199999996, 0.0700000003, 0.0700000003, 0.0700000003, 0.0700000003, 0.0700000003, 0.0700000003, 0.0700000003, 0.0199999996, 0.0199999996, 0.0199999996, 0.0199999996};
    };
    class IndustrialNew: Default
    {
        zombieChance = 0.600000024;
        zombieClass[] = {"z_worker1", "z_worker2", "z_worker3", "ori_zombie7n", "ori_zombie8Ln"};
        maxRoaming = 2;
        lootChance = 0.200000003;
        lootPos[] = {};
        itemType[] = {{"PartGeneric", "magazine"}, {"", "generic"}, {"PartFueltank", "magazine"}, {"PartEngine", "magazine"}, {"ItemKnife", "military"}, {"PartScrap", "magazine"}, {"", "military"}, {"PartPipe", "magazine"}, {"ItemCementBag", "magazine"}, {"ItemBpt_g_s", "magazine"}, {"", "trash"}, {"ItemBpt_g_b", "magazine"}, {"ItemTow", "weapon"}, {"ItemHose", "weapon"}, {"PartBlockV", "magazine"}, {"ItemBpt_wt", "magazine"}, {"ItemBlueSpr", "magazine"}, {"ItemGreenSpr", "magazine"}, {"ItemPinkSpr", "magazine"}, {"ItemBlackSpr", "magazine"}, {"ItemRedSpr", "magazine"}, {"ItemYellowSpr", "magazine"}, {"ItemWhiteSpr", "magazine"}, {"", "trash"}, {"ItemSaw", "weapon"}, {"ItemMTubes", "magazine"}, {"ItemBpt_wt1", "magazine"}, {"ItemBpt_wt2", "magazine"}, {"ItemBpt_wt3", "magazine"}, {"ItemBpt_wt4", "magazine"}};
        itemChance[] = {0.0399999991, 0.349999994, 0.0399999991, 0.0199999996, 0.0500000007, 0.0199999996, 0.349999994, 0.0399999991, 0.0399999991, 0.00999999978, 0.25, 0.0399999991, 0.00999999978, 0.00999999978, 0.0199999996, 0.00999999978, 0.0500000007, 0.0500000007, 0.0500000007, 0.0500000007, 0.0500000007, 0.0500000007, 0.0500000007, 0.100000001, 0.0500000007, 0.0299999993, 0.0299999993, 0.0299999993, 0.0299999993, 0.0299999993};
    };
    class Industrial: Default
    {
        zombieChance = 0.600000024;
        zombieClass[] = {"z_worker1", "z_worker2", "z_worker3", "ori_zombie7n", "ori_zombie8Ln", "ori_pozarnik"};
        maxRoaming = 5;
        lootChance = 0.300000012;
        lootPos[] = {};
        itemType[] = {{"", "generic"}, {"", "trash"}, {"", "military"}, {"PartGeneric", "magazine"}, {"PartWheel", "magazine"}, {"PartFueltank", "magazine"}, {"PartEngine", "magazine"}, {"PartGlass", "magazine"}, {"PartVRotor", "magazine"}, {"ItemJerrycan", "magazine"}, {"ItemHatchet", "weapon"}, {"ItemKnife", "military"}, {"ItemToolbox", "weapon"}, {"ItemTankTrap", "magazine"}, {"PartScrap", "magazine"}, {"ItemJerrycanB", "magazine"}, {"ItemPickaxe", "weapon"}, {"ItemCeMix", "magazine"}, {"ItemCementBag", "magazine"}, {"ItemBpt_g_s", "magazine"}, {"ItemBpt_g_b", "magazine"}, {"ItemEtool", "weapon"}, {"ItemHose", "weapon"}};
        itemChance[] = {0.349999994, 0.25, 0.0399999991, 0.0399999991, 0.0500000007, 0.0199999996, 0.0199999996, 0.0399999991, 0.00999999978, 0.0399999991, 0.109999999, 0.0700000003, 0.0299999993, 0.0399999991, 0.0500000007, 0.00999999978, 0.0900000036, 0.0700000003, 0.0500000007, 0.00999999978, 0.00999999978, 0.0599999987, 0.00999999978};
    };
    class Farm: Default
    {
        zombieChance = 0.300000012;
        maxRoaming = 3;
        zombieClass[] = {"zZombie_Base", "z_hunter", "z_hunter", "z_hunter", "z_villager1", "z_villager2", "z_villager3", "ori_vil_zombie_woman1", "ori_vil_zombie_woman2", "ori_vil_zombie_woman3", "ori_vil_zombie_woman4", "ori_zombie4Ln", "ori_zombie5Ln"};
        lootChance = 0.5;
        lootPos[] = {};
        itemType[] = {{"ItemJerrycan", "magazine"}, {"", "generic"}, {"huntingrifle", "weapon"}, {"LeeEnfield", "weapon"}, {"Winchester1866", "weapon"}, {"", "trash"}, {"Crossbow", "weapon"}, {"ItemHatchet", "weapon"}, {"MR43", "weapon"}, {"ItemJerrycanB", "magazine"}, {"ItemPickaxe", "weapon"}, {"ItemCementBag", "magazine"}, {"ItemBpt_g_s", "magazine"}, {"ItemBpt_g_b", "magazine"}, {"ItemBpt_b1", "magazine"}, {"ItemBpt_h1", "magazine"}, {"ItemRope", "weapon"}};
        itemChance[] = {0.0599999987, 0.379999995, 0.00999999978, 0.00999999978, 0.0299999993, 0.319999993, 0.0299999993, 0.170000002, 0.0599999987, 0.0299999993, 0.100000001, 0.0799999982, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978, 0.0599999987};
    };
    class Supermarket: Default
    {
        lootChance = 0.600000024;
        minRoaming = 2;
        maxRoaming = 6;
        zombieChance = 0.300000012;
        zombieClass[] = {"zZombie_Base", "zZombie_Base", "z_teacher", "z_suit1", "z_suit2", "ori_vil_zombie_woman1", "ori_vil_zombie_woman2", "ori_vil_zombie_woman3", "ori_vil_zombie_woman4"};
        itemType[] = {{"ItemWatch", "generic"}, {"ItemCompass", "generic"}, {"ItemMap", "weapon"}, {"Makarov", "weapon"}, {"Colt1911", "weapon"}, {"ItemFlashlight", "generic"}, {"ItemKnife", "generic"}, {"ItemMatchbox", "generic"}, {"", "generic"}, {"LeeEnfield", "weapon"}, {"revolver_EP1", "weapon"}, {"CZ_VestPouch_EP1", "object"}, {"DZ_CivilBackpack_EP1", "object"}, {"DZ_ALICE_Pack_EP1", "object"}, {"Winchester1866", "weapon"}, {"ItemRestTent", "magazine"}, {"", "food"}, {"", "trash"}, {"Crossbow", "weapon"}, {"Binocular", "weapon"}, {"MR43", "weapon"}, {"ItemCementBag", "magazine"}, {"ItemBattery", "magazine"}, {"ItemPin", "magazine"}, {"origins_school_1", "object"}, {"origins_school_2", "object"}, {"origins_school_3", "object"}};
        itemChance[] = {0.150000006, 0.00999999978, 0.0500000007, 0.0199999996, 0.0199999996, 0.0500000007, 0.0199999996, 0.0500000007, 0.180000007, 0.00999999978, 0.00999999978, 0.0299999993, 0.0199999996, 0.00999999978, 0.00999999978, 0.00999999978, 0.300000012, 0.75, 0.109999999, 0.0500000007, 0.00999999978, 0.0700000003, 0.0500000007, 0.00999999978, 0.00999999978, 0.00999999978, 0.00999999978};
    };
    class HeliCrash: Default
    {
        zombieChance = 0;
        maxRoaming = 2;
        zombieClass[] = {"z_soldier_pilot", "z_soldier", "z_soldier_heavy", "ori_zombie6n"};
        lootChance = 0.5;
        lootPos[] = {};
        itemType[] = {{"FN_FAL", "weapon"}, {"bizon_silenced", "weapon"}, {"M14_EP1", "weapon"}, {"FN_FAL_ANPVS4", "weapon"}, {"huntingrifle", "weapon"}, {"SVD", "weapon"}, {"Mk_48_DZ", "weapon"}, {"M249_DZ", "weapon"}, {"BAF_L85A2_RIS_Holo", "weapon"}, {"DMR", "weapon"}, {"", "military"}, {"", "medical"}, {"NVGoggles", "weapon"}, {"Skin_Sniper1_DZ", "magazine"}, {"G36C", "weapon"}, {"G36C_camo", "weapon"}, {"G36A_camo", "weapon"}, {"G36a", "weapon"}, {"G36K_camo", "weapon"}, {"G36K", "weapon"}, {"ItemBpt_b3", "magazine"}, {"ItemBpt_h3", "magazine"}};
        itemChance[] = {0.0199999996, 0.300000012, 0.0500000007, 0.0199999996, 0.00999999978, 0.00999999978, 0.0599999987, 0.0599999987, 0.0599999987, 0.00999999978, 0.899999976, 0.300000012, 0.00999999978, 0.0500000007, 0.0299999993, 0.0199999996, 0.0199999996, 0.0199999996, 0.0199999996, 0.0199999996, 0.00999999978, 0.00999999978};
    };
    class Hospital: Default
    {
        zombieChance = 0.400000006;
        minRoaming = 2;
        maxRoaming = 6;
        zombieClass[] = {"z_doctor", "z_doctor", "z_doctor", "ori_vil_zombie_woman1", "ori_vil_zombie_woman2", "ori_vil_zombie_woman3", "ori_vil_zombie_woman4", "ori_zombie1n", "ori_zombie4n", "ori_zombie1n", "ori_zombie4n"};
        lootChance = 1;
        lootPos[] = {};
        itemType[] = {{"", "trash"}, {"", "hospital"}};
        itemChance[] = {0.200000003, 0.5};
    };
    class Military: Default
    {
        zombieChance = 0.300000012;
        maxRoaming = 6;
        zombieClass[] = {"z_soldier", "z_soldier_heavy", "z_policeman", "ori_zombie6Ln"};
        lootChance = 0.400000006;
        lootPos[] = {};
        itemType[] = {{"M9", "weapon"}, {"M16A2", "weapon"}, {"M16A2GL", "weapon"}, {"M9SD", "weapon"}, {"AK_74", "weapon"}, {"M4A1_Aim", "weapon"}, {"AKS_74_kobra", "weapon"}, {"AKS_74_U", "weapon"}, {"AK_47_M", "weapon"}, {"M24", "weapon"}, {"M1014", "weapon"}, {"DMR", "weapon"}, {"M4A1", "weapon"}, {"M14_EP1", "weapon"}, {"UZI_EP1", "weapon"}, {"Remington870_lamp", "weapon"}, {"glock17_EP1", "weapon"}, {"MP5A5", "weapon"}, {"MP5SD", "weapon"}, {"M4A3_CCO_EP1", "weapon"}, {"Binocular", "weapon"}, {"ItemFlashlightRed", "military"}, {"ItemKnife", "military"}, {"ItemGPS", "weapon"}, {"ItemMap", "military"}, {"DZ_Assault_Pack_EP1", "object"}, {"DZ_Patrol_Pack_EP1", "object"}, {"", "trash"}, {"DZ_Backpack_EP1", "object"}, {"", "medical"}, {"", "generic"}, {"", "military"}, {"ItemEtool", "weapon"}, {"ItemSandbag", "magazine"}, {"Sa58P_EP1", "weapon"}, {"Sa58V_EP1", "weapon"}, {"ItemRestTent", "magazine"}, {"Ori_mosin", "weapon"}, {"Ori_PPS43", "weapon"}, {"ori_vil_uzi_rozkl", "weapon"}, {"ori_vil_uzi_sd", "weapon"}, {"ori_vil_uzimini", "weapon"}, {"ori_vil_uzimini_SD", "weapon"}, {"Ori_Sa48SMG", "weapon"}, {"Ori_SKS", "weapon"}, {"Ori_Tt33", "weapon"}, {"Ori_APS", "weapon"}, {"Ori_APS_SD", "weapon"}, {"Ori_cz75", "weapon"}, {"Ori_cz83", "weapon"}, {"Ori_mossberg", "weapon"}};
        itemChance[] = {0.0500000007, 0.0500000007, 0.00999999978, 0.0199999996, 0.0900000036, 0.00999999978, 0.0799999982, 0.0500000007, 0.0500000007, 0.00999999978, 0.0500000007, 0.00999999978, 0.0199999996, 0.00999999978, 0.0500000007, 0.0799999982, 0.100000001, 0.0399999991, 0.0199999996, 0.00999999978, 0.0599999987, 0.100000001, 0.100000001, 0.00999999978, 0.0500000007, 0.0599999987, 0.0399999991, 0.5, 0.0199999996, 0.100000001, 0.5, 0.5, 0.0500000007, 0.100000001, 0.0299999993, 0.0299999993, 0.00999999978, 0.00999999978, 0.0500000007, 0.0500000007, 0.0299999993, 0.0500000007, 0.0299999993, 0.0500000007, 0.0500000007, 0.0500000007, 0.0500000007, 0.0500000007, 0.0500000007, 0.0500000007, 0.100000001};
    };
    class MilitarySNovi: Default
    {
        zombieChance = 0.600000024;
        minRoaming = 2;
        maxRoaming = 6;
        zombieClass[] = {"z_soldier_pilot", "z_soldier", "z_soldier_heavy", "ori_zombie6n"};
        lootChance = 0.129999995;
        lootPos[] = {};
        itemType[] = {{"M16A2", "weapon"}, {"M16A2GL", "weapon"}, {"SCAR_L_CQC_CCO_SD", "weapon"}, {"", "trash"}, {"SCAR_L_CQC_Holo", "weapon"}, {"M1014", "weapon"}, {"huntingrifle", "weapon"}, {"SCAR_L_CQC_EGLM_Holo", "weapon"}, {"", "trash"}, {"SCAR_L_STD_EGLM_RCO", "weapon"}, {"M4A1_Aim_camo", "weapon"}, {"M4A1", "weapon"}, {"SCAR_L_STD_HOLO", "weapon"}, {"", "trash"}, {"SCAR_L_STD_Mk4CQT", "weapon"}, {"", "trash"}, {"Remington870_lamp", "weapon"}, {"glock17_EP1", "weapon"}, {"Skin_Sniper1_DZ", "magazine"}, {"SCAR_H_CQC_CCO", "weapon"}, {"", "trash"}, {"SCAR_H_CQC_CCO_SD", "weapon"}, {"M9", "weapon"}, {"MP5A5", "weapon"}, {"MP5SD", "weapon"}, {"SCAR_H_STD_EGLM_Spect", "weapon"}, {"", "trash"}, {"SCAR_H_LNG_Sniper", "weapon"}, {"", "trash"}, {"M9SD", "weapon"}, {"DZ_Backpack_EP1", "object"}, {"SCAR_H_LNG_Sniper_SD", "weapon"}, {"M4A1_RCO_GL", "weapon"}, {"M4A1_HWS_GL_SD_Camo", "weapon"}, {"M4A1_HWS_GL", "weapon"}, {"M24", "weapon"}, {"MG36", "weapon"}, {"MG36_camo", "weapon"}, {"AK_107_GL_pso", "weapon"}, {"Saiga12K", "weapon"}};
        itemChance[] = {0.100000001, 0.0500000007, 0.00999999978, 0.25, 0.00999999978, 0.150000006, 0.100000001, 0.00999999978, 0.200000003, 0.00999999978, 0.0500000007, 0.200000003, 0.00999999978, 0.100000001, 0.00999999978, 0.150000006, 0.200000003, 0.200000003, 0.0500000007, 0.00999999978, 0.219999999, 0.00999999978, 0.100000001, 0.100000001, 0.100000001, 0.00999999978, 0.300000012, 0.00999999978, 0.200000003, 0.100000001, 0.100000001, 0.00999999978, 0.100000001, 0.100000001, 0.100000001, 0.0500000007, 0.00999999978, 0.00999999978, 0.0500000007, 0.0500000007};
    };
    class MilitarySpecial: Default
    {
        zombieChance = 0.400000006;
        minRoaming = 2;
        maxRoaming = 6;
        zombieClass[] = {"z_soldier_heavy", "ori_zombie6Ln"};
        lootChance = 0.400000006;
        lootPos[] = {};
        itemType[] = {{"M16A2", "weapon"}, {"M16A2GL", "weapon"}, {"M249_DZ", "weapon"}, {"M9SD", "weapon"}, {"AK_74", "weapon"}, {"M4A1_Aim", "weapon"}, {"AKS_74_kobra", "weapon"}, {"AKS_74_U", "weapon"}, {"AK_47_M", "weapon"}, {"M24", "weapon"}, {"SVD_CAMO", "weapon"}, {"M1014", "weapon"}, {"huntingrifle", "weapon"}, {"DMR", "weapon"}, {"M4A1", "weapon"}, {"M14_EP1", "weapon"}, {"UZI_EP1", "weapon"}, {"Remington870_lamp", "weapon"}, {"glock17_EP1", "weapon"}, {"M240_DZ", "weapon"}, {"M4A1_AIM_SD_camo", "weapon"}, {"M16A4_ACG", "weapon"}, {"M4A1_HWS_GL_camo", "weapon"}, {"Mk_48_DZ", "weapon"}, {"M4A3_CCO_EP1", "weapon"}, {"Binocular", "weapon"}, {"ItemFlashlightRed", "military"}, {"ItemKnife", "military"}, {"ItemGPS", "weapon"}, {"ItemMap", "military"}, {"Binocular_Vector", "military"}, {"DZ_Assault_Pack_EP1", "object"}, {"DZ_Patrol_Pack_EP1", "object"}, {"DZ_Backpack_EP1", "object"}, {"", "medical"}, {"", "generic"}, {"", "military"}, {"Sa58V_RCO_EP1", "weapon"}, {"Sa58V_CCO_EP1", "weapon"}, {"M40A3", "weapon"}, {"ItemBpt_b2", "magazine"}, {"ItemBpt_h2", "magazine"}};
        itemChance[] = {0.100000001, 0.0500000007, 0.00999999978, 0.0199999996, 0.100000001, 0.0199999996, 0.100000001, 0.100000001, 0.100000001, 0.00999999978, 0.00999999978, 0.200000003, 0.00999999978, 0.0199999996, 0.100000001, 0.0299999993, 0.200000003, 0.100000001, 0.200000003, 0.00999999978, 0.0399999991, 0.0500000007, 0.0199999996, 0.00999999978, 0.0799999982, 0.100000001, 0.0500000007, 0.150000006, 0.00999999978, 0.0299999993, 0.00999999978, 0.0199999996, 0.0299999993, 0.0199999996, 0.300000012, 0.899999976, 0.800000012, 0.00999999978, 0.00999999978, 0.0199999996, 0.0199999996, 0.0199999996};
    };
    class Church: Residential
    {
        minRoaming = 1;
        maxRoaming = 3;
        zombieClass[] = {"z_priest", "z_priest", "z_priest"};
    };
    class Land_tav_Barrack2: MilitarySNovi
    {
        lootPos[] = {{1.24634004, 4.12891006, -0.689390004}, {1.14525998, 0.330078006, -0.721592009}, {-1.68640006, 3.84179997, -0.710402012}, {-2.18811011, -2.91601992, -0.69275701}, {1.37219, -0.96875, -0.653217018}};
    };
    class Land_tav_Ind_Pec_03_nov: IndNovistr
    {
        lootPos[] = {{7.11815977, -21.1865005, -5.36022997}, {3.15233994, -9.58788967, -5.35023022}, {8.63770008, 1.13916004, -5.34022999}, {-0.453125, -0.964354992, -5.34022999}, {-13.3866997, -10.0004997, -5.33023024}, {-7.76952982, -10.0312996, -5.32023001}, {-8.60352039, -15.8285999, -3.96721005}, {-9.10741997, -12.6348, -2.47037005}, {-13.2656002, -9.32763958, -2.45037007}, {11.7870998, -7.78174019, 5.82545996}, {-1.21581995, -13.3769999, 5.83546019}, {-0.919921994, 19.6870003, 4.09103012}};
    };
    class Land_tav_tovarna2: IndNovistr
    {
        lootPos[] = {{-11.6309004, 7.2052002, -5.55932999}, {-12.0674, 2.56908989, -5.55932999}, {-4.89354992, 6.63940001, -5.55932999}, {-3.74120998, 2.90392995, -3.89665008}, {-12.8671999, 1.44518995, -2.23134995}, {-12.415, 8.1310997, -2.23134995}, {-12.7236004, 4.11254978, -2.23134995}, {-3.99804997, 8.98009968, -2.23155999}, {-7.33104992, 8.44213963, -2.23155999}, {-4.55370998, 5.22643995, -2.23155999}, {-11.4745998, 2.92113996, 1.66661}, {-11.0703001, 8.13817978, 1.66661}, {-4.67577982, 7.32677984, 1.62173998}, {-2.68262005, 3.44762993, 3.42429996}, {-13.1953001, -8.95862007, 3.42429996}, {-8.80858994, -0.443480998, 0.401226014}, {-12.1328001, -0.149414003, 0.424297988}, {-2.03417993, 6.61414003, -5.55932999}, {0.239258006, 1.72277999, -5.59792995}, {6.22460985, -3.94799995, -4.61824989}, {-6.39354992, -8.24353027, -5.59540987}, {-10.8495998, -6.91210985, -5.56572008}, {-6.77637005, -1.73082995, -5.5601902}};
    };
    class Land_tav_Ind_Pec_03: Industrial
    {
        lootPos[] = {{11.7870998, -7.78174019, 6.71999979}, {-1.21581995, -13.3769999, 6.71999979}, {-0.919921994, 19.6870003, 4.94999981}, {7.11815977, -21.1865005, -4.48999977}, {3.15233994, -9.58788967, -4.4749999}, {8.63770008, 1.13916004, -4.4749999}, {-0.453125, -0.964354992, -4.48999977}, {-13.3866997, -10.0004997, -4.48999977}, {-7.76952982, -10.0312996, -4.48999977}, {-8.60352039, -15.8285999, -3.06720996}, {-9.10741997, -12.6348, -1.55999994}, {-13.2656002, -9.32763958, -1.55999994}};
    };
    class Land_Ind_Mlyn_01: IndustrialNew
    {
        lootPos[] = {{-6.88525009, 2.53320003, 9.12112999}, {-7.21045017, 2.5947299, 3.08799005}, {-2.69336009, 8.43848038, 0.188559994}, {-2.80614996, 8.02050972, -7.77156019}};
    };
    class Land_Ind_Mlyn_03: IndustrialNew
    {
        lootPos[] = {{-7.87793016, 6.75293016, -4.22196007}, {2.31103992, 1.54102004, -4.20196009}, {2.45068002, -7.54883003, -4.22196007}};
    };
    class Land_Barn_Metal: IndustrialNew
    {
        lootPos[] = {{-9.29102039, -25.2099991, 5.55810022}, {10.665, -6.75684023, 5.54809999}, {-3.79296994, -3.18163991, 5.46810007}, {10.5614996, 14.0341997, 5.52810001}, {9.87012005, 3.90625, -5.5019002}, {-6.71581984, 14.6953001, -5.49189997}, {-0.53027302, -14.2138996, -5.5019002}};
    };
    class Land_Ind_TankBig: IndustrialNew
    {
        lootPos[] = {{-3.74512005, 2.40503001, 5.40999985}, {1.77441001, -1.92455995, 5.40999985}};
    };
    class Land_Ind_SiloVelke_02: IndustrialNew
    {
        lootPos[] = {{9.44530964, 0.0566405989, 17.7159004}, {-6.57422018, 0.0644531026, 17.7059002}};
    };
    class Land_Ind_SiloVelke_01: IndustrialNew
    {
        lootPos[] = {{1.86816001, 6.25781012, 11.9013996}, {1.64258003, -1.85741997, 11.8514004}, {-5.67187977, 3.04296994, 11.8514004}, {2.01171994, -1.57813001, -5.45221996}, {2.01366997, 7.23047018, -5.46222019}};
    };
    class Land_Ind_Pec_03b: IndustrialNew
    {
        lootPos[] = {{1.79883003, -17.8339996, 5.72048998}, {-2.71093988, 10.7084999, 5.71049023}, {-2.08104992, 19.0790997, 3.96605992}, {0.714843988, 25.2520008, 3.96605992}};
    };
    class Land_Ind_Expedice_3: IndustrialNew
    {
        lootPos[] = {{1.86475003, -5.73145008, 2.15864992}, {2.06737995, 6.79297018, 2.11729002}, {-1.11278999, 17.6688995, 2.10160995}};
    };
    class Land_tav_HouseV2_01B: Residential
    {
        maxRoaming = 2;
        lootPos[] = {{-8.60888958, 2.91016006, 1.15647995}, {-9.13623047, -0.748046994, 1.16797996}, {-4.93896008, 3.45800996, 1.15673006}, {-1.05664003, 2.22167993, 1.15663004}, {-2.76758003, -1.0625, 5.43908978}, {-7.48485994, 0.986328006, 5.44909}, {-1.41699004, 4.82129002, 5.45909023}, {1.76758003, -0.648437977, 6.17909002}, {6.99364996, 4.53906012, 5.42909002}, {1.52489996, 1.26464999, 5.42909002}};
    };
    class Land_tav_guardhouse: Military
    {
        maxRoaming = 2;
        lootPos[] = {{0.0205077995, 2.83788991, -1.70790994}, {4.25976992, -0.359375, -1.68790996}, {-1, -0.617187977, -1.71791005}, {0.95214802, -3.1552701, -1.71791005}, {-2.46191001, -3.07129002, -1.03790998}, {-2.44433999, 3.08691001, -1.69070005}};
    };
    class Land_tav_houseblock_b1: NoviShop
    {
        maxRoaming = 3;
        lootPos[] = {{6.16601992, -2.40233994, -7.09656}, {5.99218988, -3.03760004, -6.73655987}, {6.06055021, -2.62743998, -6.38655996}, {6.36718988, -2.94042993, -6.38655996}, {6.14258003, -3.62987995, -7.08655977}, {8.55469036, -2.19042993, -6.73655987}, {8.50977039, -1.98730004, -6.38655996}, {8.92772961, -2.39550996, -6.02655983}, {8.98437977, -2.92773008, -6.02655983}, {8.90625, -1.74219, -6.73655987}, {6.72266006, 0.808593988, -6.69655991}, {7.74023008, 0.877440989, -6.67655993}, {3.38671994, 0.787598014, -6.78656006}, {9.625, 2.33788991, -7.28656006}, {-5.52733994, 2.25048995, -7.27885008}, {9.87304974, -2.16895008, -7.27655983}, {4.27733994, -1.25732005, -7.27655983}};
    };
    class Land_tav_houseblock_b4_in: Residential
    {
        maxRoaming = 3;
        lootPos[] = {{0.396483988, -1.99609005, -7.3045702}, {1.09375, 0.0253906008, -3.3261199}, {-4.12305021, 2.87304997, -3.28611994}, {-3.92479992, 2.9677701, -2.54611993}, {-1.61133003, 3.08398008, -2.29611993}, {-5.28710985, -2.07909989, -3.28611994}, {-1.53418005, -3.94531012, -3.31611991}, {5.0625, -2.58495998, -2.78611994}, {0.839843988, -3.99707007, -3.30611992}, {-5.37305021, 0.949218988, -3.31611991}};
    };
    class Land_tav_HouseV_2L: Residential
    {
        maxRoaming = 3;
        lootPos[] = {{2.94726992, -4.09789991, -3.05021}, {0.294921994, -1.46436, -3.05998993}, {0.492188007, 3.06396008, -4.07833004}, {4.24218988, 1.87793005, -4.00903988}, {-2.95116997, 2.56054997, -4.05833006}, {-1.30078006, -3.30419993, -1.13694}, {2.68554997, -4.24805021, -1.13486004}, {-3.62108994, 2.62524009, -0.594857991}, {1.5, 3.74561, -0.394856989}, {-2.23633003, -4.28051996, -4.07967997}};
    };
    class LAND_Domek_zluty_BEZ: Residential
    {
        maxRoaming = 3;
        lootPos[] = {{6.47559023, 2.75781012, -2.42348003}, {-0.326415986, -0.212890998, -2.42360997}, {0.686767995, 3.92773008, -2.40346003}, {-5.34692001, 3.45313001, -1.53342998}, {-7.04883003, -0.207030997, -2.42347002}, {-6.91845989, -3.81054997, -2.42357993}, {-2.61181998, -4.18944979, -2.42365003}};
    };
    class Land_Bulding_r: Residential
    {
        maxRoaming = 3;
        lootPos[] = {{-11.9140997, -7.70056009, -3.11492991}, {-5.33789015, -8.85352039, -3.11492991}, {9.8945303, -8.91662979, -3.1249299}, {3.59570003, 0.791137993, -3.11492991}, {-0.537109017, 4.5377202, -2.80492997}, {-4.25781012, 6.32971001, 0.536800027}, {3.08203006, 1.11962998, 0.546800971}, {-6.57616997, -8.63171005, 0.536800027}, {-4.57422018, 12.0749998, 0.536800027}, {-20.6483994, -12.1408997, 0.536800027}, {-17.9160004, -16.7217007, 0.546800971}, {8.28711033, -15.3203001, 0.536800027}, {13.3633003, -1.95349002, 0.526799977}};
    };
    class Land_Barrack2: TavianaDZ
    {
        lootChance = 0.200000003;
        lootPos[] = {{0.439453006, 4.26317978, -0.699447989}, {0.953125, 0.384276986, -0.70163703}, {-2.18358994, -2.62207007, -0.682883978}, {1.95313001, -2.72217011, -0.703167021}, {1.90039003, -0.907715023, -0.723221004}};
    };
    class LAND_x: Default
    {
        minRoaming = 0;
        maxRoaming = 1;
        zombieClass[] = {};
        lootPos[] = {};
    };
    class Land_zombie_spawn: Default
    {
        minRoaming = 0;
        maxRoaming = 1;
        zombieClass[] = {"z_Mutant"};
        lootPos[] = {};
    };
    class Land_dumruina_mini: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_statek_hl_bud: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_HouseBlock_D1_ex1: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_HouseBlock_D1: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_Zachytka: Military
    {
        maxRoaming = 10;
        lootPos[] = {{-5.17870998, 7.28466988, -1.99301004}, {1.39795005, 7.94970989, -1.99301004}, {4.55420017, 10.8319998, -1.99301004}, {5.0830102, 4.22118998, -1.99300003}, {-1.39453006, 4.51416016, -1.99300003}, {-5.75731993, 2.32421994, -1.99300003}, {0.952637017, -0.995604992, -1.99300003}, {-3.72167993, -2.36328006, -1.99301004}, {-4.80811024, -10.3930998, -1.99300003}, {2.38770008, -9.27490044, -1.99300003}};
    };
    class LAND_Tav_panelak: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{-3.66747999, -4.59960985, 0.0714263991}, {-2.21387005, 2.49218988, 0.0714263991}, {-6.28418016, 3.85938001, 0.0714263991}, {-4.82372999, -2.40625, 0.0714263991}, {-6.76464987, -6.64258003, 0.0714263991}, {-0.484375, 4.40625, 1.32863998}, {6.42920017, -4.50585985, 2.77144003}, {5.15381002, 3.66601992, 2.77144003}, {3.7241199, -4.16601992, 2.77144003}};
    };
    class LAND_skola: Residential
    {
        lootChance = 0.200000003;
        maxRoaming = 10;
        lootPos[] = {{8.60058975, -12.7743998, 1.22082996}, {-4.60889006, -10.2051001, 1.32082999}, {-6.5, -16.5897999, 1.22082996}, {-3.70898008, -24.3994007, 1.22082996}, {5.27025986, -25.1494007, 1.22082996}, {21.3393993, -8.22655964, 1.22082996}, {-20.6483994, -28.2068005, 0.793335021}, {22.2014008, -25.1807003, 1.22082996}, {-0.64892602, -1.40723002, 1.22082996}, {27.3041992, 5.35059023, 1.22082996}, {18.8962002, 5.44043016, 1.22082996}, {18.3691006, 22.2285004, 1.22082996}, {27.0818005, 22.3729992, 1.22082996}, {8.3125, 10.9531002, 1.22082996}, {-5.29639006, 6.95702982, 1.22082996}, {-5.99315977, 15.7616997, 1.32082999}, {4.7719698, 16.6182003, 1.22082996}, {-3.74926996, 21.2891006, 1.22082996}, {1.79321003, 6.14648008, -2.0036099}, {-6.06323004, 22.2187996, -2.0036099}, {-0.617919981, 14.4258003, -2.0036099}, {21.3600998, 5.67187977, -2.0036099}, {29.1709003, 7.13085985, -2.0036099}, {30.4447994, 18.6074009, -2.0036099}, {19.0806007, 22.6093998, -2.0036099}, {-18.5851994, -9.68358994, -2.0036099}, {-8.88379002, 3.60840011, -2.0036099}, {21.0681, -11.5801001, -2.0036099}, {5.00268984, -2.04150009, 0.681145012}, {2.51514006, 0.760254025, 1.22082996}};
    };
    class LAND_shopping_sab5: Supermarket
    {
        maxRoaming = 10;
        lootPos[] = {{6.17187977, 24.5352001, -2.18270993}, {8.87401962, 17.3554993, -2.18276}, {15.6436005, 12.2645998, -2.1828301}, {9.71924019, 7.09033012, -2.18282008}, {3.75976992, 14.6694002, -2.18274999}, {-3.05614996, 8.42284966, -2.18273997}, {-6.89599991, 3.85889006, -2.18274999}, {1.27637005, -2.76659989, -2.1828301}, {7.05273008, 3.07959008, -2.1828301}, {-13.8569002, 3.52881002, -2.18270993}, {-11.9926996, -3.16943002, -2.18270993}, {-0.359375, -9.20067978, -2.18270993}, {8.1469698, -10.0741997, -1.36222005}, {11.5654001, 0.53027302, -2.18284988}, {6.51366997, -4.82129002, -2.18284988}, {20.8159008, 10.3062, -1.36222005}, {21.3080997, 4.17479992, -1.36222005}};
    };
    class LAND_hockej_stadion: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_konecna: Residential
    {
        maxRoaming = 4;
        lootPos[] = {{-5.50487995, 8.19188976, -1.59363997}, {-3.93066001, 12.9603996, -1.59363997}, {-1.38524997, 10.1129999, -1.59363997}, {11.9131002, -0.400635004, -1.59363997}, {-4.71436024, -4.24364996, -1.59363997}, {8.53075981, -14.1370001, -1.59363997}, {20.2113991, -13.5977001, -1.59363997}, {19.1688995, -3.08593988, -1.59363997}};
    };
    class LAND_Big_Panelka: Residential
    {
        maxRoaming = 6;
        lootPos[] = {{2.72461009, -0.673828006, -14.7521}, {3.56103992, 3.88281012, -14.7521}, {8.94433975, -1.90770996, -14.7521}, {10.9813995, 0.0883788988, -14.7518997}};
    };
    class LAND_small_Panelka: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_garaz: Industrial
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class Land_Tav_Panelak3: Residential
    {
        maxRoaming = 4;
    };
    class Land_Tav_Panelak2: Residential
    {
        maxRoaming = 4;
        lootPos[] = {{0.293945014, -2.16016006, -2.62859011}, {-0.258789003, 4.4267602, -1.30137002}, {-0.249023005, -2.08398008, 0.071428299}, {-0.540039003, 2.82520008, 1.48863995}, {0.331054986, -2.11718988, 2.91096997}, {4.62793016, -1.43066001, 5.4366498}, {6.9375, -4.94237995, 5.4366498}, {6.50684023, 3.72851992, 5.4366498}, {2.95116997, 3.61133003, 5.4366498}};
    };
    class LAND_shopping_sab1: Supermarket
    {
        lootChance = 0.300000012;
        maxRoaming = 12;
        lootPos[] = {{-20.0849991, 20.2367992, -6.25662994}, {-23.8691006, 12.5678997, -6.25662994}, {-7.74805021, 12.6436005, -6.25662994}, {-15.5684004, 25.4687996, -6.25662994}, {11.2948999, 6.83495998, -6.25662994}, {17.2056007, 18.7749004, -6.25662994}, {11.3975, 27.7455997, -6.25662994}, {0.102539003, 22.6035004, -6.25662994}, {-10.1343002, 30.6821003, -6.25662994}, {-6.97168016, -10.4419003, -6.25662994}, {-23.6030006, -10.7573004, -6.25662994}, {-31.4120998, 7.58545017, -6.25662994}, {-2.49561, -5.6469698, -6.25662994}, {18.9712009, -12.1415997, -6.25684023}, {18.0986004, 3.27099991, -6.25662994}, {30.0249004, -6.47606993, -6.25662994}, {36.6094017, 2.45508003, -6.25662994}, {7.94531012, -17.1504002, -2.38664007}, {29.4857998, -20.3656998, -2.39281988}, {31.8311005, -26.1161995, -2.39699006}, {23.8062, -29.1963005, -2.39503002}, {22.8726006, -14.0180998, -2.38821006}, {40.3642998, -19.2593002, -2.38821006}, {42.0946999, -12.2627001, -2.38821006}, {36.3895988, 4.40868998, -2.38664007}, {25.2612, -4.44775009, -2.38664007}, {25.0604992, 10.5609999, -2.38664007}, {10.1772003, 12.8071003, -2.38664007}, {5.71483994, 16.9150009, -2.38664007}, {12.8091002, 24.3246994, -2.38664007}, {-12.9209003, 30.5352001, -2.38664007}, {-16.4102001, 24.9955997, -2.38664007}, {-23.3652, 29.6459999, -2.38664007}, {-31.6040001, 25.2744007, -2.38664007}, {-31.2187996, 21.0659008, -2.38664007}, {-30.3223, 10.8169003, -2.38664007}, {-40.0863991, -0.0424804986, -2.38664007}, {-22.6709003, -9.54932022, -2.38664007}, {-8.41895008, -14.1587, -2.38664007}, {-7.25537014, -29.0214996, -2.38664007}, {-1.09570003, -19.6679993, -2.38664007}};
    };
    class Land_statek_brana: Farm
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_Statek_kulna: Farm
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_Hotel: Residential
    {
        lootChance = 0.300000012;
        maxRoaming = 10;
        lootPos[] = {{-12.1133003, 12.4419003, -7.53041983}, {-18.6973, -2.91845989, -7.64674997}, {-6.98535013, 7.09435987, -7.62251997}, {-9.23145008, -14.5623999, -7.69154978}, {-1.65137005, -22.9067001, -7.53679991}, {5.53125, -9.09362984, -7.52279997}, {18.4141006, 2.01928997, -7.93569994}, {1.40526998, 22.5328007, -7.61163998}, {-6.51464987, 13.7124996, -7.58347988}, {1.10156, 4.91199017, -7.72601986}, {8.56737995, -0.873778999, -7.97876978}, {-0.185546994, -1.58336997, -4.26797009}, {4.11327982, -17.9395008, -4.3112402}, {-1.14550996, -23.3689003, -4.18951988}, {-7.72460985, -14.7784004, -4.21828985}, {-18.4706993, -4.1572299, -4.16676998}, {-20.0429993, -1.46996999, -4.15566015}, {-17.9608994, 6.8199501, -4.0912199}, {-13.1279001, 7.21837997, -4.06750011}, {0.290039003, 6.35985994, -4.22013998}, {-3.70508003, 18.1742001, -4.09729004}, {1.52637005, 20.1590996, -4.14155006}, {21.5800991, 0.0534668006, -4.49634981}, {-0.462891012, -1.63513005, -0.764894009}, {-0.903320014, -21.0625, -0.718954027}, {14.1845999, -6.54431009, -0.958742023}, {18.6895008, 4.21460009, -0.93640399}, {20.8740005, -1.52063, -0.998733997}, {1.39063001, 20.5510006, -0.637068987}, {0.426757991, 7.36645985, -0.714541018}, {-9.52929974, 1.23803997, -0.646017015}, {7.35839987, -0.228270993, 1.03269994}, {1.69433999, -3.09766006, 2.70148993}, {-9.79491997, -14.3830996, 2.80007005}, {-5.73729992, -15.0978003, 2.76387}, {4.50781012, -18.5471001, 2.69181991}, {-1.48339999, -21.1569004, 2.78840995}, {13.7694998, -9.43395996, 2.52639008}, {17.1025009, 3.14477992, 2.57377005}, {5.0927701, 8.44556046, 2.74124002}, {6.3857398, 18.0823002, 2.79139996}, {2.2490201, 23.4939995, 2.85944009}, {-2.27343988, 21.7740002, 2.9112699}, {0.607421994, 7.07520008, 2.78139997}, {-10.7323999, 7.24023008, 2.90718007}, {-17.8311005, -3.34961009, 2.84166002}, {-20.7714996, 1.62963998, 2.86211991}, {6.38770008, 1.60095, 4.54189014}, {0.129883006, -1.36096001, 6.23433018}, {0.232421994, 6.25537014, 6.28407001}, {-2.66504002, -16.9747009, 6.25620985}, {-7.4072299, -0.0731201023, 6.32579994}, {-13.5254002, 8.42249012, 6.44308996}, {1.26855004, 20.7710991, 6.36964989}, {11.7334003, 3.17261004, 6.36703014}};
    };
    class LAND_domek05: Residential
    {
        maxRoaming = 7;
        lootPos[] = {{-4.85106993, -1.41308999, -2.79727006}, {-4.92187977, 1.28662002, -2.79728007}, {0.28027299, -1.30566001, -2.79728007}, {2.28516006, -1.74804997, -2.79727006}, {4.56299019, 0.943848014, -2.79727006}};
    };
    class LAND_ZalChata: Residential
    {
        maxRoaming = 2;
        lootPos[] = {{-0.40527299, -3.00084996, -0.631011009}};
    };
    class LAND_hotel_rivera2: Residential
    {
        maxRoaming = 4;
        lootPos[] = {{-6.81641006, -8.87415028, -0.227415994}, {-6.94629002, 2.83325005, -0.395830989}};
    };
    class LAND_hotel_rivera1: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{10.8144999, 4.72375011, -0.209453002}, {2.43163991, 6.83556986, -0.271955997}, {-6.52733994, 5.13610983, -0.358276993}};
    };
    class LAND_Posta: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{-15.4491997, 15.625, 1.00044}, {-13.2480001, 2.375, 1.00044}, {-3.58788991, 7.85645008, 1.00044}, {-14.9326, -5.10937977, 1.00044}, {-1.98046994, -7.83202982, 1.00044}, {12.4336004, -5.13379002, 1.00044}, {11.2167997, 12.8515997, 1.00044}};
    };
    class LAND_bus_depo: Industrial
    {
        maxRoaming = 5;
        lootPos[] = {{46.2206993, -12.0497999, -11.0229998}, {41.7187996, -16.0869007, -11.0229998}, {33.9931984, -27.4717007, -11.0229998}, {34.5575981, -22.0527, -11.0229998}, {27.3031998, -11.8188, -11.0229998}, {20.5039005, -15.9301996, -11.0229998}, {22.4487, -38.8652, -11.0229998}, {12.3017998, -33.7636986, -11.0229998}, {12.3319998, -27.6063995, -11.0229998}, {8.68700981, -11.8339996, -11.0229998}, {-6.22606993, -15.6729002, -11.0229998}, {-6.70020008, -26.4193993, -11.0229998}, {-9.3007803, -38.2963982, -11.0229998}, {-17.5396004, -40.0761986, -11.0229998}, {-17.5771008, -20.0937996, -11.0229998}, {-12.4267998, -9.2739296, -11.0229998}, {-23.0517998, -24.9692001, -11.0229998}, {-40.2495003, -25.6688995, -11.0229998}, {-34.6820984, -15.7069998, -11.0229998}, {-22.8115005, -2.72606993, -11.0229998}, {-23.3407993, 15.585, -11.0229998}, {-30.1620998, 35.7080002, -11.0229998}, {-23.6079006, 32.4618988, -11.0229998}};
    };
    class LAND_casino: Residential
    {
        maxRoaming = 5;
        lootPos[] = {};
    };
    class LAND_Parlament: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{14.3895998, 16.2479992, -8.68904972}, {9.83300972, -8.93848038, -8.68904972}, {10.9756002, -22.2968998, -8.68904972}, {-3.57520008, -15.6767998, -8.68904972}, {-10.0946999, -3.38965011, -8.68904972}, {-32.4775009, -11.9082003, -9.15828037}, {-41.9608994, -6.9052701, -8.68904972}, {-20.8778992, -0.0322265998, -8.68904972}, {-23.3994007, 9.42383003, -8.68904972}, {-36.8358994, 12.3270998, -8.68904972}, {-23.6777, 6.11327982, -4.44802999}, {-23.1835995, 0.365233988, -4.44802999}, {-37.2666016, 3.17383003, -4.44802999}, {-11.3095999, -14.6239996, -1.57749999}, {-16.0293007, -2.89354992, -1.57749999}, {-9.78905964, 17.9071999, -1.00882006}, {2.22656012, 22.0771008, 1.06897998}, {6.81737995, 18.7187996, -0.604358971}, {15.8086004, 10.7207003, -1.57749999}, {12.6025, -14.8163996, -1.57749999}, {11.9071999, -23.6543007, -1.57749999}, {-6.17479992, -23.7324009, -1.57749999}};
    };
    class LAND_Galerie: Residential
    {
        lootChance = 0.200000003;
        maxRoaming = 5;
        lootPos[] = {{2.29979992, -15.3848, -4.03873014}, {-3.52148008, -5.57520008, -4.03873014}, {-0.50097698, 6.5205102, -4.03873014}, {3.08398008, 17.0321999, -4.03873014}, {7.05077982, 21.6532993, -4.03873014}, {15.0928001, 20.6688995, -4.03873014}, {9.73145008, 13.6855001, -4.03873014}, {6.77148008, 6.11620998, -4.03873014}, {10.415, -5.66601992, -4.03873014}, {17.2861004, -0.505859017, -4.03873014}, {14.7919998, -11.7265997, -4.03873014}, {7.39354992, -9.91991997, -4.03873014}, {11.9823999, -23.0995998, -4.03873014}, {17.0126991, -22.9160004, -4.03873014}, {-6.96387005, -22.4403992, -4.03873014}, {-16.3311005, -20.2607002, -4.03873014}, {-8.69629002, -12.6553001, -4.03873014}, {-15.2529001, -3.19042993, -4.03873014}, {-12.7792997, 0.00878905971, -4.03873014}, {-7.13866997, 5.29004002, -4.03873014}, {-12.3525, 16.9081993, -4.03873014}, {-16.9335995, 11.4091997, -4.03873014}, {-17.1718998, 23.0137005, -4.03873014}, {-0.325195014, 23.1650009, -2.77150989}, {2.25292993, 10.8837996, -0.0799408033}, {-0.390625, -21.5741997, -0.0799408033}, {-15.8799, -21.9678001, -0.0799408033}, {-8.38183975, -15.25, -0.0799408033}, {-15.9921999, -3.94824004, -0.0799408033}, {-9.87598038, 2.0615201, -0.0799408033}, {-15.7167997, 20.9794998, -0.0799408033}, {-7.9267602, 21.0272999, -0.0799408033}, {7.2919898, 21.8848, -0.0799408033}, {9.74707031, 14.2616997, -0.0799408033}, {16.7217007, 15.6582003, -0.0799408033}, {15.3125, 4.15233994, -0.0799408033}, {9.31542969, -2.77637005, -0.0799408033}, {8.64258003, -12.2245998, -0.0799408033}, {15.8739996, -15.8506002, -0.0799408033}, {8.00195026, -22.6797009, -0.0799408033}};
    };
    class LAND_Stojan_Bus: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{-0.432617009, -4.72362995, -2.94724989}, {-0.138671994, 2.72167993, -2.94724989}, {-0.0273438003, 14.0723, -2.94724989}};
    };
    class LAND_dum_patrovy03: Residential
    {
        maxRoaming = 5;
        lootPos[] = {};
    };
    class LAND_Cinzak_long: Residential
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class LAND_Cinzak_corner2: Residential
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class LAND_Cinzak_long_centr: Residential
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class LAND_Cinzak_corner: Residential
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class LAND_Cinzak_long_double: Residential
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class LAND_hospoda: Residential
    {
        maxRoaming = 10;
        lootPos[] = {{-6.74023008, 5.91797018, -1.80274999}, {-3.31737995, -4.91406012, -1.80291998}, {7.20214987, -7.9677701, -1.80262005}, {7.2607398, -2.91796994, -1.80280006}, {0.15918, 4.6669898, -1.80324996}, {-0.799804986, 2.0615201, -1.80331004}};
    };
    class LAND_spital: Hospital
    {
        maxRoaming = 10;
        lootPos[] = {{26.7460995, 5.39745998, -20.3687992}, {27.5380993, -11.8232002, -20.3687992}, {27.3848, -4.24023008, -20.3687992}, {16.9307003, -1.49316001, -20.3687992}, {4.95116997, -14.4082003, -20.3687992}, {-0.453125, -8.02929974, -20.3687992}, {-3.30566001, 0.111327998, -20.3687992}, {-16.3808994, 0.611328006, -20.3687992}, {-15.0839996, 5.4375, -20.3687992}};
    };
    class LAND_Podloubi_double_low: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_Podloubi_End_Low_1: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_Podloubi_End_Low_2: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_Garaz_velka: Industrial
    {
        maxRoaming = 3;
        lootPos[] = {{23.1903992, 13.9424, 2.0199101}, {3.24120998, -11.0928001, 2.00445008}, {-18.8145008, -6.86035013, 1.98736}, {-1.86914003, 31.0566006, -0.0248146001}, {9.60155964, 6.17089987, -1.75023997}, {-16.4717007, -7.52930021, -1.77043998}, {-1.99414003, 24.2987995, -3.89750004}, {5.67577982, 14.3477001, -5.51864004}, {18.3740005, 7.62694979, -5.50880003}, {12.4442997, -6.52539015, -5.51339006}, {-22.5498009, -19.5303001, -5.54051018}};
    };
    class LAND_Hotel_Marcomio: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_shopping_sab2: Supermarket
    {
        maxRoaming = 3;
        lootPos[] = {{-3.02245998, -9.18651962, -3.66147995}, {2.74120998, -0.43652299, -3.66147995}, {-2.81445003, 9.39941025, -3.66147995}, {-8.21387005, 8.58104992, -3.66147995}, {-4.82520008, 20.6103992, -3.66147995}, {3.17479992, 21.4013996, -3.66147995}, {-11.0781002, -11.7069998, -3.66147995}, {-11.3046999, -1.60938001, -3.66147995}, {7.66601992, -10.1807003, -3.66147995}, {9.92284966, -2.89453006, -3.66147995}, {-19.9062996, -0.12207, -6.70005989}, {23.7675991, 4.6455102, -3.65214992}, {11.5692997, 3.95995998, -3.65814996}, {10.6962996, 10.0067997, -3.65598989}};
    };
    class LAND_Nadrazi_sabina: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{9.39159966, 2.63770008, -18.6089993}, {12.6190996, -13.3779001, -18.0830002}, {-12.0859003, -13.4140997, -18.0592003}, {-10.3866997, 11.1562996, -20.5583992}, {18.3036995, 25.9717007, -23.8341007}, {-16.3701, 27.2012005, -24.9899998}, {-28.5869007, 29.3104992, -24.9899998}, {-31.9834003, -6.94726992, -18.0517006}, {-21.3544998, -38.3886986, -12.6000996}, {-5.75585985, -43.2910004, -12.6138}, {9.5820303, -38.4443016, -12.5712004}, {19.1826, -42.455101, -12.5953999}, {-1.72852004, -27.6846008, -22.0921001}, {19.6210995, -30.2168007, -22.0317993}, {28.9629002, -26.2432003, -21.9936008}};
    };
    class LAND_dum_patrovy06: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_dum_mesto: Residential
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class Land_leseni2x: Residential
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class LAND_Autosalon: Residential
    {
        maxRoaming = 4;
        lootPos[] = {{-0.675781012, -2.78906012, -8.88722038}, {9.98241997, 0.103515998, -8.88722038}, {13.1133003, 11.5214996, -8.88722038}, {18.6688995, 20.7616997, -8.88722038}, {7.25781012, 17.5869007, -8.88722038}, {-1.80370998, 22.6142998, -8.88722038}, {-20.9941006, -4.57520008, -1.02025998}, {-8.07324028, 19.5419998, -1.02025998}, {-4.66112995, 9.11816025, -1.02025998}, {3.75292993, 8.75487995, -1.02025998}, {13.1406002, 19.0321999, -1.02025998}, {15.6493998, 4.3232398, -1.02025998}};
    };
    class LAND_Banka: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{3.83691001, -15.7803001, -25.6121998}, {5.27539015, -7.6455102, -25.6121998}, {13.2227001, -7.44335985, -25.6121998}, {11.8125, -11.6328001, -25.6121998}};
    };
    class LAND_Muzeum: Residential
    {
        maxRoaming = 15;
        lootPos[] = {};
    };
    class Land_budova4_in: Military
    {
        maxRoaming = 3;
        lootPos[] = {{5.85351992, -2.57470989, -1.88722003}, {2.91601992, 1.52587998, -1.88722003}, {-3.42578006, 1.62987995, -1.88722003}};
    };
    class LAND_vokzal_big: Residential
    {
        maxRoaming = 3;
        lootPos[] = {{-8.12695026, -7.29883003, -7.96283007}, {4.75684023, -7.01270008, -7.96283007}, {5.32714987, -0.784179986, -7.96283007}, {3.16308999, 2.8115201, -7.96283007}, {-4.88281012, 1.66112995, -7.96283007}};
    };
    class LAND_big_church: Church
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_Ruske_kolo: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_Bufet: Residential
    {
        maxRoaming = 3;
        lootPos[] = {{10.9902, -1.64453006, -1.71350002}, {6.5302701, -2.49707007, -1.71350002}, {4.95410013, -6.7294898, -1.71350002}, {-1.73046994, -12.3477001, -1.71350002}, {3.03808999, -3.75781012, -1.71350002}, {-4.38379002, -7.69726992, -1.71350002}, {-0.751953006, -1.20019996, -1.71350002}, {6.97559023, 4.30762005, -1.71350002}, {-0.258789003, 2.55762005, -1.71350002}, {-6.70898008, 3.59179997, -1.71350002}, {-7.43555021, -5.57520008, -1.71350002}};
    };
    class LAND_Bus_Stojan_Bud: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_Cinzak_roh2: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_Cinzak_roh3: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_Cinzak_trojuhlenik: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_kanovka_budova: Industrial
    {
        maxRoaming = 3;
        lootPos[] = {{-4.9365201, -3.72851992, -6.58417988}, {-6.65625, 10.7011995, -6.58417988}};
    };
    class LAND_kanovka_budova_snich: Industrial
    {
        maxRoaming = 3;
        lootPos[] = {{-12.3037004, -0.175780997, -7.46694994}, {-6.47118998, -8.65233994, -7.46694994}, {-4.8134799, -3.49023008, -7.46694994}};
    };
    class LAND_HouseV_2I_snow: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_bouda1_zima: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_kasarna_brana: Military
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_kasarna: Military
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_kasarna_prujezd: Military
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_kasarna_rohova: Military
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class LAND_watertower1: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class OSShDY_base: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class CD2: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Ds: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_afbarabizna: Residential
    {
        maxRoaming = 10;
        lootPos[] = {{5.24512005, 5.3703599, -4.19494009}, {5.20116997, -1.52295005, -4.22116995}, {-2.97362995, -1.07031, -4.22116995}, {-2.50391006, 5.43676996, -4.22116995}, {5.04004002, -0.233642995, -0.168262005}};
    };
    class Land_fuelstation_army: Military
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_army_hut_int: Military
    {
        maxRoaming = 3;
        lootPos[] = {{1.64453006, -5.52002001, -1.33055997}, {0.53125, 1.72607005, -1.36390996}};
    };
    class Land_army_hut3_long_int: Military
    {
        maxRoaming = 3;
        lootPos[] = {{-1.72802997, -0.726562977, -1.23617005}, {-2.26415992, -4.8740201, -1.23617005}, {-0.449218988, 3.7133801, -1.23617005}};
    };
    class Land_army_hut2_int: Military
    {
        maxRoaming = 3;
        lootPos[] = {{0.703369021, 0.560546994, -0.948328018}, {1.6875, -2.17627001, -0.948328018}};
    };
    class Land_cihlovej_dum_in: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{1.87743998, 2.3759799, -5.27587986}, {-1.71484005, 1.78710997, -1.81470001}, {0.640137017, -1.39795005, -1.81472003}};
    };
    class Land_dum_mesto_in: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{-4.72754002, -0.462401986, -4.23206997}, {5.52393007, -1.52441001, -4.21336985}, {-4.91895008, 3.55243993, -4.27988005}, {5.21289015, 2.88671994, -1.27999997}, {5.27440977, -1.26953006, -1.23013997}, {-3.92675996, 4.3217802, -1.56757998}, {-3.16260004, -0.68847698, -1.22934997}};
    };
    class Land_sara_Domek_sedy: Residential
    {
        maxRoaming = 3;
        lootPos[] = {{-1.28320003, 0.84472698, -2.14195991}, {-3.59521008, 3.14893007, -2.14197993}, {4.49567986, 2.2133801, -2.14195991}};
    };
    class Land_hruzdum: Residential
    {
        maxRoaming = 3;
        lootPos[] = {{1.31640995, 2.11474991, 1.59320998}, {-1.16504002, 0.63964802, 1.59320998}, {0.558593988, 2.17695999, -1.16264999}};
    };
    class Land_tovarna1: Industrial
    {
        maxRoaming = 5;
        lootPos[] = {{1.59081995, -4.73145008, -5.7544198}, {-6.48047018, -0.565429986, -5.7544198}, {-9.13379002, 4, 4.82972002}, {-5.4169898, -6.46045017, 4.82972002}, {3.56592011, -7.53319979, -0.320107013}, {1.14160001, -6.83887005, 2.17997003}, {2.71288991, 1.61425996, 2.15098}, {-9.2114296, -6.2822299, 2.17997003}};
    };
    class Land_ryb_domek: Residential
    {
        maxRoaming = 2;
        lootPos[] = {{-0.0595703013, -1.03418005, -2.0150001}};
    };
    class Land_benzina_schnell: Industrial
    {
        maxRoaming = 7;
        lootPos[] = {};
    };
    class Land_deutshe_mini: Residential
    {
        maxRoaming = 3;
        lootPos[] = {{-1.81348002, 2.3696301, -2.79261994}, {-2.11768007, -0.958007991, -2.73061991}, {3.41356993, 0.916504025, -2.78434992}, {3.76171994, -2.10693002, -2.73064995}};
    };
    class Land_sara_stodola: Farm
    {
        maxRoaming = 3;
        lootPos[] = {{-2.94824004, -0.0193847995, -2.19523001}, {4.0830102, -1.08350003, -2.19523001}};
    };
    class Land_hut01: Residential
    {
        maxRoaming = 2;
        lootPos[] = {0.323242009, 1.36377001, -0.448339999};
    };
    class Land_hut02: Residential
    {
        maxRoaming = 2;
        lootPos[] = {-0.162597999, 1.24706995, -0.445762992};
    };
    class Land_hut04: Residential
    {
        maxRoaming = 2;
        lootPos[] = {-0.0205077995, 1.74512005, -0.437198013};
    };
    class Land_hut03: Residential
    {
        maxRoaming = 2;
        lootPos[] = {};
    };
    class Land_hut_old02: Industrial
    {
        maxRoaming = 5;
        lootPos[] = {{0.573242009, -7.09033012, -3.0330801}, {0.1875, 0.723145008, -3.0330801}, {-7.09033012, -3.14648008, -3.0330801}, {-7.18456984, 1.79688001, -3.0330801}};
    };
    class Land_dum_rasovna: Residential
    {
        maxRoaming = 3;
        lootPos[] = {{1.02197003, 3.18603992, 0.272605985}, {1.36816001, 1.83447003, -2.66957998}};
    };
    class Land_dum_istan3_pumpa: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{3.21826005, 0.550293028, 1.47485006}, {-2.80614996, 0.327636987, 1.47485006}};
    };
    class Land_dum_istan3_hromada2: Residential
    {
        maxRoaming = 5;
        lootPos[] = {{-1.50048995, 4.32764006, -1.28516996}, {-1.12061, -3.42383003, -1.28516996}, {4.62012005, -3.88379002, 2.08801007}, {6.20166016, 2.9365201, 2.08801007}};
    };
    class Land_fuelstation: Industrial
    {
        maxRoaming = 10;
    };
    class Land_chilovej_dum_mini: Residential
    {
        maxRoaming = 3;
        lootPos[] = {2.51220989, 2.39453006, -2.86942005};
    };
    class Land_dum_mesto2: Residential
    {
        maxRoaming = 10;
        lootPos[] = {{-2.2177701, 5.00585985, -0.944006026}, {1.03662002, 6.85106993, -0.944006026}, {-1.46631002, -5.90137005, -0.944006026}, {0.75732398, -3.82909989, -0.944006026}, {-2.23193002, -6.66845989, -4.34474993}, {-1.34229004, -2.26806998, -4.34474993}, {2.40282989, 4.83936024, -4.34474993}, {-1.56201005, 5.76904011, -4.34474993}};
    };
    class Land_HouseV_1I4: Residential
    {
        lootPos[] = {{-0.400146008, -3.87695003, -2.76879001}, {-3.67749, -2.52002001, -2.76551008}, {-0.472167999, 3.19702005, -2.72021008}};
    };
    class Land_kulna: Residential
    {
        lootPos[] = {{0.504395008, 0.218262002, -1.11643004}, {-0.496582001, 1.93262005, -1.12826002}};
    };
    class Land_Ind_Workshop01_01: Industrial
    {
        lootPos[] = {{0.595215023, -2.43114996, -1.29411995}, {1.24364996, 0.463867009, -1.29499996}, {-0.66357398, -0.502929986, -1.29837}};
    };
    class Land_Ind_Garage01: Industrial
    {
        lootPos[] = {{-0.580078006, -1.49706995, -1.23483002}, {-0.834473014, 2.75781012, -1.22563004}, {2.47754002, -1.12890995, -1.23714006}, {1.31933999, 1.63085997, -1.23228002}};
    };
    class Land_Ind_Workshop01_02: Industrial
    {
        lootPos[] = {{1.15429997, -0.552245975, -1.42943001}, {-1.18665004, -0.178222999, -1.42867994}, {-0.661620975, 1.10399997, -1.42682004}};
    };
    class Land_Ind_Workshop01_04: Industrial
    {
        lootPos[] = {{-1.37415004, 4.18896008, -1.53122997}, {0.695434988, 4.24561024, -1.52934003}, {-1.06676996, 2.69531012, -1.53061998}, {0.792479992, -4.60741997, -1.49340999}, {-1.84423995, -6.17089987, -1.44427001}, {-1.05566001, -4.08398008, -1.51926994}, {1.43773997, -6.59424019, -1.41742003}};
        hangPos[] = {{-0.541747987, 4.01220989, -2.03067994}};
    };
    class Land_Ind_Workshop01_L: Industrial
    {
        lootPos[] = {{-3.26171994, 4.75438976, -1.30245996}, {0.175780997, 3.91747999, -1.30765998}, {-2.37891006, 2.35302997, -1.30404997}, {4.10547018, -4.10791016, -1.31344998}, {0.727539003, -2.61620998, -1.31418002}, {2.54688001, -2.17724991, -1.31482005}, {1.52344, -3.79443002, -1.31332004}};
    };
    class Land_Hangar_2: Industrial
    {
        lootPos[] = {{10.1245003, -6.48729992, -2.56316996}, {11.9386997, 7.91112995, -2.56316996}, {1.79516995, 7.12694979, -2.56316996}, {-11.8948002, 10.5448999, -2.56316996}, {-8.97021008, -4.34766006, -2.56316996}, {-0.562744021, -7.59375, -2.56316996}, {5.98803997, -2.61229992, -2.56316996}};
    };
    class Land_hut06: Residential
    {
        lootPos[] = {{0.328125, 2.26953006, -1.57786}, {-0.552367985, -0.0620117001, -1.53837001}};
    };
    class Land_stodola_old_open: Farm
    {
        lootPos[] = {{-3.06836009, 8.63183975, -5.08054018}, {2.5258801, 10.5261002, -5.08051014}, {4.76758003, 5.00854015, -0.993499994}, {-2.78467011, 10.2368002, -0.993499994}, {4.6259799, 10.4982996, -0.993469}, {2.09082007, 10.8424997, 2.96447992}, {-0.440917999, 10.3091002, 2.96444988}, {-2.5883801, -5.91821003, -5.08054018}, {4.11083984, -10.9301996, -5.08054018}, {-2.62842011, -6.55518007, -1.01584005}, {2.5053699, -10.7410002, 2.96444988}, {0.0410155989, -11.0595999, 2.96444988}};
        hangPos[] = {{-1.50537002, 5.3447299, -5.08813}, {0.494141012, 9.42724991, -5.09015989}, {2.5947299, -6.21190977, -5.08055019}, {-1.74854004, -2.39843988, -1.14301002}};
    };
    class Land_A_FuelStation_Build: Industrial
    {
        lootChance = 0.5;
        zombieClass[] = {"zZombie_Base", "zZombie_Base", "z_teacher", "z_suit1", "z_suit2"};
        lootPos[] = {{-1.31957996, -0.65515101, -1.57448006}, {1.82349002, 0.769653022, -1.57457995}, {1.67870998, -0.918700993, -1.57457995}, {-1.23241997, 1.26794004, -1.57457995}};
    };
    class Land_A_GeneralStore_01: Supermarket
    {
        lootPos[] = {{-9.38965034, -3.30370998, -1.20155001}, {-3.77538991, -3.86864996, -1.20155001}, {1.31835997, 1.46631002, -1.20155001}, {9.01366997, 3.84570003, -1.20155001}, {13.3008003, -1.77831995, -1.20155001}, {9.81054974, 1.43212998, -1.20155001}, {1.65039003, 5.14354992, -1.20155001}, {0.753906012, -3.69531012, -1.20155001}, {13.3125, -7.65137005, -1.20155001}, {11.1680002, -3.73681998, -1.20155001}, {8.8945303, -8.37401962, -1.20155001}, {-2.04491997, -7.58104992, -1.20155001}, {-7.84766006, -5.73633003, -1.20155001}, {-8.22461033, -7.32422018, -1.20155001}, {3.79004002, -5.69335985, -1.20155001}, {-9.38379002, 4.46190977, -1.20155001}, {-3.57520008, 4.46533012, -1.20155001}, {-3.33788991, 0.612793028, -1.20155001}, {10.5917997, -9.94579983, -1.21081996}, {0.105469003, -9.60840034, -1.21081996}, {-4.86035013, -10.4209003, -1.21081996}, {-6.80858994, -1.23975003, -1.20155001}, {1.12206995, -1.58887005, -1.20155001}};
    };
    class Land_Farm_Cowshed_a: Farm
    {
        lootPos[] = {{-1.06835997, -5.92162991, -3.08763003}, {1.69043005, -4.9108901, -3.08763003}, {5.88329983, -6.15381002, -3.08763003}, {8.83983994, -5.60277987, -3.08763003}, {9.74022961, -2.48656988, -3.08763003}, {2.88427997, -2.34545994, -3.08763003}, {7.88037014, 2.9421401, -3.08763003}};
    };
    class Land_stodola_open: Farm
    {
        lootPos[] = {{-2.60302997, 5.31664991, -4.12803984}, {-2.58154011, -0.530028999, -4.17349005}, {-0.0478515998, -4.88989019, -4.13600016}, {0.98339802, 6.20483017, -4.11143017}};
        hangPos[] = {{-0.932617009, -3.35962009, -4.16446018}, {-2.01563001, -0.115111999, -4.19492006}};
    };
    class Land_Barn_W_01: Farm
    {
        lootPos[] = {{4.93188, -17.0443993, -2.63063002}, {-3.82813001, -18.6699009, -2.63035989}, {-4.46387005, 16.6665001, -2.6365099}, {5.78710985, 18.9473, -2.63689995}, {3.95409989, 4.8842802, -2.63445997}, {-2.99072003, -4.16747999, -2.63286996}};
    };
    class Land_Hlidac_budka: Residential
    {
        lootPos[] = {{-2.31859994, 1.51269996, -0.783630013}, {2.02075005, 0.444335997, -0.783630013}, {-0.460938007, 1.75879002, -0.783630013}};
    };
    class Land_HouseV2_02_Interier: Residential
    {
        lootPos[] = {{7.23095989, 5.37206984, -5.53067017}, {8.55004978, 0.754882991, -5.53067017}, {5.20166016, -1.54004002, -5.53067017}, {3.3491199, 1.97070003, -5.53067017}, {-3.6259799, 3.05370998, -5.53067017}, {-5.48120022, -0.0292968992, -5.53067017}, {-5.83325005, 3.26563001, -5.53067017}, {-5.71045017, 5.49414015, -5.53067017}};
    };
    class Land_a_stationhouse: Military
    {
        lootChance = 0.300000012;
        lootPos[] = {{-2.69921994, -7.57422018, -9.4705801}, {-0.892578006, -5.71680021, -9.4705801}, {-3.24169993, -6.61914015, -4.64890003}, {-1.35644996, -8.36229992, -4.64890003}, {-1.70800996, -7.8544898, -0.0437926985}, {-3.39502001, -7.88281012, -0.0437926985}, {-1.39600003, -7.79883003, 4.41140985}, {-1.37939, -5.79101992, 4.41140985}, {1.51269996, 1.96484005, -9.4705801}, {18.9057999, -4.06737995, -9.4705801}};
    };
    class Land_Mil_ControlTower: Military
    {
        lootChance = 0.400000006;
        lootPos[] = {{10.0703001, 3.76366997, -9.62868977}, {3.89843988, 3.43457007, -5.46367979}, {1.75195003, 5.68164015, -5.46367979}, {6.66112995, -0.625487983, -1.06869996}, {2.63965011, -0.191405997, -1.06869996}, {6.72266006, 3.23389006, -1.06869996}};
    };
    class Land_SS_hangar: Military
    {
        maxRoaming = 3;
        lootPos[] = {{11.7343998, -17.1650009, -5.87252998}, {-11.7158003, -18.9540997, -5.87252998}, {-14.2461004, 23.0438995, -5.87252998}};
    };
    class Land_A_Pub_01: Residential
    {
        zombieChance = 0.200000003;
        lootPos[] = {{1.83397996, 0.393799007, -5.74620008}, {-1.76514006, 0.334473014, -5.74622011}, {-6.62206984, -6.55370998, -5.74622011}, {-4.63622999, -0.100585997, -5.74622011}, {-5.7592802, -3.05029011, -5.74622011}, {-2.08203006, 0.92285198, -1.76121998}, {-4.76514006, -5.89087009, -1.76121998}, {-6.94385004, -1.9375, -1.76121998}, {-4.05224991, -0.779784977, -1.76121998}, {1.39795005, -1.73778999, -1.76121998}, {3.13866997, -2.78564, -1.76121998}, {3.58300996, -0.591309011, -1.76121998}, {3.0302701, -4.04345989, -1.76121998}, {1.94092, 3.18798995, -1.76121998}, {-0.0961913988, 6.22437, -1.76121998}, {5.30468988, 7.55956984, -1.76121998}, {6.72559023, -2.72705007, -1.76121998}, {2.56885004, -4.60010004, -5.7462101}, {4.06737995, 5.41406012, -5.74622011}, {0.753418028, 2.29979992, -5.74622011}};
    };
    class Land_HouseB_Tenement: Office
    {
        lootPos[] = {{5.40575981, 9.89550972, -20.7845001}, {5.99023008, 14.1688995, -20.7845001}, {12.9609003, 14.0718002, -20.7845001}, {14.6069002, 8.92383003, -20.7845001}, {-2.75635004, -2.08593988, -20.7845001}};
    };
    class Land_A_Hospital: hospital
    {
        lootChance = 0.899999976;
        lootPos[] = {{0.807129025, -1.16332996, -7.33966017}, {-7.23389006, -2.63647008, -7.33966017}, {-16.3687, -2.40381002, -7.33966017}, {-12.2847004, -3.19603992, -7.33966017}, {4.40674019, -3.50513005, -7.33966017}, {-3.26659989, -0.925293028, -7.33966017}, {6.85692978, -2.75146008, -7.33966017}, {11.0150995, -3.95434999, -7.33966017}, {16.8197994, -4.71118021, -7.33966017}, {-1.12793005, 3.78417993, -7.44938993}, {12.7475996, 0.142821997, 3.29184008}, {10.2660999, -1.21557999, 3.29184008}};
    };
    class Land_Panelak: Office
    {
        lootPos[] = {{-2.76904011, -6.26562977, 0.0714225993}, {-2.93896008, -1.39160001, 0.0714225993}, {-5.42065001, -3.13183999, 0.0714225993}, {-6.81127977, -6.1552701, 0.0714221001}, {-4.00879002, 2.5302701, 0.0714225993}, {-0.730956972, -3.20116997, 2.77144003}, {3.97900009, -7.08936024, 2.77144003}, {2.49608994, 2.93701005, 2.77144003}, {6.73729992, 1.63281, 2.77144003}, {6.38525009, -2.39159989, 2.77144003}, {6.80614996, -5.77295017, 2.77144003}, {3.75121999, -0.803710997, 2.77144003}, {-0.824218988, 1.86914003, 1.32865}};
    };
    class Land_Panelak2: Office
    {
        lootPos[] = {{-0.729492009, -3.00635004, -2.62859011}, {-0.76464802, 1.36278999, -1.37136996}, {-0.301270008, 3.65038991, 1.40864003}, {0.735840023, -3.22217011, 2.71096992}, {-0.630859017, 1.84765995, 4.15244007}, {3.68920994, -7.33545017, 5.4366498}, {2.26806998, 2.94092011, 5.4366498}, {6.70020008, 2.68993998, 5.4366498}, {6.87841988, -1.45947003, 5.4366498}, {6.09618998, -5.9482398, 5.4366498}, {4.45508003, -1.64892995, 5.4366498}, {2.76366997, 0.44580099, 5.4366498}};
    };
    class Land_Shed_Ind02: Industrial
    {
        lootPos[] = {{-2.28173995, -5.67235994, -4.62598991}, {4.54528999, 9.66650009, -4.62598991}, {4.41223001, 2.64941001, -1.27953994}, {-0.437866002, 11.6942997, -1.27640998}, {-3.44481993, 12.2118998, -1.27704}};
    };
    class Land_Shed_wooden: Residential
    {
        lootPos[] = {{1.26806998, -0.361328006, -1.29153001}, {-0.34277299, 1.02929997, -1.29153001}};
    };
    class Land_Misc_PowerStation: Industrial
    {
        lootPos[] = {{4.09887981, 4.89745998, -1.26742995}, {4.22827005, -1.19872999, -1.26810002}};
    };
    class Land_HouseBlock_A1_1: Residential
    {
        lootPos[] = {{-3.52881002, 0.158935994, -4.74364996}, {-3.5615201, -2.33484006, -4.73106003}};
    };
    class Land_Shed_W01: Industrial
    {
        lootPos[] = {{-1.52637005, -0.246094003, -1.41129005}};
    };
    class Land_HouseV_1I1: Residential
    {
        lootPos[] = {{0.181640998, -1.97314, -2.82275009}};
    };
    class Land_Tovarna2: Industrial
    {
        lootPos[] = {{-11.6309004, 7.2052002, -5.55932999}, {-12.0674, 2.56908989, -5.55932999}, {-4.89354992, 6.63940001, -5.55932999}, {-3.74120998, 2.90392995, -3.89665008}, {-12.8671999, 1.44518995, -2.23134995}, {-12.415, 8.1310997, -2.23134995}, {-12.7236004, 4.11254978, -2.23134995}, {-3.99804997, 8.98009968, -2.23155999}, {-7.33104992, 8.44213963, -2.23155999}, {-4.55370998, 5.22643995, -2.23155999}, {-11.4745998, 2.92113996, 1.66661}, {-11.0703001, 8.13817978, 1.66661}, {-4.67577982, 7.32677984, 1.62173998}, {-2.68262005, 3.44762993, 3.42429996}, {-13.1953001, -8.95862007, 3.42429996}, {-8.80858994, -0.443480998, 0.401226014}, {-12.1328001, -0.149414003, 0.424297988}, {-2.03417993, 6.61414003, -5.55932999}, {0.239258006, 1.72277999, -5.59792995}, {6.22460985, -3.94799995, -4.61824989}, {-6.39354992, -8.24353027, -5.59540987}, {-10.8495998, -6.91210985, -5.56572008}, {-6.77637005, -1.73082995, -5.5601902}};
    };
    class Land_rail_station_big: Office
    {
        lootPos[] = {{-4.97266006, 4.55737019, -5.04438019}, {0.458496004, 4.85229015, -5.04438019}, {2.46239996, 2.21850991, -5.04438019}, {-1.32372999, -2.60571003, -5.04438019}, {-3.29443002, -0.121826001, -5.04438019}, {-1.07764006, 2.36646008, -5.04438019}, {7.46045017, -3.4152801, -5.04438019}, {8.93408012, 3.11890006, -5.04438019}, {-8.1635704, -5.12841988, -5.04438019}};
    };
    class Land_Ind_Vysypka: Industrial
    {
        lootPos[] = {{0.486084014, 4.95458984, -4.96860981}, {1.08032, -0.406738013, -4.96800995}, {-0.0354004018, -10.8207998, -4.96685982}, {-5.07787991, -16.4624004, -4.96758986}, {-6.30297995, 2.92968988, -4.96837997}, {-6.26684999, 26.7348995, -4.97720003}, {1.64697003, 23.4037991, -4.97097015}, {7.14575005, 3.92529011, -4.96971989}, {4.63599014, -12.1620998, -4.96970987}};
    };
    class Land_A_MunicipalOffice: Residential
    {
        zombieChance = 0;
        minRoaming = 3;
        maxRoaming = 9;
        zombieClass[] = {"z_soldier", "z_soldier_heavy", "z_policeman"};
        lootChance = 0.400000006;
        lootPos[] = {{-4.66112995, -6.27172995, -18.4290009}, {3.31641006, -5.77416992, -18.4290009}, {-0.207519993, -6.48682022, -18.4290009}, {-9.72412014, -4.88745022, -3.78903008}, {-9.57812977, 3.55614996, -3.78903008}, {-7.16797018, 11.0737, -3.78903008}, {5.07422018, 11.1837997, -3.78903008}, {9.32079983, 5.38622999, -3.78903008}, {9.65332031, -4.82055998, -3.78903008}, {3.23534989, -0.105957001, -0.169027001}, {4.85204983, -3.69019008, -0.169027001}, {-0.801270008, -7.89087009, -0.169027001}, {-4.40819979, -4.91771984, -0.169027001}, {-4.90771008, -2.23168993, -0.169027001}};
    };
    class Land_A_Office01: Office
    {
        lootPos[] = {{-2.50391006, -2.46948004, -4.52799988}, {4.23535013, -0.336914003, -4.52799988}, {4.11133003, 6.11229992, -4.52799988}, {0.242188007, 6.06299019, -4.52799988}, {4.31641006, 3.74023008, -4.52799988}, {5.08887005, 0.219726995, -4.52799988}, {11.6504002, -1.56470001, -4.52799988}, {14.5811005, -4.11229992, -4.52799988}, {13.8544998, -0.74902302, -4.52799988}, {-7.76270008, 5.59081984, -4.52799988}, {1.81151998, 0.993408024, -2.02800012}, {4.93164015, 4.31981993, -2.02800012}, {1.18945003, 6.07031012, -2.02800012}, {2.23145008, 3.76563001, -2.02800012}, {-4.76366997, -2.51220989, -2.02800012}, {-14.5595999, -3.4072299, -2.02800012}, {-15.2705002, 5.92773008, -2.02800012}, {-10.9062996, 6.04174995, 0.47200799}, {-6.30762005, 3.30078006, 0.472005993}, {7.64160013, 6.38696003, 0.472000986}, {13.6729002, 6.59569979, 0.47199899}, {13.1924, -2.58691001, 0.471998006}, {3.09179997, 2.4375, 6.2049098}, {-1.45703006, -2.28368998, 6.2049098}, {-2.12987995, 4.51587009, 0.47200501}, {4.74414015, -4.60156012, -2.01485991}, {8.34570026, -1.10718, -2.02800012}, {9.94727039, -3.74146008, -2.02800012}, {7.13866997, -2.50731993, -2.02800012}, {12.8701, 4.70922995, -2.02800012}, {15.3720999, 3.42383003, -2.02800012}};
    };
    class Land_A_Office02: Office
    {
        lootPos[] = {{4.72266006, -5.74120998, -8.15108013}, {0.96142602, -5.16942978, -8.1507597}};
    };
    class Land_A_BuildingWIP: Industrial
    {
        lootChance = 0.5;
        lootPos[] = {{-4.62573004, 4.52343988, -6.45268011}, {-12.6377001, 0.494141012, -6.4924202}, {-14.6022997, -8.62841988, -6.49960995}, {-16.0004997, -9.80957031, -6.50423002}, {-15.5627003, -5.17724991, -6.50522995}, {0.944580019, -2.30370998, -6.43042994}, {7.28125, 3.20898008, -6.44042015}, {9.75708008, 10.1138, -6.40826988}, {14.7709999, 7.29687977, -6.47756004}, {15.4504004, -0.314940989, -6.52978992}, {20.4895, 2.31836009, -4.52571011}, {17.3122997, -3.10010004, -2.53291011}, {10.7069998, -6.51610994, -2.5325501}, {2.22533989, -9.21582031, -2.53399992}, {-8.91942978, -7.18896008, -2.53312993}, {-16.3178997, -8.35645008, -2.53357005}, {-21.3064003, -6.79150009, -2.53182006}, {-21.6018009, -1.79541004, -2.53182006}, {-17.5807991, 6.14745998, -2.53182006}, {-23.198, 8.44727039, -2.53182006}, {-17.1973, 9.58594036, -2.53182006}, {-4.99023008, 9.80957031, -2.53182006}, {14.0872002, 7.44091988, -2.5267601}, {10.5796003, -6.84912014, 1.48116004}, {-3.19115996, -2.4946301, 1.49403}, {-13.8185997, 3.98974991, 1.49828994}, {-15.9502001, -6.17383003, 1.48801994}, {-20.6996994, -16.9761009, 1.50282001}, {-15.415, -13.3900995, 5.46682978}};
    };
    class Land_Church_01: Church
    {
        lootPos[] = {{-6.92102003, -0.382813007, -4.21338987}};
    };
    class Land_Church_03: Church
    {
        lootPos[] = {{5.15331984, -6.96875, -14.3021002}, {-1.79052997, -7.68018007, -14.3021002}, {-0.0263672005, -2.98438001, -14.3021002}, {-0.00341796991, 2.02245998, -14.3021002}, {5.49877977, 7.20508003, -14.3021002}, {5.38891983, 3.40429997, -14.3021002}, {3.23656988, 2.76074004, -14.3021002}, {-1.51001, 7.66309023, -14.3021002}, {-7.64160013, 4.8125, -14.3021002}, {-6.56591988, -4.59131002, -14.3021002}, {9.55200005, 2.22362995, -13.7587996}, {9.93262005, -3.85254002, -13.7587996}};
        hangPos[] = {{1.72168005, -8.39770985, -0.172569007}, {2.0883801, -14.4236002, -0.275359988}, {-13.7158003, -10.4807997, -0.795174003}, {-12.9071999, -16.4104996, -0.89506501}};
    };
    class Land_Church_02: Church
    {
        lootPos[] = {};
        maxRoaming = 2;
    };
    class Land_Church_02a: Church
    {
        lootPos[] = {};
        maxRoaming = 2;
    };
    class Land_Church_05R: Church
    {
        lootPos[] = {};
        maxRoaming = 2;
    };
    class Land_Mil_Barracks_i: MilitarySpecial
    {
        lootPos[] = {{5.39037991, -1.75683999, -1.09824002}, {1.46753001, -0.131835997, -1.09824002}, {1.29394996, -2.16211009, -1.09824002}, {-1.78393996, -0.168945, -1.09824002}, {-1.80614996, -1.97656, -1.09824002}, {-4.77881002, 0.0488280989, -1.09824002}, {-5.39258003, -2.11816001, -1.09824002}, {-5.47045994, 2.58104992, -1.09824002}, {-8.32592964, -0.144530997, -1.09824002}, {-9.14966011, -2.55858994, -1.09824002}, {-1.95288002, 2.57715011, -1.09824002}, {5.46362019, 2.57813001, -1.09824002}};
    };
    class Land_A_TVTower_Base: Industrial
    {
        lootPos[] = {{-0.982421994, -1.92627001, -2.21572995}, {-2.01781988, -4.24170017, -2.21918011}, {-0.759276986, 1.42139006, -2.21572995}};
    };
    class Land_Mil_House: Military
    {
        vehPos[] = {{13.4390001, 3.25243998, -5.71244001, 84}};
        lootPos[] = {{12.4569998, 1.42480004, -5.51438999}, {11.0390997, 4.85277987, -5.51438999}, {13.6669998, 4.42139006, -5.51438999}};
    };
    class Land_Misc_Cargo1Ao: Industrial
    {
        lootPos[] = {{0.488770008, -1.61377001, -1.09223998}, {0.0122069996, 2.19263005, -1.09223998}, {0.00976562966, 0.19043, -1.09223998}};
    };
    class Land_Misc_Cargo1Bo: Industrial
    {
        lootPos[] = {{-0.322021008, 1.68554997, -1.09221995}, {0.548583984, -1.96289003, -1.09221995}, {0.223389, -0.580078006, -1.09221995}};
    };
    class Land_Nav_Boathouse: Industrial
    {
        lootPos[] = {{17.3271008, -20.1973, 5.80719995}, {8.30370998, -20.2520008, 5.80897999}, {7.69434023, -26.3505993, 5.80897999}, {7.97069979, -4.63476992, 5.69822979}, {5.61718988, -13.5430002, 5.70074987}};
    };
    class Land_ruin_01: Residential
    {
        lootPos[] = {{-4.31934023, -0.115234002, -1.45578003}, {3.41308999, 0.270507991, -1.71364999}, {3.00292993, 3.42773008, -1.55764997}, {0.622070014, -1.73778999, -1.49047995}};
    };
    class Land_wagon_box: Industrial
    {
        lootPos[] = {{0.542968988, -3.89453006, -0.776678979}, {0.479979992, -0.60839802, -0.776637971}, {0.515380979, 3.03856993, -0.776592016}};
    };
    class Land_HouseV2_04_interier: Residential
    {
        lootPos[] = {{7.49462986, 5.83739996, -5.73901987}, {7.50989008, -0.93017602, -5.74175978}, {1.95532, 4.16406012, -5.73937988}, {2.10876012, 6.60645008, -5.73859978}, {-2.30016994, 4.22460985, -5.73935986}, {-5.13305998, 6.74364996, -5.7385602}, {-4.74658012, 2.68457007, -5.73985004}};
    };
    class Land_HouseV2_01A: Residential
    {
        lootPos[] = {{-3.52881002, -3.16895008, -5.60345984}, {-1.62987995, -3.25439, -5.66886997}};
    };
    class Land_psi_bouda: Residential
    {
        maxRoaming = 4;
        lootPos[] = {{-1.77002001, -1.45166004, 1.95941997}};
    };
    class Land_KBud: Residential
    {
        zombieChance = 0;
        maxRoaming = 0;
        lootPos[] = {{-0.0170898009, 0.0114746001, -0.663670003}};
    };
    class Land_A_Castle_Bergfrit: Residential
    {
        lootPos[] = {{0.0185547005, 1.91602004, -2.83640003}, {1.19140995, -1.43848002, -2.83640003}, {-2.36816001, 3.32275009, -0.628570974}, {2.36133003, 3.86768007, 1.83972001}, {2.48438001, -3.20556998, 3.8554101}, {-2.0947299, -3.44872999, 6.31902981}, {-1.15918005, 3.13866997, 8.7669096}, {1.74706995, 1.26806998, 8.7669096}, {-0.540039003, -2.35254002, 8.7669096}, {-1.62206995, -4.27978992, 13.4800997}, {-2.23046994, 4.82470989, 16.8560009}, {1.67578006, -0.825195014, 16.8505001}};
    };
    class Land_A_Castle_Stairs_A: Residential
    {
        lootPos[] = {{0.697997987, -1.79394996, 0.726929009}, {8.39379978, 0.890625, 0.875122011}, {8.17261028, 1.48925996, 7.02587986}};
    };
    class Land_A_Castle_Gate: Residential
    {
        lootChance = 0.699999988;
        lootPos[] = {{0.244140998, -4.48485994, -3.14362001}, {-1.25293005, 2.98779011, -3.07028008}, {4.50684023, -3.3115201, -2.94884992}, {4.5517602, 3.29834008, -2.94858003}, {7.9482398, 1.40820003, -2.91002989}};
    };
    class Land_Mil_Barracks: Military
    {
        lootPos[] = {};
    };
    class Land_Mil_Barracks_L: Military
    {
        lootPos[] = {};
    };
    class Land_Barn_W_02: Farm
    {
        lootPos[] = {{3.16504002, 5.56543016, -2.31409001}, {3.35938001, -0.152344003, -2.31305003}, {2.53612995, -5.89452982, -2.30957007}, {-2.94629002, -5.01366997, -2.31006002}, {-2.84375, 0.212890998, -2.31183004}, {-5.63281012, 4.82910013, -2.3136301}};
    };
    class Land_sara_domek_zluty: Residential
    {
        maxRoaming = 1;
        lootPos[] = {{2.95703006, 3.00731993, -2.43370008}, {7.06737995, 2.95556998, -2.43370008}, {6.36303997, -0.236328006, -2.43374991}, {0.627686024, -0.586914003, -2.43387008}, {-0.65991199, 2.05370998, -2.43370008}, {-2.77515006, 0.751953006, -2.43372011}, {-5.07666016, 3.04491997, -2.43360996}, {-6.17139006, -2.33691001, -2.43382001}, {-3.75292993, -3.54688001, -2.43382001}};
    };
    class Land_HouseV_3I4: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_Shed_W4: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_HouseV_3I1: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_HouseV_1L2: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_HouseV_1T: Residential
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_telek1: Industrial
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_Rail_House_01: Industrial
    {
        lootPos[] = {{2.8115201, 3.61425996, -1.28266001}, {-1.82177997, 3.10546994, -1.28266001}, {0.487792999, 3.38866997, -1.28266001}};
    };
    class Land_HouseV_2I: Default
    {
        maxRoaming = 3;
        lootPos[] = {};
    };
    class Land_Misc_deerstand: Military
    {
        zombieChance = 0;
        lootChance = 0.5;
        maxRoaming = 3;
        lootPos[] = {{-0.923828006, -0.808593988, 1.08538997}, {0.419921994, -0.237305, 1.08538997}};
    };
    class Land_Stan: Military
    {
        maxRoaming = 1;
        lootPos[] = {{0.880370975, 2.16016006, -1.14058006}, {-0.372070014, -0.763671994, -1.14759004}};
    };
    class CampEast: Military
    {
        maxRoaming = 1;
        lootPos[] = {{-1.05712998, -1.80762005, -1.31049001}, {0.627440989, 1.83397996, -1.31049001}};
    };
    class Land_stan_east: Military
    {
        maxRoaming = 1;
        lootPos[] = {{2, -3.4000001, -1.20093}, {-1, 1, -1.27363002}, {-2, -3.4000001, -1.27363002}, {1, 1, -1.27363002}};
    };
    class MASH: Hospital
    {
        maxRoaming = 1;
        lootChance = 0.400000006;
        lootPos[] = {{1.18212998, -1.65039003, -1.17793}, {0.24707, 0.799315989, -1.17803001}};
    };
    class MASH_EP1: MASH
    {
    };
    class UH1Wreck_Ori: Military
    {
        zombieClass[] = {"z_soldier_pilot", "z_soldier_heavy"};
        zombieChance = 0;
        lootChance = 0;
        minRoaming = 4;
        maxRoaming = 8;
        lootPos[] = {};
    };
    class Land_kamaz: TavianaDZ
    {
        zombieClass[] = {"z_soldier_heavy", "z_soldier_heavy"};
        zombieChance = 1;
        lootChance = 1;
        minRoaming = 5;
        maxRoaming = 9;
        lootPos[] = {{-2.26854992, 2.10840011, -1.78322005}, {-0.986328006, -0.760742009, -1.78322995}, {-1.16699004, -3.86816001, -1.78322995}, {0.269531012, -5.41942978, -1.78321004}, {1.94140995, -3.60741997, -1.78315997}, {1.25927997, 0.826659977, -1.78310001}, {2.22851992, 3.42529011, -1.78313005}};
    };
    class Land_zygul_wrecked: Residential
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class Land_sedan_weck: Residential
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class Land_Trabant_wreck: Residential
    {
        maxRoaming = 1;
        lootPos[] = {};
    };
    class Land_kamaz_hasic: Residential
    {
        minRoaming = 1;
        maxRoaming = 1;
        zombieClass[] = {"ori_pozarnik", "ori_pozarnik", "ori_pozarnik", "ori_zombie6Ln"};
        lootPos[] = {};
    };
    class USMC_WarfareBFieldhHospital: MASH
    {
        minRoaming = 1;
        maxRoaming = 3;
        zombieClass[] = {"z_soldier", "z_soldier_heavy"};
        lootPos[] = {{-3.52245998, -5.03930998, 1.14725995}, {2.36620998, -4.52295017, 1.14786005}, {1.39063001, -0.423096001, 1.14745998}, {1.14258003, 5.00952005, 1.14779997}, {3.71239996, 1.89795005, 1.14787996}};
    };
    class Land_Ind_Shed_02_main: Default
    {
        zombieChance = 0;
        maxRoaming = 3;
    };
    class HouseRoaming: Residential
    {
        lootChance = 0;
        zombieChance = 0;
        maxRoaming = 2;
    };
    class FarmRoaming: Farm
    {
        lootChance = 0;
        zombieChance = 0;
        maxRoaming = 2;
    };
    class Land_Shed_W03: HouseRoaming
    {
    };
    class Land_HouseV_1I3: HouseRoaming
    {
    };
    class Land_HouseV_1L1: HouseRoaming
    {
    };
    class Land_HouseV_1I2: HouseRoaming
    {
    };
    class Land_HouseV_2L: HouseRoaming
    {
    };
    class Land_HouseV_2T1: HouseRoaming
    {
    };
    class Land_houseV_2T2: HouseRoaming
    {
    };
    class Land_HouseV_3I2: HouseRoaming
    {
    };
    class Land_HouseV_3I3: HouseRoaming
    {
    };
    class Land_HouseBlock_A1: HouseRoaming
    {
    };
    class Land_HouseBlock_A1_2: HouseRoaming
    {
    };
    class Land_HouseBlock_A2: HouseRoaming
    {
    };
    class Land_HouseBlock_A2_1: HouseRoaming
    {
    };
    class Land_HouseBlock_A3: HouseRoaming
    {
    };
    class Land_HouseBlock_B1: HouseRoaming
    {
    };
    class Land_HouseBlock_B2: HouseRoaming
    {
    };
    class Land_HouseBlock_B3: HouseRoaming
    {
    };
    class Land_HouseBlock_B4: HouseRoaming
    {
    };
    class Land_HouseBlock_B5: HouseRoaming
    {
    };
    class Land_HouseBlock_B6: HouseRoaming
    {
    };
    class Land_HouseBlock_C1: HouseRoaming
    {
    };
    class Land_HouseBlock_C2: HouseRoaming
    {
    };
    class Land_HouseBlock_C3: HouseRoaming
    {
    };
    class Land_HouseBlock_C4: HouseRoaming
    {
    };
    class Land_HouseBlock_C5: HouseRoaming
    {
    };
    class Land_HouseV2_01B: HouseRoaming
    {
    };
    class Land_Misc_Cargo1D: HouseRoaming
    {
    };
    class Land_HouseV2_03: HouseRoaming
    {
    };
    class Land_Ind_Shed_01_end: HouseRoaming
    {
    };
    class Land_A_statue01: HouseRoaming
    {
        zombieClass[] = {"zZombie_Base", "zZombie_Base", "z_teacher", "z_suit1", "z_suit2", "z_soldier", "z_soldier_heavy", "z_policeman"};
        minRoaming = 2;
        maxRoaming = 8;
    };
    class Land_Shed_W02: FarmRoaming
    {
    };
    class Grave: HouseRoaming
    {
        maxRoaming = 3;
    };
    class GraveCross1: HouseRoaming
    {
        maxRoaming = 2;
    };
    class GraveCross2: HouseRoaming
    {
        maxRoaming = 2;
    };
    class GraveCrossHelmet: Military
    {
        maxRoaming = 4;
    };
};

enum { DestructNo = 0 };
enum { DestructBuilding = 1 };
enum { DestructEngine = 2 };
enum { DestructTree = 3 };
enum { DestructTent = 4 };
enum { DestructMan = 5 };
enum { DestructDefault = 6 };
enum { DestructWreck = 7 };
