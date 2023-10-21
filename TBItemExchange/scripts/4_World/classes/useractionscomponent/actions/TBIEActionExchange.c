class TBIEActionExchange: ActionInteractBase
{

    void TBREActionLockDoors() {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
    }

    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINone();
        m_ConditionTarget = new CCTSelf();
    }

    override bool HasTarget()
    {
        return false;
    }

	override string GetText()
	{
		return "#exchange_item";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        ItemBase itemInHands = player.GetItemInHands();
        return itemInHands && TBIEItemExchangeConfig.Get() && TBIEItemExchangeConfig.Get().HasItemToExchange(itemInHands.GetType());
    }

    override void OnEndServer(ActionData action_data) {
		ItemBase itemInHands = action_data.m_Player.GetItemInHands();
		
		float health = itemInHands.GetMaxHealth() / 100 * itemInHands.GetHealth();
		
        string typeName = TBIEItemExchangeConfig.Get().GetTargetType(itemInHands.GetType());
        
		ItemBase target = ItemBase.Cast(action_data.m_Player.GetInventory().CreateInInventory(typeName));
		
		if (!target) Error("TB Exchange Item: Could not create Item from type: " + typeName);
		
		
		if (itemInHands.HasQuantity()) {
			itemInHands.SetQuantity(itemInHands.GetQuantity() - 1);
		} else {
			itemInHands.Delete();
		}
		
		if (target.HasQuantity()) {
			target.SetQuantity(1);
		}
		
		target.SetHealth(target.GetMaxHealth() * health);
    }
};
