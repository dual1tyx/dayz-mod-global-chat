modded class MissionServer extends MissionBase {
    override void OnInit () {
        super.OnInit ();
		Print ("[SchanaChat] OnInit");
		GetSchanaModGlobalChatServerSettings();
		GetRPCManager ().AddRPC ( "SchanaChat", "SchanaChatSettingsRPC", this, SingeplayerExecutionType.Both );
		GetRPCManager ().AddRPC ( "SchanaChat", "SchanaRoleColoursRPC", this, SingeplayerExecutionType.Both );
	}
	
	void SchanaChatSettingsRPC( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		PlayerIdentity RequestedBy = PlayerIdentity.Cast(sender);
		if (RequestedBy){
			Print ("[SchanaChat] Settings Requested By " + RequestedBy.GetId ());
			GetRPCManager ().SendRPC ("SchanaChat", "SchanaChatSettingsRPC", new Param1< SchanaModGlobalChatServerSettings >( GetSchanaModGlobalChatServerSettings () ), true, RequestedBy);
		}
	}

	void SchanaRoleColoursRPC( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		PlayerIdentity RequestedBy = PlayerIdentity.Cast(sender);
		if (RequestedBy){
			Print ("[SchanaChat] Roles Requested By " + RequestedBy.GetId ());
			GetRPCManager ().SendRPC ("SchanaChat", "SchanaRoleColoursRPC", new Param1< array<ref RoleSettingsData> >( GetSchanaModGlobalChatServerSettings ().GetRoles () ), true, RequestedBy);
		}	
	}	

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		string theRole = "";
		theRole = player.AttainRole(identity);
		player.SetRole(theRole);
    }

}

    string AttainRole(PlayerIdentity sender){
        SchanaModGlobalChatServerSettings settings = GetSchanaModGlobalChatServerSettings();
        array<ref RoleSettingsData> serverRoles = GetSchanaModGlobalChatServerSettings().GetRoles();
        for (int x=0; x<serverRoles.Count();x++){
            RoleSettingsData role = serverRoles[x];
            if (role!=null){
                string roleName = role.GetName();
                array<string> roleMembers = role.GetMembers();
                for (int y=0; y<roleMembers.Count();y++){
                    if (sender.GetPlainId() == roleMembers[y]){
                        return roleName;
                    }
                }
            }
        }
		  return "";
    }