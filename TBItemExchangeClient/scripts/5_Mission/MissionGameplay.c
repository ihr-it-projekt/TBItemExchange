modded class MissionGameplay
{
    ref TBIEConfigListener tbieConfigListener;

    override void OnInit()
    {
        super.OnInit();

        tbieConfigListener = new TBIEConfigListener();
	}

}