package spell;

import unit.Mage;

public class Firebolt extends Bolt {
		
	public Firebolt(Mage mage){	
		
		super(FIRE,mage);
		this.nameStatusEffect = "Burn";
	}

}	
