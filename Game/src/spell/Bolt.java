package spell;

import java.lang.reflect.InvocationTargetException;

import unit.Mage;

public abstract class Bolt extends Spell {
	
	public static final byte FIRE = 0;
	public static final byte ICE = 1;
	
	protected Bolt(byte spellType,Mage mage) {
		
		super(spellType,mage);
	}
	
	public int attackEffect() throws ClassNotFoundException, NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, InstantiationException {	
		
		addStatusEffect();
		return mage.getIntelligence()*spellLevel;
	}
	
	

}

