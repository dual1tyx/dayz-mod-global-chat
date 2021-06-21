modded class PlayerBase extends ManBase {
    protected string m_ServerRole = "";
    static const int SCHANA_RPC_CHAT_CLIENT_SEND_GLOBAL = -44301;

    override void OnRPC (PlayerIdentity sender, int rpc_type, ParamsReadContext ctx) {
        switch (rpc_type) {
            case SCHANA_RPC_CHAT_CLIENT_SEND_GLOBAL:
                {
                    Param1<string> chatParams;
                    if (!ctx.Read (chatParams)) return;
                    string name = sender.GetName ();

                    string text;
                    if (m_ServerRole){
                        text = m_ServerRole+" # " + name + " : " + chatParams.param1;
                    }
                    else {
                        text = name + " : " + chatParams.param1;
                    }

                    ref array<Man> players = new array<Man> ();
                    GetGame ().GetPlayers (players);

                    for (int i = 0; i < players.Count (); ++i) {
                        if (players[i] && players[i].GetIdentity ()) {
                            GetGame ().RPCSingleParam (players[i], ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string> (text), true, players[i].GetIdentity ());
                        }
                    }

                    break;
                }
        }

        super.OnRPC (sender, rpc_type, ctx);
    }

    void SetRole(string role){
        m_ServerRole = role;
    }

    string GetRole(){
        return m_ServerRole;
    }
}