modded class PlayerBase {

    override void SetActions(out TInputActionMap InputActionMap) {
        super.SetActions(InputActionMap);

        AddAction(TBIEActionExchange, InputActionMap);
    }

}