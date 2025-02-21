modded class MissionServer {
    ref TBIEConfigListener tbieConfigListener;

    override void OnInit() {
        super.OnInit();

        tbieConfigListener = new TBIEConfigListener();
    }

}
