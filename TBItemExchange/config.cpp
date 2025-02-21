class CfgPatches {
    class TBItemExchangeClient {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {
            "DZ_Scripts",
            "TBLibClient"
        };
    };
};

class CfgMods {
    class TBItemExchangeClient {
        dir = "TBItemExchangeClient";
        picture = "";
        action = "";
        hideName = 0;
        name = "TBItemExchangeClient";
        credits = "TheBuster";
        creditsJson = "TBItemExchangeClient/Scripts/Data/Credits.json";
        versionPath = "TBItemExchangeClient/scripts/Data/Version.hpp";
        inputs = "TBItemExchangeClient\inputs.xml";
        author = "TheBuster";
        authorID = "76561198196317725";
        version = "1.0.0";
        extra = 0;
        type = "mod";

        dependencies[] = {"Game", "World", "Mission"};

        class defs {
            class gameScriptModule {
                value = "";
                files[] = {
                    "TBItemExchangeClient/scripts/3_Game"
                };
            };
            class worldScriptModule {
                value = "";
                files[] = {
                    "TBItemExchangeClient/scripts/4_World"
                };
            };
            class missionScriptModule {
                value = "";
                files[] = {
                    "TBItemExchangeClient/scripts/5_Mission"
                };
            };
        };
    };
};
