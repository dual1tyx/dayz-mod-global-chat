class RoleSettingsData {
    protected string Name;
    protected ref array<string> Members;
    protected ref SchanaColour  Colour = new SchanaColour("163 5 0");

    void RoleSettingsData(string roleName = "Staff", array<string> playerIds = null, SchanaColour roleColour = null){
        if (playerIds.Count() == 0){
            Members = {
                "76561197997664497"
            };
        }
        if (roleColour == null){
            Colour = new SchanaColour("163 5 0");
        }
        Name = roleName;
        Members = playerIds;
        Colour = roleColour;
    }

    string GetName(){
        return Name;
    }

    void GetName(string name){
        Name = name;
    }

    array<string> GetMembers(){
        return Members;
    }

    void GetMembers(array<string> ids){
        Members = ids;
    } 

    int GetColour(){
        return Colour.Get();
    }

    void SetColour(SchanaColour colour){
        Colour = colour;
    }
}
