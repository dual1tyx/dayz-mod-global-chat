class SchanaColour {
	int R;
	int G;
	int B;
	
	void SchanaColour (vector c){
		float r =c[0];
		float g =c[1];
		float b =c[2];
		R = r;
		G = g;
		B = b;
	}
	
	int Get (){
		return ARGB (255, R, G, B);
	}
	
	string Debug (){
		return "[SchanaChat][DebugColour]R: " + R + " G: " + G + " B: " +  B;
	}
}
