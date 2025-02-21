class TBIEItemExchangeConfig {
    static ref TBIEItemExchangeConfig config;
    static int lastRequestTime = GetGame().GetTime() + 2000;

    static TBIEItemExchangeConfig Get() {
        if(!GetGame().IsServer() && GetGame().GetPlayer() && GetGame().GetPlayer().GetIdentity() && (!config || TBIEItemExchangeConfig.lastRequestTime > GetGame().GetTime() - 2000)) {
            TBIEItemExchangeConfig.lastRequestTime = GetGame().GetTime();
            GetGame().RPCSingleParam(null, TB_IE_RPC.GET_ITEM_EXCHANGE_CONFIG, null, true, GetGame().GetPlayer().GetIdentity());
        } else if(GetGame().IsServer() && !config) {
            config = new TBIEItemExchangeConfig();
        }

        return config;
    }

    [NonSerialized()] ref TBLibBaseSaveLoadFile<TBIEItemExchangeConfig> fileHandler;
    private string version = "1";
    private ref array<ref TBIEItemConfig> itemTypes = new array<ref TBIEItemConfig>();

    void TBIEItemExchangeConfig() {
        fileHandler = new TBLibBaseSaveLoadFile<TBIEItemExchangeConfig>(TB_IE_MOD_NAME, "ItemExchangeConfig.json", TBLibGetConfigPath(TB_IE_MOD_NAME), false);

        if(!fileHandler.Load(this)) {
            TBIEItemConfig itemConfig = new TBIEItemConfig();
            itemConfig.sourceType = "Hammer";
            itemConfig.targetType = "Nail";
            itemTypes.Insert(itemConfig);
            itemConfig = new TBIEItemConfig();
            itemConfig.sourceType = "Nail";
            itemConfig.targetType = "Hammer";
            itemTypes.Insert(itemConfig);

            fileHandler.Save(this);
        }
    }

    bool HasItemToExchange(string type) {
        foreach(TBIEItemConfig itemConfig : itemTypes) {
            if(itemConfig.sourceType == type) {
                return true;
            }
        }

        return false;
    }

    string GetTargetType(string type) {
        foreach(TBIEItemConfig itemConfig : itemTypes) {
            if(itemConfig.sourceType == type) {
                return itemConfig.targetType;
            }
        }

        return "";
    }

}
