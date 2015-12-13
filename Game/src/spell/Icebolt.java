package spell;

import unit.Mage;

public class Icebolt extends Bolt {
	
	String nameStatusEffect = "Freeze";
	
	public Icebolt(Mage mage){	
		
		super(ICE,mage);
		this.mage = mage;
	
	}

}	
