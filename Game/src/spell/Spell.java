package spell;

import unit.Mage;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import effect.status.Burn;
import effect.status.StatusEffect;
import state.attack.Attack;
import unit.PlayableCharacter;

public abstract class Spell extends Attack {
		
	protected static byte MAGICAL = PlayableCharacter.MAGICAL;
	
	protected byte spellLevel;
	protected byte spellType;		
	protected Mage mage;
	protected String nameStatusEffect;
	
	Spell(byte spellType, Mage mage) {
		
		super(MAGICAL);
		this.spellType = spellType;
		this.mage = mage;
	}	
	
	void setSpellLevel(byte level) {this.spellLevel = level;}
	
	public byte getSpellLevel() {return this.spellLevel;}
	
	int getNewDuration(byte statusEffect) {
		
		return this.attackable.getStatus().containsKey(statusEffect)?this.attackable.getStatus().get(statusEffect).getTurnDuration():0;
	}
	
	protected void addStatusEffect() throws ClassNotFoundException, NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, InstantiationException {
		
		Class<?> ClassStatusEffect = Class.forName(this.nameStatusEffect);
		Constructor<?> ConsStatusEffect = ClassStatusEffect.getConstructor(byte.class,Mage.class);
		Byte ByteStatusEffect = (Byte)(ClassStatusEffect.getMethod("getStatusType").invoke(null));
					
		int duration = this.getNewDuration(ByteStatusEffect);
		
		StatusEffect statusEffect;
		
		if(StatusEffect.checkOldStatusEffects(ByteStatusEffect)) {
			
			statusEffect = StatusEffect.getOldStatusEffect(ByteStatusEffect);
			StatusEffect.removeOldStatusEffect(ByteStatusEffect);
		}
		
		else
			
			statusEffect = (StatusEffect)(ConsStatusEffect.newInstance(new Byte((byte)(3+duration)),this));
		
		statusEffect.addTurnDuration(3);
		
	}
}
