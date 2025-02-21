class TBIEConfigListener {
    TBIEItemExchangeConfig itemExchangeConfig;

    void TBIEConfigListener() {
        if(GetGame().IsServer()) {
            GetDayZGame().Event_OnRPC.Insert(OnRPCServer);
        } else {
            GetDayZGame().Event_OnRPC.Insert(OnRPCClient);
        }

        itemExchangeConfig = TBIEItemExchangeConfig.Get();
    }

    void ~TBIEConfigListener() {
        if(GetGame().IsServer()) {
            GetDayZGame().Event_OnRPC.Remove(OnRPCServer);
        } else {
            GetDayZGame().Event_OnRPC.Remove(OnRPCClient);
        }
    }

    void OnRPCClient(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if(rpc_type == TB_IE_RPC.RESPONSE_ITEM_EXCHANGE_CONFIG) {
            Param1 <ref TBIEItemExchangeConfig> itemExchangeConfigParam;
            if(ctx.Read(itemExchangeConfigParam)) {
                TBIEItemExchangeConfig.config = itemExchangeConfigParam.param1;
            }
        }
    }

    void OnRPCServer(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if(rpc_type == TB_IE_RPC.GET_ITEM_EXCHANGE_CONFIG) {
            GetGame().RPCSingleParam(null, TB_IE_RPC.RESPONSE_ITEM_EXCHANGE_CONFIG, new Param1<ref TBIEItemExchangeConfig>(itemExchangeConfig), true, sender);
        }
    }

}